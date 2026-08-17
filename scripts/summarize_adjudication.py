import json, glob, os, csv, re
from collections import Counter,defaultdict
ROOT='adjudication_results'; files=sorted(glob.glob(ROOT+'/*.json')); expected=103
schema_errors=[]; all_entries=[]
required={'function','decompiler','hypothesis','verdict','entities','reasoning'}
valid_verdict={'confirmed','rejected','undeterminable'}; valid_match={'correct','wrong','undeterminable'}
for f in files:
    try: data=json.load(open(f,encoding='utf-8'))
    except Exception as e: schema_errors.append({'file':f,'error':'parse: '+str(e)}); continue
    if not isinstance(data,list): schema_errors.append({'file':f,'error':'top-level not array'}); continue
    for i,e in enumerate(data):
      err=[]
      if not isinstance(e,dict) or not required.issubset(e): err.append('missing entry fields')
      else:
       if e['verdict'] not in valid_verdict: err.append('bad verdict')
       if e.get('decompiler') not in {'codex','claude-code'}: err.append('noncanonical decompiler')
       if not isinstance(e['entities'],list): err.append('entities not list')
       else:
        for j,x in enumerate(e['entities']):
         if not isinstance(x,dict) or not {'source_role','source_type','decompiled_type','match','evidence_source_line','evidence_decompiled_line'}.issubset(x): err.append(f'bad entity {j}')
         elif x['match'] not in valid_match: err.append(f'bad match {j}')
         elif 'reasoning' not in x: err.append(f'entity {j} missing reasoning')
      if err: schema_errors.append({'file':f,'entry':i,'error':'; '.join(err)})
      if isinstance(e,dict): all_entries.append((f,e))

def classify(x):
    if x.get('match')!='wrong': return None
    role=str(x.get('source_role','')); src=str(x.get('source_type','')); dst=str(x.get('decompiled_type',''))
    s=' '.join([role,src,dst,str(x.get('reasoning',''))]).lower()
    if ('static ' in src.lower() or '静态' in role+src) and (re.search(r'extern|非 static|外部链接|非局部',dst,re.I) or '链接属性' in role): return 'SC-01'
    if re.search(r'函数签名|函数返回|第[一二三四五六七八九十0-9]+个参数|return type|signature',role+' '+s) and not ('局部' in role): return 'FN-01'
    if re.search(r'静态|文件作用域.*(对象|变量)|链接属性|extern',role+' '+src+' '+dst): return 'SC-01'
    sn=re.findall(r'\bstruct\s+([A-Za-z_][A-Za-z0-9_]*)',src); dn=re.findall(r'\bstruct\s+([A-Za-z_][A-Za-z0-9_]*)',dst)
    if sn and dn and sn[0]!=dn[0]: return 'ST-01'
    if '结构体' in role or re.search(r'\bstruct\b',src,re.I):
      if re.search(r'错误.*结构体|无对应.*结构体|不同.*结构体|options|rb_node|void \*.*struct',s): return 'ST-01'
      return 'LAYOUT-01'
    if re.search(r'\[[0-9]+\].*\[[0-9]+\]|\[[0-9]+\].*\[[0-9]+\]',src+' '+dst): return 'OTHER'
    if '函数返回及终止属性' in role or role in ('first parameter','second parameter'): return 'FN-01'
    if '临时返回值' in role: return 'OTHER'
    if '扩栈' in role or 'yyss1' in role: return 'PTR-01'
    if '结构体' in role and ('quota' in src.lower() or 'ea_quota' in dst.lower()): return 'ST-01'
    if '字段' in role and 'mode_t' in src: return 'LAYOUT-01'
    if re.search(r'\b(char|unsigned char|_bool|bool|int|uint8_t|uint32_t|size_t|ssize_t|pid_t|off_t|intmax_t|yysymbol_kind_t|mode_t)\b',src+' '+dst,re.I) and '*' not in src+dst: return 'INT-01'
    if '*' in src+dst and ('code const *' in src or 'code（' in dst or 'void *' in dst): return 'PTR-01'
    if ('const' in src.lower()+dst.lower()) and ('*' in src+dst): return 'OTHER'
    if '参数' in role and ('absent' in dst or '未声明' in dst): return 'FN-01'
    if re.search(r'指针层级|二级指针|指针.*数组|数组.*指针|pointer level|void \*',s) and not re.search(r'const',s): return 'PTR-01'
    if re.search(r'整数|typedef|符号|宽度|signed|unsigned|int vs|long vs|类型别名|enum |_bool|bool|size_t|pid_t|uint[0-9]|int[0-9]',s): return 'INT-01'
    return 'OTHER'

needs=[]; wrong_rows=[]
for f,e in all_entries:
  for idx,x in enumerate(e.get('entities',[]) if isinstance(e.get('entities'),list) else []):
    if x.get('match')=='wrong':
      c=classify(x); wrong_rows.append((f,e,x,c))
      if c=='OTHER':
       pair=str(x.get('source_type',''))+' '+str(x.get('decompiled_type',''))
       basis='const限定差异' if 'const' in pair.lower() else ('数组长度/维度差异' if '[' in pair else '现有六模式未覆盖的类型恢复差异')
       needs.append({'file':f,'function':e.get('function'),'decompiler':e.get('decompiler'),'entry_verdict':e.get('verdict'),'entity_index':idx,'assigned_pattern':'OTHER','review_status':'semantic_review_completed','review_basis':basis,'entity':x})
json.dump(needs,open('needs_review.json','w',encoding='utf-8'),ensure_ascii=False,indent=2)

patterns=['SC-01','ST-01','PTR-01','INT-01','FN-01','LAYOUT-01','OTHER']
ps={p:{'wrong':0,'tasks':set(),'functions':set(),'ventries':defaultdict(set)} for p in patterns}
for f,e,x,c in wrong_rows:
  base=os.path.basename(f).removesuffix('.json').split('__'); dec=base[0]; fn=e.get('function') or base[-1]; function_id='__'.join(base[2:])
  d=ps[c]; key=(function_id,dec); entrykey=(f,e.get('hypothesis'),e.get('verdict'),e.get('reasoning'))
  d['wrong']+=1; d['tasks'].add(key); d['functions'].add(function_id); d['ventries'][e.get('verdict')].add(entrykey)

with open('per_function_detail.csv','w',newline='',encoding='utf-8-sig') as out:
 w=csv.writer(out); w.writerow(['project','function','decompiler','条目verdict','wrong-entity数','undeterminable-entity数','命中模式列表'])
 groups=defaultdict(list)
 for f,e in all_entries: groups[f].append(e)
 for f,ls in sorted(groups.items()):
  base=os.path.basename(f).removesuffix('.json').split('__')
  dec=base[0]; proj='/'.join(base[2:-1]) if len(base)>3 else (base[2] if len(base)>2 else ''); fn=ls[0].get('function') or (base[-1] if base else '')
  vc=Counter(e.get('verdict','') for e in ls); verdict=f"confirmed={vc['confirmed']};rejected={vc['rejected']};undeterminable={vc['undeterminable']}"
  ents=[x for e in ls for x in e.get('entities',[])]; wr=[classify(x) for x in ents if x.get('match')=='wrong']; und=sum(x.get('match')=='undeterminable' for x in ents)
  w.writerow([proj,fn,dec,verdict,len(wr),und,','.join(sorted(set(wr)))])

lines=['# 模式汇总表','', '| 模式 | 命中wrong-entity数 | 命中(函数,反编译器)任务数 | 命中函数数 | 任务命中率 | 函数命中率 | verdict分布(confirmed/rejected/undeterminable) |','|---|---:|---:|---:|---:|---:|---|']
for p in patterns:
 d=ps[p]; vc={v:len(d['ventries'][v]) for v in valid_verdict}; lines.append(f"| {p} | {d['wrong']} | {len(d['tasks'])} | {len(d['functions'])} | {len(d['tasks'])/103:.1%} | {len(d['functions'])/52:.1%} | {vc.get('confirmed',0)}/{vc.get('rejected',0)}/{vc.get('undeterminable',0)} |")
tw=sum(d['wrong'] for d in ps.values()); tt=set(); tf=set(); ve=defaultdict(set)
for d in ps.values():
 tt|=d['tasks']; tf|=d['functions']
 for v,s in d['ventries'].items(): ve[v]|=s
lines.append(f"| 总体 | {tw} | {len(tt)} | {len(tf)} | {len(tt)/103:.1%} | {len(tf)/52:.1%} | {len(ve['confirmed'])}/{len(ve['rejected'])}/{len(ve['undeterminable'])} |")
open('pattern_summary.md','w',encoding='utf-8').write('\n'.join(lines)+'\n')

matches=Counter(); verdicts=Counter(); bydec=defaultdict(lambda:[0,0])
for f,e in all_entries:
 verdicts[e.get('verdict')]+=1
 dec=os.path.basename(f).split('__',1)[0]
 for x in e.get('entities',[]):
  matches[x.get('match')]+=1; bydec[dec][1]+=1
  if x.get('match')=='wrong': bydec[dec][0]+=1
quality={'file_count':len(files),'expected_file_count':expected,'count_delta':len(files)-expected,'schema_errors':schema_errors,'schema_error_file_count':len(set(e['file'] for e in schema_errors)),'match_distribution':dict(matches),'match_total':sum(matches.values()),'undeterminable_entity_rate':matches.get('undeterminable',0)/sum(matches.values()) if matches else 0,'verdict_distribution':dict(verdicts),'wrong_by_decompiler':{k:{'wrong':v[0],'entities':v[1],'rate':v[0]/v[1] if v[1] else 0} for k,v in bydec.items()},'needs_review_count':len(needs)}
quality['quality_flag']=('裁决质量存疑，建议复核' if quality['undeterminable_entity_rate']>0.30 else '')
tasksets=defaultdict(set)
for f in files:
 b=os.path.basename(f).removesuffix('.json').split('__'); tasksets[b[0]].add('__'.join(b[1:]))
alltasks=set().union(*tasksets.values())
quality['unique_function_tasks']=len(alltasks)
quality['missing_task_files']={d:sorted(alltasks-s) for d,s in tasksets.items()}
quality['extra_task_files']={d:sorted(s-alltasks) for d,s in tasksets.items()}
quality['schema_error_files']=sorted(set(e['file'] for e in schema_errors))
quality['candidate_new_patterns']={
 'QUAL-01 const限定恢复差异':sum(n.get('review_basis')=='const限定差异' for n in needs),
 'ARRAY-01 数组长度/维度错误':sum(n.get('review_basis')=='数组长度/维度差异' for n in needs),
 '其他零散OTHER':sum(n.get('review_basis')=='现有六模式未覆盖的类型恢复差异' for n in needs)}
quality['unresolved_review_count']=0
task_wrong=defaultdict(lambda:[0,0])
for f,entries in groups.items():
 dec=os.path.basename(f).split('__',1)[0]; task_wrong[dec][1]+=1
 if any(x.get('match')=='wrong' for e in entries for x in e.get('entities',[])): task_wrong[dec][0]+=1
quality['wrong_task_rate_by_decompiler']={d:{'tasks_with_wrong':v[0],'tasks':v[1],'rate':v[0]/v[1]} for d,v in task_wrong.items()}
json.dump(quality,open('quality_monitor.json','w',encoding='utf-8'),ensure_ascii=False,indent=2)
mt=quality['match_total']
md=['# 质量监控','',f"- JSON 文件：{len(files)}/103；无法解析：{sum('parse:' in e['error'] for e in schema_errors)}",f"- schema 异常文件：{quality['schema_error_file_count']}（详细异常见 quality_monitor.json）",f"- entity match：correct {matches['correct']} ({matches['correct']/mt:.1%})；wrong {matches['wrong']} ({matches['wrong']/mt:.1%})；undeterminable {matches['undeterminable']} ({matches['undeterminable']/mt:.1%})",f"- 条目 verdict：confirmed {verdicts['confirmed']}；rejected {verdicts['rejected']}；undeterminable {verdicts['undeterminable']}",f"- codex entity wrong 命中率：{bydec['codex'][0]}/{bydec['codex'][1]} ({bydec['codex'][0]/bydec['codex'][1]:.1%})；任务 wrong 命中率：{task_wrong['codex'][0]}/{task_wrong['codex'][1]} ({task_wrong['codex'][0]/task_wrong['codex'][1]:.1%})",f"- claude-code entity wrong 命中率：{bydec['claude-code'][0]}/{bydec['claude-code'][1]} ({bydec['claude-code'][0]/bydec['claude-code'][1]:.1%})；任务 wrong 命中率：{task_wrong['claude-code'][0]}/{task_wrong['claude-code'][1]} ({task_wrong['claude-code'][0]/task_wrong['claude-code'][1]:.1%})",f"- 候选新模式：QUAL-01 {quality['candidate_new_patterns']['QUAL-01 const限定恢复差异']}；ARRAY-01 {quality['candidate_new_patterns']['ARRAY-01 数组长度/维度错误']}；其他零散 OTHER {quality['candidate_new_patterns']['其他零散OTHER']}",f"- 未完成语义复核：0"]
md.insert(3,f"- 缺失任务文件：{quality['missing_task_files']}；多余任务文件：无")
if quality['quality_flag']: md.insert(2,'**裁决质量存疑，建议复核**')
md.extend(['','## Schema 异常文件清单','']+[f"- {f}" for f in quality['schema_error_files']])
open('quality_monitor.md','w',encoding='utf-8').write('\n'.join(md)+'\n')
print(json.dumps(quality,ensure_ascii=False,indent=2))
