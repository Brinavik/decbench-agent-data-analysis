// Function: main @ 0x165c0
int main(int argc, const char **argv, const char **envp)
{
  int v5; // ebx
  long long v6; // r12
  struct timeval *v7; // r12
  FILE *tv_usec; // rsi
  const char **v9; // rbx
  const char *v10; // rdi
  FILE *v11; // rsi
  long long v12; // rbx
  const char *v13; // r8
  int v14; // ecx
  int v15; // r8d
  int v16; // r9d
  struct timeval *v17; // r12
  long long v18; // rdx
  struct timeval *v19; // rdi
  int tv_usec_high; // eax
  int v21; // edx
  unsigned int v22; // ecx
  long long v23; // rsi
  void *v24; // r14
  long long v25; // rax
  struct timeval *v26; // r8
  long long v27; // r15
  long long v28; // rdi
  unsigned int v29; // ebp
  unsigned int v30; // eax
  int v31; // r8d
  int v32; // r9d
  long long v33; // rax
  int v34; // ebp
  int v35; // r15d
  __suseconds_t v36; // rbp
  unsigned int v37; // eax
  int v38; // r8d
  int v39; // r9d
  __suseconds_t v40; // r15
  unsigned int v41; // eax
  int v42; // ecx
  int v43; // r8d
  int v44; // r9d
  struct timeval *v45; // rdi
  long long v46; // rax
  __time_t v47; // rax
  int v48; // ebp
  int v49; // ebp
  unsigned int v50; // r14d
  long long device_size2; // rax
  long long v52; // rbp
  __suseconds_t v53; // rdx
  bool v54; // cc
  char *v55; // r12
  char v56; // r14
  const unsigned short **v57; // rax
  __suseconds_t v58; // rdi
  struct timeval *v59; // r8
  long long v60; // r8
  struct timeval *v61; // r8
  const char *v62; // rax
  unsigned int v63; // eax
  int v64; // ecx
  int v65; // r8d
  int v66; // r9d
  long long v67; // rcx
  unsigned int v68; // eax
  long long v69; // rdx
  long long v70; // r8
  int v71; // eax
  long long v72; // rdx
  __time_t v73; // rdi
  struct timeval *v74; // rcx
  long long v75; // rsi
  unsigned int v76; // ebx
  unsigned int v77; // eax
  void *v78; // rsi
  long long v79; // rdx
  __time_t v80; // r12
  char *v81; // rsi
  long long bb_inode; // rax
  int v83; // r14d
  long long v84; // rdx
  int v85; // r12d
  long long v86; // rdx
  long long v87; // rcx
  struct timeval *v88; // r8
  __suseconds_t v89; // r14
  unsigned int v90; // esi
  int v91; // ecx
  int v92; // r8d
  int v93; // r9d
  unsigned int v94; // eax
  int v95; // ecx
  int v96; // r8d
  int v97; // r9d
  long long v98; // rbp
  __time_t v99; // r14
  unsigned int v100; // eax
  int v101; // r8d
  int v102; // r9d
  int *v103; // rbp
  unsigned int v104; // edx
  unsigned int v105; // ecx
  __time_t v106; // r12
  long long v107; // r14
  unsigned int v108; // eax
  int v109; // ecx
  int v110; // r8d
  int v111; // r9d
  int v112; // edx
  int v113; // ecx
  int v114; // r8d
  int v115; // r9d
  int v116; // r15d
  unsigned int v117; // ebx
  int v118; // ebp
  long long v119; // rsi
  int v120; // eax
  int v121; // ecx
  int v122; // r8d
  int v123; // r9d
  char *v124; // rax
  __time_t v125; // r12
  unsigned int v126; // eax
  int v127; // r8d
  int v128; // r9d
  long long v129; // r12
  long long v130; // rax
  int v131; // ebp
  struct timeval *v132; // r8
  long long i; // r14
  __suseconds_t v134; // rdi
  char *v135; // rax
  int v136; // r12d
  __suseconds_t v137; // r14
  unsigned int v138; // eax
  int v139; // r8d
  int v140; // r9d
  unsigned int v141; // eax
  int v142; // ecx
  int v143; // r8d
  int v144; // r9d
  struct timeval *v145; // rdi
  char *v146; // rax
  __suseconds_t v147; // r12
  unsigned int v148; // eax
  int v149; // r8d
  int v150; // r9d
  const char *v151; // r14
  unsigned int v152; // eax
  int v153; // ecx
  int v154; // r8d
  int v155; // r9d
  const char *v156; // rsi
  unsigned int v157; // eax
  int v158; // ecx
  int v159; // r8d
  int v160; // r9d
  unsigned int v161; // eax
  int v162; // r8d
  int v163; // r9d
  unsigned int v164; // eax
  int v165; // ecx
  int v166; // r8d
  int v167; // r9d
  char *v168; // rax
  __suseconds_t v169; // r14
  unsigned int v170; // eax
  int v171; // r8d
  int v172; // r9d
  char *v173; // rax
  int v174; // r15d
  unsigned int v175; // eax
  int v176; // ecx
  int v177; // r8d
  int v178; // r9d
  long long v179; // rax
  unsigned int v180; // eax
  int v181; // ecx
  int v182; // r8d
  int v183; // r9d
  unsigned int v184; // eax
  int v185; // ecx
  int v186; // r8d
  int v187; // r9d
  __suseconds_t v188; // r12
  const char *v189; // rsi
  unsigned int v190; // eax
  int v191; // ecx
  int v192; // r8d
  int v193; // r9d
  __suseconds_t v194; // r12
  unsigned int v195; // eax
  int v196; // ecx
  int v197; // r8d
  int v198; // r9d
  __suseconds_t v199; // r12
  unsigned int v200; // eax
  int v201; // r8d
  int v202; // r9d
  __time_t v203; // r13
  int v204; // eax
  struct timeval *v205; // r12
  int v206; // ebx
  long long v207; // rcx
  int *v208; // rdi
  __suseconds_t v209; // r12
  unsigned int v210; // eax
  int v211; // ecx
  int v212; // r8d
  int v213; // r9d
  int v214; // ebx
  __suseconds_t v215; // r12
  unsigned int v216; // eax
  int v217; // ecx
  int v218; // r8d
  int v219; // r9d
  unsigned int v220; // eax
  __suseconds_t v221; // r12
  unsigned int v222; // eax
  int v223; // ecx
  int v224; // r8d
  int v225; // r9d
  struct timeval *v226; // r12
  __suseconds_t v227; // rdi
  int v229; // eax
  int v230; // ecx
  int v231; // r8d
  int v232; // r9d
  int v233; // r14d
  long long v234; // r12
  unsigned int v235; // eax
  int v236; // r8d
  int v237; // r9d
  __suseconds_t v238; // r12
  unsigned int v239; // eax
  int v240; // ecx
  int v241; // r8d
  int v242; // r9d
  int v243; // r13d
  int v244; // r12d
  unsigned int v245; // eax
  int v246; // r8d
  int v247; // r9d
  unsigned int v248; // eax
  int v249; // r8d
  int v250; // r9d
  char v251; // [rsp+0h] [rbp-178h]
  char v252; // [rsp+0h] [rbp-178h]
  char v253; // [rsp+0h] [rbp-178h]
  char v254; // [rsp+0h] [rbp-178h]
  char v255; // [rsp+0h] [rbp-178h]
  unsigned int v256; // [rsp+Ch] [rbp-16Ch]
  __suseconds_t v257; // [rsp+20h] [rbp-158h]
  long long v258; // [rsp+28h] [rbp-150h]
  int v259; // [rsp+30h] [rbp-148h]
  unsigned int v260; // [rsp+34h] [rbp-144h]
  long long v261; // [rsp+38h] [rbp-140h]
  long long tv_sec; // [rsp+48h] [rbp-130h]
  int v263; // [rsp+50h] [rbp-128h] BYREF
  int v264; // [rsp+54h] [rbp-124h] BYREF
  int v265[2]; // [rsp+58h] [rbp-120h] BYREF
  void *v266; // [rsp+60h] [rbp-118h] BYREF
  long long v267; // [rsp+68h] [rbp-110h] BYREF
  struct timeval *v268; // [rsp+70h] [rbp-108h]
  int v269[2]; // [rsp+78h] [rbp-100h] BYREF
  long long v270[14]; // [rsp+80h] [rbp-F8h] BYREF
  unsigned int v271; // [rsp+F4h] [rbp-84h]
  unsigned int v272; // [rsp+F8h] [rbp-80h]
  unsigned int v273; // [rsp+FCh] [rbp-7Ch]
  char v274[56]; // [rsp+100h] [rbp-78h] BYREF
  unsigned long long v275; // [rsp+138h] [rbp-40h]

  v275 = __readfsqword(0x28u);
  *(long long *)v265 = 0;
  clear_problem_context(v270, argv, envp);
  sigcatcher_setup();
  setlocale(5, "");
  setlocale(0, "");
  bindtextdomain("e2fsprogs", "/usr/share/locale");
  textdomain("e2fsprogs");
  set_com_err_gettext(&gettext);
  v5 = ext2fs_parse_version_string("1.46.5");
  if ( v5 > (int)ext2fs_get_library_version(0, &v267) )
  {
    v168 = dcgettext(0, "Error: ext2fs library version out of date!\n", 5);
    __fprintf_chk(stderr, 1, "%s", v168);
    ++dword_B7134;
  }
  v6 = sub_1A330(argc, (char **)argv);
  if ( v6 )
  {
    v248 = (unsigned int)dcgettext(0, "while trying to initialize program", 5);
    com_err((unsigned int)"e2fsck", v6, (unsigned int)"%s", v248, v249, v250);
    exit(8);
  }
  sub_1A2B0();
  set_up_logging(v268);
  v7 = v268;
  tv_usec = (FILE *)v268[2].tv_usec;
  if ( tv_usec )
  {
    fputs("E2fsck run: ", tv_usec);
    if ( argc > 0 )
    {
      v9 = argv;
      while ( 1 )
      {
        v10 = *v9++;
        fputs(v10, (FILE *)v268[2].tv_usec);
        if ( &argv[(unsigned int)(argc - 1) + 1] == v9 )
          break;
        fputc(32, (FILE *)v268[2].tv_usec);
      }
    }
    fputc(10, (FILE *)v268[2].tv_usec);
    v7 = v268;
  }
  v11 = (FILE *)v7[3].tv_usec;
  if ( v11 )
  {
    fputs("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n", v11);
    __fprintf_chk(v268[3].tv_usec, 1, "<problem_log time=\"%lu\">\n", v268[52].tv_usec);
    __fprintf_chk(v268[3].tv_usec, 1, "<invocation prog=\"%s\"", *argv);
    if ( argc > 1 )
    {
      v12 = 1;
      do
      {
        v13 = argv[v12];
        v14 = v12++;
        __fprintf_chk(v268[3].tv_usec, 1, " arg%d=\"%s\"", v14, v13);
      }
      while ( argc != v12 );
    }
    fputs("/>\n", (FILE *)v268[3].tv_usec);
    v7 = v268;
  }
  init_resource_track(v7 + 40);
  v17 = v268;
  if ( (v268[4].tv_usec & 0x200000000LL) == 0 || dword_B7134 )
  {
    log_err(
      (int)v268,
      (unsigned int)"e2fsck %s (%s)\n",
      (unsigned int)"1.46.5",
      (unsigned int)"30-Dec-2021",
      v15,
      v16);
    v17 = v268;
    if ( dword_B7134 )
    {
      v243 = v267;
      v244 = error_message(2133571328);
      v245 = (unsigned int)dcgettext(0, "\tUsing %s, %s\n", 5);
      log_err((int)v268, v245, v244, v243, v246, v247);
      exit(0);
    }
  }
  sub_18290(v17);
  if ( (v268[4].tv_usec & 0xE00000000LL) == 0 && !LODWORD(v268[45].tv_usec) )
  {
    v146 = dcgettext(0, "need terminal for interactive repairs", 5);
    fatal_error(v268, v146);
  }
  v259 = 4096;
  v258 = 0;
  v268[6].tv_sec = v268[5].tv_usec;
  v261 = 0;
  v256 = 68157440;
  tv_sec = -1;
  v260 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        do
        {
          while ( 1 )
          {
            if ( getenv("TEST_IO_FLAGS") || getenv("TEST_IO_BLOCK") )
            {
              v266 = test_io_manager;
              test_io_backing_manager = (long long)unix_io_manager;
            }
            else
            {
              v266 = unix_io_manager;
            }
            profile_get_boolean(v268[54].tv_sec, "options", "old_bitmaps", 0, 0, &v263);
            if ( v263 )
              v256 |= 0x10000u;
            else
              v256 |= 0x30000u;
            v19 = v268;
            tv_usec_high = HIDWORD(v268[4].tv_usec);
            if ( (tv_usec_high & 1) == 0 )
            {
              v21 = HIDWORD(v268[7].tv_usec);
              v22 = v256 | 1;
              if ( (v21 & 6) != 6 )
                v22 = v256 | 0x4001;
              v18 = v21 & 4;
              v256 = v22;
              if ( (int)v18 )
              {
                v18 = v22;
                BYTE1(v18) = BYTE1(v22) & 0xBF;
                if ( (tv_usec_high & 0x100) == 0 )
                  v18 = v22;
                v256 = v18;
              }
            }
            if ( v268[58].tv_usec )
            {
              if ( (unsigned int)sub_18480(v268, &v266, v18) )
                exit(8);
              v19 = v268;
            }
            v23 = v256;
            v24 = v266;
            LODWORD(v19[8].tv_sec) = v256;
            v25 = sub_18830(v19, v256, v24, v265);
            v26 = v268;
            v27 = v25;
            if ( v268[6].tv_sec || (v268[4].tv_usec & 0x200000100LL) != 0 )
              goto LABEL_53;
            if ( v25 != 2133571480 && v25 != 2133571347 && v25 != 2133571388 )
              break;
            if ( v25 )
            {
              v23 = 68;
              v270[0] = v25;
              fix_problem(v268, 68, v270);
            }
            if ( !v261 )
            {
              v270[0] = 0;
              goto LABEL_42;
            }
LABEL_118:
            v23 = 69;
            v270[0] = v261;
            fix_problem(v268, 69, v270);
            v270[0] = 0;
            if ( v261 == 12 || v261 == 2133571398 )
            {
              v27 = v261;
              v26 = v268;
              goto LABEL_121;
            }
LABEL_42:
            v28 = *(long long *)v265;
            if ( (*(char *)(*(long long *)v265 + 18LL) & 1) != 0 )
            {
              ext2fs_free();
              *(long long *)v265 = 0;
LABEL_44:
              if ( v27 )
                v29 = (unsigned int)dcgettext(0, "Superblock invalid,", 5);
              else
                v29 = (unsigned int)dcgettext(0, "Group descriptors look bad...", 5);
              v257 = v268->tv_usec;
              v30 = (unsigned int)dcgettext(0, "%s: %s trying backup blocks...\n", 5);
              log_out((int)v268, v30, v257, v29, v31, v32, v251);
              tv_sec = v268[6].tv_sec;
              get_backup_sb(v268, *(long long *)v265, v268[1].tv_sec, v24);
              if ( *(long long *)v265 )
                ext2fs_close_free(v265);
              v23 = v256;
              v33 = sub_18830(v268, v256, v24, v265);
              v34 = v33;
              if ( v27 || !v33 )
              {
                v258 = v27;
                v26 = v268;
                v27 = v33;
              }
              else
              {
                if ( *(long long *)v265 )
                  ext2fs_close_free(v265);
                v35 = error_message(v34);
                v36 = v268->tv_usec;
                v37 = (unsigned int)dcgettext(0, "%s: %s while using the backup blocks", 5);
                log_out((int)v268, v37, v36, v35, v38, v39, v251);
                v40 = v268->tv_usec;
                v41 = (unsigned int)dcgettext(0, "%s: going back to original superblock\n", 5);
                log_out((int)v268, v41, v40, v42, v43, v44, v252);
                v45 = v268;
                v23 = v256;
                v268[6].tv_sec = tv_sec;
                v46 = sub_18830(v45, v256, v24, v265);
                v26 = v268;
                v258 = 0;
                v27 = v46;
              }
LABEL_53:
              if ( (unsigned long long)(v27 - 2133571395) <= 1 )
                goto LABEL_129;
              goto LABEL_54;
            }
            if ( *(int *)(*(long long *)v265 + 48LL) > 1u )
              goto LABEL_44;
            v26 = v268;
            if ( (unsigned long long)(v27 - 2133571395) <= 1 )
              goto LABEL_130;
LABEL_54:
            if ( !v27 )
              goto LABEL_55;
LABEL_121:
            v99 = v26[1].tv_sec;
            if ( v258 )
              v27 = v258;
            v100 = (unsigned int)dcgettext(0, "while trying to open %s", 5);
            com_err(v268->tv_usec, v27, v100, v99, v101, v102);
            if ( v27 == 2133571348 )
            {
              v164 = (unsigned int)dcgettext(
                                     0,
                                     "The filesystem revision is apparently too high for this version of e2fsck.\n"
                                     "(Or the filesystem superblock is corrupt)\n"
                                     "\n",
                                     5);
              log_out((int)v268, (unsigned int)"%s", v164, v165, v166, v167, v251);
              fix_problem(v268, 4, v270);
              goto LABEL_147;
            }
            if ( v27 <= 30 )
            {
              if ( v27 > 0 )
              {
                switch ( v27 )
                {
                  case 1LL:
                  case 13LL:
                    v151 = "r/o";
                    if ( (v268[4].tv_usec & 0x100000000LL) == 0 )
                      v151 = "r/w";
                    v152 = (unsigned int)dcgettext(0, "You must have %s access to the filesystem or be root\n", 5);
                    log_out((int)v268, v152, (int)v151, v153, v154, v155, v251);
                    goto LABEL_147;
                  case 2LL:
                    v156 = "Possibly non-existent device?\n";
                    goto LABEL_189;
                  case 6LL:
                    v156 = "Possibly non-existent or swap device?\n";
                    goto LABEL_189;
                  case 16LL:
                    v156 = "Filesystem mounted or opened exclusively by another program?\n";
                    goto LABEL_189;
                  case 30LL:
                    v156 = "Disk write-protected; use the -n option to do a read-only\ncheck of the device.\n";
                    goto LABEL_189;
                  default:
                    break;
                }
              }
LABEL_180:
              fix_problem(v268, 4, v270);
              if ( v27 == 2133571347 )
                check_plausibility(v268[1].tv_sec, 4, 0);
LABEL_147:
              fatal_error(v268, 0);
            }
            if ( v27 == 2133571364 )
            {
              v156 = "Could this be a zero-length partition?\n";
LABEL_189:
              v157 = (unsigned int)dcgettext(0, v156, 5);
              log_out((int)v268, (unsigned int)"%s", v157, v158, v159, v160, v251);
              goto LABEL_147;
            }
            if ( v27 != 2133571388 )
              goto LABEL_180;
            if ( (v256 & 0x800000) != 0 )
            {
              fix_problem(v268, 4, v270);
              goto LABEL_147;
            }
            if ( *(long long *)v265 )
              ext2fs_close_free(v265);
            v194 = v268->tv_usec;
            v195 = (unsigned int)dcgettext(0, "%s: Trying to load superblock despite errors...\n", 5);
            log_out((int)v268, v195, v194, v196, v197, v198, v251);
            v256 |= 0x800000u;
            if ( tv_sec != -1 )
              v268[6].tv_sec = tv_sec;
          }
          if ( v25 )
          {
            if ( (unsigned long long)(v25 - 2133571395) > 1 )
              goto LABEL_121;
LABEL_129:
            v28 = *(long long *)v265;
            if ( !*(long long *)v265 )
              goto LABEL_121;
LABEL_130:
            v103 = *(int **)(v28 + 32);
            if ( v103 )
            {
              v104 = v103[24] & 0xFFFC1821;
              v105 = v103[25] & 0xFFFF0884;
              v271 = v103[23] & 0xFFFFF1C0;
              v272 = v104;
              v273 = v105;
              if ( v271 || v105 | v104 )
              {
LABEL_133:
                v106 = v26[1].tv_sec;
                v107 = 0;
                v108 = (unsigned int)dcgettext(0, "%s has unsupported feature(s):", 5);
                log_err((int)v268, v108, v106, v109, v110, v111);
                do
                {
                  v116 = 32;
                  v117 = 1;
                  v118 = *(&v271 + v107);
                  do
                  {
                    while ( (v118 & v117) == 0 )
                    {
                      v117 *= 2;
                      if ( !--v116 )
                        goto LABEL_138;
                    }
                    v119 = v117;
                    v117 *= 2;
                    v120 = e2p_feature2string((unsigned int)v107, v119);
                    log_err((int)v268, (unsigned int)" %s", v120, v121, v122, v123);
                    --v116;
                  }
                  while ( v116 );
LABEL_138:
                  ++v107;
                }
                while ( v107 != 3 );
                log_err((int)v268, (unsigned int)"\n", v112, v113, v114, v115);
LABEL_140:
                v124 = dcgettext(0, "Get a newer version of e2fsck!", 5);
                fatal_error(v268, v124);
              }
            }
            goto LABEL_121;
          }
          v261 = ext2fs_check_desc(v265[0]);
          if ( v261 )
            goto LABEL_118;
          v26 = v268;
LABEL_55:
          v47 = *(long long *)v265;
          v48 = v26[4].tv_usec;
          *(int *)(*(long long *)v265 + 16LL) |= 0x200u;
          v49 = v48 & 0x800;
          if ( v49 )
            goto LABEL_62;
          v50 = 1024 << *(int *)(*(long long *)(v47 + 32) + 24LL);
          v23 = v50;
          device_size2 = ext2fs_get_device_size2(v26[1].tv_sec, v50, &v26[6].tv_usec);
          v270[0] = device_size2;
          if ( device_size2 == 16 )
          {
            v49 = 1;
            ext2fs_close_free(v265);
            v23 = v50;
            device_size2 = ext2fs_get_device_size2(v268[1].tv_sec, v50, &v268[6].tv_usec);
            v270[0] = device_size2;
          }
          v26 = v268;
          if ( device_size2 == 2133571408 )
          {
            v268[6].tv_usec = 0;
          }
          else if ( device_size2 )
          {
            fix_problem(v268, 12, v270);
            v145 = v268;
            LODWORD(v268[4].tv_usec) |= 1u;
            fatal_error(v145, 0);
          }
          LODWORD(v26[4].tv_usec) |= 0x800u;
        }
        while ( v49 );
        v47 = *(long long *)v265;
LABEL_62:
        v52 = *(long long *)(v47 + 32);
        v53 = v26[52].tv_usec;
        v26->tv_sec = v47;
        v54 = *(int *)(v52 + 76) <= 1u;
        *(long long *)(v47 + 184) = v53;
        if ( !v54 )
        {
          v125 = v26[1].tv_sec;
          v126 = (unsigned int)dcgettext(0, "while trying to open %s", 5);
          com_err(v268->tv_usec, 2133571348, v126, v125, v127, v128);
          goto LABEL_140;
        }
        v55 = (char *)v26[1].tv_usec;
        if ( !v55 )
        {
          if ( !*(char *)(v52 + 120)
            || (v23 = v52 + 120,
                v26[1].tv_usec = string_copy(v26, v52 + 120, 16),
                v26 = v268,
                (v55 = (char *)v268[1].tv_usec) == 0) )
          {
            v23 = v26[1].tv_sec;
            v26[1].tv_usec = string_copy(v26, v23, 0);
            v26 = v268;
            v55 = (char *)v268[1].tv_usec;
          }
        }
        v56 = *v55;
        if ( *v55 )
        {
          v57 = __ctype_b_loc();
          do
          {
            if ( ((*v57)[v56] & 0x2000) != 0 || v56 == 58 )
              *v55 = 95;
            v56 = *++v55;
          }
          while ( v56 );
          v26 = v268;
        }
        v58 = v26[3].tv_usec;
        if ( v58 )
        {
          __fprintf_chk(v58, 1, "<filesystem dev=\"%s\"", (const char *)v26[1].tv_sec);
          if ( !(unsigned int)uuid_is_null(v52 + 104) )
          {
            uuid_unparse(v52 + 104, v274);
            __fprintf_chk(v268[3].tv_usec, 1, " uuid=\"%s\"", v274);
          }
          v59 = v268;
          if ( *(char *)(v52 + 120) )
          {
            __fprintf_chk(v268[3].tv_usec, 1, " label=\"%.*s\"", 16, (const char *)(v52 + 120));
            v59 = v268;
          }
          v23 = v59[3].tv_usec;
          fputs("/>\n", (FILE *)v23);
        }
        ehandler_init(*(long long *)(*(long long *)v265 + 8LL));
        if ( !(unsigned int)sub_18200(*(long long *)(*(long long *)v265 + 32LL)) || (v256 & 0x100000) == 0 )
          break;
        if ( sub_18950(v60, v268) )
          fatal_error(v268, 0);
        ext2fs_close_free(v268);
        v256 &= ~0x100000u;
      }
      v61 = v268;
      if ( v268[2].tv_usec )
      {
        v62 = (const char *)e2p_uuid2str(v52 + 104);
        v23 = 1;
        __fprintf_chk(v268[2].tv_usec, 1, "Filesystem UUID: %s\n", v62);
        v61 = v268;
      }
      if ( (v61[7].tv_usec & 0x1100000000LL) == 0 )
      {
        v129 = e2fsck_check_ext3_journal(v61);
        if ( v129 )
        {
          v169 = v268[1].tv_usec;
          v170 = (unsigned int)dcgettext(0, "while checking journal for %s", 5);
          com_err(v268->tv_usec, v129, v170, v169, v171, v172);
          v173 = dcgettext(0, "Cannot proceed with file system check", 5);
          fatal_error(v268, v173);
        }
      }
      if ( !(unsigned int)sub_181F0(v52) )
        break;
      if ( (v26[4].tv_usec & 0x100000000LL) != 0 )
      {
        v63 = (unsigned int)dcgettext(
                              0,
                              "Warning: skipping journal recovery because doing a read-only filesystem check.\n",
                              5);
        v23 = (long long)"%s";
        log_out((int)v268, (unsigned int)"%s", v63, v64, v65, v66, v251);
        (*(void (**)(void))(*(long long *)(*(long long *)(v268->tv_sec + 8) + 8LL) + 56LL))();
        v26 = v268;
        break;
      }
      if ( (v26[4].tv_usec & 0x200) != 0 )
      {
        v147 = v26[1].tv_usec;
        v148 = (unsigned int)dcgettext(0, "unable to set superblock flags on %s\n", 5);
        com_err(v268->tv_usec, 0, v148, v147, v149, v150);
        fatal_error(v268, 0);
      }
      v130 = e2fsck_run_ext3_journal(v26);
      v131 = v130;
      if ( v130 == 2133571503 )
      {
        v189 = "Journal checksum error found in %s\n";
        v188 = v268[1].tv_usec;
        goto LABEL_210;
      }
      v132 = v268;
      if ( v130 == 2133571502 )
      {
        v188 = v268[1].tv_usec;
        v189 = "Journal corrupted in %s\n";
LABEL_210:
        v190 = (unsigned int)dcgettext(0, v189, 5);
        log_out((int)v268, v190, v188, v191, v192, v193, v251);
        v132 = v268;
        goto LABEL_162;
      }
      if ( v130 )
      {
        v199 = v268[1].tv_usec;
        v200 = (unsigned int)dcgettext(0, "while recovering journal of %s", 5);
        com_err(v268->tv_usec, v131, v200, v199, v201, v202);
        v132 = v268;
      }
LABEL_162:
      ext2fs_close_free(v132);
      LODWORD(v268[4].tv_usec) |= 0x200u;
    }
    v67 = *(int *)(v52 + 92) & 0xFFFFF1C0;
    v68 = *(int *)(v52 + 96) & 0xFFFC1821;
    v69 = *(int *)(v52 + 100) & 0xFFFF0884;
    v271 = v67;
    v272 = v68;
    v273 = v69;
    if ( (int)v67 || (unsigned int)v69 | v68 )
      goto LABEL_133;
    if ( (unsigned int)sub_18210(v52, v23, v69, v67, v26) && !*(long long *)(*(long long *)v265 + 360LL) )
    {
      v233 = *(unsigned short *)(v52 + 636);
      v234 = *(long long *)(v70 + 16);
      v235 = (unsigned int)dcgettext(0, "%s has unsupported encoding: %0x\n", 5);
      log_err((int)v268, v235, v234, v233, v236, v237);
      goto LABEL_140;
    }
    if ( *(long long *)(v70 + 96) && (*(char *)(v70 + 76) & 1) == 0 )
      ext2fs_mark_super_dirty(*(long long *)v265);
    v71 = sysconf(30);
    v73 = *(long long *)v265;
    v74 = v268;
    if ( v71 <= 0 )
      v71 = v259;
    v75 = *(unsigned int *)(*(long long *)v265 + 40LL);
    v76 = v71;
    v259 = v71;
    v77 = 1;
    if ( v76 >= (unsigned int)v75 )
    {
      v72 = v76 % (unsigned int)v75;
      v77 = v76 / (unsigned int)v75;
    }
    LODWORD(v268[54].tv_usec) = v77;
    if ( v74[6].tv_sec )
    {
      v75 = 4;
      set_latch_flags(80, 4, 0);
      v73 = *(long long *)v265;
    }
    ext2fs_mark_valid(v73, v75, v72);
    check_super_block(v268);
    if ( (v268[4].tv_usec & 3) != 0 )
      fatal_error(v268, 0);
    sub_18E40();
    check_resize_inode(v268);
    v78 = ptr;
    if ( ptr )
    {
      read_bad_blocks_file(v268, ptr, (unsigned int)dword_B712C);
    }
    else
    {
      v79 = (unsigned int)dword_B7138;
      if ( dword_B7138 )
      {
        v78 = 0;
        read_bad_blocks_file(v268, 0, dword_B7128 == 0);
      }
    }
    if ( (v268[4].tv_usec & 3) != 0 )
      fatal_error(v268, 0);
    v80 = *(long long *)v265;
    ext2fs_mark_valid(*(long long *)v265, v78, v79);
    v81 = (char *)(v80 + 136);
    bb_inode = ext2fs_read_bb_inode(v80, v80 + 136);
    if ( bb_inode )
    {
      v136 = error_message(bb_inode);
      v137 = v268->tv_usec;
      v138 = (unsigned int)dcgettext(0, "%s: %s while reading bad blocks inode\n", 5);
      log_out((int)v268, v138, v137, v136, v139, v140, v251);
      preenhalt(v268);
      v141 = (unsigned int)dcgettext(0, "This doesn't bode well, but we'll try to go on...\n", 5);
      v81 = "%s";
      log_out((int)v268, (unsigned int)"%s", v141, v142, v143, v144, v253);
    }
    v83 = -1;
    if ( *(char *)(v52 + 253) == 1 && !(unsigned int)sub_181C0(v52) )
      v83 = (*(int *)(v52 + 332) >> 20) | (*(int *)(v52 + 328) << 12);
    if ( (unsigned int)sub_181D0(v52) )
    {
      clear_problem_context(v270, v81, v84);
      v270[0] = quota_init_context(&v268[39].tv_usec, v268->tv_sec, 0);
      if ( v270[0] )
      {
        fix_problem(v268, 76, v270);
        fatal_error(v268, 0);
      }
    }
    v85 = e2fsck_run(v268);
    e2fsck_clear_progbar(v268);
    if ( !LODWORD(v268[32].tv_usec) && SLOBYTE(v268[4].tv_usec) < 0 && (unsigned int)fix_problem(v268, 393217, v270) )
    {
      if ( v83 <= 1023 )
      {
        ext2fs_get_journal_params(v269, *(long long *)v265);
      }
      else
      {
        v269[1] = 0;
        v269[0] = v83;
      }
      v174 = v269[0];
      v175 = (unsigned int)dcgettext(0, "Creating journal (%d blocks): ", 5);
      log_out((int)v268, v175, v174, v176, v177, v178, v251);
      fflush(stdout);
      v179 = ext2fs_add_journal_inode3(*(long long *)v265, v269, -1, 0);
      if ( v179 )
      {
        v229 = error_message(v179);
        log_out((int)v268, (unsigned int)"%s: while trying to create journal\n", v229, v230, v231, v232, v254);
      }
      else
      {
        v180 = (unsigned int)dcgettext(0, " Done.\n", 5);
        log_out((int)v268, (unsigned int)"%s", v180, v181, v182, v183, v254);
        v184 = (unsigned int)dcgettext(0, "\n*** journal has been regenerated ***\n", 5);
        log_out((int)v268, (unsigned int)"%s", v184, v185, v186, v187, v255);
      }
    }
    if ( (v85 & 1) != 0 )
    {
      v135 = dcgettext(0, "aborted", 5);
      fatal_error(v268, v135);
    }
    v88 = v268;
    if ( (v85 & 2) != 0 )
    {
      v89 = v268[1].tv_usec;
      if ( !v89 )
        v89 = v268[1].tv_sec;
      v90 = (unsigned int)dcgettext(0, "%s: e2fsck canceled.\n", 5);
      log_out((int)v268, v90, v89, v91, v92, v93, v251);
      v260 = 32;
    }
    else if ( v268[39].tv_usec && !LODWORD(v268[32].tv_usec) )
    {
      for ( i = 0; i != 3; ++i )
      {
        if ( *(int *)sub_18220(v52, (unsigned int)i, v86, v87, v88) )
        {
          v134 = v88[39].tv_usec;
          v264 = 0;
          v270[10] = i;
          if ( quota_compare_and_update(v134, (unsigned int)i, &v264) || v264 )
          {
            if ( (unsigned int)fix_problem(v268, 393218, v270) )
            {
              v270[0] = quota_write_inode(v268[39].tv_usec, (unsigned int)(1 << i));
              if ( v270[0] )
                fix_problem(v268, 393222, v270);
            }
          }
          v88 = v268;
        }
      }
      quota_release_context(&v88[39].tv_usec);
    }
    if ( v85 != 4 )
      break;
    v94 = (unsigned int)dcgettext(0, "Restarting e2fsck from the beginning...\n", 5);
    log_out((int)v268, (unsigned int)"%s", v94, v95, v96, v97, v251);
    v98 = e2fsck_reset_context(v268);
    if ( v98 )
    {
      v161 = (unsigned int)dcgettext(0, "while resetting context", 5);
      com_err(v268->tv_usec, v98, (unsigned int)"%s", v161, v162, v163);
      fatal_error(v268, 0);
    }
    ext2fs_close_free(v268);
  }
  v203 = *(long long *)v265;
  v204 = ext2fs_test_changed(*(long long *)v265);
  v205 = v268;
  v206 = v204;
  if ( (v268[4].tv_usec & 0x100000007LL) == 0 )
  {
    if ( (unsigned int)ext2fs_test_valid(v203) )
    {
      if ( (*(char *)(v52 + 58) & 1) == 0 )
        v260 |= 1u;
      *(short *)(v52 + 58) = 1;
      if ( (unsigned int)check_backup_super_block(v205) )
        *(int *)(*(long long *)v265 + 16LL) &= ~0x200u;
      v205 = v268;
    }
    else
    {
      *(short *)(v52 + 58) &= ~1u;
    }
    if ( (v205[4].tv_usec & 0x2000) == 0 )
      *(int *)(v52 + 64) = v205[52].tv_usec;
    v207 = 27;
    *(short *)(v52 + 52) = 0;
    v208 = (int *)(v52 + 404);
    while ( v207 )
    {
      *v208++ = 0;
      --v207;
    }
    v270[0] = ext2fs_set_gdt_csum(v205->tv_sec);
    if ( v270[0] )
      fix_problem(v268, 393219, v270);
    ext2fs_mark_super_dirty(*(long long *)v265);
    v205 = v268;
  }
  if ( !(unsigned int)sub_181E0(*(long long *)(v205->tv_sec + 32)) || (HIDWORD(v205[4].tv_usec) & 0x40008) != 0x40008 )
  {
    if ( (v205[4].tv_usec & 0x100000000LL) == 0 )
    {
      e2fsck_write_bitmaps(v205);
      if ( (*(char *)(*(long long *)v265 + 16LL) & 4) != 0 )
      {
        v270[0] = ext2fs_flush(v268->tv_sec);
        if ( v270[0] )
          fix_problem(v268, &loc_60004, v270);
      }
      v270[0] = (*(long long (**)(void))(*(long long *)(*(long long *)(v268->tv_sec + 8) + 8LL) + 56LL))();
      if ( v270[0] )
        fix_problem(v268, 393221, v270);
      v205 = v268;
    }
    if ( v206 )
    {
      if ( (v205[4].tv_usec & 0x4000) != 0 )
        v260 |= 1u;
      if ( (v205[4].tv_usec & 0x200000000LL) == 0 )
      {
        v238 = v205[1].tv_usec;
        v239 = (unsigned int)dcgettext(0, "\n%s: ***** FILE SYSTEM WAS MODIFIED *****\n", 5);
        log_out((int)v268, v239, v238, v240, v241, v242, v251);
        v205 = v268;
      }
      if ( (v205[7].tv_usec & 0x200000000LL) != 0 )
      {
        v209 = v205[1].tv_usec;
        v210 = (unsigned int)dcgettext(0, "%s: ***** REBOOT SYSTEM *****\n", 5);
        log_out((int)v268, v210, v209, v211, v212, v213, v251);
        v260 |= 2u;
        v205 = v268;
      }
    }
  }
  v214 = v260 & 0x20;
  if ( !(unsigned int)ext2fs_test_valid(*(long long *)v265) )
  {
    v221 = v205[1].tv_usec;
    v222 = (unsigned int)dcgettext(0, "\n%s: ********** WARNING: Filesystem still has errors **********\n\n", 5);
    log_out((int)v268, v222, v221, v223, v224, v225, v251);
    v205 = v268;
    v260 = v260 & 0xFFFFFFFA | 4;
    if ( v214 )
      goto LABEL_250;
    goto LABEL_258;
  }
  if ( (v260 & 0x20) == 0 )
  {
LABEL_258:
    sub_19400(v205);
    goto LABEL_259;
  }
  if ( (*(char *)(v52 + 58) & 2) != 0 )
  {
    v215 = v205[1].tv_usec;
    v216 = (unsigned int)dcgettext(0, "\n%s: ********** WARNING: Filesystem still has errors **********\n\n", 5);
    log_out((int)v268, v216, v215, v217, v218, v219, v251);
    v205 = v268;
    v260 = v260 & 0xFFFFFFFA | 4;
  }
LABEL_250:
  profile_get_boolean(v205[54].tv_sec, "options", "allow_cancellation", 0, 0, &v264);
  v260 &= ~1u;
  if ( v264 && (unsigned int)ext2fs_test_valid(*(long long *)v265) )
  {
    v220 = 0;
    if ( (*(short *)(v52 + 58) & 3) != 1 )
      v220 = v260;
    v260 = v220;
  }
LABEL_259:
  print_resource_track(v268, 0, &v268[40], *(long long *)(v268->tv_sec + 8));
  ext2fs_close_free(v268);
  free((void *)v268[39].tv_sec);
  v226 = v268;
  v227 = v268[2].tv_usec;
  if ( v227 )
  {
    __fprintf_chk(v227, 1, "Exit status: %d\n", v260);
    v226 = v268;
  }
  e2fsck_free_context(v226);
  remove_error_table(&et_ext2_error_table);
  remove_error_table(&et_prof_error_table);
  return v260;
}


// Function: signal_progress_on @ 0x18250
long long signal_progress_on()
{
  long long result; // rax

  result = e2fsck_global_ctx;
  if ( e2fsck_global_ctx )
    *(long long *)(e2fsck_global_ctx + 352) = sub_1B500;
  return result;
}


// Function: signal_cancel @ 0x18270
long long signal_cancel()
{
  long long result; // rax

  result = e2fsck_global_ctx;
  if ( !e2fsck_global_ctx )
    exit(32);
  *(int *)(e2fsck_global_ctx + 72) |= 2u;
  return result;
}


// Function: check_mount @ 0x18290
long long check_mount(long long a1)
{
  long long v1; // rax
  long long result; // rax
  int v3; // edx
  long long v4; // r12
  const char *v5; // rsi
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // r8d
  int v9; // r9d
  char *v10; // rax
  unsigned int v11; // eax
  int v12; // ecx
  int v13; // r8d
  int v14; // r9d
  char *v15; // rax
  long long v16; // r13
  int v17; // r12d
  unsigned int v18; // eax
  int v19; // r8d
  int v20; // r9d
  long long v21; // r12
  const char *v22; // rsi
  unsigned int v23; // eax
  int v24; // ecx
  int v25; // r8d
  int v26; // r9d
  char *v27; // rax

  v1 = ext2fs_check_if_mounted(*(long long *)(a1 + 16), a1 + 124);
  if ( v1 )
  {
    v16 = *(long long *)(a1 + 16);
    v17 = v1;
    v18 = (unsigned int)dcgettext(0, "while determining whether %s is mounted.", 5);
    return com_err((unsigned int)"ext2fs_check_if_mount", v17, v18, v16, v19, v20);
  }
  result = *(unsigned int *)(a1 + 124);
  if ( (result & 0x11) == 0 )
    return result;
  v3 = *(int *)(a1 + 76);
  if ( (*(int *)(a1 + 124) & 6) == 6 )
  {
    if ( (v3 & 0x200) == 0 )
      return result;
    if ( (v3 & 1) != 0 )
      goto LABEL_6;
LABEL_15:
    if ( (v3 & 0x100) == 0 || (result & 4) == 0 )
      goto LABEL_6;
    goto LABEL_5;
  }
  if ( (v3 & 1) == 0 )
    goto LABEL_15;
LABEL_5:
  if ( (v3 & 0x200) != 0 )
  {
LABEL_6:
    v4 = *(long long *)(a1 + 16);
    v5 = "%s is mounted.\n";
    if ( (result & 1) == 0 )
      v5 = "%s is in use.\n";
    v6 = (unsigned int)dcgettext(0, v5, 5);
    log_out(a1, v6, v4, v7, v8, v9);
    if ( !*(int *)(a1 + 728) || (*(char *)(a1 + 124) & 0x10) != 0 )
    {
      v10 = dcgettext(0, "Cannot continue, aborting.\n\n", 5);
      fatal_error(a1, v10);
    }
    puts("\a\a\a\a");
    v11 = (unsigned int)dcgettext(
                          0,
                          "\n"
                          "\n"
                          "WARNING!!!  The filesystem is mounted.   If you continue you ***WILL***\n"
                          "cause ***SEVERE*** filesystem damage.\n"
                          "\n",
                          5);
    log_out(a1, (unsigned int)"%s", v11, v12, v13, v14);
    puts("\a\a\a");
    v15 = dcgettext(0, "Do you really want to continue", 5);
    result = ask_yn(a1, v15, 0);
    if ( !(int)result )
    {
      v27 = dcgettext(0, "check aborted.\n", 5);
      __printf_chk(1, "%s", v27);
      exit(0);
    }
    return result;
  }
  v21 = *(long long *)(a1 + 16);
  v22 = "Warning!  %s is mounted.\n";
  if ( (result & 1) == 0 )
    v22 = "Warning!  %s is in use.\n";
  v23 = (unsigned int)dcgettext(0, v22, 5);
  return log_out(a1, v23, v21, v24, v25, v26);
}


// Function: e2fsck_setup_tdb @ 0x18480
long long e2fsck_setup_tdb(long long a1, long long *a2)
{
  char *v3; // rax
  char *v4; // rax
  const char *v5; // rbp
  unsigned int v6; // r13d
  char *v8; // rbp
  unsigned int v9; // eax
  int v10; // r8d
  int v11; // r9d
  long long v12; // rdi
  long long v13; // r13
  long long v14; // r12
  char *v15; // rax
  long long v16; // rcx
  int v17; // r14d
  char *v18; // r13
  size_t v19; // r15
  size_t v20; // rax
  void *v21; // rax
  void *v22; // r15
  char *v23; // rbp
  long long v24; // r12
  char *v25; // rax
  int v26; // eax
  unsigned int v27; // eax
  int v28; // r8d
  int v29; // r9d
  char *v30; // rdi
  char *s[9]; // [rsp+0h] [rbp-48h] BYREF

  s[1] = (char *)__readfsqword(0x28u);
  v3 = *(char **)(a1 + 936);
  s[0] = 0;
  if ( v3 && *v3 )
  {
    v8 = (char *)set_undo_io_backing_manager(*a2);
    if ( !v8 )
    {
      v12 = *(long long *)(a1 + 936);
      *a2 = undo_io_manager;
      v8 = (char *)set_undo_io_backup_file(v12);
      if ( !v8 )
      {
        v13 = *(long long *)(a1 + 16);
        v14 = *(long long *)(a1 + 936);
        v15 = dcgettext(
                0,
                "Overwriting existing filesystem; this can be undone using the command:\n    e2undo %s %s\n\n",
                5);
        v16 = v13;
        v6 = 0;
        __printf_chk(1, v15, v14, v16);
        return v6;
      }
    }
    v6 = (unsigned int)v8;
    goto LABEL_10;
  }
  v4 = getenv("E2FSPROGS_UNDO_DIR");
  s[0] = v4;
  v5 = v4;
  if ( !v4 )
  {
    profile_get_string(*(long long *)(a1 + 864), "defaults", "undo_dir", 0, "/var/lib/e2fsprogs", s);
    v23 = s[0];
    if ( !strcmp(s[0], "none") || !*v23 || (v26 = access(v23, 2), v23 = s[0], v26) )
    {
      v6 = 0;
      free(v23);
      return v6;
    }
    v8 = strdup(*(const char **)(a1 + 16));
    if ( !v8 )
    {
      v22 = 0;
      v6 = 12;
      LODWORD(v8) = 12;
LABEL_34:
      free(s[0]);
LABEL_21:
      free(v22);
LABEL_10:
      v9 = (unsigned int)dcgettext(0, "while trying to setup undo file\n", 5);
      com_err(*(long long *)(a1 + 8), (int)v8, (unsigned int)"%s", v9, v10, v11);
      return v6;
    }
    v17 = 1;
LABEL_15:
    v18 = __xpg_basename(v8);
    v19 = strlen(s[0]);
    v20 = strlen(v18);
    v21 = malloc(v19 + v20 + 16);
    v22 = v21;
    if ( v21 )
    {
      __sprintf_chk(v21, 1, -1, "%s/e2fsck-%s.e2undo", s[0], v18);
      free(v8);
      if ( unlink((const char *)v22) >= 0 || (v6 = *__errno_location(), v6 == 2) )
      {
        v8 = (char *)set_undo_io_backing_manager(*a2);
        if ( !v8 )
        {
          *a2 = undo_io_manager;
          v8 = (char *)set_undo_io_backup_file(v22);
          if ( !v8 )
          {
            v24 = *(long long *)(a1 + 16);
            v25 = dcgettext(
                    0,
                    "Overwriting existing filesystem; this can be undone using the command:\n    e2undo %s %s\n\n",
                    5);
            __printf_chk(1, v25, v22, v24);
            if ( v17 )
              free(s[0]);
            free(v22);
            return 0;
          }
        }
        v6 = (unsigned int)v8;
      }
      else
      {
        LODWORD(v8) = v6;
        v27 = (unsigned int)dcgettext(0, "while trying to delete %s", 5);
        com_err(*(long long *)(a1 + 8), v6, v27, (int)v22, v28, v29);
      }
    }
    else
    {
      v30 = v8;
      v6 = 12;
      LODWORD(v8) = 12;
      free(v30);
    }
    if ( !v17 )
      goto LABEL_21;
    goto LABEL_34;
  }
  if ( strcmp(v4, "none") )
  {
    if ( *v5 )
    {
      v17 = access(v5, 2);
      if ( !v17 )
      {
        v8 = strdup(*(const char **)(a1 + 16));
        if ( !v8 )
        {
          v22 = 0;
          v6 = 12;
          LODWORD(v8) = 12;
          goto LABEL_21;
        }
        goto LABEL_15;
      }
    }
  }
  return 0;
}


// Function: try_open_fs @ 0x18830
long long try_open_fs(long long a1, long long a2, long long a3, long long *a4)
{
  long long v6; // rcx
  char *v7; // rdi
  long long result; // rax
  int v9; // ebp
  int v10; // r15d

  *a4 = 0;
  v6 = *(long long *)(a1 + 96);
  v7 = *(char **)(a1 + 16);
  if ( v6 )
  {
    v9 = 7;
    v10 = 1024;
    if ( !*(int *)(a1 + 80) )
    {
      while ( 1 )
      {
        result = ext2fs_open2(v7, (long long)a4);
        if ( !result )
          break;
        v10 *= 2;
        if ( !--v9 )
          return result;
        if ( *a4 )
        {
          ext2fs_free();
          *a4 = 0;
        }
        v7 = *(char **)(a1 + 16);
      }
      goto LABEL_11;
    }
  }
  result = ext2fs_open2(v7, (long long)a4);
  if ( !result )
  {
LABEL_11:
    *(long long *)(*a4 + 224LL) = a1;
    e2fsck_set_bitmap_type(*a4, 2, "default", 0);
    return 0;
  }
  return result;
}


// Function: e2fsck_check_mmp @ 0x18950
long long e2fsck_check_mmp(long long a1, long long a2, long long a3)
{
  long long mem; // r12
  long long v4; // rdx
  unsigned int v5; // r13d
  unsigned int v6; // edx
  unsigned int v7; // ebp
  unsigned int v9; // eax
  int v10; // r8d
  int v11; // r9d
  unsigned int v12; // eax
  int v13; // r8d
  int v14; // r9d
  unsigned int v15; // eax
  int v16; // r8d
  int v17; // r9d
  long long v18; // r13
  unsigned int v19; // eax
  int v20; // ecx
  int v21; // r8d
  int v22; // r9d
  unsigned int v23; // eax
  int v24; // r8d
  int v25; // r9d
  int v26; // edx
  int v27; // ecx
  int v28; // r8d
  int v29; // r9d
  char v30[104]; // [rsp+0h] [rbp-98h] BYREF
  unsigned long long v31; // [rsp+68h] [rbp-30h]

  v31 = __readfsqword(0x28u);
  clear_problem_context(v30, a2, a3);
  if ( *(long long *)(a1 + 272) || (mem = ext2fs_get_mem(*(unsigned int *)(a1 + 40), a1 + 272)) == 0 )
  {
    mem = ext2fs_mmp_read(a1, *(long long *)(*(long long *)(a1 + 32) + 360LL));
    if ( !mem )
    {
      v4 = *(long long *)(a1 + 272);
      v5 = *(unsigned short *)(v4 + 112);
      v6 = *(int *)(v4 + 4);
      if ( v6 != -11711152 )
      {
        if ( v6 == -498250416 )
        {
          mem = 2133571468;
        }
        else
        {
          if ( v6 <= 0xE24D4D4F )
            goto LABEL_6;
          mem = 2133571470;
        }
LABEL_20:
        v15 = (unsigned int)dcgettext(0, "while checking MMP block", 5);
        com_err(*(long long *)(a2 + 8), mem, (unsigned int)"%s", v15, v16, v17);
        v18 = *(long long *)(a2 + 24);
        v19 = (unsigned int)dcgettext(
                              0,
                              "If you are sure the filesystem is not in use on any node, run:\n"
                              "'tune2fs -f -E clear_mmp %s'\n",
                              5);
        dump_mmp_msg(*(long long *)(a1 + 272), v19, v18, v20, v21, v22, v30[0]);
        return mem;
      }
LABEL_6:
      if ( v5 < *(unsigned short *)(*(long long *)(a1 + 32) + 358LL) )
        v5 = *(unsigned short *)(*(long long *)(a1 + 32) + 358LL);
      if ( v5 < 5 )
        v5 = 5;
      v7 = 2 * v5 + 1;
      if ( dword_B7130 || v7 > 0x14 )
      {
        v9 = (unsigned int)dcgettext(
                             0,
                             "MMP interval is %u seconds and total wait time is %u seconds. Please wait...\n",
                             5);
        log_out(a2, v9, v5, 2 * v7, v10, v11);
      }
      return mem;
    }
  }
  if ( mem == 2133571469 )
  {
    if ( (unsigned int)fix_problem(a2, 66, v30) )
    {
      mem = 0;
      *(long long *)(*(long long *)(a1 + 32) + 360LL) = 0;
      ext2fs_mark_super_dirty(a1);
    }
  }
  else
  {
    switch ( mem )
    {
      case 2133571466LL:
        if ( (unsigned int)fix_problem(a2, 67, v30) )
          goto LABEL_23;
        return mem;
      case 2133571467LL:
        v23 = (unsigned int)dcgettext(0, "while checking MMP block", 5);
        com_err(*(long long *)(a2 + 8), 2133571467, (unsigned int)"%s", v23, v24, v25);
        dump_mmp_msg(*(long long *)(a1 + 272), 0, v26, v27, v28, v29, v30[0]);
        return mem;
      case 2133571468LL:
      case 2133571470LL:
        goto LABEL_20;
      case 2133571482LL:
        if ( (unsigned int)fix_problem(a2, 71, v30) )
        {
LABEL_23:
          mem = 0;
          ext2fs_mmp_clear(a1);
        }
        break;
      default:
        v12 = (unsigned int)dcgettext(0, "while reading MMP block", 5);
        com_err(*(long long *)(a2 + 8), mem, (unsigned int)"%s", v12, v13, v14);
        break;
    }
  }
  return mem;
}


// Function: is_on_batt @ 0x18c40
long long is_on_batt()
{
  FILE *v0; // rax
  FILE *v1; // rdi
  FILE *v2; // rax
  FILE *v3; // rbp
  DIR *v5; // rbp
  struct dirent *v6; // rax
  const char *d_name; // r15
  FILE *v8; // rax
  FILE *v9; // r15
  int v10; // [rsp+Ch] [rbp-20Ch] BYREF
  char s1[160]; // [rsp+10h] [rbp-208h] BYREF
  char filename[296]; // [rsp+B0h] [rbp-168h] BYREF
  unsigned long long v13; // [rsp+1D8h] [rbp-40h]

  v13 = __readfsqword(0x28u);
  v0 = fopen("/sys/class/power_supply/AC/online", "r");
  if ( v0 )
  {
    v1 = v0;
    if ( (unsigned int)__isoc99_fscanf(v0, "%u\n", &v10) == 1 )
    {
      fclose(v1);
      return v10 == 0;
    }
    fclose(v1);
  }
  v2 = fopen("/proc/apm", "r");
  v3 = v2;
  if ( v2 )
  {
    if ( (unsigned int)__isoc99_fscanf(v2, "%79s %79s %79s %x", s1, s1, s1, &v10) != 4 )
      v10 = 1;
    fclose(v3);
    return v10 != 1;
  }
  else
  {
    v5 = opendir("/proc/acpi/ac_adapter");
    if ( v5 )
    {
      while ( 1 )
      {
        v6 = readdir(v5);
        if ( !v6 )
          break;
        d_name = v6->d_name;
        if ( strncmp(".", v6->d_name, 1u) )
        {
          __snprintf_chk(filename, 285, 1, 285, "/proc/acpi/ac_adapter/%s/state", d_name);
          v8 = fopen(filename, "r");
          v9 = v8;
          if ( v8 )
          {
            if ( (unsigned int)__isoc99_fscanf(v8, "%79s %79s", &s1[80], s1) != 2 )
              s1[0] = 0;
            fclose(v9);
            if ( !strncmp(s1, "off-line", 8u) )
            {
              closedir(v5);
              return 1;
            }
          }
        }
      }
      closedir(v5);
    }
    return 0;
  }
}


// Function: check_if_skip @ 0x18e40
unsigned long long check_if_skip(long long *a1)
{
  long long v1; // r13
  int v2; // eax
  int v4; // ebx
  char *v5; // rsi
  long long v6; // rax
  long long v7; // r14
  short v8; // r12
  unsigned int v9; // r14d
  long long v10; // rdx
  long long v11; // rcx
  int v12; // r8d
  int v13; // r9d
  char *v14; // r12
  int v15; // ecx
  int v16; // r8d
  int v17; // r9d
  unsigned int v18; // eax
  int v19; // ecx
  int v20; // r8d
  int v21; // r9d
  unsigned int v22; // ecx
  int v23; // r8d
  int v24; // r9d
  long long v25; // rax
  long long v26; // rdx
  int v27; // eax
  long long v28; // rax
  long long v29; // rdx
  int v30; // r14d
  int v31; // r12d
  int v32; // eax
  long long v33; // r15
  int v34; // r12d
  int *v35; // rax
  int v36; // r8d
  int v37; // r9d
  long long v38; // rdx
  long long v39; // rcx
  int v40; // eax
  int v41; // r12d
  const char *v42; // rsi
  unsigned int v43; // eax
  int v44; // ecx
  int v45; // r8d
  int v46; // r9d
  long long v47; // rdx
  char *v48; // rax
  long long v49; // rax
  unsigned int v50; // eax
  int v51; // ecx
  int v52; // r8d
  int v53; // r9d
  long long v54; // rax
  unsigned int v55; // eax
  int v56; // ecx
  int v57; // r8d
  int v58; // r9d
  unsigned int v59; // [rsp-8h] [rbp-D0h]
  int v60; // [rsp+8h] [rbp-C0h]
  int v61; // [rsp+Ch] [rbp-BCh]
  int v62; // [rsp+18h] [rbp-B0h] BYREF
  int v63; // [rsp+1Ch] [rbp-ACh] BYREF
  char v64[8]; // [rsp+20h] [rbp-A8h] BYREF
  int v65; // [rsp+28h] [rbp-A0h]
  int v66; // [rsp+2Ch] [rbp-9Ch]
  long long v67; // [rsp+48h] [rbp-80h]
  long long v68; // [rsp+50h] [rbp-78h]
  unsigned long long v69; // [rsp+88h] [rbp-40h]

  v1 = *a1;
  v69 = __readfsqword(0x28u);
  v2 = sub_18C40();
  if ( (*((char *)a1 + 73) & 0x40) == 0 )
  {
    v4 = v2;
    profile_get_boolean(a1[108], "options", "broken_system_clock", 0, 0, &v63);
    if ( (*((char *)a1 + 73) & 0x20) != 0 )
      v63 = 1;
    v5 = "options";
    profile_get_boolean(a1[108], "options", "defer_check_on_battery", 0, 1, &v62);
    if ( !v62 )
      v4 = 0;
    if ( !ptr && !(dword_B7138 | *((int *)a1 + 19) & 0x100) )
    {
      if ( (*((int *)a1 + 19) & 0x1000) != 0 )
        goto LABEL_39;
      v6 = *(long long *)(v1 + 32);
      v7 = *(unsigned int *)(v6 + 64);
      if ( a1[105] < v7 )
        v7 -= a1[106];
      v8 = *(short *)(v6 + 58);
      if ( (v8 & 2) == 0 && (unsigned int)ext2fs_test_valid(v1) )
      {
        if ( (v8 & 1) != 0 )
        {
          if ( (unsigned int)check_backup_super_block(a1) )
          {
            v5 = " primary superblock features different from backup";
            v9 = 0;
            v14 = dcgettext(0, " primary superblock features different from backup", 5);
          }
          else
          {
            v10 = *(long long *)(v1 + 32);
            if ( *(short *)(v10 + 54) > 0 && (v22 = *(unsigned short *)(v10 + 52), v22 >= *(short *)(v10 + 54)) )
            {
              v5 = " has been mounted %u times without being checked";
              v14 = dcgettext(0, " has been mounted %u times without being checked", 5);
              v49 = *(long long *)(v1 + 32);
              v9 = *(unsigned short *)(v49 + 52);
              if ( v4 && 2 * *(short *)(v49 + 54) > v9 )
                goto LABEL_25;
            }
            else
            {
              v25 = *(unsigned int *)(v10 + 68);
              if ( v63 )
              {
                if ( (int)v25 )
                {
                  log_out((int)a1, (unsigned int)"%s: ", a1[3], v22, v23, v24);
                  v55 = (unsigned int)dcgettext(0, "ignoring check interval, broken_system_clock set\n", 5);
                  v5 = "%s";
                  log_out((int)a1, (unsigned int)"%s", v55, v56, v57, v58);
                }
                goto LABEL_25;
              }
              if ( !(int)v25 )
                goto LABEL_25;
              v47 = a1[105];
              if ( v47 < v7 )
              {
                v5 = " has filesystem last checked time in the future";
                v14 = dcgettext(0, " has filesystem last checked time in the future", 5);
                if ( v4 )
                  goto LABEL_25;
                v9 = 0;
              }
              else
              {
                v10 = v47 - v7;
                if ( v10 < v25 )
                  goto LABEL_25;
                v48 = dcgettext(0, " has gone %u days without being checked", 5);
                v5 = *(char **)(v1 + 32);
                v14 = v48;
                v11 = a1[105] - *((unsigned int *)v5 + 16);
                v10 = (long long)((unsigned __int128)(0x1845C8A0CE512957LL * (__int128)v11) >> 64) >> 13;
                v9 = (int)v11 / 86400;
                if ( v4 )
                {
                  if ( v11 < (unsigned int)(2 * *((int *)v5 + 17)) )
                    goto LABEL_25;
                }
              }
            }
          }
        }
        else
        {
          v5 = " was not cleanly unmounted";
          v9 = 0;
          v14 = dcgettext(0, " was not cleanly unmounted", 5);
        }
      }
      else
      {
        v5 = " contains a file system with errors";
        v9 = 0;
        v14 = dcgettext(0, " contains a file system with errors", 5);
      }
      if ( v14 )
      {
        log_out((int)a1, (unsigned int)"%s", a1[3], v11, v12, v13);
        log_out((int)a1, (int)v14, v9, v15, v16, v17);
        v18 = (unsigned int)dcgettext(0, ", check forced.\n", 5);
        log_out((int)a1, (unsigned int)"%s", v18, v19, v20, v21);
        return v69 - __readfsqword(0x28u);
      }
LABEL_25:
      clear_problem_context(v64, v5, v10);
      v26 = *(unsigned int *)(*(long long *)(v1 + 32) + 16LL);
      v27 = *((int *)a1 + 30);
      v65 = v26;
      v66 = v27;
      if ( (int)v26 != v27 && (*((char *)a1 + 76) & 1) == 0 )
      {
        v5 = (char *)(&word_3E + 1);
        if ( (unsigned int)fix_problem(a1, 63, v64) )
        {
          *(int *)(*(long long *)(v1 + 32) + 16LL) = *((int *)a1 + 30);
          ext2fs_mark_super_dirty(v1);
        }
      }
      clear_problem_context(v64, v5, v26);
      v28 = ext2fs_free_blocks_count(*(long long *)(v1 + 32));
      v29 = a1[14];
      v67 = v28;
      v68 = v29;
      if ( v28 != v29 && (*((char *)a1 + 76) & 1) == 0 && (unsigned int)fix_problem(a1, 64, v64) )
      {
        ext2fs_free_blocks_count_set(*(long long *)(v1 + 32), a1[14]);
        ext2fs_mark_super_dirty(v1);
      }
      v30 = ext2fs_blocks_count(*(long long *)(v1 + 32));
      v31 = ext2fs_blocks_count(*(long long *)(v1 + 32));
      v32 = ext2fs_free_blocks_count(*(long long *)(v1 + 32));
      v33 = a1[3];
      v34 = v31 - v32;
      v35 = *(int **)(v1 + 32);
      v61 = *v35;
      v60 = *v35 - v35[4];
      v59 = (unsigned int)dcgettext(0, "%s: clean, %u/%u files, %llu/%llu blocks", 5);
      log_out((int)a1, v59, v33, v60, v61, v34);
      v38 = *(long long *)(v1 + 32);
      LODWORD(v39) = v30;
      if ( *(short *)(v38 + 54) <= 0 )
      {
        if ( v63 )
          goto LABEL_38;
        v54 = *(unsigned int *)(v38 + 68);
        if ( !(int)v54 )
          goto LABEL_38;
        v39 = *(unsigned int *)(v38 + 64);
        v38 = a1[105] - v39;
        if ( v54 > v38 )
          goto LABEL_38;
      }
      else
      {
        v40 = *(short *)(v38 + 54) - *(unsigned short *)(v38 + 52);
        LODWORD(v39) = 1;
        v41 = v40;
        if ( v40 <= 0 )
          v41 = 1;
        if ( !v63 )
        {
          v39 = *(unsigned int *)(v38 + 68);
          if ( (int)v39 )
          {
            v38 = a1[105] - *(unsigned int *)(v38 + 64);
            if ( v38 >= v39 )
              goto LABEL_35;
          }
        }
        if ( v40 > 5 )
        {
LABEL_38:
          log_out((int)a1, (unsigned int)"\n", v38, v39, v36, v37);
LABEL_39:
          ext2fs_close_free(a1);
          e2fsck_free_context(a1);
          exit(0);
        }
        if ( v40 > 1 )
        {
          v50 = (unsigned int)dcgettext(0, " (check in %ld mounts)", 5);
          log_out((int)a1, v50, v41, v51, v52, v53);
          goto LABEL_38;
        }
      }
LABEL_35:
      v42 = " (check deferred; on battery)";
      if ( !v4 )
        v42 = " (check after next mount)";
      v43 = (unsigned int)dcgettext(0, v42, 5);
      log_out((int)a1, (unsigned int)"%s", v43, v44, v45, v46);
      goto LABEL_38;
    }
  }
  return v69 - __readfsqword(0x28u);
}


// Function: show_stats @ 0x19400
unsigned long long show_stats(long long *a1)
{
  long long v2; // rbx
  int v3; // eax
  int *v4; // rdi
  unsigned int v5; // r14d
  long long v6; // r13
  int v7; // ecx
  int v8; // edi
  int v9; // ebx
  int v10; // edx
  int v11; // ecx
  int v12; // r8d
  int v13; // r9d
  unsigned int v14; // eax
  int v15; // r8d
  int v16; // r9d
  unsigned int v17; // r12d
  unsigned int v18; // eax
  int v19; // r9d
  unsigned int v20; // r12d
  unsigned int v21; // eax
  int v22; // r9d
  int v23; // ebx
  int v24; // r14d
  int v25; // r12d
  unsigned int v26; // eax
  int v27; // r9d
  long long v28; // rax
  int v29; // ebx
  int v31; // ebx
  unsigned int v32; // eax
  int v33; // r8d
  int v34; // r9d
  unsigned int v35; // r13d
  unsigned int v36; // eax
  int v37; // ecx
  int v38; // r8d
  int v39; // r9d
  unsigned int v40; // r13d
  unsigned int v41; // eax
  int v42; // ecx
  int v43; // r8d
  int v44; // r9d
  unsigned int v45; // r13d
  unsigned int v46; // eax
  int v47; // ecx
  int v48; // r8d
  int v49; // r9d
  unsigned int v50; // r13d
  unsigned int v51; // eax
  int v52; // ecx
  int v53; // r8d
  int v54; // r9d
  unsigned int v55; // r13d
  unsigned int v56; // eax
  int v57; // ecx
  int v58; // r8d
  int v59; // r9d
  unsigned int v60; // r13d
  unsigned int v61; // eax
  int v62; // ecx
  int v63; // r8d
  int v64; // r9d
  unsigned int v65; // r13d
  unsigned int v66; // eax
  int v67; // ecx
  int v68; // r8d
  int v69; // r9d
  int v70; // r13d
  unsigned int v71; // eax
  int v72; // ecx
  int v73; // r8d
  int v74; // r9d
  unsigned int v75; // r13d
  unsigned int v76; // eax
  int v77; // ecx
  int v78; // r8d
  int v79; // r9d
  unsigned int v80; // r13d
  unsigned int v81; // eax
  int v82; // ecx
  int v83; // r8d
  int v84; // r9d
  unsigned int v85; // r13d
  unsigned int v86; // eax
  int v87; // ecx
  int v88; // r8d
  int v89; // r9d
  int v90; // edx
  int v91; // ecx
  int v92; // r8d
  int v93; // r9d
  unsigned int v94; // eax
  int v95; // ecx
  int v96; // r8d
  int v97; // r9d
  int v99; // ebx
  int v100; // edx
  int v101; // ecx
  int v102; // r8d
  long long v103; // rax
  long long v104; // rdi
  long long v105; // r9
  int *v106; // r15
  int v107; // r14d
  unsigned int v108; // r13d
  long long v109; // rsi
  int v110; // eax
  int v111; // ecx
  int v112; // r8d
  int v113; // r9d
  long long v114; // r12
  unsigned int v115; // eax
  unsigned int v116; // eax
  int v117; // ecx
  int v118; // r8d
  int v119; // r9d
  int v120; // ecx
  int v121; // r8d
  int v122; // r9d
  int v123; // eax
  int v124; // edx
  int v125; // [rsp+0h] [rbp-78h]
  unsigned long long v126; // [rsp+8h] [rbp-70h]
  int v127; // [rsp+10h] [rbp-68h]
  unsigned int n; // [rsp+18h] [rbp-60h]
  int n_4; // [rsp+1Ch] [rbp-5Ch]
  int v130; // [rsp+20h] [rbp-58h]
  int v131; // [rsp+24h] [rbp-54h]
  int v132; // [rsp+28h] [rbp-50h]
  int v133; // [rsp+2Ch] [rbp-4Ch]
  unsigned int v134; // [rsp+34h] [rbp-44h] BYREF
  unsigned long long v135; // [rsp+38h] [rbp-40h]

  v2 = *a1;
  v135 = __readfsqword(0x28u);
  n_4 = *((int *)a1 + 184);
  v130 = *((int *)a1 + 192);
  v3 = *((int *)a1 + 188);
  v4 = *(int **)(v2 + 32);
  v131 = v3;
  v127 = *v4;
  v5 = *v4 - v4[4];
  n = v5;
  v125 = ext2fs_blocks_count(v4);
  v6 = ext2fs_blocks_count(*(long long *)(v2 + 32));
  v126 = v6 - ext2fs_free_blocks_count(*(long long *)(v2 + 32));
  if ( v5 )
  {
    v7 = *((int *)a1 + 198);
    v8 = *((int *)a1 + 199);
    v132 = (int)(10000 * v7 / v5 + 5) / 10;
    v133 = (int)(10000 * v8 / v5 + 5) / 10;
    v9 = (int)(10000 * (v7 + v8) / v5 + 5) / 10;
  }
  else
  {
    v133 = 0;
    v9 = 0;
    v132 = 0;
  }
  if ( dword_B7130 )
  {
    profile_get_boolean(a1[108], "options", "report_features", 0, 0, &v134);
    if ( dword_B7130 && v134 )
    {
      v99 = 0;
      log_out((int)a1, (unsigned int)"\nFilesystem features:", v10, v11, v12, v13);
      v103 = *a1;
      v104 = 0;
      v134 = 0;
      v105 = *(long long *)(v103 + 32);
      v106 = (int *)(v105 + 92);
      do
      {
        v107 = 32;
        v108 = 1;
        do
        {
          while ( (*v106 & v108) == 0 )
          {
            v108 *= 2;
            if ( !--v107 )
              goto LABEL_17;
          }
          v109 = v108;
          ++v99;
          v108 *= 2;
          v110 = e2p_feature2string(v104, v109);
          log_out((int)a1, (unsigned int)" %s", v110, v111, v112, v113);
          v104 = v134;
          --v107;
        }
        while ( v107 );
LABEL_17:
        v104 = (unsigned int)(v104 + 1);
        ++v106;
        v134 = v104;
      }
      while ( (int)v104 <= 2 );
      if ( !v99 )
        log_out((int)a1, (unsigned int)" (none)", v100, v101, v102, v105);
      log_out((int)a1, (unsigned int)"\n", v100, v101, v102, v105);
    }
    v14 = (unsigned int)dcngettext(
                          0,
                          "\n%12u inode used (%2.2f%%, out of %u)\n",
                          "\n%12u inodes used (%2.2f%%, out of %u)\n",
                          n,
                          5);
    log_out((int)a1, v14, n, v127, v15, v16);
    v17 = *((int *)a1 + 198);
    v18 = (unsigned int)dcngettext(
                          0,
                          "%12u non-contiguous file (%0d.%d%%)\n",
                          "%12u non-contiguous files (%0d.%d%%)\n",
                          v17,
                          5);
    log_out((int)a1, v18, v17, v132 / 10, v132 % 10, v19);
    v20 = *((int *)a1 + 199);
    v21 = (unsigned int)dcngettext(
                          0,
                          "%12u non-contiguous directory (%0d.%d%%)\n",
                          "%12u non-contiguous directories (%0d.%d%%)\n",
                          v20,
                          5);
    log_out((int)a1, v21, v20, v133 / 10, v133 % 10, v22);
    v23 = *((int *)a1 + 197);
    v24 = *((int *)a1 + 196);
    v25 = *((int *)a1 + 195);
    v26 = (unsigned int)dcgettext(0, "             # of inodes with ind/dind/tind blocks: %u/%u/%u\n", 5);
    log_out((int)a1, v26, v25, v24, v23, v27);
    v28 = 4;
    while ( 1 )
    {
      v29 = v28;
      if ( *((int *)a1 + v28 + 204) )
        break;
      if ( v28-- == 0 )
        goto LABEL_8;
    }
    v116 = (unsigned int)dcgettext(0, "             Extent depth histogram: ", 5);
    log_out((int)a1, (unsigned int)"%s", v116, v117, v118, v119);
    v134 = 0;
    v123 = 0;
    while ( 1 )
    {
      log_out((int)a1, (unsigned int)"%u", *((int *)a1 + v123 + 204), v120, v121, v122);
      v124 = v134;
      v123 = ++v134;
      if ( v124 >= v29 )
        break;
      if ( v123 )
      {
        fputc(47, stdout);
        v123 = v134;
      }
    }
    log_out((int)a1, (unsigned int)"\n", v124, v120, v121, v122);
LABEL_8:
    v31 = 2 * n_4 - 1;
    v32 = (unsigned int)dcngettext(
                          0,
                          "%12llu block used (%2.2f%%, out of %llu)\n",
                          "%12llu blocks used (%2.2f%%, out of %llu)\n",
                          v126,
                          5);
    log_out((int)a1, v32, v126, v125, v33, v34);
    v35 = *((int *)a1 + 193);
    v36 = (unsigned int)dcngettext(0, "%12u bad block\n", "%12u bad blocks\n", v35, 5);
    log_out((int)a1, v36, v35, v37, v38, v39);
    v40 = *((int *)a1 + 200);
    v41 = (unsigned int)dcngettext(0, "%12u large file\n", "%12u large files\n", v40, 5);
    log_out((int)a1, v41, v40, v42, v43, v44);
    v45 = *((int *)a1 + 185);
    v46 = (unsigned int)dcngettext(0, "\n%12u regular file\n", "\n%12u regular files\n", v45, 5);
    log_out((int)a1, v46, v45, v47, v48, v49);
    v50 = *((int *)a1 + 184);
    v51 = (unsigned int)dcngettext(0, "%12u directory\n", "%12u directories\n", v50, 5);
    log_out((int)a1, v51, v50, v52, v53, v54);
    v55 = *((int *)a1 + 187);
    v56 = (unsigned int)dcngettext(0, "%12u character device file\n", "%12u character device files\n", v55, 5);
    log_out((int)a1, v56, v55, v57, v58, v59);
    v60 = *((int *)a1 + 186);
    v61 = (unsigned int)dcngettext(0, "%12u block device file\n", "%12u block device files\n", v60, 5);
    log_out((int)a1, v61, v60, v62, v63, v64);
    v65 = *((int *)a1 + 191);
    v66 = (unsigned int)dcngettext(0, "%12u fifo\n", "%12u fifos\n", v65, 5);
    log_out((int)a1, v66, v65, v67, v68, v69);
    v70 = *((int *)a1 + 188) - v31;
    v71 = (unsigned int)dcngettext(0, "%12u link\n", "%12u links\n", (unsigned int)(v131 - v31), 5);
    log_out((int)a1, v71, v70, v72, v73, v74);
    v75 = *((int *)a1 + 189);
    v76 = (unsigned int)dcngettext(0, "%12u symbolic link", "%12u symbolic links", v75, 5);
    log_out((int)a1, v76, v75, v77, v78, v79);
    v80 = *((int *)a1 + 190);
    v81 = (unsigned int)dcngettext(0, " (%u fast symbolic link)\n", " (%u fast symbolic links)\n", v80, 5);
    log_out((int)a1, v81, v80, v82, v83, v84);
    v85 = *((int *)a1 + 194);
    v86 = (unsigned int)dcngettext(0, "%12u socket\n", "%12u sockets\n", v85, 5);
    log_out((int)a1, v86, v85, v87, v88, v89);
    log_out((int)a1, (unsigned int)"------------\n", v90, v91, v92, v93);
    v94 = (unsigned int)dcngettext(0, "%12u file\n", "%12u files\n", (unsigned int)(v130 - v31), 5);
    log_out((int)a1, v94, v130 - v31, v95, v96, v97);
  }
  else
  {
    v114 = a1[3];
    v115 = (unsigned int)dcgettext(0, "%s: %u/%u files (%0d.%d%% non-contiguous), %llu/%llu blocks\n", 5);
    log_out((int)a1, v115, v114, v5, v127, v9 / 10);
  }
  return v135 - __readfsqword(0x28u);
}


// Function: usage @ 0x19bb0
void usage(long long a1)
{
  long long v1; // r12
  char *v2; // rax
  char *v3; // rax
  char *v4; // rax

  v1 = *(long long *)(a1 + 8);
  v2 = dcgettext(
         0,
         "Usage: %s [-panyrcdfktvDFV] [-b superblock] [-B blocksize]\n"
         "\t\t[-l|-L bad_blocks_file] [-C fd] [-j external_journal]\n"
         "\t\t[-E extended-options] [-z undo_file] device\n",
         5);
  __fprintf_chk(stderr, 1, v2, v1);
  v3 = dcgettext(
         0,
         "\n"
         "Emergency help:\n"
         " -p                   Automatic repair (no questions)\n"
         " -n                   Make no changes to the filesystem\n"
         " -y                   Assume \"yes\" to all questions\n"
         " -c                   Check for bad blocks and add them to the badblock list\n"
         " -f                   Force checking even if filesystem is marked clean\n",
         5);
  __fprintf_chk(stderr, 1, "%s", v3);
  v4 = dcgettext(
         0,
         " -v                   Be verbose\n"
         " -b superblock        Use alternative superblock\n"
         " -B blocksize         Force blocksize when looking for superblock\n"
         " -j external_journal  Set location of the external journal\n"
         " -l bad_blocks_file   Add to badblocks list\n"
         " -L bad_blocks_file   Set badblocks list\n"
         " -z undo_file         Create an undo file\n",
         5);
  __fprintf_chk(stderr, 1, "%s", v4);
  exit(16);
}


// Function: syntax_err_report @ 0x19c50
void syntax_err_report(long long a1, int a2, unsigned int a3)
{
  long long v4; // rbp
  char *v5; // rax

  v4 = error_message(a2);
  v5 = dcgettext(0, "Syntax error in e2fsck config file (%s, line #%d)\n\t%s\n", 5);
  __fprintf_chk(stderr, 1, v5, a1, a3, v4);
  exit(8);
}


// Function: parse_extended_opts @ 0x19cb0
void parse_extended_opts(long long a1, long long a2)
{
  int v2; // ebp
  const char *v3; // r15
  int v4; // eax
  char *v5; // rax
  char *v6; // rbx
  char *v7; // rax
  const char *v8; // r13
  unsigned long long v9; // rax
  char *v10; // rax
  const char *v11; // rdx
  void *v12; // rcx
  char *v13; // rax
  char *v14; // rax
  FILE *v15; // rbp
  char *v16; // rax
  FILE *v17; // rbp
  char *v18; // rax
  FILE *v19; // rbp
  char *v20; // rax
  char *ptr; // [rsp+8h] [rbp-50h]
  char *endptr[9]; // [rsp+10h] [rbp-48h] BYREF

  v2 = 0;
  endptr[1] = (char *)__readfsqword(0x28u);
  ptr = (char *)string_copy(a1, a2, 0);
  v3 = ptr;
  if ( !ptr )
  {
    free(0);
    return;
  }
  while ( *v3 )
  {
    v5 = strchr(v3, 44);
    endptr[0] = v5;
    v6 = v5;
    if ( v5 )
    {
      *v5 = 0;
      v6 = endptr[0] + 1;
    }
    v7 = strchr(v3, 61);
    v8 = v7;
    if ( !v7 )
    {
      if ( strcmp(v3, "ea_ver") && strcmp(v3, "readahead_kb") )
      {
LABEL_20:
        if ( !strcmp(v3, "fragcheck") )
        {
          *(int *)(a1 + 76) |= 0x800u;
          goto LABEL_6;
        }
        if ( !strcmp(v3, "journal_only") )
        {
          if ( v8 )
            goto LABEL_23;
          *(int *)(a1 + 76) |= 0x1000u;
LABEL_6:
          if ( !v6 )
            break;
          goto LABEL_7;
        }
        if ( !strcmp(v3, "discard") )
        {
          *(int *)(a1 + 76) |= 0x2000u;
          goto LABEL_6;
        }
        if ( !strcmp(v3, "nodiscard") )
        {
          *(int *)(a1 + 76) &= ~0x2000u;
          goto LABEL_6;
        }
        if ( !strcmp(v3, "optimize_extents") )
        {
          *(int *)(a1 + 76) &= ~0x10000u;
          goto LABEL_6;
        }
        if ( !strcmp(v3, "no_optimize_extents") )
        {
          *(int *)(a1 + 76) |= 0x10000u;
          goto LABEL_6;
        }
        if ( !strcmp(v3, "inode_count_fullmap") )
        {
          *(int *)(a1 + 76) |= 0x20000u;
          goto LABEL_6;
        }
        if ( !strcmp(v3, "no_inode_count_fullmap") )
        {
          *(int *)(a1 + 76) &= ~0x20000u;
          goto LABEL_6;
        }
        if ( !strcmp(v3, "log_filename") )
        {
          if ( v8 )
          {
            *(long long *)(a1 + 48) = string_copy(a1, v8, 0);
            goto LABEL_6;
          }
        }
        else
        {
          if ( strcmp(v3, "problem_log") )
          {
            if ( !strcmp(v3, "bmap2extent") )
            {
              *(int *)(a1 + 76) |= 0x4000u;
            }
            else if ( !strcmp(v3, "fixes_only") )
            {
              *(int *)(a1 + 76) |= 0x8000u;
            }
            else if ( !strcmp(v3, "unshare_blocks") )
            {
              *(int *)(a1 + 76) |= 0x40100u;
            }
            else if ( !strcmp(v3, "check_encoding") )
            {
              *(int *)(a1 + 76) |= 0x100000u;
            }
            else
            {
              v14 = dcgettext(0, "Unknown extended option: %s\n", 5);
              v12 = (void *)v3;
              v11 = v14;
LABEL_25:
              ++v2;
              __fprintf_chk(stderr, 1, v11, v12);
            }
            goto LABEL_6;
          }
          if ( v8 )
          {
            *(long long *)(a1 + 64) = string_copy(a1, v8, 0);
            goto LABEL_6;
          }
        }
      }
LABEL_23:
      ++v2;
      goto LABEL_6;
    }
    *v7 = 0;
    v8 = v7 + 1;
    if ( !strcmp(v3, "ea_ver") )
    {
      v4 = strtoul(v8, endptr, 0);
      if ( *endptr[0] || (unsigned int)(v4 - 1) > 1 )
      {
        v10 = dcgettext(0, "Invalid EA version.\n", 5);
        v11 = "%s";
        v12 = v10;
        goto LABEL_25;
      }
      *(int *)(a1 + 856) = v4;
      goto LABEL_6;
    }
    if ( strcmp(v3, "readahead_kb") )
      goto LABEL_20;
    v9 = strtoull(v8, endptr, 0);
    if ( *endptr[0] )
    {
      v13 = dcgettext(0, "Invalid readahead buffer size.\n", 5);
      v11 = "%s";
      v12 = v13;
      goto LABEL_25;
    }
    *(long long *)(a1 + 920) = v9;
    if ( !v6 )
      break;
LABEL_7:
    v3 = v6;
  }
  free(ptr);
  if ( v2 )
  {
    v15 = stderr;
    v16 = dcgettext(
            0,
            "\n"
            "Extended options are separated by commas, and may take an argument which\n"
            "is set off by an equals ('=') sign.  Valid extended options are:\n"
            "\n",
            5);
    fputs(v16, v15);
    v17 = stderr;
    v18 = dcgettext(0, "\tea_ver=<ea_version (1 or 2)>\n", 5);
    fputs(v18, v17);
    fputs("\tfragcheck\n", stderr);
    fputs("\tjournal_only\n", stderr);
    fputs("\tdiscard\n", stderr);
    fputs("\tnodiscard\n", stderr);
    fputs("\toptimize_extents\n", stderr);
    fputs("\tno_optimize_extents\n", stderr);
    fputs("\tinode_count_fullmap\n", stderr);
    fputs("\tno_inode_count_fullmap\n", stderr);
    v19 = stderr;
    v20 = dcgettext(0, "\treadahead_kb=<buffer size>\n", 5);
    fputs(v20, v19);
    fputs("\tbmap2extent\n", stderr);
    fputs("\tunshare_blocks\n", stderr);
    fputs("\tfixes_only\n", stderr);
    fputs("\tcheck_encoding\n", stderr);
    fputc(10, stderr);
    exit(1);
  }
}


// Function: reserve_stdio_fds @ 0x1a2b0
int reserve_stdio_fds()
{
  int v0; // eax
  int *v2; // rax
  char *v3; // r12
  char *v4; // rax

  while ( 1 )
  {
    v0 = open("/dev/null", 2);
    if ( v0 < 0 )
      break;
    if ( v0 > 2 )
      return close(v0);
  }
  v2 = __errno_location();
  v3 = strerror(*v2);
  v4 = dcgettext(0, "ERROR: Couldn't open /dev/null (%s)\n", 5);
  return __fprintf_chk(stderr, 1, v4, v3);
}


// Function: PRS @ 0x1a330
long long PRS(int argc, char **argv, long long *a3)
{
  long long v5; // r14
  long long v7; // rax
  FILE *v8; // rdi
  int v9; // eax
  char *v10; // rax
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // r8d
  long long v16; // rax
  long long v17; // rdx
  char *v18; // rbx
  char *v19; // rax
  unsigned int v20; // eax
  int v21; // r8d
  int v22; // r9d
  int v23; // edx
  long long v24; // rax
  long long v25; // rdx
  char *v26; // rdi
  long long v27; // rax
  int v28; // edi
  int v29; // eax
  long long *v30; // r13
  unsigned int v31; // eax
  int v32; // r8d
  int v33; // r9d
  long long v34; // rbx
  char *v35; // rax
  char *v36; // rax
  long long v37; // r13
  char *v38; // rax
  long long v39; // r13
  long long v40; // r13
  long long v41; // r13
  int v42; // eax
  long long v43; // rcx
  __sigset_t *p_sa_mask; // rdi
  char *v45; // rax
  const char *v46; // r12
  int v47; // eax
  char *v48; // rax
  char *v49; // rbp
  int v50; // edi
  int *v51; // rax
  char *v52; // rax
  char *v53; // rax
  long long v54; // rcx
  __sigset_t *v55; // rdi
  int v56; // eax
  int v57; // ebp
  long long v58; // r12
  long long v59; // rax
  unsigned int v60; // eax
  int v61; // r8d
  int v62; // r9d
  unsigned int v63; // eax
  int v64; // r8d
  int v65; // r9d
  long long v66; // r13
  unsigned long long v67; // r12
  unsigned long long v68; // rax
  unsigned int v69; // eax
  int v70; // r8d
  int v71; // r9d
  char *v72; // r12
  unsigned int v73; // eax
  int v74; // r8d
  int v75; // r9d
  unsigned int v76; // eax
  int v77; // r8d
  int v78; // r9d
  long long v79; // r13
  unsigned int v80; // eax
  int v81; // r8d
  int v82; // r9d
  long long v83; // r13
  unsigned int v84; // r12d
  int *v85; // rax
  int v86; // r8d
  int v87; // r9d
  char *v88; // rax
  long long v89; // [rsp+8h] [rbp-120h]
  int v90; // [rsp+8h] [rbp-120h]
  long long v91; // [rsp+8h] [rbp-120h]
  unsigned int v92; // [rsp+8h] [rbp-120h]
  char *v93; // [rsp+10h] [rbp-118h]
  int v94; // [rsp+1Ch] [rbp-10Ch]
  unsigned long long memory_size; // [rsp+20h] [rbp-108h]
  long long v96; // [rsp+28h] [rbp-100h]
  int v97; // [rsp+3Ch] [rbp-ECh] BYREF
  long long v98; // [rsp+40h] [rbp-E8h] BYREF
  long long v99; // [rsp+48h] [rbp-E0h] BYREF
  struct sigaction act; // [rsp+50h] [rbp-D8h] BYREF
  unsigned long long v101; // [rsp+E8h] [rbp-40h]

  v101 = __readfsqword(0x28u);
  v5 = e2fsck_allocate_context(&v98);
  if ( !v5 )
  {
    v7 = v98;
    v8 = stdout;
    *a3 = v98;
    e2fsck_global_ctx = v7;
    setvbuf(v8, 0, 2, 0x2000u);
    setvbuf(stderr, 0, 2, 0x2000u);
    if ( getenv("E2FSCK_FORCE_INTERACTIVE") || isatty(0) && isatty(1) )
    {
      *(int *)(v98 + 728) = 1;
    }
    else
    {
      v59 = v98;
      *(char *)(v98 + 732) = 1;
      *(char *)(v59 + 734) = 2;
    }
    memset(&unk_B70A0, 61, 0x7Fu);
    memset(&unk_B7020, 32, 0x7Fu);
    add_error_table(&et_ext2_error_table);
    add_error_table(&et_prof_error_table);
    blkid_get_cache(v98 + 136, 0);
    if ( argc && *argv )
      *(long long *)(v98 + 8) = *argv;
    else
      *(long long *)(v98 + 8) = "e2fsck";
    v94 = 0;
    memory_size = get_memory_size();
    v93 = 0;
    *(long long *)(v98 + 920) = -1;
    while ( 1 )
    {
      v9 = getopt(argc, argv, "panyrcC:B:dE:fvtFVM:b:I:j:P:l:L:N:SsDkz:");
      v97 = v9;
      if ( v9 == -1 )
        break;
      switch ( v9 )
      {
        case 'B':
          v29 = atoi(optarg);
          *(int *)(v98 + 80) = v29;
          continue;
        case 'C':
          v25 = v98;
          v26 = optarg;
          *(long long *)(v98 + 352) = sub_1B500;
          if ( (unsigned int)__isoc99_sscanf(v26, "%d", v25 + 712) != 1 )
            goto LABEL_34;
          v27 = v98;
          v28 = *(int *)(v98 + 712);
          if ( v28 < 0 )
          {
            *(long long *)(v98 + 352) = 0;
            v28 = -v28;
            *(int *)(v27 + 712) = v28;
          }
          else if ( !v28 )
          {
            continue;
          }
          v50 = dup(v28);
          if ( v50 < 0 )
          {
            v51 = __errno_location();
            v96 = error_message(*v51);
            v92 = *(int *)(v98 + 712);
            v52 = dcgettext(0, "Error validating file descriptor %d: %s\n", 5);
            __fprintf_chk(stderr, 1, v52, v92, v96);
            v53 = dcgettext(0, "Invalid completion information file descriptor", 5);
            fatal_error(v98, v53);
          }
          close(v50);
          break;
        case 'D':
          *(int *)(v98 + 76) |= 0x400u;
          continue;
        case 'E':
          v93 = optarg;
          continue;
        case 'F':
          v94 = 1;
          continue;
        case 'I':
          v17 = v98 + 604;
          goto LABEL_33;
        case 'L':
          ++dword_B712C;
          goto LABEL_16;
        case 'N':
          v91 = v98;
          *(long long *)(v91 + 24) = string_copy(v98, optarg, 0);
          continue;
        case 'P':
          v17 = v98 + 600;
LABEL_33:
          if ( (unsigned int)__isoc99_sscanf(optarg, "%d", v17) != 1 )
            goto LABEL_34;
          continue;
        case 'V':
          dword_B7134 = 1;
          continue;
        case 'a':
        case 'p':
          if ( (*(char *)(v98 + 76) & 0xC) != 0 )
            goto LABEL_13;
          *(int *)(v98 + 76) |= 2u;
          continue;
        case 'b':
          v15 = __isoc99_sscanf(optarg, "%llu", &v99);
          v16 = v98;
          *(long long *)(v98 + 88) = v99;
          if ( v15 != 1 )
          {
LABEL_34:
            v18 = optarg;
            v19 = dcgettext(0, "\nInvalid non-numeric argument to -%c (\"%s\")\n\n", 5);
            __fprintf_chk(stderr, 1, v19, (unsigned int)v97, v18);
            exit(1);
          }
          *(int *)(v16 + 72) |= 0x100u;
          continue;
        case 'c':
          v23 = dword_B7138++;
          v24 = v98;
          if ( v23 )
            *(int *)(v98 + 76) |= 0x200u;
          *(int *)(v24 + 76) |= 0x40u;
          continue;
        case 'd':
          *(int *)(v98 + 76) |= 0x80u;
          continue;
        case 'f':
          *(int *)(v98 + 76) |= 0x100u;
          continue;
        case 'j':
          v89 = v98;
          *(long long *)(v89 + 624) = blkid_get_devname(*(long long *)(v98 + 136), optarg, 0);
          if ( !*(long long *)(v98 + 624) )
          {
            v90 = (int)optarg;
            v20 = (unsigned int)dcgettext(0, "Unable to resolve '%s'", 5);
            com_err(*(long long *)(v98 + 8), 0, v20, v90, v21, v22);
            fatal_error(v98, 0);
          }
          continue;
        case 'k':
          ++dword_B7128;
          continue;
        case 'l':
LABEL_16:
          if ( ptr )
            free(ptr);
          ptr = (void *)string_copy(v98, optarg, 0);
          continue;
        case 'n':
          v13 = *(int *)(v98 + 76);
          if ( (v13 & 6) != 0 )
            goto LABEL_13;
          *(int *)(v98 + 76) = v13 | 8;
          continue;
        case 'r':
          continue;
        case 't':
          v11 = *(int *)(v98 + 76);
          v12 = v11 | 0x20;
          if ( (v11 & 0x10) == 0 )
            v12 = v11 | 0x10;
          *(int *)(v98 + 76) = v12;
          continue;
        case 'v':
          dword_B7130 = 1;
          continue;
        case 'y':
          v14 = *(int *)(v98 + 76);
          if ( (v14 & 0xA) != 0 )
          {
LABEL_13:
            v10 = dcgettext(0, "Only one of the options -p/-a, -n or -y may be specified.", 5);
            fatal_error(v98, v10);
          }
          *(int *)(v98 + 76) = v14 | 4;
          continue;
        case 'z':
          *(long long *)(v98 + 936) = optarg;
          continue;
        default:
          sub_19BB0(v98);
      }
    }
    if ( !dword_B7134 )
    {
      v30 = (long long *)v98;
      if ( argc - 1 != optind )
        sub_19BB0(v98);
      if ( (*(int *)(v98 + 76) & 0x408) == 0x408 )
      {
        v63 = (unsigned int)dcgettext(0, "The -n and -D options are incompatible.", 5);
        com_err(*(long long *)(v98 + 8), 0, (unsigned int)"%s", v63, v64, v65);
        fatal_error(v98, 0);
      }
      if ( (*(char *)(v98 + 76) & 8) != 0 )
      {
        if ( dword_B7138 )
        {
          v76 = (unsigned int)dcgettext(0, "The -n and -c options are incompatible.", 5);
          com_err(*(long long *)(v98 + 8), 0, (unsigned int)"%s", v76, v77, v78);
          fatal_error(v98, 0);
        }
        if ( ptr )
        {
          v31 = (unsigned int)dcgettext(0, "The -n and -l/-L options are incompatible.", 5);
          com_err(*(long long *)(v98 + 8), 0, (unsigned int)"%s", v31, v32, v33);
          fatal_error(v98, 0);
        }
        *(int *)(v98 + 76) |= 1u;
      }
      v34 = optind;
      v35 = strchr(argv[optind], 63);
      if ( v35 )
      {
        v30[4] = v35 + 1;
        *v35 = 0;
        v30 = (long long *)v98;
        v34 = optind;
      }
      else
      {
        v30[4] = 0;
      }
      v30[2] = blkid_get_devname(v30[17], argv[v34], 0);
      if ( !*(long long *)(v98 + 16) )
      {
        v72 = argv[optind];
        v73 = (unsigned int)dcgettext(0, "Unable to resolve '%s'", 5);
        com_err(*(long long *)(v98 + 8), 0, v73, (int)v72, v74, v75);
        fatal_error(v98, 0);
      }
      if ( v93 )
        sub_19CB0(v98, (long long)v93);
      v36 = getenv("E2FSCK_FIXES_ONLY");
      v37 = v98;
      if ( v36 )
        *(int *)(v98 + 76) |= 0x8000u;
      if ( (*(int *)(v37 + 76) & 0x8400) == 0x8400 )
      {
        v60 = (unsigned int)dcgettext(0, "The -D and -E fixes_only options are incompatible.", 5);
        com_err(*(long long *)(v98 + 8), 0, (unsigned int)"%s", v60, v61, v62);
        fatal_error(v98, 0);
      }
      if ( (*(int *)(v37 + 76) & 0xC000) == 0xC000 )
      {
        v69 = (unsigned int)dcgettext(0, "The -E bmap2extent and fixes_only options are incompatible.", 5);
        com_err(*(long long *)(v98 + 8), 0, (unsigned int)"%s", v69, v70, v71);
        fatal_error(v98, 0);
      }
      v38 = getenv("E2FSCK_CONFIG");
      if ( v38 )
        off_B20B0 = v38;
      profile_set_syntax_err_cb(sub_19C50);
      profile_init(&off_B20B0);
      profile_get_boolean(*(long long *)(v98 + 864), "options", "report_time", 0, 0, &v97);
      v39 = v98;
      if ( v97 )
        *(int *)(v98 + 76) |= 0x30u;
      profile_get_boolean(*(long long *)(v39 + 864), "options", "report_verbose", 0, 0, &v97);
      if ( v97 )
        dword_B7130 = 1;
      profile_get_boolean(*(long long *)(v98 + 864), "options", "no_optimize_extents", 0, 0, &v97);
      v40 = v98;
      if ( v97 )
        *(int *)(v98 + 76) |= 0x10000u;
      profile_get_boolean(*(long long *)(v40 + 864), "options", "inode_count_fullmap", 0, 0, &v97);
      v41 = v98;
      if ( v97 )
        *(int *)(v98 + 76) |= 0x20000u;
      if ( *(long long *)(v41 + 920) == -1 )
      {
        profile_get_integer(*(long long *)(v41 + 864), "options", "readahead_mem_pct", 0, 0xFFFFFFFFLL, &v97);
        v66 = v98;
        v67 = memory_size >> 10;
        if ( (unsigned int)v97 <= 0x64 )
          *(long long *)(v98 + 920) = v67 * v97 / 0x64;
        profile_get_integer(*(long long *)(v66 + 864), "options", "readahead_kb", 0, 0xFFFFFFFFLL, &v97);
        v41 = v98;
        if ( v97 >= 0 )
          *(long long *)(v98 + 920) = v97;
        v68 = *(long long *)(v41 + 920);
        if ( v68 > v67 && v68 != -1 )
          *(long long *)(v41 + 920) = v67;
      }
      v42 = *(int *)(v41 + 76);
      if ( (v42 & 0x2008) == 0x2008 )
      {
        BYTE1(v42) &= ~0x20u;
        *(int *)(v41 + 76) = v42;
      }
      if ( v94 )
      {
        v56 = open(*(const char **)(v41 + 16), 0, 0);
        v57 = v56;
        if ( v56 < 0 )
        {
          v83 = *(long long *)(v98 + 16);
          v84 = (unsigned int)dcgettext(0, "while opening %s for flushing", 5);
          v85 = __errno_location();
          com_err((unsigned int)"open", *v85, v84, v83, v86, v87);
          fatal_error(v98, 0);
        }
        v58 = ext2fs_sync_device(v56);
        if ( v58 )
        {
          v79 = *(long long *)(v98 + 16);
          v80 = (unsigned int)dcgettext(0, "while trying to flush %s", 5);
          com_err((unsigned int)"ext2fs_sync_device", v58, v80, v79, v81, v82);
          fatal_error(v98, 0);
        }
        close(v57);
      }
      if ( dword_B7138 )
      {
        if ( ptr )
        {
          v88 = dcgettext(0, "The -c and the -l/-L options may not be both used at the same time.\n", 5);
          __fprintf_chk(stderr, 1, "%s", v88);
          exit(16);
        }
        v43 = 36;
        p_sa_mask = &act.sa_mask;
        while ( v43 )
        {
          LODWORD(p_sa_mask->__val[0]) = 0;
          p_sa_mask = (__sigset_t *)((char *)p_sa_mask + 4);
          --v43;
        }
        act.sa_handler = (__sighandler_t)sub_18270;
        sigaction(2, &act, 0);
        sigaction(15, &act, 0);
        act.sa_flags = 0x10000000;
        act.sa_handler = (__sighandler_t)sub_18250;
        sigaction(10, &act, 0);
        act.sa_handler = (__sighandler_t)sub_1B260;
        sigaction(12, &act, 0);
        v45 = getenv("PATH");
        v46 = v45;
        if ( v45 )
        {
          v47 = strlen(v45);
          v48 = (char *)malloc(v47 + 12);
          v49 = v48;
          if ( !v48 )
            fatal_error(v98, "Couldn't malloc() newpath");
          strcpy(v48, "PATH=/sbin");
          strcat(v48, ":");
          strcat(v49, v46);
        }
        else
        {
          v49 = (char *)malloc(0xCu);
          if ( !v49 )
            fatal_error(v98, "Couldn't malloc() newpath");
          strcpy(v49, "PATH=/sbin");
        }
        putenv(v49);
      }
      else
      {
        v54 = 36;
        v55 = &act.sa_mask;
        while ( v54 )
        {
          LODWORD(v55->__val[0]) = 0;
          v55 = (__sigset_t *)((char *)v55 + 4);
          --v54;
        }
        act.sa_handler = (__sighandler_t)sub_18270;
        sigaction(2, &act, 0);
        sigaction(15, &act, 0);
        act.sa_flags = 0x10000000;
        act.sa_handler = (__sighandler_t)sub_18250;
        sigaction(10, &act, 0);
        act.sa_handler = (__sighandler_t)sub_1B260;
        sigaction(12, &act, 0);
      }
    }
  }
  return v5;
}


// Function: e2fsck_clear_progbar @ 0x1b210
int e2fsck_clear_progbar(long long a1)
{
  int result; // eax

  if ( (*(char *)(a1 + 72) & 0x20) != 0 )
  {
    __printf_chk(1, "%s%s\r%s", (const char *)(a1 + 732), byte_B7050, (const char *)(a1 + 734));
    result = fflush(stdout);
    *(int *)(a1 + 72) &= ~0x20u;
  }
  return result;
}


// Function: signal_progress_off @ 0x1b260
int signal_progress_off()
{
  long long v0; // rbx
  int result; // eax

  v0 = e2fsck_global_ctx;
  if ( e2fsck_global_ctx )
  {
    result = e2fsck_clear_progbar(e2fsck_global_ctx);
    *(long long *)(v0 + 352) = 0;
  }
  return result;
}


// Function: e2fsck_simple_progress @ 0x1b290
long long e2fsck_simple_progress(long long a1, const char *a2, int a3, float a4)
{
  int v4; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  bool v9; // sf
  int v10; // edx
  int v11; // eax
  signed int v12; // eax
  struct timeval tv; // [rsp+10h] [rbp-48h] BYREF
  unsigned long long v15; // [rsp+28h] [rbp-30h]

  v15 = __readfsqword(0x28u);
  if ( (*(char *)(a1 + 72) & 0x40) == 0 )
  {
    v4 = (int)((float)(a4 * 10.0) + 0.5);
    if ( *(int *)(a1 + 720) != v4 )
    {
      *(int *)(a1 + 720) = v4;
      gettimeofday(&tv, 0);
      v6 = tv.tv_usec / 125000 + 8 * LODWORD(tv.tv_sec);
      if ( *(int *)(a1 + 724) != v6 || !v4 || v4 == 1000 )
      {
        *(int *)(a1 + 724) = v6;
        v7 = *(int *)(a1 + 716);
        *(int *)(a1 + 72) |= 0x20u;
        *(int *)(a1 + 716) = ((char)v7 + 1) & 3;
        v8 = strlen(a2);
        v9 = 66 - v8 < 0;
        v10 = 66 - v8;
        v11 = 66 - v8 + 7;
        if ( !v9 )
          v11 = v10;
        v12 = v11 & 0xFFFFFFF8;
        if ( a3 )
          v12 -= 8;
        __printf_chk(
          1,
          "%s%s: |%s%s",
          (const char *)(a1 + 732),
          a2,
          &byte_B70A0[128LL - ((int)(float)((float)((float)((float)v12 * a4) + 50.0) / 100.0) + 1)],
          &byte_B7020[128LL - (v12 - (int)(float)((float)((float)((float)v12 * a4) + 50.0) / 100.0) + 1)]);
        if ( v4 == 1000 )
          fputc(124, stdout);
        else
          fputc(asc_78CC8[*(int *)(a1 + 716) & 3], stdout);
        __printf_chk(1, " %4.1f%%  ", a4);
        if ( a3 )
          __printf_chk(1, "%u\r", a3);
        else
          fputs(" \r", stdout);
        fputs((const char *)(a1 + 734), stdout);
        if ( v4 == 1000 )
          e2fsck_clear_progbar(a1);
        fflush(stdout);
      }
    }
  }
  return 0;
}


// Function: e2fsck_update_progress @ 0x1b500
long long e2fsck_update_progress(long long a1, unsigned int a2, long long a3, long long a4)
{
  size_t v4; // rax
  float v6; // xmm0_4
  char v7[1032]; // [rsp+0h] [rbp-428h] BYREF
  unsigned long long v8; // [rsp+408h] [rbp-20h]

  v8 = __readfsqword(0x28u);
  if ( a2 )
  {
    if ( *(int *)(a1 + 712) )
    {
      __snprintf_chk(v7, 1024, 1, 1024, "%d %lu %lu %s\n", a2, a3, a4, *(const char **)(a1 + 24));
      v4 = strlen(v7);
      write_all(*(int *)(a1 + 712), v7, v4);
    }
    else
    {
      v6 = sub_1B190(a2, a3, (unsigned int)a4);
      e2fsck_simple_progress(a1, *(const char **)(a1 + 24), 0, v6);
    }
  }
  return 0;
}


// Function: e2fsck_allocate_context @ 0x1b5c0
long long e2fsck_allocate_context(long long *a1)
{
  long long mem; // r12
  long long v4; // rcx
  long long v5; // rdi
  int *v6; // rax
  char *v7; // rdi
  unsigned long long v8; // r8
  long long v9; // rax
  long long v10; // rbp
  long long v11[5]; // [rsp+0h] [rbp-28h] BYREF

  v11[1] = __readfsqword(0x28u);
  mem = ext2fs_get_mem(1016, v11);
  if ( !mem )
  {
    v4 = v11[0];
    v5 = v11[0] + 8LL;
    *(long long *)v11[0] = 0;
    *(long long *)(v4 + 1008) = 0;
    memset(
      (void *)(v5 & 0xFFFFFFFFFFFFFFF8LL),
      0,
      8 * ((unsigned long long)((unsigned int)v4 - (v5 & 0xFFFFFFF8) + 1016) >> 3));
    v6 = (int *)v11[0];
    *(int *)(v11[0] + 600LL) = 256;
    v6[214] = 2;
    v6[218] = 1;
    v6[152] = 255;
    v7 = getenv("E2FSCK_TIME");
    if ( v7 )
    {
      v8 = strtoull(v7, 0, 0);
      v9 = v11[0];
      *(long long *)(v11[0] + 840LL) = v8;
    }
    else
    {
      v10 = v11[0];
      *(long long *)(v10 + 840) = time(0);
      v9 = v11[0];
      if ( *(long long *)(v11[0] + 840LL) <= 1262321999 )
        *(int *)(v11[0] + 72LL) |= 0x2000u;
    }
    *a1 = v9;
  }
  return mem;
}


// Function: e2fsck_reset_context @ 0x1b6e0
long long e2fsck_reset_context(long long *a1)
{
  long long v2; // rdi
  long long v3; // rax
  long long v4; // rax

  *((int *)a1 + 18) &= 0x6000u;
  a1[69] = 0;
  if ( a1[45] )
  {
    ext2fs_free_inode_bitmap();
    a1[45] = 0;
  }
  if ( a1[47] )
  {
    ext2fs_free_inode_bitmap();
    a1[47] = 0;
  }
  if ( a1[50] )
  {
    ext2fs_free_inode_bitmap();
    a1[50] = 0;
  }
  if ( a1[52] )
  {
    ext2fs_free_block_bitmap();
    a1[52] = 0;
  }
  if ( a1[51] )
  {
    ext2fs_free_block_bitmap();
    a1[51] = 0;
  }
  if ( a1[56] )
  {
    ext2fs_free_icount();
    a1[56] = 0;
  }
  v2 = a1[77];
  v3 = *a1;
  if ( v2 )
  {
    if ( !v3 )
    {
      a1[77] = 0;
      goto LABEL_21;
    }
    if ( v2 != *(long long *)(v3 + 8) )
    {
      (*(void (**)(void))(*(long long *)(v2 + 8) + 24LL))();
      v3 = *a1;
    }
    a1[77] = 0;
  }
  if ( v3 && *(long long *)(v3 + 144) )
  {
    ext2fs_free_dblist();
    *(long long *)(*a1 + 144) = 0;
  }
LABEL_21:
  e2fsck_free_dir_info(a1);
  e2fsck_free_dx_dir_info(a1);
  if ( a1[57] )
  {
    ea_refcount_free();
    a1[57] = 0;
  }
  if ( a1[58] )
  {
    ea_refcount_free();
    a1[58] = 0;
  }
  if ( a1[59] )
  {
    ea_refcount_free();
    a1[59] = 0;
  }
  if ( a1[60] )
  {
    ea_refcount_free();
    a1[60] = 0;
  }
  if ( a1[61] )
  {
    ea_refcount_free();
    a1[61] = 0;
  }
  if ( a1[53] )
  {
    ext2fs_free_block_bitmap();
    a1[53] = 0;
  }
  if ( a1[54] )
  {
    ext2fs_free_block_bitmap();
    a1[54] = 0;
  }
  if ( a1[114] )
  {
    ext2fs_free_block_bitmap();
    a1[114] = 0;
  }
  if ( a1[48] )
  {
    ext2fs_free_inode_bitmap();
    a1[48] = 0;
  }
  if ( a1[46] )
  {
    ext2fs_free_inode_bitmap();
    a1[46] = 0;
  }
  if ( a1[49] )
  {
    ext2fs_free_inode_bitmap();
    a1[49] = 0;
  }
  if ( a1[73] )
  {
    ext2fs_u32_list_free();
    a1[73] = 0;
  }
  destroy_encrypted_file_info(a1);
  if ( a1[62] )
  {
    ext2fs_free_mem(a1 + 62);
    a1[62] = 0;
  }
  if ( a1[63] )
  {
    ext2fs_free_mem(a1 + 63);
    a1[63] = 0;
  }
  if ( a1[64] )
  {
    ext2fs_free_mem(a1 + 64);
    a1[64] = 0;
  }
  if ( a1[110] )
  {
    ext2fs_u32_list_free();
    a1[110] = 0;
  }
  if ( a1[55] )
  {
    ext2fs_free_icount();
    a1[55] = 0;
  }
  a1[92] = 0;
  v4 = a1[11];
  a1[93] = 0;
  a1[12] = v4;
  a1[94] = 0;
  a1[95] = 0;
  a1[96] = 0;
  a1[97] = 0;
  a1[98] = 0;
  a1[99] = 0;
  a1[100] = 0;
  a1[102] = 0;
  a1[103] = 0;
  *((int *)a1 + 208) = 0;
  return 0;
}


// Function: e2fsck_free_context @ 0x1baa0
long long e2fsck_free_context(long long *a1)
{
  long long *v1; // rdi
  FILE *v2; // rsi
  long long result; // rax
  long long *v4; // [rsp+8h] [rbp-10h] BYREF

  v4 = a1;
  if ( a1 )
  {
    e2fsck_reset_context(a1);
    v1 = v4;
    if ( v4[17] )
    {
      blkid_put_cache(v4[17]);
      v1 = v4;
    }
    if ( v1[108] )
    {
      profile_release((void *)v1[108]);
      v1 = v4;
    }
    if ( v1[2] )
    {
      ext2fs_free_mem(v1 + 2);
      v1 = v4;
    }
    if ( v1[3] )
    {
      ext2fs_free_mem(v1 + 3);
      v1 = v4;
    }
    if ( v1[6] )
    {
      free((void *)v1[6]);
      v1 = v4;
    }
    if ( v1[5] )
    {
      fclose((FILE *)v1[5]);
      v1 = v4;
    }
    if ( v1[8] )
    {
      free((void *)v1[8]);
      v1 = v4;
    }
    v2 = (FILE *)v1[7];
    if ( v2 )
    {
      fputs("</problem_log>\n", v2);
      fclose((FILE *)v4[7]);
    }
    return ext2fs_free_mem(&v4);
  }
  return result;
}


// Function: e2fsck_run @ 0x1bb90
long long e2fsck_run(long long a1)
{
  int v1; // r8d
  int v2; // eax
  int v3; // eax
  void (*v4)(long long); // rbx
  long long (**v5)(); // rbp
  void (*v6)(long long, long long, long long, long long); // rax
  unsigned int v7; // r8d
  unsigned int v8; // edx

  v1 = _setjmp((struct __jmp_buf_tag *)(a1 + 144));
  v2 = *(int *)(a1 + 72);
  if ( v1 )
  {
    v8 = v2 & 0xFFFFFFEF;
    v7 = *(int *)(a1 + 72) & 7;
  }
  else
  {
    v3 = v2 | 0x10;
    v4 = (void (*)(long long))e2fsck_pass1;
    v5 = off_B1808;
    *(int *)(a1 + 72) = v3;
    while ( 1 )
    {
      v7 = v3 & 7;
      if ( (v3 & 7) != 0 )
        break;
      if ( e2fsck_mmp_update(*(long long *)a1) )
        fatal_error(a1, 0);
      v4(a1);
      v6 = *(void (**)(long long, long long, long long, long long))(a1 + 352);
      if ( v6 )
        v6(a1, 0, 0, 0);
      v4 = (void (*)(long long))*v5++;
      v3 = *(int *)(a1 + 72);
      if ( !v4 )
      {
        v7 = *(int *)(a1 + 72) & 7;
        break;
      }
    }
    v8 = v3 & 0xFFFFFFEF;
  }
  *(int *)(a1 + 72) = v8;
  return v7;
}


// Function: check_super_value @ 0x1bd20
long long check_super_value(
        long long a1,
        long long a2,
        unsigned long long a3,
        char a4,
        unsigned long long a5,
        unsigned long long a6)
{
  unsigned long long v6; // rbx
  long long result; // rax
  long long v8[19]; // [rsp+0h] [rbp-98h] BYREF

  v6 = a3;
  v8[13] = __readfsqword(0x28u);
  if ( a3 < a5 && (a4 & 1) != 0
    || (a4 & 2) != 0 && a3 > a6
    || (result = 1, (a4 & 4) != 0) && (--a3, (v6 & (v6 - 1)) != 0) )
  {
    clear_problem_context(v8, a2, a3);
    v8[10] = v6;
    v8[12] = a2;
    fix_problem(a1, 11, v8);
    *(int *)(a1 + 72) |= 1u;
    return 0;
  }
  return result;
}


// Function: release_inode_blocks @ 0x1bdc0
long long release_inode_blocks(long long *a1, unsigned int a2, long long a3, long long a4, long long a5)
{
  long long v9; // r15
  long long v10; // rbp
  long long v11; // rax
  bool v12; // zf
  unsigned long long v13; // rcx
  unsigned int v14; // edx
  long long v15; // r14
  unsigned int v16; // r14d
  long long v17; // rax
  long long v19; // rdx
  long long v20; // rax
  unsigned long long v21; // r8
  long long v22; // rax
  long long v23; // r11
  int v24; // r12d
  long long v25; // rdi
  unsigned int v26; // eax
  int v27; // esi
  int v28; // r8d
  int v29; // r9d
  unsigned int v30; // eax
  int v31; // r8d
  int v32; // r9d
  long long v34; // [rsp+8h] [rbp-A0h]
  int v35; // [rsp+1Ch] [rbp-8Ch] BYREF
  long long v36[3]; // [rsp+20h] [rbp-88h] BYREF
  int v37; // [rsp+38h] [rbp-70h]
  unsigned int v38; // [rsp+3Ch] [rbp-6Ch]
  unsigned long long v39; // [rsp+40h] [rbp-68h]
  int v40; // [rsp+48h] [rbp-60h]
  unsigned int v41; // [rsp+4Ch] [rbp-5Ch]
  long long v42; // [rsp+50h] [rbp-58h]
  long long v43; // [rsp+58h] [rbp-50h]
  long long v44; // [rsp+60h] [rbp-48h]
  unsigned long long v45; // [rsp+68h] [rbp-40h]

  v9 = *a1;
  v45 = __readfsqword(0x28u);
  v10 = sub_1BC80(a3);
  if ( !(unsigned int)ext2fs_inode_has_valid_blocks2(v9, v10) )
    return 0;
  v11 = *a1;
  v36[0] = a1;
  v36[2] = a5;
  LODWORD(v11) = *(int *)(v11 + 40);
  v41 = 0;
  v42 = 0;
  v44 = a3;
  v43 = 0;
  v12 = *(short *)(a3 + 26) == 0;
  v36[1] = a4 + (unsigned int)(3 * v11);
  if ( v12 )
  {
    v37 = 0;
    v13 = 0;
    v14 = 0;
  }
  else
  {
    v19 = *(unsigned int *)(a3 + 108);
    v20 = *(unsigned int *)(a3 + 4);
    v37 = 1;
    v21 = *(unsigned int *)(v9 + 40);
    v13 = (v21 + (v20 | (v19 << 32)) - 1) / v21;
    v14 = (unsigned int)v20 % (unsigned int)v21;
  }
  v39 = v13;
  v38 = v14;
  v40 = 0;
  v15 = ext2fs_block_iterate3(v9, a2, 2, a4, sub_1C0A0, v36);
  if ( v15 )
  {
    v26 = (unsigned int)dcgettext(0, "while calling ext2fs_block_iterate for inode %u", 5);
    v27 = v15;
    v16 = 1;
    com_err((unsigned int)"release_inode_blocks", v27, v26, a2, v28, v29);
    return v16;
  }
  v16 = v41;
  if ( v41 )
    return 1;
  e2fsck_read_inode_full(a1, a2, v10, 160, "release_inode_blocks");
  if ( v40 )
    ext2fs_iblk_sub_blocks(v9, v10);
  v17 = ext2fs_file_acl_block(v9, v10);
  if ( v17 )
  {
    v34 = v17;
    v22 = ext2fs_adjust_ea_refcount3(v9, v17, a4, 0xFFFFFFFFLL, &v35, a2);
    v23 = v34;
    v24 = v22;
    if ( v22 == 2133571418 )
    {
      v35 = 1;
    }
    else
    {
      if ( v22 )
      {
        v16 = 1;
        v30 = (unsigned int)dcgettext(0, "while calling ext2fs_adjust_ea_refcount2 for inode %u", 5);
        com_err((unsigned int)"release_inode_blocks", v24, v30, a2, v31, v32);
        return v16;
      }
      if ( !v35 )
      {
        v25 = a1[79];
        if ( v25 )
        {
          quota_data_sub(v25, a3, 0, *(unsigned int *)(*a1 + 40LL));
          v23 = v34;
        }
        ext2fs_block_alloc_stats2(v9, v23, 0xFFFFFFFFLL);
        ++a1[14];
      }
    }
    ext2fs_file_acl_block_set(v9, v10, 0);
  }
  else
  {
    return 0;
  }
  return v16;
}


// Function: release_inode_block @ 0x1c0a0
long long release_inode_block(long long a1, unsigned long long *a2, long long a3, long long a4, long long a5, long long a6)
{
  unsigned long long v6; // rbp
  long long v7; // r12
  int v8; // ecx
  long long *v9; // r8
  long long v12; // rdi
  unsigned long long v14; // rax
  int v15; // eax
  long long *v16; // r8
  unsigned int v17; // r12d
  long long v18; // rax
  long long v19; // rdi
  long long blk64; // rax
  int *v21; // rax
  int v22; // edx
  int *v23; // rdx
  long long v25; // rax
  long long v26; // rax
  long long *v27; // [rsp+8h] [rbp-40h]
  long long *v28; // [rsp+8h] [rbp-40h]
  long long *v29; // [rsp+8h] [rbp-40h]
  long long *v30; // [rsp+8h] [rbp-40h]

  v6 = *a2;
  v7 = *(long long *)(a6 + 16);
  v8 = *(int *)(a1 + 192);
  v9 = *(long long **)a6;
  *(long long *)(v7 + 40) = *a2;
  *(long long *)(v7 + 56) = a3;
  if ( !v6 || *(long long *)(a6 + 56) == v6 >> v8 )
    return 0;
  v12 = *(long long *)(a1 + 32);
  *(long long *)(a6 + 56) = v6 >> v8;
  if ( *(unsigned int *)(v12 + 20) > v6 || (v27 = v9, v14 = ext2fs_blocks_count(v12), v9 = v27, v14 <= v6) )
  {
    fix_problem(v9, 33, v7);
    goto LABEL_22;
  }
  v15 = ext2fs_test_block_bitmap2(*(long long *)(a1 + 88), v6);
  v16 = v27;
  if ( !v15 )
  {
    fix_problem(v27, 34, v7);
    goto LABEL_22;
  }
  v17 = *(int *)(a6 + 24);
  if ( v17 )
  {
    if ( a3 >= 0 )
    {
      v18 = *(long long *)(a6 + 32);
      if ( v18 <= a3 )
        goto LABEL_9;
      return 0;
    }
    blk64 = io_channel_read_blk64(*(long long *)(a1 + 8), v6, 1, *(long long *)(a6 + 8));
    *(long long *)(a6 + 48) = blk64;
    if ( !blk64 )
    {
      v21 = *(int **)(a6 + 8);
      v16 = v27;
      v22 = *(int *)(a1 + 40) >> 2;
      if ( !v22 )
      {
LABEL_28:
        v18 = *(long long *)(a6 + 32);
LABEL_9:
        if ( a3 == v18 )
        {
          if ( *(int *)(a6 + 28) )
          {
            v30 = v16;
            v25 = io_channel_read_blk64(*(long long *)(a1 + 8), v6, 1, *(long long *)(a6 + 8));
            *(long long *)(a6 + 48) = v25;
            if ( v25 )
              goto LABEL_22;
            memset(
              (void *)(*(long long *)(a6 + 8) + *(int *)(a6 + 28)),
              0,
              (unsigned int)(*(int *)(a1 + 40) - *(int *)(a6 + 28)));
            v26 = io_channel_write_blk64(*(long long *)(a1 + 8), v6, 1, *(long long *)(a6 + 8));
            v16 = v30;
            *(long long *)(a6 + 48) = v26;
            if ( v26 )
              goto LABEL_22;
          }
        }
        ++*(int *)(a6 + 40);
        v17 = 1;
        *a2 = 0;
        goto LABEL_11;
      }
      v23 = &v21[v22];
      while ( !*v21 )
      {
        if ( ++v21 == v23 )
          goto LABEL_28;
      }
      return 0;
    }
LABEL_22:
    *(int *)(a6 + 44) = 1;
    return 2;
  }
LABEL_11:
  v19 = v16[79];
  if ( v19 )
  {
    v28 = v16;
    quota_data_sub(v19, *(long long *)(a6 + 64), 0, *(unsigned int *)(*v16 + 40LL));
    v16 = v28;
  }
  v29 = v16;
  ext2fs_block_alloc_stats2(a1, v6, 0xFFFFFFFFLL);
  ++v29[14];
  return v17;
}


// Function: e2fsck_write_all_quotas @ 0x1c380
long long e2fsck_write_all_quotas(long long *a1, long long a2)
{
  long long v3; // rdx
  int v4; // r8d
  long long result; // rax
  long long v6; // rbp
  long long v7; // rdi
  long long v8[19]; // [rsp+0h] [rbp-98h] BYREF

  v8[13] = __readfsqword(0x28u);
  v4 = sub_1C370(*(unsigned int *)(*(long long *)(*a1 + 32LL) + 100LL));
  result = 0;
  if ( v4 )
  {
    v6 = 0;
    clear_problem_context(v8, a2, v3);
    while ( 1 )
    {
      v7 = a1[79];
      v8[10] = v6;
      v8[0] = quota_write_inode(v7, (unsigned int)(1 << v6));
      if ( v8[0] )
        break;
      if ( ++v6 == 3 )
        goto LABEL_5;
    }
    fix_problem(a1, 393222, v8);
LABEL_5:
    quota_release_context(a1 + 79);
    return v8[0];
  }
  return result;
}


// Function: e2fsck_read_all_quotas @ 0x1c440
long long e2fsck_read_all_quotas(long long *a1)
{
  long long v1; // rsi
  long long result; // rax
  unsigned int v3; // ebp
  long long v4; // rsi
  long long all_dquots; // rax
  long long v6; // [rsp+8h] [rbp-20h]

  v1 = *a1;
  if ( !(unsigned int)sub_1C370(*(unsigned int *)(*(long long *)(*a1 + 32LL) + 100LL)) )
    return 0;
  result = quota_init_context(a1 + 79, v1, 0);
  if ( !result )
  {
    v3 = 0;
    while ( 1 )
    {
      v4 = *(unsigned int *)sub_1BCF0(*(long long *)(*a1 + 32LL), v3);
      if ( (int)v4 )
      {
        all_dquots = quota_read_all_dquots(a1[79], v4, v3, 3);
        if ( all_dquots )
          break;
      }
      if ( ++v3 == 3 )
        return 0;
    }
    v6 = all_dquots;
    quota_release_context(a1 + 79);
    return v6;
  }
  return result;
}


// Function: release_orphan_inodes @ 0x1c4e0
long long release_orphan_inodes(long long *a1, long long a2, long long a3)
{
  long long v3; // r14
  unsigned int v4; // r12d
  long long result; // rax
  long long v7; // rbx
  long long v8; // rdx
  long long v9; // rsi
  unsigned int v10; // eax
  long long v11; // r15
  char *v12; // rax
  unsigned int v13; // ebx
  unsigned int *v14; // rax
  unsigned int v15; // edx
  unsigned int v16; // eax
  long long v17; // rdi
  long long v18; // rdx
  long long memory; // [rsp+18h] [rbp-160h] BYREF
  long long v20; // [rsp+20h] [rbp-158h] BYREF
  unsigned int v21; // [rsp+28h] [rbp-150h]
  long long v22; // [rsp+38h] [rbp-140h]
  char *v23; // [rsp+80h] [rbp-F8h]
  short v24[10]; // [rsp+90h] [rbp-E8h] BYREF
  unsigned int v25; // [rsp+A4h] [rbp-D4h]
  short v26; // [rsp+AAh] [rbp-CEh]
  unsigned long long v27; // [rsp+138h] [rbp-40h]

  v3 = *a1;
  v27 = __readfsqword(0x28u);
  v4 = *(int *)(*(long long *)(v3 + 32) + 232LL);
  if ( !v4 )
    return 0;
  clear_problem_context(&v20, a2, a3);
  v20 = sub_1C440(a1);
  if ( v20 )
  {
    fix_problem(a1, 76, &v20);
    return 1;
  }
  v7 = *(long long *)(v3 + 32);
  *(int *)(v7 + 232) = 0;
  ext2fs_mark_super_dirty(v3);
  if ( (*(char *)(v7 + 58) & 2) != 0 )
  {
    if ( a1[79] )
      quota_release_context(a1 + 79);
    return 0;
  }
  v9 = *(unsigned int *)(v7 + 76);
  v10 = 11;
  if ( (int)v9 )
    v10 = *(int *)(v7 + 84);
  if ( v10 > v4 || *(int *)v7 < v4 )
  {
    clear_problem_context(&v20, v9, v8);
    v21 = v4;
    fix_problem(a1, 35, &v20);
LABEL_27:
    result = 1;
    if ( a1[79] )
    {
      quota_release_context(a1 + 79);
      return 1;
    }
  }
  else
  {
    memory = e2fsck_allocate_memory(a1, (unsigned int)(4 * *(int *)(v3 + 40)), "block iterate buffer");
    e2fsck_read_bitmaps(a1);
    v11 = sub_1BC80(v24);
    while ( 1 )
    {
      e2fsck_read_inode_full(a1, v4, v11, 160, "release_orphan_inodes");
      clear_problem_context(&v20, v4, v18);
      v21 = v4;
      v22 = v11;
      if ( v26 )
        v12 = dcgettext(0, "Truncating", 5);
      else
        v12 = dcgettext(0, "Clearing", 5);
      v23 = v12;
      fix_problem(a1, 32, &v20);
      v13 = v25;
      if ( v25 )
      {
        v14 = *(unsigned int **)(v3 + 32);
        v15 = 11;
        if ( v14[19] )
          v15 = v14[21];
        if ( v15 > v25 || *v14 < v25 )
        {
          v21 = v25;
          fix_problem(a1, 36, &v20);
LABEL_33:
          ext2fs_free_mem(&memory);
          goto LABEL_27;
        }
      }
      v16 = sub_1BDC0(a1, v4, (long long)v24, memory, (long long)&v20);
      if ( v16 )
        goto LABEL_33;
      if ( !v26 )
      {
        v17 = a1[79];
        if ( v17 )
          quota_data_inodes(v17, v24, v4, 0xFFFFFFFFLL);
        ext2fs_inode_alloc_stats2(v3, v4, 0xFFFFFFFFLL, (v24[0] & 0xF000) == 0x4000);
        ++*((int *)a1 + 30);
        v16 = *((int *)a1 + 210);
      }
      v25 = v16;
      e2fsck_write_inode_full(a1, v4, v11, 160, "delete_file");
      if ( !v13 )
        break;
      v4 = v13;
    }
    ext2fs_free_mem(&memory);
    return sub_1C380(a1, v4) != 0;
  }
  return result;
}


// Function: e2fsck_fix_dirhash_hint @ 0x1c880
unsigned long long e2fsck_fix_dirhash_hint(char *a1, long long a2)
{
  long long v2; // rbp
  long long v3; // rdx
  char v5[104]; // [rsp+0h] [rbp-88h] BYREF
  unsigned long long v6; // [rsp+68h] [rbp-20h]

  v6 = __readfsqword(0x28u);
  v2 = *(long long *)(*(long long *)a1 + 32LL);
  if ( (a1[76] & 1) == 0 )
  {
    if ( (unsigned int)sub_1C870(*(unsigned int *)(v2 + 92)) )
    {
      if ( (*(char *)(v2 + 352) & 3) == 0 )
      {
        clear_problem_context(v5, a2, v3);
        if ( (unsigned int)fix_problem(a1, 52, v5) )
        {
          *(int *)(v2 + 352) |= 1u;
          ext2fs_mark_super_dirty(*(long long *)a1);
        }
      }
    }
  }
  return v6 - __readfsqword(0x28u);
}


// Function: check_resize_inode @ 0x1c930
unsigned long long check_resize_inode(long long *a1, long long a2, long long a3)
{
  long long v4; // rbp
  long long v5; // rdx
  long long v6; // r9
  unsigned int v7; // r15d
  int v8; // edx
  long long i; // rax
  bool v10; // al
  int *v12; // rax
  long long v13; // rdx
  long long v14; // rcx
  long long v15; // r8
  long long v16; // rax
  short v17; // r9
  long long memory; // rax
  long long v19; // rbx
  long long v20; // rsi
  int v21; // edi
  unsigned int v22; // eax
  unsigned int v23; // edx
  int v24; // ecx
  int v25; // ebx
  unsigned int k; // r15d
  long long v27; // [rsp+8h] [rbp-160h]
  unsigned int j; // [rsp+8h] [rbp-160h]
  long long v29; // [rsp+10h] [rbp-158h]
  int v30; // [rsp+18h] [rbp-150h]
  unsigned int v31; // [rsp+1Ch] [rbp-14Ch]
  long long v32; // [rsp+28h] [rbp-140h] BYREF
  char v33[8]; // [rsp+30h] [rbp-138h] BYREF
  int v34; // [rsp+38h] [rbp-130h]
  long long v35; // [rsp+80h] [rbp-E8h]
  int v36[34]; // [rsp+A0h] [rbp-C8h] BYREF
  unsigned long long v37; // [rsp+128h] [rbp-40h]

  v4 = *a1;
  v37 = __readfsqword(0x28u);
  v32 = 0;
  clear_problem_context(v33, a2, a3);
  if ( !(unsigned int)sub_1C920(*(unsigned int *)(*(long long *)(v4 + 32) + 92LL)) )
    goto LABEL_56;
  if ( (unsigned int)sub_1C340(*(unsigned int *)(v5 + 96)) )
  {
    if ( (unsigned int)fix_problem(a1, 81, v33) )
    {
      v16 = sub_1BC90(*(long long *)(v4 + 32), 81, v13, v14, v15, 0);
      *(short *)(v16 + 206) = v17;
      ext2fs_mark_super_dirty(v4);
    }
    if ( !(unsigned int)sub_1C920(*(unsigned int *)(*(long long *)(v4 + 32) + 92LL)) )
    {
LABEL_56:
      if ( *(short *)(v5 + 206) )
      {
        v35 = *(unsigned short *)(v5 + 206);
        if ( (unsigned int)fix_problem(a1, 46, v33) )
        {
          *(short *)(*(long long *)(v4 + 32) + 206LL) = 0;
          ext2fs_mark_super_dirty(v4);
        }
      }
    }
  }
  v34 = 7;
  if ( ext2fs_read_inode(v4, 7, v36) )
  {
    if ( (unsigned int)sub_1C920(*(unsigned int *)(*(long long *)(v4 + 32) + 92LL)) )
      *((int *)a1 + 18) |= 0x400u;
    return v37 - __readfsqword(0x28u);
  }
  if ( (unsigned int)sub_1C920(*(unsigned int *)(*(long long *)(v4 + 32) + 92LL)) )
  {
    v7 = v36[23];
    v8 = 1;
    for ( i = 0; ; ++i )
    {
      if ( i != 13 )
      {
        if ( v36[i + 10] )
        {
          v10 = (int)i <= 14;
LABEL_11:
          if ( !v36[23]
            || v10
            || !HIWORD(v36[6])
            || SLOWORD(v36[0]) >= 0
            || *(int *)(v6 + 20) > v36[23]
            || v7 >= (unsigned long long)ext2fs_blocks_count(v6)
            || (memory = e2fsck_allocate_memory(a1, (unsigned int)(2 * *(int *)(v4 + 40)), "resize dind buffer"),
                v19 = *(unsigned int *)(v4 + 40),
                v32 = memory,
                v27 = memory,
                ext2fs_read_ind_block(v4, v7, memory)) )
          {
LABEL_17:
            if ( (unsigned int)fix_problem(a1, 48, v33) )
            {
              memset(v36, 0, 0x80u);
              e2fsck_write_inode(a1, 7, v36, "clear_resize");
              *((int *)a1 + 18) |= 0x400u;
              if ( (*((char *)a1 + 76) & 1) != 0 )
                goto LABEL_19;
            }
            else if ( (*((char *)a1 + 76) & 1) != 0 )
            {
              goto LABEL_19;
            }
            *(short *)(*(long long *)(v4 + 32) + 58LL) &= ~1u;
            ext2fs_mark_super_dirty(v4);
            goto LABEL_19;
          }
          v20 = *(long long *)(v4 + 32);
          v21 = *(int *)(v20 + 20);
          v22 = *(long long *)(v4 + 56);
          v23 = *(int *)(v4 + 40);
          v30 = v21 + v22 + 1;
          if ( !v21 )
          {
            v24 = v21 + v22 + 2;
            if ( v23 != 1024 )
              v24 = v21 + v22 + 1;
            v30 = v24;
          }
          if ( *(short *)(v20 + 206) >> 2 )
          {
            v29 = v27 + v19;
            for ( j = v30; ; ++j )
            {
              v31 = v22 % (v23 >> 2);
              if ( *(int *)(v32 + 4LL * v31) != j || ext2fs_read_ind_block(v4, j, v29) )
                break;
              v25 = 0;
              for ( k = 1; *(int *)(v4 + 48) > k; ++k )
              {
                if ( (unsigned int)ext2fs_bg_has_super(v4, k) )
                {
                  if ( *(int *)(v29 + 4LL * v25) != k * *(int *)(*(long long *)(v4 + 32) + 32LL) + j )
                    goto LABEL_17;
                  ++v25;
                }
              }
              v22 = v31 + 1;
              if ( *(short *)(*(long long *)(v4 + 32) + 206LL) >> 2 <= (int)(j + 1 - v30) )
                goto LABEL_19;
              v23 = *(int *)(v4 + 40);
            }
            goto LABEL_17;
          }
LABEL_19:
          if ( v32 )
            ext2fs_free_mem(&v32);
          return v37 - __readfsqword(0x28u);
        }
        if ( v8 == 15 )
        {
          v10 = 0;
          goto LABEL_11;
        }
      }
      ++v8;
    }
  }
  v12 = &v36[10];
  while ( !*v12 )
  {
    if ( ++v12 == &v36[25] )
      return v37 - __readfsqword(0x28u);
  }
  if ( (unsigned int)fix_problem(a1, 47, v33) )
  {
    memset(v36, 0, 0x80u);
    e2fsck_write_inode(a1, 7, v36, "clear_resize");
  }
  return v37 - __readfsqword(0x28u);
}


// Function: check_super_block @ 0x1cdb0
unsigned long long check_super_block(long long a1)
{
  long long v2; // r12
  unsigned int *v3; // r15
  long long memory; // rax
  long long v5; // rsi
  long long v6; // rax
  long long v7; // rsi
  long long v8; // rax
  int *v9; // rsi
  long long v10; // rbx
  unsigned long long v11; // rdx
  int v12; // r8d
  long long v13; // rax
  unsigned long long v14; // rbx
  unsigned long long v16; // rax
  unsigned long long v17; // rax
  unsigned long long v18; // r9
  unsigned int v19; // eax
  unsigned int v20; // edx
  unsigned long long v21; // r13
  unsigned long long v22; // rax
  unsigned long long v23; // r13
  int v24; // eax
  long long v25; // rsi
  int v26; // ecx
  long long v27; // rax
  int v28; // eax
  unsigned long long v29; // rdx
  unsigned int v30; // ebx
  unsigned long long v31; // rdx
  long long v32; // r8
  long long v33; // rdx
  long long v34; // r8
  long long v35; // r8
  unsigned long long v36; // rax
  unsigned int v37; // ebx
  long long v38; // r13
  long long v39; // rax
  unsigned long long v40; // rax
  unsigned long long v41; // rbx
  unsigned long long v42; // rbx
  long long v43; // rdx
  const char *v44; // rsi
  long long v45; // rdx
  long long v46; // r8
  long long v47; // rdi
  long long v48; // rsi
  unsigned int *v49; // r8
  int v50; // edx
  long long v51; // rax
  signed long long v52; // rdx
  long long v53; // rcx
  long long v54; // rax
  int v55; // eax
  unsigned int v56; // ebx
  int v57; // eax
  int v58; // [rsp+8h] [rbp-E0h]
  unsigned long long block2; // [rsp+8h] [rbp-E0h]
  unsigned long long v60; // [rsp+10h] [rbp-D8h]
  int v61; // [rsp+10h] [rbp-D8h]
  unsigned long long v62; // [rsp+10h] [rbp-D8h]
  unsigned int v63; // [rsp+1Ch] [rbp-CCh]
  unsigned int v64; // [rsp+1Ch] [rbp-CCh]
  int v65; // [rsp+1Ch] [rbp-CCh]
  int v66; // [rsp+20h] [rbp-C8h]
  long long v67; // [rsp+20h] [rbp-C8h]
  unsigned int v68; // [rsp+28h] [rbp-C0h]
  int v69; // [rsp+28h] [rbp-C0h]
  unsigned int v70; // [rsp+2Ch] [rbp-BCh]
  unsigned int v71; // [rsp+2Ch] [rbp-BCh]
  unsigned int v72; // [rsp+34h] [rbp-B4h] BYREF
  int v73; // [rsp+38h] [rbp-B0h] BYREF
  int v74; // [rsp+3Ch] [rbp-ACh] BYREF
  char v75[8]; // [rsp+40h] [rbp-A8h] BYREF
  unsigned int v76; // [rsp+48h] [rbp-A0h]
  int v77; // [rsp+4Ch] [rbp-9Ch]
  long long v78; // [rsp+68h] [rbp-80h]
  long long v79; // [rsp+70h] [rbp-78h]
  unsigned int v80; // [rsp+80h] [rbp-68h]
  int v81; // [rsp+84h] [rbp-64h]
  int v82; // [rsp+88h] [rbp-60h]
  unsigned long long v83; // [rsp+90h] [rbp-58h]
  char *v84; // [rsp+A0h] [rbp-48h]
  unsigned long long v85; // [rsp+A8h] [rbp-40h]

  v2 = *(long long *)a1;
  v85 = __readfsqword(0x28u);
  v58 = 128;
  v3 = *(unsigned int **)(v2 + 32);
  v70 = v3[8];
  v63 = v3[6];
  if ( v3[19] )
    v58 = *((unsigned short *)v3 + 44);
  v68 = v3[7];
  v66 = *(int *)(v2 + 192);
  memory = e2fsck_allocate_memory(a1, 4LL * *(unsigned int *)(v2 + 48), "invalid_inode_bitmap");
  v5 = *(unsigned int *)(v2 + 48);
  *(long long *)(a1 + 496) = memory;
  v6 = e2fsck_allocate_memory(a1, 4 * v5, "invalid_block_bitmap");
  v7 = *(unsigned int *)(v2 + 48);
  *(long long *)(a1 + 504) = v6;
  v8 = e2fsck_allocate_memory(a1, 4 * v7, "invalid_inode_table");
  v9 = *(int **)(v2 + 32);
  *(long long *)(a1 + 512) = v8;
  v10 = (unsigned int)(65528 * ((1024 << v9[7]) / (1024 << v9[6])));
  v12 = sub_1C320((unsigned int)v9[24], v9, 0xFFFFFFFFLL);
  v13 = 0xFFFFFFFFFFFFLL;
  v14 = v10 << 32;
  if ( v14 <= 0xFFFFFFFFFFFFLL )
    v13 = v14;
  if ( v14 > v11 )
    v14 = v11;
  if ( !v12 )
    v13 = v14;
  v60 = v13;
  clear_problem_context(v75, v9, v11);
  if ( !(unsigned int)sub_1BD20(a1, (long long)"inodes_count", *v3, 1, 1u, 0) )
    return v85 - __readfsqword(0x28u);
  v16 = ext2fs_blocks_count(v3);
  if ( !(unsigned int)sub_1BD20(a1, (long long)"blocks_count", v16, 3, 1u, v60) )
    return v85 - __readfsqword(0x28u);
  v17 = ext2fs_blocks_count(v3);
  if ( !(unsigned int)sub_1BD20(a1, (long long)"first_data_block", v3[5], 2, 0, v17)
    || !(unsigned int)sub_1BD20(a1, (long long)"log_block_size", v3[6], 3, 0, 6u)
    || !(unsigned int)sub_1BD20(a1, (long long)"log_cluster_size", v3[7], 3, v3[6], 0x13u) )
  {
    return v85 - __readfsqword(0x28u);
  }
  v18 = 65528;
  v61 = 1024 << v63;
  v64 = 8 * (1024 << v63);
  if ( v64 <= 0xFFF8 )
    v18 = v64;
  if ( !(unsigned int)sub_1BD20(a1, (long long)"clusters_per_group", v3[9], 3, 8u, v18) )
    return v85 - __readfsqword(0x28u);
  v19 = 65528 * ((1024 << v68) / v61);
  if ( v19 > v64 << v66 )
    v19 = v64 << v66;
  if ( !(unsigned int)sub_1BD20(a1, (long long)"blocks_per_group", v3[8], 3, 8u, v19) )
    return v85 - __readfsqword(0x28u);
  v20 = v61 / v58 * (v70 - 4);
  if ( v20 > 0x10000 - v61 / v58 )
    v20 = 0x10000 - v61 / v58;
  if ( !(unsigned int)sub_1BD20(a1, (long long)"inodes_per_group", v3[10], 3, v61 / v58, v20) )
    return v85 - __readfsqword(0x28u);
  v21 = ext2fs_blocks_count(v3);
  v22 = ext2fs_r_blocks_count(v3);
  if ( !(unsigned int)sub_1BD20(a1, (long long)"r_blocks_count", v22, 2, 0, v21 >> 1)
    || !(unsigned int)sub_1BD20(
                        a1,
                        (long long)"reserved_gdt_blocks",
                        *((unsigned short *)v3 + 103),
                        2,
                        0,
                        (*(int *)(v2 + 40) >> 2) & 0x3FFFFFFF)
    || !(unsigned int)sub_1BD20(a1, (long long)"desc_size", *((unsigned short *)v3 + 127), 6, 0, 0x400u) )
  {
    return v85 - __readfsqword(0x28u);
  }
  v23 = *(unsigned int *)(v2 + 48) * (unsigned long long)v3[10];
  if ( v23 > 0xFFFFFFFF )
  {
    v83 = *(unsigned int *)(v2 + 48) * (unsigned long long)v3[10];
    fix_problem(a1, 80, v75);
    *(int *)(a1 + 72) |= 1u;
    return v85 - __readfsqword(0x28u);
  }
  if ( *v3 != v23 )
  {
    v76 = *v3;
    v77 = v23;
    if ( !(unsigned int)fix_problem(a1, 13, v75) )
    {
      v40 = *v3;
      v84 = "inodes_count";
      v83 = v40;
      goto LABEL_118;
    }
    *v3 = v23;
    ext2fs_mark_super_dirty(v2);
  }
  if ( !v3[19] )
    goto LABEL_32;
  if ( !(unsigned int)sub_1BD20(a1, (long long)"first_ino", v3[21], 3, 0xBu, *v3) )
    return v85 - __readfsqword(0x28u);
  if ( v3[19] )
    v24 = *((unsigned short *)v3 + 44);
  else
LABEL_32:
    v24 = 128;
  v25 = (long long)"inode_size";
  if ( (unsigned int)sub_1BD20(a1, (long long)"inode_size", v24, 7, 0x80u, *(unsigned int *)(v2 + 40)) )
  {
    v26 = *(int *)(v2 + 192);
    if ( v3[8] == v3[9] << v26 )
    {
      if ( (*(char *)(a1 + 73) & 8) != 0 )
      {
        v41 = *(long long *)(a1 + 104);
        if ( v41 < ext2fs_blocks_count(v3) )
        {
          v25 = 5;
          v78 = ext2fs_blocks_count(v3);
          v79 = *(long long *)(a1 + 104);
          if ( (unsigned int)fix_problem(a1, 5, v75) )
            goto LABEL_127;
        }
      }
      v27 = 0;
      if ( !v3[6] )
        v27 = *(int *)(v2 + 192) == 0;
      if ( v3[5] != v27 )
      {
        v78 = v3[5];
        v79 = v27;
        fix_problem(a1, 8, v75);
LABEL_127:
        *(int *)(a1 + 72) |= 1u;
        return v85 - __readfsqword(0x28u);
      }
      if ( v3[19] )
      {
        v28 = *((unsigned short *)v3 + 44);
        if ( (unsigned short)v28 > 0x80u )
        {
          v29 = *((unsigned short *)v3 + 174);
          v30 = v28 - 128;
          v83 = v29;
          if ( (short)v29 && ((unsigned short)v29 <= 3u || (unsigned short)v29 > v30 || (v29 & 3) != 0) )
          {
            v25 = 77;
            if ( (unsigned int)fix_problem(a1, 77, v75) )
            {
              *((short *)v3 + 174) = 32;
              ext2fs_mark_super_dirty(v2);
            }
          }
          v31 = *((unsigned short *)v3 + 175);
          v83 = v31;
          if ( (short)v31 && ((unsigned short)v31 > v30 || (unsigned short)v31 <= 3u || (v31 & 3) != 0) )
          {
            v25 = 78;
            if ( (unsigned int)fix_problem(a1, 78, v75) )
            {
              *((short *)v3 + 175) = 32;
              ext2fs_mark_super_dirty(v2);
            }
          }
        }
      }
      if ( !(unsigned int)sub_1C360(*(unsigned int *)(*(long long *)(v2 + 32) + 100LL)) )
        goto LABEL_213;
      if ( (unsigned int)sub_1C830() )
      {
        v25 = 70;
        if ( (unsigned int)fix_problem(a1, 70, v75) )
        {
          v56 = 0;
          sub_1BCA0(*(long long *)(v2 + 32));
          ext2fs_mark_super_dirty(v2);
          while ( *(int *)(v2 + 48) > v56 )
          {
            v25 = v56++;
            ext2fs_group_desc_csum_set(v2, v25);
          }
        }
        if ( !(unsigned int)sub_1C360(*(unsigned int *)(*(long long *)(v2 + 32) + 100LL)) )
        {
LABEL_213:
          if ( (unsigned int)sub_1C300(*(unsigned int *)(v32 + 96)) )
          {
            v25 = 75;
            if ( (unsigned int)fix_problem(a1, 75, v75) )
            {
              *(int *)(sub_1BCE0(*(long long *)(v2 + 32)) + 624) = 0;
              ext2fs_mark_super_dirty(v2);
            }
            v32 = *(long long *)(v2 + 32);
          }
        }
      }
      if ( (unsigned int)sub_1C320(*(unsigned int *)(v32 + 96), v25, v33) && !(unsigned int)sub_1C330() )
      {
        v25 = 72;
        if ( (unsigned int)fix_problem(a1, 72, v75) )
        {
          sub_1BCD0(*(long long *)(v2 + 32));
          ext2fs_mark_super_dirty(v2);
        }
        v34 = *(long long *)(v2 + 32);
      }
      if ( (*(char *)(a1 + 77) & 0x40) != 0 )
      {
        sub_1BCD0(v34);
        ext2fs_mark_super_dirty(v2);
        v34 = *(long long *)(v2 + 32);
      }
      if ( (unsigned int)sub_1C340(*(unsigned int *)(v34 + 96)) )
      {
        v36 = *(unsigned int *)(v35 + 260);
        if ( v36 > *(long long *)(v2 + 56) )
        {
          v80 = *(long long *)(v2 + 56);
          v25 = 73;
          v83 = v36;
          if ( (unsigned int)fix_problem(a1, 73, v75) )
          {
            *(int *)(sub_1BCC0(*(long long *)(v2 + 32)) + 260) = 0;
            ext2fs_mark_super_dirty(v2);
          }
        }
      }
      v37 = 0;
      block2 = v3[5];
      v62 = ext2fs_blocks_count(v3) - 1;
      v69 = 0;
      v65 = sub_1C840(*(long long *)(v2 + 32));
      v67 = 0;
      while ( 1 )
      {
        if ( *(int *)(v2 + 48) <= v37 )
        {
          *(long long *)(a1 + 112) = v67 << *(int *)(v2 + 192);
          *(int *)(a1 + 120) = v69;
          v42 = ext2fs_free_blocks_count(v3);
          if ( v42 > ext2fs_blocks_count(v3) || v3[4] > *v3 )
            ext2fs_unmark_valid(v2);
          if ( *(int *)(a1 + 520) && (*(char *)(a1 + 76) & 1) == 0 )
          {
            *((short *)v3 + 29) &= ~1u;
            ext2fs_mark_super_dirty(v2);
          }
          clear_problem_context(v75, v25, v43);
          if ( (*(char *)(a1 + 76) & 1) == 0
            && (unsigned int)uuid_is_null(v3 + 26)
            && !(unsigned int)sub_1C360(*(unsigned int *)(*(long long *)(*(long long *)a1 + 32LL) + 100LL))
            && (!v65 || (*(char *)(a1 + 124) & 1) == 0)
            && (unsigned int)fix_problem(a1, 9, v75) )
          {
            uuid_generate(v3 + 26);
            ext2fs_init_csum_seed(v2);
            v55 = *(int *)(v2 + 16);
            BYTE1(v55) &= ~2u;
            *(int *)(v2 + 16) = v55 | 4;
          }
          v44 = "options";
          profile_get_boolean(*(long long *)(a1 + 864), "options", "clear_test_fs_flag", 0, 1, &v74);
          if ( (*(char *)(a1 + 76) & 1) == 0 )
          {
            v46 = *(long long *)(v2 + 32);
            if ( v74 && (*(char *)(v46 + 352) & 4) != 0 )
            {
              if ( (unsigned int)fs_proc_check("ext4") || (unsigned int)check_for_modules("ext4") )
              {
                v44 = (char *)(&word_3A + 1);
                if ( (unsigned int)fix_problem(a1, 59, v75) )
                {
                  v57 = *(int *)(v2 + 16);
                  BYTE1(v57) &= ~2u;
                  *(int *)(*(long long *)(v2 + 32) + 352LL) &= ~4u;
                  *(int *)(v2 + 16) = v57 | 4;
                }
              }
              if ( (*(char *)(a1 + 76) & 1) == 0 )
              {
                v46 = *(long long *)(v2 + 32);
                goto LABEL_141;
              }
            }
            else
            {
LABEL_141:
              if ( *(int *)(v46 + 72) == 1 && (unsigned int)sub_1C350(*(unsigned int *)(v46 + 96)) )
              {
                v44 = byte_9 + 5;
                if ( (unsigned int)fix_problem(a1, 14, v75) )
                {
                  sub_1BCB0(*(long long *)(v2 + 32));
                  ext2fs_mark_super_dirty(v2);
                  *(int *)(v2 + 16) &= ~0x200u;
                }
                if ( (*(char *)(a1 + 76) & 1) == 0 )
                {
                  v46 = *(long long *)(v2 + 32);
                  goto LABEL_142;
                }
              }
              else
              {
LABEL_142:
                if ( *(int *)(v46 + 76) || !*(int *)(v46 + 92) && !*(long long *)(v46 + 96) )
                  goto LABEL_214;
                v44 = (char *)(&off_18 + 2);
                if ( (unsigned int)fix_problem(a1, 26, v75) )
                {
                  ext2fs_update_dynamic_rev(v2);
                  ext2fs_mark_super_dirty(v2);
                  *(int *)(v2 + 16) &= ~0x200u;
                }
                if ( (*(char *)(a1 + 76) & 1) == 0 )
                {
LABEL_214:
                  if ( sub_1C4E0((long long *)a1, (long long)v44, v45) )
                  {
                    *(short *)(*(long long *)(v2 + 32) + 58LL) &= ~1u;
                    ext2fs_mark_super_dirty(v2);
                  }
                }
              }
            }
          }
          profile_get_boolean(*(long long *)(a1 + 864), "options", "accept_time_fudge", 0, 1, &v72);
          profile_get_boolean(*(long long *)(a1 + 864), "options", "buggy_init_scripts", 0, v72, &v72);
          v47 = *(long long *)(a1 + 864);
          *(long long *)(a1 + 848) = v72 != 0 ? 0x15180 : 0;
          profile_get_boolean(v47, "options", "broken_system_clock", 0, 0, &v73);
          v48 = *(int *)(a1 + 76) & 0x100;
          if ( (*(int *)(a1 + 76) & 0x100) != 0 )
          {
            if ( !v73 )
            {
              v50 = *(int *)(a1 + 72);
              if ( (v50 & 0x2000) == 0 )
              {
                v49 = *(unsigned int **)(v2 + 32);
                goto LABEL_164;
              }
            }
            goto LABEL_160;
          }
          v49 = *(unsigned int **)(v2 + 32);
          if ( !v49[17] )
            goto LABEL_160;
          if ( !v73 )
          {
            v50 = *(int *)(a1 + 72);
            if ( (v50 & 0x2000) != 0 )
              goto LABEL_152;
LABEL_164:
            v53 = v49[11];
            v51 = *(long long *)(a1 + 840);
            if ( (unsigned int)v53 <= (unsigned int)v51 )
            {
              if ( (int)v48 )
                goto LABEL_155;
LABEL_152:
              if ( v49[17] )
                goto LABEL_153;
              goto LABEL_160;
            }
            v54 = *(long long *)(a1 + 848) + (unsigned int)v51;
            v48 = 49;
            v83 = (unsigned int)v53;
            if ( v53 <= v54 )
              v48 = 60;
            if ( (unsigned int)fix_problem(a1, v48, v75) )
            {
              *(int *)(*(long long *)(v2 + 32) + 44LL) = *(long long *)(a1 + 840);
              *(int *)(v2 + 16) |= 4u;
            }
            if ( (*(char *)(a1 + 77) & 1) != 0 )
            {
LABEL_170:
              if ( !v73 )
              {
                v50 = *(int *)(a1 + 72);
LABEL_153:
                if ( (v50 & 0x2000) == 0 )
                {
                  v49 = *(unsigned int **)(v2 + 32);
                  v51 = *(long long *)(a1 + 840);
LABEL_155:
                  v52 = v49[12];
                  if ( (unsigned int)v52 > (unsigned int)v51 )
                  {
                    v48 = 50;
                    if ( v52 <= *(long long *)(a1 + 848) + (unsigned int)v51 )
                      v48 = 61;
                    v83 = (unsigned int)v52;
                    if ( (unsigned int)fix_problem(a1, v48, v75) )
                    {
                      *(int *)(*(long long *)(v2 + 32) + 48LL) = *(long long *)(a1 + 840);
                      *(int *)(v2 + 16) |= 4u;
                    }
                  }
                }
              }
LABEL_160:
              e2fsck_validate_quota_inodes(a1);
              e2fsck_move_ext3_journal(a1);
              e2fsck_fix_ext3_journal_hint(a1);
              sub_1C880((char *)a1, v48);
              e2fsck_hide_quota(a1);
              return v85 - __readfsqword(0x28u);
            }
            v49 = *(unsigned int **)(v2 + 32);
          }
          if ( v49[17] )
            goto LABEL_170;
          goto LABEL_160;
        }
        v39 = *(long long *)(v2 + 32);
        v80 = v37;
        if ( !(unsigned int)sub_1C310(*(unsigned int *)(v39 + 96)) )
        {
          block2 = ext2fs_group_first_block2(v2, v37);
          v62 = ext2fs_group_last_block2(v2, v37);
        }
        if ( ext2fs_block_bitmap_loc(v2, v37) < block2 || ext2fs_block_bitmap_loc(v2, v37) > v62 )
        {
          v78 = ext2fs_block_bitmap_loc(v2, v37);
          if ( (unsigned int)fix_problem(a1, 1, v75) )
            ext2fs_block_bitmap_loc_set(v2, v37, 0);
        }
        if ( !ext2fs_block_bitmap_loc(v2, v37) )
        {
          ++*(int *)(*(long long *)(a1 + 504) + 4LL * v37);
          ++*(int *)(a1 + 520);
        }
        if ( ext2fs_inode_bitmap_loc(v2, v37) < block2 || ext2fs_inode_bitmap_loc(v2, v37) > v62 )
        {
          v78 = ext2fs_inode_bitmap_loc(v2, v37);
          if ( (unsigned int)fix_problem(a1, 2, v75) )
            ext2fs_inode_bitmap_loc_set(v2, v37, 0);
        }
        if ( !ext2fs_inode_bitmap_loc(v2, v37) )
        {
          ++*(int *)(*(long long *)(a1 + 496) + 4LL * v37);
          ++*(int *)(a1 + 520);
        }
        if ( ext2fs_inode_table_loc(v2, v37) < block2
          || (unsigned long long)*(unsigned int *)(v2 + 72) + ext2fs_inode_table_loc(v2, v37) - 1 > v62 )
        {
          v78 = ext2fs_inode_table_loc(v2, v37);
          if ( (unsigned int)fix_problem(a1, 3, v75) )
            ext2fs_inode_table_loc_set(v2, v37, 0);
        }
        if ( !ext2fs_inode_table_loc(v2, v37) )
        {
          ++*(int *)(*(long long *)(a1 + 512) + 4LL * v37);
          ++*(int *)(a1 + 520);
        }
        v67 += (unsigned int)ext2fs_bg_free_blocks_count(v2, v37);
        v69 += ext2fs_bg_free_inodes_count(v2, v37);
        if ( (unsigned int)ext2fs_bg_free_blocks_count(v2, v37) > v3[8]
          || (unsigned int)ext2fs_bg_free_inodes_count(v2, v37) > v3[10]
          || (unsigned int)ext2fs_bg_used_dirs_count(v2, v37) > v3[10] )
        {
          ext2fs_unmark_valid(v2);
        }
        v38 = 0;
        if ( !(unsigned int)ext2fs_group_desc_csum_verify(v2, v37) )
        {
          v81 = (unsigned short)ext2fs_bg_checksum(v2, v37);
          v82 = (unsigned short)ext2fs_group_desc_csum(v2, v37);
          if ( (unsigned int)fix_problem(a1, 53, v75) )
          {
            v38 = 1;
            ext2fs_bg_flags_clear(v2, v37, 2);
            ext2fs_bg_flags_clear(v2, v37, 1);
            ext2fs_bg_itable_unused_set(v2, v37, 0);
          }
          ext2fs_unmark_valid(v2);
        }
        if ( v65 )
        {
          if ( v37 != *(int *)(v2 + 48) - 1 || !(unsigned int)ext2fs_bg_flags_test(v2, v37, 2) )
            goto LABEL_96;
          if ( !(unsigned int)fix_problem(a1, 57, v75) )
          {
            ext2fs_unmark_valid(v2);
            goto LABEL_96;
          }
        }
        else
        {
          if ( (unsigned int)ext2fs_bg_flags_test(v2, v37, 2)
            || (unsigned int)ext2fs_bg_flags_test(v2, v37, 1)
            || (v25 = v37, (unsigned int)ext2fs_bg_itable_unused(v2, v37)) )
          {
            v25 = 54;
            if ( (unsigned int)fix_problem(a1, 54, v75) )
            {
              v38 = 1;
              ext2fs_bg_flags_clear(v2, v37, 2);
              ext2fs_bg_flags_clear(v2, v37, 1);
              v25 = v37;
              ext2fs_bg_itable_unused_set(v2, v37, 0);
            }
            ext2fs_unmark_valid(v2);
          }
          if ( v37 != *(int *)(v2 + 48) - 1 )
            goto LABEL_101;
          v25 = v37;
          if ( !(unsigned int)ext2fs_bg_flags_test(v2, v37, 2) )
            goto LABEL_101;
          v25 = 57;
          if ( !(unsigned int)fix_problem(a1, 57, v75) )
            goto LABEL_100;
        }
        ext2fs_bg_flags_clear(v2, v37, 2);
        ext2fs_unmark_valid(v2);
        if ( !v65 )
          goto LABEL_89;
        v38 = 1;
LABEL_96:
        v71 = ext2fs_bg_itable_unused(v2, v37);
        if ( v71 > (unsigned int)ext2fs_bg_free_inodes_count(v2, v37)
          || (v25 = v37, (unsigned int)ext2fs_bg_itable_unused(v2, v37) > v3[10]) )
        {
          v25 = 56;
          v78 = (unsigned int)ext2fs_bg_itable_unused(v2, v37);
          if ( (unsigned int)fix_problem(a1, 56, v75) )
          {
            v25 = v37;
            v38 = 1;
            ext2fs_bg_itable_unused_set(v2, v37, 0);
          }
LABEL_100:
          ext2fs_unmark_valid(v2);
        }
LABEL_101:
        if ( v38 )
        {
LABEL_89:
          v25 = v37;
          ext2fs_group_desc_csum_set(v2, v37);
        }
        if ( (*(char *)(a1 + 72) & 3) != 0 )
          return v85 - __readfsqword(0x28u);
        ++v37;
      }
    }
    v83 = v3[9] << v26;
    v84 = "block_size";
LABEL_118:
    fix_problem(a1, 11, v75);
    *(int *)(a1 + 72) |= 1u;
  }
  return v85 - __readfsqword(0x28u);
}


// Function: check_backup_super_block @ 0x1df40
long long check_backup_super_block(long long *a1)
{
  long long v1; // rbx
  unsigned int v2; // ebp
  long long block2; // rax
  int *v4; // rax
  unsigned int v5; // r12d
  int v7[14]; // [rsp+0h] [rbp-428h] BYREF
  short v8; // [rsp+38h] [rbp-3F0h]
  unsigned int v9; // [rsp+4Ch] [rbp-3DCh]
  unsigned short v10; // [rsp+58h] [rbp-3D0h]
  int v11; // [rsp+5Ch] [rbp-3CCh]
  int v12; // [rsp+60h] [rbp-3C8h]
  int v13; // [rsp+64h] [rbp-3C4h]
  char s2[232]; // [rsp+68h] [rbp-3C0h] BYREF
  int v15; // [rsp+150h] [rbp-2D8h]
  unsigned long long v16; // [rsp+408h] [rbp-20h]

  v1 = *a1;
  v16 = __readfsqword(0x28u);
  if ( (*(char *)(v1 + 17) & 2) == 0
    || !(unsigned int)ext2fs_test_valid(v1)
    || (*(char *)(*(long long *)(v1 + 32) + 58LL) & 2) != 0
    || (a1[9] & 0x100000003LL) != 0
    || *(int *)(v1 + 48) <= 1u )
  {
    return 0;
  }
  v2 = 1;
  while ( 1 )
  {
    if ( (unsigned int)ext2fs_bg_has_super(v1, v2) )
    {
      block2 = ext2fs_group_first_block2(v1, v2);
      if ( !(*(long long (**)(long long, long long, long long, int *))(*(long long *)(*(long long *)(v1 + 8) + 8LL) + 40LL))(
              *(long long *)(v1 + 8),
              block2,
              4294966272LL,
              v7)
        && v8 == -4269
        && v9 <= 1
        && (unsigned int)(v7[6] + 10) <= 0x10
        && (!v9 || v10 > 0x7Fu) )
      {
        break;
      }
    }
    if ( *(int *)(v1 + 48) <= ++v2 )
      return 0;
  }
  v4 = *(int **)(v1 + 32);
  v5 = 1;
  if ( v4[23] == v11
    && ((v12 ^ v4[24]) & 0xFFFFFFBB) == 0
    && ((v13 ^ v4[25]) & 0xFFFFFFDD) == 0
    && v4[1] == v7[1]
    && v4[84] == v15
    && *v4 == v7[0]
    && !memcmp(v4 + 26, s2, 0x10u) )
  {
    return 0;
  }
  return v5;
}


// Function: check_inode_extra_negative_epoch @ 0x1e170
long long check_inode_extra_negative_epoch(int a1, char a2)
{
  long long result; // rax

  result = 0;
  if ( a1 < 0 )
    return (a2 & 3) == 3;
  return result;
}


// Function: quota_inum_is_super @ 0x1e190
long long quota_inum_is_super(long long a1)
{
  long long v1; // r8
  unsigned int v2; // edx
  int *v3; // rax
  int v4; // edx
  int v5; // ecx

  v1 = a1;
  v2 = 0;
  while ( 1 )
  {
    v3 = (int *)sub_1E140(v1, v2);
    if ( *v3 == v5 )
      break;
    v2 = v4 + 1;
    if ( v2 == 3 )
      return 0;
  }
  return 1;
}


// Function: pass1_get_blocks @ 0x1e1c0
long long pass1_get_blocks(long long a1, int a2, long long a3)
{
  long long v3; // rax
  long long v4; // r8
  long long v5; // rsi
  long long i; // rax

  v3 = *(long long *)(a1 + 224);
  v4 = 2133571393;
  if ( *(int *)(v3 + 536) == a2 )
  {
    v5 = *(long long *)(v3 + 544);
    if ( v5 )
    {
      for ( i = 0; i != 60; i += 4 )
        *(int *)(a3 + i) = *(int *)(v5 + i + 40);
      return 0;
    }
  }
  return v4;
}


// Function: pass1_read_inode @ 0x1e210
long long pass1_read_inode(long long a1, int a2, __m128i *a3)
{
  long long v3; // rax
  long long v4; // r8
  const __m128i *v5; // rax

  v3 = *(long long *)(a1 + 224);
  v4 = 2133571393;
  if ( *(int *)(v3 + 536) == a2 )
  {
    v5 = *(const __m128i **)(v3 + 544);
    if ( v5 )
    {
      v4 = 0;
      *a3 = _mm_loadu_si128(v5);
      a3[1] = _mm_loadu_si128(v5 + 1);
      a3[2] = _mm_loadu_si128(v5 + 2);
      a3[3] = _mm_loadu_si128(v5 + 3);
      a3[4] = _mm_loadu_si128(v5 + 4);
      a3[5] = _mm_loadu_si128(v5 + 5);
      a3[6] = _mm_loadu_si128(v5 + 6);
      a3[7] = _mm_loadu_si128(v5 + 7);
    }
  }
  return v4;
}


// Function: pass1_write_inode @ 0x1e290
long long pass1_write_inode(long long a1, int a2, const __m128i *a3)
{
  long long v3; // rax
  __m128i *v5; // rax

  v3 = *(long long *)(a1 + 224);
  if ( *(int *)(v3 + 536) != a2 )
    return 2133571393;
  v5 = *(__m128i **)(v3 + 544);
  if ( !v5 || v5 == a3 )
    return 2133571393;
  *v5 = _mm_loadu_si128(a3);
  v5[1] = _mm_loadu_si128(a3 + 1);
  v5[2] = _mm_loadu_si128(a3 + 2);
  v5[3] = _mm_loadu_si128(a3 + 3);
  v5[4] = _mm_loadu_si128(a3 + 4);
  v5[5] = _mm_loadu_si128(a3 + 5);
  v5[6] = _mm_loadu_si128(a3 + 6);
  v5[7] = _mm_loadu_si128(a3 + 7);
  return 2133571393;
}


// Function: pass1_check_directory @ 0x1e310
long long pass1_check_directory(long long a1, int a2)
{
  long long v2; // rdx
  long long result; // rax
  short *v4; // rdx

  v2 = *(long long *)(a1 + 224);
  result = 2133571393;
  if ( *(int *)(v2 + 536) == a2 )
  {
    v4 = *(short **)(v2 + 544);
    if ( v4 )
    {
      result = 0;
      if ( (*v4 & 0xF000) != 0x4000 )
        return 2133571402;
    }
  }
  return result;
}


// Function: e2fsck_block_alloc_stats @ 0x1e350
void e2fsck_block_alloc_stats(long long a1, long long a2, long long a3, long long a4)
{
  long long v4; // rbx
  long long v5; // rdi
  long long v6; // r8

  v4 = *(long long *)(a1 + 224);
  v5 = *(long long *)(v4 + 416);
  if ( v5 )
  {
    v6 = *(long long *)(v4 + 912);
    if ( (int)a3 >= 0 || !v6 )
    {
      if ( (int)a3 > 0 )
      {
        ext2fs_mark_block_bitmap2(v5, a2, a3, a4, v6);
        return;
      }
      goto LABEL_8;
    }
    if ( !(unsigned int)ext2fs_test_block_bitmap2(*(long long *)(v4 + 912), a2) )
    {
      v5 = *(long long *)(v4 + 416);
      if ( v5 )
LABEL_8:
        ext2fs_unmark_block_bitmap2(v5, a2, a3, a4, v6);
    }
  }
}


// Function: could_be_block_map @ 0x1e3d0
long long could_be_block_map(long long a1, long long a2)
{
  unsigned int *v2; // rbx
  unsigned long long v3; // rbp

  v2 = (unsigned int *)(a2 + 40);
  while ( 1 )
  {
    v3 = *v2;
    if ( v3 >= ext2fs_blocks_count(*(long long *)(a1 + 32)) )
      break;
    if ( ++v2 == (unsigned int *)(a2 + 100) )
      return 1;
  }
  return 0;
}


// Function: alloc_bb_map @ 0x1e430
unsigned long long alloc_bb_map(long long a1, long long a2, long long a3)
{
  char *v3; // rax
  long long v5[13]; // [rsp+0h] [rbp-88h] BYREF
  unsigned long long v6; // [rsp+68h] [rbp-20h]

  v6 = __readfsqword(0x28u);
  clear_problem_context(v5, a2, a3);
  v3 = dcgettext(0, "inode in bad block map", 5);
  v5[0] = e2fsck_allocate_inode_bitmap(*(long long *)a1, v3, 2, "inode_bb_map", a1 + 384);
  if ( v5[0] )
  {
    v5[10] = 4;
    fix_problem(a1, 65572, v5);
    *(int *)(a1 + 72) |= 1u;
  }
  return v6 - __readfsqword(0x28u);
}


// Function: alloc_imagic_map @ 0x1e4e0
unsigned long long alloc_imagic_map(long long a1, long long a2, long long a3)
{
  char *v3; // rax
  long long v5[13]; // [rsp+0h] [rbp-88h] BYREF
  unsigned long long v6; // [rsp+68h] [rbp-20h]

  v6 = __readfsqword(0x28u);
  clear_problem_context(v5, a2, a3);
  v3 = dcgettext(0, "imagic inode map", 5);
  v5[0] = e2fsck_allocate_inode_bitmap(*(long long *)a1, v3, 2, "inode_imagic_map", a1 + 392);
  if ( v5[0] )
  {
    v5[10] = 5;
    fix_problem(a1, 65572, v5);
    *(int *)(a1 + 72) |= 1u;
  }
  return v6 - __readfsqword(0x28u);
}


// Function: mark_inode_bad @ 0x1e590
unsigned long long mark_inode_bad(long long a1, long long a2, long long a3)
{
  long long v4; // rdi
  char *v6; // rax
  long long v7[13]; // [rsp+0h] [rbp-88h] BYREF
  unsigned long long v8; // [rsp+68h] [rbp-20h]

  v4 = *(long long *)(a1 + 368);
  v8 = __readfsqword(0x28u);
  if ( !v4 )
  {
    clear_problem_context(v7, a2, a3);
    v6 = dcgettext(0, "bad inode map", 5);
    v7[0] = e2fsck_allocate_inode_bitmap(*(long long *)a1, v6, 2, "inode_bad_map", a1 + 368);
    if ( v7[0] )
    {
      v7[10] = 3;
      fix_problem(a1, 65572, v7);
      *(int *)(a1 + 72) |= 1u;
      return v8 - __readfsqword(0x28u);
    }
    v4 = *(long long *)(a1 + 368);
  }
  ext2fs_mark_inode_bitmap2(v4, (unsigned int)a2);
  return v8 - __readfsqword(0x28u);
}


// Function: check_extents_inlinedata @ 0x1e660
long long check_extents_inlinedata(long long a1, long long a2)
{
  long long result; // rax
  long long v3; // rdx
  long long v4; // rsi

  result = *(long long *)(a2 + 24);
  if ( (*(int *)(result + 32) & 0x10080000) != 0 )
  {
    result = fix_problem(a1, 65654, a2);
    if ( (int)result )
    {
      v3 = *(long long *)(a2 + 24);
      v4 = *(unsigned int *)(a2 + 8);
      *(int *)(v3 + 32) &= 0xEFF7FFFF;
      return e2fsck_write_inode(a1, v4, v3, "pass1");
    }
  }
  return result;
}


// Function: check_immutable @ 0x1e6c0
long long check_immutable(long long a1, long long a2)
{
  long long result; // rax
  long long v3; // rdx
  long long v4; // rsi

  result = *(long long *)(a2 + 24);
  if ( (*(char *)(result + 32) & 0x30) != 0 )
  {
    result = fix_problem(a1, 65584, a2);
    if ( (int)result )
    {
      v3 = *(long long *)(a2 + 24);
      v4 = *(unsigned int *)(a2 + 8);
      *(int *)(v3 + 32) &= 0xFFFFFFCF;
      return e2fsck_write_inode(a1, v4, v3, "pass1");
    }
  }
  return result;
}


// Function: check_size @ 0x1e720
unsigned long long check_size(long long *a1, long long a2)
{
  long long v2; // rbp
  unsigned long long result; // rax

  v2 = *(long long *)(a2 + 24);
  result = *(unsigned int *)(v2 + 4) | ((unsigned long long)*(unsigned int *)(v2 + 108) << 32);
  if ( result )
  {
    result = fix_problem(a1, 65586, a2);
    if ( (int)result )
    {
      ext2fs_inode_size_set(*a1, v2, 0);
      return e2fsck_write_inode(a1, *(unsigned int *)(a2 + 8), *(long long *)(a2 + 24), "pass1");
    }
  }
  return result;
}


// Function: process_inode_cmp @ 0x1e780
long long process_inode_cmp(int *a1, int *a2)
{
  long long result; // rax
  long long v4; // rsi
  int v5; // ebx
  long long v6; // rax

  result = (unsigned int)(a1[28] - a2[28]);
  if ( !(int)result )
  {
    v4 = ext2fs_const_inode(a1 + 6);
    v5 = ext2fs_file_acl_block(0, v4);
    v6 = ext2fs_const_inode(a2 + 6);
    result = v5 - (unsigned int)ext2fs_file_acl_block(0, v6);
    if ( !(int)result )
      return (unsigned int)(*a1 - *a2);
  }
  return result;
}


// Function: mark_table_blocks @ 0x1e7e0
unsigned long long mark_table_blocks(long long *a1, long long a2, long long a3)
{
  long long v3; // rbp
  unsigned int v4; // ebx
  long long v5; // rdx
  long long v6; // rax
  long long v7; // rax
  long long v8; // rax
  long long v10; // rax
  long long v11; // rdx
  long long v12; // rcx
  long long v13; // r8
  long long v14; // rax
  long long v15; // rdx
  long long v16; // rcx
  long long v17; // r8
  long long v18; // rax
  long long v19; // rdx
  long long v20; // rcx
  long long v21; // r8
  long long v22; // rax
  long long v23; // rdx
  long long v24; // rcx
  long long v25; // r8
  long long v26; // r15
  unsigned int v27; // r13d
  long long v28; // rax
  long long v29; // rdx
  long long v30; // rcx
  long long v31; // r8
  long long v32; // rdx
  long long v33; // rcx
  long long v34; // r8
  char v35[40]; // [rsp+10h] [rbp-A8h] BYREF
  long long v36; // [rsp+38h] [rbp-80h]
  unsigned int v37; // [rsp+50h] [rbp-68h]
  unsigned long long v38; // [rsp+78h] [rbp-40h]

  v3 = *a1;
  v38 = __readfsqword(0x28u);
  clear_problem_context(v35, a2, a3);
  if ( *(int *)(v3 + 48) )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = a1[52];
      v37 = v4;
      ext2fs_reserve_super_and_bgd(v3, v4, v5);
      ext2fs_reserve_super_and_bgd(v3, v4, a1[114]);
      if ( ext2fs_inode_table_loc(v3, v4) )
      {
        v26 = ext2fs_inode_table_loc(v3, v4);
        if ( *(int *)(v3 + 72) )
        {
          v27 = 0;
          do
          {
            if ( (unsigned int)ext2fs_test_block_bitmap2(a1[52], v26) )
            {
              v28 = a1[64];
              v36 = v26;
              if ( !*(int *)(v28 + 4LL * v4) && (unsigned int)fix_problem(a1, 65545, v35) )
              {
                ++*(int *)(4LL * v4 + a1[64]);
                ++*((int *)a1 + 130);
              }
            }
            else
            {
              ext2fs_mark_block_bitmap2(a1[52], v26, v29, v30, v31);
              ext2fs_mark_block_bitmap2(a1[114], v26, v32, v33, v34);
            }
            ++v27;
            ++v26;
          }
          while ( *(int *)(v3 + 72) > v27 );
        }
      }
      if ( !ext2fs_block_bitmap_loc(v3, v4) )
        goto LABEL_3;
      v6 = ext2fs_block_bitmap_loc(v3, v4);
      if ( !(unsigned int)ext2fs_test_block_bitmap2(a1[52], v6) )
        break;
      v36 = ext2fs_block_bitmap_loc(v3, v4);
      if ( !(unsigned int)fix_problem(a1, 65543, v35) )
        goto LABEL_3;
      ++*(int *)(a1[63] + 4LL * v4);
      ++*((int *)a1 + 130);
      if ( !ext2fs_inode_bitmap_loc(v3, v4) )
        goto LABEL_4;
LABEL_10:
      v7 = ext2fs_inode_bitmap_loc(v3, v4);
      if ( !(unsigned int)ext2fs_test_block_bitmap2(a1[52], v7) )
      {
        v18 = ext2fs_inode_bitmap_loc(v3, v4);
        ext2fs_mark_block_bitmap2(a1[114], v18, v19, v20, v21);
        v22 = ext2fs_inode_bitmap_loc(v3, v4);
        ext2fs_mark_block_bitmap2(a1[52], v22, v23, v24, v25);
        goto LABEL_4;
      }
      v36 = ext2fs_inode_bitmap_loc(v3, v4);
      if ( (unsigned int)fix_problem(a1, 65544, v35) )
      {
        v8 = v4++;
        ++*(int *)(a1[62] + 4 * v8);
        ++*((int *)a1 + 130);
        if ( *(int *)(v3 + 48) <= v4 )
          return v38 - __readfsqword(0x28u);
      }
      else
      {
LABEL_4:
        if ( *(int *)(v3 + 48) <= ++v4 )
          return v38 - __readfsqword(0x28u);
      }
    }
    v10 = ext2fs_block_bitmap_loc(v3, v4);
    ext2fs_mark_block_bitmap2(a1[52], v10, v11, v12, v13);
    v14 = ext2fs_block_bitmap_loc(v3, v4);
    ext2fs_mark_block_bitmap2(a1[114], v14, v15, v16, v17);
LABEL_3:
    if ( !ext2fs_inode_bitmap_loc(v3, v4) )
      goto LABEL_4;
    goto LABEL_10;
  }
  return v38 - __readfsqword(0x28u);
}


// Function: pass1_readahead @ 0x1eae0
long long pass1_readahead(int *a1, unsigned int *a2, int *a3)
{
  unsigned int v4; // eax
  long long v5; // rsi
  long long v6; // rdx
  long long v7; // rdi
  int v8; // ecx
  unsigned int v9; // ebp
  unsigned int v10; // r13d
  long long v11; // r12
  int v12; // ebx
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  long long v16; // rcx
  long long v17; // rax
  int v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // eax
  long long v21; // rdx
  long long result; // rax
  unsigned int v25; // [rsp+18h] [rbp-40h]

  v4 = *a2;
  v5 = *(long long *)a1;
  v25 = v4;
  v6 = *(long long *)(*(long long *)a1 + 32LL);
  if ( !*((long long *)a1 + 115) )
    goto LABEL_18;
  v7 = *(long long *)a1;
  v8 = 128;
  if ( *(int *)(v6 + 76) )
    v8 = *(unsigned short *)(v6 + 88);
  v9 = (1024 << *(int *)(v6 + 24)) / v8;
  if ( v4 >= *(int *)(v5 + 48) )
  {
    v10 = v4;
    v16 = 1;
    v12 = 0;
  }
  else
  {
    v10 = v4;
    v11 = 0;
    v12 = 0;
    do
    {
      v13 = ext2fs_bg_flags_test(v7, v10, 1);
      v7 = *(long long *)a1;
      if ( !v13 )
      {
        v14 = *(int *)(*(long long *)(v7 + 32) + 40LL);
        v15 = ext2fs_bg_itable_unused(v7, v10);
        v7 = *(long long *)a1;
        v12 = v14 - v15;
        v11 += (v9 - 1 + v12) / v9;
        if ( v11 * (unsigned long long)*(unsigned int *)(*(long long *)a1 + 40LL) > *((long long *)a1 + 115) << 10 )
          break;
      }
      ++v10;
    }
    while ( *(int *)(v7 + 48) > v10 );
    v16 = v10 + 1 - v25;
  }
  v17 = e2fsck_readahead(v7, 16, v25, v16);
  if ( v17 == 11 )
  {
    *((long long *)a1 + 115) >>= 1;
    goto LABEL_12;
  }
  if ( v17 )
  {
    v5 = *(long long *)a1;
LABEL_18:
    *a2 = *(int *)(v5 + 48);
    result = **(unsigned int **)(v5 + 32);
    goto LABEL_19;
  }
LABEL_12:
  *a2 = v10 + 1;
  v18 = a1[151];
  v19 = 128;
  if ( !v18 )
    v18 = 8;
  v20 = *(int *)(*(long long *)a1 + 40LL) * v18;
  v21 = *(long long *)(*(long long *)a1 + 32LL);
  if ( *(int *)(v21 + 76) )
    v19 = *(unsigned short *)(v21 + 88);
  result = v12 + v10 * *(int *)(v21 + 40) - (v12 - 1) % (v20 / v19);
LABEL_19:
  *a3 = result;
  return result;
}


// Function: quota_inum_is_reserved @ 0x1ec90
long long quota_inum_is_reserved(long long a1, int a2)
{
  unsigned int v2; // ebx

  v2 = 0;
  while ( (unsigned int)quota_type2inum(v2, *(long long *)(a1 + 32)) != a2 )
  {
    if ( ++v2 == 3 )
      return 0;
  }
  return 1;
}


// Function: inc_ea_inode_refs @ 0x1ecd0
void inc_ea_inode_refs(long long a1, long long *a2, int *a3, unsigned long long a4)
{
  long long v4; // r14
  int *v8; // rbx
  long long v9; // rsi
  long long v10; // rdi
  long long v11; // rax

  if ( (unsigned long long)a3 < a4 )
  {
    v4 = a1 + 488;
    v8 = a3;
    while ( *v8 )
    {
      v9 = (unsigned int)v8[1];
      if ( (int)v9 )
      {
        v10 = *(long long *)(a1 + 488);
        if ( !v10 )
        {
          v11 = ea_refcount_create(0, v4);
          *a2 = v11;
          if ( v11 )
          {
            a2[10] = 4;
            fix_problem(a1, 65592, a2);
            *(int *)(a1 + 72) |= 1u;
            return;
          }
          v9 = (unsigned int)v8[1];
          v10 = *(long long *)(a1 + 488);
        }
        ea_refcount_increment(v10, v9, 0);
      }
      v8 = (int *)((char *)v8 + ((*(unsigned char *)v8 + 19) & 0x1FC));
      if ( a4 <= (unsigned long long)v8 )
        return;
    }
  }
}


// Function: add_casefolded_dir @ 0x1ed80
unsigned long long add_casefolded_dir(long long a1, unsigned int a2)
{
  long long v3; // rdi
  long long v5[13]; // [rsp+0h] [rbp-88h] BYREF
  unsigned long long v6; // [rsp+68h] [rbp-20h]

  v3 = *(long long *)(a1 + 880);
  v6 = __readfsqword(0x28u);
  if ( !v3 )
  {
    v5[0] = ext2fs_u32_list_create(a1 + 880, 0);
    if ( v5[0] )
      goto LABEL_3;
    v3 = *(long long *)(a1 + 880);
  }
  v5[0] = ext2fs_u32_list_add(v3, a2);
  if ( v5[0] )
  {
LABEL_3:
    fix_problem(a1, 65676, v5);
    *(int *)(a1 + 72) |= 1u;
  }
  return v6 - __readfsqword(0x28u);
}


// Function: check_blocks_inline_data @ 0x1ee10
unsigned long long check_blocks_inline_data(int *a1, long long *a2, unsigned int *a3)
{
  long long v7; // rax
  long long v8; // rdi
  long long v9; // rsi
  int v10; // eax
  int v11; // r13d
  long long v12; // rax
  long long v13; // rcx
  long long v14; // rax
  unsigned long long v15; // [rsp+0h] [rbp-38h] BYREF
  unsigned long long v16; // [rsp+8h] [rbp-30h]

  v16 = __readfsqword(0x28u);
  v15 = 0;
  if ( (a3[1] & 1) == 0 )
    goto LABEL_2;
  v7 = ext2fs_add_dir_block2(*(long long *)(*(long long *)a1 + 144LL), *a3, 0, 0);
  *a2 = v7;
  if ( v7 )
    goto LABEL_8;
  v8 = *(long long *)a1;
  v9 = *a3;
  v10 = *(int *)(*(long long *)a1 + 16LL);
  v11 = v10 & 0x200000;
  *(int *)(v8 + 16) = v10 | 0x200000;
  v12 = ext2fs_inline_data_size(v8, v9, &v15);
  v13 = *(long long *)a1;
  *a2 = v12;
  *(int *)(v13 + 16) = v11 | *(int *)(v13 + 16) & 0xFFDFFFFF;
  if ( v12 )
  {
LABEL_2:
    *a2 = 0;
    return v16 - __readfsqword(0x28u);
  }
  if ( v15 > 0x3C )
  {
    v14 = ext2fs_add_dir_block2(*(long long *)(v13 + 144), *a3, 0, 1);
    *a2 = v14;
    if ( v14 )
    {
LABEL_8:
      a2[5] = 0;
      a2[10] = 0;
      fix_problem(a1, 65579, a2);
      a1[18] |= 1u;
    }
  }
  return v16 - __readfsqword(0x28u);
}


// Function: recheck_bad_inode_checksum @ 0x1ef30
long long recheck_bad_inode_checksum(long long a1, long long a2, long long a3, long long a4)
{
  long long result; // rax
  long long v7[27]; // [rsp+0h] [rbp-D8h] BYREF

  v7[21] = __readfsqword(0x28u);
  *(int *)(a3 + 536) = 0;
  result = ext2fs_read_inode_full(a1, a2, v7, 160);
  if ( !result )
    return 0;
  if ( result != 2133571474 )
    return result;
  if ( (unsigned int)fix_problem(a3, 65640, a4) )
    return ext2fs_write_inode_full(a1, (unsigned int)a2, v7, 160);
  else
    return 0;
}


// Function: finish_processing_inode @ 0x1eff0
void finish_processing_inode(long long a1, long long a2, long long *a3, int a4)
{
  long long v5; // rax

  if ( a4 )
  {
    v5 = sub_1EF30(*(long long *)a1, a2, a1, (long long)a3);
    *a3 = v5;
    if ( v5 )
      *(int *)(a1 + 72) |= 1u;
  }
}


// Function: reserve_block_for_root_repair @ 0x1f030
unsigned long long reserve_block_for_root_repair(long long *a1)
{
  long long v1; // rbp
  long long v3; // rdx
  long long v4; // rcx
  long long v5; // r8
  long long v6; // [rsp+0h] [rbp-28h] BYREF
  unsigned long long v7; // [rsp+8h] [rbp-20h]

  v1 = *a1;
  v7 = __readfsqword(0x28u);
  v6 = 0;
  a1[111] = 0;
  if ( !(unsigned int)ext2fs_test_inode_bitmap2(a1[45], 2) && !ext2fs_new_block2(v1, 0, a1[52], &v6) )
  {
    ext2fs_mark_block_bitmap2(a1[52], v6, v3, v4, v5);
    a1[111] = v6;
  }
  return v7 - __readfsqword(0x28u);
}


// Function: reserve_block_for_lnf_repair @ 0x1f0d0
unsigned long long reserve_block_for_lnf_repair(long long *a1)
{
  long long v1; // rbp
  long long v3; // rdx
  long long v4; // rcx
  long long v5; // r8
  char v6[4]; // [rsp+Ch] [rbp-2Ch] BYREF
  long long v7; // [rsp+10h] [rbp-28h] BYREF
  unsigned long long v8; // [rsp+18h] [rbp-20h]

  v1 = *a1;
  v8 = __readfsqword(0x28u);
  a1[112] = 0;
  v7 = 0;
  if ( ext2fs_lookup(v1, 2, "lost+found", 10, 0, v6) && !ext2fs_new_block2(v1, 0, a1[52], &v7) )
  {
    ext2fs_mark_block_bitmap2(a1[52], v7, v3, v4, v5);
    a1[112] = v7;
  }
  return v8 - __readfsqword(0x28u);
}


// Function: adjust_extattr_refcount @ 0x1f180
unsigned long long adjust_extattr_refcount(long long *a1, long long a2, long long a3, int a4)
{
  long long i; // rax
  unsigned int v6; // ebx
  long long v7; // r15
  long long v9; // [rsp+10h] [rbp-C8h]
  int v11; // [rsp+28h] [rbp-B0h] BYREF
  long long ext_attr3; // [rsp+30h] [rbp-A8h] BYREF
  unsigned int v13; // [rsp+38h] [rbp-A0h]
  long long v14; // [rsp+58h] [rbp-80h]
  long long v15; // [rsp+68h] [rbp-70h]
  long long v16; // [rsp+80h] [rbp-58h]
  unsigned long long v17; // [rsp+98h] [rbp-40h]

  v17 = __readfsqword(0x28u);
  v9 = *a1;
  clear_problem_context(&ext_attr3, a2, a3);
  ea_refcount_intr_begin(a2);
  for ( i = ea_refcount_intr_next(a2, &v11); ; i = ea_refcount_intr_next(a2, &v11) )
  {
    v7 = i;
    if ( !i )
      break;
    v14 = i;
    ext_attr3 = ext2fs_read_ext_attr3(v9, i, a3, v13);
    if ( ext_attr3 )
    {
      fix_problem(a1, 65595, &ext_attr3);
      return v17 - __readfsqword(0x28u);
    }
    v6 = *(int *)(a3 + 4) + v11 * a4;
    v15 = *(unsigned int *)(a3 + 4);
    v16 = v6;
    if ( (unsigned int)fix_problem(a1, 65596, &ext_attr3) )
    {
      *(int *)(a3 + 4) = v6;
      ext_attr3 = ext2fs_write_ext_attr3(v9, v7, a3, v13);
      if ( ext_attr3 )
        fix_problem(a1, 65597, &ext_attr3);
    }
  }
  return v17 - __readfsqword(0x28u);
}


// Function: e2fsck_block_alloc_stats_range @ 0x1f2d0
void e2fsck_block_alloc_stats_range(long long a1, long long a2, long long a3, long long a4)
{
  long long v4; // rbx
  long long v5; // rdi
  long long v6; // r8
  int v7; // eax
  unsigned int v8; // [rsp+Ch] [rbp-Ch]

  v4 = *(long long *)(a1 + 224);
  v5 = *(long long *)(v4 + 416);
  if ( v5 )
  {
    v6 = *(long long *)(v4 + 912);
    if ( (int)a4 >= 0 || !v6 )
    {
      if ( (int)a4 > 0 )
      {
        ext2fs_mark_block_bitmap_range2(v5, a2, a3, a4, v6);
        return;
      }
      goto LABEL_8;
    }
    v8 = a3;
    v7 = ext2fs_test_block_bitmap_range2(*(long long *)(v4 + 912));
    a3 = v8;
    if ( !v7 )
    {
      v5 = *(long long *)(v4 + 416);
      if ( v5 )
LABEL_8:
        ext2fs_unmark_block_bitmap_range2(v5, a2, a3, a4, v6);
    }
  }
}


// Function: e2fsck_new_range @ 0x1f350
long long e2fsck_new_range(long long a1, int a2, int a3, int a4, int a5, long long a6)
{
  long long v8; // r8
  long long result; // rax
  int v10; // [rsp+10h] [rbp-28h]
  int v11; // [rsp+18h] [rbp-20h]

  v8 = *(long long *)(*(long long *)(a1 + 224) + 416LL);
  if ( v8 )
    return ext2fs_new_range(a1, a2, a3, a4, v8, a5, a6);
  v8 = *(long long *)(a1 + 88);
  if ( v8 )
    return ext2fs_new_range(a1, a2, a3, a4, v8, a5, a6);
  v11 = a4;
  v10 = a3;
  result = ext2fs_read_block_bitmap();
  if ( !result )
  {
    a4 = v11;
    a3 = v10;
    v8 = *(long long *)(a1 + 88);
    return ext2fs_new_range(a1, a2, a3, a4, v8, a5, a6);
  }
  return result;
}


// Function: e2fsck_get_alloc_block @ 0x1f3d0
long long e2fsck_get_alloc_block(long long a1, long long a2, long long *a3)
{
  long long v5; // rdx
  long long result; // rax
  long long v7; // rdx
  long long v8; // rcx
  long long v9; // r8
  long long v10; // rdi
  long long v11; // rsi
  long long v12; // rdx
  long long v13[5]; // [rsp+10h] [rbp-28h] BYREF

  v13[1] = __readfsqword(0x28u);
  v5 = *(long long *)(*(long long *)(a1 + 224) + 416LL);
  if ( v5 )
  {
    result = ext2fs_new_block2(a1, a2, v5, v13);
    if ( !result )
    {
      v10 = *(long long *)(a1 + 88);
      v11 = v13[0];
      if ( v10 )
      {
        ext2fs_mark_block_bitmap2(v10, v13[0], v7, v8, v9);
        ext2fs_mark_bb_dirty(a1);
        v11 = v13[0];
      }
      *a3 = v11;
      return 0;
    }
  }
  else
  {
    v12 = *(long long *)(a1 + 88);
    if ( !v12 )
    {
      result = ext2fs_read_block_bitmap();
      if ( result )
        return result;
      v12 = *(long long *)(a1 + 88);
    }
    result = ext2fs_new_block2(a1, a2, v12, v13);
    if ( !result )
    {
      *a3 = v13[0];
      return 0;
    }
  }
  return result;
}


// Function: check_large_ea_inode @ 0x1f600
long long check_large_ea_inode(long long *a1, int *a2, long long a3, long long *a4)
{
  long long v7; // rdx
  unsigned int v8; // eax
  unsigned int *v9; // rdx
  long long v10; // rsi
  long long v11; // r15
  long long v12; // rax
  unsigned int v13; // r13d
  long long v15; // rax
  unsigned int v16; // eax
  int v17; // r8d
  int v18; // r9d
  long long v19; // rsi
  long long v20; // rdi
  int v21; // [rsp+Ch] [rbp-DCh]
  int v22; // [rsp+1Ch] [rbp-CCh] BYREF
  char v23[16]; // [rsp+20h] [rbp-C8h] BYREF
  int v24; // [rsp+30h] [rbp-B8h]
  int v25; // [rsp+40h] [rbp-A8h]
  int v26; // [rsp+84h] [rbp-64h]
  unsigned long long v27; // [rsp+A8h] [rbp-40h]

  v7 = *a1;
  v27 = __readfsqword(0x28u);
  v8 = a2[1];
  v9 = *(unsigned int **)(v7 + 32);
  if ( v9[19] )
  {
    v10 = v8;
    if ( v8 < v9[21] )
    {
LABEL_10:
      *(long long *)(a3 + 80) = v10;
      return 65667;
    }
  }
  else
  {
    v10 = v8;
    if ( v8 < 0xB )
      goto LABEL_10;
  }
  if ( v8 > *v9 )
    goto LABEL_10;
  e2fsck_read_inode(a1, v10, v23, "pass1");
  v11 = ext2fs_ext_attr_hash_entry2(*a1, a2, 0, &v22);
  if ( v11 )
  {
    v21 = a2[1];
    v16 = (unsigned int)dcgettext(0, "while hashing entry with e_value_inum = %u", 5);
    com_err((unsigned int)"check_large_ea_inode", v11, v16, v21, v17, v18);
    fatal_error(a1, 0);
  }
  v12 = (unsigned int)a2[3];
  if ( (int)v12 == v22 )
  {
    v15 = sub_1F5E0(*(unsigned int *)(*a1 + 40LL), *(unsigned int *)(*a1 + 192LL), (unsigned int)a2[2]);
  }
  else
  {
    if ( v24 != *(int *)(a3 + 8) || v26 != *(int *)(*(long long *)(a3 + 24) + 100LL) )
    {
      if ( (v25 & 0x200000) != 0 )
      {
        *(long long *)(a3 + 80) = v12;
        return 65620;
      }
      else
      {
        v13 = 65667;
        *(long long *)(a3 + 80) = (unsigned int)a2[1];
      }
      return v13;
    }
    v15 = 0;
  }
  *a4 = v15;
  v13 = v25 & 0x200000;
  if ( (v25 & 0x200000) != 0 )
  {
    return 0;
  }
  else
  {
    *(long long *)(a3 + 80) = (unsigned int)a2[1];
    if ( (unsigned int)fix_problem(a1, 65670, a3) )
    {
      v19 = (unsigned int)a2[1];
      v20 = *a1;
      v25 |= 0x200000u;
      ext2fs_write_inode(v20, v19, v23);
    }
    else
    {
      return 65669;
    }
  }
  return v13;
}


// Function: check_ea_in_inode @ 0x1f800
void check_ea_in_inode(long long a1, long long a2, long long *a3)
{
  long long v5; // rcx
  long long v6; // rax
  int v7; // edx
  long long v8; // rsi
  int v9; // ebx
  long long v10; // rax
  long long v11; // rbp
  unsigned int v12; // ebx
  unsigned char *v13; // r13
  unsigned int v14; // edx
  int v15; // eax
  unsigned int v16; // edx
  long long v17; // rsi
  unsigned int v18; // ebx
  long long v19; // rdx
  unsigned int v20; // eax
  int v21; // eax
  long long v22; // rax
  unsigned int v23; // eax
  long long v24; // rcx
  unsigned char *v25; // [rsp+8h] [rbp-70h]
  unsigned char *v26; // [rsp+10h] [rbp-68h]
  unsigned int v27; // [rsp+18h] [rbp-60h]
  long long v28; // [rsp+20h] [rbp-58h]
  long long v29; // [rsp+28h] [rbp-50h]
  long long v30[9]; // [rsp+30h] [rbp-48h] BYREF

  v5 = *(long long *)(a2 + 24);
  v30[1] = __readfsqword(0x28u);
  v6 = *(long long *)(*(long long *)a1 + 32LL);
  *a3 = 0;
  a3[1] = 0;
  v7 = 0;
  v29 = v6;
  if ( *(int *)(v6 + 76) )
    v7 = *(unsigned short *)(v6 + 88) - 128;
  v8 = *(unsigned short *)(v5 + 128);
  v9 = v7 - v8;
  v25 = (unsigned char *)(v5 + v8 + 128);
  v28 = (unsigned int)(v7 - v8);
  v26 = (unsigned char *)(v5 + v8 + 132);
  v10 = region_create(0);
  v11 = v10;
  if ( v10 )
  {
    if ( (unsigned int)region_allocate(v10, 0, 4) )
    {
      region_free(v11);
      v23 = 65641;
    }
    else
    {
      v12 = v9 - 4;
      if ( v12 <= 0xF )
      {
        v17 = 4;
      }
      else
      {
        v13 = v26;
        while ( 1 )
        {
          v17 = v13 - v25;
          if ( !*(int *)v13 )
            break;
          if ( (unsigned int)region_allocate(v11, v17, (*v13 + 19) & 0xFFFFFFFC) )
            goto LABEL_31;
          v18 = v12 - 16;
          v19 = *v13;
          v20 = (v19 + 3) & 0xFFFFFFFC;
          if ( v20 > v18 )
          {
            *(long long *)(a2 + 80) = v19;
            region_free(v11);
            v23 = 65616;
            goto LABEL_22;
          }
          v12 = v18 - v20;
          if ( *((int *)v13 + 1) )
          {
            v21 = sub_1F600((long long *)a1, v13, a2, v30);
            if ( v21 )
              goto LABEL_32;
            v22 = v30[0];
            ++a3[1];
            *a3 += v22;
          }
          else
          {
            v14 = *((int *)v13 + 2);
            if ( v14 > v12 )
            {
              *(long long *)(a2 + 80) = v14;
              region_free(v11);
              v23 = 65619;
              goto LABEL_22;
            }
            if ( v14 && (unsigned int)region_allocate(v11, *((unsigned short *)v13 + 1) + 4LL, (v14 + 3) & 0xFFFFFFFC) )
            {
LABEL_31:
              v21 = 65641;
LABEL_32:
              v27 = v21;
              region_free(v11);
              v23 = v27;
              goto LABEL_22;
            }
            v15 = ext2fs_ext_attr_hash_entry(v13, &v26[*((unsigned short *)v13 + 1)]);
            v16 = *((int *)v13 + 3);
            if ( v16 && v16 != v15 )
            {
              *(long long *)(a2 + 80) = v16;
              region_free(v11);
              v23 = 65620;
              goto LABEL_22;
            }
          }
          if ( !*((int *)v13 + 1) )
            v12 -= *((int *)v13 + 2);
          v13 += (*v13 + 19) & 0x1FC;
          if ( v12 <= 0xF )
          {
            v17 = v13 - v25;
            break;
          }
        }
      }
      if ( !(unsigned int)region_allocate(v11, v17, 4) )
      {
        region_free(v11);
        goto LABEL_29;
      }
      region_free(v11);
      v23 = 65641;
    }
LABEL_22:
    if ( !(unsigned int)fix_problem(a1, v23, a2) )
    {
LABEL_29:
      sub_1ECD0(a1, (long long *)a2, v26, (unsigned long long)&v25[v28]);
      return;
    }
    v24 = 128;
    *(int *)v25 = 0;
    if ( *(int *)(v29 + 76) )
      v24 = *(unsigned short *)(v29 + 88);
    e2fsck_write_inode_full(a1, *(unsigned int *)(a2 + 8), *(long long *)(a2 + 24), v24, "pass1");
    *a3 = 0;
    a3[1] = 0;
  }
  else
  {
    fix_problem(a1, 65599, a2);
    *(int *)(a1 + 72) |= 1u;
  }
}


// Function: check_inode_extra_space @ 0x1fb80
unsigned long long check_inode_extra_space(long long *a1, long long a2, long long *a3)
{
  unsigned long long result; // rax
  long long v4; // r13
  long long v5; // r14
  int v7; // edx
  int v8; // r15d
  int v9; // edx
  int v10; // edx
  int v11; // edx
  int v12; // edx
  long long v13; // rcx
  unsigned short v14; // ax
  short v15; // ax
  int v16; // edx
  long long v17; // rcx

  result = *a1;
  v4 = *(long long *)(a2 + 24);
  v5 = *(long long *)(*a1 + 32);
  *a3 = 0;
  a3[1] = 0;
  if ( *(int *)(v5 + 76) )
  {
    v7 = *(unsigned short *)(v5 + 88);
    if ( (short)v7 != 128 )
    {
      result = *(unsigned short *)(v4 + 128);
      v8 = v7 - 128;
      if ( (short)result && ((unsigned short)result > v8 || (unsigned short)result <= 3u || (result & 3) != 0) )
      {
        result = fix_problem(a1, 65615, a2);
        if ( !(int)result )
          return result;
        v14 = *(short *)(v4 + 128);
        if ( v14 > 3u && v14 <= v8 )
          v15 = (v14 + 3) & 0xFFFC;
        else
          v15 = *(short *)(v5 + 350);
        v16 = *(int *)(v5 + 76);
        *(short *)(v4 + 128) = v15;
        v17 = 128;
        if ( v16 )
          v17 = *(unsigned short *)(v5 + 88);
        e2fsck_write_inode_full(a1, *(unsigned int *)(a2 + 8), *(long long *)(a2 + 24), v17, "pass1");
        result = *(unsigned short *)(v4 + 128);
      }
      if ( result < v8 - 4LL )
      {
        if ( *(int *)(v4 + result + 128) == -368967680 )
          sub_1F800((long long)a1, a2, a3);
        result = 0x1FFFFFFFFLL;
        if ( a1[105] <= 0x1FFFFFFFFLL )
        {
          if ( sub_1E170(*(int *)(v4 + 8), *(int *)(v4 + 140))
            || sub_1E170(*(int *)(v4 + 12), *(int *)(v4 + 132))
            || sub_1E170(*(int *)(v4 + 144), *(int *)(v4 + 148))
            || (result = sub_1E170(*(int *)(v4 + 16), *(int *)(v4 + 136)), (int)result) )
          {
            result = fix_problem(a1, 65666, a2);
            if ( (int)result )
            {
              if ( sub_1E170(*(int *)(v4 + 8), *(int *)(v4 + 140)) )
                *(int *)(v4 + 140) = v9 & 0xFFFFFFFC;
              if ( sub_1E170(*(int *)(v4 + 12), *(int *)(v4 + 132)) )
                *(int *)(v4 + 132) = v10 & 0xFFFFFFFC;
              if ( sub_1E170(*(int *)(v4 + 144), *(int *)(v4 + 148)) )
                *(int *)(v4 + 148) = v11 & 0xFFFFFFFC;
              if ( sub_1E170(*(int *)(v4 + 16), *(int *)(v4 + 136)) )
                *(int *)(v4 + 136) = v12 & 0xFFFFFFFC;
              v13 = 128;
              if ( *(int *)(v5 + 76) )
                v13 = *(unsigned short *)(v5 + 88);
              return e2fsck_write_inode_full(a1, *(unsigned int *)(a2 + 8), *(long long *)(a2 + 24), v13, "pass1");
            }
          }
        }
      }
    }
  }
  return result;
}


// Function: new_table_block @ 0x1fe80
unsigned long long new_table_block(long long *a1, long long a2, long long a3, long long a4, unsigned int a5, long long *a6)
{
  unsigned int v6; // r14d
  long long v9; // rbp
  long long v10; // r13
  long long v11; // rdx
  long long v12; // rdi
  long long v13; // rdx
  unsigned int v14; // eax
  long long v15; // rsi
  long long v16; // rax
  long long free_blocks2; // rax
  long long v18; // rax
  long long v19; // r14
  long long v20; // rdx
  long long v21; // r8
  long long v22; // rcx
  long long v23; // rdi
  long long v24; // rsi
  long long v25; // rdi
  long long v26; // rsi
  long long block2; // rax
  long long v29; // r14
  long long v30; // rax
  long long v32; // [rsp+8h] [rbp-D0h]
  long long v34; // [rsp+10h] [rbp-C8h]
  char v35; // [rsp+18h] [rbp-C0h]
  long long v36; // [rsp+28h] [rbp-B0h] BYREF
  long long v37[5]; // [rsp+30h] [rbp-A8h] BYREF
  long long v38; // [rsp+58h] [rbp-80h]
  long long v39; // [rsp+60h] [rbp-78h]
  unsigned int v40; // [rsp+70h] [rbp-68h]
  long long v41; // [rsp+80h] [rbp-58h]
  long long v42; // [rsp+90h] [rbp-48h]
  unsigned long long v43; // [rsp+98h] [rbp-40h]

  v6 = a3;
  v9 = *a1;
  v10 = *a6;
  v43 = __readfsqword(0x28u);
  clear_problem_context(v37, a2, a3);
  v11 = *(long long *)(v9 + 32);
  v40 = v6;
  v38 = v10;
  v12 = *(unsigned int *)(v11 + 96);
  v42 = a4;
  if ( !(unsigned int)sub_1FE70(v12) )
  {
    block2 = ext2fs_group_last_block2(v9, v6);
    v37[0] = ext2fs_get_free_blocks2(v9, a2, block2, a5, a1[52], a6);
    if ( !v37[0] )
      goto LABEL_7;
LABEL_22:
    v26 = 65566;
    v41 = (int)a5;
    goto LABEL_19;
  }
  v35 = *(char *)(v13 + 372);
  v34 = ext2fs_group_first_block2(v9, v6 >> v35 << v35);
  v14 = *(int *)(v9 + 48);
  v15 = v6 | ((1 << v35) - 1);
  if ( v14 <= (unsigned int)v15 )
    v15 = v14 - 1;
  v16 = ext2fs_group_last_block2(v9, v15);
  free_blocks2 = ext2fs_get_free_blocks2(v9, v34, v16, a5, a1[52], a6);
  v37[0] = free_blocks2;
  if ( free_blocks2 == 2133571400 )
  {
    v29 = a1[52];
    v30 = ext2fs_blocks_count(*(long long *)(v9 + 32));
    free_blocks2 = ext2fs_get_free_blocks2(v9, *(unsigned int *)(*(long long *)(v9 + 32) + 20LL), v30, a5, v29, a6);
    v37[0] = free_blocks2;
  }
  if ( free_blocks2 )
    goto LABEL_22;
LABEL_7:
  v37[0] = ext2fs_get_mem(*(unsigned int *)(v9 + 40), &v36);
  if ( v37[0] )
  {
    v26 = 65567;
LABEL_19:
    fix_problem(a1, v26, v37);
    ext2fs_unmark_valid(v9);
    *((int *)a1 + 18) |= 1u;
    return v43 - __readfsqword(0x28u);
  }
  ext2fs_mark_super_dirty(v9);
  v18 = *a6;
  *(int *)(v9 + 16) &= ~0x200u;
  v39 = v18;
  v19 = 0;
  fix_problem(a1, (unsigned int)(v10 == 0) + 65568, v37);
  v22 = (int)a5;
  v39 = 0;
  v32 = v22;
  if ( (int)v22 > 0 )
  {
    do
    {
      while ( 1 )
      {
        v24 = *a6;
        v25 = a1[52];
        v38 = v19;
        ext2fs_mark_block_bitmap2(v25, v19 + v24, v20, v22, v21);
        if ( !v10 )
          break;
        v37[0] = io_channel_read_blk64(*(long long *)(v9 + 8), v10 + v19, 1, v36);
        if ( v37[0] )
          fix_problem(a1, 65570, v37);
        v23 = *(long long *)(v9 + 8);
        v38 = v19 + *a6;
        v37[0] = io_channel_write_blk64(v23, v38, 1, v36);
        if ( v37[0] )
          goto LABEL_16;
LABEL_13:
        if ( v32 == ++v19 )
          goto LABEL_17;
      }
      v38 = v19 + *a6;
      v37[0] = ext2fs_zero_blocks2(v9, v38, 1, 0, 0);
      if ( !v37[0] )
        goto LABEL_13;
LABEL_16:
      ++v19;
      fix_problem(a1, 65571, v37);
    }
    while ( v32 != v19 );
  }
LABEL_17:
  ext2fs_free_mem(&v36);
  return v43 - __readfsqword(0x28u);
}


// Function: handle_fs_bad_blocks @ 0x201c0
unsigned long long handle_fs_bad_blocks(long long a1)
{
  long long v1; // rbp
  unsigned int i; // ebx
  long long block2; // r12
  char *v4; // rax
  char *v5; // rax
  long long v6; // rax
  unsigned int v7; // r8d
  char *v8; // rax
  long long v9; // rsi
  unsigned int v11; // [rsp+Ch] [rbp-4Ch]
  long long v12; // [rsp+10h] [rbp-48h] BYREF
  unsigned long long v13; // [rsp+18h] [rbp-40h]

  v1 = *(long long *)a1;
  v13 = __readfsqword(0x28u);
  if ( *(int *)(v1 + 48) )
  {
    for ( i = 0; *(int *)(v1 + 48) > i; ++i )
    {
      while ( 1 )
      {
        block2 = ext2fs_group_first_block2(v1, i);
        if ( *(int *)(*(long long *)(a1 + 504) + 4LL * i) )
          break;
        if ( *(int *)(*(long long *)(a1 + 496) + 4LL * i) )
          goto LABEL_8;
LABEL_4:
        if ( !*(int *)(*(long long *)(a1 + 512) + 4LL * i) )
          goto LABEL_5;
LABEL_9:
        v6 = ext2fs_inode_table_loc(v1, i);
        v7 = *(int *)(v1 + 72);
        v12 = v6;
        v11 = v7;
        v8 = dcgettext(0, "inode table", 5);
        sub_1FE80((long long *)a1, block2, i, (long long)v8, v11, &v12);
        v9 = i++;
        ext2fs_inode_table_loc_set(v1, v9, v12);
        *(int *)(a1 + 72) |= 4u;
        if ( *(int *)(v1 + 48) <= i )
          goto LABEL_10;
      }
      v12 = ext2fs_block_bitmap_loc(v1, i);
      v4 = dcgettext(0, "block bitmap", 5);
      sub_1FE80((long long *)a1, block2, i, (long long)v4, 1u, &v12);
      ext2fs_block_bitmap_loc_set(v1, i, v12);
      if ( !*(int *)(*(long long *)(a1 + 496) + 4LL * i) )
        goto LABEL_4;
LABEL_8:
      v12 = ext2fs_inode_bitmap_loc(v1, i);
      v5 = dcgettext(0, "inode bitmap", 5);
      sub_1FE80((long long *)a1, block2, i, (long long)v5, 1u, &v12);
      ext2fs_inode_bitmap_loc_set(v1, i, v12);
      if ( *(int *)(*(long long *)(a1 + 512) + 4LL * i) )
        goto LABEL_9;
LABEL_5:
      ;
    }
  }
LABEL_10:
  *(int *)(a1 + 520) = 0;
  return v13 - __readfsqword(0x28u);
}


// Function: check_is_really_dir @ 0x203d0
unsigned long long check_is_really_dir(long long *a1, long long a2, long long a3)
{
  long long v4; // r12
  long long v6; // rdi
  unsigned int v7; // eax
  long long v8; // rdx
  unsigned int v9; // edx
  int v10; // ecx
  long long v11; // r10
  long long v12; // rdi
  long long v13; // rax
  long long v14; // rdx
  unsigned long long v16; // r15
  int v17; // r13d
  long long v18; // rdi
  char *v19; // rax
  long long dir_block4; // r13
  long long v21; // r14
  long long v22; // rcx
  short v23; // ax
  long long v24; // rax
  unsigned int v25; // r13d
  unsigned int v26; // eax
  long long v27; // r8
  long long v28; // rax
  unsigned int *v29; // rax
  unsigned int v30; // ecx
  unsigned int v31; // [rsp+4h] [rbp-154h] BYREF
  unsigned long long v32; // [rsp+8h] [rbp-150h] BYREF
  unsigned int v33[66]; // [rsp+10h] [rbp-148h] BYREF
  unsigned long long v34; // [rsp+118h] [rbp-40h]

  v4 = *(long long *)(a2 + 24);
  v34 = __readfsqword(0x28u);
  if ( (*(short *)v4 & 0xF000) == 0x4000 || (*(short *)v4 & 0xD000) == 0x8000 || !*(int *)(v4 + 40) )
    return v34 - __readfsqword(0x28u);
  v6 = *(unsigned int *)(*(long long *)(*a1 + 32LL) + 96LL);
  v7 = sub_203C0(v6);
  if ( (unsigned int)sub_1FE30(v6, a2, v8, v7) && (*(char *)(v4 + 35) & 0x10) != 0 )
  {
    v12 = v11;
    v13 = ext2fs_inline_data_size(v11, *(unsigned int *)(a2 + 8), &v32);
    if ( !(v13 | v32 & 3) )
    {
      v25 = *(int *)(v4 + 40);
      v26 = sub_1F560(v12, v4 + 44, v14, 264, v33);
      v28 = __memcpy_chk(v27, v4 + 44, v26);
      ext2fs_get_rec_len(*a1, v28, &v31);
      v29 = *(unsigned int **)(*a1 + 32LL);
      if ( *v29 > v25 )
      {
        v30 = 11;
        if ( v29[19] )
          v30 = v29[21];
        if ( (v25 == 2 || v30 <= v25) && *v29 > v33[0] && (v33[0] >= v30 || !v33[0]) && v31 <= 0x38 )
        {
LABEL_32:
          if ( (unsigned int)fix_problem(a1, 65621, a2) )
          {
            v22 = 128;
            v23 = *(short *)v4 & 0xFFF;
            HIBYTE(v23) |= 0x40u;
            *(short *)v4 = v23;
            v24 = *(long long *)(*a1 + 32LL);
            if ( *(int *)(v24 + 76) )
              v22 = *(unsigned short *)(v24 + 88);
            e2fsck_write_inode_full(a1, *(unsigned int *)(a2 + 8), v4, v22, "check_is_really_dir");
          }
        }
      }
    }
  }
  else
  {
    v16 = 0;
    if ( v10 )
    {
      v17 = *(int *)(v4 + 32) & 0x80000;
      if ( !v17 )
        goto LABEL_11;
      if ( !ext2fs_bmap2(v11, *(int *)(a2 + 8), v4, 0, 0, 0, 0, (long long)&v32) )
      {
LABEL_19:
        v19 = dcgettext(0, "reading directory block", 5);
        ehandler_operation(v19);
        dir_block4 = ext2fs_read_dir_block4(*a1, v32, a3, 0, *(unsigned int *)(a2 + 8));
        ehandler_operation(0);
        if ( dir_block4 )
          return v34 - __readfsqword(0x28u);
        if ( ext2fs_get_rec_len(*a1, a3, &v31) )
          return v34 - __readfsqword(0x28u);
        if ( (unsigned int)ext2fs_dirent_name_len(a3) != 1 )
          return v34 - __readfsqword(0x28u);
        if ( *(char *)(a3 + 8) != 46 )
          return v34 - __readfsqword(0x28u);
        if ( *(int *)a3 != *(int *)(a2 + 8) )
          return v34 - __readfsqword(0x28u);
        if ( v31 <= 0xB )
          return v34 - __readfsqword(0x28u);
        if ( (v31 & 3) != 0 )
          return v34 - __readfsqword(0x28u);
        if ( v31 >= *(int *)(*a1 + 40LL) - 12 )
          return v34 - __readfsqword(0x28u);
        v21 = v31 + a3;
        if ( ext2fs_get_rec_len(*a1, v21, &v31)
          || (unsigned int)ext2fs_dirent_name_len(v21) != 2
          || *(short *)(v21 + 8) != 11822
          || v31 <= 0xB
          || (v31 & 3) != 0 )
        {
          return v34 - __readfsqword(0x28u);
        }
        goto LABEL_32;
      }
    }
    else
    {
      v17 = 0;
LABEL_11:
      while ( 1 )
      {
        v32 = v9;
        if ( v9 )
        {
          v17 -= (v16 < 4) - 1;
          v18 = *(long long *)(*a1 + 32LL);
          if ( v9 < (unsigned long long)*(unsigned int *)(v18 + 20)
            || ext2fs_blocks_count(v18) <= v32
            || (unsigned int)ext2fs_fast_test_block_bitmap2(a1[52]) )
          {
            break;
          }
        }
        if ( ++v16 == 15 )
        {
          v32 = *(unsigned int *)(v4 + 40);
          if ( (*(short *)v4 & 0xB000) == 0x2000 && *(short *)(v4 + 26) == 1 && !v17 )
            return v34 - __readfsqword(0x28u);
          goto LABEL_19;
        }
        v9 = *(int *)(v4 + 4 * v16 + 40);
      }
    }
  }
  return v34 - __readfsqword(0x28u);
}


// Function: mark_block_used @ 0x20780
unsigned long long mark_block_used(long long a1, long long a2, long long a3)
{
  long long v4; // rdi
  char *v6; // rax
  long long v7[13]; // [rsp+0h] [rbp-88h] BYREF
  unsigned long long v8; // [rsp+68h] [rbp-20h]

  v8 = __readfsqword(0x28u);
  clear_problem_context(v7, a2, a3);
  if ( !(unsigned int)ext2fs_fast_test_block_bitmap2(*(long long *)(a1 + 416)) )
  {
    v4 = *(long long *)(a1 + 416);
LABEL_5:
    ext2fs_fast_mark_block_bitmap2(v4, a2);
    return v8 - __readfsqword(0x28u);
  }
  if ( !(unsigned int)sub_20770(*(unsigned int *)(*(long long *)(*(long long *)a1 + 32LL) + 100LL))
    || (*(char *)(a1 + 78) & 4) != 0 )
  {
    v4 = *(long long *)(a1 + 424);
    if ( !v4 )
    {
      v6 = dcgettext(0, "multiply claimed block map", 5);
      v7[0] = e2fsck_allocate_block_bitmap(*(long long *)a1, v6);
      if ( v7[0] )
      {
        v7[10] = 3;
        fix_problem(a1, 65573, v7);
        *(int *)(a1 + 72) |= 1u;
        return v8 - __readfsqword(0x28u);
      }
      v4 = *(long long *)(a1 + 424);
    }
    goto LABEL_5;
  }
  return v8 - __readfsqword(0x28u);
}


// Function: process_bad_block @ 0x20890
long long process_bad_block(long long a1, unsigned long long *a2, long long a3, long long a4, long long a5, long long a6)
{
  unsigned long long v6; // rbp
  long long v8; // rdi
  long long v10; // r12
  unsigned long long v12; // rax
  unsigned int v13; // r14d
  long long v15; // rdx
  long long v16; // rcx
  long long v17; // r8
  unsigned long long v18; // r14
  unsigned int v19; // r15d
  long long v20; // rdx
  int *v21; // rax
  long long v22; // [rsp+0h] [rbp-48h]

  v6 = *a2;
  if ( !*a2 )
    return 0;
  v8 = *(long long *)(a1 + 32);
  v10 = *(long long *)(a6 + 72);
  v22 = *(long long *)(a6 + 88);
  v12 = *(unsigned int *)(v8 + 20);
  *(int *)(v10 + 8) = 1;
  *(long long *)(v10 + 40) = v6;
  *(long long *)(v10 + 56) = a3;
  if ( v12 > v6 || ext2fs_blocks_count(v8) <= v6 )
  {
    if ( (unsigned int)fix_problem(v22, 65554, v10) )
      goto LABEL_4;
    return 0;
  }
  if ( a3 >= 0 )
  {
    ++*(int *)(v22 + 772);
    v13 = ext2fs_test_block_bitmap2(*(long long *)(v22 + 416), v6);
    if ( !v13 )
    {
      ext2fs_mark_block_bitmap2(*(long long *)(v22 + 416), v6, v15, v16, v17);
      return v13;
    }
    v18 = *(unsigned int *)(*(long long *)(a1 + 32) + 20LL);
    if ( *(int *)(a1 + 48) )
    {
      v19 = 0;
      while ( 1 )
      {
        *(int *)(v10 + 64) = v19;
        *(long long *)(v10 + 40) = v6;
        if ( (unsigned int)ext2fs_bg_has_super(a1, v19) )
        {
          if ( v6 == v18 )
          {
            if ( v19 )
            {
              v13 = 0;
              fix_problem(v22, 65563, v10);
              return v13;
            }
            if ( (unsigned int)fix_problem(v22, 65561, v10) )
              goto LABEL_4;
            return 0;
          }
          if ( v6 > v18 && v18 + *(long long *)(a1 + 56) >= v6 )
            break;
        }
        if ( ext2fs_block_bitmap_loc(a1, v19) == v6 )
        {
          if ( !(unsigned int)fix_problem(v22, 65546, v10) )
            return 0;
          v13 = 0;
          ++*(int *)(*(long long *)(v22 + 504) + 4LL * v19);
          ++*(int *)(v22 + 520);
          return v13;
        }
        if ( ext2fs_inode_bitmap_loc(a1, v19) == v6 )
        {
          if ( !(unsigned int)fix_problem(v22, 65547, v10) )
            return 0;
          v13 = 0;
          ++*(int *)(*(long long *)(v22 + 496) + 4LL * v19);
          ++*(int *)(v22 + 520);
          return v13;
        }
        if ( ext2fs_inode_table_loc(a1, v19) <= v6
          && ext2fs_inode_table_loc(a1, v19) + (unsigned long long)*(unsigned int *)(a1 + 72) > v6 )
        {
          return 0;
        }
        ++v19;
        v18 += *(unsigned int *)(*(long long *)(a1 + 32) + 32LL);
        if ( *(int *)(a1 + 48) <= v19 )
          goto LABEL_28;
      }
      if ( v19 )
      {
        v13 = 0;
        fix_problem(v22, 65564, v10);
        return v13;
      }
      *(long long *)(v10 + 40) = *a2;
      if ( (unsigned int)fix_problem(v22, 65562, v10) )
        goto LABEL_4;
      return 0;
    }
LABEL_28:
    v21 = *(int **)(a6 + 64);
    if ( v21[22] != v6 && v21[23] != v6 && v21[24] != v6 )
    {
      *(int *)(v10 + 64) = -1;
      fix_problem(v22, 65565, v10);
      return 0;
    }
    *(char *)(a6 + 4) |= 0x40u;
    if ( !(unsigned int)fix_problem(v22, 65557, v10) )
      return 2 * (unsigned int)((*(char *)(v22 + 72) & 3) != 0);
    goto LABEL_4;
  }
  if ( !(unsigned int)ext2fs_test_block_bitmap2(*(long long *)(a6 + 80), v6) )
  {
    v13 = ext2fs_test_block_bitmap2(*(long long *)(v22 + 416), v6);
    if ( !v13 )
    {
      sub_20780(v22, v6, v20);
      return v13;
    }
    *(char *)(a6 + 4) |= 0x40u;
    if ( !(unsigned int)fix_problem(v22, 65557, v10) )
      return 2 * (unsigned int)((*(char *)(v22 + 72) & 3) != 0);
    goto LABEL_4;
  }
  *(char *)(a6 + 4) |= 0x40u;
  if ( !(unsigned int)fix_problem(v22, 65613, v10) )
    return 0;
LABEL_4:
  v13 = 1;
  *a2 = 0;
  return v13;
}


// Function: process_block @ 0x20c70
long long process_block(long long a1, unsigned long long *a2, long long a3, long long a4, long long a5, unsigned int *a6)
{
  long long v9; // rdx
  unsigned long long v10; // r14
  long long v11; // r13
  long long v12; // r15
  char v13; // al
  long long v14; // r8
  long long v15; // r8
  int v16; // ecx
  char *v17; // rax
  long long v18; // r11
  int v19; // r8d
  unsigned long long v20; // rax
  unsigned long long v21; // rdx
  unsigned int v22; // r8d
  int v23; // eax
  long long v24; // rdi
  int v25; // ecx
  unsigned long long v26; // rsi
  unsigned int v27; // r12d
  long long v29; // rsi
  int v30; // eax
  long long v31; // rax
  long long v32; // rsi
  long long v33; // rcx
  long long v34; // rdi
  long long v35; // rax
  long long v36; // rax
  int fixed; // eax
  int v38; // eax
  long long v39; // rdx
  long long v40; // rdx
  int v41; // eax
  unsigned int v44; // [rsp+10h] [rbp-58h]
  unsigned int v45; // [rsp+10h] [rbp-58h]
  unsigned int v46; // [rsp+10h] [rbp-58h]
  long long v47; // [rsp+18h] [rbp-50h]
  unsigned int v48; // [rsp+18h] [rbp-50h]
  unsigned int v49; // [rsp+18h] [rbp-50h]
  long long v50; // [rsp+20h] [rbp-48h]
  unsigned int v51; // [rsp+2Ch] [rbp-3Ch]

  v9 = *((unsigned char *)a6 + 4);
  v10 = *a2;
  v11 = *((long long *)a6 + 9);
  v12 = *((long long *)a6 + 11);
  v13 = v9 & 1;
  if ( (v9 & 1) == 0 || a3 | v10 )
  {
    if ( !v10 )
      return 0;
    v14 = *((long long *)a6 + 7);
    if ( v14 )
    {
      if ( *a6 != 7 )
      {
        v15 = v14 + 1;
        if ( v15 != v10 )
        {
          if ( (*(char *)(v12 + 77) & 8) != 0 )
          {
            v16 = 100;
            if ( !v13 )
              v16 = (v9 & 2) == 0 ? 63 : 102;
            v51 = v16;
            v50 = v15;
            v47 = *(unsigned int *)(v11 + 8);
            v17 = dcgettext(0, "%6lu(%c): expecting %6lu got phys %6lu (blkcnt %lld)\n", 5);
            __printf_chk(1, v17, v47, v51, v50, v10, a3);
          }
          v9 = *((unsigned char *)a6 + 4) | 0x10u;
          *((char *)a6 + 4) |= 0x10u;
          v13 = v9 & 1;
        }
      }
    }
    v18 = *(long long *)(a1 + 32);
    if ( v13 )
    {
      if ( !(unsigned int)sub_1FE40(*(unsigned int *)(v18 + 96), a1, v9, a4, 0) )
      {
        v19 = *(int *)(*(long long *)(v11 + 24) + 108LL);
        if ( v19 )
        {
          v19 = 0;
        }
        else if ( 1 << (21 - *(char *)(v18 + 24)) < a3 )
        {
          v19 = 65604;
        }
      }
      if ( (unsigned long long)(*((long long *)a6 + 1) + 1LL) < *((long long *)a6 + 2) )
      {
LABEL_17:
        v20 = *(unsigned int *)(v18 + 20);
        if ( (v9 & 3) != 0 || a3 <= 0 )
        {
          if ( v20 > v10 )
          {
LABEL_40:
            v23 = *a6;
            if ( a3 >= 0 )
              goto LABEL_78;
            if ( v23 == 7 )
            {
              v22 = 65550;
              goto LABEL_48;
            }
            if ( v10 >= *(unsigned int *)(*(long long *)(*(long long *)v12 + 32LL) + 4LL) )
            {
LABEL_78:
              v22 = 65550;
              goto LABEL_55;
            }
            if ( (unsigned int)ext2fs_test_block_bitmap2(*(long long *)(v12 + 912), v10) )
            {
              v22 = 65550;
              goto LABEL_45;
            }
LABEL_54:
            v23 = *a6;
            v22 = 65550;
            goto LABEL_55;
          }
        }
        else
        {
          v19 = 65606;
          if ( v10 < v20 )
            goto LABEL_54;
        }
        v48 = v19;
        if ( ext2fs_blocks_count(v18) > v10 )
        {
          v22 = v48;
          if ( a3 >= 0 )
            goto LABEL_22;
          v23 = *a6;
          if ( *a6 != 7 )
          {
            v24 = *(long long *)v12;
            v21 = *(unsigned int *)(*(long long *)(*(long long *)v12 + 32LL) + 4LL);
            if ( v21 <= v10 )
            {
              if ( !v48 )
                goto LABEL_25;
              goto LABEL_55;
            }
            v41 = ext2fs_test_block_bitmap2(*(long long *)(v12 + 912), v10);
            v22 = v48;
            if ( !v41 )
            {
LABEL_22:
              v23 = *a6;
              if ( !v22 )
              {
                if ( v23 != 7 )
                {
                  v24 = *(long long *)v12;
LABEL_25:
                  v25 = *(int *)(v24 + 192);
                  if ( v25 )
                  {
                    v26 = *((long long *)a6 + 7);
                    if ( v26 )
                    {
                      v21 = v10 >> v25;
                      if ( v10 >> v25 == v26 >> v25 )
                      {
                        v38 = (1 << v25) - 1;
                        v21 = v10 & v38;
                        if ( v21 == ((unsigned int)a3 & v38) )
                        {
                          if ( (unsigned int)sub_1F570(v24, v26, *((long long *)a6 + 3), v10, a3) )
                          {
                            *(long long *)(v11 + 40) = a3;
                            *(long long *)(v11 + 48) = v10;
                            fix_problem(v12, 65652, v11);
                            sub_20780(v12, v10, v39);
                            sub_20780(v12, v10, v40);
                          }
                          goto LABEL_30;
                        }
                      }
                    }
                  }
LABEL_28:
                  sub_20780(v12, v10, v21);
LABEL_29:
                  ++*((long long *)a6 + 1);
LABEL_30:
                  if ( a3 >= 0 )
                    *((long long *)a6 + 3) = a3;
                  *((long long *)a6 + 7) = v10;
                  v27 = 0;
LABEL_60:
                  if ( a3 >= 0 && (a6[1] & 1) != 0 )
                  {
                    while ( 1 )
                    {
                      v32 = *a6;
                      v33 = *((long long *)a6 + 5) + 1LL;
                      *((long long *)a6 + 5) = v33;
                      v34 = *(long long *)(a1 + 144);
                      if ( v33 >= a3 )
                        break;
                      v31 = ext2fs_add_dir_block2(v34, v32, 0, v33);
                      *(long long *)v11 = v31;
                      if ( v31 )
                      {
                        *(long long *)(v11 + 40) = 0;
                        a3 = *((long long *)a6 + 5);
                        goto LABEL_77;
                      }
                    }
                    v35 = ext2fs_add_dir_block2(v34, v32, v10, a3);
                    *(long long *)v11 = v35;
                    if ( !v35 )
                      return v27;
                    *(long long *)(v11 + 40) = v10;
                    goto LABEL_77;
                  }
                  return v27;
                }
LABEL_73:
                if ( a3 != -2 )
                  goto LABEL_29;
                goto LABEL_28;
              }
LABEL_55:
              v29 = a4;
              ++a6[12];
              if ( a4 )
              {
                if ( v23 != 7 )
                {
                  v45 = v22;
                  v30 = ext2fs_test_block_bitmap2(*(long long *)(v12 + 912), v29);
                  v22 = v45;
                  if ( v30 )
                  {
                    *a2 = 0;
                    return 0;
                  }
                }
              }
              goto LABEL_49;
            }
LABEL_45:
            *(long long *)(v11 + 40) = v10;
            v49 = v22;
            fix_problem(v12, 65649, v11);
            v22 = v49;
            if ( (*(char *)(v12 + 76) & 8) == 0 )
              *(int *)(v12 + 72) |= 8u;
            goto LABEL_22;
          }
          if ( !v48 )
            goto LABEL_73;
LABEL_48:
          ++a6[12];
LABEL_49:
          if ( (a6[1] & 8) == 0 && __ROR4__(-1431655765 * a6[12] + 715827880, 2) <= 0x15555554u )
          {
            v46 = v22;
            if ( (unsigned int)fix_problem(v12, 65553, v11) )
            {
              *((char *)a6 + 4) |= 4u;
              return 2;
            }
            fixed = fix_problem(v12, 65581, v11);
            v22 = v46;
            if ( fixed )
            {
              *((char *)a6 + 4) |= 8u;
              set_latch_flags(16, 8, 0);
              v22 = v46;
            }
          }
          *(long long *)(v11 + 40) = v10;
          *(long long *)(v11 + 56) = a3;
          v44 = v22;
          if ( (unsigned int)fix_problem(v12, v22, v11) )
          {
            *a2 = 0;
            v10 = 0;
            v27 = 1;
            *((char *)a6 + 4) |= 0x80u;
            if ( v44 == 65604 )
              return v27;
            goto LABEL_60;
          }
          return 0;
        }
        goto LABEL_40;
      }
      v19 = 65604;
    }
    else
    {
      v19 = 0;
    }
    if ( (v9 & 2) != 0 && (unsigned long long)(*((long long *)a6 + 1) + 1LL) >= *((long long *)a6 + 2) )
      v19 = 65605;
    goto LABEL_17;
  }
  v36 = ext2fs_add_dir_block2(*(long long *)(a1 + 144), *a6, 0, 0);
  *(long long *)v11 = v36;
  if ( v36 )
  {
    *(long long *)(v11 + 40) = 0;
    a3 = 0;
LABEL_77:
    *(long long *)(v11 + 80) = a3;
    v27 = 2;
    fix_problem(v12, 65579, v11);
    *(int *)(v12 + 72) |= 1u;
    return v27;
  }
  ++*((long long *)a6 + 5);
  return 0;
}


// Function: mark_blocks_used @ 0x21240
long long mark_blocks_used(long long *a1, long long a2, unsigned int a3)
{
  long long result; // rax
  long long v5; // rdx
  long long v6; // rcx
  long long v7; // r8
  unsigned int i; // ebx

  result = ext2fs_test_block_bitmap_range2(a1[52]);
  if ( (int)result )
    return ext2fs_mark_block_bitmap_range2(a1[52], a2, a3, v6, v7);
  for ( i = 0; a3 > i; i += result )
  {
    sub_20780((long long)a1, a2 + i, v5);
    result = (unsigned int)(1 << *(int *)(*a1 + 192LL));
  }
  return result;
}


// Function: scan_extent_node @ 0x212c0
unsigned long long scan_extent_node(
        char *a1,
        long long *a2,
        unsigned int *a3,
        unsigned long long a4,
        unsigned long long a5,
        unsigned long long a6,
        long long a7,
        int a8)
{
  long long v11; // rbx
  long long info; // rax
  long long v13; // rax
  int v14; // eax
  unsigned long long v15; // rsi
  long long v16; // rdx
  char v17; // r8
  short v18; // ax
  unsigned long long v19; // r13
  long long v20; // r8
  short v21; // ax
  long long v22; // rcx
  unsigned char v23; // r10
  Elf64_Rela *v24; // rsi
  unsigned long long v25; // r13
  long long v26; // rbx
  long long v27; // rax
  long long v28; // rax
  long long v29; // rax
  long long v30; // rax
  long long v31; // rdi
  unsigned long long v32; // rax
  int v33; // r8d
  long long v34; // rax
  unsigned long long v35; // rax
  int v36; // eax
  long long v37; // rax
  long long v38; // rdx
  long long v40; // r8
  long long v41; // r8
  char v42; // al
  long long v43; // rcx
  long long v44; // rdx
  unsigned long long v45; // r8
  int v46; // eax
  long long v47; // rdi
  int v48; // eax
  unsigned long long v49; // r11
  unsigned int v50; // r9d
  long long v51; // r10
  int v52; // ecx
  unsigned long long v53; // r13
  unsigned long long v54; // r13
  long long v55; // rsi
  long long v56; // rax
  long long v57; // rcx
  long long v58; // rax
  unsigned int v59; // ebx
  unsigned int v60; // r9d
  long long v61; // rax
  unsigned long long v62; // r9
  unsigned long long v63; // rax
  unsigned long long v64; // rax
  int v65; // ecx
  int v66; // edx
  int v67; // esi
  unsigned int *v68; // rax
  unsigned int v69; // edi
  unsigned int v70; // edi
  unsigned long long v71; // rcx
  long long v72; // rax
  const char *v73; // rax
  long long v74; // rax
  long long v75; // rax
  unsigned long long v76; // rax
  unsigned int v77; // r13d
  long long v78; // rbx
  unsigned long long v79; // r11
  unsigned long long v80; // rax
  long long v81; // rdx
  long long v82; // rdx
  long long v83; // rsi
  long long v84; // rdx
  long long v85; // r9
  unsigned long long v86; // r13
  unsigned long long v87; // rax
  long long v88; // rax
  long long v89; // rax
  unsigned long long v90; // rax
  unsigned long long v91; // rdx
  int fixed; // eax
  long long v93; // rax
  unsigned long long v94; // r11
  unsigned long long v95; // r8
  long long v96; // rdx
  long long v97; // rsi
  int v98; // eax
  bool v99; // [rsp+4h] [rbp-104h]
  int v100; // [rsp+4h] [rbp-104h]
  unsigned long long v101; // [rsp+10h] [rbp-F8h]
  unsigned char v103; // [rsp+18h] [rbp-F0h]
  unsigned long long v104; // [rsp+18h] [rbp-F0h]
  unsigned int v105; // [rsp+18h] [rbp-F0h]
  long long v106; // [rsp+18h] [rbp-F0h]
  int v109; // [rsp+30h] [rbp-D8h]
  bool v110; // [rsp+34h] [rbp-D4h]
  int v111; // [rsp+34h] [rbp-D4h]
  unsigned int v112; // [rsp+34h] [rbp-D4h]
  short v113; // [rsp+38h] [rbp-D0h]
  bool v114; // [rsp+3Ah] [rbp-CEh]
  unsigned int v115; // [rsp+3Ch] [rbp-CCh]
  unsigned long long v116; // [rsp+40h] [rbp-C8h] BYREF
  unsigned long long v117; // [rsp+48h] [rbp-C0h]
  unsigned int v118; // [rsp+50h] [rbp-B8h]
  int v119; // [rsp+54h] [rbp-B4h]
  char v120[4]; // [rsp+60h] [rbp-A8h] BYREF
  int v121; // [rsp+64h] [rbp-A4h]
  int v122; // [rsp+68h] [rbp-A0h]
  int v123; // [rsp+6Ch] [rbp-9Ch]
  char v124[4]; // [rsp+90h] [rbp-78h] BYREF
  int v125; // [rsp+94h] [rbp-74h]
  unsigned long long v126; // [rsp+C8h] [rbp-40h]

  v11 = *a2;
  v126 = __readfsqword(0x28u);
  info = ext2fs_extent_get_info(a7, v120);
  *a2 = info;
  if ( info )
    return v126 - __readfsqword(0x28u);
  if ( a1[77] >= 0 && !a3[27] )
  {
    v65 = v122;
    v66 = v123;
    v67 = v121;
    v68 = &a3[2 * v121 + 28];
    v69 = a3[2 * v121 + 29];
    *v68 += v122;
    v70 = v66 + v69;
    if ( v65 < v66 && v67 )
      --v70;
    v68[1] = v70;
  }
  v109 = v11 == 2133571476;
  v13 = ext2fs_extent_get(a7, 3);
  *a2 = v13;
  v114 = v13 == 0 || v13 == 2133571476;
  if ( !v114 )
  {
LABEL_44:
    if ( v109 )
      goto LABEL_45;
    goto LABEL_46;
  }
  while ( 1 )
  {
    v14 = v122--;
    if ( v14 <= 0 )
      goto LABEL_44;
    v15 = v117;
    v16 = v118;
    v17 = v119;
    v18 = *(short *)a2[3];
    v19 = v116;
    a2[6] = v117;
    LODWORD(v20) = v17 & 1;
    a2[10] = v16;
    v21 = v18 & 0xF000;
    a2[5] = v19;
    v113 = v21;
    LOBYTE(v22) = v21 == 0x4000;
    a2[7] = v15 + v16;
    v23 = a8 & 1;
    v101 = v15 + v16 - 1;
    v99 = v20;
    if ( !v19
      || (v31 = *(long long *)(*(long long *)a1 + 32LL), v19 < *(unsigned int *)(v31 + 20))
      || (v115 = v20,
          v110 = v21 == 0x4000,
          v32 = ext2fs_blocks_count(v31),
          v22 = v110,
          v23 = a8 & 1,
          v20 = v115,
          v19 >= v32) )
    {
      v24 = &stru_10058;
      v23 &= v22;
      if ( v23 )
        goto LABEL_16;
      goto LABEL_7;
    }
    if ( v117 < a4 )
    {
      v24 = &stru_10058 + 6;
      v23 &= v110;
      if ( v23 )
        goto LABEL_16;
      goto LABEL_7;
    }
    if ( a5 && v101 > a5 && (v101 <= a6 || (v119 & 2) == 0 && (*(char *)(a2[3] + 34) & 0x10) == 0) )
    {
      v24 = &stru_10058 + 22;
      v23 &= v110;
      if ( v23 )
        goto LABEL_16;
      goto LABEL_7;
    }
    if ( !v115 )
      goto LABEL_113;
    if ( v118 )
    {
      v86 = v116 + v118;
      v87 = ext2fs_blocks_count(*(long long *)(*(long long *)a1 + 32LL));
      v22 = v110;
      v23 = a8 & 1;
      if ( v86 <= v87 )
      {
        v20 = v115;
LABEL_113:
        v83 = v99;
        LOBYTE(v83) = v22 && v99;
        if ( v22 && v99 )
        {
          v84 = v118;
          if ( !*(int *)(a2[3] + 108)
            && !(unsigned int)sub_1FE40(
                                *(unsigned int *)(*(long long *)(*(long long *)a1 + 32LL) + 96LL),
                                v83,
                                v118,
                                v22,
                                v20) )
          {
            v25 = v117;
            if ( v117 + (unsigned int)v84 > (unsigned int)(1 << (21 - *(char *)(v85 + 24))) )
            {
              if ( a8 )
              {
                v24 = &stru_10040 + 4;
                goto LABEL_16;
              }
              goto LABEL_165;
            }
          }
          if ( !(int)v84 )
          {
            if ( v23 )
              goto LABEL_136;
LABEL_140:
            v25 = v117;
            v23 = 0;
            v99 = v114;
            goto LABEL_9;
          }
        }
        else
        {
          if ( !v99 )
          {
            LOBYTE(v83) = v23 & v22;
            if ( !(v23 & v22) )
            {
              v25 = v117;
LABEL_165:
              v99 = v83;
              v23 = 0;
              goto LABEL_9;
            }
LABEL_137:
            if ( (v119 & 2) != 0 && (v111 = v20, fixed = fix_problem(a1, 65651, a2), LODWORD(v20) = v111, fixed) )
            {
              *((char *)a3 + 4) |= 0x80u;
              v119 &= ~2u;
              v93 = ext2fs_extent_replace(a7, 0, &v116);
              *a2 = v93;
              if ( v93 )
                return v126 - __readfsqword(0x28u);
              v109 = 0;
              v25 = v117;
              v23 = v114;
              LODWORD(v20) = v111;
            }
            else
            {
              v25 = v117;
              v23 = v114;
            }
            goto LABEL_9;
          }
          v84 = v118;
          v23 &= v22;
          if ( !v118 )
            goto LABEL_140;
        }
        v25 = v117;
        v90 = *((long long *)a3 + 12);
        if ( v117 >= v90 )
        {
          v91 = v117 + v84;
          if ( v90 >= v91 )
          {
            if ( v23 )
              goto LABEL_136;
          }
          else
          {
            *((long long *)a3 + 12) = v91;
            if ( v23 )
            {
LABEL_136:
              v99 = v114;
              goto LABEL_137;
            }
          }
          v99 = v114;
          goto LABEL_9;
        }
        v24 = &stru_10070 + 13;
        v99 = v114;
LABEL_7:
        if ( a8 )
          goto LABEL_16;
        v25 = v117;
LABEL_9:
        if ( !(int)v20 )
        {
          v26 = v116;
          if ( *a3 != 7
            && *(unsigned int *)(*(long long *)(*(long long *)a1 + 32LL) + 4LL) > v116
            && (unsigned int)ext2fs_test_block_bitmap2(*((long long *)a1 + 114), v116) )
          {
            a2[5] = v26;
            fix_problem(a1, 65649, a2);
            if ( (a1[76] & 8) == 0 )
              *((int *)a1 + 18) |= 8u;
            v72 = ext2fs_extent_get(a7, 12);
            v33 = 0;
            *a2 = v72;
            if ( v72 && v72 != 2133571476 )
            {
              v73 = "EXT2_EXTENT_DOWN";
LABEL_100:
              a2[12] = (long long)v73;
              return v126 - __readfsqword(0x28u);
            }
LABEL_34:
            if ( v117 != v25 )
            {
              v100 = v33;
              v34 = ext2fs_extent_get_info(a7, v124);
              *a2 = v34;
              if ( v34 )
              {
                v73 = "ext2fs_extent_get_info";
                goto LABEL_100;
              }
              v35 = v117;
              a2[5] = v25;
              a2[6] = v35;
              a2[10] = v125 - 1;
              v36 = fix_problem(a1, 65645, a2);
              v33 = v100;
              if ( v36 )
              {
                *((char *)a3 + 4) |= 0x80u;
                v74 = ext2fs_extent_fix_parents(a7);
                v33 = v100;
                *a2 = v74;
                if ( v74 )
                {
LABEL_104:
                  v73 = "ext2fs_extent_fix_parents";
                  goto LABEL_100;
                }
              }
              LODWORD(v25) = v117;
            }
            scan_extent_node((int)a1, (int)a2, (int)a3, v25, v101, a6, a7, v33);
            if ( *a2 )
              return v126 - __readfsqword(0x28u);
            v37 = ext2fs_extent_get(a7, 11);
            *a2 = v37;
            if ( v37 )
            {
              a2[12] = (long long)"EXT2_EXTENT_UP";
              return v126 - __readfsqword(0x28u);
            }
            sub_20780((long long)a1, v26, v38);
            ++*((long long *)a3 + 1);
LABEL_41:
            v30 = ext2fs_extent_get(a7, 5);
            *a2 = v30;
            goto LABEL_42;
          }
          v27 = ext2fs_extent_get(a7, 12);
          *a2 = v27;
          if ( !v27 || v27 == 2133571476 )
          {
            v33 = 1;
            goto LABEL_34;
          }
          a2[12] = (long long)"EXT2_EXTENT_DOWN";
          if ( v27 != 2133571447 )
            return v126 - __readfsqword(0x28u);
          v24 = &stru_10058 + 7;
          goto LABEL_16;
        }
        v40 = *((long long *)a3 + 7);
        if ( v40 )
        {
LABEL_50:
          v41 = v40 + 1;
          if ( v41 != v116 )
          {
            if ( (a1[77] & 8) != 0 )
            {
              v42 = *((char *)a3 + 4);
              v43 = 100;
              if ( (v42 & 1) == 0 )
                v43 = (v42 & 2) == 0 ? 63 : 102;
              v103 = v23;
              __printf_chk(
                1,
                "%6lu(%c): expecting %6lu actual extent phys %6lu log %lu len %lu\n",
                *((unsigned int *)a2 + 2),
                v43,
                v41,
                v116,
                v25,
                v118);
              v25 = v117;
              v23 = v103;
            }
            *((char *)a3 + 4) |= 0x10u;
          }
        }
        if ( v23 )
        {
          v44 = *((long long *)a3 + 3);
          v45 = v44 + 1;
          if ( v44 + 1 < v25 )
          {
            v46 = 1 << *(int *)(*(long long *)a1 + 192LL);
            if ( v46 > 1 )
              v45 = v116 & (v46 - 1) | -v46 & (unsigned long long)(v44 + v46);
            a2[6] = v45;
            a2[5] = v25;
            v104 = v45;
            if ( (unsigned int)fix_problem(a1, 65650, a2) )
            {
              *((char *)a3 + 4) |= 0x80u;
              v117 = v104;
              v75 = ext2fs_extent_replace(a7, 0, &v116);
              *a2 = v75;
              if ( !v75 )
              {
                v88 = ext2fs_extent_fix_parents(a7);
                *a2 = v88;
                if ( v88 || (v89 = ext2fs_extent_goto(a7, v117), (*a2 = v89) != 0) )
                {
LABEL_120:
                  fix_problem(a1, 65579, a2);
                  *((int *)a1 + 18) |= 1u;
                  return v126 - __readfsqword(0x28u);
                }
                v25 = v117;
                v109 = 0;
                v101 = v117 + v118 - 1;
                goto LABEL_62;
              }
              *a2 = 0;
            }
            v25 = v117;
          }
        }
LABEL_62:
        if ( v113 == 0x4000 )
        {
          while ( 1 )
          {
            v57 = *((long long *)a3 + 5) + 1LL;
            v58 = *(long long *)a1;
            *((long long *)a3 + 5) = v57;
            if ( v57 >= (long long)v25 )
              break;
            v56 = ext2fs_add_dir_block2(*(long long *)(v58 + 144), *a3, 0, v57);
            *a2 = v56;
            if ( v56 )
            {
              a2[5] = 0;
              a2[10] = *((long long *)a3 + 5);
              goto LABEL_120;
            }
            v25 = v117;
          }
          if ( v118 )
          {
            v59 = 0;
            while ( 1 )
            {
              v61 = ext2fs_add_dir_block2(*(long long *)(v58 + 144), *((unsigned int *)a2 + 2), v59 + v116, v59 + v25);
              *a2 = v61;
              if ( v61 )
              {
                v62 = v117 + v59;
                a2[5] = v59 + v116;
                a2[10] = v62;
                goto LABEL_120;
              }
              v60 = v118;
              ++v59;
              v25 = v117;
              if ( v118 <= v59 )
                break;
              v58 = *(long long *)a1;
            }
            if ( v118 )
            {
              v94 = v116;
              v47 = *(long long *)a1;
              v95 = v117;
              v96 = *((long long *)a3 + 3);
              v97 = *((long long *)a3 + 7);
              v112 = v118;
              *((long long *)a3 + 5) = v117 + v118 - 1;
              v106 = v60;
              v98 = sub_1F570(v47, v97, v96, v94, v95);
              v51 = v106;
              v50 = v112;
              if ( v98 )
                goto LABEL_108;
LABEL_65:
              v52 = *(int *)(v47 + 192);
              v53 = v49 >> v52;
              if ( v52 && (v63 = *((long long *)a3 + 7)) != 0 && (v64 = v63 >> v52, v64 == v53) )
                v54 = (v64 + 1) << v52;
              else
                v54 = v53 << v52;
              v55 = v49 + v51 - 1;
              if ( v51 + v49 > v54 )
              {
                sub_21240(a1, v54, v50 + v49 - v54);
                v55 = v116 + v118 - 1;
                v71 = 1 << *(int *)(*(long long *)a1 + 192LL);
                *((long long *)a3 + 1) += (unsigned int)((v71 + v55 - v54) / v71);
              }
              *((long long *)a3 + 7) = v55;
              *((long long *)a3 + 3) = v101;
              if ( v113 == 0x4000 || !v99 )
              {
                a4 = v101;
              }
              else
              {
                a4 = v101;
                if ( (v119 & 2) == 0 )
                  *((long long *)a3 + 4) = v101;
              }
              goto LABEL_41;
            }
          }
          v49 = v116;
          v47 = *(long long *)a1;
        }
        else
        {
          v47 = *(long long *)a1;
          v105 = v118;
          v48 = sub_1F570(*(long long *)a1, *((long long *)a3 + 7), *((long long *)a3 + 3), v116, v25);
          v50 = v105;
          if ( !v48 )
          {
LABEL_64:
            v51 = v50;
            goto LABEL_65;
          }
          if ( v105 )
          {
LABEL_108:
            v76 = v25;
            v77 = 0;
            while ( 1 )
            {
              v78 = v77;
              v79 = v77 + v49;
              v80 = v77++ + v76;
              a2[6] = v79;
              a2[5] = v80;
              fix_problem(a1, 65652, a2);
              sub_20780((long long)a1, v78 + v116, v81);
              sub_20780((long long)a1, v116 + v78, v82);
              v50 = v118;
              if ( v118 <= v77 )
                break;
              v76 = v117;
              v49 = v116;
            }
            v47 = *(long long *)a1;
            v49 = v116;
            goto LABEL_64;
          }
        }
        v50 = 0;
        v51 = 0;
        goto LABEL_65;
      }
      if ( v110 )
      {
        v24 = &stru_10058 + 1;
        if ( (a8 & 1) != 0 )
          goto LABEL_16;
      }
      v24 = &stru_10058 + 1;
    }
    else
    {
      if ( v110 )
      {
        v24 = &stru_10058 + 14;
        if ( v23 )
          goto LABEL_16;
      }
      v24 = &stru_10058 + 14;
    }
    if ( !a8 )
    {
      v40 = *((long long *)a3 + 7);
      v25 = v117;
      if ( v40 )
      {
        v23 = 0;
        goto LABEL_50;
      }
      goto LABEL_62;
    }
LABEL_16:
    if ( !(unsigned int)fix_problem(a1, v24, a2) )
      goto LABEL_41;
    if ( *((int *)a1 + 130) )
      break;
    e2fsck_read_bitmaps(a1);
    *((char *)a3 + 4) |= 0x80u;
    v28 = ext2fs_extent_delete(a7, 0);
    *a2 = v28;
    if ( v28 )
    {
      a2[12] = (long long)"ext2fs_extent_delete";
      return v126 - __readfsqword(0x28u);
    }
    v29 = ext2fs_extent_fix_parents(a7);
    *a2 = v29;
    if ( v29 && v29 != 2133571456 )
      goto LABEL_104;
    v30 = ext2fs_extent_get(a7, 0);
    *a2 = v30;
    if ( v30 == 2133571456 )
      goto LABEL_83;
    v109 = 0;
LABEL_42:
    if ( v30 && v30 != 2133571476 )
      goto LABEL_44;
  }
  v30 = ext2fs_extent_get(a7, 5);
  *a2 = v30;
  *((int *)a1 + 18) |= 8u;
  if ( v30 != 2133571456 )
    goto LABEL_42;
LABEL_83:
  *a2 = 0;
  if ( !v109 )
    return v126 - __readfsqword(0x28u);
LABEL_45:
  if ( (unsigned int)fix_problem(a1, 65642, a2) )
  {
    *((char *)a3 + 4) |= 0x80u;
    *a2 = ext2fs_extent_replace(a7, 0, &v116);
  }
  else
  {
LABEL_46:
    if ( *a2 == 2133571452 )
      *a2 = 0;
  }
  return v126 - __readfsqword(0x28u);
}


// Function: handle_htree @ 0x22000
long long handle_htree(long long *a1, long long *a2, int a3, long long a4, long long a5)
{
  long long v10; // r15
  long long v11; // rax
  long long v12; // rdi
  long long result; // rax
  unsigned long long v14; // rax
  long long v15; // rdx
  long long v16; // rax
  unsigned char v17; // dl
  long long v18; // rsi
  long long v19; // rdx
  long long v20; // rcx
  long long v21; // r8
  long long v22; // rcx
  int v23; // r8d
  unsigned int *v24; // rdi
  long long v25[9]; // [rsp+0h] [rbp-48h] BYREF

  v10 = *a1;
  v25[1] = __readfsqword(0x28u);
  if ( (*(short *)a4 & 0xF000) != 0x4000 && (unsigned int)fix_problem(a1, 65608, a2)
    || !(unsigned int)sub_21FF0(*(unsigned int *)(*(long long *)(v10 + 32) + 92LL))
    && (unsigned int)fix_problem(a1, 65607, a2) )
  {
    return 1;
  }
  v11 = ext2fs_bmap2(v10, a3, a4, 0, 0, 0, 0, (long long)v25);
  *a2 = v11;
  if ( v11 )
    return (unsigned int)fix_problem(a1, 65609, a2) != 0;
  if ( !v25[0] )
    return (unsigned int)fix_problem(a1, 65609, a2) != 0;
  v12 = *(long long *)(v10 + 32);
  if ( v25[0] < (unsigned long long)*(unsigned int *)(v12 + 20) )
    return (unsigned int)fix_problem(a1, 65609, a2) != 0;
  v14 = ext2fs_blocks_count(v12);
  if ( v14 <= v25[0] )
    return (unsigned int)fix_problem(a1, 65609, a2) != 0;
  if ( io_channel_read_blk64(*(long long *)(v10 + 8), v25[0], 1, a5) && (unsigned int)fix_problem(a1, 65609, a2)
    || (*(int *)(a5 + 24) || *(char *)(a5 + 29) <= 7u) && (unsigned int)fix_problem(a1, 65609, a2) )
  {
    return 1;
  }
  v15 = *(unsigned char *)(a5 + 28);
  a2[10] = v15;
  if ( (unsigned char)v15 > 2u && (char)v15 != 6 && (unsigned int)fix_problem(a1, 65610, a2) )
    return 1;
  if ( (unsigned int)sub_1E110(a4) )
  {
    if ( *(char *)(a5 + 28) != 6 && (unsigned int)fix_problem(a1, 65677, a2) )
      return 1;
  }
  else if ( *(char *)(a5 + 28) == 6 && (unsigned int)fix_problem(a1, 65678, a2) )
  {
    return 1;
  }
  if ( (*(char *)(a5 + 31) & 1) != 0 && (unsigned int)fix_problem(a1, 65611, a2) )
    return 1;
  v16 = *(unsigned char *)(a5 + 30);
  a2[10] = v16;
  v17 = v16;
  if ( (unsigned char)v16 > 3u )
  {
    if ( (unsigned int)fix_problem(a1, 65612, a2) )
      return 1;
    v17 = *(char *)(a5 + 30);
  }
  v18 = v17;
  if ( v17 > (unsigned int)sub_1FE50(*(long long *)(v10 + 32), v17)
    && !(unsigned int)sub_1FE40(*(unsigned int *)(v20 + 96), v18, v19, v20, v21) )
  {
    v23 = *(int *)(v22 + 24);
    v24 = (unsigned int *)a2[3];
    if ( (v24[1] | ((unsigned long long)v24[27] << 32)) < (unsigned int)((((1 << (v23 + 17)) - 2) * ((1 << (v23 + 17)) - 1)) << (v23 + 20))
      && v24[7] < (((1 << (v23 + 17)) - 2) * ((1 << (v23 + 17)) - 1)) << (v23 + 11) )
    {
      if ( (unsigned int)fix_problem(a1, 65612, a2) )
        return 1;
      LOBYTE(v19) = *(char *)(a5 + 30);
    }
  }
  if ( (unsigned char)v19 > 2u
    || (result = sub_1E130(*(unsigned int *)(a4 + 4) | ((unsigned long long)*(unsigned int *)(a4 + 108) << 32)),
        (int)result) )
  {
    ++*((int *)a1 + 201);
    return 0;
  }
  return result;
}


// Function: e2fsck_pass1_check_device_inode @ 0x22d20
long long e2fsck_pass1_check_device_inode(long long a1, int *a2)
{
  int v2; // edx
  long long result; // rax
  int *v4; // rax
  int *v5; // rsi

  v2 = a2[8];
  result = 0;
  if ( (v2 & 0x81000) == 0 )
  {
    result = 1;
    if ( (v2 & 0x30) != 0 )
    {
      v4 = a2 + 14;
      v5 = a2 + 25;
      while ( !*v4 )
      {
        if ( ++v4 == v5 )
          return 1;
      }
      return 0;
    }
  }
  return result;
}


// Function: e2fsck_pass1_check_symlink @ 0x22d70
long long e2fsck_pass1_check_symlink(long long a1, long long a2, long long a3, const char *a4)
{
  int v4; // r9d
  int v6; // eax
  unsigned int is_fast_symlink; // r12d
  int v11; // eax
  unsigned int v12; // r12d
  unsigned int v13; // eax
  unsigned long long v14; // r14
  int *v15; // rax
  long long v16; // rdi
  long long v17; // rax
  long long v18[3]; // [rsp+18h] [rbp-90h] BYREF
  int v19; // [rsp+30h] [rbp-78h]
  long long v20; // [rsp+40h] [rbp-68h] BYREF
  int v21; // [rsp+48h] [rbp-60h]
  int v22; // [rsp+50h] [rbp-58h]
  unsigned long long v23; // [rsp+78h] [rbp-30h]

  v4 = *(int *)(a3 + 108);
  v23 = __readfsqword(0x28u);
  if ( v4 )
    return 0;
  if ( !*(int *)(a3 + 4) )
    return 0;
  v6 = *(int *)(a3 + 32);
  if ( (v6 & 0x1000) != 0 )
    return 0;
  if ( (v6 & 0x10000000) != 0 )
  {
    if ( (v6 & 0x80000) == 0 && !ext2fs_inline_data_size(a1, a2, &v20) )
      return *(unsigned int *)(a3 + 4) == v20;
    return 0;
  }
  is_fast_symlink = ext2fs_is_fast_symlink(a3);
  if ( is_fast_symlink )
  {
    v11 = *(int *)(a3 + 32);
    if ( (v11 & 0x80000) != 0 )
      return 0;
    a4 = (const char *)(a3 + 40);
    v12 = 60;
LABEL_13:
    if ( (v11 & 0x800) != 0 )
      v13 = *(unsigned short *)a4 + 2;
    else
      v13 = strnlen(a4, v12);
    if ( v12 > v13 )
      return *(int *)(a3 + 4) == v13;
    return 0;
  }
  if ( (*(char *)(a3 + 34) & 8) != 0 )
  {
    if ( !ext2fs_extent_open2(a1, (unsigned int)a2, a3, v18) )
    {
      if ( ext2fs_extent_get_info(v18[0], &v20)
        || v21 != 1
        || v22
        || (v17 = ext2fs_extent_get(v18[0], 1), v18[2] | v17)
        || v19 != 1 )
      {
        ext2fs_extent_free(v18[0]);
        return is_fast_symlink;
      }
      v14 = v18[1];
      ext2fs_extent_free(v18[0]);
LABEL_21:
      v16 = *(long long *)(a1 + 32);
      if ( *(unsigned int *)(v16 + 20) <= v14
        && ext2fs_blocks_count(v16) > v14
        && !io_channel_read_blk64(*(long long *)(a1 + 8), v14, 1, a4) )
      {
        v12 = *(int *)(a1 + 40);
        v11 = *(int *)(a3 + 32);
        goto LABEL_13;
      }
    }
  }
  else
  {
    v14 = *(unsigned int *)(a3 + 40);
    v15 = (int *)(a3 + 44);
    while ( !*v15 )
    {
      if ( (int *)(a3 + 100) == ++v15 )
        goto LABEL_21;
    }
  }
  return is_fast_symlink;
}


// Function: e2fsck_setup_icount @ 0x22f80
long long e2fsck_setup_icount(long long *a1, long long a2, unsigned int a3, long long a4, long long *a5)
{
  long long v9; // rdi
  long long result; // rax
  unsigned int v11; // [rsp+0h] [rbp-58h] BYREF
  int v12; // [rsp+4h] [rbp-54h] BYREF
  unsigned int v13; // [rsp+8h] [rbp-50h] BYREF
  int v14; // [rsp+Ch] [rbp-4Ch] BYREF
  char *name[9]; // [rsp+10h] [rbp-48h] BYREF

  v9 = a1[108];
  name[1] = (char *)__readfsqword(0x28u);
  *a5 = 0;
  profile_get_string(v9, "scratch_files", "directory", 0, 0, name);
  profile_get_uint(a1[108], "scratch_files", "numdirs_threshold", 0, 0, &v11);
  profile_get_boolean(a1[108], "scratch_files", "icount", 0, 1, &v14);
  if ( ext2fs_get_num_dirs(*a1, &v13) )
    v13 = 1024;
  if ( !v14
    || !name[0]
    || access(name[0], 2)
    || v11 && v11 >= v13
    || (result = ext2fs_create_icount_tdb(*a1, name[0], a3, a5)) != 0 )
  {
    e2fsck_set_bitmap_type(*a1, 2, a2, &v12);
    if ( (*((char *)a1 + 78) & 2) != 0 )
      a3 |= 2u;
    result = ext2fs_create_icount2(*a1, a3, 0, a4, a5);
    *(short *)(*a1 + 196LL) = v12;
  }
  return result;
}


// Function: e2fsck_clear_inode @ 0x230f0
long long e2fsck_clear_inode(long long a1, long long a2, long long a3, int a4, long long a5)
{
  long long v9; // rdi
  long long v10; // rdx
  unsigned int v11; // eax
  long long v12; // rdi
  long long v13; // rdi

  v9 = *(long long *)(a1 + 448);
  *(int *)(a3 + 32) = 0;
  *(short *)(a3 + 26) = 0;
  ext2fs_icount_store(v9, a2, 0);
  *(int *)(a3 + 20) = *(long long *)(a1 + 840);
  v10 = *(long long *)(*(long long *)a1 + 32LL);
  v11 = 11;
  if ( *(int *)(v10 + 76) )
    v11 = *(int *)(v10 + 84);
  if ( v11 > (unsigned int)a2 )
  {
    *(long long *)(a3 + 88) = 0;
    *(int *)(a3 + 96) = 0;
    *(_OWORD *)(a3 + 40) = 0;
    *(_OWORD *)(a3 + 56) = 0;
    *(_OWORD *)(a3 + 72) = 0;
  }
  ext2fs_unmark_inode_bitmap2(*(long long *)(a1 + 376), (unsigned int)a2);
  ext2fs_unmark_inode_bitmap2(*(long long *)(a1 + 360), (unsigned int)a2);
  v12 = *(long long *)(a1 + 400);
  if ( v12 )
    ext2fs_unmark_inode_bitmap2(v12, (unsigned int)a2);
  v13 = *(long long *)(a1 + 368);
  if ( v13 )
    ext2fs_unmark_inode_bitmap2(v13, (unsigned int)a2);
  *(int *)(a1 + 72) |= a4;
  if ( (int)a2 == 1 )
  {
    *(long long *)a3 = 0;
    *(long long *)(a3 + 120) = 0;
    memset(
      (void *)((a3 + 8) & 0xFFFFFFFFFFFFFFF8LL),
      0,
      8LL * (((unsigned int)a3 - (((int)a3 + 8) & 0xFFFFFFF8) + 128) >> 3));
  }
  return e2fsck_write_inode(a1, (unsigned int)a2, a3, a5);
}


// Function: fix_inline_data_extents_file @ 0x23210
long long fix_inline_data_extents_file(long long a1, long long a2, long long a3, int a4, long long a5)
{
  long long v9; // r15
  long long v10; // rdi
  long long v11; // rdx
  long long v12; // rcx
  short v13; // dx
  unsigned long long v14; // rdx
  unsigned int v15; // eax

  v9 = *(long long *)a1;
  v10 = *(unsigned int *)(*(long long *)(*(long long *)a1 + 32LL) + 96LL);
  if ( !(unsigned int)sub_203C0(v10) && !(unsigned int)sub_1FE30(v10, a2, v11, v12) )
    return 0;
  v13 = *(short *)a3 & 0xF000;
  if ( v13 == 4096 || (*(short *)a3 & 0xB000) == 0x2000 || v13 == -16384 )
  {
    sub_1E660(a1, a5);
    return 0;
  }
  else
  {
    if ( !ext2fs_extent_header_verify(a3 + 40, 60) && (unsigned int)fix_problem(a1, 65655, a5) )
    {
      v15 = *(int *)(a3 + 32) & 0xEFFFFFFF;
      goto LABEL_11;
    }
    v14 = 60;
    if ( a4 > 128 )
      v14 = a4 - *(unsigned short *)(a3 + 128) - 68;
    if ( (*(unsigned int *)(a3 + 4) | ((unsigned long long)*(unsigned int *)(a3 + 108) << 32)) < v14
      && (unsigned int)fix_problem(a1, 65656, a5) )
    {
      v15 = *(int *)(a3 + 32) & 0xFFF7FFFF;
LABEL_11:
      *(int *)(a3 + 32) = v15;
      e2fsck_write_inode(a1, (unsigned int)a2, a3, "pass1");
      return 0;
    }
    if ( (unsigned int)sub_1E3D0(v9, a3) && (unsigned int)fix_problem(a1, 65657, a5) )
    {
      v15 = *(int *)(a3 + 32) & 0xEFF7FFFF;
      goto LABEL_11;
    }
    if ( !(unsigned int)fix_problem(a1, 65658, a5) )
      return 0;
    e2fsck_clear_inode(a1, (unsigned int)a2, a3, 0, (long long)"pass1");
    return 0xFFFFFFFFLL;
  }
}


// Function: check_blocks_extents @ 0x233d0
unsigned long long check_blocks_extents(char *a1, long long a2, long long a3)
{
  long long v4; // r13
  long long v5; // r14
  unsigned int v6; // r15d
  long long v7; // rax
  bool v8; // zf
  long long v9; // rax
  long long v10; // rdx
  unsigned long long v11; // rax
  unsigned int v12; // eax
  long long v13; // rdx
  long long v14; // rax
  long long v16; // [rsp+18h] [rbp-80h] BYREF
  char v17[16]; // [rsp+20h] [rbp-78h] BYREF
  int v18; // [rsp+30h] [rbp-68h]
  unsigned long long v19; // [rsp+58h] [rbp-40h]

  v4 = *(long long *)(a2 + 24);
  v5 = *(long long *)a1;
  v19 = __readfsqword(0x28u);
  v6 = *(int *)(a2 + 8);
  if ( ext2fs_extent_header_verify(v4 + 40, 60) )
  {
    if ( !(unsigned int)fix_problem(a1, 65665, a2) )
      goto LABEL_16;
    goto LABEL_18;
  }
  v7 = ext2fs_extent_open2(v5, v6, v4, &v16);
  *(long long *)a2 = v7;
  if ( v7 )
  {
    if ( !(unsigned int)fix_problem(a1, 65622, a2) )
    {
LABEL_16:
      *(long long *)a2 = 0;
      return v19 - __readfsqword(0x28u);
    }
LABEL_18:
    e2fsck_clear_inode((long long)a1, v6, v4, 0, (long long)"check_blocks_extents");
    *(long long *)a2 = 0;
    return v19 - __readfsqword(0x28u);
  }
  v8 = ext2fs_extent_get_info(v16, v17) == 0;
  v9 = v18;
  if ( v8 )
  {
    v10 = 4;
    if ( v18 <= 4 )
      v10 = v18;
    ++*(int *)&a1[4 * v10 + 816];
  }
  *(long long *)(a2 + 40) = v9;
  v11 = ext2fs_max_extent_depth(v16);
  *(long long *)(a2 + 48) = v11;
  if ( v11 < *(long long *)(a2 + 40) )
  {
    if ( (unsigned int)fix_problem(a1, 65663, a2) )
      *(int *)(a3 + 108) = 1;
    v11 = *(long long *)(a2 + 48);
  }
  *(long long *)(a2 + 40) = 5;
  if ( v11 > 5 )
    fix_problem(a1, 81925, a2);
  v12 = *(int *)a3;
  *(long long *)(a3 + 144) = 0;
  *(_OWORD *)(a3 + 112) = 0;
  *(_OWORD *)(a3 + 128) = 0;
  v13 = *(unsigned int *)(v4 + 4);
  *(int *)(a3 + 104) = v12;
  v14 = *(unsigned int *)(v4 + 108);
  *(long long *)(a3 + 96) = 0;
  sub_212C0(
    a1,
    (long long *)a2,
    (unsigned int *)a3,
    0,
    0,
    (((v13 | (v14 << 32)) + (unsigned long long)*(unsigned int *)(v5 + 40) - 1) >> ((unsigned char)*(int *)(*(long long *)(v5 + 32) + 24LL)
                                                                                + 10))
  - 1,
    v16,
    1);
  if ( *(long long *)a2 && (unsigned int)fix_problem(a1, 65623, a2) )
  {
    *(long long *)(a3 + 8) = 0;
    *(int *)(v4 + 28) = 0;
    e2fsck_clear_inode((long long)a1, v6, v4, 4, (long long)"check_blocks_extents");
    *(long long *)a2 = 0;
  }
  ext2fs_extent_free(v16);
  if ( (*(short *)v4 & 0xF000) != 0x4000 || !(unsigned int)e2fsck_dir_will_be_rehashed(a1, v6) )
  {
    if ( (a1[77] & 0x40) != 0 )
      e2fsck_rebuild_extents_later(a1, v6);
    else
      e2fsck_should_rebuild_extents(a1, a2, a3 + 104, v17);
  }
  return v19 - __readfsqword(0x28u);
}


// Function: check_blocks @ 0x236a0
unsigned long long check_blocks(char *a1, long long a2, long long a3, long long *a4)
{
  unsigned int v7; // r15d
  long long v8; // r12
  long long v9; // r14
  unsigned long long v10; // rax
  long long v11; // rsi
  short v12; // dx
  int v13; // ecx
  unsigned long long v14; // rax
  int v15; // ecx
  long long v16; // rdi
  long long v17; // rdx
  long long v18; // rcx
  long long v19; // rdx
  long long v20; // rax
  bool v21; // sf
  int v22; // r11d
  char v23; // al
  long long v24; // rdx
  unsigned int v25; // eax
  int v26; // r13d
  long long v27; // rsi
  int v28; // eax
  long long v29; // rdx
  unsigned long long v30; // rdi
  unsigned long long v31; // r13
  unsigned long long v32; // r13
  long long v33; // rdi
  short v34; // ax
  short v35; // r8
  long long v36; // r13
  long long v37; // rcx
  int v38; // eax
  long long v39; // rdi
  int v40; // eax
  short v42; // r8
  long long v43; // rcx
  long long v44; // rdi
  long long v45; // rsi
  long long v46; // rax
  short v47; // dx
  unsigned long long v48; // r13
  short v49; // rax^4
  long long v50; // rax
  long long v51; // rdx
  unsigned int v52; // eax
  long long v53; // rax
  int v54; // eax
  int v55; // [rsp+0h] [rbp-108h]
  int v56; // [rsp+0h] [rbp-108h]
  int v57; // [rsp+0h] [rbp-108h]
  int v58; // [rsp+4h] [rbp-104h]
  int v59; // [rsp+4h] [rbp-104h]
  long long v61[2]; // [rsp+18h] [rbp-F0h] BYREF
  long long v62; // [rsp+28h] [rbp-E0h]
  unsigned int v63; // [rsp+30h] [rbp-D8h] BYREF
  char v64; // [rsp+34h] [rbp-D4h]
  unsigned long long v65; // [rsp+38h] [rbp-D0h]
  long long v66; // [rsp+40h] [rbp-C8h]
  long long v67; // [rsp+48h] [rbp-C0h]
  long long v68; // [rsp+50h] [rbp-B8h]
  long long v69; // [rsp+58h] [rbp-B0h]
  int v70; // [rsp+60h] [rbp-A8h]
  long long v71; // [rsp+68h] [rbp-A0h]
  long long v72; // [rsp+70h] [rbp-98h]
  long long v73; // [rsp+78h] [rbp-90h]
  char *v74; // [rsp+88h] [rbp-80h]
  int v75; // [rsp+9Ch] [rbp-6Ch]
  unsigned long long v76; // [rsp+C8h] [rbp-40h]

  v7 = *(int *)(a2 + 8);
  v8 = *(long long *)a1;
  v9 = *(long long *)(a2 + 24);
  v76 = __readfsqword(0x28u);
  v10 = 0;
  v63 = v7;
  if ( a4 )
    v10 = *a4;
  v11 = *(long long *)(v8 + 32);
  v12 = *(short *)v9;
  v67 = -1;
  v13 = *(int *)(v8 + 192);
  v70 = 0;
  v68 = -1;
  v69 = -1;
  v14 = v10 >> v13;
  v15 = *(int *)(v11 + 24);
  v65 = v14;
  *(long long *)a2 = 0;
  v66 = 0x80000000 >> v15;
  v75 = 0;
  v16 = *(unsigned int *)(v11 + 96);
  v72 = v9;
  v71 = 0;
  v73 = a2;
  v74 = a1;
  v64 = v64 & 0x40 | ((v12 & 0xF000) == 0x4000) | (2 * ((v12 & 0xF000) == 0x8000));
  v58 = sub_203C0(v16);
  v55 = sub_1FE30(v16, a2, v17, v18);
  if ( (unsigned int)sub_22320(a1) )
  {
    if ( (a1[72] & 3) != 0 )
      return v76 - __readfsqword(0x28u);
    v65 += v61[1] >> *(int *)(*(long long *)a1 + 192LL);
  }
  if ( v55 && (*(char *)(v9 + 35) & 0x10) != 0 )
  {
    sub_1EE10(a1, (long long *)a2, &v63);
  }
  else if ( (unsigned int)ext2fs_inode_has_valid_blocks2(v8, v9) )
  {
    if ( v58 && (*(char *)(v9 + 34) & 8) != 0 )
    {
      sub_233D0(a1, a2, (long long)&v63);
    }
    else
    {
      v19 = v64 & 1;
      v56 = *(int *)(v8 + 16);
      *(int *)(v8 + 16) = v56 | 0x200000;
      v20 = ext2fs_block_iterate3(v8, v7, v19, a3, sub_20C70, &v63);
      v21 = v64 < 0;
      v22 = v56;
      *(long long *)a2 = v20;
      v68 = v67;
      if ( v21 )
      {
        e2fsck_read_inode(a1, v7, v9, "check_blocks");
        v22 = v56;
      }
      *(int *)(v8 + 16) = v22 & 0x200000 | *(int *)(v8 + 16) & 0xFFDFFFFF;
      if ( (a1[77] & 0x40) != 0
        && ((*(short *)v9 & 0xF000) != 0x4000 || !(unsigned int)e2fsck_dir_will_be_rehashed(a1, v7)) )
      {
        e2fsck_rebuild_extents_later(a1, v7);
      }
    }
  }
  end_problem_latch(a1, 16);
  end_problem_latch(a1, 128);
  v57 = *((int *)a1 + 18) & 3;
  if ( !v57 )
  {
    if ( *(long long *)a2 )
    {
      fix_problem(a1, 65577, a2);
      v23 = v64;
      if ( (v64 & 0x10) == 0 )
        goto LABEL_22;
    }
    else
    {
      v23 = v64;
      if ( (v64 & 0x10) == 0 )
        goto LABEL_22;
    }
    if ( v65 < *(unsigned int *)(*(long long *)(v8 + 32) + 32LL) )
    {
      if ( (*(short *)v9 & 0xF000) == 0x4000 )
        ++*((int *)a1 + 199);
      else
        ++*((int *)a1 + 198);
    }
LABEL_22:
    if ( (v23 & 4) != 0 )
    {
      e2fsck_clear_inode((long long)a1, v7, v9, 4, (long long)"check_blocks");
      return v76 - __readfsqword(0x28u);
    }
    if ( (*(char *)(v9 + 33) & 0x10) != 0 )
    {
      v57 = sub_22000((long long *)a1, (long long *)a2, v7, v9, a3);
      if ( v57 )
      {
        *(int *)(v9 + 32) &= ~0x1000u;
        v57 = 1;
      }
      else
      {
        e2fsck_add_dx_dir(a1, v7, v9, (unsigned int)(v67 + 1));
      }
    }
    if ( !v65 && (v64 & 1) != 0 && (*(char *)(v9 + 35) & 0x10) == 0 && (unsigned int)fix_problem(a1, 65542, a2) )
    {
      e2fsck_clear_inode((long long)a1, v7, v9, 0, (long long)"check_blocks");
      --*((int *)a1 + 184);
      return v76 - __readfsqword(0x28u);
    }
    if ( (unsigned int)quota_type2inum(2, *(long long *)(v8 + 32)) != v7 )
    {
      if ( v7 == 2 )
        goto LABEL_31;
      v24 = *(long long *)(*(long long *)a1 + 32LL);
      v25 = 11;
      if ( *(int *)(v24 + 76) )
        v25 = *(int *)(v24 + 84);
      if ( v25 <= v7 )
      {
LABEL_31:
        v26 = *(int *)(v9 + 32) & 0x200000;
        if ( !v26 )
        {
          quota_data_add(*((long long *)a1 + 79), v9, v7, v65 * (1024 << *(int *)(*(long long *)(v8 + 32) + 28LL)));
          if ( a4 )
            v26 = *((int *)a4 + 2);
          quota_data_inodes(*((long long *)a1 + 79), v9, v7, (unsigned int)(v26 + v62 + 1));
        }
      }
    }
    v27 = *(long long *)(v8 + 32);
    v28 = sub_21FE0(*(unsigned int *)(v27 + 100), v27);
    v30 = v65;
    if ( !v28 || (*(char *)(v9 + 34) & 4) == 0 )
      v30 = (*(int *)(v8 + 40) >> 9) * v65;
    v31 = (unsigned long long)*(unsigned int *)(v9 + 108) << 32;
    v65 = v30 * (1 << *(int *)(v8 + 192));
    v32 = *(unsigned int *)(v9 + 4) | v31;
    if ( (v64 & 1) != 0 )
    {
      if ( (*(char *)(v9 + 35) & 0x10) != 0 )
      {
        v44 = *(long long *)a1;
        v45 = *(unsigned int *)(a2 + 8);
        v61[0] = 0;
        v59 = *(int *)(v44 + 16);
        *(int *)(v44 + 16) = v59 | 0x200000;
        v46 = ext2fs_inline_data_size(v44, v45, v61);
        *(int *)(*(long long *)a1 + 16LL) = v59 & 0x200000 | *(int *)(*(long long *)a1 + 16LL) & 0xFFDFFFFF;
        if ( !v46 && v61[0] == v32 )
        {
LABEL_50:
          v34 = *(short *)v9;
          v29 = *(long long *)(v8 + 32);
          goto LABEL_51;
        }
        v47 = *(short *)v9;
        *(long long *)(a2 + 80) = v61[0];
        v38 = 7;
        if ( (v47 & 0xF000) != 0xA000 )
        {
LABEL_48:
          *(int *)(a2 + 64) = v38;
          if ( (unsigned int)fix_problem(a1, 65548, a2) )
          {
            ext2fs_inode_size_set(v8, v9, *(long long *)(a2 + 80));
            if ( !(*(unsigned int *)(v9 + 4) | ((unsigned long long)*(unsigned int *)(v9 + 108) << 32)) )
            {
              v54 = *(int *)(v9 + 32);
              if ( (v54 & 0x10000000) != 0 )
              {
                *(long long *)(v9 + 88) = 0;
                *(int *)(v9 + 96) = 0;
                *(int *)(v9 + 32) = v54 & 0xEFFFFFFF;
                *(_OWORD *)(v9 + 40) = 0;
                *(_OWORD *)(v9 + 56) = 0;
                *(_OWORD *)(v9 + 72) = 0;
              }
            }
            ++v57;
          }
          *(long long *)(a2 + 80) = 0;
          goto LABEL_50;
        }
        v27 = *(long long *)(v8 + 32);
      }
      else
      {
        v33 = *(unsigned int *)(v8 + 40);
        v34 = *(short *)v9;
        v35 = *(short *)v9 & 0xF000;
        if ( ((unsigned int)v32 & ((int)v33 - 1)) == 0 )
        {
          v36 = (unsigned int)(v32 >> ((unsigned char)*(int *)(v29 + 24) + 10));
          v37 = v67 + 1;
          if ( v67 + 1 < (unsigned long long)(unsigned int)v36 )
          {
            v38 = 1;
            if ( v35 == -24576 )
              goto LABEL_53;
          }
          else
          {
            if ( v67 + 1 <= (unsigned long long)(unsigned int)v36
              || v37 - v36 <= (unsigned long long)*(unsigned char *)(v29 + 205) )
            {
              goto LABEL_51;
            }
            v38 = 2;
            if ( v35 == -24576 )
              goto LABEL_53;
          }
          goto LABEL_47;
        }
        if ( v35 != -24576 )
        {
          v37 = v67 + 1;
          v38 = 5;
LABEL_47:
          *(long long *)(a2 + 80) = v33 * v37;
          goto LABEL_48;
        }
      }
    }
    else
    {
      v34 = *(short *)v9;
      v42 = *(short *)v9 & 0xF000;
      if ( v68 < 0 || (v33 = *(unsigned int *)(v8 + 40), v33 * v68 <= v32) || (*(char *)(v9 + 34) & 0x10) != 0 )
      {
        v43 = *(unsigned int *)(v29 + 24);
        if ( v58 && (*(char *)(v9 + 34) & 8) != 0 )
        {
          if ( (1LL << ((unsigned char)v43 + 42)) - 1 < v32 )
          {
            if ( v42 != -24576 )
            {
              v33 = *(unsigned int *)(v8 + 40);
              v37 = v67 + 1;
              v38 = 6;
              goto LABEL_47;
            }
            goto LABEL_53;
          }
        }
        else if ( v32 > qword_B7140[v43] )
        {
          if ( v42 != -24576 )
          {
            v33 = *(unsigned int *)(v8 + 40);
            v37 = v67 + 1;
            v38 = 4;
            goto LABEL_47;
          }
          goto LABEL_53;
        }
LABEL_51:
        if ( (v34 & 0xF000) == 0x8000
          && (unsigned int)sub_1E130(*(unsigned int *)(v9 + 4) | ((unsigned long long)*(unsigned int *)(v9 + 108) << 32)) )
        {
          ++*((int *)a1 + 200);
        }
        v27 = v29;
        goto LABEL_53;
      }
      if ( v42 != -24576 )
      {
        v37 = v67 + 1;
        v38 = 3;
        goto LABEL_47;
      }
    }
LABEL_53:
    if ( *(int *)(v27 + 72) == 1 )
    {
      v39 = *(unsigned int *)(v27 + 100);
    }
    else
    {
      v48 = v65;
      if ( v48 != ext2fs_inode_i_blocks(v8, v9)
        || (v39 = *(unsigned int *)(*(long long *)(v8 + 32) + 100LL), (unsigned int)sub_21FE0(v39, v9))
        && (*(char *)(v9 + 34) & 4) != 0
        && *(short *)(v9 + 116) )
      {
        *(long long *)(a2 + 80) = v65;
        if ( (unsigned int)fix_problem(a1, 65549, a2) )
        {
          v49 = WORD2(v65);
          ++v57;
          *(int *)(v9 + 28) = v65;
          *(short *)(v9 + 116) = v49;
        }
        v50 = *(long long *)(v8 + 32);
        *(long long *)(a2 + 80) = 0;
        v39 = *(unsigned int *)(v50 + 100);
      }
    }
    if ( !(unsigned int)sub_21FC0(v39)
      || (((*(short *)v9 & 0xF000) - 0x4000) & 0xB000) != 0
      || !ext2fs_inode_data_blocks2(v8, v9) )
    {
      goto LABEL_62;
    }
    if ( v7 != 2 )
    {
      v51 = *(long long *)(v8 + 32);
      v52 = 11;
      if ( *(int *)(v51 + 76) )
        v52 = *(int *)(v51 + 84);
      if ( v52 > v7 )
        goto LABEL_62;
    }
    if ( (*(int *)(v9 + 32) & 0x10080000) != 0
      || !(unsigned int)fix_problem(a1, 65664, a2)
      || (v53 = e2fsck_rebuild_extents_later(a1, v7), (*(long long *)a2 = v53) == 0) )
    {
LABEL_62:
      if ( *((long long *)a1 + 73) )
      {
        if ( (v64 & 1) != 0 )
        {
          v40 = *((int *)a1 + 138);
          if ( (!v40 || v40 != v7)
            && (*(char *)(v9 + 33) & 0x10) == 0
            && (unsigned int)(*(int *)(v9 + 4) / *(int *)(v8 + 40)) > 2 )
          {
            e2fsck_rehash_dir_later(a1, v7, (unsigned int)(*(int *)(v9 + 4) % *(int *)(v8 + 40)));
          }
        }
      }
    }
    if ( v57 )
      e2fsck_write_inode(a1, v7, v9, "check_blocks");
  }
  return v76 - __readfsqword(0x28u);
}


// Function: process_inodes @ 0x240b0
unsigned long long process_inodes(long long a1, long long a2)
{
  long long v4; // rax
  long long v5; // rsi
  long long v6; // rdx
  long long v7; // rbx
  int v8; // r14d
  unsigned int v9; // r8d
  char *v10; // rdx
  char *v11; // rax
  long long v12; // [rsp+8h] [rbp-120h]
  long long v13; // [rsp+10h] [rbp-118h]
  unsigned int v14; // [rsp+18h] [rbp-110h]
  int v15; // [rsp+1Ch] [rbp-10Ch]
  char v16[8]; // [rsp+20h] [rbp-108h] BYREF
  unsigned int v17; // [rsp+28h] [rbp-100h]
  char *v18; // [rsp+38h] [rbp-F0h]
  char v19[88]; // [rsp+90h] [rbp-98h] BYREF
  unsigned long long v20; // [rsp+E8h] [rbp-40h]

  v20 = __readfsqword(0x28u);
  if ( dword_B7178 )
  {
    v4 = ehandler_operation(0);
    v5 = dword_B7178;
    v12 = v4;
    v13 = *(long long *)(a1 + 544);
    v15 = *(int *)(a1 + 536);
    qsort(base, dword_B7178, 0xB8u, (__compar_fn_t)compar);
    clear_problem_context(v16, v5, v6);
    if ( dword_B7178 > 0 )
    {
      v7 = 0;
      v8 = 0;
      do
      {
        v9 = *(int *)((char *)base + v7);
        v10 = (char *)base + v7 + 24;
        *(long long *)(a1 + 544) = v10;
        *(int *)(a1 + 536) = v9;
        v18 = v10;
        v17 = v9;
        v14 = v9;
        v11 = dcgettext(0, "reading indirect blocks of inode %u", 5);
        __sprintf_chk(v19, 1, 80, v11, v14);
        ehandler_operation(v19);
        sub_236A0((char *)a1, (long long)v16, a2, (long long *)((char *)base + v7 + 8));
        if ( (*(char *)(a1 + 72) & 3) != 0 )
          break;
        ++v8;
        v7 += 184;
      }
      while ( dword_B7178 > v8 );
    }
    dword_B7178 = 0;
    *(long long *)(a1 + 544) = v13;
    *(int *)(a1 + 536) = v15;
    ehandler_operation(v12);
  }
  return v20 - __readfsqword(0x28u);
}


// Function: scan_callback @ 0x24270
long long scan_callback(long long a1, long long a2, int a3, long long a4)
{
  long long *v5; // rbp
  unsigned int (*v6)(long long *, long long, long long, long long); // rax

  v5 = *(long long **)a4;
  sub_240B0(*(long long *)(a1 + 224), *(long long *)(a4 + 8));
  v6 = (unsigned int (*)(long long *, long long, long long, long long))v5[44];
  if ( v6 && v6(v5, 1, (unsigned int)(a3 + 1), *(unsigned int *)(*v5 + 48LL)) )
    return 2133571409;
  else
    return 0;
}


// Function: e2fsck_use_inode_shortcuts @ 0x242d0
long long *e2fsck_use_inode_shortcuts(long long a1, int a2)
{
  long long *result; // rax

  result = *(long long **)a1;
  if ( a2 )
  {
    result[12] = sub_1E1C0;
    result[13] = sub_1E310;
    result[15] = sub_1E210;
    result[16] = sub_1E290;
    *(int *)(a1 + 536) = 0;
  }
  else
  {
    result[12] = 0;
    result[13] = 0;
    result[15] = 0;
    result[16] = 0;
  }
  return result;
}


// Function: e2fsck_intercept_block_allocations @ 0x24340
long long e2fsck_intercept_block_allocations(long long *a1)
{
  ext2fs_set_alloc_block_callback(*a1, sub_1F3D0, 0);
  ext2fs_set_block_alloc_stats_callback(*a1, sub_1E350, 0);
  ext2fs_set_new_range_callback(*a1, sub_1F350, 0);
  return ext2fs_set_block_alloc_stats_range_callback(*a1, sub_1F2D0, 0);
}


// Function: e2fsck_pass1 @ 0x24390
unsigned long long e2fsck_pass1(long long *a1)
{
  long long v2; // r12
  long long v3; // rbx
  long long v4; // rax
  long long v5; // rax
  long long v6; // rsi
  long long v7; // rdx
  long long i; // rdx
  char *v9; // rax
  char *v10; // rax
  char *v11; // rax
  char *v12; // rax
  char *v13; // rsi
  char *v14; // rax
  unsigned int v15; // eax
  void *memory; // rax
  long long v17; // rsi
  void *v18; // rax
  long long v19; // rdx
  long long v20; // rax
  long long v21; // rax
  char *v22; // rax
  long long v23; // rdi
  unsigned int (*v24)(long long *, long long, long long, long long); // rax
  unsigned int *v25; // r8
  unsigned int v26; // eax
  unsigned int v27; // eax
  unsigned int v28; // eax
  long long v29; // r8
  long long v30; // rdx
  long long v31; // rcx
  unsigned int *v32; // rsi
  long long v33; // r15
  long long v34; // rdx
  long long v35; // rax
  int v36; // r15d
  short *v37; // rdx
  short *v38; // rcx
  unsigned int v39; // eax
  unsigned short v40; // ax
  long long v41; // rdi
  unsigned int v42; // eax
  int v43; // eax
  void *v44; // rdx
  long long v45; // rsi
  long long v46; // rsi
  unsigned int v47; // edx
  long long v48; // rsi
  long long v49; // rdx
  unsigned int v50; // eax
  long long v51; // rcx
  long long v52; // r8
  long long v53; // rsi
  int *v54; // rdx
  long long v55; // rdi
  long long v56; // rdx
  long long v57; // rdi
  long long v58; // rdx
  int *v59; // rsi
  int v60; // eax
  short v61; // ax
  const __m128i *v62; // rsi
  int v63; // eax
  int v64; // eax
  int v65; // r8d
  unsigned int v66; // r8d
  __m128i v67; // xmm0
  int v68; // r9d
  char *v69; // rdx
  char *v70; // rax
  int v71; // eax
  long long v73; // rsi
  long long v74; // rdx
  long long v75; // rdi
  long long v76; // r12
  char *v77; // rax
  void *v78; // rdx
  long long v79; // rsi
  int fixed; // eax
  int v81; // eax
  void *v82; // rdx
  long long v83; // rsi
  unsigned int v84; // eax
  long long v85; // rsi
  long long v86; // rdi
  short *v87; // rax
  short v88; // dx
  void *v89; // rdx
  long long v90; // rsi
  long long v91; // rcx
  long long v92; // rax
  long long v93; // rcx
  long long v94; // rax
  void *v95; // rdx
  long long v96; // rcx
  char *v97; // rsi
  int *v98; // rdi
  long long v99; // rsi
  int v100; // eax
  long long *v101; // rax
  unsigned long long v102; // rdi
  void *v103; // rdx
  long long v104; // rsi
  long long v105; // rcx
  long long v106; // r8
  long long v107; // r8
  void *v108; // rdx
  long long v109; // rsi
  short v110; // ax
  void *v111; // rdx
  long long v112; // rsi
  void *v113; // rsi
  long long v114; // rdi
  long long v115; // rdi
  long long v116; // rdx
  long long v117; // rcx
  long long v118; // r8
  int v119; // eax
  char *v120; // rdi
  void *v121; // rdx
  long long v122; // rsi
  void *v123; // rdx
  unsigned int n; // [rsp+8h] [rbp-240h]
  unsigned int v125; // [rsp+10h] [rbp-238h]
  char *v126; // [rsp+18h] [rbp-230h]
  unsigned int v127; // [rsp+24h] [rbp-224h]
  int v128; // [rsp+24h] [rbp-224h]
  long long v129; // [rsp+30h] [rbp-218h]
  int v130; // [rsp+30h] [rbp-218h]
  unsigned long long v131; // [rsp+30h] [rbp-218h]
  int v132; // [rsp+38h] [rbp-210h]
  int v133; // [rsp+3Ch] [rbp-20Ch]
  int v134; // [rsp+50h] [rbp-1F8h]
  int v135; // [rsp+58h] [rbp-1F0h]
  unsigned int v136; // [rsp+64h] [rbp-1E4h] BYREF
  unsigned int v137; // [rsp+68h] [rbp-1E0h] BYREF
  unsigned int v138; // [rsp+6Ch] [rbp-1DCh] BYREF
  void *s; // [rsp+70h] [rbp-1D8h] BYREF
  long long v140; // [rsp+78h] [rbp-1D0h] BYREF
  const char *v141; // [rsp+80h] [rbp-1C8h] BYREF
  long long v142; // [rsp+88h] [rbp-1C0h] BYREF
  long long v143[2]; // [rsp+90h] [rbp-1B8h] BYREF
  __m128i v144; // [rsp+A0h] [rbp-1A8h] BYREF
  struct timeval tv; // [rsp+B0h] [rbp-198h] BYREF
  long long inode_bitmap; // [rsp+100h] [rbp-148h] BYREF
  unsigned int v147; // [rsp+108h] [rbp-140h]
  short *v148; // [rsp+118h] [rbp-130h]
  long long v149; // [rsp+150h] [rbp-F8h]
  int v150; // [rsp+170h] [rbp-D8h] BYREF
  char v151; // [rsp+174h] [rbp-D4h]
  long long v152; // [rsp+178h] [rbp-D0h]
  long long v153; // [rsp+188h] [rbp-C0h]
  long long v154; // [rsp+198h] [rbp-B0h]
  int v155; // [rsp+1A0h] [rbp-A8h]
  void *v156; // [rsp+1B0h] [rbp-98h]
  long long *p_inode_bitmap; // [rsp+1B8h] [rbp-90h]
  long long v158[9]; // [rsp+1C0h] [rbp-88h] BYREF
  unsigned long long v159; // [rsp+208h] [rbp-40h]

  v2 = *a1;
  v159 = __readfsqword(0x28u);
  v136 = 0;
  s = 0;
  v3 = *(long long *)(v2 + 32);
  v140 = 0;
  v141 = 0;
  n = 128;
  v126 = dcgettext(0, "getting next inode from scan", 5);
  v4 = *(long long *)(v2 + 32);
  if ( *(int *)(v4 + 76) )
    n = *(unsigned short *)(v4 + 88);
  v5 = *a1;
  v137 = 0;
  v138 = 0;
  v6 = *(long long *)(v5 + 8);
  init_resource_track(&tv);
  clear_problem_context(&inode_bitmap, v6, v7);
  if ( (unsigned int)e2fsck_can_readahead(*a1) )
  {
    if ( a1[115] == -1 )
      a1[115] = e2fsck_guess_readahead(*a1);
  }
  else
  {
    a1[115] = 0;
  }
  sub_1EAE0((int *)a1, &v138, &v137);
  if ( (*((char *)a1 + 76) & 2) == 0 )
    fix_problem(a1, 0x10000, &inode_bitmap);
  if ( (unsigned int)sub_21FF0(*(unsigned int *)(*(long long *)(v2 + 32) + 92LL))
    && (*((char *)a1 + 76) & 8) == 0
    && ext2fs_u32_list_create(a1 + 73, 50) )
  {
    a1[73] = 0;
  }
  for ( i = 10; i != 17; ++i )
    qword_B70F0[i] = ((1LL << ((unsigned char)i - 2))
                    + (1LL << ((unsigned char)i - 2) << ((unsigned char)i - 2))
                    + 12
                    + (1LL << ((unsigned char)i - 2) << ((unsigned char)i - 2) << ((unsigned char)i - 2))) << i;
  v127 = *(int *)(v3 + 92);
  v125 = *(int *)(v3 + 96);
  v9 = dcgettext(0, "in-use inode map", 5);
  inode_bitmap = e2fsck_allocate_inode_bitmap(v2, v9, 2, "inode_used_map", a1 + 45);
  if ( inode_bitmap )
    goto LABEL_139;
  v10 = dcgettext(0, "directory inode map", 5);
  inode_bitmap = e2fsck_allocate_inode_bitmap(v2, v10, 3, "inode_dir_map", a1 + 47);
  if ( inode_bitmap )
  {
    v149 = 2;
LABEL_137:
    fix_problem(a1, 65572, &inode_bitmap);
    *((int *)a1 + 18) |= 1u;
    return v159 - __readfsqword(0x28u);
  }
  v11 = dcgettext(0, "regular file inode map", 5);
  inode_bitmap = e2fsck_allocate_inode_bitmap(v2, v11, 2, "inode_reg_map", a1 + 50);
  if ( inode_bitmap )
  {
    v149 = 6;
    goto LABEL_137;
  }
  v12 = dcgettext(0, "in-use block map", 5);
  inode_bitmap = e2fsck_allocate_subcluster_bitmap(v2, v12);
  if ( inode_bitmap
    || (v13 = dcgettext(0, "metadata block map", 5), (inode_bitmap = e2fsck_allocate_block_bitmap(v2, v13)) != 0) )
  {
    v149 = 1;
    fix_problem(a1, 65573, &inode_bitmap);
    *((int *)a1 + 18) |= 1u;
    return v159 - __readfsqword(0x28u);
  }
  v132 = sub_1FE20(v125);
  if ( v132 )
  {
    v14 = dcgettext(0, "inode casefold map", 5);
    inode_bitmap = e2fsck_allocate_inode_bitmap(v2, v14, 2, "inode_casefold_map", a1 + 51);
    if ( inode_bitmap )
    {
LABEL_139:
      v149 = 1;
      goto LABEL_137;
    }
  }
  inode_bitmap = e2fsck_setup_icount(a1, (long long)"inode_link_info", 0, 0, a1 + 56);
  if ( inode_bitmap )
  {
    fix_problem(a1, 65574, &inode_bitmap);
    *((int *)a1 + 18) |= 1u;
    return v159 - __readfsqword(0x28u);
  }
  v15 = 160;
  if ( n >= 0xA0 )
    v15 = n;
  memory = (void *)e2fsck_allocate_memory(a1, v15, "scratch inode");
  v17 = *((int *)a1 + 150);
  s = memory;
  v18 = (void *)e2fsck_allocate_memory(a1, 184 * v17, "array of inodes to process");
  dword_B7178 = 0;
  base = v18;
  inode_bitmap = ext2fs_init_dblist(v2, 0);
  if ( inode_bitmap )
  {
    fix_problem(a1, 65575, &inode_bitmap);
    *((int *)a1 + 18) |= 1u;
    goto LABEL_145;
  }
  if ( (*((char *)a1 + 76) & 1) == 0 )
  {
    v20 = *(long long *)(v2 + 32);
    if ( *(int *)(v20 + 232) )
    {
      *(int *)(v20 + 232) = 0;
      ext2fs_mark_super_dirty(v2);
    }
  }
  sub_1E7E0(a1, 0, v19);
  inode_bitmap = ext2fs_convert_subcluster_bitmap(v2);
  if ( inode_bitmap )
  {
    fix_problem(a1, 65633, &inode_bitmap);
    *((int *)a1 + 18) |= 1u;
    goto LABEL_145;
  }
  v141 = (const char *)e2fsck_allocate_memory(a1, (unsigned int)(3 * *(int *)(v2 + 40)), "block interate buffer");
  v21 = *(long long *)(v2 + 32);
  if ( !*(int *)(v21 + 76) || *(short *)(v21 + 88) == 128 )
    e2fsck_use_inode_shortcuts((long long)a1, 1);
  e2fsck_intercept_block_allocations(a1);
  v22 = dcgettext(0, "opening inode scan", 5);
  v129 = ehandler_operation(v22);
  inode_bitmap = ext2fs_open_inode_scan(v2, *((unsigned int *)a1 + 151), &v140);
  ehandler_operation(v129);
  if ( inode_bitmap )
  {
LABEL_185:
    fix_problem(a1, &stru_10028, &inode_bitmap);
    goto LABEL_186;
  }
  ext2fs_inode_scan_flags(v140, 40, 0);
  v23 = v140;
  v143[0] = a1;
  a1[68] = (long long)s;
  v143[1] = v141;
  ext2fs_set_inode_callback(v23, sub_24270, v143);
  v24 = (unsigned int (*)(long long *, long long, long long, long long))a1[44];
  if ( v24 && v24(a1, 1, 0, *(unsigned int *)(*a1 + 48)) )
    goto LABEL_145;
  v25 = *(unsigned int **)(v2 + 32);
  v26 = v25[12];
  if ( !v26 || (v133 = 0, v26 >= *v25) )
  {
    v27 = v25[11];
    if ( !v27 || (v133 = 0, v27 >= *v25) )
    {
      v28 = v25[66];
      v133 = 1;
      if ( v28 )
        v133 = v28 >= *v25;
    }
  }
  if ( (unsigned int)sub_203A0(v25[24]) )
  {
    if ( *(long long *)(v29 + 360) > (unsigned long long)*(unsigned int *)(v29 + 20) )
    {
      v131 = *(long long *)(v29 + 360);
      if ( v131 < ext2fs_blocks_count(v29) )
        ext2fs_mark_block_bitmap2(a1[52], *(long long *)(*(long long *)(v2 + 32) + 360LL), v131, v105, v106);
    }
  }
  v134 = sub_22D10(v127, 0);
  v128 = sub_203C0(v125);
  v130 = sub_1FE30(v125, 0, v30, v31);
  e2fsck_get_lost_and_found(a1);
  while ( 1 )
  {
    while ( 1 )
    {
      if ( v136 % (4 * *(int *)(*(long long *)(v2 + 32) + 40LL)) == 1 && e2fsck_mmp_update(v2) )
        fatal_error(a1, 0);
      v32 = &v136;
      v33 = ehandler_operation(v126);
      inode_bitmap = ext2fs_get_next_inode_full(v140, &v136, s, n);
      if ( v136 > v137 )
      {
        v32 = &v138;
        sub_1EAE0((int *)a1, &v138, &v137);
      }
      ehandler_operation(v33);
      if ( (a1[9] & 3) != 0 )
        goto LABEL_145;
      v35 = inode_bitmap;
      if ( inode_bitmap == 2133571394 )
        break;
      LOBYTE(v36) = inode_bitmap != 0;
      if ( inode_bitmap != 0 && inode_bitmap != 2133571474 && inode_bitmap != 2133571497 )
        goto LABEL_185;
      if ( !v136 )
      {
        sub_240B0((long long)a1, (long long)v141);
        ext2fs_close_inode_scan(v140);
        v140 = 0;
        sub_1F030(a1);
        sub_1F0D0(a1);
        v112 = a1[57];
        if ( v112 )
        {
          sub_1F180(a1, v112, (long long)v141, -1);
          ea_refcount_free(a1[57]);
          a1[57] = 0;
        }
        v113 = (void *)a1[58];
        if ( v113 )
        {
          sub_1F180(a1, (long long)v113, (long long)v141, 1);
          ea_refcount_free(a1[58]);
          a1[58] = 0;
        }
        v114 = a1[59];
        if ( v114 )
        {
          ea_refcount_free(v114);
          a1[59] = 0;
        }
        v115 = a1[60];
        if ( v115 )
        {
          ea_refcount_free(v115);
          a1[60] = 0;
        }
        if ( *((int *)a1 + 130) )
          sub_201C0((long long)a1);
        if ( a1[54] )
        {
          ((void (*)(void))ext2fs_free_block_bitmap)();
          a1[54] = 0;
        }
        destroy_encryption_policy_map(a1);
        v119 = *((int *)a1 + 18);
        if ( (v119 & 0x400) == 0 )
        {
LABEL_334:
          if ( (v119 & 4) != 0 )
          {
            a1[11] = 0;
          }
          else
          {
            if ( *((int *)a1 + 201)
              && !(unsigned int)sub_1FE40(*(unsigned int *)(*(long long *)(v2 + 32) + 96LL), v113, v116, v117, v118) )
            {
              v113 = &loc_20039;
              if ( (unsigned int)fix_problem(a1, &loc_20039, &inode_bitmap) )
              {
                sub_1E0F0(*(long long *)(v2 + 32));
                *(int *)(v2 + 16) &= ~0x200u;
                ext2fs_mark_super_dirty(v2);
              }
              if ( !*(int *)(*(long long *)(v2 + 32) + 76LL) )
              {
                v113 = &stru_10028 + 11;
                if ( (unsigned int)fix_problem(a1, 65587, &inode_bitmap) )
                {
                  ext2fs_update_dynamic_rev(v2);
                  ext2fs_mark_super_dirty(v2);
                }
              }
            }
            if ( a1[53] )
            {
              if ( (*((char *)a1 + 76) & 2) != 0 )
              {
                clear_problem_context(&inode_bitmap, v113, v116);
                fix_problem(a1, 65556, &inode_bitmap);
              }
              e2fsck_pass1_dupblocks(a1, v141);
            }
            *((int *)a1 + 18) |= 0x8000u;
          }
          goto LABEL_145;
        }
        clear_problem_context(&inode_bitmap, v113, v116);
        inode_bitmap = ext2fs_create_resize_inode(v2);
        if ( !inode_bitmap )
        {
LABEL_358:
          e2fsck_read_inode(a1, 7, s, "recreate inode");
          v123 = s;
          v113 = &byte_7;
          *((int *)s + 4) = a1[105];
          e2fsck_write_inode(a1, 7, v123, "recreate inode");
          *((int *)a1 + 18) &= ~0x400u;
          v119 = *((int *)a1 + 18);
          goto LABEL_334;
        }
        if ( (unsigned int)fix_problem(a1, 65614, &inode_bitmap) )
        {
          inode_bitmap = 0;
          goto LABEL_358;
        }
LABEL_186:
        *((int *)a1 + 18) |= 1u;
        goto LABEL_145;
      }
      v37 = s;
      v147 = v136;
      *((int *)a1 + 134) = v136;
      v148 = v37;
      v38 = v37;
      if ( v35 == 2133571497 )
      {
        LOBYTE(v36) = 1;
        if ( v37[13] )
        {
          if ( (unsigned int)fix_problem(a1, 65639, &inode_bitmap) )
          {
            inode_bitmap = 0;
            e2fsck_clear_inode((long long)a1, v136, (long long)s, 0, (long long)"pass1");
          }
          v37 = s;
          LOBYTE(v36) = inode_bitmap != 0;
          v38 = s;
        }
      }
      v39 = *((int *)v37 + 5);
      v36 = (unsigned char)v36;
      if ( v39 )
      {
        if ( v133 && v39 < **(int **)(*a1 + 32) )
        {
          fixed = fix_problem(a1, 65590, &inode_bitmap);
          v37 = s;
          v38 = s;
          if ( fixed )
          {
            v81 = 0;
            if ( !*((short *)s + 13) )
              v81 = *((int *)a1 + 210);
            *((int *)s + 5) = v81;
            v36 = 0;
            e2fsck_write_inode(a1, v136, v37, "pass1");
            v37 = s;
            v38 = s;
          }
        }
      }
      v40 = v37[13];
      if ( v40 )
      {
        inode_bitmap = ext2fs_icount_store(a1[56], v136, v40);
        if ( inode_bitmap )
        {
          v149 = *((unsigned short *)s + 13);
          fix_problem(a1, 65578, &inode_bitmap);
          *((int *)a1 + 18) |= 1u;
          goto LABEL_145;
        }
LABEL_197:
        v37 = s;
        v38 = s;
        goto LABEL_55;
      }
      v41 = *(long long *)(v2 + 32);
      v42 = 11;
      if ( *(int *)(v41 + 76) )
        v42 = *(int *)(v41 + 84);
      if ( v42 <= v136 )
      {
        if ( !(unsigned int)sub_1EC90(v2, v136) )
        {
          if ( !*((int *)s + 5) && *(short *)s && (unsigned int)fix_problem(a1, 65540, &inode_bitmap) )
          {
            v82 = s;
            v83 = v136;
            v36 = 0;
            *((int *)s + 5) = a1[105];
            e2fsck_write_inode(a1, v83, v82, "pass1");
          }
          goto LABEL_166;
        }
        goto LABEL_197;
      }
LABEL_55:
      v43 = *((int *)v37 + 8);
      if ( (v43 & 0x40000000) != 0 )
      {
        if ( (*v37 & 0xF000) != 0x4000 && (unsigned int)fix_problem(a1, &stru_10088, &inode_bitmap)
          || !v132 && (unsigned int)fix_problem(a1, 65673, &inode_bitmap) )
        {
          v44 = s;
          v45 = v136;
          *((int *)s + 8) &= ~0x40000000u;
          e2fsck_write_inode(a1, v45, v44, "pass1");
        }
        v37 = s;
        v43 = *((int *)s + 8);
        v38 = s;
      }
      if ( (v43 & 0x10080000) != 0x10080000 )
        goto LABEL_61;
      if ( (int)sub_23210((long long)a1, v136, (long long)v37, n, (long long)&inode_bitmap) >= 0 )
      {
        v37 = s;
        v43 = *((int *)s + 8);
        v38 = s;
LABEL_61:
        if ( (v43 & 0x10000000) == 0 )
          goto LABEL_66;
        v46 = *(long long *)(v2 + 32);
        if ( v130 )
          goto LABEL_210;
        v47 = 11;
        if ( *(int *)(v46 + 76) )
          v47 = *(int *)(v46 + 84);
        if ( v136 >= v47 )
        {
          v142 = 0;
          inode_bitmap = sub_1F4A0(v2, v136, &v142, v38);
          if ( !inode_bitmap && (unsigned int)fix_problem(a1, 65647, &inode_bitmap) )
          {
            sub_1E100(v3);
            ext2fs_mark_super_dirty(v2);
            v38 = s;
            v130 = 1;
            v43 = *((int *)s + 8);
            v37 = s;
            if ( (v43 & 0x10000000) == 0 )
              goto LABEL_66;
            v46 = *(long long *)(v2 + 32);
LABEL_210:
            v84 = 11;
            if ( *(int *)(v46 + 76) )
              v84 = *(int *)(v46 + 84);
            v85 = v136;
            if ( v136 < v84 )
            {
              v43 = *((int *)v37 + 8);
              v38 = v37;
              goto LABEL_66;
            }
            v142 = 0;
            v91 = *(unsigned int *)(v2 + 16);
            if ( v36 )
              *(int *)(v2 + 16) = v91 | 0x200000;
            v135 = v91;
            v92 = sub_1F4A0(v2, v85, &v142, v91);
            *(int *)(v2 + 16) = v135 & 0x200000 | *(int *)(v2 + 16) & 0xFFDFFFFF;
            if ( v92 != 2133571418 )
            {
              if ( v92 <= 2133571418 )
              {
                if ( v92 )
                  goto LABEL_250;
LABEL_241:
                v38 = s;
                v43 = *((int *)s + 8);
                goto LABEL_66;
              }
              if ( (unsigned long long)(v92 - 2133571479) > 0x1B || (v93 = 134873025, !_bittest64(&v93, v92 - 2133571479)) )
              {
LABEL_250:
                inode_bitmap = v92;
                v100 = *((int *)a1 + 18) | 1;
                goto LABEL_251;
              }
            }
            if ( (unsigned int)fix_problem(a1, 65653, &inode_bitmap) )
            {
              v94 = ext2fs_inode_size_set(v2, s, 0);
              if ( v94 )
              {
                inode_bitmap = v94;
                v100 = *((int *)a1 + 18) | 1;
                goto LABEL_251;
              }
              v95 = s;
              v96 = 15;
              v36 = 0;
              v97 = (char *)s + 40;
              *((int *)s + 8) &= ~0x10000000u;
              v98 = v97;
              v99 = v136;
              while ( v96 )
              {
                *v98++ = 0;
                --v96;
              }
              e2fsck_write_inode(a1, v99, v95, "pass1");
            }
            goto LABEL_241;
          }
          if ( !(unsigned int)fix_problem(a1, &stru_10070, &inode_bitmap) )
          {
            v38 = s;
            v130 = 0;
            v43 = *((int *)s + 8);
            goto LABEL_66;
          }
          e2fsck_clear_inode((long long)a1, v136, (long long)s, 0, (long long)"pass1");
        }
        else
        {
LABEL_66:
          if ( (v43 & 0x80000) != 0 )
          {
            if ( v128 )
              goto LABEL_168;
            if ( !v38[13] )
            {
              v48 = v136;
              if ( v136 - 1 > 1 && v136 != 8 )
                goto LABEL_76;
            }
            if ( ext2fs_extent_header_verify(v38 + 20, 60) || !(unsigned int)fix_problem(a1, 65627, &inode_bitmap) )
            {
              if ( (unsigned int)fix_problem(a1, 65626, &inode_bitmap) )
                goto LABEL_281;
              v128 = 0;
              v48 = v136;
LABEL_75:
              if ( (int)v48 != 1 )
                goto LABEL_76;
              if ( !v36 )
              {
LABEL_155:
                v36 = 0;
                if ( !*(int *)s && !*((int *)s + 6) && (*((char *)s + 35) & 0x10) == 0 && !*((int *)s + 26) )
                  goto LABEL_161;
              }
              if ( (unsigned int)fix_problem(a1, 65637, &inode_bitmap) )
              {
                v101 = s;
                v36 = 0;
                v102 = (unsigned long long)s + 8;
                *(long long *)s = 0;
                v101[15] = 0;
                memset(
                  (void *)(v102 & 0xFFFFFFFFFFFFFFF8LL),
                  0,
                  8 * (((unsigned int)v101 - (v102 & 0xFFFFFFF8) + 128) >> 3));
                e2fsck_write_inode(a1, v136, s, "clear bad inode");
              }
LABEL_161:
              inode_bitmap = ext2fs_copy_bitmap(a1[52], v158);
              if ( inode_bitmap )
              {
                v149 = 4;
                fix_problem(a1, 65573, &inode_bitmap);
                v100 = *((int *)a1 + 18) | 1;
              }
              else
              {
                v151 &= 0xA0u;
                v153 = 0;
                v152 = 0;
                v154 = -1;
                v155 = 0;
                v150 = 1;
                v156 = s;
                p_inode_bitmap = &inode_bitmap;
                v158[1] = a1;
                inode_bitmap = ext2fs_block_iterate3(v2, v136, 0, v141, sub_20890, &v150);
                ext2fs_free_block_bitmap(v158[0]);
                if ( inode_bitmap )
                {
                  fix_problem(a1, 65577, &inode_bitmap);
                  v100 = *((int *)a1 + 18) | 1;
                }
                else
                {
                  if ( (v151 & 0x40) == 0 || (unsigned int)fix_problem(a1, 65558, &inode_bitmap) )
                  {
                    v73 = v136;
                    ext2fs_mark_inode_bitmap2(a1[45], v136);
                    clear_problem_context(&inode_bitmap, v73, v74);
                    goto LABEL_166;
                  }
                  v100 = *((int *)a1 + 18) | 1;
                }
              }
LABEL_251:
              *((int *)a1 + 18) = v100;
              goto LABEL_145;
            }
            sub_1E0E0(v3);
            ext2fs_mark_super_dirty(v2);
            v38 = s;
            if ( (*((char *)s + 34) & 8) != 0 )
            {
              v128 = 1;
              v48 = v136;
              goto LABEL_75;
            }
            v128 = 1;
          }
          else if ( !v128 )
          {
            goto LABEL_168;
          }
          if ( v38[13] || (v48 = v136, v136 - 1 <= 1) || v136 == 8 )
          {
            if ( (((*v38 & 0xF000) - 0x4000) & 0xB000) != 0
              || ext2fs_extent_header_verify(v38 + 20, 60)
              || !(unsigned int)fix_problem(a1, 65628, &inode_bitmap) )
            {
LABEL_168:
              v48 = v136;
              goto LABEL_75;
            }
            v78 = s;
            v79 = v136;
            *((int *)s + 8) |= 0x80000u;
            e2fsck_write_inode(a1, v79, v78, "pass1");
            v48 = v136;
            if ( v136 == 1 )
              goto LABEL_155;
            v36 = 0;
          }
LABEL_76:
          if ( (int)v48 == 2 )
          {
            v87 = s;
            if ( (*(short *)s & 0xF000) != 0x4000 )
            {
              if ( (unsigned int)fix_problem(a1, 65537, &inode_bitmap) )
                goto LABEL_281;
              v87 = s;
            }
            v88 = v87[13];
            if ( !*((int *)v87 + 5) )
            {
              if ( !v88 )
                goto LABEL_166;
              goto LABEL_84;
            }
            if ( !v88 )
              goto LABEL_166;
            if ( (unsigned int)fix_problem(a1, 65538, &inode_bitmap) )
            {
              v89 = s;
              v90 = v136;
              v36 = 0;
              *((int *)s + 5) = 0;
              e2fsck_write_inode(a1, v90, v89, "pass1");
            }
          }
          else if ( (int)v48 == 8 )
          {
            ext2fs_mark_inode_bitmap2(a1[45], v48);
            if ( *(int *)(*(long long *)(v2 + 32) + 224LL) == 8 )
            {
              if ( (*(short *)s & 0xF000) == 0x8000 || !(unsigned int)fix_problem(a1, 65589, &inode_bitmap) )
                goto LABEL_295;
LABEL_298:
              v111 = s;
              *(short *)s = 0x8000;
              goto LABEL_299;
            }
            if ( !*((short *)s + 13) && !*((int *)s + 7) && !*((int *)s + 10) )
              goto LABEL_166;
            if ( (unsigned int)fix_problem(a1, 65588, &inode_bitmap) )
            {
LABEL_235:
              v36 = 0;
              memset(s, 0, n);
              ext2fs_icount_store(a1[56], v136, 0);
              e2fsck_write_inode_full(a1, v136, s, n, "pass1");
            }
          }
          else
          {
            if ( !(unsigned int)sub_1EC90(v2, v48) )
            {
              v49 = *(long long *)(v2 + 32);
              v50 = 11;
              if ( *(int *)(v49 + 76) )
                v50 = *(int *)(v49 + 84);
              if ( v136 < v50 )
              {
                ext2fs_mark_inode_bitmap2(a1[45], v136);
                v110 = *(short *)s;
                if ( v136 == 5 )
                {
                  if ( (v110 & 0xF000) != 0x4000 )
                    goto LABEL_295;
                }
                else
                {
                  if ( v136 != 7 )
                  {
                    if ( v110 )
                      goto LABEL_294;
LABEL_295:
                    sub_236A0((char *)a1, (long long)&inode_bitmap, (long long)v141, 0);
                    goto LABEL_166;
                  }
                  if ( !v110 || (v110 & 0xF000) == 0x8000 )
                    goto LABEL_295;
                }
LABEL_294:
                if ( !(unsigned int)fix_problem(a1, 65539, &inode_bitmap) )
                  goto LABEL_295;
                v111 = s;
                *(short *)s = 0;
LABEL_299:
                v36 = 0;
                e2fsck_write_inode(a1, v136, v111, "pass1");
                goto LABEL_295;
              }
              goto LABEL_82;
            }
            ext2fs_mark_inode_bitmap2(a1[45], v136);
            if ( (unsigned int)sub_21FD0(*(unsigned int *)(*(long long *)(v2 + 32) + 100LL))
              && (unsigned int)sub_1E190(v107) )
            {
              if ( (*(short *)s & 0xF000) == 0x8000 || !(unsigned int)fix_problem(a1, 65634, &inode_bitmap) )
                goto LABEL_295;
              goto LABEL_298;
            }
            if ( !*((short *)s + 13) && !*((int *)s + 7) && !*((int *)s + 10) )
              goto LABEL_166;
            if ( (unsigned int)fix_problem(a1, 65635, &inode_bitmap) )
              goto LABEL_235;
          }
LABEL_82:
          if ( !*((short *)s + 13) )
            goto LABEL_166;
          if ( *((int *)s + 5) && (unsigned int)fix_problem(a1, 65541, &inode_bitmap) )
          {
            v103 = s;
            v104 = v136;
            v36 = 0;
            *((int *)s + 5) = 0;
            e2fsck_write_inode(a1, v104, v103, "pass1");
          }
LABEL_84:
          ext2fs_mark_inode_bitmap2(a1[45], v136);
          v53 = *(long long *)(v2 + 32);
          v54 = s;
          if ( *(int *)(v53 + 72) == 1 )
          {
            if ( !*((int *)s + 28)
              && !*((short *)s + 58)
              && ((unsigned int)sub_1FE40(*(unsigned int *)(v53 + 96), v53, s, *((unsigned char *)s + 117), v52)
               || (*(short *)v54 & 0xF000) != 0x4000
               || !v54[27]) )
            {
              goto LABEL_94;
            }
          }
          else if ( !*((int *)s + 28) )
          {
            v55 = *(unsigned int *)(v53 + 96);
            if ( (unsigned int)sub_1FE40(v55, v53, s, v51, v52) )
              goto LABEL_89;
            if ( (*(short *)v54 & 0xF000) != 0x4000 || !v54[27] )
            {
LABEL_88:
              v55 = *(unsigned int *)(v53 + 96);
LABEL_89:
              if ( (unsigned int)sub_203B0(v55)
                || !*(short *)(v56 + 118)
                || (sub_1E590((long long)a1, v136, v56), v53 = *(long long *)(v2 + 32), v54 = s, *(int *)(v53 + 72) != 1) )
              {
                if ( !(unsigned int)sub_21FE0(*(unsigned int *)(v53 + 100), v53) && *((short *)v54 + 58) )
                {
                  v53 = v136;
                  sub_1E590((long long)a1, v136, (long long)v54);
                  v54 = s;
                }
              }
              goto LABEL_94;
            }
          }
          sub_1E590((long long)a1, v136, (long long)v54);
          v53 = *(long long *)(v2 + 32);
          v54 = s;
          if ( *(int *)(v53 + 72) != 1 )
            goto LABEL_88;
LABEL_94:
          if ( (*((char *)v54 + 33) & 0x20) != 0 )
          {
            if ( v134 )
            {
              v57 = a1[49];
              if ( !v57 )
              {
                sub_1E4E0((long long)a1, v53, (long long)v54);
                v57 = a1[49];
              }
              ext2fs_mark_inode_bitmap2(v57, v136);
            }
            else if ( (unsigned int)fix_problem(a1, 65583, &inode_bitmap) )
            {
              v108 = s;
              v109 = v136;
              v36 = 0;
              *((int *)s + 8) &= ~0x2000u;
              e2fsck_write_inode(a1, v109, v108, "pass1");
            }
          }
          sub_1FB80(a1, (long long)&inode_bitmap, &v144);
          sub_203D0(a1, (long long)&inode_bitmap, (long long)v141);
          v59 = s;
          v60 = *((int *)s + 8);
          if ( v128 )
          {
            if ( (v60 & 0x80000) != 0 )
            {
              v58 = *(unsigned short *)s;
              LOWORD(v58) = v58 & 0xF000;
              if ( (short)v58 == 0xA000 )
              {
                if ( (unsigned int)ext2fs_inode_has_valid_blocks2(v2, s)
                  || !(unsigned int)fix_problem(a1, 65629, &inode_bitmap) )
                {
                  v59 = s;
                  v60 = *((int *)s + 8);
                }
                else
                {
                  v121 = s;
                  v122 = v136;
                  v36 = 0;
                  *((int *)s + 8) &= ~0x80000u;
                  e2fsck_write_inode(a1, v122, v121, "pass1");
                  v59 = s;
                  v60 = *((int *)s + 8);
                }
              }
            }
          }
          if ( (v60 & 0x800) == 0 )
            goto LABEL_103;
          if ( (int)add_encrypted_file(a1, &inode_bitmap) < 0 )
          {
LABEL_281:
            e2fsck_clear_inode((long long)a1, v136, (long long)s, 0, (long long)"pass1");
            if ( v136 == 1 )
              ext2fs_mark_inode_bitmap2(a1[45], 1);
          }
          else
          {
            v59 = s;
LABEL_103:
            if ( v132 && (*((char *)v59 + 35) & 0x40) != 0 )
            {
              ext2fs_mark_inode_bitmap2(a1[51], v136);
              v59 = s;
            }
            v61 = *(short *)v59 & 0xF000;
            switch ( v61 )
            {
              case 16384:
                ext2fs_mark_inode_bitmap2(a1[47], v136);
                e2fsck_add_dir_info(a1, v136, 0);
                v62 = (const __m128i *)s;
                ++*((int *)a1 + 184);
                v63 = v62[2].m128i_i32[0];
                if ( (v63 & 0x40000000) != 0 )
                {
                  sub_1ED80((long long)a1, v136);
                  v62 = (const __m128i *)s;
                  v63 = *((int *)s + 8);
                }
                goto LABEL_116;
              case -32768:
                ext2fs_mark_inode_bitmap2(a1[50], v136);
                v62 = (const __m128i *)s;
                ++*((int *)a1 + 185);
                v63 = v62[2].m128i_i32[0];
                goto LABEL_116;
              case 8192:
                if ( !(unsigned int)e2fsck_pass1_check_device_inode(v2, v59) )
                  goto LABEL_114;
                sub_1E660((long long)a1, (long long)&inode_bitmap);
                sub_1E6C0((long long)a1, (long long)&inode_bitmap);
                sub_1E720(a1, (long long)&inode_bitmap);
                v62 = (const __m128i *)s;
                ++*((int *)a1 + 187);
                v63 = v62[2].m128i_i32[0];
                goto LABEL_116;
              case 24576:
                if ( !(unsigned int)e2fsck_pass1_check_device_inode(v2, v59) )
                  goto LABEL_114;
                sub_1E660((long long)a1, (long long)&inode_bitmap);
                sub_1E6C0((long long)a1, (long long)&inode_bitmap);
                sub_1E720(a1, (long long)&inode_bitmap);
                v62 = (const __m128i *)s;
                ++*((int *)a1 + 186);
                v63 = v62[2].m128i_i32[0];
                goto LABEL_116;
              case -24576:
                if ( !(unsigned int)e2fsck_pass1_check_symlink(v2, v136, (long long)v59, v141) )
                {
                  v59 = s;
                  v61 = *(short *)s & 0xF000;
                  goto LABEL_111;
                }
                sub_1E6C0((long long)a1, (long long)&inode_bitmap);
                v120 = s;
                ++*((int *)a1 + 189);
                if ( (v120[35] & 0x10) == 0 )
                {
                  if ( !(unsigned int)ext2fs_is_fast_symlink(v120) )
                    goto LABEL_115;
                  ++*((int *)a1 + 190);
                  sub_236A0((char *)a1, (long long)&inode_bitmap, (long long)v141, v144.m128i_i64);
                }
LABEL_166:
                sub_1EFF0((long long)a1, v136, &inode_bitmap, v36);
                if ( (a1[9] & 1) != 0 )
                  return v159 - __readfsqword(0x28u);
                break;
              default:
LABEL_111:
                if ( v61 == 4096 )
                {
                  if ( !(unsigned int)e2fsck_pass1_check_device_inode(v2, v59) )
                    goto LABEL_114;
                  sub_1E660((long long)a1, (long long)&inode_bitmap);
                  sub_1E6C0((long long)a1, (long long)&inode_bitmap);
                  sub_1E720(a1, (long long)&inode_bitmap);
                  v62 = (const __m128i *)s;
                  ++*((int *)a1 + 191);
                  v63 = v62[2].m128i_i32[0];
                }
                else
                {
                  if ( v61 != -16384 || !(unsigned int)e2fsck_pass1_check_device_inode(v2, v59) )
                  {
LABEL_114:
                    sub_1E590((long long)a1, v136, v58);
LABEL_115:
                    v62 = (const __m128i *)s;
                    v63 = *((int *)s + 8);
                    goto LABEL_116;
                  }
                  sub_1E660((long long)a1, (long long)&inode_bitmap);
                  sub_1E6C0((long long)a1, (long long)&inode_bitmap);
                  sub_1E720(a1, (long long)&inode_bitmap);
                  v62 = (const __m128i *)s;
                  ++*((int *)a1 + 194);
                  v63 = v62[2].m128i_i32[0];
                }
LABEL_116:
                if ( (v63 & 0x10080000) == 0 )
                {
                  v64 = v62[5].m128i_i32[2];
                  if ( v64 )
                    ++*((int *)a1 + 195);
                  if ( v62[5].m128i_i32[3] )
                  {
                    v65 = v62[6].m128i_i32[0];
                    ++*((int *)a1 + 196);
                    if ( v65 )
LABEL_121:
                      ++*((int *)a1 + 197);
LABEL_122:
                    v66 = v136;
                    v67 = _mm_load_si128(&v144);
                    v68 = dword_B7178;
                    v69 = (char *)base + 184 * dword_B7178;
                    *(int *)v69 = v136;
                    v70 = v69 + 24;
                    *(__m128i *)(v69 + 8) = v67;
                    if ( n > 0x9F )
                    {
                      *(__m128i *)(v69 + 24) = _mm_loadu_si128(v62);
                      *(__m128i *)(v69 + 40) = _mm_loadu_si128(v62 + 1);
                      *(__m128i *)(v69 + 56) = _mm_loadu_si128(v62 + 2);
                      *(__m128i *)(v69 + 72) = _mm_loadu_si128(v62 + 3);
                      *(__m128i *)(v69 + 88) = _mm_loadu_si128(v62 + 4);
                      *(__m128i *)(v69 + 104) = _mm_loadu_si128(v62 + 5);
                      *(__m128i *)(v69 + 120) = _mm_loadu_si128(v62 + 6);
                      *(__m128i *)(v69 + 136) = _mm_loadu_si128(v62 + 7);
                      *(__m128i *)(v69 + 152) = _mm_loadu_si128(v62 + 8);
                      *(__m128i *)(v69 + 168) = _mm_loadu_si128(v62 + 9);
                    }
                    else if ( n >= 8 )
                    {
                      *((long long *)v69 + 3) = v62->m128i_i64[0];
                      *(long long *)&v70[n - 8] = *(long long *)((char *)&v62->m128i_i64[-1] + n);
                      qmemcpy(
                        (void *)((unsigned long long)(v69 + 32) & 0xFFFFFFFFFFFFFFF8LL),
                        (const void *)((char *)v62 - &v70[-((unsigned long long)(v69 + 32) & 0xFFFFFFFFFFFFFFF8LL)]),
                        8LL * ((n + (int)v70 - (((int)v69 + 32) & 0xFFFFFFF8)) >> 3));
                    }
                    else if ( (n & 4) != 0 )
                    {
                      *((int *)v69 + 6) = v62->m128i_i32[0];
                      *(int *)&v70[n - 4] = *(int *)((char *)&v62->m128i_i32[-1] + n);
                    }
                    else if ( n )
                    {
                      v69[24] = v62->m128i_i8[0];
                      if ( (n & 2) != 0 )
                        *(short *)&v70[n - 2] = *(short *)((char *)&v62->m128i_i16[-1] + n);
                    }
                    dword_B7178 = v68 + 1;
                    goto LABEL_129;
                  }
                  if ( v62[6].m128i_i32[0] )
                    goto LABEL_121;
                  if ( v64 )
                    goto LABEL_122;
                  if ( ext2fs_file_acl_block(v2, v62) )
                  {
                    v62 = (const __m128i *)s;
                    goto LABEL_122;
                  }
                }
                sub_236A0((char *)a1, (long long)&inode_bitmap, (long long)v141, v144.m128i_i64);
                v66 = v136;
LABEL_129:
                sub_1EFF0((long long)a1, v66, &inode_bitmap, v36);
                v71 = *((int *)a1 + 18);
                if ( (v71 & 1) != 0 )
                  return v159 - __readfsqword(0x28u);
                if ( (v71 & 3) != 0 )
                  goto LABEL_145;
                if ( *((int *)a1 + 150) <= dword_B7178 )
                {
                  sub_240B0((long long)a1, (long long)v141);
                  if ( (a1[9] & 3) != 0 )
                    goto LABEL_145;
                }
                break;
            }
          }
        }
      }
    }
    if ( v136 == 1 )
    {
      v32 = (int *)(&stru_10070 + 11);
      if ( (unsigned int)fix_problem(a1, 65659, &inode_bitmap) )
        break;
    }
    v75 = a1[48];
    if ( !v75 )
    {
      sub_1E430((long long)a1, (long long)v32, v34);
      v75 = a1[48];
    }
    ext2fs_mark_inode_bitmap2(v75, v136);
    ext2fs_mark_inode_bitmap2(a1[45], v136);
  }
  e2fsck_clear_inode((long long)a1, v136, (long long)s, 0, (long long)"pass1");
  ext2fs_badblocks_list_free(*(long long *)(*a1 + 136));
  v86 = *a1;
  *(long long *)(v86 + 136) = 0;
  if ( ext2fs_read_bb_inode(v86, v86 + 136) )
    goto LABEL_185;
  *((int *)a1 + 18) |= 4u;
LABEL_145:
  e2fsck_use_inode_shortcuts((long long)a1, 0);
  ext2fs_free_mem(&base);
  base = 0;
  if ( v140 )
    ext2fs_close_inode_scan(v140);
  if ( v141 )
    ext2fs_free_mem(&v141);
  if ( s )
    ext2fs_free_mem(&s);
  *((int *)a1 + 138) = 0;
  if ( (a1[9] & 3) != 0 )
  {
    ++*((int *)a1 + 130);
  }
  else
  {
    v76 = *(long long *)(*a1 + 8);
    v77 = dcgettext(0, "Pass 1", 5);
    print_resource_track(a1, v77, &tv, v76);
  }
  return v159 - __readfsqword(0x28u);
}


// Function: dict_int_cmp @ 0x263c0
long long dict_int_cmp(long long a1, int a2, int a3)
{
  return (unsigned int)(a2 - a3);
}


// Function: inode_dnode_free @ 0x263d0
unsigned long long inode_dnode_free(long long a1)
{
  long long v1; // rax
  long long v2; // rbx
  long long v4; // [rsp+8h] [rbp-40h] BYREF
  long long v5; // [rsp+18h] [rbp-30h] BYREF
  long long i; // [rsp+20h] [rbp-28h] BYREF
  unsigned long long v7; // [rsp+28h] [rbp-20h]

  v1 = *(long long *)(a1 + 40);
  v4 = a1;
  v2 = *(long long *)(v1 + 168);
  v7 = __readfsqword(0x28u);
  v5 = v1;
  for ( i = v2; v2; i = v2 )
  {
    v2 = *(long long *)(v2 + 8);
    ext2fs_free_mem(&i);
  }
  ext2fs_free_mem(&v5);
  ext2fs_free_mem(&v4);
  return v7 - __readfsqword(0x28u);
}


// Function: cluster_dnode_free @ 0x26460
unsigned long long cluster_dnode_free(long long a1)
{
  long long v1; // rax
  long long v2; // rbx
  long long v4; // [rsp+8h] [rbp-40h] BYREF
  long long v5; // [rsp+18h] [rbp-30h] BYREF
  long long i; // [rsp+20h] [rbp-28h] BYREF
  unsigned long long v7; // [rsp+28h] [rbp-20h]

  v1 = *(long long *)(a1 + 40);
  v4 = a1;
  v2 = *(long long *)(v1 + 8);
  v7 = __readfsqword(0x28u);
  v5 = v1;
  for ( i = v2; v2; i = v2 )
  {
    v2 = *(long long *)(v2 + 8);
    ext2fs_free_mem(&i);
  }
  ext2fs_free_mem(&v5);
  ext2fs_free_mem(&v4);
  return v7 - __readfsqword(0x28u);
}


// Function: search_dirent_proc @ 0x264f0
long long search_dirent_proc(int a1, int a2, unsigned int *a3, long long a4, long long a5, long long a6, int *a7)
{
  unsigned int v7; // r8d
  long long v10; // rax
  int *v11; // rdx
  int v12; // eax

  v7 = *a3;
  if ( *a3 > a7[2] )
    return 0;
  if ( v7 < a7[1] )
    return 0;
  if ( a2 <= 2 )
    return 0;
  if ( !(unsigned int)ext2fs_test_inode_bitmap2(qword_B71A0, v7) )
    return 0;
  v10 = dict_lookup(&unk_B71C0, *a3);
  if ( !v10 )
    return 0;
  v11 = *(int **)(v10 + 40);
  v12 = *a7;
  if ( !*v11 )
  {
    --v12;
    *v11 = a1;
    *a7 = v12;
  }
  return 2 * (unsigned int)(v12 == 0);
}


// Function: add_dupe @ 0x26580
long long *add_dupe(long long a1, unsigned int a2, long long a3, const __m128i *a4)
{
  long long v6; // rax
  long long v7; // rbx
  long long v8; // rax
  long long v9; // rdx
  long long v10; // rax
  long long v11; // rbx
  long long *result; // rax
  long long v13; // rdx
  long long memory; // rax
  long long v15; // rax
  __m128i v16; // xmm0
  __m128i v17; // xmm1

  v6 = dict_lookup(&unk_B7240, a3);
  if ( v6 )
  {
    v7 = *(long long *)(v6 + 40);
  }
  else
  {
    memory = e2fsck_allocate_memory(a1, 16, "duplicate cluster header");
    *(int *)memory = 0;
    v7 = memory;
    *(long long *)(memory + 8) = 0;
    dict_alloc_insert(&unk_B7240, a3, memory);
  }
  v8 = e2fsck_allocate_memory(a1, 16, "inode element");
  v9 = *(long long *)(v7 + 8);
  *(int *)v8 = a2;
  *(long long *)(v8 + 8) = v9;
  ++*(int *)v7;
  *(long long *)(v7 + 8) = v8;
  v10 = dict_lookup(&unk_B71C0, a2);
  if ( v10 )
  {
    v11 = *(long long *)(v10 + 40);
  }
  else
  {
    v15 = e2fsck_allocate_memory(a1, 176, "duplicate inode header");
    v11 = v15;
    if ( a2 == 2 )
    {
      ++dword_B72B0;
      *(int *)v15 = 2;
    }
    else
    {
      *(int *)v15 = 0;
    }
    v16 = _mm_loadu_si128(a4);
    *(int *)(v15 + 4) = 0;
    *(__m128i *)(v15 + 8) = v16;
    v17 = _mm_loadu_si128(a4 + 1);
    *(long long *)(v15 + 168) = 0;
    *(__m128i *)(v15 + 24) = v17;
    *(__m128i *)(v15 + 40) = _mm_loadu_si128(a4 + 2);
    *(__m128i *)(v15 + 56) = _mm_loadu_si128(a4 + 3);
    *(__m128i *)(v15 + 72) = _mm_loadu_si128(a4 + 4);
    *(__m128i *)(v15 + 88) = _mm_loadu_si128(a4 + 5);
    *(__m128i *)(v15 + 104) = _mm_loadu_si128(a4 + 6);
    *(__m128i *)(v15 + 120) = _mm_loadu_si128(a4 + 7);
    *(__m128i *)(v15 + 136) = _mm_loadu_si128(a4 + 8);
    *(__m128i *)(v15 + 152) = _mm_loadu_si128(a4 + 9);
    dict_alloc_insert(&unk_B71C0, a2, v15);
  }
  result = (long long *)e2fsck_allocate_memory(a1, 16, "cluster element");
  v13 = *(long long *)(v11 + 168);
  *result = a3;
  result[1] = v13;
  ++*(int *)(v11 + 4);
  *(long long *)(v11 + 168) = result;
  return result;
}


// Function: process_pass1b_block @ 0x26760
long long process_pass1b_block(long long a1, unsigned long long *a2, long long a3, long long a4, long long a5, long long a6)
{
  unsigned long long v7; // rsi
  long long v9; // r14
  int v10; // ecx
  long long v13; // r13
  long long v14; // rsi
  long long v15; // rcx
  unsigned long long v16; // rax
  long long v17; // rdx
  long long v18; // rsi
  unsigned long long v19; // [rsp+8h] [rbp-40h]

  v7 = *a2;
  if ( v7 )
  {
    v9 = *(long long *)a6;
    v10 = *(int *)(a1 + 192);
    v13 = a3 >> v10;
    v19 = v7 >> v10;
    if ( (unsigned int)ext2fs_test_block_bitmap2(*(long long *)(*(long long *)a6 + 424LL), v7) )
    {
      v14 = *(unsigned int *)(a6 + 8);
      if ( (int)v14 != 1 )
      {
        v15 = *(long long *)(a6 + 32);
        v16 = *a2;
        v17 = *(long long *)(a6 + 48);
        if ( v15 + 1 != *a2 )
        {
          if ( v15 )
          {
            v18 = 69634;
            if ( *(long long *)(v17 + 40) != *(long long *)(v17 + 48) )
              v18 = 69640;
            fix_problem(v9, v18, v17);
            v16 = *a2;
            v14 = *(unsigned int *)(a6 + 8);
            v17 = *(long long *)(a6 + 48);
          }
          *(long long *)(v17 + 40) = v16;
          v16 = *a2;
        }
        *(long long *)(v17 + 48) = v16;
        *(long long *)(a6 + 32) = v16;
      }
      ++*(int *)(a6 + 12);
      ext2fs_mark_inode_bitmap2(qword_B71A0, v14);
      if ( a3 < 0 || *(long long *)(a6 + 16) != v13 || *(long long *)(a6 + 24) != v19 )
        sub_26580(v9, *(int *)(a6 + 8), *a2 >> *(int *)(a1 + 192), *(const __m128i **)(a6 + 40));
    }
    *(long long *)(a6 + 16) = v13;
    *(long long *)(a6 + 24) = v19;
  }
  return 0;
}


// Function: pass1c @ 0x26880
unsigned long long pass1c(long long *a1, long long a2, long long a3)
{
  long long v3; // rbx
  int v4; // edx
  int *v5; // rax
  int v6; // eax
  long long v7; // rdi
  int v9[3]; // [rsp+4h] [rbp-A4h] BYREF
  char v10[104]; // [rsp+10h] [rbp-98h] BYREF
  unsigned long long v11; // [rsp+78h] [rbp-30h]

  v3 = *a1;
  v11 = __readfsqword(0x28u);
  clear_problem_context(v10, a2, a3);
  if ( (*((char *)a1 + 76) & 2) == 0 )
    fix_problem(a1, 73728, v10);
  v4 = 11;
  v9[0] = dword_B72B4 - dword_B72B0;
  v5 = *(int **)(v3 + 32);
  if ( v5[19] )
    v4 = v5[21];
  v6 = *v5;
  v7 = *(long long *)(v3 + 144);
  v9[1] = v4;
  v9[2] = v6;
  ext2fs_dblist_dir_iterate(v7, 0, a2, sub_264F0, v9);
  return v11 - __readfsqword(0x28u);
}


// Function: decrement_badcount @ 0x26b50
long long decrement_badcount(long long *a1, unsigned long long a2, int *a3)
{
  long long result; // rax
  long long v4; // rdx
  long long v5; // rcx
  long long v6; // r8

  result = (unsigned int)(*a3 - 1);
  *a3 = result;
  if ( (int)result <= 0 || (int)result == 1 && (result = sub_26A70(*a1), !(int)result) )
  {
    result = sub_26950(*a1, a2 >> *(int *)(*a1 + 192LL));
    if ( !(int)result )
      return ext2fs_unmark_block_bitmap2(a1[53], a2, v4, v5, v6);
  }
  return result;
}


// Function: deferred_dec_badcount @ 0x26bc0
long long deferred_dec_badcount(long long a1)
{
  int *v1; // rdx
  long long result; // rax

  v1 = *(int **)(a1 + 56);
  if ( v1 )
  {
    result = sub_26B50(*(long long **)(a1 + 40), *(long long *)(a1 + 64), v1);
    *(long long *)(a1 + 56) = 0;
  }
  return result;
}


// Function: delete_file_block @ 0x26bf0
long long delete_file_block(long long a1, unsigned long long *a2, long long a3, long long a4, long long a5, long long a6)
{
  unsigned long long v6; // r13
  long long *v8; // r15
  long long v10; // r12
  long long v11; // rax
  unsigned long long v12; // r13
  unsigned int v13; // eax
  int v14; // r8d
  int v15; // r9d
  int v16; // [rsp+Ch] [rbp-3Ch]

  v6 = *a2;
  if ( *a2 )
  {
    v8 = *(long long **)a6;
    v16 = *(int *)(a1 + 192);
    v10 = a3 >> v16;
    if ( (unsigned int)ext2fs_test_block_bitmap2(*(long long *)(*(long long *)a6 + 424LL), *a2) )
    {
      v11 = dict_lookup(&unk_B7240, v6 >> v16);
      if ( v11 )
      {
        if ( *(long long *)(a6 + 16) != v10 )
        {
          sub_26B50(v8, *a2, *(int **)(v11 + 40));
          ++*(int *)(a6 + 12);
        }
      }
      else
      {
        v12 = *a2;
        v13 = (unsigned int)dcgettext(0, "internal error: can't find dup_blk for %llu\n", 5);
        com_err((unsigned int)"delete_file_block", 0, v13, v12, v14, v15);
      }
    }
    else
    {
      if ( !(*a2 % (1 << *(int *)(*v8 + 192LL))) )
        ext2fs_block_alloc_stats2(a1, *a2, 0xFFFFFFFFLL);
      ++*(int *)(a6 + 12);
    }
    *(long long *)(a6 + 16) = v10;
  }
  return 0;
}


// Function: clone_file_block @ 0x26d20
long long clone_file_block(long long a1, unsigned long long *a2, long long a3, long long a4, long long a5, long long a6)
{
  long long v10; // r15
  unsigned long long v11; // rsi
  int v12; // r14d
  long long v13; // r8
  int v14; // ecx
  long long v15; // rsi
  unsigned long long v17; // rsi
  long long v18; // rax
  long long v19; // rdx
  long long v20; // rax
  long long v21; // rdi
  long long v22; // rax
  long long v23; // r8
  long long blk64; // rax
  int v25; // eax
  int v26; // ecx
  long long v27; // rdx
  long long v28; // rsi
  long long v29; // rdx
  long long v30; // rdx
  long long v31; // r8
  unsigned long long v32; // rsi
  long long v33; // rcx
  unsigned long long v34; // rax
  long long v35; // rdi
  long long v36; // rdx
  long long v37; // rcx
  long long v38; // r8
  unsigned long long v39; // r12
  unsigned int v40; // eax
  int v41; // r8d
  int v42; // r9d
  long long v43; // [rsp+8h] [rbp-60h]
  long long v44; // [rsp+8h] [rbp-60h]
  unsigned int v45; // [rsp+14h] [rbp-54h]
  long long v46; // [rsp+18h] [rbp-50h]
  long long v47[9]; // [rsp+20h] [rbp-48h] BYREF

  v10 = *(long long *)(a6 + 40);
  v47[1] = __readfsqword(0x28u);
  sub_26BC0(a6);
  v11 = *a2;
  if ( !*a2 )
    return 0;
  v12 = 1;
  if ( (unsigned int)sub_26D10(*(unsigned int *)(*(long long *)(*(long long *)v10 + 32LL) + 100LL)) )
    v12 = (*(int *)(v10 + 76) & 0x40008) != 262152;
  v14 = *(int *)(a1 + 192);
  v43 = a3 >> v14;
  v45 = sub_26950(v13, v11 >> v14);
  if ( *(long long *)(a6 + 8) == v43 )
  {
    v15 = *(long long *)(a6 + 16);
    if ( v15 )
    {
      v46 = 0;
      goto LABEL_17;
    }
  }
  if ( (unsigned int)ext2fs_test_block_bitmap2(*(long long *)(v10 + 424), *a2) )
  {
    v17 = *a2 >> *(int *)(a1 + 192);
    v18 = dict_lookup(&unk_B7240, v17);
    if ( !v18 )
    {
      v39 = *a2;
      v40 = (unsigned int)dcgettext(0, "internal error: can't find dup_blk for %llu\n", 5);
      com_err((unsigned int)"clone_file_block", 0, v40, v39, v41, v42);
      return 0;
    }
    v20 = *(long long *)(v18 + 40);
    v21 = *(long long *)(a6 + 48);
    v47[0] = 0;
    v46 = v20;
    *(long long *)(a6 + 8) = v43;
    v22 = sub_263A0(v21, v17, v19, a3, v47);
    v44 = v23;
    if ( ext2fs_map_cluster_block(a1, *(unsigned int *)(a6 + 28), v22)
      || (v15 = v47[0]) == 0
      || v47[0] >> *(int *)(*(long long *)v10 + 192LL) == *a2 >> *(int *)(*(long long *)v10 + 192LL) )
    {
      blk64 = ext2fs_new_block2(a1, 0, *(long long *)(v10 + 416), v44);
      if ( blk64 )
        goto LABEL_25;
      v25 = sub_26D10(*(unsigned int *)(*(long long *)(a1 + 32) + 100LL));
      v15 = v47[0];
      if ( v25 )
      {
        ext2fs_block_alloc_stats2(a1, v47[0], 1);
        v15 = v47[0];
      }
    }
    *(long long *)(a6 + 16) = v15;
LABEL_17:
    v26 = 1 << *(int *)(a1 + 192);
    v27 = v15 & -v26;
    v28 = *(unsigned int *)(a6 + 24);
    v29 = (a3 & (v26 - 1)) + v27;
    v47[0] = v29;
    if ( a3 < 0 || !(int)v28 || (blk64 = ext2fs_set_dir_block2(*(long long *)(a1 + 144), v28, v29, a3)) == 0 )
    {
      blk64 = io_channel_read_blk64(*(long long *)(a1 + 8), *a2, 1, *(long long *)(a6 + 32));
      if ( !blk64 )
      {
        v32 = v47[0];
        if ( !v12 )
        {
          v33 = v45;
          v34 = *a2;
          v35 = *(long long *)(v10 + 416);
          if ( !v45 )
          {
LABEL_22:
            v33 = v46;
            *(long long *)(a6 + 56) = v46;
LABEL_23:
            *(long long *)(a6 + 64) = v34;
            *a2 = v32;
            ext2fs_mark_block_bitmap2(v35, v32, v30, v33, v31);
            ext2fs_mark_block_bitmap2(*(long long *)(a1 + 88), v47[0], v36, v37, v38);
            return v12;
          }
LABEL_28:
          *(long long *)(a6 + 56) = 0;
          goto LABEL_23;
        }
        blk64 = io_channel_write_blk64(*(long long *)(a1 + 8), v47[0], 1, *(long long *)(a6 + 32));
        if ( !blk64 )
        {
          v30 = v45;
          v34 = *a2;
          v32 = v47[0];
          v35 = *(long long *)(v10 + 416);
          if ( !v45 )
            goto LABEL_22;
          goto LABEL_28;
        }
      }
    }
LABEL_25:
    *(long long *)a6 = blk64;
    return 2;
  }
  return 0;
}


// Function: clone_file @ 0x27070
long long clone_file(long long *a1, long long a2, long long a3, long long a4)
{
  int v5; // ebx
  long long v6; // rbp
  long long v7; // r13
  long long v8; // rdi
  long long mem; // r10
  long long v11; // rdx
  long long v12; // rcx
  long long v13; // r8
  long long v14; // rbp
  long long v15; // rax
  long long v16; // r10
  unsigned long long v17; // r15
  int v18; // eax
  long long v19; // rax
  long long v20; // rax
  unsigned int *v21; // r14
  long long v22; // rsi
  long long v23; // rax
  long long v24; // rdx
  long long v25; // rcx
  long long v26; // r8
  long long v27; // r12
  long long v28; // rax
  unsigned int v29; // eax
  int v30; // r8d
  int v31; // r9d
  int v32; // r12d
  unsigned int v33; // eax
  int v34; // r8d
  int v35; // r9d
  unsigned int v36; // eax
  int v37; // r8d
  int v38; // r9d
  long long v40; // [rsp+0h] [rbp-128h]
  int *v41; // [rsp+0h] [rbp-128h]
  long long v42; // [rsp+0h] [rbp-128h]
  long long *v43; // [rsp+8h] [rbp-120h]
  long long v44; // [rsp+28h] [rbp-100h] BYREF
  long long v45[3]; // [rsp+30h] [rbp-F8h] BYREF
  int v46; // [rsp+48h] [rbp-E0h]
  int v47; // [rsp+4Ch] [rbp-DCh]
  char v48[8]; // [rsp+50h] [rbp-D8h] BYREF
  long long *v49; // [rsp+58h] [rbp-D0h]
  long long v50; // [rsp+60h] [rbp-C8h]
  long long v51; // [rsp+68h] [rbp-C0h]
  long long v52; // [rsp+70h] [rbp-B8h]
  long long v53; // [rsp+80h] [rbp-A8h] BYREF
  int v54; // [rsp+88h] [rbp-A0h]
  const char *v55; // [rsp+E0h] [rbp-48h]
  unsigned long long v56; // [rsp+E8h] [rbp-40h]

  v5 = a2;
  v6 = a3 + 8;
  v7 = *a1;
  v56 = __readfsqword(0x28u);
  clear_problem_context(&v53, a2, a3);
  v8 = *(unsigned int *)(v7 + 40);
  v47 = a2;
  v45[0] = 0;
  v46 = 0;
  v45[1] = -1;
  v45[2] = 0;
  v49 = a1;
  v50 = v6;
  v51 = 0;
  v52 = 0;
  mem = ext2fs_get_mem(v8, v48);
  if ( !mem )
  {
    if ( (unsigned int)ext2fs_test_inode_bitmap2(a1[47], (unsigned int)a2) )
      v46 = a2;
    v54 = a2;
    v55 = "clone_file";
    v14 = sub_263A0(v6, (unsigned int)a2, v11, v12, v13);
    if ( (unsigned int)ext2fs_inode_has_valid_blocks2(v7, v14) )
      v53 = ext2fs_block_iterate3(v7, (unsigned int)a2, 0, a4, sub_26D20, v45);
    sub_26BC0((long long)v45);
    ext2fs_mark_bb_dirty(v7);
    if ( v53 )
    {
      fix_problem(a1, 69638, &v53);
      v16 = v53;
      goto LABEL_10;
    }
    if ( v45[0] )
    {
      v29 = (unsigned int)dcgettext(0, "returned from clone_file_block", 5);
      com_err((unsigned int)"clone_file", v45[0], (unsigned int)"%s", v29, v30, v31);
      v42 = v45[0];
      ext2fs_free_mem(v48);
      return v42;
    }
    else
    {
      e2fsck_read_inode_full(a1, (unsigned int)a2, v14, 160, "clone file EA");
      v15 = ext2fs_file_acl_block(v7, v14);
      v16 = 0;
      v44 = v15;
      v17 = v15;
      if ( v15 )
      {
        v18 = sub_26D20(v7, (unsigned long long *)&v44, -5, 0, 0, (long long)v45);
        v16 = 0;
        if ( v18 == 1 )
        {
          ext2fs_file_acl_block_set(v7, v14, v44);
          e2fsck_write_inode_full(a1, (unsigned int)a2, v14, 160, "clone file EA");
          v19 = dict_lookup(&unk_B7240, v17 >> *(int *)(v7 + 192));
          v16 = 0;
          if ( v19 )
          {
            v20 = *(long long *)(v19 + 40);
            v41 = (int *)v20;
            if ( !*(long long *)(v20 + 8) )
              goto LABEL_10;
            v21 = *(unsigned int **)(v20 + 8);
            v43 = a1;
            while ( 1 )
            {
              v22 = *v21;
              if ( (int)v22 != v5 )
              {
                v23 = dict_lookup(&unk_B71C0, v22);
                if ( !v23 )
                {
                  v32 = *v21;
                  v33 = (unsigned int)dcgettext(0, "internal error: couldn't lookup EA inode record for %u", 5);
                  com_err((unsigned int)"clone_file", 0, v33, v32, v34, v35);
                  v16 = 0;
                  goto LABEL_10;
                }
                v27 = sub_263A0(*(long long *)(v23 + 40) + 8LL, v22, v24, v25, v26);
                if ( ext2fs_file_acl_block(v7, v27) == v17 )
                {
                  v28 = ext2fs_file_acl_block(v7, v14);
                  ext2fs_file_acl_block_set(v7, v27, v28);
                  e2fsck_write_inode_full(v43, *v21, v27, 160, "clone file EA");
                  sub_26B50(v43, v17, v41);
                }
              }
              v21 = (unsigned int *)*((long long *)v21 + 1);
              if ( !v21 )
              {
                v16 = 0;
                goto LABEL_10;
              }
            }
          }
          v36 = (unsigned int)dcgettext(0, "internal error: couldn't lookup EA block record for %llu", 5);
          com_err((unsigned int)"clone_file", 0, v36, v17, v37, v38);
          v16 = 0;
        }
      }
LABEL_10:
      v40 = v16;
      ext2fs_free_mem(v48);
      return v40;
    }
  }
  return mem;
}


// Function: delete_file @ 0x274a0
unsigned long long delete_file(long long *a1, long long a2, long long a3, long long a4)
{
  long long v4; // r14
  long long v6; // r13
  long long v7; // rdx
  long long v8; // rcx
  long long v9; // r8
  long long v10; // rbp
  long long v11; // rax
  long long v12; // rdi
  long long v13; // rdi
  long long v15; // rax
  unsigned long long v16; // r10
  int v17; // eax
  unsigned long long v19; // [rsp+0h] [rbp-108h]
  int v21; // [rsp+14h] [rbp-F4h] BYREF
  long long v22; // [rsp+18h] [rbp-F0h] BYREF
  long long *v23; // [rsp+20h] [rbp-E8h] BYREF
  int v24; // [rsp+28h] [rbp-E0h]
  int v25; // [rsp+2Ch] [rbp-DCh]
  long long v26; // [rsp+30h] [rbp-D8h]
  long long v27; // [rsp+60h] [rbp-A8h] BYREF
  int v28; // [rsp+68h] [rbp-A0h]
  unsigned long long v29; // [rsp+88h] [rbp-80h]
  const char *v30; // [rsp+C0h] [rbp-48h]
  unsigned long long v31; // [rsp+C8h] [rbp-40h]

  v4 = a3 + 8;
  v6 = *a1;
  v31 = __readfsqword(0x28u);
  clear_problem_context(&v27, a2, a3);
  v24 = a2;
  v28 = a2;
  v25 = 0;
  v23 = a1;
  v30 = "delete_file";
  v26 = -1;
  v10 = sub_263A0(v4, a2, v7, v8, v9);
  if ( (unsigned int)ext2fs_inode_has_valid_blocks2(v6, v10) )
  {
    v11 = ext2fs_block_iterate3(v6, (unsigned int)a2, 8, a4, sub_26BF0, &v23);
    v27 = v11;
  }
  else
  {
    v11 = v27;
  }
  if ( v11 )
    fix_problem(a1, 69638, &v27);
  v12 = a1[46];
  if ( v12 )
    ext2fs_unmark_inode_bitmap2(v12, (unsigned int)a2);
  v13 = a1[50];
  if ( v13 )
    ext2fs_unmark_inode_bitmap2(v13, (unsigned int)a2);
  ext2fs_unmark_inode_bitmap2(a1[47], (unsigned int)a2);
  ext2fs_unmark_inode_bitmap2(a1[45], (unsigned int)a2);
  ext2fs_inode_alloc_stats2(v6, (unsigned int)a2, 0xFFFFFFFFLL, (*(short *)(a3 + 8) & 0xF000) == 0x4000);
  quota_data_sub(a1[79], v4, (unsigned int)a2, (unsigned int)(*(int *)(v6 + 40) * v25));
  quota_data_inodes(a1[79], v4, (unsigned int)a2, 0xFFFFFFFFLL);
  e2fsck_read_inode_full(a1, (unsigned int)a2, v10, 160, "delete_file");
  e2fsck_clear_inode((long long)a1, (unsigned int)a2, v10, 0, (long long)"delete_file");
  if ( ext2fs_file_acl_block(v6, v10) && (unsigned int)sub_27490(*(unsigned int *)(*(long long *)(v6 + 32) + 92LL)) )
  {
    v22 = ext2fs_file_acl_block(v6, v10);
    v21 = 1;
    v19 = v22;
    v15 = ext2fs_adjust_ea_refcount3(v6, v22, a4, 0xFFFFFFFFLL, &v21, (unsigned int)a2);
    v16 = v19;
    v27 = v15;
    if ( v15 == 2133571418 )
    {
      v27 = 0;
      v21 = 1;
    }
    else
    {
      if ( v15 )
      {
        v29 = v19;
        fix_problem(a1, 69639, &v27);
        v17 = v21;
        v16 = v19;
      }
      else
      {
        v17 = v21;
      }
      if ( !v17 )
      {
LABEL_17:
        sub_26BF0(v6, (unsigned long long *)&v22, -5, 0, 0, (long long)&v23);
        ext2fs_file_acl_block_set(v6, v10, v22);
        quota_data_sub(a1[79], v4, (unsigned int)a2, *(unsigned int *)(v6 + 40));
        return v31 - __readfsqword(0x28u);
      }
    }
    if ( !(unsigned int)ext2fs_test_block_bitmap2(a1[53], v16) )
      return v31 - __readfsqword(0x28u);
    goto LABEL_17;
  }
  return v31 - __readfsqword(0x28u);
}


// Function: pass1d @ 0x277b0
unsigned long long pass1d(long long *a1, long long a2, long long a3)
{
  long long *v3; // r12
  long long v4; // rsi
  long long v5; // rdx
  long long v6; // r8
  long long v7; // rax
  unsigned int v8; // ebp
  int v9; // r15d
  int v10; // ebx
  long long *v11; // r12
  long long v12; // rax
  long long v13; // r14
  int v14; // eax
  int v15; // edi
  unsigned int *v16; // r9
  long long v17; // rcx
  long long v18; // rax
  int v19; // edi
  int *v20; // rcx
  long long v21; // rbx
  long long v22; // r15
  long long v23; // rax
  long long v24; // rcx
  long long v25; // r8
  int *v26; // rdx
  long long v28; // rax
  int v29; // [rsp+4h] [rbp-F4h]
  long long v30; // [rsp+8h] [rbp-F0h]
  long long *v31; // [rsp+10h] [rbp-E8h]
  int v32; // [rsp+10h] [rbp-E8h]
  int v33; // [rsp+20h] [rbp-D8h]
  long long v34; // [rsp+28h] [rbp-D0h]
  long long v36; // [rsp+38h] [rbp-C0h]
  long long memory; // [rsp+48h] [rbp-B0h] BYREF
  long long v38; // [rsp+50h] [rbp-A8h] BYREF
  int v39; // [rsp+58h] [rbp-A0h]
  int v40; // [rsp+60h] [rbp-98h]
  long long v41; // [rsp+68h] [rbp-90h]
  long long v42; // [rsp+88h] [rbp-70h]
  long long v43; // [rsp+A0h] [rbp-58h]
  unsigned long long v44; // [rsp+B8h] [rbp-40h]

  v3 = a1;
  v44 = __readfsqword(0x28u);
  v36 = *a1;
  clear_problem_context(&v38, a2, a3);
  if ( (*((char *)a1 + 76) & 2) == 0 )
    fix_problem(a1, 77824, &v38);
  e2fsck_read_bitmaps(a1);
  v43 = dword_B72B4;
  fix_problem(a1, 77828, &v38);
  v4 = 4 * qword_B71F0;
  memory = e2fsck_allocate_memory(a1, 4 * qword_B71F0, "Shared inode list");
  v29 = 0;
  v30 = dict_first(&unk_B71C0);
  if ( !v30 )
    goto LABEL_38;
  do
  {
    v7 = *(long long *)(v30 + 32);
    v33 = v7;
    v8 = v7;
    if ( (int)v7 == 1 || (int)v7 == 7 )
      goto LABEL_37;
    v9 = 0;
    v10 = 1;
    v34 = *(long long *)(v30 + 40);
    if ( !*(long long *)(v34 + 168) )
      goto LABEL_24;
    v31 = v3;
    v11 = *(long long **)(*(long long *)(v30 + 40) + 168LL);
    do
    {
      v4 = *v11;
      v12 = dict_lookup(&unk_B7240, *v11);
      if ( v12 )
      {
        v13 = *(long long *)(v12 + 40);
        v4 = *v11;
        if ( *(int *)v13 >= 2 )
          v10 = 0;
        v14 = sub_26950(*v31, v4);
        v15 = 1;
        v16 = *(unsigned int **)(v13 + 8);
        if ( v14 )
          v10 = 0;
        else
          v15 = v29;
        v29 = v15;
        if ( v16 )
        {
          v17 = memory;
          do
          {
            while ( 1 )
            {
              v5 = *v16;
              if ( (int)v5 != v8 )
                break;
LABEL_21:
              v16 = (unsigned int *)*((long long *)v16 + 1);
              if ( !v16 )
                goto LABEL_22;
            }
            if ( v9 > 0 )
            {
              v4 = (unsigned int)(v9 + 1);
              v18 = 1;
              while ( (int)v5 != *(int *)(v17 + 4 * v18 - 4) )
              {
                v19 = v18++;
                if ( v4 == v18 )
                  goto LABEL_40;
              }
              goto LABEL_21;
            }
            v19 = 0;
LABEL_40:
            if ( v19 != v9 )
              goto LABEL_21;
            v16 = (unsigned int *)*((long long *)v16 + 1);
            v28 = v9++;
            *(int *)(v17 + 4 * v28) = v5;
          }
          while ( v16 );
        }
      }
LABEL_22:
      v11 = (long long *)v11[1];
    }
    while ( v11 );
    v3 = v31;
LABEL_24:
    v41 = sub_263A0(v34 + 8, v4, v5, v34, v6);
    v39 = v33;
    v40 = *v20;
    v42 = v20[1];
    if ( v29 )
    {
      v43 = v9 + 1;
      fix_problem(v3, 77825, &v38);
      v42 = 0;
      v43 = 0;
      fix_problem(v3, 77827, &v38);
    }
    else
    {
      v43 = v9;
      fix_problem(v3, 77825, &v38);
      v42 = 0;
      v43 = 0;
    }
    if ( v9 <= 0 )
    {
      if ( !v10 || !(v29 | v9) )
        goto LABEL_32;
LABEL_48:
      fix_problem(v3, 77829, &v38);
      goto LABEL_37;
    }
    v32 = v10;
    v21 = 0;
    v22 = 4LL * v9;
    do
    {
      v23 = dict_lookup(&unk_B71C0, *(unsigned int *)(memory + v21));
      if ( v23 )
      {
        v41 = sub_263A0(*(long long *)(v23 + 40) + 8LL, 77826, *(long long *)(v23 + 40), v24, v25);
        v39 = *(int *)(memory + v21);
        v40 = *v26;
        fix_problem(v3, 77826, &v38);
      }
      v21 += 4;
    }
    while ( v22 != v21 );
    if ( v32 )
      goto LABEL_48;
LABEL_32:
    if ( (*((char *)v3 + 78) & 4) == 0 && !(unsigned int)fix_problem(v3, 77830, &v38) )
      goto LABEL_34;
    v38 = sub_27070(v3, v8, v34, a2);
    if ( v38 )
    {
      fix_problem(v3, 77832, &v38);
LABEL_34:
      if ( (*((char *)v3 + 78) & 4) == 0 && (unsigned int)fix_problem(v3, 77831, &v38) )
        sub_274A0(v3, v8, v34, a2);
      else
        ext2fs_unmark_valid(v36);
    }
LABEL_37:
    v4 = v30;
    v30 = dict_next(&unk_B71C0, v30);
  }
  while ( v30 );
LABEL_38:
  ext2fs_free_mem(&memory);
  return v44 - __readfsqword(0x28u);
}


// Function: pass1b @ 0x27c30
unsigned long long pass1b(long long a1, long long a2, long long a3)
{
  long long v3; // rbx
  long long v4; // rsi
  long long v5; // rdx
  long long v6; // rcx
  long long v7; // r8
  long long v8; // rax
  long long v9; // r12
  long long next_inode_full; // rax
  long long v11; // rsi
  long long *v12; // rax
  long long v13; // rsi
  long long v14; // rax
  unsigned int v15; // edx
  unsigned int v18; // [rsp+1Ch] [rbp-1ACh] BYREF
  long long v19; // [rsp+20h] [rbp-1A8h] BYREF
  long long v20; // [rsp+28h] [rbp-1A0h] BYREF
  long long v21; // [rsp+30h] [rbp-198h] BYREF
  int v22; // [rsp+38h] [rbp-190h]
  int v23; // [rsp+3Ch] [rbp-18Ch]
  long long v24; // [rsp+40h] [rbp-188h]
  long long v25; // [rsp+48h] [rbp-180h]
  long long v26; // [rsp+50h] [rbp-178h]
  char *v27; // [rsp+58h] [rbp-170h]
  long long *v28; // [rsp+60h] [rbp-168h]
  long long v29; // [rsp+70h] [rbp-158h] BYREF
  unsigned int v30; // [rsp+78h] [rbp-150h]
  long long v31; // [rsp+98h] [rbp-130h]
  long long v32; // [rsp+A0h] [rbp-128h]
  const char *v33; // [rsp+D0h] [rbp-F8h]
  char v34[168]; // [rsp+E0h] [rbp-E8h] BYREF
  unsigned long long v35; // [rsp+188h] [rbp-40h]

  v3 = *(long long *)a1;
  v35 = __readfsqword(0x28u);
  v18 = 0;
  clear_problem_context(&v29, a2, a3);
  if ( (*(char *)(a1 + 76) & 2) == 0 )
    fix_problem(a1, &stru_11000, &v29);
  v4 = *(unsigned int *)(a1 + 604);
  v29 = ext2fs_open_inode_scan(v3, v4, &v19);
  if ( !v29 )
  {
    v8 = sub_263A0(v34, v4, v5, v6, v7);
    v21 = a1;
    *(long long *)(a1 + 544) = v8;
    v9 = v8;
    v28 = &v29;
    v33 = "pass1b";
    while ( 1 )
    {
      while ( 1 )
      {
        do
        {
          if ( v18 % (4 * *(int *)(*(long long *)(v3 + 32) + 40LL)) == 1 && e2fsck_mmp_update(v3) )
            fatal_error(a1, 0);
          next_inode_full = ext2fs_get_next_inode_full(v19, &v18, v9, 160);
          v29 = next_inode_full;
        }
        while ( next_inode_full == 2133571394 );
        v11 = v18;
        if ( next_inode_full )
        {
          v30 = v18;
          goto LABEL_33;
        }
        if ( !v18 )
        {
          ext2fs_close_inode_scan(v19);
          e2fsck_use_inode_shortcuts(a1, 0);
          return v35 - __readfsqword(0x28u);
        }
        *(int *)(a1 + 536) = v18;
        v30 = v11;
        if ( (int)v11 != 1 )
          break;
LABEL_12:
        v12 = v28;
        v27 = v34;
        v22 = v11;
        v28[6] = 0;
        v12[5] = 0;
        v23 = 0;
        v24 = -1;
        v25 = -1;
        v26 = 0;
        if ( (unsigned int)ext2fs_inode_has_valid_blocks2(v3, v9) || v18 == 1 )
        {
          v29 = ext2fs_block_iterate3(v3, v18, 8, a2, sub_26760, &v21);
          if ( !(unsigned int)sub_27490(*(unsigned int *)(*(long long *)(v3 + 32) + 92LL)) )
            goto LABEL_15;
        }
        else if ( !(unsigned int)sub_27490(*(unsigned int *)(*(long long *)(v3 + 32) + 92LL)) )
        {
          goto LABEL_15;
        }
        if ( ext2fs_file_acl_block(v3, v9) )
        {
          v20 = ext2fs_file_acl_block(v3, v9);
          sub_26760(v3, (unsigned long long *)&v20, -5, 0, 0, (long long)&v21);
          ext2fs_file_acl_block_set(v3, v9, v20);
        }
LABEL_15:
        if ( v23 )
        {
          if ( v18 != 1 )
          {
            v13 = 69634;
            if ( v31 != v32 )
              v13 = 69640;
            fix_problem(a1, v13, v28);
          }
          end_problem_latch(a1, 96);
          v14 = *(long long *)(v3 + 32);
          v15 = 11;
          if ( *(int *)(v14 + 76) )
            v15 = *(int *)(v14 + 84);
          if ( v18 == 2 || v18 >= v15 )
            ++dword_B72B4;
        }
        if ( v29 )
          fix_problem(a1, 69638, &v29);
      }
      if ( (unsigned int)ext2fs_test_inode_bitmap2(*(long long *)(a1 + 360), v11) )
      {
        LODWORD(v11) = v18;
        goto LABEL_12;
      }
    }
  }
LABEL_33:
  fix_problem(a1, 69636, &v29);
  *(int *)(a1 + 72) |= 1u;
  return v35 - __readfsqword(0x28u);
}


// Function: e2fsck_pass1_dupblocks @ 0x27f90
unsigned long long e2fsck_pass1_dupblocks(long long *a1, long long a2, long long a3)
{
  long long v3; // r13
  char *v4; // rax
  long long v5; // rdx
  long long v6; // rdx
  long long v7; // rdx
  long long v8; // r8
  long long v10; // rax
  long long v11; // r8
  char v12[8]; // [rsp+8h] [rbp-F0h] BYREF
  struct timeval tv; // [rsp+10h] [rbp-E8h] BYREF
  long long v14[13]; // [rsp+60h] [rbp-98h] BYREF
  unsigned long long v15; // [rsp+C8h] [rbp-30h]

  v3 = *a1;
  v15 = __readfsqword(0x28u);
  clear_problem_context(v14, a2, a3);
  v4 = dcgettext(0, "multiply claimed inode map", 5);
  v14[0] = e2fsck_allocate_inode_bitmap(v3, v4, 2, "inode_dup_map", &qword_B71A0);
  if ( v14[0] )
  {
    fix_problem(a1, 69637, v14);
    *((int *)a1 + 18) |= 1u;
  }
  else
  {
    dict_init(&unk_B71C0, -1, sub_263C0);
    dict_init(&unk_B7240, -1, sub_263C0);
    dict_set_allocator(&unk_B71C0, 0, sub_263D0, 0);
    dict_set_allocator(&unk_B7240, 0, sub_26460, 0);
    init_resource_track(&tv);
    sub_27C30((long long)a1, a2, v5);
    print_resource_track(a1, "Pass 1b", &tv, *(long long *)(*a1 + 8));
    init_resource_track(&tv);
    sub_26880(a1, a2, v6);
    print_resource_track(a1, "Pass 1c", &tv, *(long long *)(*a1 + 8));
    init_resource_track(&tv);
    sub_277B0(a1, a2, v7);
    print_resource_track(a1, "Pass 1d", &tv, *(long long *)(*a1 + 8));
    if ( (unsigned int)sub_26D10(*(unsigned int *)(*(long long *)(*a1 + 32) + 100LL)) )
    {
      if ( (*((char *)a1 + 78) & 4) != 0 )
      {
        v10 = ext2fs_blocks_count(v8);
        if ( (unsigned int)ext2fs_find_first_set_block_bitmap2(
                             a1[53],
                             *(unsigned int *)(*(long long *)(*a1 + 32) + 20LL),
                             v10 - 1,
                             v12) == 2
          && (*((char *)a1 + 76) & 8) == 0 )
        {
          sub_263B0(*(long long *)(*a1 + 32));
          ext2fs_mark_super_dirty(v11);
        }
      }
    }
    dict_free_nodes(&unk_B71C0);
    dict_free_nodes(&unk_B7240);
    ext2fs_free_inode_bitmap(qword_B71A0);
  }
  return v15 - __readfsqword(0x28u);
}


// Function: htree_depth @ 0x28220
long long htree_depth(long long a1, long long a2)
{
  long long result; // rax

  if ( *(int *)a2 == 1 )
    return 0;
  LODWORD(result) = 0;
  do
  {
    result = (unsigned int)(result + 1);
    a2 = *(long long *)(a1 + 16) + 48LL * *(long long *)(a2 + 16);
  }
  while ( *(int *)a2 != 1 && (short)result != 32000 );
  return result;
}


// Function: special_dir_block_cmp @ 0x28260
long long special_dir_block_cmp(int *a1, int *a2)
{
  long long v2; // rdx
  long long v3; // rcx
  long long v4; // rax
  long long v5; // r8
  long long result; // rax
  int v7; // edi
  int v8; // esi
  unsigned int v9; // edx

  v2 = *((long long *)a1 + 2);
  v3 = *((long long *)a2 + 2);
  if ( v2 )
  {
    result = 1;
    if ( !v3 )
      return result;
  }
  else if ( v3 )
  {
    return 0xFFFFFFFFLL;
  }
  v4 = *((long long *)a1 + 1);
  v5 = *((long long *)a2 + 1);
  if ( v4 != v5 )
    return (unsigned int)(v4 - v5);
  v7 = *a1;
  v8 = *a2;
  v9 = v2 - v3;
  result = (unsigned int)(v7 - v8);
  if ( v7 == v8 )
    return v9;
  return result;
}


// Function: encrypted_check_name @ 0x282c0
long long encrypted_check_name(long long *a1, long long a2, long long a3)
{
  int v4; // r8d
  long long result; // rax

  v4 = ext2fs_dirent_name_len(a2);
  result = 0;
  if ( v4 <= 15 )
  {
    if ( (unsigned int)fix_problem(a1, 131152, a3) )
    {
      return 1;
    }
    else
    {
      ext2fs_unmark_valid(*a1);
      return 0;
    }
  }
  return result;
}


// Function: check_name @ 0x28330
long long check_name(long long a1, long long a2, long long a3)
{
  unsigned int v4; // r13d
  int fixed; // r12d
  long long i; // rbx
  char v7; // al

  v4 = 0;
  fixed = -1;
  for ( i = 0; (int)ext2fs_dirent_name_len(a2) > (int)i; ++i )
  {
    v7 = *(char *)(a2 + i + 8);
    if ( v7 == 47 || !v7 )
    {
      if ( fixed < 0 )
      {
        fixed = fix_problem(a1, &loc_20008, a3);
        if ( !fixed )
          return 0;
      }
      *(char *)(a2 + i + 8) = 46;
      v4 = 1;
    }
  }
  return v4;
}


// Function: dict_de_cmp @ 0x283c0
int dict_de_cmp(long long a1, long long a2, long long a3)
{
  int v4; // ebx
  int v5; // eax

  v4 = ext2fs_dirent_name_len(a2);
  v5 = ext2fs_dirent_name_len(a3);
  if ( v4 == v5 )
    return memcmp((const void *)(a2 + 8), (const void *)(a3 + 8), v4);
  else
    return v4 - v5;
}


// Function: dict_de_cf_cmp @ 0x28410
long long dict_de_cf_cmp(long long a1, long long a2, long long a3)
{
  int v4; // r12d
  int v5; // eax

  v4 = ext2fs_dirent_name_len(a2);
  v5 = ext2fs_dirent_name_len(a3);
  return ext2fs_casefold_cmp(a1, a2 + 8, v4, a3 + 8, v5);
}


// Function: needs_encryption @ 0x28460
long long needs_encryption(long long a1, unsigned int *a2)
{
  int v2; // eax
  unsigned int v4; // ebx
  short v5[68]; // [rsp+0h] [rbp-A8h] BYREF
  unsigned long long v6; // [rsp+88h] [rbp-20h]

  v6 = __readfsqword(0x28u);
  v2 = ext2fs_dirent_file_type(a2);
  if ( v2 )
    return ((unsigned int)(v2 - 1) <= 1) | (unsigned char)(v2 == 7);
  v4 = *a2;
  if ( (unsigned int)ext2fs_test_inode_bitmap2(*(long long *)(a1 + 400), *a2)
    || (unsigned int)ext2fs_test_inode_bitmap2(*(long long *)(a1 + 376), v4) )
  {
    return 1;
  }
  e2fsck_read_inode(a1, v4, v5, "check_encryption_policy");
  return ((v5[0] & 0xD000) == 0x8000) | (unsigned char)((v5[0] & 0xF000) == 0x4000);
}


// Function: check_encryption_policy @ 0x28540
long long check_encryption_policy(long long a1, unsigned int *a2, int a3, long long a4)
{
  int encryption_policy; // eax
  long long v8; // rdx
  long long v9; // rsi
  int v11; // eax

  encryption_policy = find_encryption_policy(a1, *a2);
  if ( encryption_policy == a3 )
    return 0;
  v8 = a4;
  v9 = 131154;
  if ( encryption_policy == -1 && (v11 = sub_28460(a1, a2), v8 = a4, v9 = 131153, !v11) )
    return 0;
  else
    return fix_problem(a1, v9, v8);
}


// Function: check_encrypted_dirent @ 0x285b0
long long check_encrypted_dirent(long long *a1, unsigned int *a2, int a3, long long a4)
{
  int v6; // r8d
  long long result; // rax

  v6 = sub_282C0(a1, (long long)a2, a4);
  result = 1;
  if ( !v6 )
    return (unsigned int)sub_28540((long long)a1, a2, a3, a4) != 0;
  return result;
}


// Function: fix_inline_dir_size @ 0x28610
long long fix_inline_dir_size(long long *a1, unsigned int a2, unsigned long long *a3, long long a4, long long a5)
{
  long long v7; // r15
  unsigned long long v8; // rcx
  unsigned int v9; // eax
  unsigned long long v10; // rbx
  size_t v11; // rdx
  long long v12; // rax
  long long inode; // r8
  long long v15; // rax
  int fixed; // eax
  long long v18; // [rsp+8h] [rbp-D0h]
  long long v19; // [rsp+8h] [rbp-D0h]
  char v20[32]; // [rsp+10h] [rbp-C8h] BYREF
  int v21; // [rsp+30h] [rbp-A8h]
  unsigned long long v22; // [rsp+98h] [rbp-40h]

  v7 = *a1;
  v8 = *a3;
  v22 = __readfsqword(0x28u);
  if ( v8 > 0x3C && (v9 = sub_281F0(1, 0), (unsigned long long)v9 + 60 > v8) )
  {
    v11 = 0;
    v8 = 60;
    v10 = 60;
  }
  else
  {
    v10 = (v8 & 0xFFFFFFFFFFFFFFFCLL) + 4;
    v11 = v10 - v8;
  }
  memset((void *)(a5 + v8), 0, v11);
  v12 = ext2fs_inline_data_set(v7, a2, 0, a5, v10);
  if ( v12 == 2133571495 )
  {
    v10 -= 4LL;
    v15 = ext2fs_inline_data_set(v7, a2, 0, a5, v10);
    if ( v15 )
    {
      v19 = v15;
      fixed = fix_problem(a1, 131151, a4);
      inode = v19;
      if ( !fixed )
        return inode;
      v10 = 0;
    }
  }
  else if ( v12 )
  {
    v18 = v12;
    if ( !(unsigned int)fix_problem(a1, 131151, a4) )
      return v18;
    v10 = 0;
  }
  inode = ext2fs_read_inode(v7, a2, v20);
  if ( !inode )
  {
    inode = ext2fs_inode_size_set(v7, v20, v10);
    if ( !inode )
    {
      if ( !v10 )
        v21 &= ~0x10000000u;
      inode = ext2fs_write_inode(v7, a2, v20);
      if ( !inode )
        *a3 = v10;
    }
  }
  return inode;
}


// Function: salvage_directory @ 0x287e0
unsigned long long salvage_directory(long long a1, int *a2, long long a3, int *a4, unsigned int a5, unsigned int a6)
{
  long long v9; // rcx
  int v10; // r13d
  int v11; // edx
  long long v12; // rcx
  long long v14; // rcx
  int v16; // eax
  int v17; // r8d
  unsigned int v18; // r9d
  int v19; // eax
  unsigned int v20; // r10d
  size_t v21; // rax
  long long v22; // rbx
  int v23; // [rsp+0h] [rbp-58h]
  long long v24; // [rsp+0h] [rbp-58h]
  unsigned int v26; // [rsp+8h] [rbp-50h]
  unsigned char v27; // [rsp+Ch] [rbp-4Ch]
  int v28; // [rsp+Ch] [rbp-4Ch]
  int v29; // [rsp+10h] [rbp-48h] BYREF
  unsigned int v30; // [rsp+14h] [rbp-44h] BYREF
  unsigned long long v31; // [rsp+18h] [rbp-40h]

  v9 = (unsigned int)*a4;
  v31 = __readfsqword(0x28u);
  v10 = a5 - v9;
  if ( a5 - (unsigned int)v9 > 7 )
  {
    v27 = ext2fs_dirent_name_len(a2);
    ext2fs_get_rec_len(a1, a2, &v29);
    v10 = a5 - *a4;
    v23 = v29;
    v16 = sub_281F0(1, a6);
    v11 = v23;
    if ( v23 == 8 && v16 <= v17 )
    {
      v22 = v17;
      memmove(a2, a2 + 2, v17);
      *(long long *)((char *)a2 + v22) = 0;
      return v31 - __readfsqword(0x28u);
    }
    if ( v17 < 0 && v10 > 8 )
    {
      v19 = sub_281F0(v27, v18);
      v11 = v23;
      if ( v10 >= v19 && *a2 <= **(int **)(a1 + 32) )
      {
        v28 = v23;
        v26 = v9;
        v24 = v20;
        v21 = strnlen((const char *)a2 + 8, v20);
        v9 = v26;
        v11 = v28;
        if ( v24 == v21 )
        {
          ext2fs_set_rec_len(a1, (unsigned int)v10, a2, v26);
          return v31 - __readfsqword(0x28u);
        }
      }
    }
  }
  else
  {
    v29 = a5 - v9;
    v11 = a5 - v9;
  }
  if ( a3 )
  {
    if ( !v11 || (v11 & 3) != 0 || (int)v9 + v11 > a5 )
    {
      ext2fs_get_rec_len(a1, a3, &v30);
      v30 = v30 + a5 - *a4;
      ext2fs_set_rec_len(a1, v30, a3, v12);
      *a4 = *(int *)(a1 + 40);
    }
    else
    {
      ext2fs_get_rec_len(a1, a3, &v30);
      v30 += v29;
      ext2fs_set_rec_len(a1, v30, a3, v14);
      *a4 += v29;
    }
  }
  else
  {
    v29 = v10;
    ext2fs_set_rec_len(a1, (unsigned int)v10, a2, v9);
    ext2fs_dirent_set_name_len(a2, 0);
    ext2fs_dirent_set_file_type(a2, 0);
    *a2 = 0;
  }
  return v31 - __readfsqword(0x28u);
}


// Function: encoded_check_name @ 0x28a10
long long encoded_check_name(long long a1, long long a2, long long a3)
{
  long long v4; // rbx
  int v5; // eax
  char *v7; // rax
  long long v8; // rcx
  char *v9; // rax
  long long v10[7]; // [rsp+0h] [rbp-38h] BYREF

  v10[1] = __readfsqword(0x28u);
  v4 = (int)ext2fs_dirent_name_len(a2);
  v5 = ext2fs_check_encoded_name(*(long long *)(*(long long *)a1 + 360LL), a2 + 8, v4, v10);
  if ( v5 < 0 )
  {
    v9 = dcgettext(0, "NLS is broken.", 5);
    fatal_error(a1, v9);
  }
  if ( !v5 || !(unsigned int)fix_problem(a1, 131155, a3) )
    return (unsigned int)sub_28330(a1, a2, a3) != 0;
  v7 = (char *)v10[0];
  v8 = a2 + v4 + 8;
  if ( *(char *)v10[0] && v8 != v10[0] )
  {
    do
    {
      *v7 = 46;
      v7 = (char *)(v10[0] + 1LL);
      v10[0] = v7;
    }
    while ( *v7 && v7 != (char *)v8 );
  }
  return 1;
}


// Function: insert_dirent_tail @ 0x28b30
long long insert_dirent_tail(long long a1, unsigned long long a2)
{
  unsigned long long v2; // rbx
  int *v3; // rbp
  unsigned long long v4; // rax
  long long v5; // rax
  unsigned char v6; // al
  long long v7; // rdx
  long long v8; // rcx
  long long result; // rax

  v2 = a2;
  v3 = (int *)(a2 + *(unsigned int *)(a1 + 40) - 12);
  while ( 1 )
  {
    v5 = *(unsigned short *)(v2 + 4);
    if ( !(short)v5 )
      break;
    if ( (v5 & 3) != 0 )
      break;
    v4 = v2 + v5;
    if ( v4 > (unsigned long long)v3 )
      break;
    v2 = v4;
  }
  if ( (int *)v2 != v3 )
  {
    v6 = ext2fs_dirent_name_len(a2);
    v7 = (unsigned int)sub_281F0(v6, 0);
    result = 2133571477;
    if ( v7 > v8 )
      return result;
    *(short *)(v2 + 4) = v8;
  }
  if ( *v3 || (result = 0, v3[1] != -570425332) )
  {
    ext2fs_initialize_dirent_tail(a1, v3);
    return 0;
  }
  return result;
}


// Function: clear_htree @ 0x28bc0
unsigned long long clear_htree(long long a1, unsigned int a2)
{
  long long v2; // rdi
  char v4[32]; // [rsp+0h] [rbp-B8h] BYREF
  int v5; // [rsp+20h] [rbp-98h]
  unsigned long long v6; // [rsp+88h] [rbp-30h]

  v6 = __readfsqword(0x28u);
  e2fsck_read_inode(a1, a2, v4, "clear_htree");
  v5 &= ~0x1000u;
  e2fsck_write_inode(a1, a2, v4, "clear_htree");
  v2 = *(long long *)(a1 + 584);
  if ( v2 )
    ext2fs_u32_list_add(v2, a2);
  return v6 - __readfsqword(0x28u);
}


// Function: deallocate_inode_block @ 0x28c60
long long deallocate_inode_block(long long a1, unsigned long long *a2, long long a3, long long a4, long long a5, long long a6)
{
  unsigned long long v6; // rax
  long long v9; // rdi
  unsigned long long v10; // r13

  if ( !*a2 )
    return 0;
  v6 = *a2 >> *(int *)(a1 + 192);
  if ( *(long long *)(a6 + 16) == v6 )
    return 0;
  v9 = *(long long *)(a1 + 32);
  *(long long *)(a6 + 16) = v6;
  if ( *a2 < *(unsigned int *)(v9 + 20) )
    return 0;
  v10 = *a2;
  if ( v10 >= ext2fs_blocks_count(v9) )
    return 0;
  ext2fs_block_alloc_stats2(a1, *a2, 0xFFFFFFFFLL);
  ++*(long long *)(a6 + 8);
  return 0;
}


// Function: check_dotdot @ 0x29200
long long check_dotdot(long long *a1, unsigned int *a2, unsigned int a3, long long a4)
{
  unsigned int v7; // ecx
  long long v8; // rsi
  unsigned int v9; // r12d
  long long v12; // rsi
  long long v13; // rdi
  unsigned int v14; // [rsp+4h] [rbp-34h] BYREF
  unsigned long long v15; // [rsp+8h] [rbp-30h]

  v7 = *a2;
  v15 = __readfsqword(0x28u);
  if ( v7 )
  {
    if ( (unsigned int)ext2fs_dirent_name_len(a2) == 2 )
    {
      v13 = *a1;
      if ( *((short *)a2 + 4) == 11822 )
      {
        if ( !*((char *)a2 + 10) )
        {
          ext2fs_get_rec_len(v13, a2, &v14);
          if ( !(unsigned int)e2fsck_dir_info_set_dotdot(a1, a3, *a2) )
            return 0;
          fix_problem(a1, 131100, a4);
          return 0xFFFFFFFFLL;
        }
        ext2fs_get_rec_len(v13, a2, &v14);
        v8 = 131095;
      }
      else
      {
        ext2fs_get_rec_len(v13, a2, &v14);
        v8 = 131084;
      }
    }
    else
    {
      ext2fs_get_rec_len(*a1, a2, &v14);
      v8 = 131084;
    }
  }
  else
  {
    ext2fs_get_rec_len(*a1, a2, &v14);
    v8 = 131082;
  }
  v9 = *(int *)(*(long long *)(*a1 + 32LL) + 96LL);
  if ( !(unsigned int)fix_problem(a1, v8, a4) )
    return 0;
  if ( v14 <= 0xB )
    *((short *)a2 + 2) = 12;
  *a2 = 2;
  ext2fs_dirent_set_name_len(a2, 2);
  v12 = (unsigned int)sub_29080(v9, 0) != 0;
  ext2fs_dirent_set_file_type(a2, 2 * v12);
  strcpy((char *)a2 + 8, "..");
  return 1;
}


// Function: check_dot @ 0x29390
long long check_dot(long long *a1, int *a2, int a3, long long a4)
{
  int v8; // esi
  void *v9; // rsi
  long long v10; // rdx
  int fixed; // r14d
  unsigned int v12; // r15d
  unsigned int v13; // r12d
  long long v15; // rcx
  long long v16; // rdi
  unsigned int v17; // [rsp+Ch] [rbp-4Ch]
  unsigned int v18; // [rsp+14h] [rbp-44h] BYREF
  unsigned long long v19; // [rsp+18h] [rbp-40h]

  v8 = *a2;
  v19 = __readfsqword(0x28u);
  if ( v8 )
  {
    if ( (unsigned int)ext2fs_dirent_name_len(a2) == 1 )
    {
      v16 = *a1;
      if ( *((char *)a2 + 8) == 46 )
      {
        if ( !*((char *)a2 + 9) )
        {
          ext2fs_get_rec_len(v16, a2, &v18);
          fixed = 0;
          v17 = 2;
LABEL_4:
          v12 = fixed;
          if ( *a2 == a3 )
            goto LABEL_5;
          goto LABEL_15;
        }
        ext2fs_get_rec_len(v16, a2, &v18);
        v9 = &loc_20016;
      }
      else
      {
        ext2fs_get_rec_len(v16, a2, &v18);
        v9 = &loc_20008 + 3;
      }
    }
    else
    {
      ext2fs_get_rec_len(*a1, a2, &v18);
      v9 = &loc_20008 + 3;
    }
  }
  else
  {
    ext2fs_get_rec_len(*a1, a2, &v18);
    v9 = &loc_20008 + 1;
  }
  v17 = 2 * ((unsigned int)sub_29080(*(unsigned int *)(*(long long *)(*a1 + 32LL) + 96LL), v9) != 0);
  fixed = fix_problem(a1, v9, v10);
  if ( !fixed )
    goto LABEL_4;
  if ( v18 <= 0xB )
  {
    v18 = 12;
    *((short *)a2 + 2) = 12;
  }
  *a2 = a3;
  fixed = 1;
  v12 = 1;
  ext2fs_dirent_set_name_len(a2, 1);
  ext2fs_dirent_set_file_type(a2, v17);
  *((short *)a2 + 4) = 46;
  if ( *a2 != a3 )
  {
LABEL_15:
    if ( (unsigned int)fix_problem(a1, 131073, a4) )
    {
      *a2 = a3;
      v12 = 1;
    }
  }
LABEL_5:
  if ( v18 > 0xC )
  {
    v13 = v18 - 12;
    if ( v18 - 12 > 0xC && (fixed || (unsigned int)fix_problem(a1, 131108, a4)) )
    {
      *((short *)a2 + 2) = 12;
      if ( strncmp((const char *)a2 + 20, "..", 3u) )
      {
        ext2fs_set_rec_len(*a1, v13, a2 + 3, v15);
        a2[3] = 0;
        ext2fs_dirent_set_name_len(a2 + 3, 0);
        ext2fs_dirent_set_file_type(a2 + 3, v17);
      }
      return 1;
    }
  }
  return v12;
}


// Function: parse_int_node @ 0x29610
long long parse_int_node(long long a1, long long *a2, long long a3, long long a4, long long a5, int a6)
{
  long long v8; // rbx
  unsigned short *v9; // r13
  int v10; // r14d
  long long v11; // rdx
  unsigned long long v12; // rax
  long long v13; // rdx
  unsigned long long v14; // rbx
  long long v15; // rcx
  unsigned int v16; // eax
  unsigned int v17; // r10d
  unsigned int v18; // r9d
  unsigned int v19; // ebp
  long long v20; // rdx
  long long v21; // rbx
  long long v22; // rdi
  long long v23; // rax
  int v24; // esi
  int v25; // esi
  long long v26; // rbx
  int v27; // esi
  int v28; // edi
  int v29; // edi
  long long v30; // rdi
  long long v31; // rsi
  long long v32; // rdi
  long long v33; // rdx
  long long result; // rax
  int fixed; // eax
  long long v36; // rdi
  long long *v37; // [rsp+0h] [rbp-58h]
  unsigned short v38; // [rsp+8h] [rbp-50h]
  long long v39; // [rsp+8h] [rbp-50h]
  long long v40; // [rsp+8h] [rbp-50h]
  unsigned int v41; // [rsp+10h] [rbp-48h]
  unsigned int v42; // [rsp+10h] [rbp-48h]
  unsigned int v43; // [rsp+14h] [rbp-44h]
  unsigned int v44; // [rsp+14h] [rbp-44h]
  long long v45; // [rsp+18h] [rbp-40h]
  long long v46; // [rsp+18h] [rbp-40h]

  v37 = a2;
  if ( a2[2] )
  {
    v9 = (unsigned short *)(a5 + 8);
    v8 = 8;
    if ( a6 )
    {
      if ( (unsigned int)e2fsck_dir_will_be_rehashed(*(long long *)(a3 + 120), *(unsigned int *)(a3 + 16)) )
        goto LABEL_29;
      a2 = (long long *)(&loc_20049 + 1);
      if ( (unsigned int)fix_problem(*(long long *)(a3 + 120), 131146, a3 + 8) )
        goto LABEL_29;
    }
  }
  else
  {
    v8 = *(unsigned char *)(a5 + 29) + 24LL;
    v9 = (unsigned short *)(a5 + v8);
    if ( a6 )
    {
      if ( (unsigned int)e2fsck_dir_will_be_rehashed(*(long long *)(a3 + 120), *(unsigned int *)(a3 + 16)) )
        goto LABEL_29;
      a2 = &loc_20049;
      if ( (unsigned int)fix_problem(*(long long *)(a3 + 120), &loc_20049, a3 + 8) )
        goto LABEL_29;
    }
  }
  v10 = v9[1];
  v38 = v9[1];
  LOBYTE(v11) = (unsigned int)sub_29600(*(unsigned int *)(*(long long *)(a1 + 32) + 100LL), a2, 0) != 0;
  v12 = *(unsigned int *)(a1 + 40) - (v8 + 8 * v11);
  v13 = *v9;
  v14 = v12 >> 3;
  if ( (int)v13 == (unsigned int)(v12 >> 3) )
  {
    if ( v10 <= (int)v14 )
      goto LABEL_5;
  }
  else
  {
    *(long long *)(a3 + 88) = v13;
    if ( (unsigned int)fix_problem(*(long long *)(a3 + 120), 131133, a3 + 8) )
    {
LABEL_29:
      sub_28BC0(*(long long *)(a3 + 120), *(int *)(a3 + 16));
      v31 = *(unsigned int *)(a3 + 16);
      v32 = *(long long *)(a3 + 120);
      *(int *)(a4 + 8) = 0;
      return e2fsck_rehash_dir_later(v32, v31, v33);
    }
    if ( v10 <= (int)v14 )
      goto LABEL_5;
  }
  v36 = *(long long *)(a3 + 120);
  *(long long *)(a3 + 88) = v38;
  if ( (unsigned int)fix_problem(v36, &loc_2003E, a3 + 8) )
    goto LABEL_29;
  v10 = v14;
LABEL_5:
  if ( v10 > 0 )
  {
    v15 = 0;
    v16 = 0;
    v17 = 0;
    v18 = -1;
    v19 = 0;
    v20 = a3 + 8;
    while ( 1 )
    {
      v21 = *(int *)&v9[4 * v15 + 2] & 0xFFFFFFF;
      if ( *(int *)(a4 + 8) <= (unsigned int)v21 )
        break;
      if ( v19 < v16 )
      {
        v46 = v15;
        v44 = v17;
        v42 = v18;
        v40 = v20;
        fixed = fix_problem(*(long long *)(a3 + 120), 131135, v20);
        v20 = v40;
        v18 = v42;
        v17 = v44;
        v15 = v46;
        if ( fixed )
          goto LABEL_29;
      }
      v22 = *(long long *)(a4 + 16);
      v23 = v22 + 48 * v21;
      v24 = *(int *)(v23 + 4);
      if ( (v24 & 1) != 0 )
      {
        *(int *)(v23 + 4) = v24 | 2;
        if ( !v15 )
          goto LABEL_19;
      }
      else
      {
        *(int *)(v23 + 4) = v24 | 1;
        *(long long *)(v23 + 16) = v37[2];
        if ( !v15 )
        {
LABEL_19:
          *(int *)(v23 + 40) = v19;
          v27 = 1;
          if ( v18 > v19 )
            v18 = v19;
          *(long long *)(v23 + 24) = 0;
          if ( v17 < v19 )
            v17 = v19;
          if ( v10 > 1 )
          {
            *(int *)(v23 + 44) = *((int *)v9 + 2) & 0xFFFFFFFE;
            v29 = *(int *)(v23 + 4);
          }
          else
          {
            v28 = *(int *)(v23 + 4);
            *(int *)(v23 + 44) = -2;
            v29 = v28 | 8;
          }
          *(int *)(v23 + 4) = v29 | 4;
          goto LABEL_26;
        }
      }
      v25 = *(int *)&v9[4 * v15 - 2];
      *(int *)(v23 + 40) = v19;
      v26 = v25 & 0xFFFFFFF;
      if ( v18 > v19 )
        v18 = v19;
      v27 = v15 + 1;
      *(long long *)(v23 + 24) = v26;
      if ( v17 < v19 )
        v17 = v19;
      if ( v10 <= v27 )
      {
        *(int *)(v23 + 4) |= 8u;
        *(int *)(v23 + 44) = -2;
        goto LABEL_45;
      }
      *(int *)(v23 + 44) = *(int *)&v9[4 * v15 + 4] & 0xFFFFFFFE;
LABEL_17:
      v16 = v19;
      ++v15;
      v19 = *(int *)&v9[4 * v27] & 0xFFFFFFFE;
    }
    v30 = *(long long *)(a3 + 120);
    v45 = v15;
    *(long long *)(a3 + 48) = (unsigned int)v21;
    v43 = v17;
    v41 = v18;
    v39 = v20;
    if ( (unsigned int)fix_problem(v30, 131130, v20) )
      goto LABEL_29;
    v15 = v45;
    v20 = v39;
    v18 = v41;
    v17 = v43;
    v27 = v45 + 1;
LABEL_26:
    if ( v10 <= v27 )
    {
      v22 = *(long long *)(a4 + 16);
      goto LABEL_45;
    }
    goto LABEL_17;
  }
  v22 = *(long long *)(a4 + 16);
  v17 = 0;
  v18 = -1;
LABEL_45:
  result = v22 + 48LL * v37[2];
  *(int *)(result + 32) = v18;
  *(int *)(result + 36) = v17;
  return result;
}


// Function: e2fsck_pass2 @ 0x29cb0
unsigned long long e2fsck_pass2(long long a1)
{
  long long v2; // rbp
  long long v3; // rsi
  long long v4; // rdx
  long long v5; // rdi
  long long v6; // rax
  long long v7; // rdx
  long long v8; // rcx
  long long v9; // rax
  unsigned long long v10; // rsi
  unsigned long long v11; // rdx
  void (*v12)(long long, long long, long long, long long); // rax
  long long (*v13)(); // rsi
  long long v14; // rax
  unsigned int v15; // edx
  unsigned int *v16; // rax
  long long v17; // r14
  long long v18; // rsi
  long long v19; // rdx
  int v20; // r13d
  long long v21; // rbx
  int v22; // edx
  int v23; // eax
  int v24; // r11d
  unsigned int v25; // r12d
  unsigned int v26; // edx
  long long v27; // rax
  int v28; // eax
  unsigned int v29; // edx
  long long v30; // rax
  long long v32; // rdi
  long long v33; // rdi
  long long v34; // rdi
  long long v35; // rdx
  long long v36; // r13
  char *v37; // rax
  long long v38; // [rsp+10h] [rbp-1B8h]
  int v39; // [rsp+24h] [rbp-1A4h] BYREF
  long long memory; // [rsp+28h] [rbp-1A0h] BYREF
  struct timeval tv; // [rsp+30h] [rbp-198h] BYREF
  char v42[16]; // [rsp+80h] [rbp-148h] BYREF
  unsigned int v43; // [rsp+90h] [rbp-138h]
  long long v44; // [rsp+A8h] [rbp-120h]
  long long v45; // [rsp+B0h] [rbp-118h]
  long long v46; // [rsp+B8h] [rbp-110h]
  int v47; // [rsp+C0h] [rbp-108h]
  long long v48; // [rsp+D0h] [rbp-F8h]
  long long v49; // [rsp+F0h] [rbp-D8h] BYREF
  long long v50[13]; // [rsp+F8h] [rbp-D0h] BYREF
  int v51; // [rsp+160h] [rbp-68h]
  int v52; // [rsp+164h] [rbp-64h]
  long long v53; // [rsp+168h] [rbp-60h]
  long long v54; // [rsp+170h] [rbp-58h]
  unsigned long long v55; // [rsp+178h] [rbp-50h]
  long long v56; // [rsp+180h] [rbp-48h]
  unsigned long long v57; // [rsp+188h] [rbp-40h]

  v2 = *(long long *)a1;
  v57 = __readfsqword(0x28u);
  memory = 0;
  v3 = *(long long *)(v2 + 8);
  v38 = *(long long *)(v2 + 32);
  init_resource_track(&tv);
  clear_problem_context(v50, v3, v4);
  if ( (*(char *)(a1 + 76) & 2) == 0 )
    fix_problem(a1, 0x20000, v50);
  v50[0] = e2fsck_setup_icount((long long *)a1, (long long)"inode_count", 1u, *(long long *)(a1 + 448), (long long *)(a1 + 440));
  if ( v50[0] )
  {
    fix_problem(a1, 131102, v50);
    *(int *)(a1 + 72) |= 1u;
  }
  else
  {
    memory = e2fsck_allocate_memory(a1, (unsigned int)(2 * *(int *)(v2 + 40)), "directory scan buffer");
    e2fsck_dir_info_set_parent(a1, 2, 2);
    v5 = *(long long *)(v2 + 144);
    v53 = a1;
    v51 = 1;
    v49 = memory;
    v6 = ext2fs_dblist_count2(v5);
    v7 = *(long long *)a1;
    v54 = 0;
    v52 = v6;
    v8 = v6;
    v9 = *(long long *)(a1 + 920);
    v10 = *(unsigned int *)(v7 + 40);
    v56 = 0;
    v11 = (v9 << 10) % v10;
    v55 = (v9 << 10) / v10;
    v12 = *(void (**)(long long, long long, long long, long long))(a1 + 352);
    if ( v12 )
    {
      v10 = 2;
      v12(a1, 2, 0, (int)v8);
    }
    if ( (unsigned int)sub_299E0(*(unsigned int *)(*(long long *)(v2 + 32) + 92LL), v10, v11, v8) )
      ext2fs_dblist_sort2(*(long long *)(v2 + 144), sub_28260);
    v13 = sub_2C070;
    if ( !v55 )
      v13 = sub_2A9C0;
    v14 = ext2fs_dblist_iterate2(*(long long *)(v2 + 144), v13, &v49);
    v15 = *(int *)(a1 + 72);
    v50[0] = v14;
    if ( (v15 & 8) != 0 )
    {
      v15 = v15 & 0xFFFFFFF3 | 4;
      *(int *)(a1 + 72) = v15;
    }
    if ( (v15 & 7) == 0 )
    {
      if ( v14 )
      {
        fix_problem(a1, 131103, v50);
        *(int *)(a1 + 72) |= 1u;
      }
      else
      {
        v39 = 0;
        while ( 1 )
        {
          v16 = (unsigned int *)e2fsck_dx_dir_info_iter(a1, &v39);
          v17 = (long long)v16;
          if ( !v16 )
            break;
          if ( (*(char *)(a1 + 72) & 3) != 0 )
            goto LABEL_37;
          v18 = *v16;
          v20 = e2fsck_dir_will_be_rehashed(a1, v18);
          if ( !v20 && *(int *)(v17 + 8) )
          {
            clear_problem_context(v42, v18, v19);
            v21 = *(long long *)(v17 + 16);
            v22 = *(int *)(v21 + 4);
            v43 = *(int *)v17;
            v23 = v22 | 1;
            if ( (v22 & 1) != 0 )
              v23 = v22 | 2;
            *(int *)(v21 + 4) = v23;
            sub_28FC0(*(unsigned int *)(v17 + 8), v21, 2);
            sub_28FC0(*(unsigned int *)(v17 + 8), v21, 3);
            if ( v24 )
            {
              v25 = 0;
              do
              {
                while ( 1 )
                {
                  v46 = v25;
                  v47 = *(long long *)(v21 + 16);
                  if ( (*(char *)(v21 + 4) & 4) == 0 )
                  {
                    v29 = *(int *)(v21 + 32);
                    v30 = *(unsigned int *)(v21 + 40);
                    if ( v29 < (unsigned int)v30 )
                    {
                      v44 = v29;
                      ++v20;
                      v45 = v30;
                      fix_problem(a1, 131126, v42);
                    }
                  }
                  if ( *(int *)v21 == 2 && *(short *)(v17 + 4) != (unsigned short)sub_28220(v17, v21) )
                  {
                    ++v20;
                    v48 = *(short *)(v17 + 4);
                    fix_problem(a1, 131136, v42);
                  }
                  if ( v25 )
                  {
                    v26 = *(int *)(v21 + 36);
                    v27 = *(unsigned int *)(v21 + 44);
                    if ( v26 > (unsigned int)v27 )
                    {
                      v44 = v26;
                      ++v20;
                      v45 = v27;
                      fix_problem(a1, 131127, v42);
                    }
                  }
                  v28 = *(int *)(v21 + 4);
                  if ( (v28 & 1) != 0 )
                    break;
                  ++v20;
                  ++v25;
                  v21 += 48;
                  fix_problem(a1, &loc_20034, v42);
                  if ( *(int *)(v17 + 8) <= v25 )
                    goto LABEL_39;
                }
                if ( (v28 & 2) != 0 )
                {
                  ++v20;
                  fix_problem(a1, 131125, v42);
                }
                ++v25;
                v21 += 48;
              }
              while ( *(int *)(v17 + 8) > v25 );
LABEL_39:
              if ( v20 )
              {
                if ( (unsigned int)fix_problem(a1, 131128, v42) )
                {
                  sub_28BC0(a1, *(int *)v17);
                  *(int *)(v17 + 8) = 0;
                }
              }
            }
          }
        }
        e2fsck_free_dx_dir_info(a1);
        ext2fs_free_mem(&memory);
        ext2fs_free_dblist(*(long long *)(v2 + 144));
        v32 = *(long long *)(a1 + 368);
        if ( v32 )
        {
          ext2fs_free_inode_bitmap(v32);
          *(long long *)(a1 + 368) = 0;
        }
        v33 = *(long long *)(a1 + 400);
        if ( v33 )
        {
          ext2fs_free_inode_bitmap(v33);
          *(long long *)(a1 + 400) = 0;
        }
        v34 = *(long long *)(a1 + 408);
        if ( v34 )
        {
          ext2fs_free_inode_bitmap(v34);
          *(long long *)(a1 + 408) = 0;
        }
        destroy_encrypted_file_info(a1);
        if ( *(long long *)(a1 + 880) )
        {
          ext2fs_u32_list_free();
          *(long long *)(a1 + 880) = 0;
        }
        clear_problem_context(v42, &v39, v35);
        if ( *(int *)(a1 + 800) )
        {
          if ( !(unsigned int)sub_299D0(*(unsigned int *)(v38 + 100)) && (unsigned int)fix_problem(a1, 131123, v42) )
          {
            sub_281E0(v38);
            *(int *)(v2 + 16) &= ~0x200u;
            ext2fs_mark_super_dirty(v2);
          }
          if ( !*(int *)(v38 + 76) && (unsigned int)fix_problem(a1, 65587, v42) )
          {
            ext2fs_update_dynamic_rev(v2);
            ext2fs_mark_super_dirty(v2);
          }
        }
        v36 = *(long long *)(v2 + 8);
        v37 = dcgettext(0, "Pass 2", 5);
        print_resource_track(a1, v37, &tv, v36);
      }
    }
  }
LABEL_37:
  ext2fs_free_mem(&memory);
  return v57 - __readfsqword(0x28u);
}


// Function: e2fsck_process_bad_inode @ 0x2a2f0
long long e2fsck_process_bad_inode(long long a1, int a2, unsigned int a3, const char *a4)
{
  long long v6; // rbp
  long long v7; // rsi
  long long v8; // rdx
  long long v9; // r12
  short v10; // dx
  long long v11; // rdx
  int v12; // eax
  long long v13; // rdx
  long long v14; // rdi
  long long v16; // rdx
  void *v17; // rsi
  long long v18; // rdx
  int fixed; // [rsp+Ch] [rbp-14Ch]
  long long v20; // [rsp+10h] [rbp-148h]
  unsigned long long v22; // [rsp+18h] [rbp-140h]
  char v23[8]; // [rsp+20h] [rbp-138h] BYREF
  unsigned int v24; // [rsp+28h] [rbp-130h]
  int v25; // [rsp+30h] [rbp-128h]
  int *v26; // [rsp+38h] [rbp-120h]
  long long v27; // [rsp+70h] [rbp-E8h]
  int v28[7]; // [rsp+90h] [rbp-C8h] BYREF
  unsigned int v29; // [rsp+ACh] [rbp-ACh]
  int v30; // [rsp+FCh] [rbp-5Ch]
  int v31; // [rsp+100h] [rbp-58h]
  unsigned short v32; // [rsp+104h] [rbp-54h]
  unsigned short v33; // [rsp+106h] [rbp-52h]
  unsigned long long v34; // [rsp+118h] [rbp-40h]

  v6 = *(long long *)a1;
  v34 = __readfsqword(0x28u);
  v7 = a3;
  v20 = a3;
  e2fsck_read_inode(a1, a3, v28, "process_bad_inode");
  clear_problem_context(v23, v7, v8);
  v24 = a3;
  v25 = a2;
  v26 = v28;
  if ( ext2fs_file_acl_block(v6, v28)
    && (LODWORD(v9) = sub_299F0(*(unsigned int *)(*(long long *)(v6 + 32) + 92LL)), !(int)v9) )
  {
    fixed = fix_problem(a1, 131086, v23);
    if ( fixed )
    {
      ext2fs_file_acl_block_set(v6, v28, 0);
      fixed = 1;
    }
    else
    {
      LODWORD(v9) = 1;
    }
  }
  else
  {
    fixed = 0;
    LODWORD(v9) = 0;
  }
  v10 = v28[0] & 0xF000;
  if ( (v28[0] & 0xB000) != 0x2000 && (v28[0] & 0x7000) != 0x4000 && (v28[0] & 0xD000) != 0x8000 && v10 != 4096 )
  {
    v17 = &loc_20010 + 2;
    goto LABEL_47;
  }
  if ( v10 == 0x2000 )
  {
    if ( !(unsigned int)e2fsck_pass1_check_device_inode(v6, v28) )
    {
      v17 = &loc_20016 + 2;
      goto LABEL_47;
    }
    v10 = v28[0] & 0xF000;
  }
  if ( v10 == 24576 )
  {
    if ( !(unsigned int)e2fsck_pass1_check_device_inode(v6, v28) )
    {
      v17 = &loc_20019;
      goto LABEL_47;
    }
    v10 = v28[0] & 0xF000;
  }
  if ( v10 == 4096 )
  {
    if ( !(unsigned int)e2fsck_pass1_check_device_inode(v6, v28) )
    {
      v17 = &loc_20022 + 3;
      goto LABEL_47;
    }
    v10 = v28[0] & 0xF000;
  }
  if ( v10 != -16384 )
  {
LABEL_10:
    if ( v10 != -24576 )
      goto LABEL_11;
    v17 = &loc_2002F + 2;
    if ( (unsigned int)e2fsck_pass1_check_symlink(v6, a3, (long long)v28, a4) )
      goto LABEL_11;
    goto LABEL_47;
  }
  if ( (unsigned int)e2fsck_pass1_check_device_inode(v6, v28) )
  {
    v10 = v28[0] & 0xF000;
    goto LABEL_10;
  }
  v17 = &loc_20022 + 4;
LABEL_47:
  LODWORD(v9) = v9 + 1;
  if ( (unsigned int)fix_problem(a1, v17, v23) )
  {
    sub_29A00(a1, a3);
    return (*(char *)(a1 + 72) & 3) == 0;
  }
LABEL_11:
  if ( v31 )
  {
    if ( (unsigned int)fix_problem(a1, &loc_2000D, v23) )
    {
      ++fixed;
      v31 = 0;
    }
    else
    {
      LODWORD(v9) = v9 + 1;
    }
  }
  v11 = *(long long *)(v6 + 32);
  v12 = *(int *)(v11 + 72);
  if ( v12 == 1 )
  {
    if ( (char)v32 )
    {
      v27 = (unsigned char)v32;
      if ( (unsigned int)fix_problem(a1, &loc_20010, v23) )
      {
        ++fixed;
        LOBYTE(v32) = 0;
      }
      else
      {
        LODWORD(v9) = v9 + 1;
      }
      v27 = 0;
    }
    if ( HIBYTE(v32) )
    {
      v27 = HIBYTE(v32);
      if ( (unsigned int)fix_problem(a1, 131089, v23) )
      {
        ++fixed;
        HIBYTE(v32) = 0;
      }
      else
      {
        LODWORD(v9) = v9 + 1;
      }
      v27 = 0;
    }
    v11 = *(long long *)(v6 + 32);
    v12 = *(int *)(v11 + 72);
  }
  if ( !v12 )
  {
    if ( (unsigned int)sub_299C0(*(unsigned int *)(v11 + 100)) || !v32 )
      goto LABEL_17;
    v27 = v32;
    if ( (unsigned int)fix_problem(a1, 131140, v23) )
    {
      ++fixed;
      v32 = 0;
    }
    v13 = *(long long *)(v6 + 32);
    if ( !*(int *)(v13 + 72) )
    {
LABEL_17:
      if ( !(unsigned int)sub_29070(*(unsigned int *)(v13 + 96)) && v33 )
      {
        v27 = v33;
        if ( (unsigned int)fix_problem(a1, 131144, v23) )
        {
          ++fixed;
          v33 = 0;
        }
        else
        {
          LODWORD(v9) = v9 + 1;
        }
      }
    }
  }
  if ( ext2fs_file_acl_block(v6, v28) )
  {
    if ( ext2fs_file_acl_block(v6, v28) < (unsigned long long)*(unsigned int *)(*(long long *)(v6 + 32) + 20LL)
      || (v22 = ext2fs_file_acl_block(v6, v28), v22 >= ext2fs_blocks_count(*(long long *)(v6 + 32))) )
    {
      if ( (unsigned int)fix_problem(a1, 131122, v23) )
      {
        ext2fs_file_acl_block_set(v6, v28, 0);
        if ( v30 )
        {
          if ( !(unsigned int)sub_29040(*(unsigned int *)(*(long long *)(v6 + 32) + 96LL)) )
          {
            ++fixed;
            if ( !((unsigned long long)v29 >> (19 - *(char *)(v18 + 24))) && (v28[0] & 0xF000) == 0x4000 )
            {
LABEL_81:
              if ( (unsigned int)fix_problem(a1, 131087, v23) )
              {
                v30 = 0;
              }
              else
              {
                LODWORD(v9) = v9 + 1;
                if ( !fixed )
                {
LABEL_25:
                  LODWORD(v9) = 0;
                  return (unsigned int)v9;
                }
              }
            }
          }
        }
LABEL_40:
        e2fsck_write_inode(a1, v20, v28, "process_bad_inode");
        goto LABEL_21;
      }
      LODWORD(v9) = v9 + 1;
    }
  }
  if ( v30
    && !(unsigned int)sub_29040(*(unsigned int *)(*(long long *)(v6 + 32) + 96LL))
    && !((unsigned long long)v29 >> (19 - *(char *)(v16 + 24)))
    && (v28[0] & 0xF000) == 0x4000 )
  {
    goto LABEL_81;
  }
  if ( fixed )
    goto LABEL_40;
LABEL_21:
  if ( (int)v9 )
    goto LABEL_25;
  v14 = *(long long *)(a1 + 368);
  if ( !v14 )
    goto LABEL_25;
  ext2fs_unmark_inode_bitmap2(v14, a3);
  return (unsigned int)v9;
}


// Function: check_dir_block @ 0x2a9c0
long long check_dir_block(long long a1, long long a2, long long a3)
{
  long long v6; // rbp
  unsigned int v7; // r13d
  long long v8; // rax
  long long v9; // rdi
  long long v10; // rsi
  unsigned int (*v11)(long long, long long, long long, long long); // rax
  long long v12; // rdx
  long long v13; // rcx
  long long v14; // rdx
  unsigned int v15; // r14d
  long long v16; // rax
  long long v17; // rax
  long long v18; // rdi
  long long v19; // rdi
  char *v20; // rdi
  long long dir_block4; // rax
  unsigned long long v22; // rcx
  unsigned int v23; // eax
  unsigned long long v24; // rcx
  long long v25; // rax
  long long v26; // rsi
  long long v27; // rax
  unsigned long long v28; // rax
  int v29; // ecx
  long long v30; // rsi
  long long v31; // rdi
  int v32; // r12d
  char v33; // cl
  long long v34; // r8
  unsigned int v35; // r13d
  unsigned int *v36; // r14
  bool v37; // dl
  unsigned char v38; // al
  unsigned int v39; // r12d
  int v40; // r13d
  unsigned int *v41; // rdx
  unsigned int v42; // eax
  long long v43; // rdi
  long long v44; // rdi
  long long v45; // r12
  int v46; // r15d
  int v47; // eax
  int v48; // eax
  unsigned char v49; // r12
  unsigned int v50; // eax
  long long v51; // rdx
  unsigned long long v52; // r11
  void *v53; // rsi
  int v54; // r10d
  int v55; // r12d
  long long v56; // rax
  long long v58; // rax
  long long v59; // rdx
  char *v60; // rax
  long long v61; // rax
  unsigned int v62; // eax
  unsigned char v63; // dl
  unsigned int v64; // ecx
  unsigned char v65; // al
  unsigned long long v66; // rdx
  bool v67; // cf
  short v68; // ax
  long long v69; // r8
  unsigned int v70; // eax
  short v71; // ax
  long long v72; // r15
  int v73; // eax
  bool v74; // zf
  unsigned char v75; // dl
  short v76; // ax
  long long v77; // rdx
  int v78; // eax
  long long v79; // rdx
  long long v80; // rdx
  long long v81; // rdx
  long long v82; // rdx
  char *dest; // [rsp+0h] [rbp-388h]
  int v84; // [rsp+8h] [rbp-380h]
  unsigned long long v85; // [rsp+8h] [rbp-380h]
  int fixed; // [rsp+10h] [rbp-378h]
  unsigned long long v87; // [rsp+10h] [rbp-378h]
  unsigned int v88; // [rsp+18h] [rbp-370h]
  int v89; // [rsp+1Ch] [rbp-36Ch]
  long long v90; // [rsp+20h] [rbp-368h]
  long long v91; // [rsp+28h] [rbp-360h]
  int v92; // [rsp+28h] [rbp-360h]
  int v93; // [rsp+30h] [rbp-358h]
  unsigned char v94; // [rsp+37h] [rbp-351h]
  const char *v95; // [rsp+38h] [rbp-350h]
  long long dx_dir_info; // [rsp+40h] [rbp-348h]
  long long v97; // [rsp+50h] [rbp-338h]
  unsigned int v98; // [rsp+50h] [rbp-338h]
  unsigned int v99; // [rsp+58h] [rbp-330h]
  int v100; // [rsp+5Ch] [rbp-32Ch]
  unsigned int v101; // [rsp+60h] [rbp-328h]
  unsigned int v102; // [rsp+64h] [rbp-324h]
  int *v103; // [rsp+68h] [rbp-320h]
  int encryption_policy; // [rsp+70h] [rbp-318h]
  int has_tail; // [rsp+74h] [rbp-314h]
  int v106; // [rsp+78h] [rbp-310h]
  long long v107; // [rsp+78h] [rbp-310h]
  short v108; // [rsp+88h] [rbp-300h]
  int v109; // [rsp+8Ch] [rbp-2FCh]
  long long *v110; // [rsp+90h] [rbp-2F8h]
  int v111; // [rsp+98h] [rbp-2F0h]
  int v112; // [rsp+9Ch] [rbp-2ECh]
  unsigned short v113; // [rsp+A2h] [rbp-2E6h] BYREF
  unsigned int v114; // [rsp+A4h] [rbp-2E4h] BYREF
  unsigned int v115; // [rsp+A8h] [rbp-2E0h] BYREF
  unsigned int v116; // [rsp+ACh] [rbp-2DCh] BYREF
  unsigned long long v117; // [rsp+B0h] [rbp-2D8h] BYREF
  void *src; // [rsp+B8h] [rbp-2D0h] BYREF
  char v119[8]; // [rsp+C0h] [rbp-2C8h] BYREF
  unsigned int v120; // [rsp+C8h] [rbp-2C0h]
  unsigned int v121; // [rsp+D0h] [rbp-2B8h]
  unsigned int *v122; // [rsp+E0h] [rbp-2A8h]
  unsigned long long v123; // [rsp+110h] [rbp-278h]
  int v124[68]; // [rsp+130h] [rbp-258h] BYREF
  int v125[66]; // [rsp+240h] [rbp-148h] BYREF
  unsigned long long v126; // [rsp+348h] [rbp-40h]

  v6 = *(long long *)(a3 + 120);
  v7 = *(int *)a2;
  v126 = __readfsqword(0x28u);
  v8 = *(long long *)(a2 + 8);
  v115 = 0;
  v9 = *(long long *)(v6 + 408);
  v10 = v7;
  v117 = 0;
  v90 = v8;
  dest = *(char **)a3;
  v89 = ext2fs_test_inode_bitmap2(v9, v7);
  if ( v89 && (v89 = 1, (*(char *)(*(long long *)(*(long long *)v6 + 32LL) + 638LL) & 1) == 0) )
  {
    v89 = (*(int *)(v6 + 76) >> 20) & 1;
    v88 = *(int *)(v6 + 72) & 7;
    if ( v88 )
      return 2;
  }
  else
  {
    v88 = *(int *)(v6 + 72) & 7;
    if ( v88 )
      return 2;
  }
  v11 = *(unsigned int (**)(long long, long long, long long, long long))(v6 + 352);
  if ( v11 )
  {
    v12 = *(int *)(a3 + 112);
    v13 = *(int *)(a3 + 116);
    *(int *)(a3 + 112) = v12 + 1;
    v10 = 2;
    if ( v11(v6, 2, v12, v13) )
      return 2;
  }
  v84 = sub_29600(*(unsigned int *)(*(long long *)(a1 + 32) + 100LL), v10, *(long long *)(a1 + 32));
  if ( v84 )
  {
    fixed = 12;
    v84 = 8;
  }
  else
  {
    fixed = 0;
  }
  v15 = *(int *)(v14 + 96);
  if ( !(unsigned int)ext2fs_test_inode_bitmap2(*(long long *)(v6 + 360), v7) )
    return v88;
  *(int *)(a3 + 16) = v7;
  *(long long *)(a3 + 48) = v90;
  v16 = *(long long *)(a2 + 16);
  *(int *)(a3 + 20) = 0;
  *(long long *)(a3 + 64) = v16;
  v17 = *(long long *)(a1 + 32);
  *(long long *)(a3 + 40) = 0;
  *(long long *)(a3 + 88) = 0;
  if ( (unsigned int)sub_29030(*(unsigned int *)(v17 + 96)) )
  {
    v58 = ext2fs_inline_data_size(a1, v7, &v117);
    if ( v58 )
    {
      if ( v58 != 2133571493 )
        return 2;
    }
  }
  if ( !*(long long *)(a2 + 8) )
  {
    v18 = *(unsigned int *)(*(long long *)(a1 + 32) + 96LL);
    if ( (unsigned int)sub_29040(v18) && !(unsigned int)sub_29030(v18) )
      return v88;
    if ( !v117 )
    {
      if ( (unsigned int)sub_28CF0(v6, a2, a3 + 8) )
        return v88;
      v90 = *(long long *)(a2 + 8);
    }
  }
  v19 = *(long long *)(v6 + 584);
  v100 = 0;
  v93 = 2 * (*(long long *)(a2 + 16) != 0);
  if ( v19 )
    v100 = ext2fs_u32_list_test(v19, v7) != 0;
  v20 = domainname;
  if ( !domainname )
  {
    domainname = dcgettext(0, "reading directory block", 5);
    v20 = domainname;
  }
  ehandler_operation(v20);
  if ( v117 )
  {
    memset(dest, 0, *(unsigned int *)(a1 + 40) - v117);
    dir_block4 = ext2fs_inline_data_get(a1, v7, 0, dest, 0);
  }
  else
  {
    dir_block4 = ext2fs_read_dir_block4(a1, v90, dest, 0, v7);
  }
  v22 = v117;
  *(long long *)(a3 + 8) = dir_block4;
  v120 = v7;
  v123 = v22;
  if ( (v22 & 3) != 0 || v22 > 0x3C && (v23 = sub_281F0(1, 0), v24 < (unsigned long long)v23 + 60) )
  {
    if ( (unsigned int)fix_problem(v6, 131150, v119)
      && sub_28610((long long *)v6, v7, &v117, (long long)v119, (long long)dest) )
    {
      return 2;
    }
  }
  ehandler_operation(0);
  v25 = *(long long *)(a3 + 8);
  if ( v25 == 2133571363 )
  {
    has_tail = 0;
  }
  else
  {
    if ( v25 != 2133571478 )
    {
      if ( v25 )
      {
        if ( !(unsigned int)fix_problem(v6, 131104, a3 + 8) )
        {
          *(int *)(v6 + 72) |= 1u;
          return 2;
        }
        v26 = 0;
        if ( !*(long long *)(a2 + 16) )
          v26 = v7;
        ext2fs_new_dir_block(a1, v26, 2, &src);
        memcpy(dest, src, *(unsigned int *)(a1 + 40));
        ext2fs_free_mem(&src);
      }
      dx_dir_info = e2fsck_get_dx_dir_info(v6, v7);
      if ( !dx_dir_info )
      {
        has_tail = 0;
        v28 = v117;
        v103 = 0;
        v111 = 1;
        goto LABEL_35;
      }
      v27 = *(unsigned int *)(dx_dir_info + 8);
      if ( !(int)v27 )
      {
        has_tail = 0;
        v28 = v117;
        v111 = 1;
        v103 = 0;
        goto LABEL_35;
      }
      has_tail = 0;
      goto LABEL_130;
    }
    has_tail = 1;
  }
  *(long long *)(a3 + 8) = 0;
  dx_dir_info = e2fsck_get_dx_dir_info(v6, v7);
  if ( !dx_dir_info || (v27 = *(unsigned int *)(dx_dir_info + 8), !(int)v27) )
  {
    v103 = 0;
    v66 = v117;
    goto LABEL_143;
  }
LABEL_130:
  v59 = *(long long *)(a2 + 16);
  if ( v59 < v27 )
  {
    v61 = *(long long *)(dx_dir_info + 16) + 48 * v59;
    *(int *)v61 = 2;
    *(long long *)(v61 + 8) = v90;
    *(long long *)(v61 + 32) = 0xFFFFFFFFLL;
    v103 = (int *)v61;
    ext2fs_get_rec_len(a1, dest, &v116);
    if ( *(long long *)(a2 + 16) )
    {
      if ( !*(int *)dest && *(int *)(a1 + 40) == v116 )
      {
        v92 = *(int *)(a1 + 40);
        v111 = ext2fs_dirent_name_len(dest);
        if ( !v111 )
        {
          v29 = v92;
          if ( *((unsigned short *)dest + 4) == (unsigned int)(v92 - 8 - v84) >> 3 )
          {
            *v103 = 3;
            v28 = v117;
            if ( !v117 )
            {
              fixed = 0;
              goto LABEL_37;
            }
            goto LABEL_164;
          }
        }
      }
    }
    else
    {
      v103[1] |= 0xCu;
      *v103 = 1;
      if ( *((int *)dest + 6)
        || (unsigned char)dest[29] <= 7u
        || (v62 = sub_29050(*(long long *)(a1 + 32), dest, (unsigned char)dest[30]), v64 >= v62) )
      {
        if ( (unsigned int)fix_problem(v6, &loc_2003C, a3 + 8) )
        {
          sub_28BC0(v6, v7);
          *(int *)(dx_dir_info + 8) = 0;
          v75 = dest[28];
          *(char *)(dx_dir_info + 6) = v75;
          if ( v75 > 2u )
          {
            v76 = (unsigned char)dest[30];
          }
          else
          {
            v76 = (unsigned char)dest[30];
            if ( (*(char *)(*(long long *)(a1 + 32) + 352LL) & 2) != 0 )
            {
              v111 = 0;
              fixed = 0;
              *(char *)(dx_dir_info + 6) = v75 + 3;
              *(short *)(dx_dir_info + 4) = v76 + 1;
              v28 = v117;
              v103 = 0;
              goto LABEL_35;
            }
          }
          v111 = 0;
          fixed = 0;
          *(short *)(dx_dir_info + 4) = v76 + 1;
          v28 = v117;
          v103 = 0;
          goto LABEL_35;
        }
        v63 = dest[30];
      }
      v65 = dest[28];
      *(char *)(dx_dir_info + 6) = v65;
      if ( v65 <= 2u && (*(char *)(*(long long *)(a1 + 32) + 352LL) & 2) != 0 )
      {
        *(char *)(dx_dir_info + 6) = v65 + 3;
        *(short *)(dx_dir_info + 4) = v63 + 1;
      }
      else
      {
        *(short *)(dx_dir_info + 4) = v63 + 1;
      }
    }
    v28 = v117;
    v66 = v117;
    if ( *v103 != 2 )
    {
      v111 = 0;
      fixed = 0;
      goto LABEL_35;
    }
  }
  else
  {
    v121 = v7;
    if ( !(unsigned int)fix_problem(v6, 131141, v119) )
    {
      v60 = dcgettext(0, "Can not continue.", 5);
      fatal_error(v6, v60);
    }
    sub_28BC0(v6, v7);
    v103 = 0;
    v66 = v117;
    *(int *)(dx_dir_info + 8) = 0;
  }
LABEL_143:
  v28 = v66;
  if ( v66 || (has_tail & 1) == 0 )
  {
    v111 = 1;
  }
  else
  {
    has_tail = ext2fs_dirent_has_tail(a1, dest);
    if ( has_tail )
    {
LABEL_146:
      has_tail = 1;
      v28 = v117;
      v111 = 1;
      goto LABEL_35;
    }
    if ( !(unsigned int)e2fsck_dir_will_be_rehashed(v6, v7) )
    {
      fixed = fix_problem(*(long long *)(a3 + 120), &loc_2004C, a3 + 8);
      if ( !fixed )
        goto LABEL_146;
      e2fsck_rehash_dir_later(v6, v7, v81);
    }
    fixed = 0;
    v28 = v117;
    v111 = 1;
  }
LABEL_35:
  if ( !v28 )
  {
    v29 = *(int *)(a1 + 40);
LABEL_37:
    v87 = (unsigned int)(v29 - fixed);
    v95 = dest;
    goto LABEL_38;
  }
  if ( !*(long long *)(a2 + 16) )
  {
    v87 = 60;
    v95 = dest;
    goto LABEL_38;
  }
LABEL_164:
  v87 = v28 - 60;
  if ( v28 == 60 )
    return v88;
  v95 = dest + 60;
LABEL_38:
  encryption_policy = find_encryption_policy(v6, v7);
  if ( !v89 )
  {
    v30 = -1;
    dict_init(&unk_B72C0, -1, sub_283C0);
    v31 = *(long long *)(v6 + 880);
    if ( v31 )
      goto LABEL_40;
LABEL_170:
    v102 = 0;
    v94 = 0;
    goto LABEL_41;
  }
  dict_init(&unk_B72C0, -1, sub_28410);
  v30 = *(long long *)(*(long long *)v6 + 360LL);
  dict_set_cmp_context(&unk_B72C0, v30);
  v31 = *(long long *)(v6 + 880);
  if ( !v31 )
    goto LABEL_170;
LABEL_40:
  v30 = v7;
  v94 = (encryption_policy != -1) & ((unsigned int)ext2fs_u32_list_test(v31, v7) != 0);
  v102 = v94;
LABEL_41:
  v99 = 0;
  v101 = v7;
  v91 = a1;
  v110 = (long long *)a2;
  v32 = 0;
  v109 = 0;
  v108 = ((unsigned int)sub_29080(v15, v30) != 0) << 9;
  v97 = 0;
  do
  {
    v35 = sub_281F0(1, (v93 > 1) & v94);
    if ( v117 && !v33 )
    {
      if ( v93 )
      {
        memset(v125, 0, sizeof(v125));
        v125[0] = *(int *)v95;
        v68 = sub_281F0(2, 0);
        v36 = v125;
        LOWORD(v125[2]) = 11822;
        LOWORD(v125[1]) = v68;
        HIWORD(v125[1]) = v108 | 2;
      }
      else
      {
        v36 = v124;
        memset(v124, 0, 0x108u);
        v124[0] = v101;
        v71 = sub_281F0(1, 0);
        LOBYTE(v124[2]) = 46;
        LOWORD(v124[1]) = v71;
        HIWORD(v124[1]) = v108 | 1;
      }
      *(long long *)(a3 + 40) = v36;
      *(long long *)(a3 + 88) = v69;
LABEL_50:
      if ( v93 )
      {
        if ( v93 != 1 )
        {
          v98 = 0;
          v39 = *v36;
          if ( *v36 == v101 )
          {
            if ( (unsigned int)fix_problem(v6, 131076, a3 + 8) )
              goto LABEL_171;
            v98 = 131076;
            v39 = *v36;
          }
          goto LABEL_53;
        }
        v73 = sub_29200((long long *)v6, v36, v101, a3 + 8);
        v74 = v73 == 0;
        if ( v73 < 0 )
          goto LABEL_160;
        v70 = *v36;
        v39 = *v36;
        if ( !v74 )
        {
          ++v99;
          goto LABEL_178;
        }
        v98 = 0;
      }
      else
      {
        if ( (unsigned int)sub_29390((long long *)v6, (int *)v36, v101, a3 + 8) )
        {
          ++v99;
          v70 = *v36;
LABEL_178:
          v39 = v70;
          if ( !v70 )
            goto LABEL_172;
          v98 = 0;
LABEL_54:
          v40 = ext2fs_dirent_name_len(v36);
          v41 = *(unsigned int **)(v91 + 32);
          if ( v39 != 2 )
          {
            v42 = 11;
            if ( v41[19] )
              v42 = v41[21];
            if ( v42 > v39 )
              goto LABEL_261;
          }
          if ( *v41 < v39 || v41[144] == v39 || v41[145] == v39 || v41[155] == v39 )
          {
LABEL_261:
            if ( !(unsigned int)fix_problem(v6, 131074, a3 + 8) )
            {
              ext2fs_unmark_valid(v91);
              goto LABEL_93;
            }
            goto LABEL_171;
          }
          v43 = *(long long *)(v6 + 384);
          if ( v43 && (unsigned int)ext2fs_test_inode_bitmap2(v43, v39) )
          {
            v98 = 131077;
            goto LABEL_65;
          }
          if ( v40 == 1 && v93 > 1 )
          {
            if ( *((char *)v36 + 8) == 46 )
            {
              v98 = 131098;
              goto LABEL_65;
            }
          }
          else
          {
            if ( v40 != 2 || v93 <= 1 )
            {
              if ( v93 > 1 )
              {
                if ( *v36 == 2 )
                  goto LABEL_228;
                if ( !v40 )
                {
                  v98 = 131120;
                  goto LABEL_65;
                }
              }
LABEL_246:
              if ( !v98 )
                goto LABEL_67;
              v98 = 131076;
LABEL_65:
              if ( (unsigned int)fix_problem(v6, v98, a3 + 8) )
                goto LABEL_171;
              ext2fs_unmark_valid(v91);
LABEL_67:
              v44 = *(long long *)(v6 + 368);
              if ( v44 && (unsigned int)ext2fs_test_inode_bitmap2(v44, *v36) )
              {
                if ( (unsigned int)e2fsck_process_bad_inode(v6, v101, *v36, &v95[*(unsigned int *)(v91 + 40)]) )
                  goto LABEL_171;
                if ( (*(char *)(v6 + 72) & 3) != 0 )
                  return 2;
              }
              v45 = (unsigned int)ext2fs_group_of_ino(v91, *v36);
              v46 = *(int *)(*(long long *)(v91 + 32) + 40LL);
              v47 = ext2fs_bg_itable_unused(v91, v45);
              *(int *)(a3 + 72) = v45;
              v106 = v47;
              if ( (unsigned int)ext2fs_bg_flags_test(v91, (unsigned int)v45, 1) )
              {
                v123 = *v36;
                if ( (unsigned int)fix_problem(v6, 131142, a3 + 8) )
                {
                  v72 = v91;
                  ext2fs_bg_flags_clear(v91, (unsigned int)v45, 1);
LABEL_189:
                  ext2fs_group_desc_csum_set(v72, (unsigned int)v45);
                  ext2fs_mark_super_dirty(v72);
                  *(int *)(v6 + 72) |= 8u;
                  goto LABEL_190;
                }
              }
              else
              {
                if ( *v36 < v46 * ((int)v45 + 1) - v106 + 1 )
                {
LABEL_71:
                  if ( (*(int *)(v6 + 72) & 8) == 0
                    && !(unsigned int)ext2fs_test_inode_bitmap2(*(long long *)(v6 + 360), *v36) )
                  {
                    v98 = (unsigned int)&loc_20003;
                    goto LABEL_74;
                  }
LABEL_190:
                  if ( !v98 )
                  {
LABEL_76:
                    v99 -= ((unsigned int)sub_29090(v6, v36, a3 + 8) == 0) - 1;
                    if ( encryption_policy == -1 )
                    {
                      v77 = a3 + 8;
                      if ( v89 )
                        v99 -= !sub_28A10(v6, (long long)v36, v77) - 1;
                      else
                        v99 -= ((unsigned int)sub_28330(v6, (long long)v36, v77) == 0) - 1;
                      if ( !v103 )
                        goto LABEL_88;
                      goto LABEL_79;
                    }
                    if ( v93 <= 1 )
                    {
                      if ( !v103 )
                      {
LABEL_89:
                        if ( !v100 )
                        {
                          if ( dict_lookup(&unk_B72C0, v36) )
                          {
                            clear_problem_context(v119, v36, v79);
                            v122 = v36;
                            v120 = v101;
                            fix_problem(v6, 131139, v119);
                            e2fsck_rehash_dir_later(v6, v101, v80);
                            v100 = 1;
                          }
                          else
                          {
                            dict_alloc_insert(&unk_B72C0, v36, v36);
                          }
                        }
                        ext2fs_icount_increment(*(long long *)(v6 + 440), *v36, &v113);
                        if ( v113 > 1u )
                          ++*(int *)(v6 + 752);
                        ++*(int *)(v6 + 768);
LABEL_93:
                        v51 = v99;
                        if ( !v99 )
                          goto LABEL_94;
                        goto LABEL_172;
                      }
LABEL_79:
                      v48 = 0x40000000;
                      v49 = *(char *)(dx_dir_info + 6);
                      if ( (*(char *)(dx_dir_info + 7) & 1) == 0 )
                        v48 = v109;
                      v109 = v48;
                      if ( v49 == 6 )
                      {
                        v50 = v114;
                        if ( v93 > 1 )
                        {
                          v50 = *(unsigned int *)((char *)v36 + (int)((ext2fs_dirent_name_len(v36) + 3) & 0xFFFFFFFC)
                                                              + 8);
                          v114 = v50;
                        }
                      }
                      else
                      {
                        v78 = ext2fs_dirent_name_len(v36);
                        ext2fs_dirhash2(
                          v49,
                          (int)v36 + 8,
                          v78,
                          *(long long *)(v91 + 360),
                          v109,
                          *(long long *)(v91 + 32) + 236,
                          (long long)&v114,
                          0);
                        v50 = v114;
                      }
                      if ( v103[8] > v50 )
                        v103[8] = v50;
                      if ( v103[9] < v50 )
                        v103[9] = v50;
LABEL_88:
                      if ( v93 <= 1 )
                        goto LABEL_89;
                      goto LABEL_207;
                    }
                    if ( !sub_285B0((long long *)v6, v36, encryption_policy, a3 + 8) )
                    {
                      if ( !v103 )
                      {
LABEL_207:
                        if ( !(unsigned int)ext2fs_test_inode_bitmap2(*(long long *)(v6 + 376), *v36) )
                          goto LABEL_89;
                        if ( (unsigned int)e2fsck_dir_info_get_parent(v6, *v36, &src) )
                        {
                          *(int *)(a3 + 16) = *v36;
                          fix_problem(v6, 131100, a3 + 8);
                          goto LABEL_160;
                        }
                        if ( !(int)src )
                        {
                          e2fsck_dir_info_set_parent(v6, *v36, v101);
                          goto LABEL_89;
                        }
                        *(int *)(a3 + 20) = (int)src;
                        if ( !(unsigned int)fix_problem(v6, 131078, a3 + 8) )
                        {
                          *(int *)(a3 + 20) = 0;
                          goto LABEL_89;
                        }
                        goto LABEL_171;
                      }
                      goto LABEL_79;
                    }
LABEL_171:
                    ++v99;
                    *v36 = 0;
LABEL_172:
                    ext2fs_get_rec_len(v91, v36, &v116);
LABEL_94:
                    if ( v117 && v93 <= 1 )
                    {
                      if ( v93 == 1 )
                      {
                        v97 = 0;
                        v52 = 4;
                        v32 = 4;
                        v115 = 4;
                      }
                      else
                      {
                        v52 = v115;
                        v97 = (long long)v36;
                        v32 = v115;
                      }
                    }
                    else
                    {
                      v97 = (long long)v36;
                      v115 += v116;
                      v52 = v115;
                      v32 = v115;
                    }
                    ++v93;
                    continue;
                  }
LABEL_74:
                  if ( (unsigned int)fix_problem(v6, v98, a3 + 8) )
                    goto LABEL_171;
                  ext2fs_unmark_valid(v91);
                  goto LABEL_76;
                }
                v123 = *v36;
                if ( (unsigned int)fix_problem(v6, &loc_20047, a3 + 8) )
                {
                  v72 = v91;
                  ext2fs_bg_itable_unused_set(v91, (unsigned int)v45, 0);
                  goto LABEL_189;
                }
              }
              ext2fs_unmark_valid(v91);
              goto LABEL_71;
            }
            if ( *((short *)v36 + 4) == 11822 )
            {
              v98 = 131099;
              goto LABEL_65;
            }
          }
          if ( *v36 == 2 )
          {
LABEL_228:
            v98 = 131079;
            goto LABEL_65;
          }
          goto LABEL_246;
        }
        v98 = 0;
        v39 = *v36;
      }
LABEL_53:
      if ( !v39 )
        goto LABEL_93;
      goto LABEL_54;
    }
    v36 = (unsigned int *)&v95[v34];
    if ( v87 - v34 > 7 )
    {
      v107 = v34;
      ext2fs_get_rec_len(v91, &v95[v34], &v116);
      v34 = v107;
      v67 = v35 < v116;
      v74 = v35 == v116;
      v35 = v116;
      v37 = !v67 && !v74;
    }
    else
    {
      v116 = v35;
      v37 = 0;
    }
    *(long long *)(a3 + 40) = v36;
    *(long long *)(a3 + 88) = v34;
    if ( v35 + v32 <= v87 && !v37 && (v35 & 3) == 0 )
    {
      v38 = ext2fs_dirent_name_len(v36);
      if ( (unsigned int)sub_281F0(v38, (v93 > 1) & v94) <= v35 )
        goto LABEL_50;
    }
    if ( !(unsigned int)fix_problem(v6, 131091, a3 + 8) )
      goto LABEL_160;
    sub_287E0(v91, v36, v97, &v115, v87, v102);
    v52 = v115;
    ++v99;
    v32 = v115;
  }
  while ( v52 < v87 );
  v53 = v103;
  v54 = v32;
  if ( v103 )
  {
    *(int *)(a3 + 24) = *(int *)(a3 + 16);
    if ( (*v103 & 0xFFFFFFFD) == 1 )
    {
      v53 = v110;
      v85 = v52;
      sub_29610(v91, v110, a3, dx_dir_info, (long long)v95, has_tail);
      v54 = v32;
      v52 = v85;
    }
  }
  if ( v52 != v87 )
  {
    v53 = &loc_2001D;
    *(long long *)(a3 + 88) = v116 + v54 - v87;
    if ( (unsigned int)fix_problem(v6, &loc_2001D, a3 + 8) )
    {
      *((short *)v36 + 2) = *(long long *)(a3 + 88);
      goto LABEL_105;
    }
  }
  if ( !v99 )
  {
    if ( (has_tail & v111) != 0 && (unsigned int)fix_problem(v6, 131149, a3 + 8) )
      goto LABEL_107;
LABEL_116:
    dict_free_nodes(&unk_B72C0);
    return v88;
  }
LABEL_105:
  if ( (unsigned int)sub_29600(*(unsigned int *)(*(long long *)(v91 + 32) + 100LL), v53, v51)
    && (v111 & 1) != 0
    && !v117
    && !(unsigned int)ext2fs_dirent_has_tail(v91, v95)
    && sub_28B30(v91, (unsigned long long)v95) )
  {
    e2fsck_rehash_dir_later(v6, v101, v82);
  }
LABEL_107:
  v55 = e2fsck_dir_will_be_rehashed(v6, v101);
  if ( v55 )
  {
    v112 = *(int *)(*(long long *)v6 + 16LL);
    *(int *)(*(long long *)v6 + 16LL) = v112 | 0x200000;
  }
  if ( v117 )
    v56 = ext2fs_inline_data_set(v91, v101, 0, dest, v117);
  else
    v56 = ext2fs_write_dir_block4(v91, v90, v95, 0, v101);
  *(long long *)(a3 + 8) = v56;
  if ( v55 )
    *(int *)(*(long long *)v6 + 16LL) = v112 & 0x200000 | *(int *)(*(long long *)v6 + 16LL) & 0xFFDFFFFF;
  if ( !v56 || (unsigned int)fix_problem(v6, 131105, a3 + 8) )
  {
    ext2fs_mark_changed(v91);
    goto LABEL_116;
  }
LABEL_160:
  *(int *)(v6 + 72) |= 1u;
  dict_free_nodes(&unk_B72C0);
  return 2;
}


// Function: check_dir_block2 @ 0x2c070
long long check_dir_block2(long long a1, long long a2, long long *a3)
{
  unsigned long long v4; // r8
  unsigned long long v5; // rax
  long long result; // rax
  unsigned long long v7; // rax

  v4 = a3[17];
  if ( v4 )
  {
    v5 = a3[16];
    if ( v5 >= a3[18] )
    {
      if ( (unsigned int)e2fsck_readahead_dblist(a1, 1, *(long long *)(a1 + 144), v5 + (v4 >> 3)) )
      {
        a3[17] = 0;
        v7 = 0;
      }
      else
      {
        v7 = (unsigned long long)(7LL * a3[17]) >> 3;
      }
      a3[18] = a3[16] + v7;
    }
  }
  result = sub_2A9C0(a1, a2, (long long)a3);
  ++a3[16];
  return result;
}


// Function: fix_dotdot @ 0x2c130
unsigned long long fix_dotdot(unsigned int *a1, long long a2, long long a3)
{
  unsigned int v3; // r13d
  unsigned int v4; // r12d
  long long v5; // r14
  int v6; // edx
  int v7; // ebx
  long long v8; // rax
  long long v9; // rsi
  long long v11; // [rsp+0h] [rbp-C8h] BYREF
  int v12; // [rsp+8h] [rbp-C0h]
  int v13; // [rsp+Ch] [rbp-BCh]
  unsigned int *v14; // [rsp+10h] [rbp-B8h]
  long long v15; // [rsp+20h] [rbp-A8h] BYREF
  int v16; // [rsp+28h] [rbp-A0h]
  unsigned long long v17; // [rsp+88h] [rbp-40h]

  v3 = a3;
  v4 = a2;
  v5 = *(long long *)a1;
  v17 = __readfsqword(0x28u);
  v14 = a1;
  v11 = v5;
  v12 = a3;
  v13 = 0;
  clear_problem_context(&v15, a2, a3);
  v16 = a2;
  if ( (unsigned int)e2fsck_dir_will_be_rehashed(a1, (unsigned int)a2) )
  {
    v6 = *(int *)(*(long long *)a1 + 16LL);
    v7 = v6 & 0x200000;
    *(int *)(*(long long *)a1 + 16LL) = v6 | 0x200000;
    v8 = ((long long (*)(long long, long long, long long, long long, long long (*)(), long long *))ext2fs_dir_iterate)(
           v5,
           (unsigned int)a2,
           1,
           0,
           sub_2C940,
           &v11);
    *(int *)(*(long long *)a1 + 16LL) = v7 | *(int *)(*(long long *)a1 + 16LL) & 0xFFDFFFFF;
  }
  else
  {
    v8 = ((long long (*)(long long, long long, long long, long long, long long (*)(), long long *))ext2fs_dir_iterate)(
           v5,
           (unsigned int)a2,
           1,
           0,
           sub_2C940,
           &v11);
  }
  if ( v8 )
  {
    v9 = 196623;
  }
  else
  {
    v9 = 196624;
    if ( v13 )
      goto LABEL_5;
  }
  v15 = v8;
  fix_problem(a1, v9, &v15);
  ext2fs_unmark_valid(v5);
LABEL_5:
  e2fsck_dir_info_set_dotdot(a1, v4, v3);
  if ( (unsigned int)e2fsck_dir_info_set_parent(a1, v4, a1[138]) )
    fix_problem(a1, 196630, &v15);
  return v17 - __readfsqword(0x28u);
}


// Function: expand_dir_proc @ 0x2c2b0
long long expand_dir_proc(long long a1, long long *a2, long long a3, long long a4, long long a5, long long a6)
{
  long long v9; // r14
  long long v10; // rax
  long long v11; // rax
  unsigned long long v12; // rax
  int v13; // ecx
  long long v14; // rsi
  long long v15; // rdx
  long long v16; // rax
  long long v17; // rbp
  long long v18; // rdx
  long long v19; // rcx
  long long v20; // r8
  long long v21; // rsi
  long long v22; // rdi
  long long v24; // [rsp+8h] [rbp-50h] BYREF
  long long v25[9]; // [rsp+10h] [rbp-48h] BYREF

  v9 = *(long long *)(a6 + 40);
  v25[1] = __readfsqword(0x28u);
  v10 = *(long long *)(a6 + 8);
  if ( v10 <= a3 && v10 )
    return 2;
  if ( a3 <= 0 )
  {
    v11 = *a2;
    if ( !*a2 )
    {
      v12 = qword_B7338;
      v13 = *(int *)(a1 + 192);
      if ( !a3 )
        goto LABEL_7;
      goto LABEL_6;
    }
LABEL_13:
    qword_B7338 = v11;
    return 0;
  }
  *(long long *)(a6 + 24) = a3;
  v11 = *a2;
  if ( *a2 )
    goto LABEL_13;
  v12 = qword_B7338;
  v13 = *(int *)(a1 + 192);
LABEL_6:
  v14 = v12 + 1;
  if ( v12 >> v13 == (v12 + 1) >> v13 )
  {
    v24 = v12 + 1;
    goto LABEL_9;
  }
LABEL_7:
  v15 = *(long long *)(v9 + 416);
  qword_B7338 = v12 & (-1 << v13);
  v16 = ext2fs_new_block2(a1, qword_B7338, v15, &v24);
  if ( v16 )
    goto LABEL_14;
  ++*(long long *)(a6 + 16);
  ext2fs_block_alloc_stats2(a1, v24, 1);
  v14 = v24;
LABEL_9:
  qword_B7338 = v14;
  if ( a3 > 0 )
  {
    v16 = ext2fs_new_dir_block(a1, 0, 0, v25);
    if ( !v16 )
    {
      --*(long long *)a6;
      v17 = ext2fs_write_dir_block4(a1, v24, v25[0], 0, *(unsigned int *)(a6 + 48));
      ext2fs_free_mem(v25);
      if ( !v17 )
      {
LABEL_12:
        v21 = v24;
        v22 = *(long long *)(v9 + 416);
        *a2 = v24;
        ext2fs_mark_block_bitmap2(v22, v21, v18, v19, v20);
        return *(long long *)a6 == 0 ? 3 : 1;
      }
      goto LABEL_20;
    }
LABEL_14:
    *(long long *)(a6 + 32) = v16;
    return 2;
  }
  v17 = ext2fs_zero_blocks2(a1, v14, 1, 0, 0);
  if ( !v17 )
    goto LABEL_12;
LABEL_20:
  *(long long *)(a6 + 32) = v17;
  return 2;
}


// Function: check_root @ 0x2c4c0
unsigned long long check_root(long long *a1, long long a2, long long a3)
{
  long long v3; // r12
  long long v4; // rdx
  long long v5; // rcx
  long long v6; // r8
  long long v7; // rsi
  int v8; // eax
  long long v10; // rdx
  long long v11; // rcx
  long long v12; // r8
  const char *v13; // rax
  long long v14; // [rsp+0h] [rbp-158h] BYREF
  long long v15; // [rsp+8h] [rbp-150h] BYREF
  long long v16[14]; // [rsp+10h] [rbp-148h] BYREF
  int v17[42]; // [rsp+80h] [rbp-D8h] BYREF
  unsigned long long v18; // [rsp+128h] [rbp-30h]

  v3 = *a1;
  v18 = __readfsqword(0x28u);
  clear_problem_context(v16, a2, a3);
  if ( !(unsigned int)ext2fs_test_inode_bitmap2(a1[45], 2) )
  {
    if ( !(unsigned int)fix_problem(a1, 196609, v16) )
    {
      fix_problem(a1, 196629, v16);
      *((int *)a1 + 18) |= 1u;
      return v18 - __readfsqword(0x28u);
    }
    e2fsck_read_bitmaps(a1);
    v7 = a1[111];
    if ( v7 )
    {
      v14 = a1[111];
      a1[111] = 0;
    }
    else
    {
      v16[0] = ext2fs_new_block2(v3, 0, a1[52], &v14);
      if ( v16[0] )
      {
        v13 = "ext2fs_new_block";
        goto LABEL_16;
      }
      ext2fs_mark_block_bitmap2(a1[52], v14, v10, v11, v12);
      v7 = v14;
    }
    ext2fs_mark_block_bitmap2(*(long long *)(v3 + 88), v7, v4, v5, v6);
    ext2fs_mark_bb_dirty(v3);
    memset(v17, 0, 0xA0u);
    LOWORD(v17[0]) = 16877;
    v8 = *(int *)(v3 + 40);
    HIWORD(v17[6]) = 2;
    v17[1] = v8;
    v17[4] = a1[105];
    v17[3] = v17[4];
    v17[2] = v17[4];
    ext2fs_iblk_set(v3, v17, 1);
    v17[10] = v14;
    LOWORD(v17[32]) = 32;
    v16[0] = ext2fs_write_new_inode(v3, 2, v17);
    if ( v16[0] )
    {
      v13 = "ext2fs_write_inode";
    }
    else
    {
      v16[0] = ext2fs_new_dir_block(v3, 2, 2, &v15);
      if ( v16[0] )
      {
        v13 = "ext2fs_new_dir_block";
      }
      else
      {
        v16[0] = ext2fs_write_dir_block4(v3, v14, v15, 0, 2);
        ext2fs_free_mem(&v15);
        if ( !v16[0] )
        {
          e2fsck_add_dir_info(a1, 2, 2);
          ext2fs_icount_store(a1[55], 2, 2);
          ext2fs_icount_store(a1[56], 2, 2);
          ext2fs_mark_inode_bitmap2(a1[45], 2);
          ext2fs_mark_inode_bitmap2(a1[47], 2);
          ext2fs_mark_inode_bitmap2(*(long long *)(v3 + 80), 2);
          ext2fs_mark_ib_dirty(v3);
          quota_data_add(a1[79], v17, 2, 1024 << *(int *)(*(long long *)(v3 + 32) + 28LL));
          quota_data_inodes(a1[79], v17, 2, 1);
          return v18 - __readfsqword(0x28u);
        }
        v13 = "ext2fs_write_dir_block4";
      }
    }
LABEL_16:
    v16[12] = v13;
    fix_problem(a1, 196626, v16);
    *((int *)a1 + 18) |= 1u;
    return v18 - __readfsqword(0x28u);
  }
  if ( !(unsigned int)ext2fs_test_inode_bitmap2(a1[47], 2) )
  {
    fix_problem(a1, 196628, v16);
    *((int *)a1 + 18) |= 1u;
  }
  return v18 - __readfsqword(0x28u);
}


// Function: e2fsck_adjust_inode_count @ 0x2c830
long long e2fsck_adjust_inode_count(long long *a1, long long a2, int a3)
{
  long long v3; // r13
  long long result; // rax
  char v6[26]; // [rsp+0h] [rbp-B8h] BYREF
  short v7; // [rsp+1Ah] [rbp-9Eh]
  unsigned long long v8; // [rsp+88h] [rbp-30h]

  v3 = *a1;
  v8 = __readfsqword(0x28u);
  if ( !(int)a2 )
    return 0;
  result = ext2fs_read_inode(v3, a2, v6);
  if ( !result )
  {
    if ( a3 == 1 )
    {
      ext2fs_icount_increment(a1[55], (unsigned int)a2, 0);
      if ( v7 != -1 )
      {
        ext2fs_icount_increment(a1[56], (unsigned int)a2, 0);
        ++v7;
        return ext2fs_write_inode(v3, (unsigned int)a2, v6);
      }
    }
    else
    {
      if ( a3 != -1 )
        return ext2fs_write_inode(v3, (unsigned int)a2, v6);
      ext2fs_icount_decrement(a1[55], (unsigned int)a2, 0);
      if ( v7 )
      {
        ext2fs_icount_decrement(a1[56], (unsigned int)a2, 0);
        --v7;
        return ext2fs_write_inode(v3, (unsigned int)a2, v6);
      }
    }
    return 0;
  }
  return result;
}


// Function: fix_dotdot_proc @ 0x2c940
long long fix_dotdot_proc(char *a1, long long a2, long long a3, long long a4, long long a5)
{
  unsigned int v5; // r12d
  long long v8; // rdx
  long long v10; // rax
  long long v11; // rax
  long long v12; // rdi
  long long v13; // rdi
  long long v14[17]; // [rsp+0h] [rbp-88h] BYREF

  v5 = 0;
  v14[13] = __readfsqword(0x28u);
  if ( (unsigned int)ext2fs_dirent_name_len(a1) == 2 && !strncmp(a1 + 8, "..", 2u) )
  {
    clear_problem_context(v14, "..", v8);
    v10 = e2fsck_adjust_inode_count(*(long long **)(a5 + 16), *(unsigned int *)a1, -1);
    if ( v10 )
    {
      v13 = *(long long *)(a5 + 16);
      v14[0] = v10;
      fix_problem(v13, &loc_3000E, v14);
    }
    v11 = e2fsck_adjust_inode_count(*(long long **)(a5 + 16), *(unsigned int *)(a5 + 8), 1);
    if ( v11 )
    {
      v12 = *(long long *)(a5 + 16);
      v14[0] = v11;
      fix_problem(v12, &loc_3000E, v14);
    }
    *(int *)a1 = *(int *)(a5 + 8);
    if ( (unsigned int)sub_2C820(*(unsigned int *)(*(long long *)(**(long long **)(a5 + 16) + 32LL) + 96LL)) )
      ext2fs_dirent_set_file_type(a1, 2);
    else
      ext2fs_dirent_set_file_type(a1, 0);
    ++*(int *)(a5 + 12);
    return 3;
  }
  return v5;
}


// Function: e2fsck_get_lost_and_found @ 0x2ca70
long long e2fsck_get_lost_and_found(long long *a1, long long a2, long long a3)
{
  unsigned int v3; // r12d
  long long v5; // rbp
  long long v7; // rax
  long long v8; // rdx
  long long v9; // rsi
  long long v10; // rax
  unsigned long long v11; // rbx
  long long v12; // rsi
  int v13; // eax
  long long v14; // rbx
  long long v15; // rdx
  long long v16; // rax
  long long v17; // rax
  long long v18; // rdx
  long long v19; // rdi
  int v20; // ecx
  long long v21; // rax
  long long v22; // rcx
  long long inode_full; // rax
  long long v24; // rax
  long long v25; // rdx
  long long v26; // rcx
  long long v27; // r8
  long long v28; // rbx
  const char *v29; // rax
  int v30; // [rsp+8h] [rbp-180h]
  long long v31; // [rsp+8h] [rbp-180h]
  unsigned int v32; // [rsp+1Ch] [rbp-16Ch] BYREF
  long long v33; // [rsp+20h] [rbp-168h] BYREF
  long long v34; // [rsp+28h] [rbp-160h] BYREF
  long long v35; // [rsp+30h] [rbp-158h] BYREF
  unsigned int v36; // [rsp+38h] [rbp-150h]
  const char *v37; // [rsp+90h] [rbp-F8h]
  long long v38[29]; // [rsp+A0h] [rbp-E8h] BYREF

  v3 = *((int *)a1 + 138);
  v38[21] = __readfsqword(0x28u);
  if ( !v3 )
  {
    v5 = *a1;
    clear_problem_context(&v35, a2, a3);
    if ( (unsigned int)e2fsck_dir_will_be_rehashed(a1, 2) )
    {
      v30 = *(int *)(*a1 + 16);
      *(int *)(*a1 + 16) = v30 | 0x200000;
      v7 = ext2fs_lookup(v5, 2, "lost+found", 10, 0, &v32);
      v8 = *(int *)(*a1 + 16) & 0xFFDFFFFF;
      *(int *)(*a1 + 16) = v8 | v30 & 0x200000;
      if ( v7 )
      {
LABEL_5:
        if ( !(int)a2 )
          return v3;
        if ( v7 != 2133571404 )
        {
          v35 = v7;
          fix_problem(a1, 196617, &v35);
        }
        goto LABEL_8;
      }
    }
    else
    {
      v7 = ext2fs_lookup(v5, 2, "lost+found", 10, 0, &v32);
      if ( v7 )
        goto LABEL_5;
    }
    v21 = sub_2C120(v38, 2, v8, 160);
    inode_full = ext2fs_read_inode_full(v5, v32, v21, v22);
    if ( (int)a2 )
    {
      if ( inode_full )
        return v3;
      if ( (v38[4] & 0x10000000) != 0 )
      {
        if ( !(unsigned int)fix_problem(a1, 196632, &v35) )
          return v3;
      }
      else
      {
        if ( (v38[4] & 0x800LL) == 0 )
        {
          if ( ext2fs_check_directory(v5, v32) )
          {
            v36 = v32;
            if ( !(unsigned int)fix_problem(a1, &loc_30017, &v35) )
              return v3;
            goto LABEL_26;
          }
LABEL_38:
          v3 = v32;
          *((int *)a1 + 138) = v32;
          return v3;
        }
        if ( !(unsigned int)fix_problem(a1, 196635, &v35) )
          return v3;
      }
LABEL_26:
      v35 = ext2fs_unlink(v5, 2, "lost+found", v32, 0);
      if ( v35 )
      {
        v29 = "ext2fs_unlink";
        goto LABEL_33;
      }
      e2fsck_dir_info_set_parent(a1, v32, 0);
      e2fsck_adjust_inode_count(a1, v32, -1);
      if ( (v38[0] & 0xF000) == 0x4000 )
        *((int *)a1 + 18) |= 4u;
LABEL_8:
      if ( !(unsigned int)fix_problem(a1, 196612, 0) )
        return v3;
      e2fsck_read_bitmaps(a1);
      v9 = a1[112];
      if ( v9 )
      {
        v33 = a1[112];
        a1[112] = 0;
LABEL_11:
        ext2fs_block_alloc_stats2(v5, v9, 1);
        v10 = ext2fs_new_inode(v5, 2, 16832, a1[45], &v32);
        v11 = v10;
        if ( v10 != 2133571401 )
        {
          if ( !v10 )
          {
            ext2fs_mark_inode_bitmap2(a1[45], v32);
            ext2fs_mark_inode_bitmap2(a1[47], v32);
            v12 = v32;
            ext2fs_inode_alloc_stats2(v5, v32, 1, 1);
            memset64(v38, v11, 0x14u);
            LOWORD(v38[0]) = 16832;
            v13 = *(int *)(v5 + 40);
            WORD1(v38[3]) = 2;
            HIDWORD(v38[0]) = v13;
            LODWORD(v38[2]) = a1[105];
            HIDWORD(v38[1]) = v38[2];
            LODWORD(v38[1]) = v38[2];
            v14 = sub_2C120(v38, v12, 1, 0);
            ext2fs_iblk_set(v5, v14, v15);
            LODWORD(v38[5]) = v33;
            v35 = ext2fs_write_new_inode(v5, v32, v14);
            if ( v35 )
            {
              v29 = "ext2fs_write_inode";
LABEL_33:
              v37 = v29;
              fix_problem(a1, &loc_30013, &v35);
              return v3;
            }
            v16 = ext2fs_new_dir_block(v5, v32, 2, &v34);
            if ( v16 )
            {
              v35 = v16;
              fix_problem(a1, 196620, &v35);
              return v3;
            }
            v31 = ext2fs_write_dir_block4(v5, v33, v34, 0, v32);
            ext2fs_free_mem(&v34);
            if ( v31 )
            {
              v35 = v31;
              fix_problem(a1, 196621, &v35);
              return v3;
            }
            v17 = ext2fs_link(v5, 2, "lost+found", v32, 2);
            v35 = v17;
            if ( v17 == 2133571366 )
            {
              v35 = ext2fs_expand_dir(v5, 2);
              if ( v35 )
              {
LABEL_46:
                v29 = "ext2fs_link";
                goto LABEL_33;
              }
              v17 = ext2fs_link(v5, 2, "lost+found", v32, 2);
              v35 = v17;
            }
            if ( !v17 )
            {
              e2fsck_add_dir_info(a1, v32, 2);
              e2fsck_adjust_inode_count(a1, 2, 1);
              ext2fs_icount_store(a1[55], v32, 2);
              ext2fs_icount_store(a1[56], v32, 2);
              v18 = v32;
              v19 = a1[79];
              v20 = *(int *)(*(long long *)(v5 + 32) + 28LL);
              *((int *)a1 + 138) = v32;
              quota_data_add(v19, v38, v18, 1024 << v20);
              quota_data_inodes(a1[79], v38, v32, 1);
              return v32;
            }
            goto LABEL_46;
          }
LABEL_36:
          v35 = v11;
          fix_problem(a1, &loc_3000B, &v35);
          return v3;
        }
        if ( !(unsigned int)fix_problem(a1, 196633, &v35) )
          goto LABEL_36;
LABEL_40:
        fix_problem(a1, 196634, &v35);
        *((int *)a1 + 138) = 2;
        return v3;
      }
      v24 = ext2fs_new_block2(v5, 0, a1[52], &v33);
      v28 = v24;
      if ( v24 == 2133571400 )
      {
        if ( (unsigned int)fix_problem(a1, 196633, &v35) )
          goto LABEL_40;
      }
      else if ( !v24 )
      {
        ext2fs_mark_block_bitmap2(a1[52], v33, v25, v26, v27);
        v9 = v33;
        goto LABEL_11;
      }
      v35 = v28;
      fix_problem(a1, 196618, &v35);
      return v3;
    }
    if ( ext2fs_check_directory(v5, v32) )
      return v3;
    goto LABEL_38;
  }
  return v3;
}


// Function: e2fsck_expand_directory @ 0x2d140
long long e2fsck_expand_directory(long long *a1, unsigned int a2, int a3, int a4)
{
  long long inode_full; // r12
  long long v5; // r13
  long long v6; // r14
  long long v9; // rdx
  long long v10; // r14
  long long v11; // rcx
  long long v12[2]; // [rsp+0h] [rbp-128h] BYREF
  long long v13; // [rsp+10h] [rbp-118h]
  long long v14; // [rsp+18h] [rbp-110h]
  long long v15; // [rsp+20h] [rbp-108h]
  long long *v16; // [rsp+28h] [rbp-100h]
  unsigned int v17; // [rsp+30h] [rbp-F8h]
  char v18[168]; // [rsp+40h] [rbp-E8h] BYREF
  unsigned long long v19; // [rsp+E8h] [rbp-40h]

  inode_full = 2133571349;
  v5 = *a1;
  v19 = __readfsqword(0x28u);
  if ( (*(char *)(v5 + 16) & 1) != 0 )
  {
    v6 = a3;
    e2fsck_read_bitmaps(a1);
    inode_full = ext2fs_check_directory(v5, a2);
    if ( !inode_full )
    {
      v12[1] = a4;
      v12[0] = v6;
      v14 = 0;
      v15 = 0;
      v13 = 0;
      v16 = a1;
      v17 = a2;
      ext2fs_block_iterate3(v5, a2, 1, 0, sub_2C2B0, v12);
      inode_full = v15;
      if ( !v15 )
      {
        v10 = sub_2C120(v18, a2, v9, 160);
        inode_full = ext2fs_read_inode_full(v5, a2, v10, v11);
        if ( !inode_full )
        {
          inode_full = ext2fs_inode_size_set(v5, v10, *(unsigned int *)(v5 + 40) * (v14 + 1));
          if ( !inode_full )
          {
            ext2fs_iblk_add_blocks(v5, v10, v13);
            quota_data_add(a1[79], v18, a2, v13 * (1024 << *(int *)(*(long long *)(v5 + 32) + 28LL)));
            e2fsck_write_inode_full(a1, a2, v10, 160, "expand_directory");
          }
        }
      }
    }
  }
  return inode_full;
}


// Function: e2fsck_reconnect_file @ 0x2d2e0
long long e2fsck_reconnect_file(long long a1, long long a2, long long a3)
{
  long long v3; // r15
  long long v4; // rdx
  bool v5; // zf
  unsigned int v6; // r13d
  long long inode; // rax
  long long v8; // rdx
  long long v9; // rcx
  long long v10; // r8
  long long v11; // rax
  long long v13; // rax
  unsigned int v14; // [rsp+Ch] [rbp-18Ch]
  long long v15; // [rsp+10h] [rbp-188h] BYREF
  int v16; // [rsp+18h] [rbp-180h]
  short v17[64]; // [rsp+80h] [rbp-118h] BYREF
  char v18[88]; // [rsp+100h] [rbp-98h] BYREF
  unsigned long long v19; // [rsp+158h] [rbp-40h]

  v3 = *(long long *)a1;
  v19 = __readfsqword(0x28u);
  clear_problem_context(&v15, a2, a3);
  v5 = *(long long *)(a1 + 552) == 0;
  v16 = a2;
  if ( !v5 || (unsigned int)e2fsck_get_lost_and_found((long long *)a1, 1, v4) )
  {
    v6 = *(int *)(a1 + 556);
  }
  else
  {
    v6 = *(int *)(a1 + 556) + 1;
    *(int *)(a1 + 556) = v6;
  }
  if ( v6 )
  {
    v6 = 1;
    fix_problem(a1, &loc_30006, &v15);
  }
  else
  {
    __sprintf_chk(v18, 1, 80, "#%u", a2);
    inode = ext2fs_read_inode(v3, (unsigned int)a2, v17);
    v10 = 0;
    if ( !inode )
      v10 = (unsigned int)ext2_file_type(v17[0], (unsigned int)a2, v8, v9, 0);
    v14 = v10;
    v11 = ext2fs_link(v3, *(unsigned int *)(a1 + 552), v18, (unsigned int)a2, v10);
    if ( v11 == 2133571366 )
    {
      if ( !(unsigned int)fix_problem(a1, &loc_30002, &v15) )
        return 1;
      v13 = e2fsck_expand_directory((long long *)a1, *(int *)(a1 + 552), 1, 0);
      if ( v13 )
      {
        v15 = v13;
        fix_problem(a1, 196615, &v15);
        return 1;
      }
      v11 = ext2fs_link(v3, *(unsigned int *)(a1 + 552), v18, (unsigned int)a2, v14);
    }
    if ( v11 )
    {
      v15 = v11;
      fix_problem(a1, 196616, &v15);
      return 1;
    }
    else
    {
      e2fsck_adjust_inode_count((long long *)a1, (unsigned int)a2, 1);
    }
  }
  return v6;
}


// Function: check_directory @ 0x2d500
long long check_directory(unsigned int *a1, unsigned int a2, long long a3)
{
  int v3; // r13d
  int v4; // ebp
  unsigned int v5; // ebx
  char *v6; // rax
  long long inode_bitmap; // rax
  long long v8; // rdx
  unsigned int parent; // r13d
  long long v12; // [rsp+8h] [rbp-50h]
  unsigned int v13; // [rsp+14h] [rbp-44h] BYREF
  unsigned long long v14; // [rsp+18h] [rbp-40h]

  v3 = 0;
  v4 = 0;
  v5 = a2;
  v14 = __readfsqword(0x28u);
  v12 = *(long long *)a1;
  while ( !(unsigned int)ext2fs_mark_inode_bitmap2(qword_B7340, v5) )
  {
    if ( (unsigned int)e2fsck_dir_info_get_parent(a1, v5, &v13) )
      goto LABEL_20;
    if ( !v13 )
    {
LABEL_14:
      *(int *)(a3 + 8) = v5;
      if ( (unsigned int)fix_problem(a1, 196611, a3) )
      {
        if ( (unsigned int)e2fsck_reconnect_file((long long)a1, *(unsigned int *)(a3 + 8), v8) )
        {
          ext2fs_unmark_valid(v12);
        }
        else
        {
          sub_2C130(a1, *(unsigned int *)(a3 + 8), a1[138]);
          v13 = a1[138];
        }
      }
      break;
    }
    if ( v3 )
    {
      if ( (unsigned int)ext2fs_test_inode_bitmap2(qword_B7348, v13) )
        goto LABEL_14;
      v5 = v13;
      ext2fs_mark_inode_bitmap2(qword_B7348, v13);
    }
    else if ( v4 > 2048 )
    {
      if ( qword_B7348 )
      {
        ext2fs_clear_inode_bitmap();
        ++v4;
        v3 = 1;
        v5 = a2;
      }
      else
      {
        v6 = dcgettext(0, "inode loop detection bitmap", 5);
        inode_bitmap = e2fsck_allocate_inode_bitmap(v12, v6, 3, "inode_loop_detect", &qword_B7348);
        *(long long *)a3 = inode_bitmap;
        if ( inode_bitmap )
        {
          *(long long *)(a3 + 80) = 1;
          parent = -1;
          fix_problem(a1, 196625, a3);
          a1[18] |= 1u;
          return parent;
        }
        ++v4;
        v3 = 1;
        v5 = a2;
      }
    }
    else
    {
      ++v4;
      v5 = v13;
    }
  }
  *(int *)(a3 + 8) = a2;
  if ( (unsigned int)e2fsck_dir_info_get_dotdot(a1, a2, a3 + 12)
    || (parent = e2fsck_dir_info_get_parent(a1, a2, a3 + 16)) != 0 )
  {
LABEL_20:
    parent = 0;
    fix_problem(a1, 196630, a3);
    return parent;
  }
  if ( *(int *)(a3 + 12) != *(int *)(a3 + 16) && (unsigned int)fix_problem(a1, 196613, a3) )
    sub_2C130(a1, a2, *(unsigned int *)(a3 + 16));
  return parent;
}


// Function: e2fsck_pass3 @ 0x2d780
unsigned long long e2fsck_pass3(long long a1)
{
  long long v1; // rbp
  long long v2; // rsi
  long long v3; // rdx
  char *v4; // rax
  char *v5; // rsi
  long long v6; // rdx
  long long v7; // rdx
  long long v8; // rcx
  long long v9; // r8
  long long v10; // rsi
  long long v11; // rsi
  long long v12; // r12
  char *v13; // rax
  unsigned int (*v15)(long long, long long, long long, long long); // rax
  long long v16; // r14
  long long v17; // r12
  long long v18; // rdx
  unsigned int *v19; // rbx
  unsigned int (*v20)(long long, long long, long long, long long); // rax
  long long v21; // rbp
  long long num_dirinfo; // [rsp+0h] [rbp-108h]
  struct timeval tv; // [rsp+10h] [rbp-F8h] BYREF
  long long v24[13]; // [rsp+60h] [rbp-A8h] BYREF
  unsigned long long v25; // [rsp+C8h] [rbp-40h]

  v1 = *(long long *)a1;
  v25 = __readfsqword(0x28u);
  v2 = *(long long *)(v1 + 8);
  init_resource_track(&tv);
  clear_problem_context(v24, v2, v3);
  if ( (*(char *)(a1 + 76) & 2) == 0 )
    fix_problem(a1, 196608, v24);
  v4 = dcgettext(0, "inode done bitmap", 5);
  v24[0] = e2fsck_allocate_inode_bitmap(v1, v4, 3, "inode_done_map", &qword_B7340);
  if ( v24[0] )
  {
    v24[10] = 2;
    fix_problem(a1, 196625, v24);
    *(int *)(a1 + 72) |= 1u;
  }
  else
  {
    v5 = dcgettext(0, "Peak memory", 5);
    print_resource_track(a1, v5, a1 + 640, 0);
    sub_2C4C0((long long *)a1, (long long)v5, v6);
    if ( (*(char *)(a1 + 72) & 3) == 0 )
    {
      ext2fs_mark_inode_bitmap2(qword_B7340, 2);
      num_dirinfo = (int)e2fsck_get_num_dirinfo(a1);
      v15 = *(unsigned int (**)(long long, long long, long long, long long))(a1 + 352);
      if ( !v15 || !v15(a1, 3, 0, num_dirinfo) )
      {
        v16 = 1;
        v17 = e2fsck_dir_info_iter_begin(a1);
        while ( 1 )
        {
          v19 = (unsigned int *)e2fsck_dir_info_iter(a1, v17);
          if ( !v19 )
            break;
          if ( (*(char *)(a1 + 72) & 7) != 0 )
            goto LABEL_24;
          v20 = *(unsigned int (**)(long long, long long, long long, long long))(a1 + 352);
          if ( v20 )
          {
            v21 = v16 + 1;
            if ( v20(a1, 3, v16, num_dirinfo) )
              goto LABEL_24;
          }
          else
          {
            v21 = v16;
          }
          if ( (unsigned int)ext2fs_test_inode_bitmap2(*(long long *)(a1 + 376), *v19)
            && (unsigned int)sub_2D500((unsigned int *)a1, *v19, (long long)v24) )
          {
            goto LABEL_24;
          }
          v16 = v21;
        }
        if ( (*(char *)(a1 + 76) & 1) == 0 )
          e2fsck_get_lost_and_found((long long *)a1, 1, v18);
        e2fsck_rehash_directories(a1);
LABEL_24:
        if ( v17 )
          e2fsck_dir_info_iter_end(a1, v17);
      }
    }
  }
  e2fsck_free_dir_info(a1);
  if ( qword_B7348 )
  {
    ext2fs_free_inode_bitmap(qword_B7348);
    qword_B7348 = 0;
  }
  if ( qword_B7340 )
  {
    ext2fs_free_inode_bitmap(qword_B7340);
    qword_B7340 = 0;
  }
  v10 = *(long long *)(a1 + 896);
  if ( v10 )
  {
    ext2fs_unmark_block_bitmap2(*(long long *)(a1 + 416), v10, v7, v8, v9);
    *(long long *)(a1 + 896) = 0;
  }
  v11 = *(long long *)(a1 + 888);
  if ( v11 )
  {
    ext2fs_unmark_block_bitmap2(*(long long *)(a1 + 416), v11, v7, v8, v9);
    *(long long *)(a1 + 888) = 0;
  }
  v12 = *(long long *)(*(long long *)a1 + 8LL);
  v13 = dcgettext(0, "Pass 3", 5);
  print_resource_track(a1, v13, &tv, v12);
  return v25 - __readfsqword(0x28u);
}


// Function: check_ea_inode @ 0x2dad0
unsigned long long check_ea_inode(long long *a1, long long a2, long long a3, short *a4)
{
  long long v5; // rcx
  long long v8; // rax
  long long v9; // rax
  long long v10; // rdx
  long long v11; // rax
  long long v12; // r12
  long long v13; // rcx
  long long v14; // r8
  long long v15; // rdi
  long long v17; // rdx
  long long ea_inode_ref; // r14
  long long v19; // [rsp+8h] [rbp-B0h] BYREF
  char v20[8]; // [rsp+10h] [rbp-A8h] BYREF
  int v21; // [rsp+18h] [rbp-A0h]
  long long v22; // [rsp+60h] [rbp-58h]
  long long v23; // [rsp+68h] [rbp-50h]
  unsigned long long v24; // [rsp+78h] [rbp-40h]

  v5 = 128;
  v24 = __readfsqword(0x28u);
  v8 = *a1;
  v19 = 0;
  v9 = *(long long *)(v8 + 32);
  v10 = *(unsigned int *)(v9 + 76);
  if ( (int)v10 )
    v5 = *(unsigned short *)(v9 + 88);
  v11 = sub_2DAB0(a3, a2, v10, v5, "pass4: check_ea_inode");
  a2 = (unsigned int)a2;
  v12 = v11;
  e2fsck_read_inode_full(a1, (unsigned int)a2, v11, v13, v14);
  if ( (*(char *)(a3 + 34) & 0x20) != 0 )
  {
    v15 = a1[61];
    if ( v15 )
    {
      a2 = (unsigned int)a2;
      ea_refcount_fetch(v15, (unsigned int)a2, &v19);
    }
    if ( v19 )
    {
      *a4 = 1;
      ea_inode_ref = ext2fs_get_ea_inode_ref(v12);
      if ( v19 != ea_inode_ref && *(int *)(a3 + 12) != *(int *)(a3 + 8) )
      {
        clear_problem_context(v20, a2, v17);
        v21 = a2;
        v22 = ea_inode_ref;
        v23 = v19;
        if ( (unsigned int)fix_problem(a1, 262149, v20) )
        {
          ext2fs_set_ea_inode_ref(v12, v19);
          e2fsck_write_inode(a1, (unsigned int)a2, v12, "pass4");
        }
      }
    }
  }
  return v24 - __readfsqword(0x28u);
}


// Function: disconnect_inode @ 0x2dc20
long long disconnect_inode(long long *a1, unsigned int a2, long long a3)
{
  long long v3; // rcx
  long long v5; // r15
  long long v6; // rax
  long long v7; // r14
  long long v8; // rcx
  long long v9; // r8
  long long v10; // rdx
  long long v11; // rax
  long long v12; // rcx
  int v13; // eax
  long long v14; // rdx
  long long result; // rax
  unsigned short v16; // [rsp+Eh] [rbp-AAh]
  char v17[8]; // [rsp+10h] [rbp-A8h] BYREF
  unsigned int v18; // [rsp+18h] [rbp-A0h]
  long long v19; // [rsp+28h] [rbp-90h]
  unsigned long long v20; // [rsp+78h] [rbp-40h]

  v3 = 128;
  v5 = *a1;
  v20 = __readfsqword(0x28u);
  v6 = *(long long *)(v5 + 32);
  if ( *(int *)(v6 + 76) )
    v3 = *(unsigned short *)(v6 + 88);
  v7 = sub_2DAB0(a3, a2, a3, v3, "pass4: disconnect_inode");
  e2fsck_read_inode_full(a1, a2, v7, v8, v9);
  v11 = *(long long *)(v5 + 32);
  if ( *(int *)(v11 + 76) && *(short *)(v11 + 88) > 0x80u )
  {
    v16 = *(short *)(a3 + 128);
    clear_problem_context(v17, a2, v10);
    v12 = *(long long *)(v5 + 32);
    v18 = a2;
    v19 = v7;
    if ( !*(int *)(v12 + 76) )
      goto LABEL_16;
    v13 = v16;
  }
  else
  {
    clear_problem_context(v17, a2, v10);
    v12 = *(long long *)(v5 + 32);
    v18 = a2;
    v19 = v7;
    if ( !*(int *)(v12 + 76) )
      goto LABEL_16;
    v13 = 0;
  }
  if ( *(unsigned short *)(v12 + 88) - 128 <= v13 )
  {
LABEL_16:
    if ( *(int *)(a3 + 28) )
      goto LABEL_12;
    goto LABEL_17;
  }
  if ( *(int *)(a3 + v13 + 128) == -368967680 || *(int *)(a3 + 28) )
    goto LABEL_12;
LABEL_17:
  if ( (((*(short *)a3 & 0xF000) - 0x4000) & 0xB000) == 0 && (unsigned int)fix_problem(a1, 262145, v17) )
  {
    e2fsck_clear_inode((long long)a1, a2, v7, 0, (long long)"disconnect_inode");
    e2fsck_read_bitmaps(a1);
    ext2fs_inode_alloc_stats2(v5, a2, 0xFFFFFFFFLL, (*(short *)a3 & 0xF000) == 0x4000);
    quota_data_inodes(a1[79], a3, a2, 0xFFFFFFFFLL);
    return 0;
  }
LABEL_12:
  if ( (unsigned int)fix_problem(a1, 262146, v17) )
  {
    result = e2fsck_reconnect_file((long long)a1, a2, v14);
    if ( (int)result )
    {
      ext2fs_unmark_valid(v5);
      return 0;
    }
  }
  else
  {
    ext2fs_unmark_valid(v5);
    return 1;
  }
  return result;
}


// Function: e2fsck_pass4 @ 0x2de50
unsigned long long e2fsck_pass4(long long *a1)
{
  long long *v1; // r15
  long long v2; // rbx
  long long v3; // rax
  long long v4; // rsi
  long long v5; // rdx
  unsigned int v6; // ebp
  unsigned int (*v7)(long long *, long long, long long); // rax
  long long memory; // rax
  int *v9; // rdx
  long long v10; // rdi
  long long v11; // r14
  unsigned int v12; // ebp
  unsigned int v13; // eax
  unsigned int *v14; // rdx
  unsigned int *v15; // rcx
  unsigned int v16; // r15d
  unsigned int (*v17)(long long, long long, long long, long long); // rax
  unsigned int v18; // eax
  long long v19; // rdi
  long long v20; // rdi
  long long v21; // rdx
  long long v22; // rcx
  int v23; // r12d
  short v24; // ax
  long long v25; // r12
  char *v26; // rax
  const char *v28; // rcx
  long long v29; // rax
  long long v30; // r8
  long long v31; // rcx
  long long v32; // r8
  long long v33; // rax
  long long v34; // rdx
  unsigned short v35; // cx
  unsigned short v36; // cx
  int v37; // eax
  long long v38; // rdx
  long long v39; // rcx
  long long v40; // rdi
  long long v41; // rax
  long long v42; // r8
  long long v43; // rdi
  long long v44; // rdi
  long long v45; // rdi
  long long v46; // rdi
  unsigned int v47; // [rsp+4h] [rbp-134h]
  unsigned int v48; // [rsp+18h] [rbp-120h]
  unsigned int fixed; // [rsp+1Ch] [rbp-11Ch]
  unsigned short v50; // [rsp+2Ch] [rbp-10Ch] BYREF
  unsigned short v51; // [rsp+2Eh] [rbp-10Ah] BYREF
  long long v52; // [rsp+30h] [rbp-108h] BYREF
  long long v53; // [rsp+38h] [rbp-100h] BYREF
  struct timeval tv; // [rsp+40h] [rbp-F8h] BYREF
  char v55[8]; // [rsp+90h] [rbp-A8h] BYREF
  unsigned int v56; // [rsp+98h] [rbp-A0h]
  long long v57; // [rsp+A8h] [rbp-90h]
  long long v58; // [rsp+E0h] [rbp-58h]
  unsigned long long v59; // [rsp+F8h] [rbp-40h]

  v1 = a1;
  v2 = *a1;
  v59 = __readfsqword(0x28u);
  v48 = 128;
  v3 = *(long long *)(v2 + 32);
  if ( *(int *)(v3 + 76) )
    v48 = *(unsigned short *)(v3 + 88);
  v4 = *(long long *)(v2 + 8);
  v53 = 0;
  init_resource_track(&tv);
  if ( a1[115] && (!*(long long *)(v2 + 88) || !*(long long *)(v2 + 80)) )
  {
    v4 = 12;
    e2fsck_readahead(v2, 12, 0, *(unsigned int *)(v2 + 48));
  }
  clear_problem_context(v55, v4, v5);
  if ( (*((char *)a1 + 76) & 2) == 0 )
    fix_problem(a1, 0x40000, v55);
  v6 = *(int *)(*(long long *)(v2 + 32) + 100LL);
  v7 = (unsigned int (*)(long long *, long long, long long))a1[44];
  v47 = *(int *)(v2 + 48);
  if ( !v7 || !v7(a1, 4, 0) )
  {
    memory = e2fsck_allocate_memory(a1, (int)v48, "scratch inode");
    v9 = *(int **)(v2 + 32);
    v52 = memory;
    if ( *v9 )
    {
      v10 = v6;
      v11 = (long long)v1;
      v12 = 0;
      v13 = sub_2DE40(v10);
      v15 = v14;
      v16 = 1;
      fixed = v13;
      if ( (*(char *)(v11 + 72) & 3) == 0 )
      {
        while ( 1 )
        {
          if ( !(v16 % v15[10]) )
          {
            v17 = *(unsigned int (**)(long long, long long, long long, long long))(v11 + 352);
            ++v12;
            if ( v17 )
            {
              if ( v17(v11, 4, v12, v47) )
                goto LABEL_35;
            }
          }
          if ( (unsigned int)quota_type2inum(2, *(long long *)(*(long long *)v11 + 32LL)) == v16 || v16 == 1 )
            goto LABEL_32;
          if ( v16 == 2 )
            break;
          v15 = *(unsigned int **)(v2 + 32);
          v18 = 11;
          if ( v15[19] )
            v18 = v15[21];
          if ( v18 <= v16 )
            break;
LABEL_33:
          if ( *v15 <= v16 )
          {
            v1 = (long long *)v11;
            goto LABEL_57;
          }
          ++v16;
          if ( (*(char *)(v11 + 72) & 3) != 0 )
            goto LABEL_35;
        }
        if ( !(unsigned int)ext2fs_test_inode_bitmap2(*(long long *)(v11 + 360), v16) )
          goto LABEL_32;
        v19 = *(long long *)(v11 + 392);
        if ( v19 )
        {
          if ( (unsigned int)ext2fs_test_inode_bitmap2(v19, v16) )
            goto LABEL_32;
        }
        v20 = *(long long *)(v11 + 384);
        if ( v20 )
        {
          if ( (unsigned int)ext2fs_test_inode_bitmap2(v20, v16) )
            goto LABEL_32;
        }
        ext2fs_icount_fetch(*(long long *)(v11 + 448), v16, &v50);
        ext2fs_icount_fetch(*(long long *)(v11 + 440), v16, &v51);
        if ( !v51 )
        {
          sub_2DAD0((long long *)v11, v16, v52, &v51);
          if ( !v51 )
          {
            v28 = (const char *)v53;
            if ( !v53 )
            {
              v53 = e2fsck_allocate_memory(v11, *(unsigned int *)(v2 + 40), "bad_inode buffer");
              v28 = (const char *)v53;
            }
            if ( (unsigned int)e2fsck_process_bad_inode(v11, 0, v16, v28)
              || (unsigned int)sub_2DC20((long long *)v11, v16, v52) )
            {
              goto LABEL_32;
            }
            ext2fs_icount_fetch(*(long long *)(v11 + 448), v16, &v50);
            ext2fs_icount_fetch(*(long long *)(v11 + 440), v16, &v51);
          }
        }
        v23 = ext2fs_test_inode_bitmap2(*(long long *)(v11 + 376), v16);
        v24 = v51;
        if ( v23 && v51 > 0xFDE8u )
        {
          v21 = fixed;
          if ( !fixed )
          {
            fixed = fix_problem(v11, &loc_40006, v55);
            if ( fixed )
            {
              sub_2DAC0(*(long long *)(v2 + 32));
              ext2fs_mark_super_dirty(v2);
              fixed = 1;
            }
          }
          v51 = 1;
          v24 = 1;
        }
        if ( v50 == v24 )
        {
LABEL_32:
          v15 = *(unsigned int **)(v2 + 32);
          goto LABEL_33;
        }
        v29 = sub_2DAB0(v52, v16, v21, v22, "pass4");
        e2fsck_read_inode_full(v11, v16, v29, v48, v30);
        v56 = v16;
        v33 = sub_2DAB0(v52, v16, v52, v31, v32);
        v35 = *(short *)(v34 + 26);
        v57 = v33;
        if ( v35 == v50 )
        {
          v58 = v51;
          v36 = v51;
          if ( !v23 )
            goto LABEL_52;
        }
        else
        {
          if ( !v23 )
          {
            if ( v35 <= 0xFDE8u )
            {
              v58 = v50;
              fix_problem(v11, 262148, v55);
            }
            v58 = v51;
            goto LABEL_52;
          }
          v58 = v51;
          v36 = v51;
        }
        if ( v36 > 1u && (*(char *)(v34 + 33) & 0x10) != 0 && v50 == 1 )
        {
          if ( (*(char *)(v11 + 76) & 1) != 0 )
            goto LABEL_32;
          v37 = fix_problem(v11, 262151, v55);
LABEL_53:
          if ( v37 )
          {
            v40 = v52;
            *(short *)(v52 + 26) = v51;
            v41 = sub_2DAB0(v40, v16, v38, v39, "pass4");
            e2fsck_write_inode_full(v11, v16, v41, v48, v42);
          }
          goto LABEL_32;
        }
LABEL_52:
        v37 = fix_problem(v11, &loc_40003, v55);
        goto LABEL_53;
      }
LABEL_35:
      v1 = (long long *)v11;
    }
    else
    {
LABEL_57:
      ext2fs_free_icount(v1[56]);
      v43 = v1[55];
      v1[56] = 0;
      ext2fs_free_icount(v43);
      v44 = v1[48];
      v1[55] = 0;
      ext2fs_free_inode_bitmap(v44);
      v45 = v1[61];
      v1[48] = 0;
      ea_refcount_free(v45);
      v46 = v1[49];
      v1[61] = 0;
      ext2fs_free_inode_bitmap(v46);
      v1[49] = 0;
    }
    if ( v53 )
      ext2fs_free_mem(&v53);
    ext2fs_free_mem(&v52);
    v25 = *(long long *)(*v1 + 8LL);
    v26 = dcgettext(0, "Pass 4", 5);
    print_resource_track(v1, v26, &tv, v25);
  }
  return v59 - __readfsqword(0x28u);
}


// Function: print_bitmap_problem @ 0x2e470
long long print_bitmap_problem(long long a1, long long a2, long long a3)
{
  long long result; // rax

  if ( (int)a2 == 327688 )
  {
    if ( *(int *)(a3 + 8) != *(int *)(a3 + 12) )
    {
      a2 = 327702;
      goto LABEL_7;
    }
    goto LABEL_16;
  }
  if ( (unsigned int)a2 > 0x50008 )
  {
    if ( (int)a2 != 327689 )
      goto LABEL_7;
    if ( *(int *)(a3 + 8) != *(int *)(a3 + 12) )
    {
      a2 = 327703;
      goto LABEL_7;
    }
LABEL_16:
    *(int *)(a3 + 12) = 0;
    goto LABEL_7;
  }
  if ( (int)a2 == (int)&loc_50004 )
  {
    if ( *(long long *)(a3 + 40) != *(long long *)(a3 + 48) )
    {
      a2 = 327700;
      goto LABEL_7;
    }
    goto LABEL_15;
  }
  if ( (int)a2 == 327685 )
  {
    if ( *(long long *)(a3 + 40) != *(long long *)(a3 + 48) )
    {
      a2 = 327701;
      goto LABEL_7;
    }
LABEL_15:
    *(long long *)(a3 + 48) = 0;
  }
LABEL_7:
  result = fix_problem(a1, a2, a3);
  *(long long *)(a3 + 48) = -1;
  *(long long *)(a3 + 40) = -1;
  *(long long *)(a3 + 8) = 0;
  return result;
}


// Function: e2fsck_discard_blocks @ 0x2e530
long long e2fsck_discard_blocks(long long *a1, long long a2, long long a3)
{
  long long v4; // rbp
  long long result; // rax

  v4 = *a1;
  result = ext2fs_test_changed(*a1);
  if ( (int)result
    || (*((char *)a1 + 77) & 0x20) != 0 && (result = io_channel_discard(*(long long *)(v4 + 8), a2, a3)) != 0 )
  {
    *((int *)a1 + 19) &= ~0x2000u;
  }
  return result;
}


// Function: check_block_bitmaps @ 0x2e580
unsigned long long check_block_bitmaps(long long a1)
{
  long long v2; // r15
  unsigned long long v3; // r12
  void *memory; // rax
  long long v5; // rsi
  long long v6; // rdx
  void *v7; // rax
  int v8; // ecx
  long long v9; // rdi
  unsigned int v10; // ebx
  unsigned long long v11; // rbx
  long long v12; // rdi
  int v13; // ecx
  long long v14; // rax
  long long v15; // rdi
  int block_bitmap_start2; // eax
  long long v17; // rdi
  unsigned int v19; // ebx
  unsigned long long v20; // rbx
  long long v21; // r14
  long long v22; // rdi
  int v23; // ecx
  int v24; // ebp
  long long v25; // r15
  unsigned int v26; // ebx
  unsigned long long v27; // rbx
  long long v28; // rdi
  unsigned long long v29; // r14
  long long v30; // rax
  int v31; // ecx
  long long v32; // rdx
  unsigned int v33; // r14d
  int v34; // r9d
  long long block_bitmap_range2; // rax
  long long v36; // rax
  int v37; // eax
  long long v38; // rdx
  long long v39; // rcx
  long long v40; // r8
  int v41; // r14d
  void *v42; // rax
  long long v43; // rdx
  long long v44; // rdi
  unsigned long long v45; // r14
  long long v46; // rax
  unsigned int (*v47)(long long, long long, long long, long long); // rax
  long long v48; // rdi
  int v49; // ecx
  long long v50; // rax
  long long v51; // rdi
  int v52; // eax
  int v53; // eax
  int v54; // r9d
  unsigned int i; // r12d
  int v56; // ebp
  unsigned long long v57; // rbp
  int v58; // eax
  int v59; // esi
  int v60; // eax
  long long v61; // rdx
  unsigned long long v62; // [rsp+0h] [rbp-168h]
  unsigned int v63; // [rsp+0h] [rbp-168h]
  unsigned int v64; // [rsp+0h] [rbp-168h]
  int v65; // [rsp+0h] [rbp-168h]
  unsigned int v66; // [rsp+8h] [rbp-160h]
  int v67; // [rsp+Ch] [rbp-15Ch]
  unsigned int v68; // [rsp+10h] [rbp-158h]
  int v69; // [rsp+14h] [rbp-154h]
  long long v70; // [rsp+20h] [rbp-148h]
  int v71; // [rsp+28h] [rbp-140h]
  void *s; // [rsp+38h] [rbp-130h] BYREF
  void *s1; // [rsp+40h] [rbp-128h] BYREF
  void *s2; // [rsp+48h] [rbp-120h] BYREF
  char v75[8]; // [rsp+50h] [rbp-118h] BYREF
  int v76; // [rsp+58h] [rbp-110h]
  int block_bitmap_end2; // [rsp+5Ch] [rbp-10Ch]
  long long v78; // [rsp+78h] [rbp-F0h]
  unsigned long long v79; // [rsp+80h] [rbp-E8h]
  unsigned int v80; // [rsp+90h] [rbp-D8h]
  long long v81; // [rsp+A0h] [rbp-C8h]
  char v82[40]; // [rsp+C0h] [rbp-A8h] BYREF
  unsigned long long v83; // [rsp+E8h] [rbp-80h]
  unsigned int v84; // [rsp+100h] [rbp-68h]
  unsigned long long v85; // [rsp+128h] [rbp-40h]

  v2 = *(long long *)a1;
  v85 = __readfsqword(0x28u);
  v3 = ext2fs_blocks_count(*(long long *)(v2 + 32));
  memory = (void *)e2fsck_allocate_memory(a1, *(unsigned int *)(v2 + 40), "actual bitmap buffer");
  v5 = *(unsigned int *)(v2 + 40);
  s1 = memory;
  s2 = (void *)e2fsck_allocate_memory(a1, v5, "bitmap block buffer");
  clear_problem_context(v75, v5, v6);
  v7 = (void *)e2fsck_allocate_memory(a1, 4LL * *(unsigned int *)(v2 + 48), "free block count array");
  v8 = *(int *)(v2 + 192);
  v9 = *(long long *)(a1 + 416);
  s = v7;
  v10 = *(int *)(*(long long *)(v2 + 32) + 20LL) >> v8;
  if ( v10 < (unsigned long long)ext2fs_get_block_bitmap_start2(v9)
    || (v11 = (unsigned long long)(ext2fs_blocks_count(*(long long *)(v2 + 32)) - 1) >> *(int *)(v2 + 192),
        v11 > ext2fs_get_block_bitmap_end2(*(long long *)(a1 + 416))) )
  {
    v12 = *(long long *)(v2 + 32);
    v13 = *(int *)(v2 + 192);
    v81 = 1;
    v78 = (unsigned int)(*(int *)(v12 + 20) >> v13);
    v14 = ext2fs_blocks_count(v12);
    v15 = *(long long *)(a1 + 416);
    v79 = (unsigned long long)(v14 - 1) >> *(int *)(v2 + 192);
    block_bitmap_start2 = ext2fs_get_block_bitmap_start2(v15);
    v17 = *(long long *)(a1 + 416);
    v76 = block_bitmap_start2;
LABEL_4:
    block_bitmap_end2 = ext2fs_get_block_bitmap_end2(v17);
    fix_problem(a1, 327696, v75);
    *(int *)(a1 + 72) |= 1u;
    goto LABEL_5;
  }
  v19 = *(int *)(*(long long *)(v2 + 32) + 20LL) >> *(int *)(v2 + 192);
  if ( v19 < (unsigned long long)ext2fs_get_block_bitmap_start2(*(long long *)(v2 + 88))
    || (v20 = (unsigned long long)(ext2fs_blocks_count(*(long long *)(v2 + 32)) - 1) >> *(int *)(v2 + 192),
        v20 > ext2fs_get_block_bitmap_end2(*(long long *)(v2 + 88))) )
  {
    v48 = *(long long *)(v2 + 32);
    v49 = *(int *)(v2 + 192);
    v81 = 2;
    v78 = (unsigned int)(*(int *)(v48 + 20) >> v49);
    v50 = ext2fs_blocks_count(v48);
    v51 = *(long long *)(v2 + 88);
    v79 = (unsigned long long)(v50 - 1) >> *(int *)(v2 + 192);
    v52 = ext2fs_get_block_bitmap_start2(v51);
    v17 = *(long long *)(v2 + 88);
    v76 = v52;
    goto LABEL_4;
  }
  v69 = 0;
  v21 = v2;
  while ( 2 )
  {
    v22 = *(long long *)(v21 + 32);
    v23 = *(int *)(v21 + 192);
    v24 = 0;
    v25 = v21;
    v79 = -1;
    v26 = *(int *)(v22 + 20);
    v71 = 0;
    v78 = -1;
    v68 = 0;
    v27 = v26 >> v23;
    v67 = 0;
    v70 = 0;
    v66 = 0;
    while ( ext2fs_blocks_count(v22) > v27 )
    {
      v32 = *(long long *)(v25 + 32);
      v33 = *(int *)(v32 + 36);
      v62 = ((v27 >> *(int *)(v25 + 192)) - (unsigned int)(*(int *)(v32 + 20) >> *(int *)(v25 + 192))) % v33;
      v34 = ext2fs_fast_test_block_bitmap2(*(long long *)(a1 + 416));
      if ( v62
        || *(int *)(v25 + 48) - 1 == v66
        || (*(char *)(a1 + 77) & 0x20) != 0
        || (v63 = v34,
            block_bitmap_range2 = ext2fs_get_block_bitmap_range2(
                                    *(long long *)(a1 + 416),
                                    v27 >> *(int *)(v25 + 192),
                                    *(unsigned int *)(*(long long *)(v25 + 32) + 36LL),
                                    s1),
            v34 = v63,
            block_bitmap_range2)
        || (v36 = ext2fs_get_block_bitmap_range2(
                    *(long long *)(v25 + 88),
                    v27 >> *(int *)(v25 + 192),
                    *(unsigned int *)(*(long long *)(v25 + 32) + 36LL),
                    s2),
            v34 = v63,
            v36)
        || (v37 = memcmp(s1, s2, v33 >> 3), v34 = v63, v37) )
      {
        v41 = v34;
        if ( !v69 )
        {
          v65 = v34;
          v53 = ext2fs_fast_test_block_bitmap2(*(long long *)(v25 + 88));
          v34 = v65;
          v41 = v53;
        }
        if ( (v34 != 0) == (v41 == 0) )
        {
          if ( v34 || (v42 = &loc_50004, !v41) )
          {
            v54 = ext2fs_bg_flags_test(v25, v66, 2);
            LODWORD(v42) = 327685;
            if ( v54 )
            {
              v83 = v27;
              v84 = v66;
              if ( (unsigned int)fix_problem(a1, &loc_50018, v82) )
                ext2fs_bg_flags_clear(v25, v66, 2);
              LODWORD(v42) = 327685;
            }
          }
          if ( v78 == -1 )
          {
            v79 = v27;
            v78 = v27;
            v68 = (unsigned int)v42;
          }
          else if ( (int)v42 == v68 && (v43 = 1 << *(int *)(v25 + 192), v79 == v27 - v43) )
          {
            v79 += v43;
          }
          else
          {
            v64 = (unsigned int)v42;
            sub_2E470(a1, v68, (long long)v75);
            v78 = v27;
            v79 = v27;
            v68 = v64;
          }
          *(int *)(a1 + 72) |= 0x40u;
          ++v71;
          *(int *)(a1 + 76) &= ~0x2000u;
        }
        ++v24;
        if ( v41 )
        {
          if ( v27 > v3 )
          {
            sub_2E530((long long *)a1, v3, v27 - v3);
            v3 = ext2fs_blocks_count(*(long long *)(v25 + 32));
          }
          v44 = *(long long *)(v25 + 32);
          if ( *(int *)(v44 + 36) == v24 )
            goto LABEL_38;
          v45 = v27 >> *(int *)(v25 + 192);
          v46 = ext2fs_blocks_count(v44);
          v31 = *(int *)(v25 + 192);
          if ( (unsigned long long)(v46 - 1) >> v31 != v45 )
            goto LABEL_14;
        }
        else
        {
          v28 = *(long long *)(v25 + 32);
          ++v67;
          ++v70;
          if ( v3 > v27 )
            v3 = v27;
          if ( *(int *)(v28 + 36) != v24 )
          {
            v29 = v27 >> *(int *)(v25 + 192);
            v30 = ext2fs_blocks_count(v28);
            v31 = *(int *)(v25 + 192);
            if ( v29 != (unsigned long long)(v30 - 1) >> v31 )
              goto LABEL_14;
          }
          if ( v3 <= v27 )
            sub_2E530((long long *)a1, v3, v27 + 1 - v3);
        }
        v44 = *(long long *)(v25 + 32);
      }
      else
      {
        v58 = ext2fs_bitcount(s1, v33 >> 3, v38, v39, v40, v63);
        v44 = *(long long *)(v25 + 32);
        v59 = *(int *)(v44 + 36);
        v67 = v59 - v58;
        v27 += (unsigned int)((v59 - 1) << *(int *)(v25 + 192));
        v70 += (unsigned int)(v59 - v58);
      }
LABEL_38:
      v3 = ext2fs_blocks_count(v44);
      *((int *)s + v66) = v67;
      v47 = *(unsigned int (**)(long long, long long, long long, long long))(a1 + 352);
      ++v66;
      if ( v47 && v47(a1, 5, v66, (unsigned int)(2 * *(int *)(v25 + 48))) )
        goto LABEL_5;
      v67 = 0;
      v31 = *(int *)(v25 + 192);
      v24 = 0;
LABEL_14:
      v22 = *(long long *)(v25 + 32);
      v27 += 1 << v31;
    }
    v21 = v25;
    if ( v78 != -1 )
      sub_2E470(a1, v68, (long long)v75);
    if ( !v71 )
    {
      *(int *)(a1 + 72) &= ~0x40u;
      goto LABEL_53;
    }
    v60 = end_problem_latch(a1, 64);
    *(int *)(a1 + 72) &= ~0x40u;
    if ( v60 == 1 )
    {
      ext2fs_free_block_bitmap(*(long long *)(v25 + 88));
      if ( !ext2fs_copy_bitmap(*(long long *)(a1 + 416), v25 + 88) )
      {
        ext2fs_set_bitmap_padding(*(long long *)(v25 + 88));
        ext2fs_mark_bb_dirty(v25);
        memset(s, 0, 4LL * *(unsigned int *)(v25 + 48));
        ++v69;
        continue;
      }
      clear_problem_context(v75, v25 + 88, v61);
      fix_problem(a1, &loc_50013, v75);
      *(int *)(a1 + 72) |= 1u;
    }
    else
    {
      if ( !v60 )
        ext2fs_unmark_valid(v25);
LABEL_53:
      for ( i = 0; *(int *)(v25 + 48) > i; ++i )
      {
        v56 = *((int *)s + i);
        if ( v56 != (unsigned int)ext2fs_bg_free_blocks_count(v25, i) )
        {
          v80 = i;
          v78 = (unsigned int)ext2fs_bg_free_blocks_count(v25, i);
          v79 = *((unsigned int *)s + i);
          if ( (unsigned int)fix_problem(a1, 327694, v75) )
          {
            ext2fs_bg_free_blocks_count_set(v25, i, *((unsigned int *)s + i));
            ext2fs_mark_super_dirty(v25);
          }
          else
          {
            ext2fs_unmark_valid(v25);
          }
        }
      }
      v57 = v70 << *(int *)(v25 + 192);
      if ( ext2fs_free_blocks_count(*(long long *)(v25 + 32)) != v57 )
      {
        v80 = 0;
        v78 = ext2fs_free_blocks_count(*(long long *)(v25 + 32));
        v79 = v57;
        if ( (unsigned int)fix_problem(a1, &loc_5000F, v75) )
        {
          ext2fs_free_blocks_count_set(*(long long *)(v25 + 32), v57);
          ext2fs_mark_super_dirty(v25);
        }
      }
    }
    break;
  }
LABEL_5:
  ext2fs_free_mem(&s);
  ext2fs_free_mem(&s1);
  ext2fs_free_mem(&s2);
  return v85 - __readfsqword(0x28u);
}


// Function: e2fsck_discard_inodes @ 0x2ee40
void e2fsck_discard_inodes(long long a1, long long a2, unsigned int a3, int a4)
{
  long long v6; // r13
  long long v7; // rdx
  int v9; // ecx
  unsigned int v10; // ecx
  unsigned int v11; // ebx
  int v12; // r12d
  long long v13; // rax
  long long v14; // rdx
  long long v15; // rdi
  int v16; // ecx
  int v17; // eax

  v6 = *(long long *)a1;
  if ( a3 && (v7 = *(long long *)(v6 + 32), *(int *)(v7 + 40) >= a3) )
  {
    if ( (*(char *)(a1 + 77) & 0x20) != 0 && (*(char *)(*(long long *)(v6 + 8) + 52LL) & 2) != 0 )
    {
      v9 = 128;
      if ( *(int *)(v7 + 76) )
        v9 = *(unsigned short *)(v7 + 88);
      v10 = (1024 << *(int *)(v7 + 24)) / v9;
      v11 = (a3 + v10 - 2) / v10;
      v12 = a3 + a4 - 1 - v11 * v10;
      v13 = ext2fs_inode_table_loc(v6, a2);
      v14 = *(long long *)(v6 + 32);
      v15 = v13;
      v16 = 128;
      if ( *(int *)(v14 + 76) )
        v16 = *(unsigned short *)(v14 + 88);
      v17 = v12 / ((1024 << *(int *)(v14 + 24)) / v16);
      if ( v17 )
        sub_2E530((long long *)a1, v15 + v11, v17);
    }
  }
  else
  {
    __printf_chk(1, "PROGRAMMING ERROR: Got start %d outside of group %d! Disabling discard\n", a3, a2);
    *(int *)(a1 + 76) &= ~0x2000u;
  }
}


// Function: check_inode_end @ 0x2ef40
unsigned long long check_inode_end(long long *a1, long long a2, long long a3)
{
  long long v4; // rbp
  unsigned int v5; // r12d
  long long v6; // rsi
  unsigned int v7; // ebx
  long long v8; // rdi
  long long v10; // rsi
  unsigned int v11; // [rsp+Ch] [rbp-9Ch] BYREF
  long long v12[10]; // [rsp+10h] [rbp-98h] BYREF
  long long v13; // [rsp+60h] [rbp-48h]
  unsigned long long v14; // [rsp+78h] [rbp-30h]

  v4 = *a1;
  v14 = __readfsqword(0x28u);
  clear_problem_context(v12, a2, a3);
  v5 = *(int *)(v4 + 48) * *(int *)(*(long long *)(v4 + 32) + 40LL);
  v12[0] = ext2fs_fudge_inode_bitmap_end(*(long long *)(v4 + 80), v5, &v11);
  if ( v12[0] )
  {
    v13 = 1;
LABEL_13:
    fix_problem(a1, 327697, v12);
    *((int *)a1 + 18) |= 1u;
    return v14 - __readfsqword(0x28u);
  }
  v6 = v11;
  if ( v11 != v5 )
  {
    v7 = v11 + 1;
    if ( v5 >= v11 + 1 )
    {
      while ( 1 )
      {
        v8 = *(long long *)(v4 + 80);
        if ( (unsigned int)v6 >= v7 )
          break;
        if ( !(unsigned int)ext2fs_test_inode_bitmap(v8, v7) )
        {
          if ( (unsigned int)fix_problem(a1, &loc_50001, v12) )
          {
            while ( v5 >= v7 )
            {
              v10 = v7++;
              ext2fs_mark_inode_bitmap(*(long long *)(v4 + 80), v10);
            }
            ext2fs_mark_ib_dirty(v4);
          }
          else
          {
            ext2fs_unmark_valid(v4);
          }
          v12[0] = ext2fs_fudge_inode_bitmap_end(*(long long *)(v4 + 80), v11, 0);
          if ( !v12[0] )
            return v14 - __readfsqword(0x28u);
          goto LABEL_20;
        }
        ++v7;
        v6 = v11;
        if ( v5 < v7 )
          goto LABEL_11;
      }
    }
    else
    {
LABEL_11:
      v8 = *(long long *)(v4 + 80);
    }
    v12[0] = ext2fs_fudge_inode_bitmap_end(v8, v6, 0);
    if ( v12[0] )
    {
LABEL_20:
      v13 = 2;
      goto LABEL_13;
    }
  }
  if ( (*(char *)(v4 + 19) & 2) != 0 )
  {
    if ( (unsigned int)fix_problem(a1, &loc_50001, v12) )
      ext2fs_mark_ib_dirty(v4);
    else
      ext2fs_unmark_valid(v4);
  }
  return v14 - __readfsqword(0x28u);
}


// Function: check_block_end @ 0x2f0f0
unsigned long long check_block_end(long long *a1, long long a2, long long a3)
{
  long long v4; // rbp
  unsigned long long v5; // r12
  unsigned long long v6; // rsi
  unsigned long long v7; // rbx
  long long v8; // rdi
  long long v10; // rdx
  long long v11; // r8
  unsigned long long v12; // rsi
  unsigned long long v13; // [rsp+8h] [rbp-A0h] BYREF
  long long v14[10]; // [rsp+10h] [rbp-98h] BYREF
  long long v15; // [rsp+60h] [rbp-48h]
  unsigned long long v16; // [rsp+78h] [rbp-30h]

  v4 = *a1;
  v16 = __readfsqword(0x28u);
  clear_problem_context(v14, a2, a3);
  v5 = *(unsigned int *)(v4 + 48) * (unsigned long long)*(unsigned int *)(*(long long *)(v4 + 32) + 36LL)
     + ext2fs_get_block_bitmap_start2(*(long long *)(v4 + 88))
     - 1;
  v14[0] = ext2fs_fudge_block_bitmap_end2(*(long long *)(v4 + 88), v5, &v13);
  if ( v14[0] )
  {
    v15 = 3;
LABEL_13:
    fix_problem(a1, 327697, v14);
    *((int *)a1 + 18) |= 1u;
    return v16 - __readfsqword(0x28u);
  }
  v6 = v13;
  if ( v13 != v5 )
  {
    v7 = v13 + 1;
    if ( v5 >= v13 + 1 )
    {
      while ( 1 )
      {
        v8 = *(long long *)(v4 + 88);
        if ( v6 >= v7 )
          break;
        if ( !(unsigned int)ext2fs_test_block_bitmap2(v8, v7 << *(int *)(v4 + 192)) )
        {
          if ( (unsigned int)fix_problem(a1, 327682, v14) )
          {
            while ( v5 >= v7 )
            {
              v12 = v7++;
              ext2fs_mark_block_bitmap2(
                *(long long *)(v4 + 88),
                v12 << *(int *)(v4 + 192),
                v10,
                *(unsigned int *)(v4 + 192),
                v11);
            }
            ext2fs_mark_bb_dirty(v4);
          }
          else
          {
            ext2fs_unmark_valid(v4);
          }
          v14[0] = ext2fs_fudge_block_bitmap_end2(*(long long *)(v4 + 88), v13, 0);
          if ( !v14[0] )
            return v16 - __readfsqword(0x28u);
          goto LABEL_20;
        }
        ++v7;
        v6 = v13;
        if ( v5 < v7 )
          goto LABEL_11;
      }
    }
    else
    {
LABEL_11:
      v8 = *(long long *)(v4 + 88);
    }
    v14[0] = ext2fs_fudge_block_bitmap_end2(v8, v6, 0);
    if ( v14[0] )
    {
LABEL_20:
      v15 = 4;
      goto LABEL_13;
    }
  }
  if ( (*(char *)(v4 + 19) & 1) != 0 )
  {
    if ( (unsigned int)fix_problem(a1, 327682, v14) )
      ext2fs_mark_bb_dirty(v4);
    else
      ext2fs_unmark_valid(v4);
  }
  return v16 - __readfsqword(0x28u);
}


// Function: check_block_bitmap_checksum @ 0x2f2f0
unsigned long long check_block_bitmap_checksum(long long *a1)
{
  long long v2; // rbx
  long long v3; // r12
  unsigned int v5; // r12d
  unsigned int v6; // r13d
  long long v7; // rdx
  long long v8; // rdi
  unsigned int v9; // ebx
  signed int v10; // r12d
  unsigned int v11; // eax
  int v12; // r8d
  int v13; // r9d
  long long v14; // [rsp+8h] [rbp-B0h] BYREF
  char v15[64]; // [rsp+10h] [rbp-A8h] BYREF
  unsigned int v16; // [rsp+50h] [rbp-68h]
  unsigned long long v17; // [rsp+78h] [rbp-40h]

  v2 = *a1;
  v17 = __readfsqword(0x28u);
  v14 = 0;
  v3 = *(long long *)(v2 + 32);
  if ( (unsigned int)sub_2F2E0(*(unsigned int *)(v3 + 100)) && !(unsigned int)ext2fs_test_bb_dirty(v2) )
  {
    v5 = *(int *)(v3 + 36);
    v6 = v5 >> 3;
    if ( ext2fs_get_mem(*(unsigned int *)(v2 + 40), &v14) )
    {
      v11 = (unsigned int)dcgettext(0, "check_block_bitmap_checksum: Memory allocation error", 5);
      com_err(a1[1], 0, (unsigned int)"%s", v11, v12, v13);
      fatal_error(a1, 0);
    }
    clear_problem_context(v15, &v14, v7);
    v8 = *a1;
    if ( *(int *)(*a1 + 48LL) )
    {
      v9 = 0;
      v10 = v5 & 0xFFFFFFF8;
      while ( 1 )
      {
        if ( !(unsigned int)ext2fs_bg_flags_test(v8, v9, 2) )
        {
          if ( ext2fs_get_block_bitmap_range2(
                 *(long long *)(*a1 + 88LL),
                 v10 * (unsigned long long)v9
               + (unsigned int)(*(int *)(*(long long *)(*a1 + 32LL) + 20LL) >> *(int *)(*a1 + 192LL)),
                 v10,
                 v14) )
          {
            goto LABEL_12;
          }
          if ( !(unsigned int)ext2fs_block_bitmap_csum_verify(*a1, v9, v14, v6) )
          {
            v16 = v9;
            if ( (unsigned int)fix_problem(a1, &loc_5001B, v15) )
              break;
          }
        }
        v8 = *a1;
        if ( *(int *)(*a1 + 48LL) <= ++v9 )
          goto LABEL_12;
      }
      ext2fs_mark_bb_dirty(*a1);
    }
LABEL_12:
    ext2fs_free_mem(&v14);
  }
  return v17 - __readfsqword(0x28u);
}


// Function: check_inode_bitmap_checksum @ 0x2f4a0
unsigned long long check_inode_bitmap_checksum(long long *a1)
{
  long long v2; // rbx
  long long v3; // r12
  unsigned int v5; // r12d
  unsigned int v6; // r13d
  long long v7; // rdx
  long long v8; // rdi
  unsigned int v9; // ebx
  signed int v10; // r12d
  unsigned int v11; // eax
  int v12; // r8d
  int v13; // r9d
  long long v14; // [rsp+8h] [rbp-B0h] BYREF
  char v15[64]; // [rsp+10h] [rbp-A8h] BYREF
  unsigned int v16; // [rsp+50h] [rbp-68h]
  unsigned long long v17; // [rsp+78h] [rbp-40h]

  v2 = *a1;
  v17 = __readfsqword(0x28u);
  v14 = 0;
  v3 = *(long long *)(v2 + 32);
  if ( (unsigned int)sub_2F2E0(*(unsigned int *)(v3 + 100)) && !(unsigned int)ext2fs_test_ib_dirty(v2) )
  {
    v5 = *(int *)(v3 + 40);
    v6 = v5 >> 3;
    if ( ext2fs_get_mem(*(unsigned int *)(v2 + 40), &v14) )
    {
      v11 = (unsigned int)dcgettext(0, "check_inode_bitmap_checksum: Memory allocation error", 5);
      com_err(a1[1], 0, (unsigned int)"%s", v11, v12, v13);
      fatal_error(a1, 0);
    }
    clear_problem_context(v15, &v14, v7);
    v8 = *a1;
    if ( *(int *)(*a1 + 48LL) )
    {
      v9 = 0;
      v10 = v5 & 0xFFFFFFF8;
      while ( 1 )
      {
        if ( !(unsigned int)ext2fs_bg_flags_test(v8, v9, 1) )
        {
          if ( ext2fs_get_inode_bitmap_range2(*(long long *)(*a1 + 80LL), v9 * v10 + 1, v10, v14) )
            goto LABEL_12;
          if ( !(unsigned int)ext2fs_inode_bitmap_csum_verify(*a1, v9, v14, v6) )
          {
            v16 = v9;
            if ( (unsigned int)fix_problem(a1, 327706, v15) )
              break;
          }
        }
        v8 = *a1;
        if ( *(int *)(*a1 + 48LL) <= ++v9 )
          goto LABEL_12;
      }
      ext2fs_mark_ib_dirty(*a1);
    }
LABEL_12:
    ext2fs_free_mem(&v14);
  }
  return v17 - __readfsqword(0x28u);
}


// Function: check_inode_bitmaps @ 0x2f680
unsigned long long check_inode_bitmaps(long long *a1, long long a2, long long a3)
{
  long long v3; // r15
  long long v4; // rbp
  int v5; // r13d
  void *memory; // rax
  long long v7; // rsi
  void *v8; // rax
  long long v9; // rdi
  unsigned int v10; // r12d
  unsigned int *v11; // rax
  long long v12; // rdi
  int inode_bitmap_start2; // eax
  long long v14; // rdi
  unsigned int v16; // r12d
  unsigned int v17; // r13d
  unsigned int *v18; // rax
  long long v19; // rdi
  unsigned int v20; // ebx
  unsigned int v21; // r15d
  unsigned int v22; // r14d
  long long v23; // r12
  unsigned int v24; // ecx
  int v25; // r11d
  unsigned int v26; // edx
  unsigned int v27; // ecx
  long long v28; // rdi
  unsigned int v29; // r11d
  int v30; // r11d
  int v31; // edx
  int v32; // eax
  int v33; // eax
  unsigned int v34; // edx
  long long v35; // rdx
  unsigned int (*v36)(long long, long long, long long, long long); // r10
  int v37; // eax
  unsigned int *v38; // rax
  long long v39; // rdi
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int fixed; // eax
  bool v44; // al
  unsigned int i; // r13d
  int v46; // r12d
  int v47; // r12d
  int v48; // eax
  long long v49; // rdx
  int v50; // [rsp+0h] [rbp-158h]
  unsigned int v51; // [rsp+4h] [rbp-154h]
  int v52; // [rsp+8h] [rbp-150h]
  int v53; // [rsp+Ch] [rbp-14Ch]
  int v54; // [rsp+Ch] [rbp-14Ch]
  int v55; // [rsp+Ch] [rbp-14Ch]
  int v56; // [rsp+Ch] [rbp-14Ch]
  int v57; // [rsp+10h] [rbp-148h]
  unsigned int v58; // [rsp+14h] [rbp-144h]
  int v59; // [rsp+18h] [rbp-140h]
  int v60; // [rsp+1Ch] [rbp-13Ch]
  int v61; // [rsp+28h] [rbp-130h]
  int v62; // [rsp+2Ch] [rbp-12Ch]
  void *s; // [rsp+30h] [rbp-128h] BYREF
  void *v64; // [rsp+38h] [rbp-120h] BYREF
  char v65[8]; // [rsp+40h] [rbp-118h] BYREF
  long long v66; // [rsp+48h] [rbp-110h]
  long long v67; // [rsp+68h] [rbp-F0h]
  long long v68; // [rsp+70h] [rbp-E8h]
  int v69; // [rsp+80h] [rbp-D8h]
  long long v70; // [rsp+90h] [rbp-C8h]
  char v71[40]; // [rsp+B0h] [rbp-A8h] BYREF
  long long v72; // [rsp+D8h] [rbp-80h]
  unsigned int v73; // [rsp+F0h] [rbp-68h]
  unsigned long long v74; // [rsp+118h] [rbp-40h]

  v3 = (long long)a1;
  v4 = *a1;
  v74 = __readfsqword(0x28u);
  v5 = *(int *)(*(long long *)(v4 + 32) + 40LL);
  clear_problem_context(v65, a2, a3);
  memory = (void *)e2fsck_allocate_memory(a1, 4LL * *(unsigned int *)(v4 + 48), "free inode count array");
  v7 = *(unsigned int *)(v4 + 48);
  s = memory;
  v8 = (void *)e2fsck_allocate_memory(a1, 4 * v7, "directory count array");
  v9 = a1[45];
  v64 = v8;
  if ( (unsigned int)ext2fs_get_inode_bitmap_start2(v9) > 1
    || (v10 = **(int **)(v4 + 32), v10 > (unsigned int)ext2fs_get_inode_bitmap_end2(*(long long *)(v3 + 360))) )
  {
    v11 = *(unsigned int **)(v4 + 32);
    v12 = *(long long *)(v3 + 360);
    v70 = 3;
    v67 = 1;
    v68 = *v11;
    inode_bitmap_start2 = ext2fs_get_inode_bitmap_start2(v12);
    v14 = *(long long *)(v3 + 360);
    LODWORD(v66) = inode_bitmap_start2;
LABEL_4:
    HIDWORD(v66) = ext2fs_get_inode_bitmap_end2(v14);
    fix_problem(v3, 327696, v65);
    *(int *)(v3 + 72) |= 1u;
    goto LABEL_5;
  }
  if ( (unsigned int)ext2fs_get_inode_bitmap_start2(*(long long *)(v4 + 80)) > 1
    || (v16 = **(int **)(v4 + 32), v16 > (unsigned int)ext2fs_get_inode_bitmap_end2(*(long long *)(v4 + 80))) )
  {
    v38 = *(unsigned int **)(v4 + 32);
    v39 = *(long long *)(v4 + 80);
    v70 = 4;
    v67 = 1;
    v68 = *v38;
    v40 = ext2fs_get_inode_bitmap_start2(v39);
    v14 = *(long long *)(v4 + 80);
    LODWORD(v66) = v40;
    goto LABEL_4;
  }
  v17 = v5 + 1;
  v57 = 0;
  v60 = sub_2F650(*(long long *)(v4 + 32));
  v50 = 0;
  while ( 2 )
  {
    v66 = 0;
    if ( v60 )
      v50 -= ((unsigned int)ext2fs_bg_flags_test(v4, 0, 1) == 0) - 1;
    v18 = *(unsigned int **)(v4 + 32);
    if ( !*v18 )
    {
      v59 = v66;
      if ( (int)v66 )
      {
        sub_2E470(v3, 0, (long long)v65);
        v59 = 0;
      }
      goto LABEL_67;
    }
    v19 = v3;
    v20 = 0;
    v21 = 1;
    v61 = 0;
    v22 = 0;
    v23 = v19;
    v58 = 0;
    v52 = 0;
    v51 = 0;
    v59 = 0;
    do
    {
      v28 = *(long long *)(v23 + 360);
      if ( v50 )
      {
        v29 = v18[10];
        if ( v21 % v29 == 1 )
        {
          if ( (unsigned int)ext2fs_test_inode_bitmap_range(v28, v21, v29) )
          {
            v51 = *(int *)(*(long long *)(v4 + 32) + 40LL);
            v24 = v51;
            v21 += v51 - 1;
            v59 += v51;
            v17 = v51 != 0;
LABEL_58:
            sub_2EE40(v23, v20, v17, v24 + 1 - v17);
            goto LABEL_35;
          }
          v28 = *(long long *)(v23 + 360);
        }
        v30 = ext2fs_fast_test_inode_bitmap2(v28, v21);
        if ( !v57 )
        {
          if ( !v30 )
          {
            v18 = *(unsigned int **)(v4 + 32);
            ++v22;
            v24 = v18[10];
            goto LABEL_14;
          }
          v30 = 0;
          goto LABEL_48;
        }
        v31 = v30;
      }
      else
      {
        v41 = ext2fs_fast_test_inode_bitmap2(v28, v21);
        v31 = v41;
        v30 = v41;
        if ( !v57 )
        {
          v54 = v41;
          v42 = ext2fs_fast_test_inode_bitmap2(*(long long *)(v4 + 80), v21);
          v31 = v54;
          v30 = v42;
        }
      }
      if ( (v31 != 0) == (v30 == 0) )
      {
        if ( !v31 )
        {
          v32 = 327688;
          if ( v30 )
          {
            if ( !(int)v66 )
            {
LABEL_29:
              HIDWORD(v66) = v21;
              LODWORD(v66) = v21;
              v58 = v32;
LABEL_30:
              *(int *)(v23 + 72) |= 0x40u;
              ++v61;
              *(int *)(v23 + 76) &= ~0x2000u;
              goto LABEL_31;
            }
LABEL_51:
            if ( v32 == v58 && HIDWORD(v66) == v21 - 1 )
            {
              HIDWORD(v66) = v21;
            }
            else
            {
              v62 = v32;
              v56 = v30;
              sub_2E470(v23, v58, (long long)v65);
              HIDWORD(v66) = v21;
              LODWORD(v66) = v21;
              v30 = v56;
              v58 = v62;
            }
            goto LABEL_30;
          }
        }
        if ( !v50 )
        {
LABEL_50:
          v32 = 327689;
          if ( !(int)v66 )
            goto LABEL_29;
          goto LABEL_51;
        }
LABEL_48:
        v55 = v30;
        v72 = v21;
        v73 = v20;
        fixed = fix_problem(v23, 327705, v71);
        v30 = v55;
        if ( fixed )
        {
          ext2fs_bg_flags_clear(v4, v20, 1);
          v50 = 0;
          v30 = v55;
        }
        goto LABEL_50;
      }
LABEL_31:
      ++v22;
      v53 = v30;
      if ( v30 )
      {
        v33 = ext2fs_test_inode_bitmap2(*(long long *)(v23 + 376), v21);
        v25 = v53;
        v52 -= (v33 == 0) - 1;
        if ( v22 > v17 )
        {
          sub_2EE40(v23, v20, v17, v22 - v17);
          v18 = *(unsigned int **)(v4 + 32);
          v25 = v53;
          v34 = v18[10];
          v17 = v34 + 1;
        }
        else
        {
          v18 = *(unsigned int **)(v4 + 32);
          v34 = v18[10];
        }
        if ( v22 == v34 )
          goto LABEL_35;
        goto LABEL_18;
      }
      v18 = *(unsigned int **)(v4 + 32);
      v24 = v18[10];
LABEL_14:
      ++v51;
      ++v59;
      if ( v17 > v22 )
        v17 = v22;
      if ( v22 == v24 )
      {
        v44 = 1;
        goto LABEL_56;
      }
      v25 = 0;
LABEL_18:
      if ( *v18 != v21 )
      {
        v26 = *v18;
        v27 = v21;
        goto LABEL_20;
      }
      v24 = v22;
      v44 = v25 == 0;
LABEL_56:
      if ( v24 >= v17 && v44 )
        goto LABEL_58;
LABEL_35:
      if ( (*(char *)(v23 + 77) & 0x20) != 0
        && (*(char *)(*(long long *)(v4 + 8) + 52LL) & 2) != 0
        && !(unsigned int)ext2fs_bg_flags_test(v4, v20, 4) )
      {
        ext2fs_bg_flags_set(v4, v20, 4);
        ext2fs_group_desc_csum_set(v4, v20);
      }
      v18 = *(unsigned int **)(v4 + 32);
      v35 = v20++;
      v36 = *(unsigned int (**)(long long, long long, long long, long long))(v23 + 352);
      v17 = v18[10] + 1;
      *((int *)s + v35) = v51;
      *((int *)v64 + v35) = v52;
      if ( v36 )
      {
        if ( v36(v23, 5, *(int *)(v4 + 48) + v20, (unsigned int)(2 * *(int *)(v4 + 48))) )
          goto LABEL_5;
        v18 = *(unsigned int **)(v4 + 32);
      }
      v26 = *v18;
      if ( v60 )
      {
        if ( v21 == v26 )
        {
          v50 = 0;
          v3 = v23;
          goto LABEL_64;
        }
        v37 = ext2fs_bg_flags_test(v4, v20, 1);
        v52 = 0;
        v27 = v21;
        v51 = 0;
        v22 = 0;
        v50 = v37 != 0;
        v18 = *(unsigned int **)(v4 + 32);
        v26 = *v18;
      }
      else
      {
        v50 = 0;
        v27 = v21;
        v22 = 0;
        v52 = 0;
        v51 = 0;
      }
LABEL_20:
      ++v21;
    }
    while ( v27 < v26 );
    v3 = v23;
LABEL_64:
    if ( (int)v66 )
      sub_2E470(v3, v58, (long long)v65);
    if ( !v61 )
    {
LABEL_67:
      *(int *)(v3 + 72) &= ~0x40u;
      goto LABEL_68;
    }
    v48 = end_problem_latch(v3, 48);
    *(int *)(v3 + 72) &= ~0x40u;
    if ( v48 == 1 )
    {
      ext2fs_free_inode_bitmap(*(long long *)(v4 + 80));
      if ( !ext2fs_copy_bitmap(*(long long *)(v3 + 360), v4 + 80) )
      {
        ext2fs_set_bitmap_padding(*(long long *)(v4 + 80));
        ext2fs_mark_ib_dirty(v4);
        memset(s, 0, 4LL * *(unsigned int *)(v4 + 48));
        memset(v64, 0, 4LL * *(unsigned int *)(v4 + 48));
        ++v57;
        continue;
      }
      clear_problem_context(v65, v4 + 80, v49);
      fix_problem(v3, 327698, v65);
      *(int *)(v3 + 72) |= 1u;
    }
    else
    {
      if ( !v48 )
        ext2fs_unmark_valid(v4);
LABEL_68:
      for ( i = 0; *(int *)(v4 + 48) > i; ++i )
      {
        v46 = *((int *)s + i);
        if ( v46 != (unsigned int)ext2fs_bg_free_inodes_count(v4, i) )
        {
          v69 = i;
          LODWORD(v66) = ext2fs_bg_free_inodes_count(v4, i);
          HIDWORD(v66) = *((int *)s + i);
          if ( (unsigned int)fix_problem(v3, 327691, v65) )
          {
            ext2fs_bg_free_inodes_count_set(v4, i, *((unsigned int *)s + i));
            ext2fs_mark_super_dirty(v4);
          }
          else
          {
            ext2fs_unmark_valid(v4);
          }
        }
        v47 = *((int *)v64 + i);
        if ( v47 != (unsigned int)ext2fs_bg_used_dirs_count(v4, i) )
        {
          v69 = i;
          LODWORD(v66) = ext2fs_bg_used_dirs_count(v4, i);
          HIDWORD(v66) = *((int *)v64 + i);
          if ( (unsigned int)fix_problem(v3, 327692, v65) )
          {
            ext2fs_bg_used_dirs_count_set(v4, i, *((unsigned int *)v64 + i));
            ext2fs_mark_super_dirty(v4);
          }
          else
          {
            ext2fs_unmark_valid(v4);
          }
        }
      }
      if ( *(int *)(*(long long *)(v4 + 32) + 16LL) != v59 )
      {
        LODWORD(v66) = *(int *)(*(long long *)(v4 + 32) + 16LL);
        v69 = -1;
        HIDWORD(v66) = v59;
        if ( (unsigned int)fix_problem(v3, &loc_5000D, v65) )
        {
          *(int *)(*(long long *)(v4 + 32) + 16LL) = v59;
          ext2fs_mark_super_dirty(v4);
        }
      }
    }
    break;
  }
LABEL_5:
  ext2fs_free_mem(&s);
  ext2fs_free_mem(&v64);
  return v74 - __readfsqword(0x28u);
}


// Function: e2fsck_pass5 @ 0x2ffd0
unsigned long long e2fsck_pass5(long long a1)
{
  long long v2; // rsi
  long long v3; // rdx
  unsigned int (*v4)(long long, long long, long long, long long); // rax
  long long v5; // rdx
  long long v7; // rdx
  long long v8; // rdx
  long long v9; // rdi
  long long v10; // rdi
  long long v11; // rdi
  long long v12; // rax
  long long v13; // r13
  char *v14; // rax
  struct timeval v15[5]; // [rsp+0h] [rbp-D8h] BYREF
  char v16[104]; // [rsp+50h] [rbp-88h] BYREF
  unsigned long long v17; // [rsp+B8h] [rbp-20h]

  v17 = __readfsqword(0x28u);
  v2 = *(long long *)(*(long long *)a1 + 8LL);
  init_resource_track(v15);
  clear_problem_context(v16, v2, v3);
  if ( (*(char *)(a1 + 76) & 2) == 0 )
  {
    v2 = 327680;
    fix_problem(a1, 327680, v16);
  }
  v4 = *(unsigned int (**)(long long, long long, long long, long long))(a1 + 352);
  if ( !v4 || (v2 = 5, !v4(a1, 5, 0, (unsigned int)(2 * *(int *)(*(long long *)a1 + 48LL)))) )
  {
    e2fsck_read_bitmaps(a1);
    sub_2E580(a1);
    if ( (*(char *)(a1 + 72) & 3) == 0 )
    {
      sub_2F680((long long *)a1, v2, v5);
      if ( (*(char *)(a1 + 72) & 3) == 0 )
      {
        sub_2EF40((long long *)a1, v2, v7);
        if ( (*(char *)(a1 + 72) & 3) == 0 )
        {
          sub_2F0F0((long long *)a1, v2, v8);
          if ( (*(char *)(a1 + 72) & 3) == 0 )
          {
            sub_2F4A0((long long *)a1);
            sub_2F2F0((long long *)a1);
            ext2fs_free_inode_bitmap(*(long long *)(a1 + 360));
            v9 = *(long long *)(a1 + 376);
            *(long long *)(a1 + 360) = 0;
            ext2fs_free_inode_bitmap(v9);
            v10 = *(long long *)(a1 + 416);
            *(long long *)(a1 + 376) = 0;
            ext2fs_free_block_bitmap(v10);
            v11 = *(long long *)(a1 + 912);
            *(long long *)(a1 + 416) = 0;
            ext2fs_free_block_bitmap(v11);
            v12 = *(long long *)a1;
            *(long long *)(a1 + 912) = 0;
            v13 = *(long long *)(v12 + 8);
            v14 = dcgettext(0, "Pass 5", 5);
            print_resource_track(a1, v14, v15, v13);
          }
        }
      }
    }
  }
  return v17 - __readfsqword(0x28u);
}


// Function: mark_buffer_clean @ 0x301d0
void mark_buffer_clean(long long a1)
{
  *(char *)(a1 + 24) &= ~1u;
}


// Function: ex_compar @ 0x301e0
long long ex_compar(long long *a1, long long *a2)
{
  unsigned long long v2; // rax
  bool v3; // cc
  long long result; // rax

  v2 = a2[1];
  v3 = a1[1] <= v2;
  if ( a1[1] < v2 )
    return 0xFFFFFFFFLL;
  result = 1;
  if ( v3 )
    return (unsigned int)(*((int *)a1 + 4) - *((int *)a2 + 4));
  return result;
}


// Function: ex_len_compar @ 0x30210
long long ex_len_compar(long long *a1, long long *a2)
{
  long long result; // rax

  result = 1;
  if ( *((int *)a1 + 4) >= *((int *)a2 + 4) )
    return (unsigned int)-(a1[1] > a2[1]);
  return result;
}


// Function: e2fsck_journal_sb_csum @ 0x30240
long long e2fsck_journal_sb_csum(long long a1)
{
  int v1; // ebp
  long long result; // rax

  v1 = *(int *)(a1 + 252);
  *(int *)(a1 + 252) = 0;
  result = ext2fs_crc32c_le(0xFFFFFFFFLL, a1, 1024);
  *(int *)(a1 + 252) = v1;
  return result;
}


// Function: process_journal_block @ 0x30280
long long process_journal_block(long long a1, unsigned long long *a2, long long a3, long long a4, long long a5, long long *a6)
{
  unsigned long long v6; // rbp
  long long v7; // rdi
  long long result; // rax

  v6 = *a2;
  if ( !*a2 )
    return 2;
  v7 = *(long long *)(a1 + 32);
  if ( *(unsigned int *)(v7 + 20) > v6 || ext2fs_blocks_count(v7) <= v6 )
    return 2;
  result = 0;
  if ( a3 >= 0 )
    *a6 = a3;
  return result;
}


// Function: __errcode_to_errno @ 0x302d0
long long __errcode_to_errno(long long a1, const char *a2, int a3)
{
  long long result; // rax
  const char *v5; // rax

  if ( !a1 )
    return 0;
  v5 = (const char *)error_message(a1);
  __fprintf_chk(stderr, 1, "Error \"%s\" encountered in function %s at line %d\n", v5, a2, a3);
  result = (unsigned int)-(int)a1;
  if ( a1 >= 257 )
    return 4294967282LL;
  return result;
}


// Function: ext4_fc_read_extents @ 0x30330
long long ext4_fc_read_extents(long long a1, long long a2)
{
  long long extents; // rax

  if ( *(int *)(a1 + 984) == a2 )
    return 0;
  *(int *)(a1 + 984) = a2;
  extents = e2fsck_read_extents(a1, a1 + 944);
  return sub_302D0(extents, "ext4_fc_read_extents", 589);
}


// Function: make_room @ 0x30380
long long make_room(long long a1, int a2)
{
  int v2; // eax
  long long result; // rax
  long long v4; // rax

  v2 = *(int *)(a1 + 16);
  if ( v2 != *(int *)(a1 + 20) )
    goto LABEL_2;
  v4 = ext2fs_resize_mem(0, (unsigned int)(24 * v2 + 8184), a1 + 8);
  result = sub_302D0(v4, "make_room", 408);
  if ( !(int)result )
  {
    *(int *)(a1 + 20) += 341;
    v2 = *(int *)(a1 + 16);
LABEL_2:
    memmove(
      (void *)(*(long long *)(a1 + 8) + 24LL * a2 + 24),
      (const void *)(*(long long *)(a1 + 8) + 24LL * a2),
      24LL * (unsigned int)(v2 - a2));
    ++*(int *)(a1 + 16);
    return 0;
  }
  return result;
}


// Function: ex_sort_and_merge @ 0x30410
void ex_sort_and_merge(long long a1)
{
  size_t v1; // rsi
  long long v3; // rdx
  int *v4; // rdi
  size_t v5; // rsi
  int *v6; // rax
  unsigned int v7; // ecx
  long long v8; // r10
  unsigned int v9; // esi
  long long v10; // rdx
  long long v11; // r8
  long long v12; // rdi
  long long v13; // rax
  long long v14; // r9
  long long v15; // r8
  const __m128i *v16; // rdx
  __m128i v17; // xmm0
  const __m128i *v18; // rdi
  char *v19; // rdi

  v1 = *(unsigned int *)(a1 + 16);
  if ( (unsigned int)v1 > 1 )
  {
    qsort(*(void **)(a1 + 8), v1, 0x18u, (__compar_fn_t)sub_30210);
    v3 = *(unsigned int *)(a1 + 16);
    if ( (int)v3 )
    {
      v4 = *(int **)(a1 + 8);
      v5 = 0;
      v6 = v4 + 4;
      while ( *v6 )
      {
        ++v5;
        v6 += 6;
        if ( v5 == v3 )
          goto LABEL_8;
      }
      *(int *)(a1 + 16) = v5;
      if ( !(int)v5 )
        return;
LABEL_8:
      qsort(v4, v5, 0x18u, (__compar_fn_t)sub_301E0);
      v7 = *(int *)(a1 + 16) - 1;
      if ( *(int *)(a1 + 16) != 1 )
      {
        v8 = *(long long *)(a1 + 8);
        v9 = 0;
        do
        {
          v10 = v8 + 24LL * v9;
          v11 = v9 + 1;
          v12 = *(unsigned int *)(v10 + 16);
          v13 = 24 * v11;
          v14 = v8 + 24 * v11;
          if ( v12 + *(long long *)(v10 + 8) == *(long long *)(v14 + 8)
            && *(long long *)v10 + v12 == *(long long *)v14
            && ((*(int *)(v14 + 20) ^ *(int *)(v10 + 20)) & 2) == 0 )
          {
            *(int *)(v10 + 16) += *(int *)(v14 + 16);
            if ( (unsigned int)v11 < v7 )
            {
              v15 = v9 + 2;
              v16 = (const __m128i *)(v8 + 24 * v15);
              do
              {
                v17 = _mm_loadu_si128(v16);
                v18 = v16;
                v16 = (const __m128i *)((char *)v16 + 24);
                v19 = &v18->m128i_i8[-24 * v15];
                *(__m128i *)&v19[v13] = v17;
                *(long long *)&v19[v13 + 16] = v16[-1].m128i_i64[1];
              }
              while ( (const __m128i *)(v8 + 24 + 24 * (v15 + v7 - 2 - v9)) != v16 );
            }
            *(int *)(a1 + 16) = v7;
          }
          else
          {
            v7 = *(int *)(a1 + 16);
            ++v9;
          }
          --v7;
        }
        while ( v9 < v7 );
      }
    }
  }
}


// Function: ext4_modify_extent_list @ 0x30560
long long ext4_modify_extent_list(long long *a1, long long a2, long long *a3, char a4, long long a5)
{
  unsigned long long v7; // r15
  long long v8; // rdi
  unsigned int v9; // r12d
  long long v10; // r13
  unsigned long long v11; // r11
  long long v12; // rdx
  unsigned long long v13; // rbp
  long long v14; // rdx
  unsigned long long v15; // rsi
  long long v16; // r11
  int v17; // ecx
  long long v18; // rax
  unsigned int v19; // ebp
  long long v20; // r8
  long long v21; // rax
  long long result; // rax
  long long *v23; // rax
  unsigned int v24; // r12d
  long long v25; // rdx
  long long v26; // rcx
  __m128i *v27; // rax
  long long v28; // rdx
  long long v29; // r10
  long long v30; // rsi
  unsigned int v31; // [rsp+8h] [rbp-50h]
  long long v33; // [rsp+10h] [rbp-48h]
  long long v34; // [rsp+18h] [rbp-40h]

  v7 = a3[1];
  v33 = *a3;
  v31 = *((int *)a3 + 4);
  v34 = a3[2];
  if ( !*(int *)(a2 + 16) )
  {
LABEL_11:
    if ( (a4 & 1) == 0 && v31 )
    {
      sub_30380(a2, *(int *)(a2 + 16));
      v23 = (long long *)(*(long long *)(a2 + 8) + 24LL * (unsigned int)(*(int *)(a2 + 16) - 1));
      *v23 = v33;
      v23[1] = v7;
      v23[2] = v34;
    }
    v19 = 0;
    sub_30410(a2);
    if ( *(int *)(a2 + 16) )
    {
      do
      {
        v21 = v19++;
        ext2fs_mark_block_bitmap_range2(
          *(long long *)(*a1 + 88LL),
          *(long long *)(*(long long *)(a2 + 8) + 24 * v21),
          *(unsigned int *)(*(long long *)(a2 + 8) + 24 * v21 + 16),
          *a1,
          v20);
      }
      while ( *(int *)(a2 + 16) > v19 );
    }
    ext2fs_mark_bb_dirty(*a1);
    return 0;
  }
  v8 = *(long long *)(a2 + 8);
  v9 = 0;
  while ( 1 )
  {
    v10 = 24LL * v9;
    v11 = *(long long *)(v8 + v10 + 8);
    v12 = *(unsigned int *)(v8 + v10 + 16);
    if ( v11 + v12 - 1 < v7 )
      goto LABEL_5;
    v13 = v7 - 1 + v31;
    if ( v11 > v13 )
      goto LABEL_11;
    ext2fs_unmark_block_bitmap_range2(*(long long *)(*a1 + 88LL), *(long long *)(v8 + 24LL * v9), v12, 3LL * v9, a5);
    v8 = *(long long *)(a2 + 8);
    v14 = v8 + v10;
    v15 = *(long long *)(v8 + v10 + 8);
    v16 = *(unsigned int *)(v8 + v10 + 16);
    if ( v15 < v7 )
      break;
    v17 = *(int *)(v8 + v10 + 16);
    if ( v13 < v15 + v16 - 1 )
    {
      v18 = (int)(v31 + v7 - v15);
      *(long long *)v14 += v18;
      *(int *)(v14 + 16) = v15 + v17 - (v31 + v7);
      *(long long *)(v14 + 8) = v15 + v18;
      goto LABEL_11;
    }
    *(int *)(v14 + 16) = 0;
LABEL_5:
    if ( *(int *)(a2 + 16) <= ++v9 )
      goto LABEL_11;
  }
  if ( v13 >= v15 + v16 - 1 )
  {
    *(int *)(v14 + 16) = v7 - v15;
    goto LABEL_5;
  }
  v24 = v9 + 1;
  result = sub_30380(a2, v24);
  if ( !(int)result )
  {
    v25 = *(long long *)(a2 + 8);
    v26 = v25 + v10;
    v27 = (__m128i *)(v25 + 24LL * v24);
    *v27 = _mm_loadu_si128((const __m128i *)(v25 + v10));
    v28 = *(long long *)(v25 + v10 + 16);
    v29 = *(long long *)(v26 + 8);
    v27[1].m128i_i64[0] = v28;
    v30 = (int)(v31 + v7 - v29);
    v27->m128i_i64[1] += v30;
    v27->m128i_i64[0] += v30;
    v27[1].m128i_i32[0] = v29 + v28 - (v31 + v7);
    *(int *)(v26 + 16) = v7 - *(int *)(v26 + 8);
    goto LABEL_11;
  }
  return result;
}


// Function: ext4_add_extent_to_list @ 0x30790
long long ext4_add_extent_to_list(long long *a1, long long a2, long long *a3, long long a4, long long a5)
{
  return sub_30560(a1, a2, a3, 0, a5);
}


// Function: ext4_del_extent_from_list @ 0x307a0
long long ext4_del_extent_from_list(long long *a1, long long a2, long long *a3, long long a4, long long a5)
{
  return sub_30560(a1, a2, a3, 1, a5);
}


// Function: ext4_fc_replay_fixup_iblocks @ 0x307c0
long long ext4_fc_replay_fixup_iblocks(long long a1, long long a2)
{
  long long result; // rax

  result = *(unsigned int *)(a1 + 32);
  if ( (result & 0x80000) != 0 )
  {
    if ( *(short *)(a1 + 40) != 0xF30A )
    {
      *(long long *)(a1 + 40) = 0;
      *(int *)(a1 + 48) = 0;
      *(short *)(a1 + 40) = -3318;
      *(short *)(a1 + 44) = 4;
      return 4294963978LL;
    }
  }
  else if ( (result & 0x10000000) != 0 )
  {
    *(__m128i *)(a1 + 40) = _mm_loadu_si128((const __m128i *)(a2 + 40));
    *(__m128i *)(a1 + 56) = _mm_loadu_si128((const __m128i *)(a2 + 56));
    *(__m128i *)(a1 + 72) = _mm_loadu_si128((const __m128i *)(a2 + 72));
    *(long long *)(a1 + 88) = *(long long *)(a2 + 88);
    *(int *)(a1 + 96) = *(int *)(a2 + 96);
  }
  return result;
}


// Function: ext4_fc_flush_extents @ 0x30840
long long ext4_fc_flush_extents(long long a1, long long a2)
{
  long long result; // rax

  result = *(unsigned int *)(a1 + 984);
  if ( (int)result )
  {
    if ( result != a2 )
    {
      e2fsck_rewrite_extent_tree(a1, a1 + 944);
      result = ext2fs_free_mem(a1 + 952);
      *(_OWORD *)(a1 + 944) = 0;
      *(_OWORD *)(a1 + 960) = 0;
      *(_OWORD *)(a1 + 976) = 0;
    }
  }
  return result;
}


// Function: ext4_fc_handle_inode @ 0x308a0
long long ext4_fc_handle_inode(long long *a1, unsigned int *a2)
{
  unsigned int v3; // eax
  long long v4; // rax
  size_t v5; // r15
  long long mem; // rbp
  long long *v8; // rdx
  __m128i *v9; // rax
  const __m128i *v10; // roff
  long long v11; // rbp
  char *v12; // r12
  long long v13; // rdx
  long long v14; // rax
  long long v15; // rdx
  long long v16; // rcx
  long long v17; // rax
  long long v18; // rdi
  unsigned int v19; // [rsp+8h] [rbp-60h]
  unsigned int v20; // [rsp+Ch] [rbp-5Ch]
  __m128i *v21; // [rsp+10h] [rbp-58h] BYREF
  void *dest; // [rsp+18h] [rbp-50h] BYREF
  long long v23[9]; // [rsp+20h] [rbp-48h] BYREF

  v23[1] = __readfsqword(0x28u);
  v3 = *a2;
  v21 = 0;
  dest = 0;
  v19 = v3;
  v4 = *(long long *)(*a1 + 32LL);
  if ( *(int *)(v4 + 76) && *(short *)(v4 + 88) > 0x80u )
  {
    v20 = *((unsigned short *)a2 + 66) + 128;
    v5 = (int)v20;
  }
  else
  {
    v20 = 128;
    v5 = 128;
  }
  mem = ext2fs_get_mem(v5, &v21);
  if ( !mem )
  {
    mem = ext2fs_get_mem(v5, &dest);
    if ( !mem )
    {
      sub_30840((long long)a1, (int)v19);
      mem = ext2fs_read_inode_full(*a1, v19, v21, v20);
      if ( !mem )
      {
        memcpy(dest, a2 + 1, v5);
        v8 = dest;
        v9 = v21;
        v10 = (const __m128i *)dest;
        *v21 = _mm_loadu_si128((const __m128i *)dest);
        v11 = (long long)v21;
        v12 = (char *)dest;
        v9[1] = _mm_loadu_si128(v10 + 1);
        v9[2].m128i_i64[0] = v8[4];
        memcpy((void *)(v11 + 100), v12 + 100, v5 - 100);
        sub_307C0(v11, (long long)v12);
        v14 = sub_30170(v11, v12, v13, v23);
        mem = ext2fs_count_blocks(*a1, v19, v14);
        if ( !mem )
        {
          v17 = sub_30170(v21, v19, v15, v16);
          ext2fs_iblk_set(*a1, v17, v23[0]);
          ext2fs_inode_csum_set(*a1, v19, v21);
          mem = ext2fs_write_inode_full(*a1, v19, v21, v20);
          if ( !mem )
          {
            v18 = *(long long *)(*a1 + 80LL);
            if ( v21[1].m128i_i16[5] )
              ext2fs_mark_inode_bitmap2(v18, v19);
            else
              ext2fs_unmark_inode_bitmap2(v18, v19);
            ext2fs_mark_ib_dirty(*a1);
          }
        }
      }
    }
  }
  ext2fs_free_mem(&v21);
  ext2fs_free_mem(&dest);
  return sub_302D0(mem, "ext4_fc_handle_inode", 793);
}


// Function: ext4_fc_handle_add_extent @ 0x30ad0
long long ext4_fc_handle_add_extent(long long *a1, long long *a2)
{
  long long v2; // rbp
  long long v3; // rax
  long long result; // rax
  long long v5; // rax
  long long v6; // rcx
  long long v7; // r8
  __int128 v8; // [rsp+0h] [rbp-58h] BYREF
  long long v9; // [rsp+10h] [rbp-48h]
  long long v10[7]; // [rsp+20h] [rbp-38h] BYREF

  v2 = *a2;
  v10[3] = __readfsqword(0x28u);
  v3 = a2[1];
  v10[0] = v2;
  v10[1] = v3;
  sub_30840((long long)a1, (unsigned int)v2);
  result = sub_30330((long long)a1, (unsigned int)v2);
  if ( !(int)result )
  {
    v8 = 0;
    v9 = 0;
    v5 = ((long long (*)(__int128 *, char *, long long))ext2fs_decode_extent)(&v8, (char *)v10 + 4, 12);
    result = sub_302D0(v5, "ext4_fc_handle_add_extent", 814);
    if ( !(int)result )
      return sub_30790(a1, (long long)(a1 + 118), (long long *)&v8, v6, v7);
  }
  return result;
}


// Function: ext4_fc_handle_del_range @ 0x30b90
long long ext4_fc_handle_del_range(long long *a1, long long *a2)
{
  long long v2; // rbp
  long long result; // rax
  long long v4; // rcx
  long long v5; // r8
  unsigned int v6; // [rsp+Ch] [rbp-3Ch]
  long long v7[7]; // [rsp+10h] [rbp-38h] BYREF

  v2 = *a2;
  v7[3] = __readfsqword(0x28u);
  v6 = *((int *)a2 + 2);
  sub_30840((long long)a1, (int)v2);
  v7[0] = 0;
  v7[1] = HIDWORD(v2);
  v7[2] = v6;
  result = sub_30330((long long)a1, (int)v2);
  if ( !(int)result )
    return sub_307A0(a1, (long long)(a1 + 118), v7, v4, v5);
  return result;
}


// Function: tl_to_darg @ 0x30c70
long long tl_to_darg(long long a1, long long a2, long long *a3)
{
  long long v4; // rax
  int v5; // eax
  void *v6; // rax
  size_t v7; // rbx

  v4 = (unsigned int)HIDWORD(*a3);
  *(long long *)a1 = (unsigned int)*a3;
  *(long long *)(a1 + 16) = v4;
  v5 = sub_30C60(*(unsigned short *)(a2 + 2));
  *(int *)(a1 + 8) = v5 - 8;
  v6 = malloc(v5 - 7);
  *(long long *)(a1 + 24) = v6;
  if ( !v6 )
    return 4294967284LL;
  v7 = *(int *)(a1 + 8);
  *((char *)memcpy(v6, a3 + 1, v7) + v7) = 0;
  return 0;
}


// Function: ext4_fc_handle_link_and_create @ 0x30ce0
long long ext4_fc_handle_link_and_create(long long *a1, long long a2, long long *a3)
{
  long long v3; // r13
  unsigned int v4; // r12d
  unsigned int v6; // r14d
  long long inode; // rax
  unsigned int v8; // eax
  void *v9; // rbp
  short v10; // ax
  unsigned int v11; // ebx
  void *v12; // rbp
  unsigned int v13; // r12d
  long long v14; // rax
  int v15[4]; // [rsp+0h] [rbp-108h] BYREF
  unsigned int v16; // [rsp+10h] [rbp-F8h]
  void *ptr; // [rsp+18h] [rbp-F0h]
  short v18[84]; // [rsp+20h] [rbp-E8h] BYREF
  unsigned long long v19; // [rsp+C8h] [rbp-40h]

  v3 = *a1;
  v19 = __readfsqword(0x28u);
  v4 = sub_30C70((long long)v15, a2, a3);
  if ( !v4 )
  {
    sub_30840((long long)a1, 0);
    v6 = v16;
    inode = ext2fs_read_inode(v3, v16, v18);
    v8 = sub_302D0(inode, "ext4_fc_handle_link_and_create", 674);
    v9 = ptr;
    v4 = v8;
    if ( !v8 )
    {
      v10 = v18[0] & 0xF000;
      if ( (v18[0] & 0xF000) == 0x8000 )
      {
        v11 = 1;
      }
      else
      {
        switch ( v10 )
        {
          case 16384:
            v11 = 2;
            break;
          case 8192:
            v11 = 3;
            break;
          case 24576:
            v11 = 4;
            break;
          case -24576:
            return 7;
          case 4096:
            v11 = 5;
            break;
          case -16384:
            v11 = 6;
            break;
          default:
            v9 = ptr;
            v4 = -22;
            goto LABEL_12;
        }
      }
      v12 = ptr;
      v13 = v15[0];
      ext2fs_unlink(v3, v15[0], ptr, v6, 1);
      v14 = ext2fs_link(v3, v13, v12, v6, v11);
      v4 = sub_302D0(v14, "ext4_fc_handle_link_and_create", 707);
      free(v12);
      return v4;
    }
LABEL_12:
    free(v9);
  }
  return v4;
}


// Function: ext4_fc_handle_unlink @ 0x30eb0
long long ext4_fc_handle_unlink(long long *a1, long long a2, long long *a3)
{
  unsigned int v3; // r12d
  unsigned int v4; // r12d
  void *v5; // rbp
  long long v6; // rax
  int v8[4]; // [rsp+0h] [rbp-48h] BYREF
  long long v9; // [rsp+10h] [rbp-38h]
  void *ptr; // [rsp+18h] [rbp-30h]
  unsigned long long v11; // [rsp+28h] [rbp-20h]

  v11 = __readfsqword(0x28u);
  v3 = sub_30C70((long long)v8, a2, a3);
  if ( !v3 )
  {
    v4 = v9;
    sub_30840((long long)a1, v9);
    v5 = ptr;
    v6 = ext2fs_unlink(*a1, v8[0], ptr, v4, 0);
    v3 = sub_302D0(v6, "ext4_fc_handle_unlink", 655);
    free(v5);
  }
  return v3;
}


// Function: e2fsck_journal_fix_bad_inode @ 0x30fa0
long long e2fsck_journal_fix_bad_inode(int *a1, long long a2, long long a3, long long a4, long long a5)
{
  long long v6; // rbp
  long long v7; // rdx
  int v8; // r8d
  unsigned int v9; // r9d
  int v10; // eax
  __int128 v11; // xmm0
  long long v12; // rdi
  long long result; // rax
  long long v14; // rdx
  int v15; // r8d
  int fixed; // r8d

  v6 = *(long long *)(*(long long *)a1 + 32LL);
  v8 = sub_30F90(*(unsigned int *)(v6 + 92), a2, a2, a4, a5, *(unsigned int *)(v6 + 96));
  v10 = *(int *)(v6 + 224);
  if ( v8 )
  {
    *(int *)(a2 + 8) = v10;
    if ( (unsigned int)fix_problem(a1, 15, v7) )
    {
      if ( *(int *)(v6 + 224) )
        __printf_chk(1, "*** journal has been deleted ***\n\n");
      goto LABEL_4;
    }
    return 2133571504;
  }
  if ( v10 )
  {
    *(int *)(a2 + 8) = v10;
    if ( (unsigned int)fix_problem(a1, 15, v7) )
    {
LABEL_4:
      v11 = 0;
      *(double *)&v11 = sub_30190(v6, 1, 0.0);
      *(_OWORD *)(v6 + 268) = v11;
      *(int *)(v6 + 332) = 0;
      *(_OWORD *)(v6 + 284) = v11;
      *(_OWORD *)(v6 + 300) = v11;
      *(_OWORD *)(v6 + 316) = v11;
      v12 = *(long long *)a1;
      *(int *)(v6 + 224) = 0;
      a1[18] |= 0x80u;
      *(int *)(v12 + 16) &= ~0x200u;
      sub_30C30(v12, 1);
      return 0;
    }
    return 2133571504;
  }
  v15 = sub_30F60(v9);
  result = 0;
  if ( v15 )
  {
    fixed = fix_problem(a1, 23, v14);
    result = 2133571395;
    if ( fixed )
    {
      sub_30C30(*(long long *)a1, 1);
      return 0;
    }
  }
  return result;
}


// Function: e2fsck_journal_verify_csum_type @ 0x31500
long long e2fsck_journal_verify_csum_type(long long a1, long long a2)
{
  int has_csum_v2or3; // r8d
  long long result; // rax

  has_csum_v2or3 = jbd2_journal_has_csum_v2or3();
  result = 1;
  if ( has_csum_v2or3 )
    return *(char *)(a2 + 80) == 4;
  return result;
}


// Function: e2fsck_journal_sb_csum_verify @ 0x31530
long long e2fsck_journal_sb_csum_verify(long long a1, long long a2)
{
  int has_csum_v2or3; // r8d
  long long result; // rax
  int v4; // ebx

  has_csum_v2or3 = jbd2_journal_has_csum_v2or3();
  result = 1;
  if ( has_csum_v2or3 )
  {
    v4 = ext2fs_swab32(*(unsigned int *)(a2 + 252));
    return v4 == (unsigned int)sub_30240(a2);
  }
  return result;
}


// Function: ext4_fc_replay_scan @ 0x31690
long long ext4_fc_replay_scan(long long a1, long long a2, int a3, int a4, long long a5, unsigned long long a6)
{
  unsigned long long v6; // r14
  long long v8; // r15
  long long v9; // rcx
  unsigned long long v10; // r12
  long long v11; // rcx
  unsigned int v12; // ebx
  long long result; // rax
  long long v14; // rax
  unsigned int v15; // ebx
  int v16; // eax
  long long v17; // rdx
  int v18; // eax
  int v19; // edx
  long long v20; // rax
  int v21; // eax
  long long v22; // rdx
  int v23; // eax
  int v24; // eax
  char *v25; // [rsp+0h] [rbp-88h]
  unsigned long long v26; // [rsp+8h] [rbp-80h]
  __int128 v27; // [rsp+10h] [rbp-78h] BYREF
  long long v28; // [rsp+20h] [rbp-68h]
  __m128i v29; // [rsp+30h] [rbp-58h] BYREF
  unsigned long long v30; // [rsp+48h] [rbp-40h]

  v6 = a2 + 40;
  v30 = __readfsqword(0x28u);
  v8 = **(long long **)(a1 + 112);
  v9 = *(int *)(a1 + 120);
  v27 = 0;
  v28 = 0;
  v10 = a2 + v9 + 39;
  v11 = *(unsigned int *)(v8 + 996);
  if ( !(int)v11 )
  {
    *(long long *)(v8 + 1008) = 0;
    *(_OWORD *)(v8 + 944) = 0;
    *(_OWORD *)(v8 + 960) = 0;
    *(_OWORD *)(v8 + 976) = 0;
    *(_OWORD *)(v8 + 992) = 0;
    if ( *(short *)(a2 + 40) != 9 )
      return 0;
    v11 = *(unsigned int *)(v8 + 996);
  }
  if ( a3 != (int)v11 )
    return 2161395794LL;
  *(int *)(v8 + 996) = a3 + 1;
  v25 = &v29.m128i_i8[4];
  if ( v6 >= v10 )
    return 1;
  while ( 1 )
  {
    v12 = *(int *)v6;
    if ( (unsigned short)*(int *)v6 == 8 )
      break;
    if ( (unsigned short)v12 > 8u )
    {
      if ( (short)v12 != 9 )
      {
LABEL_8:
        if ( *(int *)(v8 + 992) )
          return 0;
        return 4294967171LL;
      }
      v14 = *(long long *)(v6 + 4);
      if ( (int)v14 )
        return 4294967201LL;
      if ( a4 != HIDWORD(v14) )
        return 4294967274LL;
      goto LABEL_14;
    }
    if ( (short)v12 != 1 )
    {
      if ( (unsigned short)(v12 - 2) > 5u )
        goto LABEL_8;
LABEL_14:
      ++*(int *)(v8 + 1004);
      v15 = HIWORD(v12);
      v16 = sub_30C60(v15);
      *(int *)(v8 + 1008) = jbd2_chksum(a1, *(unsigned int *)(v8 + 1008), v17, (unsigned int)(v16 + 4));
      goto LABEL_15;
    }
    v15 = HIWORD(v12);
    v29 = _mm_loadu_si128((const __m128i *)(v6 + 4));
    v20 = ((long long (*)(__int128 *, char *, long long, long long, long long, unsigned long long, char *, unsigned long long))ext2fs_decode_extent)(
            &v27,
            v25,
            12,
            v11,
            a5,
            a6,
            v25,
            v26);
    ++*(int *)(v8 + 1004);
    v26 = v20;
    v21 = sub_30C60(v15);
    v23 = jbd2_chksum(a1, *(unsigned int *)(v8 + 1008), v22, (unsigned int)(v21 + 4));
    a6 = v26;
    *(int *)(v8 + 1008) = v23;
    if ( (int)v26 )
      return 0;
LABEL_15:
    v6 += (unsigned short)v15 + 4LL;
    if ( v10 <= v6 )
      return 1;
  }
  ++*(int *)(v8 + 1004);
  v26 = *(long long *)(v6 + 4);
  v18 = jbd2_chksum(a1, *(unsigned int *)(v8 + 1008), v6, 8);
  if ( a4 == (int)v26 )
  {
    a6 = HIDWORD(v26);
    if ( v18 == HIDWORD(v26) )
    {
      v24 = *(int *)(v8 + 1004);
      v15 = HIWORD(v12);
      *(int *)(v8 + 1008) = 0;
      *(int *)(v8 + 992) = v24;
      goto LABEL_15;
    }
  }
  v19 = *(int *)(v8 + 992);
  result = 2161395793LL;
  *(int *)(v8 + 1008) = 0;
  if ( !v19 )
    return result;
  return 0;
}


// Function: ext4_fc_replay @ 0x31940
long long ext4_fc_replay(long long a1, long long a2, int a3, int a4, long long a5, unsigned long long a6)
{
  long long *v8; // rbx
  unsigned int v9; // r14d
  unsigned long long v10; // r13
  unsigned long long v11; // r12
  int v12; // eax
  int v13; // edx
  long long *v14; // rsi
  long long v16; // rdi
  long long bitmaps; // rax
  long long v18; // r13
  long long v19; // rdx
  long long v20; // rdi
  short v21; // ax
  long long v22; // rbp
  long long v23; // rdi
  int v24; // [rsp+4h] [rbp-44h] BYREF
  unsigned long long v25; // [rsp+8h] [rbp-40h]

  v25 = __readfsqword(0x28u);
  v8 = **(long long ***)(a1 + 112);
  if ( a3 )
  {
    if ( !*((int *)v8 + 248) )
    {
LABEL_18:
      v9 = 0;
      if ( *((int *)v8 + 250) == a3 )
      {
        ext2fs_calculate_summary_stats(*v8, 0);
        ext2fs_write_block_bitmap(*v8);
        ext2fs_write_inode_bitmap(*v8);
        v22 = *v8;
        ext2fs_mark_super_dirty(*v8);
        ext2fs_set_gdt_csum(v22);
        v23 = *v8;
        *(short *)(*(long long *)(*v8 + 32LL) + 58LL) = *((short *)v8 + 506);
        ext2fs_flush(v23);
      }
      return v9;
    }
    v9 = 1;
    if ( a3 != *((int *)v8 + 250) )
    {
      v16 = *v8;
      *((int *)v8 + 250) = a3;
      *(int *)(v16 + 16) |= 0x200000u;
      bitmaps = ext2fs_read_bitmaps();
      v9 = sub_302D0(bitmaps, "ext4_fc_replay", 873);
      if ( v9 )
        return v9;
      v18 = *v8;
      v19 = *(long long *)(*v8 + 32LL);
      v20 = *v8;
      v21 = *(short *)(v19 + 58);
      *((short *)v8 + 506) = v21;
      *(short *)(v19 + 58) = v21 | 0x22;
      ext2fs_mark_super_dirty(v20);
      ext2fs_flush(v18);
    }
    v10 = a2 + 40;
    v11 = a2 + *(int *)(a1 + 120) + 39;
    if ( a2 + 40 < v11 )
    {
      while ( 2 )
      {
        v12 = *(int *)v10;
        v13 = *((int *)v8 + 248);
        v14 = (long long *)(v10 + 4);
        v24 = *(int *)v10;
        if ( v13 )
        {
          *((int *)v8 + 248) = v13 - 1;
          switch ( (short)v12 )
          {
            case 1:
              v9 = sub_30AD0(v8, v14);
              goto LABEL_8;
            case 2:
              v9 = sub_30B90(v8, v14);
              goto LABEL_8;
            case 3:
            case 4:
              v9 = sub_30CE0(v8, (long long)&v24, (long long *)(v10 + 4));
              goto LABEL_8;
            case 5:
              v9 = sub_30EB0(v8, (long long)&v24, (long long *)(v10 + 4));
              goto LABEL_8;
            case 6:
              v9 = sub_308A0(v8, (unsigned int *)v14);
              goto LABEL_8;
            case 7:
            case 9:
LABEL_8:
              if ( (v9 & 0x80000000) == 0 )
                goto LABEL_9;
              return v9;
            case 8:
              sub_30840((long long)v8, 0);
LABEL_9:
              v9 = 1;
              v10 += HIWORD(v24) + 4LL;
              if ( v11 <= v10 )
                return v9;
              continue;
            default:
              return (unsigned int)-125;
          }
        }
        goto LABEL_18;
      }
    }
    return v9;
  }
  *((int *)v8 + 250) = 0;
  return sub_31690(a1, a2, a4, a5, a5, a6);
}


// Function: jbd2_journal_bmap @ 0x31c30
long long jbd2_journal_bmap(long long a1, long long a2, long long *a3)
{
  long long v4; // r9
  long long v5; // rdx
  long long result; // rax
  int v7; // eax
  long long v8[3]; // [rsp+0h] [rbp-18h] BYREF

  v4 = a2;
  v5 = *(long long *)(a1 + 136);
  v8[1] = __readfsqword(0x28u);
  result = 0;
  if ( v5 )
  {
    v7 = ext2fs_bmap2(**(long long **)v5, *(int *)(v5 + 8), (int)v5 + 12, 0, 0, a2, 0, (long long)v8);
    v4 = v8[0];
    result = (unsigned int)-v7;
  }
  *a3 = v4;
  return result;
}


// Function: getblk @ 0x31cb0
long long getblk(int *a1, long long a2, int a3)
{
  long long result; // rax
  long long *v5; // rdx
  bool v6; // zf
  long long v7; // rdx

  result = e2fsck_allocate_memory(*(long long *)a1, *(int *)(**(long long **)a1 + 40LL) + 40, "block buffer");
  if ( result )
  {
    v5 = *(long long **)a1;
    v6 = a1[2] == 1;
    *(long long *)result = *(long long *)a1;
    if ( v6 )
      v7 = *(long long *)(*v5 + 8LL);
    else
      v7 = v5[77];
    *(long long *)(result + 8) = v7;
    *(int *)(result + 16) = a3;
    *(long long *)(result + 32) = a2;
  }
  return result;
}


// Function: sync_blockdev @ 0x31d20
long long sync_blockdev(long long a1)
{
  long long *v1; // rax
  long long v2; // rdi

  v1 = *(long long **)a1;
  if ( *(int *)(a1 + 8) == 1 )
    v2 = *(long long *)(*v1 + 8LL);
  else
    v2 = v1[77];
  return (*(long long (**)(void))(*(long long *)(v2 + 8) + 56LL))() != 0 ? 0xFFFFFFFB : 0;
}


// Function: ll_rw_block @ 0x31d60
void ll_rw_block(int a1, long long a2, int a3, long long a4)
{
  long long v4; // r13
  long long v6; // rbx
  long long v7; // rbp
  long long blk64; // rsi
  int v9; // r8d
  int v10; // r9d
  long long v11; // rcx
  const char *v12; // rdx
  long long v13; // rdi

  if ( a3 > 0 )
  {
    v4 = a4 + 8LL * a3;
    v6 = a4;
    do
    {
      while ( 1 )
      {
        v6 += 8;
        v7 = *(long long *)(v6 - 8);
        if ( !a1 )
          break;
        if ( a1 != 1 || (*(char *)(v7 + 24) & 1) == 0 )
          goto LABEL_4;
        blk64 = io_channel_write_blk64(*(long long *)(v7 + 8), *(long long *)(v7 + 32), 1, v7 + 40);
        if ( blk64 )
        {
          v11 = *(long long *)(v7 + 32);
          v12 = "while writing block %llu\n";
          v13 = *(long long *)(*(long long *)v7 + 24LL);
          goto LABEL_14;
        }
        *(char *)(v7 + 24) = *(char *)(v7 + 24) & 0xFC | 2;
        if ( v6 == v4 )
          return;
      }
      if ( (*(char *)(v7 + 24) & 2) == 0 )
      {
        blk64 = io_channel_read_blk64(*(long long *)(v7 + 8), *(long long *)(v7 + 32), 1, v7 + 40);
        if ( blk64 )
        {
          v11 = *(long long *)(v7 + 32);
          v12 = "while reading block %llu\n";
          v13 = *(long long *)(*(long long *)v7 + 24LL);
LABEL_14:
          com_err(v13, blk64, (int)v12, v11, v9, v10);
          *(int *)(v7 + 20) = blk64;
          continue;
        }
        *(char *)(v7 + 24) |= 2u;
      }
LABEL_4:
      ;
    }
    while ( v6 != v4 );
  }
}


// Function: mark_buffer_dirty @ 0x31e80
void mark_buffer_dirty(long long a1)
{
  *(char *)(a1 + 24) |= 1u;
}


// Function: clear_v2_journal_fields @ 0x31e90
unsigned long long clear_v2_journal_fields(long long a1, long long a2, long long a3)
{
  long long *v3; // rbp
  long long v4; // rax
  char v6[104]; // [rsp+0h] [rbp-88h] BYREF
  unsigned long long v7; // [rsp+68h] [rbp-20h]

  v7 = __readfsqword(0x28u);
  v3 = **(long long ***)(a1 + 104);
  clear_problem_context(v6, a2, a3);
  if ( (unsigned int)fix_problem(v3, 42, v6) )
  {
    v4 = *v3;
    *((int *)v3 + 18) |= 0x4000u;
    memset((void *)(*(long long *)(a1 + 24) + 36LL), 0, (unsigned int)(*(int *)(v4 + 40) - 36));
    mark_buffer_dirty(*(long long *)(a1 + 16));
  }
  return v7 - __readfsqword(0x28u);
}


// Function: e2fsck_journal_load @ 0x31f20
long long e2fsck_journal_load(long long a1, long long a2, long long a3)
{
  long long v4; // r12
  int *v5; // rbp
  int *v6; // r13
  long long v7; // rdx
  long long v8; // rcx
  long long v9; // r8
  unsigned int v10; // eax
  long long v11; // rdx
  long long v12; // rsi
  int v13; // eax
  long long result; // rax
  bool v15; // zf
  unsigned int v16; // eax
  int v17; // r8d
  int v18; // r9d
  unsigned int v19; // eax
  long long v20; // r13
  int v21; // eax
  long long v22; // rdi
  unsigned int v23; // eax
  long long v24; // rdi
  long long v25; // r13
  long long v26; // r13
  const char *v27; // rsi
  unsigned int v28; // eax
  int v29; // r8d
  int v30; // r9d
  long long v31; // rdx
  long long v32; // [rsp+8h] [rbp-A0h] BYREF
  char v33[104]; // [rsp+10h] [rbp-98h] BYREF
  unsigned long long v34; // [rsp+78h] [rbp-30h]

  v34 = __readfsqword(0x28u);
  v4 = **(long long **)(a1 + 104);
  v32 = *(long long *)(a1 + 16);
  clear_problem_context(v33, a2, a3);
  ll_rw_block(0, 0, 1, (long long)&v32);
  if ( *(int *)(v32 + 20) )
  {
    v16 = (unsigned int)dcgettext(0, "reading journal superblock\n", 5);
    com_err(*(long long *)(v4 + 24), *(int *)(v32 + 20), (unsigned int)"%s", v16, v17, v18);
    return *(int *)(v32 + 20);
  }
  v5 = *(int **)(a1 + 24);
  v6 = v5;
  if ( *v5 != (unsigned int)sub_307B0(3225106840LL) )
    return sub_30FA0((int *)v4, (long long)v33, v7, v8, v9);
  v10 = sub_307B0((unsigned int)v5[1]);
  if ( v10 == 4 )
  {
    *(int *)(a1 + 32) = 2;
    if ( (unsigned int)sub_307B0((unsigned int)v5[16]) <= 1 )
    {
LABEL_18:
      v15 = (v6[10] & (unsigned int)ext2fs_swab32(4294967232LL)) == 0;
      result = 2133571395;
      if ( !v15 )
        return result;
      v15 = (v6[11] & (unsigned int)ext2fs_swab32(0xFFFFFFFFLL)) == 0;
      result = 2133571396;
      if ( !v15 )
        return result;
      goto LABEL_20;
    }
    if ( (unsigned int)uuid_is_null(*(long long *)(*(long long *)v4 + 32LL) + 208LL) )
      sub_31E90(a1, 0, v31);
    if ( (unsigned int)sub_307B0((unsigned int)v5[16]) > 1 )
    {
      fix_problem(v4, 16, v33);
      return 2133571414;
    }
    v13 = *(int *)(a1 + 32);
LABEL_8:
    if ( v13 <= 1 )
      goto LABEL_20;
    v6 = *(int **)(a1 + 24);
    goto LABEL_18;
  }
  if ( v10 > 4 )
  {
    v15 = v10 == 5;
    result = 2133571414;
    if ( v15 )
      return 2133571504;
    return result;
  }
  if ( v10 != 3 )
    return (-(long long)(v10 == 0) & 0xFFFFFFFFFFFFFFA6LL) + 2133571504;
  v12 = (unsigned int)v5[9];
  *(int *)(a1 + 32) = 1;
  if ( __PAIR64__(v5[10], v12) || (v11 = (unsigned int)v5[11], (int)v11) || v5[16] )
  {
    sub_31E90(a1, v12, v11);
    v13 = *(int *)(a1 + 32);
    goto LABEL_8;
  }
LABEL_20:
  if ( (unsigned int)jbd2_has_feature_csum2(a1) && (unsigned int)jbd2_has_feature_csum3(a1)
    || (unsigned int)jbd2_journal_has_csum_v2or3(a1) && (unsigned int)jbd2_has_feature_checksum(a1)
    || !sub_31500(a1, (long long)v5)
    || !sub_31530(a1, (long long)v5) )
  {
    return 2133571504;
  }
  if ( (unsigned int)jbd2_journal_has_csum_v2or3(a1) )
    *(int *)(a1 + 196) = jbd2_chksum(a1, 0xFFFFFFFFLL, v5 + 12, 16);
  if ( v5[3] != (unsigned int)sub_307B0(*(unsigned int *)(a1 + 120)) )
  {
    v26 = *(long long *)(v4 + 24);
    v27 = "%s: no valid journal superblock found\n";
LABEL_35:
    v28 = (unsigned int)dcgettext(0, v27, 5);
    com_err(*(long long *)(v4 + 8), 2133571504, v28, v26, v29, v30);
    return 2133571504;
  }
  v19 = sub_307B0((unsigned int)v5[4]);
  v20 = v19;
  if ( v19 < *(int *)(a1 + 128) )
  {
    *(int *)(a1 + 128) = v19;
    goto LABEL_31;
  }
  if ( v19 > *(int *)(a1 + 128) )
  {
    v26 = *(long long *)(v4 + 24);
    v27 = "%s: journal too short\n";
    goto LABEL_35;
  }
LABEL_31:
  v21 = sub_307B0((unsigned int)v5[6]);
  v22 = (unsigned int)v5[7];
  *(int *)(a1 + 144) = v21;
  *(int *)(a1 + 148) = v21;
  v23 = sub_307B0(v22);
  v24 = (unsigned int)v5[5];
  *(long long *)(a1 + 48) = v23;
  *(long long *)(a1 + 88) = (unsigned int)sub_307B0(v24);
  if ( (unsigned int)jbd2_has_feature_fast_commit(a1) )
  {
    if ( (unsigned int)v20 - (unsigned int)jbd2_journal_get_num_fc_blks(v5) > 0x3FF )
    {
      *(long long *)(a1 + 72) = v20;
      v25 = v20 - (int)jbd2_journal_get_num_fc_blks(v5);
      *(long long *)(a1 + 96) = v25;
      *(long long *)(a1 + 56) = v25 + 1;
      return 0;
    }
    v26 = *(long long *)(v4 + 24);
    v27 = "%s: incorrect fast commit blocks\n";
    goto LABEL_35;
  }
  *(long long *)(a1 + 96) = (unsigned int)v20;
  return 0;
}


// Function: e2fsck_journal_reset_super @ 0x32340
unsigned long long e2fsck_journal_reset_super(long long a1, int *a2, long long a3)
{
  int v4; // edx
  int v5; // eax
  long long v6; // rdi
  int v7; // edx
  long long v8; // rcx
  int v10[6]; // [rsp+0h] [rbp-38h] BYREF
  unsigned long long v11; // [rsp+18h] [rbp-20h]

  v11 = __readfsqword(0x28u);
  v4 = sub_307B0(3225106840LL);
  if ( *a2 != v4 || a2[1] != (unsigned int)sub_307B0(3) )
  {
    *a2 = v4;
    a2[1] = sub_307B0(4);
  }
  memset(a2 + 3, 0, *(unsigned int *)(*(long long *)a1 + 40LL) - 12LL);
  v5 = sub_307B0(*(unsigned int *)(*(long long *)a1 + 40LL));
  v6 = *(unsigned int *)(a3 + 128);
  a2[3] = v5;
  a2[4] = sub_307B0(v6);
  a2[5] = sub_307B0(1);
  uuid_generate(v10);
  a2[6] = sub_307B0(v10[3] ^ v10[2] ^ (unsigned int)(v10[1] ^ v10[0]));
  sub_31570(a3, a2);
  mark_buffer_dirty(*(long long *)(a3 + 16));
  ll_rw_block(1, 0, v7, v8);
  return v11 - __readfsqword(0x28u);
}


// Function: e2fsck_journal_fix_corrupt_super @ 0x32450
long long e2fsck_journal_fix_corrupt_super(int *a1, long long a2, long long a3, long long a4, long long a5, long long a6)
{
  long long v6; // rax
  unsigned int v7; // r12d
  long long v8; // rdx
  long long v9; // rcx
  long long v10; // r8
  long long result; // rax
  unsigned int v12; // eax

  v6 = *(long long *)(*(long long *)a1 + 32LL);
  v7 = *(int *)(v6 + 96);
  if ( (unsigned int)sub_30F90(*(unsigned int *)(v6 + 92), a2, a3, a4, a5, a6) )
  {
    if ( !(unsigned int)fix_problem(a1, 21, v8) )
      return 2133571504;
    sub_32340((long long)a1, *(int **)(a2 + 24), a2);
    *(int *)(a2 + 148) = 1;
    v12 = sub_30F60(v7);
    sub_30C30(*(long long *)a1, v12);
    return 0;
  }
  else
  {
    result = sub_30FA0(a1, v8, v8, v9, v10);
    if ( result )
      return 2133571504;
  }
  return result;
}


// Function: brelse @ 0x324e0
long long brelse(long long a1)
{
  long long v2[2]; // [rsp+8h] [rbp-10h] BYREF

  v2[0] = a1;
  if ( (*(char *)(a1 + 24) & 1) != 0 )
    ll_rw_block(1, 0, 1, (long long)v2);
  return ext2fs_free_mem(v2);
}


// Function: e2fsck_get_journal @ 0x32540
long long e2fsck_get_journal(long long a1, long long *a2, long long a3)
{
  long long v5; // rax
  long long v6; // r13
  long long v7; // rax
  long long v8; // rdx
  int *v9; // rbp
  long long v10; // rax
  long long v11; // rdi
  long long v12; // rsi
  long long inode; // r14
  long long v15; // rax
  long long v16; // rsi
  long long v17; // rdi
  long long v18; // rsi
  int v19; // r12d
  int v20; // eax
  bool v21; // zf
  long long v22; // rsi
  long long v23; // rdi
  long long v24; // rax
  long long v25; // rdi
  unsigned int v26; // edx
  long long v27; // rcx
  long long v28; // r8
  unsigned long long v29; // rsi
  unsigned long long v30; // rax
  int v31; // eax
  long long v32; // rdx
  long long v33; // rsi
  long long v34; // rax
  const void *v35; // r14
  long long v36; // r8
  const void *v37; // rsi
  long long v38; // rdx
  long long v39; // rcx
  long long v40; // r8
  unsigned long long v41; // rax
  long long v42; // rax
  long long v43; // rdx
  long long v44; // rdx
  long long (*v45)(long long, long long, int, int, long long, unsigned long long); // rcx
  long long (*v46)(long long, long long, int, int, long long, unsigned long long); // rax
  long long devname; // rax
  long long v48; // rax
  long long v49; // rsi
  long long v50; // rax
  int v51; // [rsp+0h] [rbp-A98h]
  long long v52; // [rsp+10h] [rbp-A88h]
  const void **v53; // [rsp+18h] [rbp-A80h]
  long long v54; // [rsp+20h] [rbp-A78h] BYREF
  int *v55; // [rsp+28h] [rbp-A70h] BYREF
  long long v56; // [rsp+30h] [rbp-A68h] BYREF
  long long v57; // [rsp+38h] [rbp-A60h] BYREF
  long long memory; // [rsp+40h] [rbp-A58h] BYREF
  long long v59; // [rsp+48h] [rbp-A50h] BYREF
  char v60[112]; // [rsp+50h] [rbp-A48h] BYREF
  long long v61[46]; // [rsp+C0h] [rbp-9D8h] BYREF
  int v62[256]; // [rsp+230h] [rbp-868h] BYREF
  char v63[1024]; // [rsp+630h] [rbp-468h] BYREF
  char v64[40]; // [rsp+A30h] [rbp-68h] BYREF
  unsigned long long v65; // [rsp+A58h] [rbp-40h]

  v65 = __readfsqword(0x28u);
  v5 = *(long long *)a1;
  v56 = 0;
  v57 = 0;
  memory = 0;
  v59 = 0;
  v6 = *(long long *)(v5 + 32);
  clear_problem_context(v60, a2, a3);
  memory = e2fsck_allocate_memory(a1, 208, "journal");
  if ( !memory )
    return 2133571398;
  v7 = e2fsck_allocate_memory(a1, 32, "kdev");
  v57 = v7;
  if ( !v7 )
    goto LABEL_33;
  v8 = memory;
  *(long long *)(v7 + 16) = a1;
  v9 = (int *)(v7 + 16);
  *(long long *)v7 = a1;
  *(int *)(v7 + 8) = 1;
  *(int *)(v7 + 24) = 2;
  *(long long *)(v8 + 112) = v7;
  v10 = *(long long *)a1;
  *(long long *)(v8 + 104) = v9;
  *(long long *)(v8 + 136) = 0;
  *(int *)(v8 + 120) = *(int *)(v10 + 40);
  if ( (unsigned int)uuid_is_null(v6 + 208) )
  {
    inode = 2133571369;
    if ( !*(int *)(v6 + 224) )
    {
LABEL_9:
      e2fsck_use_inode_shortcuts(a1, 0);
      if ( v57 )
        ext2fs_free_mem(&v57);
      if ( v56 )
        ext2fs_free_mem(&v56);
      if ( memory )
        ext2fs_free_mem(&memory);
      return inode;
    }
    v15 = e2fsck_allocate_memory(a1, 144, "journal inode");
    v56 = v15;
    if ( v15 )
    {
      v16 = *(unsigned int *)(v6 + 224);
      v17 = *(long long *)a1;
      *(long long *)v15 = a1;
      *(int *)(v15 + 8) = v16;
      inode = ext2fs_read_inode(v17, v16, v15 + 12);
      if ( inode )
      {
        if ( *(char *)(v6 + 253) == 1 )
        {
          v18 = v56;
          goto LABEL_24;
        }
      }
      else
      {
        v18 = v56;
        if ( !*(short *)(v56 + 38) )
        {
          LOBYTE(v19) = 0;
          inode = 2133571416;
          goto LABEL_22;
        }
        v19 = 0;
        if ( (*(short *)(v56 + 12) & 0xF000) == 0x8000 )
          goto LABEL_26;
LABEL_21:
        inode = 2133571416;
LABEL_22:
        while ( *(char *)(v6 + 253) == 1 && !(char)v19 )
        {
LABEL_24:
          *(long long *)(v18 + 12) = 0;
          *(long long *)(v18 + 132) = 0;
          memset(
            (void *)((v18 + 20) & 0xFFFFFFFFFFFFFFF8LL),
            0,
            8LL * (((unsigned int)v18 - (((int)v18 + 20) & 0xFFFFFFF8) + 140) >> 3));
          *(__m128i *)(v18 + 52) = _mm_loadu_si128((const __m128i *)(v6 + 268));
          *(__m128i *)(v18 + 68) = _mm_loadu_si128((const __m128i *)(v6 + 284));
          *(__m128i *)(v18 + 84) = _mm_loadu_si128((const __m128i *)(v6 + 300));
          *(long long *)(v18 + 100) = *(long long *)(v6 + 316);
          *(int *)(v18 + 108) = *(int *)(v6 + 324);
          *(int *)(v18 + 120) = *(int *)(v6 + 328);
          v20 = *(int *)(v6 + 332);
          *(short *)(v18 + 12) = -32384;
          *(int *)(v18 + 16) = v20;
          *(short *)(v18 + 38) = 1;
          e2fsck_use_inode_shortcuts(a1, 1);
          v18 = v56;
          v21 = *(short *)(v56 + 38) == 0;
          *(int *)(a1 + 536) = *(int *)(v56 + 8);
          *(long long *)(a1 + 544) = v18 + 12;
          if ( v21 )
          {
            inode = 2133571416;
            goto LABEL_9;
          }
          v19 = 1;
          if ( (*(short *)(v18 + 12) & 0xF000) != 0x8000 )
            goto LABEL_21;
LABEL_26:
          if ( (*(unsigned int *)(v18 + 16) | ((unsigned long long)*(unsigned int *)(v18 + 120) << 32))
             / *(int *)(memory + 120) > 0x3FF )
          {
            v22 = *(unsigned int *)(v18 + 8);
            v23 = *(long long *)a1;
            v54 = -1;
            v24 = ext2fs_block_iterate3(v23, v22, 1, 0, sub_30280, &v54);
            v25 = *(long long *)a1;
            v18 = v56;
            inode = v24;
            v26 = *(int *)(v56 + 16);
            v27 = v56;
            if ( *(unsigned int *)(*(long long *)a1 + 40LL) * (v54 + 1) >= (int)v26 )
            {
              if ( v19 && (*(char *)(a1 + 76) & 1) == 0 )
              {
                inode = ext2fs_write_inode(v25, *(unsigned int *)(v6 + 224), v56 + 12);
                if ( inode )
                  goto LABEL_9;
                v27 = v56;
                v25 = *(long long *)a1;
                v26 = *(int *)(v56 + 16);
              }
              v28 = memory;
              v29 = *(int *)(memory + 120);
              v30 = (unsigned long long)*(unsigned int *)(v27 + 120) << 32;
              *(long long *)(memory + 136) = v27;
              *(int *)(v28 + 128) = (v26 | v30) / v29;
              *(long long *)(a1 + 616) = *(long long *)(v25 + 8);
              v31 = jbd2_journal_bmap(v28, 0, &v59);
              if ( v31 )
              {
                inode = -v31;
                goto LABEL_9;
              }
              if ( inode )
                goto LABEL_9;
              (*(void (**)(long long, long long))(*(long long *)(*(long long *)(a1 + 616) + 8LL) + 32LL))(
                *(long long *)(a1 + 616),
                *(unsigned int *)(*(long long *)a1 + 40LL));
              v32 = memory;
              v33 = v59;
              goto LABEL_45;
            }
          }
          inode = 2133571413;
        }
      }
      goto LABEL_9;
    }
LABEL_33:
    inode = 2133571398;
    goto LABEL_9;
  }
  v11 = *(long long *)(a1 + 624);
  if ( !v11 )
  {
    uuid_unparse(v6 + 208, v64);
    devname = blkid_get_devname(*(long long *)(a1 + 136), "UUID", v64);
    *(long long *)(a1 + 624) = devname;
    v11 = devname;
    if ( !devname )
    {
      v48 = blkid_devno_to_devname(*(unsigned int *)(v6 + 228));
      *(long long *)(a1 + 624) = v48;
      v11 = v48;
      if ( !v48 )
      {
        inode = 2133571415;
        fix_problem(a1, 17, v60);
        goto LABEL_9;
      }
    }
  }
  v12 = 2 * (unsigned int)((*(int *)(a1 + 124) & 6) != 6) + 1;
  if ( (*(int *)(a1 + 124) & 4) != 0 && (*(char *)(a1 + 77) & 1) != 0 )
    v12 = 1;
  inode = (*((long long (**)(long long, long long, long long))unix_io_manager + 2))(v11, v12, a1 + 616);
  if ( inode )
    goto LABEL_9;
  (*(void (**)(long long, long long))(*(long long *)(*(long long *)(a1 + 616) + 8LL) + 32LL))(
    *(long long *)(a1 + 616),
    *(unsigned int *)(*(long long *)a1 + 40LL));
  v51 = ext2fs_journal_sb_start(*(unsigned int *)(*(long long *)a1 + 40LL));
  v34 = *(long long *)a1;
  v59 = v51 - 1;
  v55 = (int *)getblk(v9, v59, *(int *)(v34 + 40));
  if ( !v55 )
    goto LABEL_33;
  ll_rw_block(0, 0, 1, (long long)&v55);
  inode = v55[5];
  if ( v55[5] )
  {
    brelse((long long)v55);
    goto LABEL_9;
  }
  v35 = v55 + 266;
  if ( v51 != 1 )
    v35 = v55 + 10;
  qmemcpy(v62, v35, sizeof(v62));
  if ( LOWORD(v62[14]) != 0xEF53 || !(unsigned int)sub_30F50(v62[24]) )
  {
    v49 = 18;
LABEL_57:
    inode = 2133571415;
    fix_problem(a1, v49, v60);
    brelse((long long)v55);
    goto LABEL_9;
  }
  v52 = v36;
  v53 = *(const void ***)a1;
  v37 = (const void *)(*(long long *)(*(long long *)a1 + 32LL) + 208LL);
  if ( memcmp(&v62[26], v37, 0x10u) )
  {
    v49 = 19;
    goto LABEL_57;
  }
  if ( (unsigned int)sub_30F70(v62[25], v37, v38, v39, v52) )
  {
    qmemcpy(v61, v53, sizeof(v61));
    qmemcpy(v63, v53[4], sizeof(v63));
    v61[4] = v63;
    v50 = sub_301A0(v63, v35);
    if ( !(unsigned int)ext2fs_superblock_csum_verify(v50) && (unsigned int)fix_problem(a1, 74, v60) )
    {
      ext2fs_superblock_csum_set(v61, v35);
      mark_buffer_dirty((long long)v55);
    }
    v40 = (long long)v55;
  }
  brelse(v40);
  v41 = ext2fs_blocks_count(v62);
  v32 = memory;
  v33 = v51;
  if ( v41 > 0xFFFFFFFF )
    LODWORD(v41) = -1;
  v59 = v51;
  *(int *)(memory + 128) = v41;
LABEL_45:
  v42 = getblk(v9, v33, *(int *)(v32 + 120));
  v55 = (int *)v42;
  if ( !v42 )
    goto LABEL_33;
  v43 = memory;
  *(long long *)(memory + 16) = v42;
  *(long long *)(v43 + 24) = v42 + 40;
  v21 = (unsigned int)sub_30F80(*(unsigned int *)(*(long long *)(*(long long *)a1 + 32LL) + 92LL), v33, v43, 0) == 0;
  v46 = sub_31940;
  if ( v21 )
    v46 = v45;
  inode = 0;
  *(long long *)(v44 + 200) = v46;
  *a2 = v44;
  e2fsck_use_inode_shortcuts(a1, 0);
  return inode;
}


// Function: e2fsck_journal_release @ 0x32d40
long long e2fsck_journal_release(long long a1, long long a2, long long a3, int a4)
{
  long long v5; // rdi
  long long v6; // rdi
  long long v7; // rdi
  long long v9; // rdi
  long long v10; // rsi
  long long v11; // r8
  int v12; // edx
  long long v13; // [rsp+8h] [rbp-10h] BYREF

  v13 = a2;
  if ( a4 )
  {
    v5 = *(long long *)(a2 + 16);
    sub_301D0(v5);
  }
  else if ( (*(char *)(a1 + 76) & 1) != 0 )
  {
    v5 = *(long long *)(a2 + 16);
  }
  else
  {
    v9 = *(unsigned int *)(a2 + 144);
    v10 = *(long long *)(a2 + 24);
    *(int *)(v10 + 24) = sub_307B0(v9);
    if ( v12 )
      *(int *)(v10 + 28) = 0;
    sub_31570(v11, v10);
    v5 = *(long long *)(v13 + 16);
    mark_buffer_dirty(v5);
  }
  brelse(v5);
  v6 = *(long long *)(a1 + 616);
  if ( v6 )
  {
    if ( *(long long *)a1 && v6 != *(long long *)(*(long long *)a1 + 8LL) )
      (*(void (**)(void))(*(long long *)(v6 + 8) + 24LL))();
    *(long long *)(a1 + 616) = 0;
  }
  v7 = v13;
  if ( *(long long *)(v13 + 136) )
  {
    ext2fs_free_mem(v13 + 136);
    v7 = v13;
  }
  if ( *(long long *)(v7 + 112) )
    ext2fs_free_mem(v7 + 112);
  return ext2fs_free_mem(&v13);
}


// Function: recover_ext3_journal @ 0x32e30
long long recover_ext3_journal(long long a1, long long a2, long long a3)
{
  int inited; // eax
  long long v5; // r12
  int v7; // eax
  long long v8; // rdx
  long long v9; // rdx
  long long v10; // r14
  int v11; // eax
  int v12; // eax
  long long v13; // rdi
  long long v14; // [rsp+8h] [rbp-A0h] BYREF
  char v15[8]; // [rsp+10h] [rbp-98h] BYREF
  int v16; // [rsp+18h] [rbp-90h]
  unsigned long long v17; // [rsp+78h] [rbp-30h]

  v17 = __readfsqword(0x28u);
  clear_problem_context(v15, a2, a3);
  inited = jbd2_journal_init_revoke_record_cache();
  v5 = inited;
  if ( !inited )
  {
    v7 = jbd2_journal_init_revoke_table_cache();
    v5 = v7;
    if ( !v7 )
    {
      v5 = sub_32540(a1, &v14, v8);
      if ( !v5 )
      {
        v10 = v14;
        v5 = sub_31F20(v14, (long long)&v14, v9);
        if ( !v5 )
        {
          v11 = jbd2_journal_init_revoke(v10, 1024);
          v5 = v11;
          if ( !v11 )
          {
            v12 = jbd2_journal_recover(v10);
            if ( v12 )
            {
              v5 = -v12;
            }
            else
            {
              if ( *(int *)(v10 + 192) )
              {
                v16 = *(int *)(v10 + 192);
                fix_problem(a1, 58, v15);
                v13 = *(long long *)(v10 + 16);
                *(int *)(*(long long *)(v10 + 24) + 32LL) = -22;
                mark_buffer_dirty(v13);
              }
              *(int *)(v10 + 144) = *(int *)(v10 + 148);
            }
          }
        }
        jbd2_journal_destroy_revoke(v10);
        jbd2_journal_destroy_revoke_record_cache();
        jbd2_journal_destroy_revoke_table_cache();
        sub_32D40(a1, v10, 1, 0);
      }
    }
  }
  return v5;
}


// Function: buffer_uptodate @ 0x32f70
long long buffer_uptodate(long long a1)
{
  return (*(char *)(a1 + 24) & 2) != 0;
}


// Function: mark_buffer_uptodate @ 0x32f80
long long mark_buffer_uptodate(long long a1, char a2)
{
  *(char *)(a1 + 24) = (2 * (a2 & 1)) | *(char *)(a1 + 24) & 0xFD;
  return 2 * (a2 & 1u);
}


// Function: wait_on_buffer @ 0x32fa0
void wait_on_buffer(long long a1)
{
  long long v1; // [rsp+8h] [rbp-10h] BYREF

  v1 = a1;
  if ( (*(char *)(a1 + 24) & 2) == 0 )
    ll_rw_block(0, 0, 1, (long long)&v1);
}


// Function: e2fsck_check_ext3_journal @ 0x32fe0
long long e2fsck_check_ext3_journal(long long *a1, long long a2)
{
  long long v3; // rbx
  unsigned int v4; // eax
  long long v5; // rcx
  long long v6; // r8
  long long v7; // r9
  int v8; // eax
  long long v9; // rdx
  long long *v10; // rsi
  long long v11; // rdx
  long long v12; // rax
  long long v13; // rdx
  long long v14; // rcx
  long long v15; // r8
  long long v16; // r12
  unsigned long long v17; // rax
  long long v18; // rdx
  long long v20; // r14
  long long v21; // rax
  long long v22; // rdx
  long long v23; // rcx
  long long v24; // r8
  long long v25; // r9
  long long v26; // rsi
  long long v27; // rdx
  long long v28; // rcx
  long long v29; // r8
  long long v30; // r9
  long long v31; // rdi
  int v32; // r15d
  int v33; // edx
  unsigned int v34; // r15d
  long long v35; // rsi
  long long v36; // rdi
  unsigned int v37; // edx
  long long v38; // rdi
  long long v39; // [rsp+18h] [rbp-B0h] BYREF
  char v40[80]; // [rsp+20h] [rbp-A8h] BYREF
  long long v41; // [rsp+70h] [rbp-58h]
  unsigned long long v42; // [rsp+88h] [rbp-40h]

  v42 = __readfsqword(0x28u);
  v3 = *(long long *)(*a1 + 32LL);
  v4 = sub_30F60(*(unsigned int *)(v3 + 96));
  v8 = sub_30F90(*(unsigned int *)(v3 + 92), a2, v4, v5, v6, v7);
  if ( !((unsigned int)v9 | v8) && !*(long long *)(v3 + 224) )
  {
    v16 = 0;
    if ( (unsigned int)uuid_is_null(v3 + 208) )
      return v16;
  }
  clear_problem_context(v40, a2, v9);
  v10 = &v39;
  v41 = *(unsigned int *)(v3 + 224);
  v12 = sub_32540((long long)a1, &v39, v11);
  v16 = v12;
  if ( v12 )
  {
    v17 = v12 - 2133571369;
    if ( v17 <= 0x2F )
    {
      v18 = 0x900000000003LL;
      if ( _bittest64(&v18, v17) )
        return sub_30FA0(a1, (long long)v40, 0x900000000003LL, v14, v15);
    }
    return v16;
  }
  v20 = v39;
  v21 = sub_31F20(v39, (long long)&v39, v13);
  v16 = v21;
  if ( v21 )
  {
    if ( v21 != 2133571504 )
    {
      if ( v21 == 2133571395 )
      {
        if ( (unsigned int)fix_problem(a1, 38, v40) )
          goto LABEL_23;
      }
      else if ( v21 == 2133571396 )
      {
        if ( (unsigned int)fix_problem(a1, 37, v40) )
          goto LABEL_23;
      }
      else if ( v21 != 2133571414 || (unsigned int)fix_problem(a1, 39, v40) )
      {
        goto LABEL_23;
      }
    }
    v16 = sub_32450(a1, v20, (long long)v40, v23, v24, v25);
LABEL_23:
    sub_32D40((long long)a1, v20, 0, 1);
    return v16;
  }
  while ( 1 )
  {
    sub_30F90(*(unsigned int *)(v3 + 92), v10, v22, v23, v24, v25);
    v31 = *(unsigned int *)(v3 + 96);
    v32 = sub_30F60(v31);
    if ( v33 )
      goto LABEL_16;
    v26 = 22;
    if ( !(unsigned int)fix_problem(a1, 22, v40) )
      break;
    if ( !v32 )
    {
      if ( *(int *)(v3 + 76) )
        v37 = *(int *)(v3 + 84);
      else
        v37 = 11;
      v26 = *(int *)(v3 + 224) < v37;
      goto LABEL_40;
    }
    v10 = (long long *)(&dword_14 + 3);
    if ( (unsigned int)fix_problem(a1, 23, v40) )
    {
      v26 = 1;
LABEL_40:
      *(long long *)(v3 + 224) = 0;
      *(_OWORD *)(v3 + 208) = 0;
      sub_30C30(*a1, v26);
      goto LABEL_26;
    }
  }
  if ( (*((char *)a1 + 76) & 1) == 0 )
  {
    sub_30180(v3);
    v38 = *a1;
    *(int *)(v38 + 16) &= ~0x200u;
    ext2fs_mark_super_dirty(v38);
  }
LABEL_26:
  if ( !(unsigned int)sub_30F90(*(unsigned int *)(v3 + 92), v26, v27, v28, v29, v30) )
  {
LABEL_27:
    v34 = 0;
    goto LABEL_28;
  }
  v31 = *(unsigned int *)(v3 + 96);
LABEL_16:
  v34 = sub_30F60(v31);
  if ( v34 )
  {
    v34 = 0;
    goto LABEL_18;
  }
  v35 = *(long long *)(v20 + 24);
  if ( !*(int *)(v35 + 28) )
    goto LABEL_30;
  fix_problem(a1, 24, v40);
  if ( (unsigned int)fix_problem(a1, 43 - ((unsigned int)(a1[12] == 0) - 1), v40) )
  {
    *((int *)a1 + 19) |= 0x100u;
    sub_301B0(v3);
    ext2fs_mark_super_dirty(*a1);
  }
  else
  {
    if ( !(unsigned int)fix_problem(a1, 25, v40) )
      goto LABEL_27;
    *(short *)(v3 + 58) &= ~1u;
    v34 = 1;
    ext2fs_mark_super_dirty(*a1);
  }
LABEL_28:
  if ( (unsigned int)sub_30F60(*(unsigned int *)(v3 + 96)) )
    goto LABEL_18;
  v35 = *(long long *)(v20 + 24);
LABEL_30:
  if ( *(int *)(v35 + 32) )
  {
    v36 = *a1;
    *(short *)(*(long long *)(*a1 + 32LL) + 58LL) |= 2u;
    ext2fs_mark_super_dirty(v36);
    *(int *)(v35 + 32) = 0;
    sub_31570(v20, v35);
    mark_buffer_dirty(*(long long *)(v20 + 16));
  }
LABEL_18:
  sub_32D40((long long)a1, v20, v34, 0);
  return v16;
}


// Function: e2fsck_run_ext3_journal @ 0x333d0
long long e2fsck_run_ext3_journal(long long *a1)
{
  long long v2; // r14
  long long v3; // rax
  unsigned int v4; // r12d
  long long v5; // r13
  char *v6; // rsi
  long long v7; // rdx
  long long v8; // rdi
  long long v9; // rax
  long long v10; // rdi
  long long v11; // rbx
  long long v12; // r14
  long long v13; // rax
  int v14; // r12d
  long long v15; // rax
  long long v16; // rdx
  long long v17; // rdi
  long long v18; // rsi
  long long result; // rax
  void (*v20)(long long, long long *); // rax
  long long v21; // r13
  unsigned int v22; // eax
  int v23; // r8d
  int v24; // r9d
  long long v25; // r12
  char *v26; // rax
  long long v27[7]; // [rsp+0h] [rbp-38h] BYREF

  v2 = a1[3];
  v27[1] = __readfsqword(0x28u);
  v3 = *a1;
  v27[0] = 0;
  v4 = *(int *)(v3 + 40);
  v5 = *(long long *)(*(long long *)(v3 + 8) + 8LL);
  v6 = dcgettext(0, "%s: recovering journal\n", 5);
  __printf_chk(1, v6, v2);
  if ( (*((char *)a1 + 76) & 1) != 0 )
  {
    v25 = a1[3];
    v26 = dcgettext(0, "%s: won't do journal recovery while read-only\n", 5);
    __printf_chk(1, v26, v25);
    return 2133571405;
  }
  else
  {
    v8 = *a1;
    if ( (*(char *)(*a1 + 16LL) & 4) != 0 )
      ext2fs_flush(v8);
    v9 = sub_32E30((long long)a1, (long long)v6, v7);
    v10 = *a1;
    v11 = v9;
    if ( *(long long *)(*(long long *)(*a1 + 32LL) + 376LL) )
    {
      v20 = *(void (**)(long long, long long *))(*(long long *)(*(long long *)(v10 + 8) + 8LL) + 80LL);
      if ( v20 )
        v20(*(long long *)(v10 + 8), v27);
    }
    v12 = 0;
    if ( v27[0] )
      v12 = *(long long *)(v27[0] + 16LL) >> 10;
    ext2fs_mmp_stop();
    ext2fs_free(*a1);
    v13 = ext2fs_open(a1[2], *((unsigned int *)a1 + 32), *((unsigned int *)a1 + 24), v4, v5, a1);
    v14 = v13;
    if ( v13 )
    {
      v21 = a1[3];
      v22 = (unsigned int)dcgettext(0, "while trying to re-open %s", 5);
      com_err(a1[1], v14, v22, v21, v23, v24);
      fatal_error(a1, 0);
    }
    v15 = *a1;
    v16 = a1[105];
    *(int *)(v15 + 16) |= 0x200u;
    *(long long *)(v15 + 224) = a1;
    v17 = *a1;
    *(long long *)(v15 + 184) = v16;
    *(long long *)(*(long long *)(v15 + 32) + 376LL) += v12;
    v18 = v11 != 0;
    sub_30C30(v17, v18);
    result = e2fsck_check_ext3_journal(a1, v18);
    if ( !result )
      return v11;
  }
  return result;
}


// Function: e2fsck_move_ext3_journal @ 0x335e0
unsigned long long e2fsck_move_ext3_journal(long long *a1, long long a2, long long a3)
{
  long long v3; // r12
  long long v4; // rbx
  long long v5; // rdx
  long long v6; // rcx
  long long v7; // r8
  long long v8; // r9
  long long v9; // rsi
  char v10; // al
  long long v12; // rdx
  int v13; // eax
  __m128i v14; // xmm0
  __m128i v15; // xmm1
  __m128i v16; // xmm2
  int v17; // eax
  _UNKNOWN **v18; // r15
  const char *v19; // rdx
  unsigned int v20; // eax
  long long v21; // rax
  long long v22; // rsi
  long long v23; // rax
  unsigned int v24; // r13d
  unsigned int v25; // ebp
  int v26; // eax
  const char *v27; // [rsp+0h] [rbp-158h]
  unsigned int v28; // [rsp+18h] [rbp-140h] BYREF
  char v29[4]; // [rsp+1Ch] [rbp-13Ch] BYREF
  long long v30[14]; // [rsp+20h] [rbp-138h] BYREF
  char v31[4]; // [rsp+90h] [rbp-C8h] BYREF
  int v32; // [rsp+94h] [rbp-C4h]
  int v33; // [rsp+A4h] [rbp-B4h]
  short v34; // [rsp+AAh] [rbp-AEh]
  __m128i s1; // [rsp+B8h] [rbp-A0h] BYREF
  __m128i v36; // [rsp+C8h] [rbp-90h] BYREF
  __m128i v37; // [rsp+D8h] [rbp-80h] BYREF
  long long v38; // [rsp+E8h] [rbp-70h]
  int v39; // [rsp+F0h] [rbp-68h]
  int v40; // [rsp+FCh] [rbp-5Ch]
  unsigned long long v41; // [rsp+118h] [rbp-40h]

  v3 = *a1;
  v41 = __readfsqword(0x28u);
  v4 = *(long long *)(v3 + 32);
  clear_problem_context(v30, a2, a3);
  if ( (*((char *)a1 + 76) & 1) == 0 )
  {
    v9 = *(unsigned int *)(v4 + 224);
    if ( (int)v9 )
    {
      if ( (unsigned int)sub_30F90(*(unsigned int *)(v4 + 92), v9, v5, v6, v7, v8) && !ext2fs_read_inode(v3, v9, v31) )
      {
        v10 = *(char *)(v4 + 253);
        if ( (!v10 || v10 == 1 && memcmp(&s1, (const void *)(v4 + 268), 0x3Cu))
          && (unsigned int)fix_problem(a1, 45, v30) )
        {
          v12 = v38;
          v13 = v40;
          *(char *)(v4 + 253) = 1;
          v14 = _mm_loadu_si128(&s1);
          v15 = _mm_loadu_si128(&v36);
          v16 = _mm_loadu_si128(&v37);
          *(long long *)(v4 + 316) = v12;
          *(int *)(v4 + 328) = v13;
          LODWORD(v12) = v39;
          v17 = v32;
          *(__m128i *)(v4 + 268) = v14;
          *(int *)(v4 + 324) = v12;
          *(int *)(v4 + 332) = v17;
          *(__m128i *)(v4 + 284) = v15;
          *(__m128i *)(v4 + 300) = v16;
          ext2fs_mark_super_dirty(v3);
          *(int *)(v3 + 16) &= ~0x200u;
        }
        if ( *(int *)(v4 + 224) != 8 && v34 == 1 && !ext2fs_check_if_mounted(a1[2], v29) && (v29[0] & 1) == 0 )
        {
          v18 = &off_B0CC0;
          v19 = ".journal";
          while ( 1 )
          {
            v27 = v19;
            v20 = strlen(v19);
            if ( !ext2fs_lookup(v3, 2, v27, v20, 0, &v28) && *(int *)(v4 + 224) == v28 )
              break;
            v19 = (const char *)v18[1];
            ++v18;
            if ( !v19 )
              return v41 - __readfsqword(0x28u);
          }
          if ( *v18 )
          {
            if ( !ext2fs_read_bitmaps(v3) )
            {
              v30[12] = *v18;
              if ( (unsigned int)fix_problem(a1, 40, v30) )
              {
                v21 = ext2fs_unlink(v3, 2, *v18, v28, 0);
                if ( v21 )
                  goto LABEL_27;
                v21 = ext2fs_write_inode(v3, 8, v31);
                if ( v21 )
                  goto LABEL_27;
                *(int *)(v4 + 224) = 8;
                ext2fs_mark_super_dirty(v3);
                v22 = v28;
                *(int *)(v3 + 16) &= ~0x200u;
                v23 = a1[105];
                v34 = 0;
                v33 = v23;
                v21 = ext2fs_write_inode(v3, v22, v31);
                if ( v21 )
                {
LABEL_27:
                  v30[0] = v21;
                  fix_problem(a1, 41, v30);
                  *(short *)(*(long long *)(v3 + 32) + 58LL) &= ~1u;
                  ext2fs_mark_super_dirty(v3);
                }
                else
                {
                  v24 = v28;
                  v25 = ext2fs_group_of_ino(v3, v28);
                  ext2fs_unmark_inode_bitmap2(*(long long *)(v3 + 80), v24);
                  ext2fs_mark_ib_dirty(v3);
                  v26 = ext2fs_bg_free_inodes_count(v3, v25);
                  ext2fs_bg_free_inodes_count_set(v3, v25, (unsigned int)(v26 + 1));
                  ext2fs_group_desc_csum_set(v3, v25);
                  ++*(int *)(*(long long *)(v3 + 32) + 16LL);
                }
              }
            }
          }
        }
      }
    }
  }
  return v41 - __readfsqword(0x28u);
}


// Function: e2fsck_fix_ext3_journal_hint @ 0x33940
long long e2fsck_fix_ext3_journal_hint(long long *a1, long long a2, long long a3, long long a4, long long a5, long long a6)
{
  long long v6; // rbp
  const char *devname; // rax
  char *v9; // r12
  long long v10; // rdx
  long long v11; // rdi
  long long v12[14]; // [rsp+0h] [rbp-158h] BYREF
  struct stat buf; // [rsp+70h] [rbp-E8h] BYREF
  char v14[40]; // [rsp+100h] [rbp-58h] BYREF
  unsigned long long v15; // [rsp+128h] [rbp-30h]

  v15 = __readfsqword(0x28u);
  v6 = *(long long *)(*a1 + 32LL);
  if ( (unsigned int)sub_30F90(*(unsigned int *)(v6 + 92), a2, a3, a4, a5, a6) )
  {
    if ( !(unsigned int)uuid_is_null(v6 + 208) )
    {
      uuid_unparse(v6 + 208, v14);
      devname = (const char *)blkid_get_devname(a1[17], "UUID", v14);
      v9 = (char *)devname;
      if ( devname )
      {
        if ( stat(devname, &buf) >= 0 && buf.st_rdev != *(int *)(v6 + 228) )
        {
          clear_problem_context(v12, &buf, v10);
          v12[10] = buf.st_rdev;
          if ( (unsigned int)fix_problem(a1, 51, v12) )
          {
            v11 = *a1;
            *(int *)(v6 + 228) = buf.st_rdev;
            ext2fs_mark_super_dirty(v11);
          }
        }
        free(v9);
      }
    }
  }
  return 0;
}


// Function: invalid_block @ 0x33a60
long long invalid_block(long long a1, unsigned int a2)
{
  char *v2; // rax

  v2 = dcgettext(0, "Bad block %u out of range; ignored.\n", 5);
  return __printf_chk(1, v2, a2);
}


// Function: check_bb_inode_blocks @ 0x33a90
long long check_bb_inode_blocks(long long a1, unsigned int *a2)
{
  unsigned long long v2; // r12
  bool v4; // cf
  unsigned int v5; // r12d
  char *v6; // rax

  v2 = *a2;
  if ( !(int)v2 )
    return 0;
  v4 = v2 < ext2fs_blocks_count(*(long long *)(a1 + 32));
  v5 = *a2;
  if ( v4 && v5 >= *(int *)(*(long long *)(a1 + 32) + 20LL) )
    return 0;
  v6 = dcgettext(0, "Warning: illegal block %u found in bad block inode.  Cleared.\n", 5);
  __printf_chk(1, v6, v5);
  *a2 = 0;
  return 1;
}


// Function: read_bad_blocks_file @ 0x33b10
unsigned long long read_bad_blocks_file(long long *a1, const char *a2, int a3)
{
  char *v4; // r12
  long long v6; // r13
  long long v7; // rax
  FILE *v8; // rax
  FILE *v9; // rbp
  long long v10; // r12
  long long updated; // rax
  int v12; // ebp
  unsigned int v14; // eax
  int v15; // r8d
  int v16; // r9d
  long long v17; // rdi
  long long v18; // rbp
  unsigned int v19; // eax
  int v20; // r8d
  int v21; // r9d
  long long v22; // rax
  int v23; // ecx
  long long v24; // rax
  const char *v25; // r9
  const char *v26; // rdx
  FILE *v27; // rax
  FILE *v28; // rbp
  int v29; // ebp
  unsigned int v30; // eax
  int v31; // r8d
  int v32; // r9d
  unsigned int v33; // eax
  int v34; // r8d
  int v35; // r9d
  const char *v36; // rsi
  unsigned int v37; // r13d
  int *v38; // rax
  int v39; // r8d
  int v40; // r9d
  long long v41; // [rsp+8h] [rbp-440h] BYREF
  char command[1032]; // [rsp+10h] [rbp-438h] BYREF
  unsigned long long v43; // [rsp+418h] [rbp-30h]

  LODWORD(v4) = (int)a2;
  v6 = *a1;
  v43 = __readfsqword(0x28u);
  v41 = 0;
  e2fsck_read_bitmaps(a1);
  v7 = ext2fs_block_iterate(v6, 1, 0, 0, sub_33A90, 0);
  if ( v7 )
  {
    v29 = v7;
    v30 = (unsigned int)dcgettext(0, "while sanity checking the bad blocks inode", 5);
    com_err((unsigned int)"ext2fs_block_iterate", v29, (unsigned int)"%s", v30, v31, v32);
    goto LABEL_11;
  }
  if ( !a3 )
  {
    v18 = ext2fs_read_bb_inode(v6, &v41);
    if ( v18 )
    {
      v19 = (unsigned int)dcgettext(0, "while reading the bad blocks inode", 5);
      com_err((unsigned int)"ext2fs_read_bb_inode", v18, (unsigned int)"%s", v19, v20, v21);
      goto LABEL_11;
    }
  }
  if ( a2 )
  {
    v8 = fopen(a2, "r");
    v9 = v8;
    if ( v8 )
    {
      v10 = ext2fs_read_bb_FILE(v6, v8, &v41, sub_33A60);
      fclose(v9);
      goto LABEL_6;
    }
    v36 = "while trying to open %s";
LABEL_24:
    v37 = (unsigned int)dcgettext(0, v36, 5);
    v38 = __errno_location();
    com_err((unsigned int)"read_bad_blocks_file", *v38, v37, (int)v4, v39, v40);
    goto LABEL_11;
  }
  v4 = command;
  v22 = ext2fs_blocks_count(*(long long *)(v6 + 32));
  v23 = *((int *)a1 + 19);
  v24 = v22 - 1;
  v25 = "";
  v26 = "-n ";
  if ( (v23 & 0x200) == 0 )
    v26 = "";
  if ( (v23 & 2) == 0 )
    v25 = "-s ";
  __sprintf_chk(
    command,
    1,
    1024,
    "badblocks -b %d -X %s%s%s %llu",
    *(int *)(v6 + 40),
    v25,
    v26,
    *(const char **)(v6 + 24),
    v24);
  v27 = popen(command, "r");
  v28 = v27;
  if ( !v27 )
  {
    v36 = "while trying popen '%s'";
    goto LABEL_24;
  }
  v10 = ext2fs_read_bb_FILE(v6, v27, &v41, sub_33A60);
  pclose(v28);
LABEL_6:
  if ( v10 )
  {
    v14 = (unsigned int)dcgettext(0, "while reading in list of bad blocks from file", 5);
    com_err((unsigned int)"ext2fs_read_bb_FILE", v10, (unsigned int)"%s", v14, v15, v16);
  }
  else
  {
    __printf_chk(1, "%s: Updating bad block inode.\n", (const char *)a1[3]);
    updated = ext2fs_update_bb_inode(v6, v41);
    v12 = updated;
    if ( !updated )
    {
      ext2fs_badblocks_list_free(v41);
      return v43 - __readfsqword(0x28u);
    }
    v33 = (unsigned int)dcgettext(0, "while updating bad block inode", 5);
    com_err((unsigned int)"ext2fs_update_bb_inode", v12, (unsigned int)"%s", v33, v34, v35);
  }
LABEL_11:
  v17 = v41;
  *((int *)a1 + 18) |= 1u;
  if ( v17 )
    ext2fs_badblocks_list_free(v17);
  return v43 - __readfsqword(0x28u);
}


// Function: read_a_char @ 0x33e30
long long read_a_char()
{
  int v0; // ebx
  char buf; // [rsp+7h] [rbp-21h] BYREF
  unsigned long long v3; // [rsp+8h] [rbp-20h]

  v0 = 102;
  v3 = __readfsqword(0x28u);
  do
  {
    if ( e2fsck_global_ctx && (*(char *)(e2fsck_global_ctx + 72) & 2) != 0 )
      return 3;
    if ( (unsigned int)read(0, &buf, 1u) == 1 )
      return (unsigned int)buf;
    --v0;
  }
  while ( v0 );
  return 0xFFFFFFFFLL;
}


// Function: log_out @ 0x33ef0
unsigned long long log_out(long long a1, long long a2, ...)
{
  long long v2; // rdi
  gcc_va_list va; // [rsp+0h] [rbp-E8h] BYREF
  unsigned long long v5; // [rsp+18h] [rbp-D0h]

  va_start(va, a2);
  v5 = __readfsqword(0x28u);
  ((void (*)(long long, long long, __va_list_tag *))__vprintf_chk)(1, a2, va);
  if ( *(long long *)(a1 + 40) )
  {
    v2 = *(long long *)(a1 + 40);
    va_end(va);
    va_start(va, a2);
    ((void (*)(long long, long long, long long, __va_list_tag *))__vfprintf_chk)(v2, 1, a2, va);
  }
  return v5 - __readfsqword(0x28u);
}


// Function: log_err @ 0x34010
unsigned long long log_err(long long a1, long long a2, ...)
{
  long long v2; // r8
  long long v3; // r9
  long long v4; // rdi
  gcc_va_list va; // [rsp+0h] [rbp-E8h] BYREF
  unsigned long long v7; // [rsp+18h] [rbp-D0h]
  long long v8; // [rsp+30h] [rbp-B8h]
  long long v9; // [rsp+38h] [rbp-B0h]
  long long v10; // [rsp+40h] [rbp-A8h]
  long long v11; // [rsp+48h] [rbp-A0h]

  va_start(va, a2);
  v8 = va_arg(va, long long);
  v9 = va_arg(va, long long);
  v10 = va_arg(va, long long);
  v11 = va_arg(va, long long);
  va_end(va);
  va_start(va, a2);
  v7 = __readfsqword(0x28u);
  ((void (*)(FILE *, long long, long long, __va_list_tag *, long long, long long))__vfprintf_chk)(
    stderr,
    1,
    a2,
    va,
    v10,
    v11);
  if ( *(long long *)(a1 + 40) )
  {
    v4 = *(long long *)(a1 + 40);
    va_end(va);
    va_start(va, a2);
    ((void (*)(long long, long long, long long, __va_list_tag *, long long, long long))__vfprintf_chk)(
      v4,
      1,
      a2,
      va,
      v2,
      v3);
  }
  return v7 - __readfsqword(0x28u);
}


// Function: fatal_error @ 0x34130
void fatal_error(long long *a1, const char *a2)
{
  long long v3; // rbp
  long long *v4; // rdi
  unsigned int v5; // r12d
  int v6; // eax
  long long v7; // rdi
  long long v8; // r13
  char *v9; // rax
  long long v10; // r12
  char *v11; // rax

  v3 = *a1;
  if ( a2 )
    __fprintf_chk(stderr, 1, "e2fsck: %s\n", a2);
  if ( v3 )
  {
    if ( *(long long *)(v3 + 8) && *(long long *)(v3 + 32) )
    {
      ext2fs_mmp_stop(*a1);
      v4 = *(long long **)(*a1 + 8LL);
      if ( *v4 == 2133571333 )
        (*(void (**)(void))(v4[1] + 56LL))();
      else
        log_err((long long)a1, (long long)"e2fsck: io manager magic bad!\n");
    }
    v5 = 8;
    if ( (unsigned int)ext2fs_test_changed(v3) )
    {
      v10 = a1[3];
      v11 = dcgettext(0, "\n%s: ***** FILE SYSTEM WAS MODIFIED *****\n", 5);
      log_out((long long)a1, (long long)v11, v10);
      v5 = (*((int *)a1 + 31) & 2) == 0 ? 9 : 11;
    }
    if ( !(unsigned int)ext2fs_test_valid(v3) )
    {
      v8 = a1[3];
      v5 = v5 & 0xFFFFFFFA | 4;
      v9 = dcgettext(0, "\n%s: ********** WARNING: Filesystem still has errors **********\n\n", 5);
      log_out((long long)a1, (long long)v9, v8);
    }
  }
  else
  {
    v5 = 8;
  }
  v6 = *((int *)a1 + 18);
  *((int *)a1 + 18) = v6 | 1;
  if ( (v6 & 0x10) == 0 )
  {
    v7 = a1[5];
    if ( v7 )
      __fprintf_chk(v7, 1, "Exit status: %d\n", v5);
    exit(v5);
  }
  __longjmp_chk(a1 + 18, 1);
}


// Function: e2fsck_allocate_memory @ 0x342a0
long long e2fsck_allocate_memory(long long *a1, size_t a2, const char *a3)
{
  long long v5; // [rsp+8h] [rbp-140h]
  char v6[264]; // [rsp+10h] [rbp-138h] BYREF
  unsigned long long v7; // [rsp+118h] [rbp-30h]

  v7 = __readfsqword(0x28u);
  if ( ext2fs_get_memzero(a2) )
  {
    __sprintf_chk(v6, 1, 256, "Can't allocate %lu bytes for %s\n", a2, a3);
    fatal_error(a1, v6);
  }
  return v5;
}


// Function: string_copy @ 0x34340
char *string_copy(long long a1, const char *a2, size_t a3)
{
  size_t v3; // rbx
  char *v4; // rax
  char *v5; // r8
  char *v6; // rax

  if ( !a2 )
    return 0;
  v3 = a3;
  if ( !a3 )
    v3 = strlen(a2);
  v4 = (char *)malloc(v3 + 1);
  v5 = v4;
  if ( v4 )
  {
    v6 = strncpy(v4, a2, v3);
    v6[v3] = 0;
    return v6;
  }
  return v5;
}


// Function: ask_yn @ 0x343b0
long long ask_yn(long long a1, const char *a2, unsigned int a3)
{
  char *v3; // rbp
  char *v4; // rbx
  __m128i si128; // xmm1
  __m128i v6; // xmm2
  __m128i v7; // xmm3
  const char *v8; // rsi
  char *v9; // rax
  char *v10; // rax
  const char *v11; // r9
  const char *v12; // r8
  unsigned int v13; // eax
  unsigned long long v14; // rbx
  int v15; // r12d
  long long v16; // rax
  unsigned int v17; // r12d
  char *v18; // rax
  char *v20; // rax
  char *v21; // rax
  char *v22; // rax
  char *v23; // rax
  const char *s; // [rsp+0h] [rbp-F8h]
  const char *v25; // [rsp+8h] [rbp-F0h]
  struct termios termios_p; // [rsp+30h] [rbp-C8h] BYREF
  struct termios v29; // [rsp+70h] [rbp-88h] BYREF
  unsigned long long v30; // [rsp+B8h] [rbp-40h]

  v30 = __readfsqword(0x28u);
  v3 = dcgettext(0, "yY", 5);
  s = dcgettext(0, "nN", 5);
  v25 = dcgettext(0, "aA", 5);
  v4 = dcgettext(0, " ('a' enables 'yes' to all) ", 5);
  if ( tcgetattr(0, &termios_p) < 0 )
    memset(&termios_p, 0, sizeof(termios_p));
  si128 = _mm_load_si128((const __m128i *)&termios_p);
  v6 = _mm_load_si128((const __m128i *)&termios_p.c_line);
  v7 = _mm_load_si128((const __m128i *)&termios_p.c_cc[15]);
  *(long long *)&v29.c_cc[31] = *(long long *)&termios_p.c_cc[31];
  *(__m128i *)&v29.c_iflag = si128;
  *(__m128i *)&v29.c_line = v6;
  v29.c_lflag = si128.m128i_i32[3] & 0xFFFFFFF5;
  v29.c_ospeed = termios_p.c_ospeed;
  *(short *)&v29.c_cc[5] = 256;
  *(__m128i *)&v29.c_cc[15] = v7;
  tcsetattr(0, 0, &v29);
  v8 = "<y>";
  if ( a3 != 1 )
  {
    if ( a3 )
    {
      v20 = dcgettext(0, " (y/n)", 5);
      v11 = a2;
      v12 = v20;
      goto LABEL_7;
    }
    v8 = "<n>";
  }
  v9 = dcgettext(0, v8, 5);
  v10 = dcgettext(0, v9, 5);
  v11 = a2;
  v12 = v10;
LABEL_7:
  if ( dword_B7350 <= 12 )
  {
    if ( dword_B7350 <= 8 )
      v4 = (char *)"";
  }
  else
  {
    dword_B7350 = -1;
    v4 = (char *)"";
  }
  log_out(a1, (long long)"%s%s%s? ", v11, v4, v12);
  while ( 1 )
  {
    fflush(stdout);
    v13 = sub_33E30();
    v14 = v13;
    if ( v13 == -1 )
      goto LABEL_22;
    if ( v13 == 3 )
      break;
    v15 = (char)v13;
    if ( strchr(v3, (char)v13) )
      goto LABEL_32;
    if ( strchr(s, v15) )
    {
LABEL_34:
      dword_B7350 = -1;
      goto LABEL_35;
    }
    if ( strchr(v25, v15) )
      goto LABEL_36;
    if ( strchr("yY", v15) )
    {
LABEL_32:
      v17 = 1;
      if ( dword_B7350 >= 0 )
        ++dword_B7350;
LABEL_25:
      v18 = dcgettext(0, "yes\n", 5);
      log_out(a1, (long long)"%s", v18);
      goto LABEL_26;
    }
    if ( strchr("nN", v15) )
      goto LABEL_34;
    if ( strchr("aA", v15) )
    {
LABEL_36:
      dword_B7350 = -1;
      *(int *)(a1 + 76) |= 4u;
      goto LABEL_37;
    }
    if ( (unsigned int)v14 <= 0x20 )
    {
      v16 = 0x108000400LL;
      if ( _bittest64(&v16, v14) )
      {
        if ( a3 != -1 )
        {
          dword_B7350 = -1;
LABEL_22:
          if ( a3 == 2 )
          {
LABEL_37:
            v17 = 2;
            v22 = dcgettext(0, "yes to all\n", 5);
            log_out(a1, (long long)"%s", v22);
          }
          else
          {
            if ( a3 )
            {
              v17 = a3;
              goto LABEL_25;
            }
LABEL_35:
            v17 = 0;
            v21 = dcgettext(0, "no\n", 5);
            log_out(a1, (long long)"%s", v21);
          }
LABEL_26:
          tcsetattr(0, 0, &termios_p);
          return v17;
        }
      }
    }
  }
  tcsetattr(0, 0, &termios_p);
  v17 = *(int *)(a1 + 72) & 0x10;
  if ( (*(int *)(a1 + 72) & 0x10) != 0 )
  {
    log_out(a1, (long long)"\n");
    __longjmp_chk(e2fsck_global_ctx + 144, 1);
  }
  v23 = dcgettext(0, "cancelled!\n", 5);
  log_out(a1, (long long)"%s", v23);
  dword_B7350 = 0;
  return v17;
}


// Function: ask @ 0x34860
long long ask(long long a1, const char *a2, unsigned int a3)
{
  int v3; // eax
  char *v5; // rcx
  char *v7; // rax
  char *v8; // rax

  v3 = *(int *)(a1 + 76);
  if ( (v3 & 8) != 0 )
  {
    v7 = dcgettext(0, "%s? no\n\n", 5);
    log_out(a1, (long long)v7, a2);
    return 0;
  }
  else if ( (v3 & 4) != 0 )
  {
    v8 = dcgettext(0, "%s? yes\n\n", 5);
    log_out(a1, (long long)v8, a2);
    return 1;
  }
  else if ( (v3 & 2) != 0 )
  {
    if ( a3 )
      v5 = dcgettext(0, "yes", 5);
    else
      v5 = dcgettext(0, "no", 5);
    log_out(a1, (long long)"%s? %s\n\n", a2, v5);
    return a3;
  }
  else
  {
    return ask_yn(a1, a2, a3);
  }
}


// Function: e2fsck_write_bitmaps @ 0x34950
long long e2fsck_write_bitmaps(long long *a1)
{
  long long v1; // r12
  char *v2; // rax
  long long v3; // r13
  long long v4; // r12
  long long result; // rax
  long long v6; // r13
  unsigned int v7; // eax
  int v8; // r8d
  int v9; // r9d

  v1 = *a1;
  v2 = dcgettext(0, "writing block and inode bitmaps", 5);
  v3 = ehandler_operation(v2);
  v4 = ext2fs_write_bitmaps(v1);
  result = ehandler_operation(v3);
  if ( v4 )
  {
    v6 = a1[3];
    v7 = (unsigned int)dcgettext(0, "while rewriting block and inode bitmaps for %s", 5);
    com_err(a1[1], v4, v7, v6, v8, v9);
    fatal_error(a1, 0);
  }
  return result;
}


// Function: preenhalt @ 0x349d0
unsigned long long preenhalt(long long a1)
{
  long long v2; // r12
  char *v4; // rax
  long long v5; // rdi
  long long v6; // [rsp+0h] [rbp-28h] BYREF
  unsigned long long v7; // [rsp+8h] [rbp-20h]

  v7 = __readfsqword(0x28u);
  v6 = *(long long *)a1;
  if ( (*(char *)(a1 + 76) & 2) != 0 )
  {
    v2 = *(long long *)(a1 + 24);
    v4 = dcgettext(0, "\n\n%s: UNEXPECTED INCONSISTENCY; RUN fsck MANUALLY.\n\t(i.e., without -a or -p options)\n", 5);
    log_err(a1, (long long)v4, v2);
    v5 = v6;
    *(int *)(a1 + 72) |= 0x1000u;
    if ( v5 )
    {
      *(short *)(*(long long *)(v5 + 32) + 58LL) |= 2u;
      ext2fs_mark_super_dirty(v5);
      ext2fs_close_free(&v6);
    }
    exit(4);
  }
  return v7 - __readfsqword(0x28u);
}


// Function: init_resource_track @ 0x34a70
unsigned long long init_resource_track(struct timeval *tv, long long a2)
{
  __m128i si128; // xmm0
  __m128i v3; // xmm1
  long long v4; // rax
  void (*v5)(long long, long long *); // rax
  __time_t v6; // rax
  long long v8; // [rsp+8h] [rbp-C0h] BYREF
  struct rusage usage; // [rsp+10h] [rbp-B8h] BYREF
  unsigned long long v10; // [rsp+A8h] [rbp-20h]

  v10 = __readfsqword(0x28u);
  v8 = 0;
  tv[3].tv_sec = (__time_t)sbrk(0);
  gettimeofday(tv, 0);
  getrusage(RUSAGE_SELF, &usage);
  si128 = _mm_load_si128((const __m128i *)&usage);
  v3 = _mm_load_si128((const __m128i *)&usage.ru_stime);
  tv[3].tv_usec = 0;
  tv[4].tv_sec = 0;
  tv[1] = (struct timeval)si128;
  tv[2] = (struct timeval)v3;
  if ( a2 )
  {
    v4 = *(long long *)(a2 + 8);
    if ( v4 )
    {
      v5 = *(void (**)(long long, long long *))(v4 + 80);
      if ( v5 )
        v5(a2, &v8);
    }
  }
  if ( v8 )
  {
    v6 = *(long long *)(v8 + 16);
    tv[3].tv_usec = *(long long *)(v8 + 8);
    tv[4].tv_sec = v6;
  }
  return v10 - __readfsqword(0x28u);
}


// Function: print_resource_track @ 0x34b50
unsigned long long print_resource_track(long long a1, const char *a2, long long *a3, long long a4)
{
  int v6; // eax
  unsigned long long v7; // r15
  unsigned long long v8; // r14
  char *v9; // rax
  char *v10; // rax
  long long v11; // rax
  void (*v12)(long long, long long *); // rax
  double v13; // xmm2_8
  double v14; // xmm2_8
  long long v15; // r8
  long long v16; // r9
  char *v18; // r14
  char *v19; // rax
  unsigned long long v20; // [rsp+8h] [rbp-110h]
  float v21; // [rsp+8h] [rbp-110h]
  unsigned long long v22; // [rsp+10h] [rbp-108h]
  float v23; // [rsp+10h] [rbp-108h]
  float usage; // [rsp+18h] [rbp-100h]
  long long v25; // [rsp+28h] [rbp-F0h] BYREF
  struct timeval tv; // [rsp+30h] [rbp-E8h] BYREF
  struct rusage v27; // [rsp+40h] [rbp-D8h] BYREF
  unsigned long long v28; // [rsp+D8h] [rbp-40h]

  v28 = __readfsqword(0x28u);
  v6 = *(int *)(a1 + 76);
  if ( a2 )
  {
    if ( (v6 & 0x20) == 0 )
      return v28 - __readfsqword(0x28u);
    e2fsck_clear_progbar(a1);
    gettimeofday(&tv, 0);
    log_out(a1, (long long)"%s: ", a2);
  }
  else
  {
    if ( (v6 & 0x10) == 0 )
      return v28 - __readfsqword(0x28u);
    e2fsck_clear_progbar(a1);
    gettimeofday(&tv, 0);
  }
  if ( (long long)sbrk(0) - a3[6] > 0x7FFFFFFF )
  {
    v18 = (char *)sbrk(0) - a3[6];
    v19 = dcgettext(0, "Memory used: %lluk, ", 5);
    log_out(a1, (long long)v19, (unsigned long long)(v18 + 1023) >> 10);
  }
  else
  {
    mallinfo((struct mallinfo *)&v27);
    v22 = (unsigned long long)(SLODWORD(v27.ru_maxrss) + 1023LL) >> 10;
    v7 = (unsigned long long)(SLODWORD(v27.ru_stime.tv_sec) + 1023LL) >> 10;
    v8 = (unsigned long long)(SLODWORD(v27.ru_utime.tv_sec) + 1023LL) >> 10;
    v20 = (unsigned long long)(SHIDWORD(v27.ru_stime.tv_usec) + 1023LL) >> 10;
    v9 = dcgettext(0, "Memory used: %lluk/%lluk (%lluk/%lluk), ", 5);
    log_out(a1, (long long)v9, v8, v7, v20, v22);
  }
  getrusage(RUSAGE_SELF, &v27);
  usage = sub_33EC0(v27.ru_stime.tv_sec, v27.ru_stime.tv_usec, a3[4], a3[5]);
  v23 = sub_33EC0(v27.ru_utime.tv_sec, v27.ru_utime.tv_usec, a3[2], a3[3]);
  v21 = sub_33EC0(tv.tv_sec, tv.tv_usec, *a3, a3[1]);
  v10 = dcgettext(0, "time: %5.2f/%5.2f/%5.2f\n", 5);
  log_out(a1, (long long)v10, v21, v23, usage);
  if ( a4 )
  {
    v11 = *(long long *)(a4 + 8);
    if ( v11 )
    {
      v12 = *(void (**)(long long, long long *))(v11 + 80);
      if ( v12 )
      {
        v25 = 0;
        if ( a2 )
        {
          log_out(a1, (long long)"%s: ", a2);
          v12 = *(void (**)(long long, long long *))(*(long long *)(a4 + 8) + 80LL);
        }
        v12(a4, &v25);
        if ( v25 )
          v13 = (double)(int)((unsigned long long)(*(long long *)(v25 + 8) - a3[7] + *(long long *)(v25 + 16) - a3[8] + 0xFFFFFLL) >> 20);
        else
          v13 = 0.0;
        v14 = v13 / sub_33EC0(tv.tv_sec, tv.tv_usec, *a3, a3[1]);
        log_out(a1, (long long)"I/O read: %lluMB, write: %lluMB, rate: %.2fMB/s\n", v15, v16, v14);
      }
    }
  }
  return v28 - __readfsqword(0x28u);
}


// Function: e2fsck_read_inode @ 0x34ea0
long long e2fsck_read_inode(long long *a1, long long a2, long long a3, int a4)
{
  long long result; // rax
  int v6; // r12d
  unsigned int v7; // eax
  int v8; // r9d

  result = ext2fs_read_inode(*a1, a2, a3);
  if ( result )
  {
    v6 = result;
    v7 = (unsigned int)dcgettext(0, "while reading inode %lu in %s", 5);
    com_err((unsigned int)"ext2fs_read_inode", v6, v7, a2, a4, v8);
    fatal_error(a1, 0);
  }
  return result;
}


// Function: e2fsck_read_inode_full @ 0x34f10
long long e2fsck_read_inode_full(long long *a1, long long a2, long long a3, long long a4, int a5)
{
  long long result; // rax
  int v7; // r12d
  unsigned int v8; // eax
  int v9; // r9d

  result = ext2fs_read_inode_full(*a1, a2, a3, a4);
  if ( result )
  {
    v7 = result;
    v8 = (unsigned int)dcgettext(0, "while reading inode %lu in %s", 5);
    com_err((unsigned int)"ext2fs_read_inode_full", v7, v8, a2, a5, v9);
    fatal_error(a1, 0);
  }
  return result;
}


// Function: e2fsck_write_inode_full @ 0x34f80
long long e2fsck_write_inode_full(long long *a1, long long a2, long long a3, long long a4, int a5)
{
  long long result; // rax
  int v7; // r12d
  unsigned int v8; // eax
  int v9; // r9d

  result = ext2fs_write_inode_full(*a1, a2, a3, a4);
  if ( result )
  {
    v7 = result;
    v8 = (unsigned int)dcgettext(0, "while writing inode %lu in %s", 5);
    com_err((unsigned int)"ext2fs_write_inode", v7, v8, a2, a5, v9);
    fatal_error(a1, 0);
  }
  return result;
}


// Function: e2fsck_write_inode @ 0x34ff0
long long e2fsck_write_inode(long long *a1, long long a2, long long a3, int a4)
{
  long long result; // rax
  int v6; // r12d
  unsigned int v7; // eax
  int v8; // r9d

  result = ext2fs_write_inode(*a1, a2, a3);
  if ( result )
  {
    v6 = result;
    v7 = (unsigned int)dcgettext(0, "while writing inode %lu in %s", 5);
    com_err((unsigned int)"ext2fs_write_inode", v6, v7, a2, a4, v8);
    fatal_error(a1, 0);
  }
  return result;
}


// Function: get_backup_sb @ 0x35060
long long get_backup_sb(long long a1, long long a2, long long a3, long long a4)
{
  long long v4; // rax
  unsigned long long v5; // r12
  int v6; // eax
  int v8; // eax
  long long v9; // r13
  int i; // ebp
  long long v11; // [rsp+8h] [rbp-40h] BYREF
  long long v12[7]; // [rsp+10h] [rbp-38h] BYREF

  v12[1] = __readfsqword(0x28u);
  v11 = 0;
  v12[0] = 0;
  if ( a2 )
  {
    v4 = *(long long *)(a2 + 32);
    if ( v4 )
    {
      v5 = (unsigned int)(*(int *)(v4 + 32) + *(int *)(v4 + 20));
      if ( a1 )
      {
        v6 = *(int *)(a2 + 40);
        *(long long *)(a1 + 96) = v5;
        *(int *)(a1 + 80) = v6;
      }
      return v5;
    }
  }
  if ( a1 )
  {
    v8 = *(int *)(a1 + 80);
    if ( v8 )
    {
      v5 = (v8 == 1024) + (unsigned long long)(unsigned int)(8 * v8);
      *(long long *)(a1 + 96) = v5;
      return v5;
    }
    *(long long *)(a1 + 96) = 8193;
    *(int *)(a1 + 80) = 1024;
  }
  if ( !a3 || !a4 )
    return 8193;
  if ( (*(long long (**)(long long, long long, long long *))(a4 + 16))(a3, 0, &v11) || ext2fs_get_mem(1024, v12) )
  {
LABEL_12:
    v5 = 8193;
    goto LABEL_13;
  }
  v9 = v12[0];
  for ( i = 1024; ; i = 2048 )
  {
    while ( 1 )
    {
      v5 = 8 * i;
      if ( i != 1024 )
      {
        (*(void (**)(long long, long long))(*(long long *)(v11 + 8) + 32LL))(v11, (unsigned int)i);
        if ( io_channel_read_blk64(v11, 8 * i, 4294966272LL, v12[0]) )
          goto LABEL_22;
        goto LABEL_21;
      }
      ++v5;
      (*(void (**)(long long, long long))(*(long long *)(v11 + 8) + 32LL))(v11, 1024);
      if ( !io_channel_read_blk64(v11, v5, 4294966272LL, v12[0]) )
        break;
      (*(void (**)(long long, long long))(*(long long *)(v11 + 8) + 32LL))(v11, 2048);
      if ( io_channel_read_blk64(v11, 0x4000, 4294966272LL, v12[0]) )
      {
        i = 4096;
      }
      else
      {
        i = 2048;
        v5 = 0x4000;
LABEL_21:
        if ( *(short *)(v9 + 56) == 0xEF53 )
          goto LABEL_29;
LABEL_22:
        i *= 2;
        if ( i > 0x10000 )
          goto LABEL_12;
      }
    }
    if ( *(short *)(v9 + 56) == 0xEF53 )
      break;
  }
LABEL_29:
  if ( 1024 << *(int *)(v9 + 24) != i )
    goto LABEL_22;
  if ( a1 )
  {
    *(long long *)(a1 + 96) = v5;
    *(int *)(a1 + 80) = i;
  }
LABEL_13:
  if ( v11 )
    (*(void (**)(void))(*(long long *)(v11 + 8) + 24LL))();
  if ( v12[0] )
    ext2fs_free_mem(v12);
  return v5;
}


// Function: ext2_file_type @ 0x352e0
long long ext2_file_type(short a1)
{
  int v1; // edi
  long long result; // rax

  v1 = a1 & 0xF000;
  result = 1;
  if ( v1 != 0x8000 )
  {
    switch ( v1 )
    {
      case 16384:
        return 2;
      case 8192:
        return 3;
      case 24576:
        return 4;
      case 40960:
        return 7;
      case 4096:
        return 5;
      default:
        result = 0;
        if ( v1 == 49152 )
          return 6;
        break;
    }
  }
  return result;
}


// Function: fs_proc_check @ 0x35380
long long fs_proc_check(char *s1)
{
  FILE *v1; // rax
  FILE *v2; // r12
  const unsigned short **v3; // rax
  long long v4; // rdx
  const char *v5; // rbp
  const unsigned short *v6; // rcx
  char v7; // al
  char *v8; // rax
  char *v9; // rax
  char *v10; // rax
  char v12; // al
  char v13[88]; // [rsp+0h] [rbp-88h] BYREF
  unsigned long long v14; // [rsp+58h] [rbp-30h]

  v14 = __readfsqword(0x28u);
  v1 = fopen("/proc/filesystems", "r");
  if ( !v1 )
    return 0;
  v2 = v1;
  while ( !feof(v2) && fgets(v13, 80, v2) )
  {
    v3 = __ctype_b_loc();
    v4 = v13[0];
    v5 = v13;
    v6 = *v3;
    if ( ((*v3)[v13[0]] & 0x2000) != 0 )
    {
      if ( v13[0] )
      {
LABEL_10:
        while ( (v6[v4] & 0x2000) != 0 )
        {
          v7 = *++v5;
          if ( !v7 )
            break;
          v4 = v7;
        }
      }
    }
    else if ( v13[0] )
    {
      while ( 1 )
      {
        v12 = *++v5;
        if ( !v12 )
          break;
        v4 = v12;
        if ( (v6[v12] & 0x2000) != 0 )
          goto LABEL_10;
      }
    }
    v8 = strchr(v5, 10);
    if ( v8 )
      *v8 = 0;
    v9 = strchr(v5, 9);
    if ( v9 )
      *v9 = 0;
    v10 = strchr(v5, 32);
    if ( v10 )
      *v10 = 0;
    if ( !strcmp(s1, v5) )
    {
      fclose(v2);
      return 1;
    }
  }
  fclose(v2);
  return 0;
}


// Function: check_for_modules @ 0x354f0
long long check_for_modules(char *s2)
{
  unsigned int v1; // r13d
  FILE *v3; // rbp
  char *v4; // rax
  char *v5; // rax
  char *v6; // r15
  int v7; // eax
  const char *v8; // r14
  struct utsname v9; // [rsp+0h] [rbp-5D8h] BYREF
  char filename[1032]; // [rsp+190h] [rbp-448h] BYREF
  unsigned long long v11; // [rsp+598h] [rbp-40h]

  v11 = __readfsqword(0x28u);
  if ( uname(&v9) )
    return 0;
  v1 = 0;
  __snprintf_chk(filename, 1024, 1, 1024, "/lib/modules/%s/modules.dep", v9.release);
  v3 = fopen(filename, "r");
  if ( !v3 )
  {
    return 0;
  }
  else
  {
    while ( !feof(v3) && fgets(filename, 1024, v3) )
    {
      v4 = strchr(filename, 58);
      if ( v4 )
      {
        *v4 = 0;
        v5 = strrchr(filename, 47);
        v6 = v5 + 1;
        if ( !v5 )
          v6 = filename;
        v7 = strlen(v6);
        if ( v7 > 3 )
        {
          v8 = &v6[v7 - 3];
          if ( !strcmp(v8, ".ko") )
            *v8 = 0;
        }
        if ( !strcmp(v6, s2) )
        {
          v1 = 1;
          fclose(v3);
          return v1;
        }
      }
    }
    fclose(v3);
  }
  return v1;
}


// Function: write_all @ 0x35680
long long write_all(int fd, char *buf, size_t n)
{
  size_t v4; // rbx
  unsigned int v5; // r12d
  ssize_t v6; // rax
  int v8; // eax

  if ( n )
  {
    v4 = n;
    v5 = 0;
    do
    {
      while ( 1 )
      {
        v6 = write(fd, buf, v4);
        if ( v6 < 0 )
          break;
        buf += v6;
        v5 += v6;
        v4 -= v6;
        if ( !v4 )
          return v5;
      }
      v8 = *__errno_location();
    }
    while ( v8 == 11 || v8 == 4 );
    return 0xFFFFFFFFLL;
  }
  else
  {
    return 0;
  }
}


// Function: dump_mmp_msg @ 0x35700
unsigned long long dump_mmp_msg(long long a1, long long a2, ...)
{
  long long v2; // rcx
  long long v3; // r8
  long long v4; // r9
  char *v5; // rax
  time_t timer; // [rsp+8h] [rbp-F0h] BYREF
  gcc_va_list va; // [rsp+10h] [rbp-E8h] BYREF
  unsigned long long v9; // [rsp+28h] [rbp-D0h]

  v9 = __readfsqword(0x28u);
  if ( a2 )
  {
    __printf_chk(1, "MMP check failed: ");
    va_start(va, a2);
    __vprintf_chk(1, a2, va, v2, v3, v4);
  }
  if ( a1 )
  {
    timer = *(long long *)(a1 + 8);
    __printf_chk(1, "MMP_block:\n");
    __printf_chk(1, "    mmp_magic: 0x%x\n", *(int *)a1);
    __printf_chk(1, "    mmp_check_interval: %d\n", *(unsigned short *)(a1 + 112));
    __printf_chk(1, "    mmp_sequence: %08x\n", *(int *)(a1 + 4));
    v5 = ctime(&timer);
    __printf_chk(1, "    mmp_update_date: %s", v5);
    __printf_chk(1, "    mmp_update_time: %lld\n", *(long long *)(a1 + 8));
    __printf_chk(1, "    mmp_node_name: %.*s\n", 64, (const char *)(a1 + 16));
    __printf_chk(1, "    mmp_device_name: %.*s\n", 32, (const char *)(a1 + 80));
  }
  return v9 - __readfsqword(0x28u);
}


// Function: e2fsck_mmp_update @ 0x358c0
long long e2fsck_mmp_update(long long a1)
{
  long long result; // rax
  char *v2; // rax

  result = ext2fs_mmp_update();
  if ( result == 2133571471 )
  {
    v2 = dcgettext(0, "UNEXPECTED INCONSISTENCY: the filesystem is being modified while fsck is running.\n", 5);
    dump_mmp_msg(*(long long *)(a1 + 280), (long long)v2);
    return 2133571471;
  }
  return result;
}


// Function: e2fsck_set_bitmap_type @ 0x35920
unsigned long long e2fsck_set_bitmap_type(long long a1, unsigned int a2, long long a3, int *a4)
{
  short v4; // bx
  long long v5; // r14
  unsigned int v7; // [rsp+4h] [rbp-34h] BYREF
  unsigned long long v8; // [rsp+8h] [rbp-30h]

  v4 = a2;
  v5 = *(long long *)(a1 + 224);
  v8 = __readfsqword(0x28u);
  if ( a4 )
    *a4 = *(unsigned short *)(a1 + 196);
  profile_get_uint(*(long long *)(v5 + 864), "bitmaps", a3, 0, a2, &v7);
  profile_get_uint(*(long long *)(v5 + 864), "bitmaps", "all", 0, v7, &v7);
  if ( v7 )
    v4 = v7;
  *(short *)(a1 + 196) = v4;
  return v8 - __readfsqword(0x28u);
}


// Function: e2fsck_read_bitmaps @ 0x359d0
unsigned long long e2fsck_read_bitmaps(long long *a1)
{
  long long v2; // r13
  char *v3; // rax
  long long v4; // r14
  int v5; // edx
  int v6; // ebx
  long long bitmaps; // r12
  long long v9; // r12
  unsigned int v10; // eax
  int v11; // r8d
  int v12; // r9d
  long long v13; // rdi
  int v14; // esi
  unsigned int v15; // edx
  int v16; // ecx
  long long v17; // r13
  unsigned int v18; // eax
  int v19; // [rsp+4h] [rbp-34h] BYREF
  unsigned long long v20; // [rsp+8h] [rbp-30h]

  v2 = *a1;
  v20 = __readfsqword(0x28u);
  if ( *((int *)a1 + 130) )
  {
    v9 = a1[3];
    v10 = (unsigned int)dcgettext(0, "e2fsck_read_bitmaps: illegal bitmap block(s) for %s", 5);
    v13 = a1[1];
    v14 = 0;
    v15 = v10;
    v16 = v9;
    goto LABEL_5;
  }
  v3 = dcgettext(0, "reading inode and block bitmaps", 5);
  v4 = ehandler_operation(v3);
  e2fsck_set_bitmap_type(v2, 2u, (long long)"fs_bitmaps", &v19);
  v5 = *(int *)(*a1 + 16);
  v6 = v5 & 0x200000;
  *(int *)(*a1 + 16) = v5 | 0x200000;
  bitmaps = ext2fs_read_bitmaps(v2);
  *(int *)(*a1 + 16) = v6 | *(int *)(*a1 + 16) & 0xFFDFFFFF;
  *(short *)(v2 + 196) = v19;
  ehandler_operation(v4);
  if ( bitmaps )
  {
    v17 = a1[3];
    v18 = (unsigned int)dcgettext(0, "while retrying to read bitmaps for %s", 5);
    v13 = a1[1];
    v14 = bitmaps;
    v15 = v18;
    v16 = v17;
LABEL_5:
    com_err(v13, v14, v15, v16, v11, v12);
    fatal_error(a1, 0);
  }
  return v20 - __readfsqword(0x28u);
}


// Function: e2fsck_allocate_inode_bitmap @ 0x35b10
long long e2fsck_allocate_inode_bitmap(long long a1, long long a2, unsigned int a3, long long a4, long long a5)
{
  long long result; // rax
  int v7; // [rsp+4h] [rbp-24h] BYREF
  unsigned long long v8; // [rsp+8h] [rbp-20h]

  v8 = __readfsqword(0x28u);
  e2fsck_set_bitmap_type(a1, a3, a4, &v7);
  result = ext2fs_allocate_inode_bitmap(a1, a2, a5);
  *(short *)(a1 + 196) = v7;
  return result;
}


// Function: e2fsck_allocate_block_bitmap @ 0x35b80
long long e2fsck_allocate_block_bitmap(long long a1, char *s, unsigned int a3, long long a4, long long a5)
{
  long long result; // rax
  int v7; // [rsp+4h] [rbp-24h] BYREF
  unsigned long long v8; // [rsp+8h] [rbp-20h]

  v8 = __readfsqword(0x28u);
  e2fsck_set_bitmap_type(a1, a3, a4, &v7);
  result = ext2fs_allocate_block_bitmap(a1, s, a5);
  *(short *)(a1 + 196) = v7;
  return result;
}


// Function: e2fsck_allocate_subcluster_bitmap @ 0x35bf0
long long e2fsck_allocate_subcluster_bitmap(long long a1, char *s, unsigned int a3, long long a4)
{
  long long result; // rax
  int v5; // [rsp+4h] [rbp-24h] BYREF
  unsigned long long v6; // [rsp+8h] [rbp-20h]

  v6 = __readfsqword(0x28u);
  e2fsck_set_bitmap_type(a1, a3, a4, &v5);
  result = ext2fs_allocate_subcluster_bitmap(a1, s);
  *(short *)(a1 + 196) = v5;
  return result;
}


// Function: get_memory_size @ 0x35c60
long long get_memory_size()
{
  long long v0; // rbx

  v0 = sysconf(85);
  return v0 * sysconf(30);
}


// Function: setup_tdb @ 0x35c90
unsigned long long setup_tdb(long long *a1, unsigned int a2)
{
  long long v3; // r13
  long long v4; // rdi
  size_t v5; // rax
  __mode_t v7; // r14d
  int v8; // ebp
  char *v9; // rax
  unsigned int v10; // [rsp+0h] [rbp-68h] BYREF
  int v11; // [rsp+4h] [rbp-64h] BYREF
  char *name; // [rsp+8h] [rbp-60h] BYREF
  char v13[40]; // [rsp+10h] [rbp-58h] BYREF
  unsigned long long v14; // [rsp+38h] [rbp-30h]

  v3 = a1[70];
  v4 = a1[108];
  v14 = __readfsqword(0x28u);
  profile_get_string(v4, "scratch_files", "directory", 0, 0, &name);
  profile_get_uint(a1[108], "scratch_files", "numdirs_threshold", 0, 0, &v10);
  profile_get_boolean(a1[108], "scratch_files", "dirinfo", 0, 1, &v11);
  if ( v11 && name && !access(name, 2) && (v10 < a2 || !v10) )
  {
    v5 = strlen(name);
    if ( !ext2fs_get_mem(v5 + 64, v3 + 24) )
    {
      uuid_unparse(*(long long *)(*a1 + 32LL) + 104LL, v13);
      __sprintf_chk(*(long long *)(v3 + 24), 1, -1, "%s/%s-dirinfo-XXXXXX", name, v13);
      v7 = umask(0x3Fu);
      v8 = mkstemp(*(char **)(v3 + 24));
      umask(v7);
      if ( v8 < 0 )
      {
        *(long long *)(v3 + 32) = 0;
      }
      else
      {
        v9 = &algn_18696[1];
        if ( a2 >= (unsigned int)&algn_18696[1] )
          LODWORD(v9) = a2;
        *(long long *)(v3 + 32) = ext2fs_tdb_open(*(long long *)(v3 + 24), (unsigned int)v9, 68, 578, 384);
        close(v8);
      }
    }
  }
  return v14 - __readfsqword(0x28u);
}


// Function: setup_db @ 0x35e50
unsigned long long setup_db(long long *a1)
{
  long long *memory; // rax
  long long v3; // rdi
  long long *v4; // rbx
  long long v6; // rax
  unsigned int v7; // [rsp+4h] [rbp-24h] BYREF
  unsigned long long v8; // [rsp+8h] [rbp-20h]

  v8 = __readfsqword(0x28u);
  memory = (long long *)e2fsck_allocate_memory(a1, 0x28u, "directory map db");
  v3 = *a1;
  *memory = 0;
  v4 = memory;
  memory[1] = 0;
  a1[70] = (long long)memory;
  if ( ext2fs_get_num_dirs(v3, &v7) )
  {
    v7 = 1024;
    sub_35C90(a1, 0x400u);
    if ( v4[4] )
      return v8 - __readfsqword(0x28u);
LABEL_5:
    v6 = v7 + 10;
    *((int *)v4 + 1) = v6;
    v4[1] = e2fsck_allocate_memory(a1, 12 * v6, "directory map");
    return v8 - __readfsqword(0x28u);
  }
  sub_35C90(a1, v7);
  if ( !v4[4] )
    goto LABEL_5;
  return v8 - __readfsqword(0x28u);
}


// Function: e2fsck_add_dir_info @ 0x36110
unsigned long long e2fsck_add_dir_info(long long *a1, unsigned int a2, unsigned int a3)
{
  unsigned int *v6; // rdi
  long long v7; // rax
  long long v8; // rsi
  unsigned int *v9; // rax
  unsigned int v11; // r10d
  unsigned int v12; // edx
  long long v13; // r11
  unsigned int *v14; // rcx
  long long v15; // r9
  long long v16; // rdi
  long long v17; // r8
  unsigned int *v18; // rsi
  unsigned int *v19; // rsi
  long long v20; // rdx
  long long v21; // r13
  int v22[3]; // [rsp+Ch] [rbp-3Ch] BYREF
  unsigned long long v23; // [rsp+18h] [rbp-30h]

  v6 = (unsigned int *)a1[70];
  v23 = __readfsqword(0x28u);
  if ( !v6 )
  {
    sub_35E50(a1);
    v6 = (unsigned int *)a1[70];
  }
  v7 = v6[1];
  if ( *v6 >= (unsigned int)v7 )
  {
    v20 = (unsigned int)(v7 + 10);
    v21 = *((long long *)v6 + 1);
    v6[1] = v20;
    if ( ext2fs_resize_mem(12 * v7, 12 * v20, v6 + 2) )
    {
      __fprintf_chk(stderr, 1, "Couldn't reallocate dir_info structure to %u entries\n", *(int *)(a1[70] + 4));
      fatal_error(a1, 0);
    }
    v6 = (unsigned int *)a1[70];
    if ( *((long long *)v6 + 1) != v21 )
      *((long long *)v6 + 2) = 0;
  }
  if ( *((long long *)v6 + 4) )
  {
    v22[0] = a2;
    v22[2] = a3;
    v22[1] = a3;
    sub_35F20(v6, v22);
    return v23 - __readfsqword(0x28u);
  }
  v8 = *v6;
  v9 = (unsigned int *)*((long long *)v6 + 1);
  if ( (int)v8
    && (v11 = v8 - 1,
        v12 = v8 - 1,
        v13 = 12LL * (unsigned int)(v8 - 1),
        v14 = &v9[(unsigned long long)v13 / 4],
        v9[(unsigned long long)v13 / 4] >= a2) )
  {
    if ( (int)v8 != 1 )
    {
      while ( 1 )
      {
        v15 = v12 - 1;
        if ( v9[3 * v15] < a2 )
          break;
        --v12;
        if ( !(int)v15 )
          goto LABEL_13;
      }
      v9 += 3 * v12;
      if ( *v9 == a2 )
        goto LABEL_7;
      *v6 = v8 + 1;
      if ( (unsigned int)v8 <= v12 )
        goto LABEL_7;
      goto LABEL_15;
    }
LABEL_13:
    if ( a2 != *v9 )
    {
      *v6 = v8 + 1;
LABEL_15:
      v16 = 3 * v8;
      while ( 1 )
      {
        v17 = *(long long *)v14;
        v18 = v14;
        v14 -= 3;
        v19 = &v18[v13 / 0xFFFFFFFFFFFFFFFCLL];
        *(long long *)&v19[v16] = v17;
        v19[v16 + 2] = v14[5];
        if ( v11 <= v12 )
          break;
        --v11;
      }
    }
  }
  else
  {
    *v6 = v8 + 1;
    v9 += 3 * v8;
  }
LABEL_7:
  *v9 = a2;
  v9[1] = a3;
  v9[2] = a3;
  return v23 - __readfsqword(0x28u);
}


// Function: e2fsck_free_dir_info @ 0x36320
void e2fsck_free_dir_info(long long a1)
{
  long long v2; // rdi
  unsigned int v3; // r12d
  int *v4; // rax
  int v5; // ecx
  int v6; // r8d
  int v7; // r9d

  v2 = *(long long *)(a1 + 560);
  if ( v2 )
  {
    if ( *(long long *)(v2 + 32) )
    {
      ext2fs_tdb_close(*(void **)(v2 + 32));
      v2 = *(long long *)(a1 + 560);
    }
    if ( *(long long *)(v2 + 24) )
    {
      if ( unlink(*(const char **)(v2 + 24)) < 0 )
      {
        v3 = (unsigned int)dcgettext(0, "while freeing dir_info tdb file", 5);
        v4 = __errno_location();
        com_err((unsigned int)"e2fsck_free_dir_info", *v4, v3, v5, v6, v7);
      }
      ext2fs_free_mem(*(long long *)(a1 + 560) + 24LL);
      v2 = *(long long *)(a1 + 560);
    }
    if ( *(long long *)(v2 + 8) )
    {
      ext2fs_free_mem(v2 + 8);
      v2 = *(long long *)(a1 + 560);
    }
    *(long long *)v2 = 0;
    *(long long *)(v2 + 8) = 0;
    ext2fs_free_mem(a1 + 560);
    *(long long *)(a1 + 560) = 0;
  }
}


// Function: e2fsck_get_num_dirinfo @ 0x36410
long long e2fsck_get_num_dirinfo(long long a1)
{
  unsigned int *v1; // rdx
  long long result; // rax

  v1 = *(unsigned int **)(a1 + 560);
  result = 0;
  if ( v1 )
    return *v1;
  return result;
}


// Function: e2fsck_dir_info_iter_begin @ 0x36430
long long e2fsck_dir_info_iter_begin(long long *a1)
{
  long long memory; // r12
  long long v2; // rdx

  memory = e2fsck_allocate_memory(a1, 0x18u, "dir_info iterator");
  if ( *(long long *)(a1[70] + 32LL) )
  {
    *(long long *)(memory + 8) = ext2fs_tdb_firstkey();
    *(long long *)(memory + 16) = v2;
  }
  return memory;
}


// Function: e2fsck_dir_info_iter_end @ 0x36480
long long e2fsck_dir_info_iter_end(long long a1, long long a2)
{
  void *v2; // rdi
  long long v4; // [rsp+8h] [rbp-10h] BYREF

  v2 = *(void **)(a2 + 8);
  v4 = a2;
  free(v2);
  return ext2fs_free_mem(&v4);
}


// Function: e2fsck_dir_info_iter @ 0x364b0
int *e2fsck_dir_info_iter(long long a1, unsigned int *a2)
{
  long long v2; // rax
  long long v4; // rdi
  int *v5; // r13
  long long v6; // r15
  int *v7; // rax
  int *v8; // r12
  long long v9; // rax
  int *v10; // rdi
  long long v11; // rdx
  long long v13; // rdx
  long long v14; // rcx
  const char *v15; // rax

  v2 = *(long long *)(a1 + 560);
  if ( !a2 || !v2 )
    return 0;
  v4 = *(long long *)(v2 + 32);
  if ( !v4 )
  {
    v13 = *a2;
    if ( (unsigned int)v13 < *(int *)v2 )
    {
      v14 = *(long long *)(v2 + 8);
      *a2 = v13 + 1;
      v5 = (int *)(v14 + 12 * v13);
      *(long long *)(v2 + 16) = v5;
      return v5;
    }
    return 0;
  }
  v5 = (int *)*((long long *)a2 + 1);
  if ( v5 )
  {
    v6 = *((long long *)a2 + 2);
    v7 = (int *)ext2fs_tdb_fetch(v4, *((long long *)a2 + 1), v6);
    v8 = v7;
    if ( v7 )
    {
      dword_B7368 = **((int **)a2 + 1);
      dword_B736C = *v7;
      dword_B7370 = v7[1];
      v9 = ext2fs_tdb_nextkey(*(long long *)(*(long long *)(a1 + 560) + 32LL), v5, v6);
      v10 = v5;
      v5 = &dword_B7368;
      *((long long *)a2 + 1) = v9;
      *((long long *)a2 + 2) = v11;
      free(v10);
      free(v8);
    }
    else
    {
      v5 = 0;
      v15 = (const char *)ext2fs_tdb_errorstr(*(long long *)(*(long long *)(a1 + 560) + 32LL));
      __printf_chk(1, "iter fetch failed: %s\n", v15);
    }
  }
  return v5;
}


// Function: e2fsck_dir_info_set_parent @ 0x365e0
long long e2fsck_dir_info_set_parent(long long a1, long long a2, int a3)
{
  long long v4; // rsi
  long long result; // rax

  v4 = sub_35FB0(*(long long *)(a1 + 560));
  result = 1;
  if ( v4 )
  {
    *(int *)(v4 + 8) = a3;
    sub_35F20(*(long long *)(a1 + 560), v4);
    return 0;
  }
  return result;
}


// Function: e2fsck_dir_info_set_dotdot @ 0x36620
long long e2fsck_dir_info_set_dotdot(long long a1, long long a2, int a3)
{
  long long v4; // rsi
  long long result; // rax

  v4 = sub_35FB0(*(long long *)(a1 + 560));
  result = 1;
  if ( v4 )
  {
    *(int *)(v4 + 4) = a3;
    sub_35F20(*(long long *)(a1 + 560), v4);
    return 0;
  }
  return result;
}


// Function: e2fsck_dir_info_get_parent @ 0x36660
long long e2fsck_dir_info_get_parent(long long a1, long long a2, int *a3)
{
  long long v4; // rax

  v4 = sub_35FB0(*(long long *)(a1 + 560));
  if ( !v4 )
    return 1;
  *a3 = *(int *)(v4 + 8);
  return 0;
}


// Function: e2fsck_dir_info_get_dotdot @ 0x36690
long long e2fsck_dir_info_get_dotdot(long long a1, long long a2, int *a3)
{
  long long v4; // rax

  v4 = sub_35FB0(*(long long *)(a1 + 560));
  if ( !v4 )
    return 1;
  *a3 = *(int *)(v4 + 4);
  return 0;
}


// Function: e2fsck_add_dx_dir @ 0x366c0
long long e2fsck_add_dx_dir(long long a1, unsigned int a2, long long a3, int a4)
{
  long long v6; // r12
  long long v7; // rdx
  long long v8; // rax
  long long v9; // rbx
  unsigned int v10; // r8d
  unsigned int v11; // eax
  long long v12; // r9
  const __m128i *v13; // rcx
  long long v14; // rsi
  __m128i v15; // xmm0
  const __m128i *v16; // rdx
  char *v17; // rdx
  int v18; // eax
  short v19; // dx
  long long result; // rax
  long long v21; // rdx

  v6 = a4;
  if ( !*(long long *)(a1 + 576) )
  {
    *(long long *)(a1 + 568) = 0x6400000000LL;
    *(long long *)(a1 + 576) = e2fsck_allocate_memory((long long *)a1, 0x960u, "directory map");
  }
  v7 = *(unsigned int *)(a1 + 568);
  v8 = *(unsigned int *)(a1 + 572);
  if ( (unsigned int)v7 >= (unsigned int)v8 )
  {
    v21 = (unsigned int)(v8 + 10);
    *(int *)(a1 + 572) = v21;
    if ( ext2fs_resize_mem(24 * v8, 24 * v21, a1 + 576) )
    {
      __fprintf_chk(stderr, 1, "Couldn't reallocate dx_dir_info structure to %u entries\n", *(int *)(a1 + 572));
      fatal_error((long long *)a1, 0);
    }
    v7 = *(unsigned int *)(a1 + 568);
  }
  v9 = *(long long *)(a1 + 576);
  if ( !(int)v7
    || (v10 = v7 - 1,
        v11 = v7 - 1,
        v12 = 24LL * (unsigned int)(v7 - 1),
        v13 = (const __m128i *)(v9 + v12),
        *(int *)(v9 + v12) < a2) )
  {
    *(int *)(a1 + 568) = v7 + 1;
    v9 += 24 * v7;
    goto LABEL_17;
  }
  while ( 1 )
  {
    if ( !v11 )
    {
      if ( a2 == *(int *)v9 )
        goto LABEL_17;
      *(int *)(a1 + 568) = v7 + 1;
      goto LABEL_12;
    }
    if ( *(int *)(v9 + 24LL * (v11 - 1)) < a2 )
      break;
    --v11;
  }
  v9 += 24LL * v11;
  if ( *(int *)v9 != a2 )
  {
    *(int *)(a1 + 568) = v7 + 1;
    if ( v11 < (unsigned int)v7 )
    {
LABEL_12:
      v14 = 24 * v7;
      while ( 1 )
      {
        v15 = _mm_loadu_si128(v13);
        v16 = v13;
        v13 = (const __m128i *)((char *)v13 - 24);
        v17 = &v16->m128i_i8[-v12];
        *(__m128i *)&v17[v14] = v15;
        *(long long *)&v17[v14 + 16] = v13[2].m128i_i64[1];
        if ( v10 <= v11 )
          break;
        --v10;
      }
    }
  }
LABEL_17:
  v18 = *(int *)(a3 + 32);
  v19 = *(short *)(v9 + 6);
  *(int *)v9 = a2;
  *(int *)(v9 + 8) = v6;
  *(short *)(v9 + 6) = v19 & 0xFE00 | (((v18 & 0x40000000) != 0) << 8);
  result = e2fsck_allocate_memory((long long *)a1, 48 * v6, "dx_block info array");
  *(long long *)(v9 + 16) = result;
  return result;
}


// Function: e2fsck_get_dx_dir_info @ 0x368c0
int *e2fsck_get_dx_dir_info(long long a1, unsigned int a2)
{
  int *v2; // r8
  unsigned int v3; // ecx
  long long v4; // rdx
  int *result; // rax
  unsigned int v6; // eax
  unsigned int *v7; // rdi

  v2 = *(int **)(a1 + 576);
  if ( !v2 || *v2 == a2 )
    return v2;
  v3 = 0;
  v4 = (unsigned int)(*(int *)(a1 + 568) - 1);
  result = &v2[6 * v4];
  if ( *result != a2 )
  {
    while ( 1 )
    {
      if ( v3 >= (unsigned int)v4 )
        return 0;
      v6 = (v3 + (unsigned int)v4) >> 1;
      if ( v3 == v6 || (int)v4 == v6 )
        return 0;
      v7 = &v2[6 * v6];
      if ( *v7 == a2 )
        break;
      if ( *v7 > a2 )
        LODWORD(v4) = (v3 + (unsigned int)v4) >> 1;
      else
        v3 = (v3 + (unsigned int)v4) >> 1;
    }
    return &v2[6 * v6];
  }
  return result;
}


// Function: e2fsck_free_dx_dir_info @ 0x36940
long long e2fsck_free_dx_dir_info(long long a1)
{
  long long v1; // rbx
  long long *v2; // rbx
  unsigned int v3; // ebp
  long long result; // rax

  v1 = *(long long *)(a1 + 576);
  if ( v1 )
  {
    if ( *(int *)(a1 + 568) )
    {
      v2 = (long long *)(v1 + 16);
      v3 = 0;
      do
      {
        if ( *v2 )
        {
          ext2fs_free_mem(v2);
          *v2 = 0;
        }
        ++v3;
        v2 += 3;
      }
      while ( *(int *)(a1 + 568) > v3 );
    }
    result = ext2fs_free_mem(a1 + 576);
    *(long long *)(a1 + 576) = 0;
  }
  *(long long *)(a1 + 568) = 0;
  return result;
}


// Function: e2fsck_get_num_dx_dirinfo @ 0x369c0
long long e2fsck_get_num_dx_dirinfo(long long a1)
{
  return *(unsigned int *)(a1 + 568);
}


// Function: e2fsck_dx_dir_info_iter @ 0x369d0
long long e2fsck_dx_dir_info_iter(long long a1, int *a2)
{
  long long v2; // rax
  long long v3; // rdx

  v2 = (unsigned int)*a2;
  if ( (unsigned int)v2 >= *(int *)(a1 + 568) )
    return 0;
  v3 = *(long long *)(a1 + 576);
  *a2 = v2 + 1;
  return v3 + 24 * v2;
}


// Function: e2fsck_handle_write_error @ 0x36a00
long long e2fsck_handle_write_error(long long a1, long long a2, int a3, long long a4, int a5, int a6, long long errnum)
{
  long long v7; // r13
  long long v8; // r12
  long long v10; // r13
  long long result; // rax
  long long v12; // rbx
  long long v13; // r14
  char *v14; // rax
  char *v15; // rax
  int v16; // r8d
  long long v17; // r14
  char *v18; // rax

  v7 = *(long long *)(*(long long *)(a1 + 176) + 224LL);
  if ( (*(char *)(v7 + 73) & 0x10) != 0 )
    return 0;
  v8 = a2;
  if ( a3 <= 1 )
  {
    v12 = qword_B7378;
    if ( qword_B7378 )
    {
      v13 = error_message(errnum);
      v14 = dcgettext(0, "Error writing block %lu (%s) while %s.  ", 5);
      __printf_chk(1, v14, a2, v13, v12);
    }
    else
    {
      v17 = error_message(errnum);
      v18 = dcgettext(0, "Error writing block %lu (%s).  ", 5);
      __printf_chk(1, v18, a2, v17);
    }
    preenhalt(v7);
    v15 = dcgettext(0, "Ignore error", 5);
    v16 = ask(v7, v15, 1u);
    result = errnum;
    if ( !v16 )
      return result;
    return 0;
  }
  v10 = a2 + (unsigned int)(a3 - 1) + 1;
  while ( 1 )
  {
    result = io_channel_write_blk64(a1, v8, 1, a4);
    if ( result )
      break;
    ++v8;
    a4 += *(int *)(a1 + 24);
    if ( v10 == v8 )
      return 0;
  }
  return result;
}


// Function: e2fsck_handle_read_error @ 0x36b40
long long e2fsck_handle_read_error(long long a1, unsigned long long a2, int a3, long long a4, int a5, int a6, long long errnum)
{
  long long v7; // r15
  long long v8; // r14
  unsigned long long v9; // rbp
  long long v12; // rbx
  long long result; // rax
  char *v14; // rax
  char *v15; // rax
  int v16; // r8d
  char *v17; // rax
  char *v18; // rax
  long long v19; // [rsp+0h] [rbp-48h]
  long long v20; // [rsp+0h] [rbp-48h]
  long long v21; // [rsp+8h] [rbp-40h]

  v7 = *(long long *)(a1 + 176);
  v8 = *(long long *)(v7 + 224);
  if ( (*(char *)(v8 + 73) & 0x10) != 0 )
    return 0;
  v9 = a2;
  if ( a3 <= 1 )
  {
    v19 = qword_B7378;
    if ( qword_B7378 )
    {
      v21 = error_message(errnum);
      v14 = dcgettext(0, "Error reading block %lu (%s) while %s.  ", 5);
      __printf_chk(1, v14, a2, v21, v19);
    }
    else
    {
      v20 = error_message(errnum);
      v18 = dcgettext(0, "Error reading block %lu (%s).  ", 5);
      __printf_chk(1, v18, a2, v20);
    }
    preenhalt(v8);
    if ( ext2fs_blocks_count(*(long long *)(v7 + 32)) > a2 )
    {
      v15 = dcgettext(0, "Ignore error", 5);
      v16 = ask(v8, v15, 1u);
      result = errnum;
      if ( !v16 )
        return result;
      v17 = dcgettext(0, "Force rewrite", 5);
      if ( (unsigned int)ask(v8, v17, 1u) )
        io_channel_write_blk64(a1, a2, (unsigned int)a3, a4);
    }
    return 0;
  }
  v12 = a2 + (unsigned int)(a3 - 1) + 1;
  while ( 1 )
  {
    result = io_channel_read_blk64(a1, v9, 1, a4);
    if ( result )
      break;
    ++v9;
    a4 += *(int *)(a1 + 24);
    if ( v12 == v9 )
      return 0;
  }
  return result;
}


// Function: ehandler_operation @ 0x36ce0
long long ehandler_operation(long long a1)
{
  long long result; // rax

  result = qword_B7378;
  qword_B7378 = a1;
  return result;
}


// Function: ehandler_init @ 0x36d00
long long (*ehandler_init(
        long long a1))(long long a1, long long a2, int a3, long long a4, int a5, int a6, long long errnum)
{
  *(long long *)(a1 + 32) = sub_36B40;
  *(long long *)(a1 + 40) = sub_36A00;
  return sub_36A00;
}


// Function: find_problem @ 0x36d20
int *find_problem(int a1)
{
  int v1; // eax
  int *v2; // rdx
  int v3; // ecx

  v1 = dword_B2180[0];
  if ( !dword_B2180[0] )
    return 0;
  v2 = (int *)&unk_B21A8;
  v3 = 0;
  while ( a1 != v1 )
  {
    v1 = *v2;
    v2 += 10;
    ++v3;
    if ( !v1 )
      return 0;
  }
  return &dword_B2180[10 * v3];
}


// Function: find_latch @ 0x36d70
int *find_latch(int a1)
{
  int v1; // eax
  int *v2; // rdx
  int v3; // ecx

  v1 = dword_B20C0[0];
  if ( dword_B20C0[0] < 0 )
    return 0;
  v2 = (int *)&unk_B20D0;
  v3 = 0;
  while ( a1 != v1 )
  {
    v1 = *v2;
    v2 += 4;
    ++v3;
    if ( v1 < 0 )
      return 0;
  }
  return &dword_B20C0[4 * v3];
}


// Function: set_latch_flags @ 0x37160
long long set_latch_flags(int a1, int a2)
{
  int *v2; // rax
  int v3; // r8d

  v2 = sub_36D70(a1);
  if ( !v2 )
    return 0xFFFFFFFFLL;
  v2[3] = ~v3 & (v2[3] | a2);
  return 0;
}


// Function: get_latch_flags @ 0x37190
long long get_latch_flags(int a1, int *a2)
{
  int *v2; // rax

  v2 = sub_36D70(a1);
  if ( !v2 )
    return 0xFFFFFFFFLL;
  *a2 = v2[3];
  return 0;
}


// Function: clear_problem_context @ 0x371b0
long long clear_problem_context(long long a1)
{
  long long v2; // rdi

  *(long long *)a1 = 0;
  v2 = a1 + 8;
  *(long long *)(v2 + 88) = 0;
  memset(
    (void *)(v2 & 0xFFFFFFFFFFFFFFF8LL),
    0,
    8 * ((unsigned long long)((unsigned int)a1 - (v2 & 0xFFFFFFF8) + 104) >> 3));
  *(long long *)(a1 + 56) = -1;
  *(int *)(a1 + 64) = -1;
  return 0;
}


// Function: fix_problem @ 0x371f0
long long fix_problem(long long a1, unsigned int a2, long long a3)
{
  int *v6; // rax
  int v7; // esi
  int *v8; // rbx
  unsigned int v9; // r15d
  int v10; // r12d
  int *v11; // rax
  unsigned int v12; // r8d
  unsigned int v13; // r12d
  int v14; // eax
  int v15; // edx
  char *v16; // r11
  FILE *v17; // rdi
  int v18; // eax
  char v19; // al
  FILE *v20; // rdi
  int v22; // eax
  char *v23; // rax
  long long v24; // rdx
  int fixed; // eax
  int v26; // r12d
  int v27; // ecx
  char *v28; // rax
  char *v29; // rax
  const char *v30; // rdx
  long long v31; // rdi
  char *v32; // rsi
  char *v33; // rax
  char *v34; // rax
  int *v35; // [rsp+8h] [rbp-70h]
  long long v36; // [rsp+10h] [rbp-68h]
  char *v37; // [rsp+18h] [rbp-60h]
  char *v38; // [rsp+18h] [rbp-60h]
  long long v39; // [rsp+20h] [rbp-58h] BYREF
  char v40[9]; // [rsp+2Fh] [rbp-49h] BYREF
  unsigned long long v41; // [rsp+38h] [rbp-40h]

  v41 = __readfsqword(0x28u);
  v36 = *(long long *)a1;
  v6 = sub_36D20(a2);
  if ( !v6 )
  {
    v9 = 0;
    v33 = dcgettext(0, "Unhandled error code (0x%x)!\n", 5);
    __printf_chk(1, v33, a2);
    return v9;
  }
  v7 = v6[5];
  v8 = v6;
  if ( (v7 & 0x80000) == 0 )
  {
    v39 = 0;
    __sprintf_chk(v40, 1, 9, "0x%06x", a2);
    profile_get_string(*(long long *)(a1 + 864), "problems", v40, "description", 0, &v39);
    if ( v39 )
      *((long long *)v8 + 1) = v39;
    sub_370F0(*(long long *)(a1 + 864), v8, v40, 1, "preen_ok");
    sub_370F0(*(long long *)(a1 + 864), v8, v40, 2, "no_ok");
    sub_370F0(*(long long *)(a1 + 864), v8, v40, 4, "no_default");
    sub_370F0(*(long long *)(a1 + 864), v8, v40, 8, "print_message_only");
    sub_370F0(*(long long *)(a1 + 864), v8, v40, 0x4000, "preen_nomessage");
    sub_370F0(*(long long *)(a1 + 864), v8, v40, 0x8000, "no_collate");
    sub_370F0(*(long long *)(a1 + 864), v8, v40, 0x10000, "no_nomsg");
    sub_370F0(*(long long *)(a1 + 864), v8, v40, 0x40000, "preen_noheader");
    sub_370F0(*(long long *)(a1 + 864), v8, v40, 0x100000, "force_no");
    sub_370F0(*(long long *)(a1 + 864), v8, v40, 0x200000, "not_a_fix");
    profile_get_integer(*(long long *)(a1 + 864), "options", "max_count_problems", 0, 0, v8 + 8);
    profile_get_integer(*(long long *)(a1 + 864), "problems", v40, "max_count", (unsigned int)v8[8], v8 + 8);
    v7 = v8[5] | 0x80000;
    v8[5] = v7;
  }
  ++v8[7];
  v9 = v7 & 4;
  if ( (v7 & 4) != 0 )
  {
    v9 = 0;
  }
  else
  {
    v22 = *(int *)(a1 + 76);
    if ( (v7 & 0x20000) == 0 || (v22 & 2) == 0 )
      v9 = (v22 & 8) == 0;
  }
  v35 = 0;
  v10 = v7 & 0xFF0;
  if ( (v7 & 0xFF0) != 0 )
  {
    v11 = sub_36D70(v7 & 0xFF0);
    v12 = v11[1];
    v35 = v11;
    if ( v12 )
    {
      v13 = v11[3];
      if ( (v13 & 4) == 0 )
      {
        fixed = fix_problem(a1, v12, a3);
        if ( fixed == 1 )
        {
          v26 = v35[3] | 1;
        }
        else
        {
          v26 = v35[3];
          if ( !fixed )
            v26 = v35[3] | 2;
        }
        v13 = v26 | 4;
        v7 = v8[5];
        v35[3] = v13;
      }
    }
    else
    {
      v13 = v11[3];
    }
    v10 = (v13 >> 3) & 1;
  }
  if ( (v7 & 0x4000) != 0 )
    v10 -= ((*(int *)(a1 + 76) & 2) == 0) - 1;
  if ( (v7 & 0x10000) != 0 )
    v10 -= ((v7 & 0x100000 | *(int *)(a1 + 76) & 8) == 0) - 1;
  v14 = v8[8];
  if ( v14 )
  {
    v15 = v8[7];
    if ( v14 < v15 )
    {
      v10 -= ((*(int *)(a1 + 76) & 0xC) == 0) - 1;
      if ( (*(int *)(a1 + 76) & 2) != 0 )
        v10 -= ((v7 & 1) == 0) - 1;
      if ( (v7 & 0xFF0) != 0 )
        v10 -= ((v35[3] & 3) == 0) - 1;
      if ( v15 == v14 + 1 )
      {
        v31 = *(long long *)(a1 + 56);
        if ( v31 )
          __fprintf_chk(v31, 1, "<suppressed code=\"0x%06x\"/>\n", a2);
        __printf_chk(1, "...problem 0x%06x suppressed\n", *v8);
        fflush(stdout);
      }
    }
  }
  v16 = (char *)*((long long *)v8 + 1);
  if ( *v16 )
    v16 = dcgettext(0, *((const char **)v8 + 1), 5);
  if ( !v10 )
  {
    if ( (*(char *)(a1 + 76) & 2) == 0 || (*((char *)v8 + 22) & 4) != 0 )
    {
      if ( !*v16 )
        goto LABEL_26;
LABEL_89:
      v38 = v16;
      print_e2fsck_message(stdout);
      v16 = v38;
      goto LABEL_26;
    }
    v30 = *(const char **)(a1 + 24);
    if ( !v30 )
      v30 = *(const char **)(a1 + 16);
    v37 = v16;
    __printf_chk(1, "%s: ", v30);
    v16 = v37;
    if ( *v37 )
      goto LABEL_89;
  }
LABEL_26:
  v17 = *(FILE **)(a1 + 40);
  if ( v16 && v17 )
    print_e2fsck_message(v17);
  v18 = v8[5];
  if ( (v18 & 1) == 0 )
  {
    if ( !*((char *)v8 + 16) )
    {
      if ( (v18 & 0x1000) == 0 )
        goto LABEL_32;
LABEL_65:
      fatal_error((long long *)a1, 0);
    }
    preenhalt(a1);
    v18 = v8[5];
  }
  if ( (v18 & 0x1000) != 0 )
    goto LABEL_65;
  v24 = *((char *)v8 + 16);
  if ( !(char)v24 )
  {
LABEL_32:
    if ( (v18 & 0x8000) == 0 )
    {
      if ( (v18 & 0x2000) == 0 )
      {
LABEL_54:
        if ( v9 )
          goto LABEL_34;
LABEL_55:
        v9 = 0;
        goto LABEL_39;
      }
    }
    else
    {
      v9 = -1;
      if ( (v18 & 0x2000) == 0 )
      {
LABEL_34:
        v19 = *((char *)v8 + 16);
        goto LABEL_35;
      }
    }
LABEL_53:
    v9 = fix_problem(a1, (unsigned int)v8[6], a3);
    goto LABEL_54;
  }
  if ( (v18 & 0x100000) != 0 )
    goto LABEL_46;
  if ( (*(char *)(a1 + 76) & 2) != 0 )
  {
    if ( (v18 & 0x4000) != 0 )
    {
      if ( !v9 )
      {
LABEL_63:
        if ( (v18 & 2) != 0 )
        {
LABEL_52:
          if ( (v18 & 0x2000) == 0 )
            goto LABEL_55;
          goto LABEL_53;
        }
        ext2fs_unmark_valid(v36);
LABEL_51:
        v18 = v8[5];
        goto LABEL_52;
      }
      if ( (char)v24 != 11 )
      {
        if ( (v18 & 0x2000) != 0 )
          goto LABEL_53;
LABEL_37:
        if ( (v18 & 0x200000) == 0 )
          *(int *)(a1 + 72) |= 0x4000u;
        goto LABEL_39;
      }
      goto LABEL_111;
    }
    if ( !v9 )
    {
LABEL_46:
      if ( (v18 & 2) == 0 )
        ext2fs_unmark_valid(v36);
      if ( v10 )
      {
        if ( !*(long long *)(a1 + 40) )
          goto LABEL_51;
      }
      else
      {
        v23 = dcgettext(0, "IGNORED", 5);
        __printf_chk(1, "%s.\n", v23);
        if ( !*(long long *)(a1 + 40) )
          goto LABEL_50;
      }
      v34 = dcgettext(0, "IGNORED", 5);
      __fprintf_chk(*(long long *)(a1 + 40), 1, "%s.\n", v34);
LABEL_50:
      if ( *((char *)v8 + 16) != 11 )
      {
        if ( (*((char *)v8 + 21) & 0x20) == 0 )
          goto LABEL_55;
        goto LABEL_53;
      }
      goto LABEL_51;
    }
LABEL_79:
    if ( v10 )
    {
      if ( !*(long long *)(a1 + 40) )
      {
        if ( (char)v24 != 11 )
        {
          v9 = 1;
          if ( (v18 & 0x2000) != 0 )
            goto LABEL_53;
          goto LABEL_37;
        }
LABEL_111:
        fatal_error((long long *)a1, 0);
      }
    }
    else
    {
      v28 = dcgettext(0, off_B0D00[v24], 5);
      __printf_chk(1, "%s.\n", v28);
      if ( !*(long long *)(a1 + 40) )
        goto LABEL_83;
      v24 = *((char *)v8 + 16);
    }
    v29 = dcgettext(0, off_B0D00[v24], 5);
    __fprintf_chk(*(long long *)(a1 + 40), 1, "%s.\n", v29);
LABEL_83:
    if ( *((char *)v8 + 16) != 11 )
    {
      v9 = 1;
      if ( (*((char *)v8 + 21) & 0x20) == 0 )
        goto LABEL_34;
      goto LABEL_53;
    }
    goto LABEL_111;
  }
  if ( (v18 & 0xFF0) != 0 )
  {
    v27 = v35[3];
    if ( (v27 & 3) != 0 )
    {
      if ( (v27 & 1) == 0 )
        goto LABEL_46;
      goto LABEL_79;
    }
  }
  v32 = (char *)"";
  if ( (char)v24 != 22 )
    v32 = dcgettext(0, off_B0DC0[v24], 5);
  v9 = ask(a1, v32, v9);
  if ( !v9 )
  {
    v18 = v8[5];
    goto LABEL_63;
  }
  v19 = *((char *)v8 + 16);
  if ( v19 == 11 )
    goto LABEL_111;
  if ( (*((char *)v8 + 21) & 0x20) != 0 )
    goto LABEL_53;
LABEL_35:
  if ( v19 )
  {
    v18 = v8[5];
    goto LABEL_37;
  }
LABEL_39:
  v20 = *(FILE **)(a1 + 56);
  if ( v20 )
    sub_36DC0(v20);
  return v9;
}


// Function: end_problem_latch @ 0x37ae0
long long end_problem_latch(long long a1, int a2)
{
  int *v2; // rbx
  int v3; // edx
  long long v4; // r8
  long long v5; // r9
  long long result; // rax
  long long v7[15]; // [rsp+0h] [rbp-78h] BYREF

  v7[13] = __readfsqword(0x28u);
  v2 = sub_36D70(a2);
  v3 = v2[3];
  if ( v2[2] && (v3 & 4) != 0 )
  {
    clear_problem_context((long long)v7);
    result = fix_problem(v4, v2[2], v5);
    v3 = v2[3];
  }
  else
  {
    result = 0xFFFFFFFFLL;
  }
  v2[3] = v3 & 0xFFFFFFF0;
  return result;
}


// Function: safe_print @ 0x37b60
void safe_print(FILE *stream, char *s, int a3)
{
  char *v3; // rbp
  char *v4; // r12
  unsigned char v5; // bl

  v3 = s;
  if ( a3 < 0 )
    a3 = strlen(s);
  if ( a3 )
  {
    v4 = &s[a3];
    while ( 1 )
    {
      v5 = *v3++;
      if ( v5 <= 0x80u )
      {
        if ( v5 > 0x1Fu )
          goto LABEL_6;
LABEL_10:
        fputc(94, stream);
        fputc(v5 ^ 0x40, stream);
        if ( v3 == v4 )
          return;
      }
      else
      {
        v5 += 0x80;
        fputs("M-", stream);
        if ( v5 <= 0x1Fu )
          goto LABEL_10;
LABEL_6:
        if ( v5 == 127 )
          goto LABEL_10;
        fputc(v5, stream);
        if ( v3 == v4 )
          return;
      }
    }
  }
}


// Function: print_pathname @ 0x37c00
int print_pathname(FILE *stream, long long a2, unsigned int a3, unsigned int a4)
{
  long long v5; // rax
  char *v6; // rdi
  char *s; // [rsp+0h] [rbp-28h] BYREF
  unsigned long long v9; // [rsp+8h] [rbp-20h]

  v9 = __readfsqword(0x28u);
  if ( a3 || a4 > 0xA )
  {
    if ( !a2 || ext2fs_get_pathname(a2, a3, a4, &s) )
    {
      fputs("???", stream);
    }
    else
    {
      sub_37B60(stream, s, -1);
      ext2fs_free_mem(&s);
    }
    return v9 - __readfsqword(0x28u);
  }
  else
  {
    v6 = dcgettext(0, off_B0E80[a4], 5);
    LODWORD(v5) = fputs(v6, stream);
  }
  return v5;
}


// Function: print_time @ 0x37cd0
long long print_time(long long a1, time_t a2)
{
  struct tm *v2; // rax
  char *v3; // rax
  time_t timer; // [rsp+8h] [rbp-10h] BYREF

  timer = a2;
  v2 = localtime(&timer);
  v3 = asctime(v2);
  return __fprintf_chk(a1, 1, "%.24s", v3);
}


// Function: expand_dirent_expression @ 0x37d10
unsigned long long expand_dirent_expression(FILE *stream, long long a2, char a3, long long a4)
{
  char *v4; // r12
  unsigned long long result; // rax
  long long v6; // rcx
  unsigned int v7; // r14d
  unsigned int v8; // [rsp+4h] [rbp-34h] BYREF
  unsigned long long v9; // [rsp+8h] [rbp-30h]

  v9 = __readfsqword(0x28u);
  if ( !a4 )
    return __fprintf_chk(stream, 1, "%%D%c", (unsigned int)a3);
  v4 = *(char **)(a4 + 32);
  if ( !v4 )
    return __fprintf_chk(stream, 1, "%%D%c", (unsigned int)a3);
  switch ( a3 )
  {
    case 'i':
      return __fprintf_chk(stream, 1, "%u", *(unsigned int *)v4);
    case 'l':
      v6 = (unsigned int)ext2fs_dirent_name_len(*(long long *)(a4 + 32));
      goto LABEL_7;
    case 'n':
      v7 = ext2fs_dirent_name_len(*(long long *)(a4 + 32));
      if ( !ext2fs_get_rec_len(a2, v4, &v8) && v7 > v8 )
        v7 = v8;
      sub_37B60(stream, v4 + 8, v7);
      goto LABEL_9;
    case 'r':
      ext2fs_get_rec_len(a2, *(long long *)(a4 + 32), &v8);
      __fprintf_chk(stream, 1, "%u", v8);
LABEL_9:
      result = v9 - __readfsqword(0x28u);
      break;
    case 't':
      v6 = (unsigned int)ext2fs_dirent_file_type(*(long long *)(a4 + 32));
LABEL_7:
      result = __fprintf_chk(stream, 1, "%u", v6);
      break;
    default:
      return __fprintf_chk(stream, 1, "%%D%c", (unsigned int)a3);
  }
  return result;
}


// Function: expand_percent_expression @ 0x3d030
unsigned long long expand_percent_expression(long long a1, int a2, char **a3, char *a4)
{
  struct tm *v7; // rax
  long long v8; // rcx
  const time_t *v10; // rdi
  const char *v11; // r12
  char *v12; // rax
  long long v13; // r8
  __uid_t v14; // eax
  struct passwd *result; // [rsp+8h] [rbp-1B0h] BYREF
  struct passwd resultbuf; // [rsp+10h] [rbp-1A8h] BYREF
  struct tm tp; // [rsp+40h] [rbp-178h] BYREF
  char name[264]; // [rsp+80h] [rbp-138h] BYREF
  unsigned long long v19; // [rsp+188h] [rbp-30h]

  v19 = __readfsqword(0x28u);
  result = 0;
  if ( (a2 & 0xDF) == 0x44
    || (v7 = 0, (unsigned char)(a2 - 72) <= 0x31u)
    && (v8 = 0x2002000021821LL, _bittest64(&v8, (unsigned int)(a2 - 72))) )
  {
    tzset();
    v10 = (const time_t *)(a1 + 840);
    if ( (*a4 & 1) != 0 )
      v7 = gmtime_r(v10, &tp);
    else
      v7 = localtime_r(v10, &tp);
  }
  switch ( (char)a2 )
  {
    case '%':
      sub_3CFA0(a3, "%", 1);
      return v19 - __readfsqword(0x28u);
    case 'D':
      __sprintf_chk(
        name,
        1,
        256,
        "%d%02d%02d",
        (unsigned int)(v7->tm_year + 1900),
        (unsigned int)(v7->tm_mon + 1),
        (unsigned int)v7->tm_mday);
      goto LABEL_5;
    case 'H':
      __sprintf_chk(name, 1, 256, "%02d", (unsigned int)v7->tm_hour);
      goto LABEL_5;
    case 'M':
      __sprintf_chk(name, 1, 256, "%02d", (unsigned int)v7->tm_min);
      goto LABEL_5;
    case 'N':
      v11 = *(const char **)(a1 + 16);
      v12 = strrchr(v11, 47);
      if ( v12 )
        v11 = v12 + 1;
      sub_3CFA0(a3, v11, 0);
      return v19 - __readfsqword(0x28u);
    case 'S':
      __sprintf_chk(name, 1, 256, "%02d", (unsigned int)v7->tm_sec);
      goto LABEL_5;
    case 'T':
      __sprintf_chk(
        name,
        1,
        256,
        "%02d%02d%02d",
        (unsigned int)v7->tm_hour,
        (unsigned int)v7->tm_min,
        (unsigned int)v7->tm_sec);
      goto LABEL_5;
    case 'U':
      *(int *)a4 |= 1u;
      return v19 - __readfsqword(0x28u);
    case 'Y':
      __sprintf_chk(name, 1, 256, "%d", (unsigned int)(v7->tm_year + 1900));
      goto LABEL_5;
    case 'd':
      __sprintf_chk(name, 1, 256, "%02d", (unsigned int)v7->tm_mday);
      goto LABEL_5;
    case 'h':
      name[0] = 0;
      gethostname(name, 0x100u);
      name[255] = 0;
      goto LABEL_5;
    case 'm':
      __sprintf_chk(name, 1, 256, "%02d", (unsigned int)(v7->tm_mon + 1));
      goto LABEL_5;
    case 'p':
      v13 = getpid();
      goto LABEL_28;
    case 's':
      v13 = *(long long *)(a1 + 840);
LABEL_28:
      __sprintf_chk(name, 1, 256, "%lu", v13);
      goto LABEL_5;
    case 'u':
      v14 = getuid();
      getpwuid_r(v14, &resultbuf, name, 0x100u, &result);
      if ( result )
        sub_3CFA0(a3, result->pw_name, 0);
      return v19 - __readfsqword(0x28u);
    case 'y':
      __sprintf_chk(name, 1, 256, "%02d", (unsigned int)(v7->tm_year % 100));
      goto LABEL_5;
    default:
LABEL_5:
      sub_3CFA0(a3, name, 0);
      return v19 - __readfsqword(0x28u);
  }
}


// Function: expand_inode_expression @ 0x382d0
int expand_inode_expression(FILE *stream, long long a2, char a3, long long a4)
{
  unsigned short *v6; // rsi
  int result; // eax
  unsigned short v8; // bx
  const char *v9; // rsi
  short v10; // ax
  char *v11; // rax
  unsigned long long v12; // rcx
  long long v13; // rcx
  int v14; // eax
  char *v15; // rax

  if ( !a4 )
    return __fprintf_chk(stream, 1, "%%I%c", (unsigned int)a3);
  v6 = *(unsigned short **)(a4 + 24);
  if ( !v6 )
    return __fprintf_chk(stream, 1, "%%I%c", (unsigned int)a3);
  switch ( a3 )
  {
    case 'F':
      return __fprintf_chk(stream, 1, "%u", *((unsigned int *)v6 + 28));
    case 'M':
      return sub_37CD0((long long)stream, *((unsigned int *)v6 + 4));
    case 'S':
      return __fprintf_chk(stream, 1, "%u", v6[64]);
    case 'b':
      v14 = sub_382C0(*(unsigned int *)(*(long long *)(a2 + 32) + 100LL));
      v13 = *((unsigned int *)v6 + 7);
      if ( !v14 )
        return __fprintf_chk(stream, 1, "%u", v13);
      v12 = ((unsigned long long)v6[58] << 32) + v13;
      return __fprintf_chk(stream, 1, "%llu", v12);
    case 'd':
      v13 = 0;
      if ( (*v6 & 0xF000) == 0x4000 )
        v13 = *((unsigned int *)v6 + 27);
      return __fprintf_chk(stream, 1, "%u", v13);
    case 'f':
      v12 = ext2fs_file_acl_block(a2, v6);
      return __fprintf_chk(stream, 1, "%llu", v12);
    case 'g':
      return __fprintf_chk(stream, 1, "%d", v6[12] | (v6[61] << 16));
    case 'l':
      return __fprintf_chk(stream, 1, "%d", v6[13]);
    case 'm':
      return __fprintf_chk(stream, 1, "0%o", *v6);
    case 's':
      v12 = *((unsigned int *)v6 + 1) | ((unsigned long long)*((unsigned int *)v6 + 27) << 32);
      return __fprintf_chk(stream, 1, "%llu", v12);
    case 't':
      v8 = *v6;
      v9 = "regular file";
      v10 = v8 & 0xF000;
      if ( (v8 & 0xF000) == 0x8000 )
        goto LABEL_30;
      v9 = "directory";
      if ( v10 == 0x4000 )
        goto LABEL_30;
      v9 = "character device";
      if ( v10 == 0x2000 )
        goto LABEL_30;
      v9 = "block device";
      if ( v10 == 24576 )
        goto LABEL_30;
      v9 = "named pipe";
      if ( v10 == 4096 )
        goto LABEL_30;
      v9 = "symbolic link";
      if ( v10 == -24576 )
        goto LABEL_30;
      if ( v10 == -16384 )
      {
        v9 = "socket";
LABEL_30:
        v15 = dcgettext(0, v9, 5);
        result = fputs(v15, stream);
      }
      else
      {
        v11 = dcgettext(0, "unknown file type with mode 0%o", 5);
        result = __fprintf_chk(stream, 1, v11, v8);
      }
      break;
    case 'u':
      return __fprintf_chk(stream, 1, "%d", v6[1] | (v6[60] << 16));
    default:
      return __fprintf_chk(stream, 1, "%%I%c", (unsigned int)a3);
  }
  return result;
}


// Function: print_e2fsck_message @ 0x38530
long long print_e2fsck_message(FILE *stream, long long *a2, const char *a3, long long a4, int a5)
{
  long long result; // rax
  char v8; // al
  long long v9; // r13
  const char *v10; // r13
  const unsigned short **v11; // rax
  long long i; // rcx
  int v13; // edx
  char v14; // dl
  char v15; // dl
  int v16; // ecx
  long long v17; // [rsp+8h] [rbp-50h]
  int v18[15]; // [rsp+1Ch] [rbp-3Ch] BYREF

  v17 = *a2;
  v18[0] = a5;
  e2fsck_clear_progbar((long long)a2);
  for ( result = *(unsigned char *)a3; (char)result; v18[0] = 0 )
  {
    if ( (char)result == 64 )
    {
      v10 = a3 + 1;
      a3 += 2;
      sub_38700(stream);
    }
    else if ( (char)result == 37 )
    {
      v11 = __ctype_b_loc();
      v10 = a3 + 1;
      for ( i = 0; ; i = (unsigned int)(v13 + 10 * i - 48) )
      {
        v13 = *v10;
        a3 = v10 + 1;
        if ( ((*v11)[*v10] & 0x800) == 0 )
          break;
        ++v10;
      }
      if ( (char)v13 == 73 )
      {
        v15 = *++v10;
        ++a3;
        sub_382D0(stream, v17, v15, a4);
      }
      else if ( (char)v13 == 68 )
      {
        v14 = *++v10;
        ++a3;
        sub_37D10(stream, v17, v14, a4);
      }
      else
      {
        sub_37EB0(stream, v17, v13, i, v18, a4);
      }
    }
    else
    {
      v8 = *a3;
      v9 = 0;
      if ( *a3 )
      {
        while ( 1 )
        {
          v16 = v9;
          if ( v8 == 64 || v8 == 37 )
            break;
          v8 = a3[v9 + 1];
          v16 = v9 + 1;
          if ( !v8 )
            goto LABEL_10;
          ++v9;
        }
        --v9;
      }
      else
      {
        v9 = -1;
        v16 = 0;
      }
LABEL_10:
      v10 = &a3[v9];
      __fprintf_chk(stream, 1, "%.*s", v16, a3);
      a3 = v10 + 1;
    }
    result = *((unsigned char *)v10 + 1);
  }
  return result;
}


// Function: expand_at_expression @ 0x38700
long long expand_at_expression(FILE *stream, long long *a2, char a3, long long a4, int *a5, int a6)
{
  char *v7; // rsi
  char **v10; // rax
  char *v12; // rax
  int v13; // r8d
  char *v14; // r15
  const char *v15; // rdx
  const unsigned short **v16; // rax
  const int_t **v17; // rax
  int v18; // [rsp+0h] [rbp-48h]
  const char *v19; // [rsp+8h] [rbp-40h]

  v7 = off_B5F20[0];
  if ( !off_B5F20[0] )
    return __fprintf_chk(stream, 1, "@%c", (unsigned int)a3);
  v10 = off_B5F20;
  while ( *v7 != a3 )
  {
    v7 = v10[1];
    ++v10;
    if ( !v7 )
      return __fprintf_chk(stream, 1, "@%c", (unsigned int)a3);
  }
  if ( a6 > 9 )
    return __fprintf_chk(stream, 1, "@%c", (unsigned int)a3);
  v12 = dcgettext(0, v7, 5);
  v13 = *a5;
  v14 = v12;
  v15 = v12 + 1;
  if ( *a5 )
  {
    v19 = v12 + 1;
    v18 = *a5;
    v16 = __ctype_b_loc();
    v13 = v18;
    v15 = v19;
    if ( ((*v16)[v14[1]] & 0x200) != 0 )
    {
      *a5 = 0;
      v17 = __ctype_toupper_loc();
      fputc((*v17)[v14[1]], stream);
      v13 = *a5;
      v15 = v14 + 2;
    }
  }
  return print_e2fsck_message(stream, a2, v15, a4, v13);
}


// Function: move_quota_inode @ 0x38860
long long move_quota_inode(long long a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  long long bitmaps; // rax
  long long inode; // r12
  long long v8; // rax
  long long v9; // rdx
  unsigned int v11; // eax
  int v12; // r8d
  int v13; // r9d
  unsigned int v14; // eax
  int v15; // r8d
  int v16; // r9d
  unsigned int v17; // eax
  int v18; // r8d
  int v19; // r9d
  unsigned int v20; // eax
  int v21; // r8d
  int v22; // r9d
  int v23[32]; // [rsp+0h] [rbp-D8h] BYREF
  char v24[24]; // [rsp+80h] [rbp-58h] BYREF
  unsigned long long v25; // [rsp+98h] [rbp-40h]

  v25 = __readfsqword(0x28u);
  bitmaps = ext2fs_read_bitmaps(a1);
  if ( bitmaps )
  {
    inode = bitmaps;
    v11 = (unsigned int)dcgettext(0, "in move_quota_inode", 5);
    com_err((unsigned int)"ext2fs_read_bitmaps", inode, (unsigned int)"%s", v11, v12, v13);
  }
  else
  {
    inode = ext2fs_read_inode(a1, a2, v23);
    if ( inode )
    {
      v17 = (unsigned int)dcgettext(0, "in move_quota_inode", 5);
      com_err((unsigned int)"ext2fs_read_inode", inode, (unsigned int)"%s", v17, v18, v19);
    }
    else
    {
      HIWORD(v23[6]) = 1;
      v8 = *(long long *)(a1 + 32);
      LOWORD(v23[0]) = -32384;
      v23[8] = (unsigned int)sub_38850(*(unsigned int *)(v8 + 96), a3, v23) == 0 ? 16 : 524304;
      inode = ext2fs_write_new_inode(a1, a3, v9);
      if ( inode )
      {
        v14 = (unsigned int)dcgettext(0, "in move_quota_inode", 5);
        com_err((unsigned int)"ext2fs_write_new_inode", inode, (unsigned int)"%s", v14, v15, v16);
      }
      else
      {
        quota_get_qf_name(a4, 4, v24);
        inode = ext2fs_unlink(a1, 2, v24, a2, 0);
        if ( inode )
        {
          v20 = (unsigned int)dcgettext(0, "in move_quota_inode", 5);
          com_err((unsigned int)"ext2fs_unlink", inode, (unsigned int)"%s", v20, v21, v22);
        }
        else
        {
          ext2fs_inode_alloc_stats(a1, a2, 0xFFFFFFFFLL);
          memset(v23, 0, sizeof(v23));
          ext2fs_write_inode(a1, a2, v23);
        }
      }
    }
  }
  return inode;
}


// Function: e2fsck_hide_quota @ 0x38a90
unsigned long long e2fsck_hide_quota(long long a1)
{
  long long v1; // r13
  long long v2; // r14
  long long i; // rbx
  unsigned int *v4; // rax
  long long v5; // rsi
  unsigned int *v6; // rbp
  unsigned int v7; // r8d
  unsigned int v9; // [rsp+Ch] [rbp-ACh]
  char v10[8]; // [rsp+10h] [rbp-A8h] BYREF
  unsigned int v11; // [rsp+18h] [rbp-A0h]
  int v12; // [rsp+20h] [rbp-98h]
  long long v13; // [rsp+60h] [rbp-58h]
  unsigned long long v14; // [rsp+78h] [rbp-40h]

  v1 = *(long long *)a1;
  v14 = __readfsqword(0x28u);
  v2 = *(long long *)(v1 + 32);
  clear_problem_context((long long)v10);
  if ( (*(char *)(a1 + 76) & 1) == 0 && (unsigned int)sub_38A80(*(unsigned int *)(v2 + 100)) )
  {
    for ( i = 0; i != 3; ++i )
    {
      v12 = 2;
      v4 = (unsigned int *)sub_38820(v2, (unsigned int)i);
      v5 = *(long long *)(v1 + 32);
      v6 = v4;
      LODWORD(v4) = *v4;
      v13 = i;
      v11 = (unsigned int)v4;
      v7 = quota_type2inum((unsigned int)i, v5);
      if ( v11 != v7 )
      {
        if ( v11 )
        {
          v9 = v7;
          if ( (unsigned int)fix_problem(a1, 0x41u, (long long)v10) )
          {
            if ( !sub_38860(v1, v11, v9, i) )
            {
              *v6 = v9;
              ext2fs_mark_super_dirty(v1);
            }
          }
        }
      }
    }
  }
  return v14 - __readfsqword(0x28u);
}


// Function: e2fsck_validate_quota_inodes @ 0x38ba0
unsigned long long e2fsck_validate_quota_inodes(long long *a1)
{
  long long v1; // rbx
  long long v2; // r15
  long long v3; // r13
  unsigned int *v4; // rbp
  unsigned int v5; // eax
  int v7[20]; // [rsp+0h] [rbp-A8h] BYREF
  long long v8; // [rsp+50h] [rbp-58h]
  unsigned long long v9; // [rsp+68h] [rbp-40h]

  v1 = 0;
  v2 = *a1;
  v9 = __readfsqword(0x28u);
  v3 = *(long long *)(v2 + 32);
  clear_problem_context((long long)v7);
  do
  {
    v4 = (unsigned int *)sub_38820(v3, (unsigned int)v1);
    v5 = *v4;
    v8 = v1;
    v7[2] = v5;
    if ( v5 && (v5 - 1 <= 1 || v5 - 5 <= 5 || v5 > **(int **)(v2 + 32)) )
    {
      if ( (unsigned int)fix_problem((long long)a1, 0x4Fu, (long long)v7) )
      {
        *v4 = 0;
        ext2fs_mark_super_dirty(v2);
      }
    }
    ++v1;
  }
  while ( v1 != 3 );
  return v9 - __readfsqword(0x28u);
}


// Function: jbd2_descriptor_block_csum_verify @ 0x38c70
long long jbd2_descriptor_block_csum_verify(long long a1, long long a2)
{
  int has_csum_v2or3; // r8d
  long long result; // rax
  long long v5; // rsi
  int *v6; // rbx
  long long v7; // rcx
  int v8; // r13d
  unsigned int v9; // eax

  has_csum_v2or3 = jbd2_journal_has_csum_v2or3(a1);
  result = 1;
  if ( has_csum_v2or3 )
  {
    v5 = *(unsigned int *)(a1 + 196);
    v6 = (int *)(a2 + *(int *)(a1 + 120) - 4);
    v7 = *(int *)(a1 + 120);
    v8 = *v6;
    *v6 = 0;
    v9 = jbd2_chksum(a1, v5, a2, v7);
    *v6 = v8;
    return (unsigned int)ext2fs_swab32(v9) == v8;
  }
  return result;
}


// Function: read_tag_block @ 0x38ce0
long long read_tag_block(long long a1, unsigned int *a2)
{
  long long v2; // r12

  v2 = (unsigned int)ext2fs_swab32(*a2);
  if ( (unsigned int)jbd2_has_feature_64bit(a1) )
    return (ext2fs_swab32(a2[2]) << 32) | v2;
  return v2;
}


// Function: jbd2_commit_block_csum_verify @ 0x38d20
long long jbd2_commit_block_csum_verify(long long a1, long long a2)
{
  int has_csum_v2or3; // r8d
  long long result; // rax
  int v4; // r12d
  long long v5; // rcx
  unsigned int v6; // eax

  has_csum_v2or3 = jbd2_journal_has_csum_v2or3(a1);
  result = 1;
  if ( has_csum_v2or3 )
  {
    v4 = *(int *)(a2 + 16);
    v5 = *(unsigned int *)(a1 + 120);
    *(int *)(a2 + 16) = 0;
    v6 = jbd2_chksum(a1, *(unsigned int *)(a1 + 196), a2, v5);
    *(int *)(a2 + 16) = v4;
    return (unsigned int)ext2fs_swab32(v6) == v4;
  }
  return result;
}


// Function: jbd2_block_tag_csum_verify @ 0x38d80
long long jbd2_block_tag_csum_verify(long long a1, long long a2, long long a3, long long a4, unsigned int a5)
{
  int has_csum_v2or3; // r8d
  long long result; // rax
  int v11; // eax
  long long v12; // rsi
  long long v13; // rsi
  unsigned int v14; // r12d
  int v15; // [rsp+4h] [rbp-34h] BYREF
  unsigned long long v16; // [rsp+8h] [rbp-30h]

  v16 = __readfsqword(0x28u);
  has_csum_v2or3 = jbd2_journal_has_csum_v2or3(a1);
  result = 1;
  if ( has_csum_v2or3 )
  {
    v11 = ext2fs_swab32(a5);
    v12 = *(unsigned int *)(a1 + 196);
    v15 = v11;
    v13 = (unsigned int)jbd2_chksum(a1, v12, &v15, 4);
    v14 = jbd2_chksum(a1, v13, a4, *(unsigned int *)(a1 + 120));
    if ( (unsigned int)jbd2_has_feature_csum3(a1) )
      return *(int *)(a3 + 12) == (unsigned int)ext2fs_swab32(v14);
    else
      return *(short *)(a2 + 4) == (unsigned short)ext2fs_swab16((unsigned short)v14);
  }
  return result;
}


// Function: scan_revoke_records @ 0x38e60
long long scan_revoke_records(long long a1, long long a2, unsigned int a3, long long a4)
{
  int v6; // r13d
  unsigned int v7; // edx
  int v8; // ebx
  unsigned int i; // ebp
  long long v10; // rax
  long long result; // rax
  long long v12; // rax
  unsigned int *v13; // rax
  unsigned int v14; // eax
  unsigned int v15; // [rsp+4h] [rbp-44h]

  v15 = ext2fs_swab32(*(unsigned int *)(a2 + 52));
  if ( *(int *)(a1 + 120) - 4 * (unsigned int)((unsigned int)jbd2_journal_has_csum_v2or3(a1) != 0) < v15 )
    return 4294967274LL;
  v6 = 16;
  v7 = (unsigned int)jbd2_has_feature_64bit(a1) == 0 ? 0xFFFFFFFC : 0;
  v8 = v7 + 24;
  for ( i = v7 + 8; v8 <= (int)v15; v8 += i )
  {
    v12 = v6;
    v6 = v8;
    v13 = (unsigned int *)(a2 + 40 + v12);
    if ( i == 4 )
    {
      v14 = ext2fs_swab32(*v13);
      result = jbd2_journal_set_revoke(a1, v14, a3);
      if ( (int)result )
        return result;
    }
    else
    {
      v10 = ext2fs_swab64(*(long long *)v13);
      result = jbd2_journal_set_revoke(a1, v10, a3);
      if ( (int)result )
        return result;
    }
    ++*(int *)(a4 + 12);
  }
  return 0;
}


// Function: jread @ 0x38f60
long long jread(long long *a1, long long a2, unsigned int a3)
{
  unsigned int v4; // r13d
  long long v5; // rax
  long long v6; // rbp
  long long v8[7]; // [rsp+0h] [rbp-38h] BYREF

  v8[1] = __readfsqword(0x28u);
  *a1 = 0;
  if ( *(int *)(a2 + 128) <= a3 )
  {
    v4 = -2133571502;
    __printf_chk(1, "JBD2: corrupted journal superblock\n");
  }
  else
  {
    v4 = jbd2_journal_bmap(a2, a3, v8);
    if ( v4 )
    {
      __printf_chk(1, "JBD2: bad block at offset %u\n", a3);
    }
    else
    {
      v5 = getblk(*(int **)(a2 + 104), v8[0], *(int *)(a2 + 120));
      v6 = v5;
      if ( v5 )
      {
        if ( !buffer_uptodate(v5) )
          wait_on_buffer(v6);
        if ( buffer_uptodate(v6) )
        {
          *a1 = v6;
        }
        else
        {
          v4 = -5;
          __printf_chk(1, "JBD2: Failed to read block at offset %u\n", a3);
          brelse(v6);
        }
      }
      else
      {
        return (unsigned int)-12;
      }
    }
  }
  return v4;
}


// Function: count_tags @ 0x39090
long long count_tags(long long a1, long long a2)
{
  long long *v2; // r15
  int v3; // ebp
  int v4; // r13d
  unsigned int v5; // r12d
  long long v7; // [rsp+1Ch] [rbp-4Ch]

  v2 = (long long *)(a2 + 52);
  v3 = *(int *)(a1 + 120);
  v4 = journal_tag_bytes();
  if ( (unsigned int)jbd2_journal_has_csum_v2or3(a1) )
    v3 -= 4;
  v5 = 0;
  do
  {
    if ( (long long)v2 + v4 - a2 - 40 > v3 )
      break;
    ++v5;
    v7 = *v2;
    v2 = (long long *)((char *)v2 + v4);
    if ( ((unsigned short)ext2fs_swab16(2) & HIWORD(v7)) == 0 )
      v2 += 2;
  }
  while ( ((unsigned short)ext2fs_swab16(8) & HIWORD(v7)) == 0 );
  return v5;
}


// Function: calc_chksums @ 0x39170
long long calc_chksums(long long *a1, long long a2, unsigned long long *a3, int *a4)
{
  int v7; // ebp
  unsigned long long v8; // rax
  int v9; // eax
  int v10; // eax
  long long v11; // rdi
  unsigned long long v12; // r12
  unsigned long long v13; // r15
  int v15; // [rsp+Ch] [rbp-4Ch]
  long long v16[9]; // [rsp+10h] [rbp-48h] BYREF

  v16[1] = __readfsqword(0x28u);
  v15 = sub_39090((long long)a1, a2);
  *a4 = ext2fs_crc32_be((unsigned int)*a4, a2 + 40, *(int *)(a2 + 16));
  if ( v15 <= 0 )
    return 0;
  v7 = 0;
  while ( 1 )
  {
    v12 = *a3;
    v13 = *a3 + 1;
    *a3 = v13;
    v8 = (unsigned int)jbd2_has_feature_fast_commit(a1) ? a1[9] : a1[12];
    if ( v13 >= v8 )
      *a3 = v13 + a1[11] - v8;
    v9 = sub_38F60(v16, (long long)a1, v12);
    if ( v9 )
      break;
    ++v7;
    v10 = ext2fs_crc32_be((unsigned int)*a4, v16[0] + 40, *(int *)(v16[0] + 16));
    v11 = v16[0];
    *a4 = v10;
    brelse(v11);
    if ( v15 == v7 )
      return 0;
  }
  __printf_chk(1, "JBD2: IO error %d recovering block %lu in log\n", v9, v12);
  return 1;
}


// Function: do_one_pass @ 0x39340
long long do_one_pass(long long a1, unsigned int *a2, unsigned int a3)
{
  int v5; // eax
  long long v6; // rbx
  unsigned int v7; // r15d
  long long v8; // rbp
  unsigned int v9; // ebx
  unsigned long long v10; // rbx
  unsigned int v11; // eax
  unsigned long long v12; // rbx
  unsigned long long v13; // rax
  long long v14; // r14
  int v15; // ebx
  long long v16; // rax
  long long v17; // rbp
  long long v18; // r14
  int v20; // eax
  unsigned long long v21; // rbx
  unsigned long long v22; // rax
  unsigned long long v23; // rbx
  int v24; // eax
  int v25; // edx
  short v26; // dx
  long long v27; // rdi
  int v28; // eax
  char v29; // cl
  int v30; // eax
  long long v31; // rdi
  long long v32; // r14
  char v33; // al
  unsigned long long v34; // r13
  char v35; // bl
  unsigned long long v36; // rax
  unsigned int v37; // eax
  long long v38; // r13
  unsigned int v39; // eax
  long long v40; // rax
  long long v41; // rbp
  long long v42; // rdi
  long long v43; // rax
  unsigned int v44; // [rsp+8h] [rbp-C0h]
  char v45; // [rsp+Fh] [rbp-B9h]
  unsigned long long v46; // [rsp+10h] [rbp-B8h]
  int v47; // [rsp+18h] [rbp-B0h]
  int v48; // [rsp+1Ch] [rbp-ACh]
  unsigned int v49; // [rsp+20h] [rbp-A8h]
  long long v50; // [rsp+28h] [rbp-A0h]
  long long v51; // [rsp+30h] [rbp-98h]
  long long v52; // [rsp+38h] [rbp-90h]
  unsigned long long v53; // [rsp+40h] [rbp-88h]
  int v54; // [rsp+48h] [rbp-80h]
  int v55; // [rsp+5Ch] [rbp-6Ch] BYREF
  unsigned long long v56; // [rsp+60h] [rbp-68h] BYREF
  long long v57; // [rsp+68h] [rbp-60h] BYREF
  long long v58; // [rsp+70h] [rbp-58h] BYREF
  long long v59; // [rsp+7Ch] [rbp-4Ch] BYREF
  int v60; // [rsp+84h] [rbp-44h]
  unsigned long long v61; // [rsp+88h] [rbp-40h]

  v61 = __readfsqword(0x28u);
  v5 = journal_tag_bytes();
  v6 = *(long long *)(a1 + 24);
  v55 = -1;
  v54 = v5;
  v7 = ext2fs_swab32(*(unsigned int *)(v6 + 24));
  v56 = (unsigned int)ext2fs_swab32(*(unsigned int *)(v6 + 28));
  if ( !a3 )
    *a2 = v7;
  v46 = 0;
  v8 = (long long)a2;
  v45 = 0;
  v48 = 0;
  v47 = 0;
  v44 = 0;
LABEL_4:
  if ( !a3 )
    goto LABEL_6;
LABEL_5:
  v9 = *(int *)(v8 + 4);
  if ( !(unsigned int)tid_geq(v7, v9) )
  {
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_6:
        v10 = v56;
        v11 = sub_38F60(&v57, a1, v56);
        if ( v11 )
          return v11;
        v12 = v10 + 1;
        v56 = v12;
        if ( (unsigned int)jbd2_has_feature_fast_commit(a1) )
          v13 = *(long long *)(a1 + 72);
        else
          v13 = *(long long *)(a1 + 96);
        if ( v12 >= v13 )
          v56 = *(long long *)(a1 + 88) + v12 - v13;
        v14 = v57;
        if ( *(int *)(v14 + 40) != (unsigned int)ext2fs_swab32(3225106840LL)
          || (v15 = ext2fs_swab32(*(unsigned int *)(v14 + 44)),
              v7 != (unsigned int)ext2fs_swab32(*(unsigned int *)(v14 + 48))) )
        {
          v31 = v14;
          v18 = v8;
          brelse(v31);
          v9 = *(int *)(v8 + 4);
          goto LABEL_18;
        }
        if ( v15 == 2 )
          break;
        if ( v15 == 5 )
        {
          if ( !a3 )
          {
            v28 = sub_38C70(a1, v14 + 40);
            v29 = v45;
            if ( !v28 )
              v29 = 1;
            v45 = v29;
            goto LABEL_37;
          }
          if ( a3 != 1 )
            goto LABEL_37;
          v49 = sub_38E60(a1, v14, v7, v8);
          brelse(v14);
          v11 = v49;
          if ( v49 )
            return v11;
          goto LABEL_5;
        }
        if ( v15 != 1 )
          goto LABEL_16;
        if ( (unsigned int)jbd2_journal_has_csum_v2or3(a1) )
        {
          v47 = 4;
          if ( !sub_38C70(a1, v14 + 40) )
            goto LABEL_31;
        }
        else if ( v47 && !sub_38C70(a1, v14 + 40) )
        {
LABEL_31:
          if ( a3 )
          {
            brelse(v14);
            return (unsigned int)-2133571503;
          }
          v45 = 1;
LABEL_33:
          v20 = sub_39090(a1, v14);
          v21 = v56 + v20;
          v56 = v21;
          if ( (unsigned int)jbd2_has_feature_fast_commit(a1) )
            v22 = *(long long *)(a1 + 72);
          else
            v22 = *(long long *)(a1 + 96);
          if ( v21 >= v22 )
            v56 = *(long long *)(a1 + 88) + v21 - v22;
LABEL_37:
          brelse(v14);
          goto LABEL_4;
        }
        if ( a3 == 2 )
        {
          v51 = v8;
          v50 = v14 + 40;
          v52 = v14;
          v32 = v14 + 52;
          while ( 1 )
          {
            if ( v54 + v32 - v50 > *(int *)(a1 + 120) - v47 )
            {
LABEL_96:
              v8 = v51;
              a3 = 2;
              brelse(v52);
              goto LABEL_5;
            }
            v59 = *(long long *)v32;
            v60 = *(int *)(v32 + 8);
            v33 = ext2fs_swab16(HIWORD(v59));
            v34 = v56;
            v35 = v33;
            v53 = ++v56;
            if ( (unsigned int)jbd2_has_feature_fast_commit(a1) )
              v36 = *(long long *)(a1 + 72);
            else
              v36 = *(long long *)(a1 + 96);
            if ( v53 >= v36 )
              v56 = *(long long *)(a1 + 88) + v53 - v36;
            v37 = sub_38F60(&v58, a1, v34);
            if ( v37 )
            {
              v44 = v37;
              __printf_chk(1, "JBD2: IO error %d recovering block %ld in log\n", v37, v34);
            }
            else
            {
              if ( !v58 )
              {
                __printf_chk(
                  1,
                  "Assertion failure in %s() at %s line %d: \"%s\"\n",
                  "do_one_pass",
                  "recovery.c",
                  633,
                  "obh != NULL");
                fatal_error((long long *)e2fsck_global_ctx, 0);
              }
              v38 = sub_38CE0(a1, (unsigned int *)&v59);
              if ( (unsigned int)jbd2_journal_test_revoke(a1, v38, v7) )
              {
                brelse(v58);
                ++*(int *)(v51 + 16);
              }
              else
              {
                v39 = ext2fs_swab32(*(unsigned int *)(v52 + 48));
                if ( (unsigned int)sub_38D80(a1, (long long)&v59, v32, v58 + 40, v39) )
                {
                  v40 = getblk(*(int **)(a1 + 112), v38, *(int *)(a1 + 120));
                  v41 = v40;
                  if ( !v40 )
                  {
                    __printf_chk(1, "JBD2: Out of memory during recovery.\n");
                    brelse(v52);
                    brelse(v58);
                    return (unsigned int)-12;
                  }
                  memcpy((void *)(v40 + 40), (const void *)(v58 + 40), *(int *)(a1 + 120));
                  if ( (v35 & 1) != 0 )
                    *(int *)(v41 + 40) = ext2fs_swab32(3225106840LL);
                  mark_buffer_uptodate(v41, 1);
                  mark_buffer_dirty(v41);
                  v42 = v58;
                  ++*(int *)(v51 + 8);
                  brelse(v42);
                  brelse(v41);
                }
                else
                {
                  brelse(v58);
                  __printf_chk(1, "JBD2: Invalid checksum recovering data block %llu in log\n", v38);
                  v48 = 1;
                  v44 = -2133571503;
                }
              }
            }
            v32 += v54;
            if ( (v35 & 2) == 0 )
              v32 += 16;
            if ( (v35 & 8) != 0 )
              goto LABEL_96;
          }
        }
        if ( a3 || (unsigned char)v45 | ((unsigned int)jbd2_has_feature_checksum(a1) == 0) )
          goto LABEL_33;
        if ( *(int *)(v8 + 4) )
        {
          v45 = 0;
          goto LABEL_33;
        }
        v27 = v14;
        if ( (unsigned int)sub_39170((long long *)a1, v14, &v56, &v55) )
          goto LABEL_67;
        brelse(v14);
        v45 = 0;
      }
      v23 = ext2fs_swab64(*(long long *)(v14 + 88));
      if ( v45 )
      {
        v43 = v8;
        v17 = v14;
        v18 = v43;
        if ( v46 <= v23 )
        {
          brelse(v17);
          return (unsigned int)-2133571503;
        }
        goto LABEL_17;
      }
      if ( a3 )
        goto LABEL_60;
      if ( !(unsigned int)jbd2_has_feature_checksum(a1) )
        goto LABEL_50;
      v24 = ext2fs_swab32(*(unsigned int *)(v14 + 56));
      v25 = *(int *)(v8 + 4);
      if ( v25 )
      {
        *(int *)(a1 + 192) = v25;
        v27 = v14;
LABEL_67:
        brelse(v27);
        goto LABEL_68;
      }
      v26 = *(short *)(v14 + 52);
      if ( v55 == v24 && v26 == 1025 )
        break;
      if ( !v26 && !v24 )
        break;
LABEL_51:
      if ( v46 > v23 )
      {
LABEL_16:
        v16 = v8;
        v17 = v14;
        v18 = v16;
LABEL_17:
        brelse(v17);
        v9 = *(int *)(v18 + 4);
        goto LABEL_18;
      }
      *(int *)(v8 + 4) = v7;
      if ( (unsigned int)jbd2_has_feature_async_commit(a1) )
      {
LABEL_59:
        v46 = v23;
LABEL_60:
        ++v7;
        brelse(v14);
        goto LABEL_4;
      }
      *(int *)(a1 + 192) = v7;
      brelse(v14);
LABEL_68:
      v45 = 0;
    }
    v55 = -1;
LABEL_50:
    if ( sub_38D20(a1, v14 + 40) )
      goto LABEL_59;
    goto LABEL_51;
  }
  v18 = v8;
LABEL_18:
  if ( a3 )
  {
    if ( v7 == v9 )
    {
      if ( !(unsigned int)jbd2_has_feature_fast_commit(a1) || a3 == 1 )
        goto LABEL_22;
    }
    else
    {
      __printf_chk(1, "JBD2: recovery pass %d ended at transaction %u, expected %u\n", a3, v7, v9);
      v30 = -5;
      if ( v44 )
        v30 = v44;
      v44 = v30;
      if ( !(unsigned int)jbd2_has_feature_fast_commit(a1) || a3 == 1 )
        return v44;
    }
  }
  else
  {
    if ( !v9 )
      *(int *)(v18 + 4) = v7;
    if ( !(unsigned int)jbd2_has_feature_fast_commit(a1) )
      goto LABEL_22;
  }
  v11 = sub_392A0(a1, *(unsigned int *)(v18 + 4), a3);
  if ( v11 )
    return v11;
LABEL_22:
  if ( !v44 )
  {
    v11 = -5;
    if ( !v48 )
      return 0;
    return v11;
  }
  return v44;
}


// Function: jbd2_journal_recover @ 0x39b80
long long jbd2_journal_recover(long long a1)
{
  long long v1; // rax
  unsigned int v2; // r12d
  long long v4; // rdx
  long long v5; // rcx
  long long v6; // r8
  long long v7; // r9
  long long v8; // rdx
  long long v9; // rcx
  long long v10; // r8
  long long v11; // r9
  unsigned int v12; // eax
  __int128 v13; // [rsp+0h] [rbp-38h] BYREF
  int v14; // [rsp+10h] [rbp-28h]
  unsigned long long v15; // [rsp+18h] [rbp-20h]

  v15 = __readfsqword(0x28u);
  v1 = *(long long *)(a1 + 24);
  v14 = 0;
  v13 = 0;
  if ( *(int *)(v1 + 28) )
  {
    v2 = sub_39340(a1, (unsigned int *)&v13, 0);
    if ( v2 || (v2 = sub_39340(a1, (unsigned int *)&v13, 1u)) != 0 )
    {
      *(int *)(a1 + 148) = DWORD1(v13) + 1;
      jbd2_journal_clear_revoke(a1, &v13, v4, v5, v6, v7, v13, *((long long *)&v13 + 1), v14, v15);
      sync_blockdev(*(long long *)(a1 + 112));
    }
    else
    {
      v2 = sub_39340(a1, (unsigned int *)&v13, 2u);
      *(int *)(a1 + 148) = DWORD1(v13) + 1;
      jbd2_journal_clear_revoke(a1, &v13, v8, v9, v10, v11, v13, *((long long *)&v13 + 1), v14, v15);
      v12 = sync_blockdev(*(long long *)(a1 + 112));
      if ( !v2 )
        return v12;
    }
  }
  else
  {
    v2 = 0;
    *(int *)(a1 + 148) = ext2fs_swab32(*(unsigned int *)(v1 + 24)) + 1;
  }
  return v2;
}


// Function: jbd2_journal_skip_recovery @ 0x39c90
long long jbd2_journal_skip_recovery(long long a1)
{
  int v1; // eax
  unsigned int v2; // r12d
  int v3; // eax
  __int128 v5; // [rsp+0h] [rbp-38h] BYREF
  int v6; // [rsp+10h] [rbp-28h]
  unsigned long long v7; // [rsp+18h] [rbp-20h]

  v7 = __readfsqword(0x28u);
  v6 = 0;
  v5 = 0;
  v1 = sub_39340(a1, (unsigned int *)&v5, 0);
  v2 = v1;
  if ( v1 )
  {
    __printf_chk(1, "JBD2: error %d scanning journal\n", v1);
    v3 = *(int *)(a1 + 148) + 1;
  }
  else
  {
    v3 = DWORD1(v5) + 1;
  }
  *(int *)(a1 + 148) = v3;
  *(long long *)(a1 + 48) = 0;
  return v2;
}


// Function: region_create @ 0x39d30
long long *region_create(long long a1, long long a2)
{
  long long *v3; // [rsp+0h] [rbp-28h]

  if ( ext2fs_get_memzero(0x20u) )
    return 0;
  *v3 = a1;
  v3[1] = a2;
  v3[3] = 0;
  return v3;
}


// Function: region_free @ 0x39da0
unsigned long long region_free(long long a1)
{
  long long v1; // rbx
  _OWORD *v2; // rax
  _OWORD *v4; // [rsp+8h] [rbp-30h] BYREF
  long long v5; // [rsp+10h] [rbp-28h] BYREF
  unsigned long long v6; // [rsp+18h] [rbp-20h]

  v1 = *(long long *)(a1 + 16);
  v4 = (_OWORD *)a1;
  v6 = __readfsqword(0x28u);
  v5 = v1;
  if ( v1 )
  {
    do
    {
      v1 = *(long long *)(v1 + 16);
      ext2fs_free_mem(&v5);
      v5 = v1;
    }
    while ( v1 );
    v2 = v4;
  }
  else
  {
    v2 = (_OWORD *)a1;
  }
  *v2 = 0;
  v2[1] = 0;
  ext2fs_free_mem(&v4);
  return v6 - __readfsqword(0x28u);
}


// Function: region_allocate @ 0x39e30
long long region_allocate(unsigned long long *a1, unsigned long long a2, int a3)
{
  unsigned long long v3; // r12
  unsigned long long *v4; // rbp
  unsigned long long *v5; // r14
  unsigned long long v6; // rax
  unsigned long long v7; // rdx
  long long result; // rax
  unsigned long long v9; // rax
  unsigned long long *v10; // rax
  unsigned long long v11; // rdx
  unsigned long long v12; // rax
  long long v13[7]; // [rsp+0h] [rbp-38h] BYREF

  v13[1] = __readfsqword(0x28u);
  if ( *a1 > a2 )
    return 0xFFFFFFFFLL;
  v3 = a2 + a3;
  if ( a1[1] < v3 )
    return 0xFFFFFFFFLL;
  if ( !a3 )
    return 1;
  v4 = (unsigned long long *)a1[3];
  if ( v4 )
  {
    if ( v4[1] == a2 )
    {
      if ( !v4[2] )
      {
LABEL_29:
        v4[1] = v3;
        return 0;
      }
    }
    else if ( v4[1] < a2 && !v4[2] )
    {
      goto LABEL_22;
    }
  }
  v4 = (unsigned long long *)a1[2];
  if ( v4 )
  {
    v5 = 0;
    while ( 1 )
    {
      v6 = *v4;
      v7 = v4[1];
      if ( *v4 > a2 )
        break;
      if ( a2 < v7 )
        return 1;
      if ( v6 >= v3 )
      {
        if ( v6 != a2 )
          goto LABEL_14;
        goto LABEL_26;
      }
      if ( v3 <= v7 || v6 >= a2 )
        return 1;
LABEL_14:
      if ( v6 == v3 )
      {
        *v4 = a2;
        return 0;
      }
      if ( a2 == v7 )
      {
        v10 = (unsigned long long *)v4[2];
        v13[0] = v10;
        if ( !v10 )
          goto LABEL_29;
        if ( *v10 < v3 )
          return 1;
        if ( *v10 != v3 )
          goto LABEL_29;
        v11 = v10[1];
        v12 = v10[2];
        v4[1] = v11;
        v4[2] = v12;
        ext2fs_free_mem(v13);
        result = 0;
        if ( !v4[2] )
          a1[3] = (unsigned long long)v4;
        return result;
      }
      if ( v6 > a2 )
      {
        if ( ext2fs_get_mem(24, v13) )
          return 0xFFFFFFFFLL;
        v9 = v13[0];
        *(long long *)v13[0] = a2;
        *(long long *)(v9 + 8) = v3;
        *(long long *)(v9 + 16) = v4;
        goto LABEL_31;
      }
      v5 = v4;
      if ( !v4[2] )
        goto LABEL_22;
      v4 = (unsigned long long *)v4[2];
    }
    if ( v6 < v3 )
      return 1;
LABEL_26:
    if ( v3 >= v7 )
      return 1;
    goto LABEL_14;
  }
LABEL_22:
  if ( ext2fs_get_mem(24, v13) )
    return 0xFFFFFFFFLL;
  v9 = v13[0];
  v5 = v4;
  *(long long *)v13[0] = a2;
  *(long long *)(v9 + 8) = v3;
  *(long long *)(v9 + 16) = 0;
  a1[3] = v9;
LABEL_31:
  if ( v5 )
    v5[2] = v9;
  else
    a1[2] = v9;
  return 0;
}


// Function: jbd2_journal_destroy_revoke_table @ 0x3a090
void jbd2_journal_destroy_revoke_table(long long *ptr)
{
  char *v1; // r8
  long long v2; // rbx

  v1 = (char *)ptr[1];
  if ( *(int *)ptr > 0 )
  {
    v2 = 0;
    do
    {
      if ( !(unsigned int)sub_3A080(&v1[16 * v2]) )
      {
        __printf_chk(
          1,
          "Assertion failure in %s() at %s line %d: \"%s\"\n",
          "jbd2_journal_destroy_revoke_table",
          "revoke.c",
          255,
          "list_empty(hash_list)");
        fatal_error((long long *)e2fsck_global_ctx, 0);
      }
      ++v2;
    }
    while ( *(int *)ptr > (int)v2 );
  }
  free(v1);
  free(ptr);
}


// Function: jbd2_journal_init_revoke_table @ 0x3a130
int *jbd2_journal_init_revoke_table(int a1)
{
  int *v1; // r12
  int v2; // edx
  int i; // eax
  long long *v4; // rax
  long long *v5; // rdx
  void *v7; // rdi

  v1 = malloc(*(int *)qword_B7380);
  if ( v1 )
  {
    v2 = 0;
    for ( i = a1 >> 1; i; i >>= 1 )
      ++v2;
    v1[1] = v2;
    *v1 = a1;
    v4 = (long long *)kmalloc_array((unsigned int)a1, 16, 0);
    *((long long *)v1 + 1) = v4;
    if ( v4 )
    {
      if ( a1 > 0 )
      {
        v5 = &v4[2 * (unsigned int)(a1 - 1) + 2];
        do
        {
          *v4 = v4;
          v4[1] = v4;
          v4 += 2;
        }
        while ( v4 != v5 );
      }
    }
    else
    {
      v7 = v1;
      v1 = 0;
      free(v7);
    }
  }
  return v1;
}


// Function: insert_revoke_hash @ 0x3a240
long long insert_revoke_hash(long long a1, long long a2, int a3)
{
  int *v4; // rax
  long long v5; // rbx
  int *v6; // rbp
  int v7; // eax

  v4 = malloc(*(int *)qword_B7388);
  if ( !v4 )
    return 4294967284LL;
  v5 = *(long long *)(a1 + 168);
  v4[4] = a3;
  v6 = v4;
  *((long long *)v4 + 3) = a2;
  v7 = sub_3A1D0(v5, a2);
  return sub_3A060(v6, *(long long *)(v5 + 8) + 16LL * v7);
}


// Function: jbd2_journal_destroy_revoke_record_cache @ 0x3a2c0
void jbd2_journal_destroy_revoke_record_cache()
{
  do_cache_destroy(qword_B7388);
  qword_B7388 = 0;
}


// Function: jbd2_journal_destroy_revoke_table_cache @ 0x3a2f0
void jbd2_journal_destroy_revoke_table_cache()
{
  do_cache_destroy(qword_B7380);
  qword_B7380 = 0;
}


// Function: jbd2_journal_init_revoke_record_cache @ 0x3a320
long long jbd2_journal_init_revoke_record_cache()
{
  if ( qword_B7388 )
  {
    __printf_chk(
      1,
      "Assertion failure in %s() at %s line %d: \"%s\"\n",
      "jbd2_journal_init_revoke_record_cache",
      "revoke.c",
      195,
      "!jbd2_revoke_record_cache");
    fatal_error((long long *)e2fsck_global_ctx, 0);
  }
  qword_B7388 = (void *)do_cache_create(32);
  return qword_B7388 == 0 ? 0xFFFFFFF4 : 0;
}


// Function: jbd2_journal_init_revoke_table_cache @ 0x3a390
long long jbd2_journal_init_revoke_table_cache()
{
  if ( qword_B7380 )
  {
    __printf_chk(
      1,
      "Assertion failure in %s() at %s line %d: \"%s\"\n",
      "jbd2_journal_init_revoke_table_cache",
      "revoke.c",
      208,
      "!jbd2_revoke_table_cache");
    fatal_error((long long *)e2fsck_global_ctx, 0);
  }
  qword_B7380 = (void *)do_cache_create(16);
  return qword_B7380 == 0 ? 0xFFFFFFF4 : 0;
}


// Function: jbd2_journal_init_revoke @ 0x3a400
long long jbd2_journal_init_revoke(long long *a1, int a2)
{
  int *v2; // rax
  int *v3; // rax

  if ( a1[22] )
  {
    __printf_chk(
      1,
      "Assertion failure in %s() at %s line %d: \"%s\"\n",
      "jbd2_journal_init_revoke",
      "revoke.c",
      265,
      "journal->j_revoke_table[0] == NULL");
    fatal_error((long long *)e2fsck_global_ctx, 0);
  }
  if ( !a2 || (a2 & (a2 - 1)) != 0 )
  {
    __printf_chk(
      1,
      "Assertion failure in %s() at %s line %d: \"%s\"\n",
      "jbd2_journal_init_revoke",
      "revoke.c",
      266,
      "is_power_of_2(hash_size)");
    fatal_error((long long *)e2fsck_global_ctx, 0);
  }
  v2 = sub_3A130(a2);
  a1[22] = v2;
  if ( !v2 )
    return 4294967284LL;
  v3 = sub_3A130(a2);
  a1[23] = v3;
  if ( v3 )
  {
    a1[21] = v3;
    return 0;
  }
  else
  {
    sub_3A090((long long *)a1[22]);
    a1[22] = 0;
    return 4294967284LL;
  }
}


// Function: jbd2_journal_destroy_revoke @ 0x3a510
void jbd2_journal_destroy_revoke(long long *a1)
{
  long long *v2; // rdi
  long long *v3; // rdi

  a1[21] = 0;
  v2 = (long long *)a1[22];
  if ( v2 )
    sub_3A090(v2);
  v3 = (long long *)a1[23];
  if ( v3 )
    sub_3A090(v3);
}


// Function: jbd2_journal_set_revoke @ 0x3a560
long long jbd2_journal_set_revoke(long long a1, long long a2, unsigned int a3)
{
  long long v4; // rax
  long long v5; // rbx

  v4 = sub_3A1E0(*(long long *)(a1 + 168));
  if ( !v4 )
    return sub_3A240(a1, a2, a3);
  v5 = v4;
  if ( (unsigned int)tid_gt(a3, *(unsigned int *)(v4 + 16)) )
    *(int *)(v5 + 16) = a3;
  return 0;
}


// Function: jbd2_journal_test_revoke @ 0x3a5d0
long long jbd2_journal_test_revoke(long long a1, long long a2, unsigned int a3)
{
  long long v4; // rax

  v4 = sub_3A1E0(*(long long *)(a1 + 168));
  return v4 && (unsigned int)tid_gt(a3, *(unsigned int *)(v4 + 16)) == 0;
}


// Function: jbd2_journal_clear_revoke @ 0x3a610
long long jbd2_journal_clear_revoke(long long a1)
{
  unsigned int *v1; // r12
  long long result; // rax
  long long v3; // rbp
  long long **v4; // rbx
  void *v5; // r9

  v1 = *(unsigned int **)(a1 + 168);
  result = *v1;
  if ( (int)result > 0 )
  {
    v3 = 0;
    do
    {
      v4 = (long long **)(*((long long *)v1 + 1) + 16 * v3);
      while ( 1 )
      {
        result = sub_3A080(v4);
        if ( (int)result )
          break;
        sub_3A2B0(**v4, (*v4)[1]);
        free(v5);
      }
      ++v3;
    }
    while ( (int)*v1 > (int)v3 );
  }
  return result;
}


// Function: refcount_collapse @ 0x3a680
void refcount_collapse(unsigned long long *a1)
{
  unsigned long long v1; // rsi
  unsigned long long v2; // r8
  unsigned int v3; // ecx
  unsigned int v4; // edx
  long long v5; // rax
  const __m128i *v6; // rax

  v1 = *a1;
  v2 = a1[3];
  if ( *a1 )
  {
    v3 = 0;
    v4 = 0;
    v5 = 0;
    do
    {
      v6 = (const __m128i *)(v2 + 16 * v5);
      if ( v6->m128i_i64[1] )
      {
        if ( v4 != v3 )
          *(__m128i *)(v2 + 16LL * v3) = _mm_loadu_si128(v6);
        ++v3;
      }
      v5 = ++v4;
    }
    while ( v4 < v1 );
    v1 = v3;
  }
  *a1 = v1;
}


// Function: insert_refcount_el @ 0x3a6d0
long long *insert_refcount_el(unsigned long long *a1, long long a2, int a3)
{
  unsigned long long v4; // rcx
  unsigned long long v5; // rax
  int v6; // edx
  long long v7; // rbx
  unsigned long long v8; // rax
  long long *result; // rax
  unsigned long long v10; // r13

  v4 = *a1;
  v5 = a1[1];
  if ( *a1 < v5 )
  {
    v6 = v4 - a3;
    if ( (int)v4 - a3 >= 0 )
      goto LABEL_3;
    return 0;
  }
  v10 = v5 + 100;
  if ( ext2fs_resize_mem(16 * (v5 + 100) - 1600, 16 * (v5 + 100), a1 + 3) )
    return 0;
  v4 = *a1;
  a1[1] = v10;
  v6 = v4 - a3;
  if ( (int)v4 - a3 < 0 )
    return 0;
LABEL_3:
  v7 = 16LL * a3;
  if ( v6 )
  {
    memmove((void *)(a1[3] + v7 + 16), (const void *)(a1[3] + v7), 16LL * v6);
    v4 = *a1;
  }
  v8 = a1[3];
  *a1 = v4 + 1;
  result = (long long *)(v7 + v8);
  *result = a2;
  result[1] = 0;
  return result;
}


// Function: get_refcount_el @ 0x3a7a0
unsigned long long *get_refcount_el(unsigned long long *a1, unsigned long long a2, int a3)
{
  unsigned long long *v3; // rbx
  unsigned long long v4; // r11
  unsigned long long v5; // rsi
  int v7; // edx
  int v8; // ecx
  unsigned long long v9; // rdx
  unsigned long long *result; // rax
  int v11; // r10d
  int v12; // edx
  unsigned long long v13; // r12

  if ( !a1 )
    return 0;
  v3 = (unsigned long long *)a1[3];
  if ( !v3 )
    return 0;
  v4 = a2;
  v5 = *a1;
  while ( 1 )
  {
    v7 = v5;
    v8 = v5 - 1;
    if ( a3 )
    {
      if ( !v5 )
      {
        v7 = 0;
LABEL_27:
        if ( v5 >= a1[1] )
        {
          sub_3A680(a1);
          v7 = *(int *)a1;
        }
        return sub_3A6D0(a1, v4, v7);
      }
      if ( v3[2 * v8] < v4 )
        goto LABEL_27;
    }
    else if ( !v5 )
    {
      return 0;
    }
    v9 = a1[2];
    if ( v9 >= v5 )
    {
      a1[2] = 0;
      result = v3;
      v9 = 0;
    }
    else
    {
      result = &v3[2 * v9];
    }
    if ( *result == v4 )
    {
      a1[2] = v9 + 1;
      return result;
    }
    v11 = 0;
    if ( v8 >= 0 )
      break;
LABEL_16:
    if ( !a3 )
      return 0;
    v13 = a1[1];
    if ( v13 <= v5 )
    {
      sub_3A680(a1);
      v5 = *a1;
      if ( v13 > *a1 )
        continue;
    }
    v7 = v11;
    return sub_3A6D0(a1, v4, v7);
  }
  while ( 1 )
  {
    v12 = (v11 + v8) >> 1;
    result = &v3[2 * v12];
    if ( *result == v4 )
      break;
    if ( *result > v4 )
    {
      v8 = v12 - 1;
      if ( v12 - 1 < v11 )
        goto LABEL_16;
    }
    else
    {
      v11 = v12 + 1;
      if ( v8 < v12 + 1 )
        goto LABEL_16;
    }
  }
  a1[2] = v12 + 1;
  return result;
}


// Function: ea_refcount_free @ 0x3a8d0
long long ea_refcount_free(long long a1)
{
  long long result; // rax
  long long v2; // [rsp+8h] [rbp-10h] BYREF

  v2 = a1;
  if ( a1 )
  {
    if ( *(long long *)(a1 + 24) )
      ext2fs_free_mem(a1 + 24);
    return ext2fs_free_mem(&v2);
  }
  return result;
}


// Function: ea_refcount_create @ 0x3a910
long long ea_refcount_create(long long a1, long long *a2)
{
  long long v2; // rbx
  long long result; // rax
  size_t v4; // rdi
  long long v5; // [rsp+8h] [rbp-30h]
  long long *v6; // [rsp+10h] [rbp-28h]

  v2 = a1;
  result = ext2fs_get_memzero(0x20u);
  if ( !result )
  {
    if ( a1 )
    {
      v4 = 16 * a1;
    }
    else
    {
      v4 = 8000;
      v2 = 500;
    }
    v6[1] = v2;
    result = ext2fs_get_memzero(v4);
    if ( result )
    {
      v5 = result;
      ea_refcount_free((long long)v6);
      return v5;
    }
    else
    {
      *v6 = 0;
      v6[2] = 0;
      *a2 = v6;
    }
  }
  return result;
}


// Function: ea_refcount_fetch @ 0x3a9d0
long long ea_refcount_fetch(unsigned long long *a1, unsigned long long a2, long long *a3)
{
  unsigned long long *v4; // rax

  v4 = sub_3A7A0(a1, a2, 0);
  if ( v4 )
    *a3 = v4[1];
  else
    *a3 = 0;
  return 0;
}


// Function: ea_refcount_increment @ 0x3aa00
long long ea_refcount_increment(unsigned long long *a1, unsigned long long a2, long long *a3)
{
  unsigned long long *v4; // rax
  unsigned long long v5; // rcx
  long long result; // rax

  v4 = sub_3A7A0(a1, a2, 1);
  if ( !v4 )
    return 2133571398;
  v5 = v4[1];
  v4[1] = v5 + 1;
  result = 0;
  if ( a3 )
    *a3 = v5 + 1;
  return result;
}


// Function: ea_refcount_decrement @ 0x3aa40
long long ea_refcount_decrement(unsigned long long *a1, unsigned long long a2, unsigned long long *a3)
{
  unsigned long long *v4; // rax
  unsigned long long v5; // rcx
  long long v6; // r8
  unsigned long long v7; // rcx

  v4 = sub_3A7A0(a1, a2, 0);
  if ( !v4 )
    return 2133571399;
  v5 = v4[1];
  v6 = 2133571399;
  if ( v5 )
  {
    v7 = v5 - 1;
    v6 = 0;
    v4[1] = v7;
    if ( a3 )
      *a3 = v7;
  }
  return v6;
}


// Function: ea_refcount_store @ 0x3aa90
long long ea_refcount_store(unsigned long long *a1, unsigned long long a2, unsigned long long a3)
{
  unsigned long long *v4; // rax

  v4 = sub_3A7A0(a1, a2, a3 != 0);
  if ( !v4 )
    return a3 != 0 ? 0x7F2BB746 : 0;
  v4[1] = a3;
  return 0;
}


// Function: ext2fs_get_refcount_size @ 0x3aad0
long long ext2fs_get_refcount_size(long long a1)
{
  if ( a1 )
    return *(long long *)(a1 + 8);
  else
    return 0;
}


// Function: ea_refcount_intr_begin @ 0x3aaf0
void ea_refcount_intr_begin(long long a1)
{
  *(long long *)(a1 + 16) = 0;
}


// Function: ea_refcount_intr_next @ 0x3ab00
long long ea_refcount_intr_next(unsigned long long *a1, long long *a2)
{
  unsigned long long v2; // rax
  unsigned long long v3; // r8
  long long *i; // rdx
  long long v5; // rcx

  v2 = a1[2];
  v3 = *a1;
  if ( *a1 <= v2 )
    return 0;
  for ( i = (long long *)(a1[3] + 16 * v2); ; i += 2 )
  {
    v5 = i[1];
    ++v2;
    if ( v5 )
      break;
    a1[2] = v2;
    if ( v3 == v2 )
      return 0;
  }
  if ( a2 )
    *a2 = v5;
  a1[2] = v2;
  return *i;
}


// Function: ino_cmp @ 0x3ac10
long long ino_cmp(long long *a1, int *a2)
{
  return (unsigned int)a1[1] - a2[2];
}


// Function: free_out_dir @ 0x3ac20
void free_out_dir(long long a1)
{
  free(*(void **)(a1 + 8));
  free(*(void **)(a1 + 16));
  *(long long *)a1 = 0;
}


// Function: name_cmp @ 0x3ac40
int name_cmp(long long a1, long long a2)
{
  int *v2; // r12
  unsigned int v3; // eax
  int *v4; // r13
  size_t v5; // rbp
  unsigned int v6; // eax
  size_t v7; // rdx
  unsigned int v8; // ebx
  int result; // eax

  v2 = *(int **)(a1 + 16);
  v3 = ext2fs_dirent_name_len(v2);
  v4 = *(int **)(a2 + 16);
  v5 = v3;
  v6 = ext2fs_dirent_name_len(v4);
  v7 = v6;
  v8 = v6;
  if ( (unsigned int)v5 <= v6 )
    v7 = v5;
  result = memcmp(v2 + 2, v4 + 2, v7);
  if ( !result )
  {
    result = 1;
    if ( (unsigned int)v5 <= v8 )
    {
      if ( (unsigned int)v5 < v8 )
        return -1;
      else
        return *v4 - *v2;
    }
  }
  return result;
}


// Function: same_name @ 0x3acb0
long long same_name(unsigned int *a1, const void *a2, int a3, const void *a4, int a5)
{
  long long result; // rax

  result = *a1;
  if ( (int)result )
    return (unsigned int)ext2fs_casefold_cmp(*((long long *)a1 + 1), a2, a3, a4, a5) == 0;
  if ( a5 == a3 )
    return memcmp(a2, a4, a5) == 0;
  return result;
}


// Function: mutate_name @ 0x3ad10
long long mutate_name(char *a1, int *a2)
{
  long long v4; // r12
  long long v5; // rbx
  const unsigned short *v6; // rsi
  char *v7; // rdx
  long long result; // rax
  char *v9; // rcx
  long long v10; // rdi
  int v11; // eax
  unsigned int v12; // edx
  bool v13; // zf

  v4 = (unsigned int)*a2;
  LODWORD(v5) = v4 - 1;
  if ( (int)v4 - 1 <= 0 )
  {
    LODWORD(result) = v4 - 1;
  }
  else
  {
    v6 = *__ctype_b_loc();
    v7 = &a1[(int)v5];
    LODWORD(result) = v4 - 1;
    do
    {
      if ( (v6[*v7] & 0x800) == 0 )
        break;
      --v7;
      LODWORD(result) = result - 1;
    }
    while ( (int)result );
  }
  if ( (int)v5 == (int)result || (result = (int)result, a1[(int)result] != 126) )
  {
    result = (unsigned int)(v4 + 2);
    if ( (v5 & 2) != 0 )
    {
      result = ((int)v4 + 3) & 0xFFFFFFFC;
      v4 = (unsigned int)(result - 2);
    }
    a1[v4] = 126;
    a1[(unsigned int)(result - 1)] = 48;
    *a2 = result;
  }
  else if ( (int)v5 >= 0 )
  {
    result = (long long)__ctype_b_loc();
    v5 = (int)v5;
    v9 = &a1[(int)v5];
    while ( 1 )
    {
      v10 = (char)*v9;
      if ( (*(char *)(*(long long *)result + 2 * v10 + 1) & 8) == 0 )
        break;
      if ( (char)v10 != 57 )
      {
        *v9 = v10 + 1;
        return result;
      }
      --v5;
      *v9-- = 48;
      if ( (int)v5 == -1 )
        return result;
    }
    if ( (int)v5 == 1 )
    {
      result = (unsigned char)*a1;
      if ( (char)result == 122 )
      {
        *a1 = 65;
      }
      else if ( (char)result == 90 )
      {
        *(short *)a1 = 12414;
        return 12414;
      }
      else
      {
        result = (unsigned int)(result + 1);
        *a1 = result;
      }
    }
    else if ( (int)v5 )
    {
      *v9 = 49;
      a1[v5 - 1] = 126;
    }
    else
    {
      v11 = (unsigned char)*a1;
      v12 = v11 + 1;
      v13 = (char)v11 == 126;
      result = 97;
      if ( !v13 )
        result = v12;
      *a1 = result;
    }
  }
  return result;
}


// Function: duplicate_search_and_fix @ 0x3ae50
long long duplicate_search_and_fix(long long *a1, long long a2, int a3, long long a4, unsigned int *a5)
{
  long long v7; // rax
  int v8; // edx
  unsigned int v9; // ebx
  long long v10; // r15
  long long v11; // rbp
  int *v12; // r13
  long long v13; // r14
  int v14; // eax
  int *v15; // rdx
  long long v16; // r13
  unsigned int v17; // eax
  unsigned int v18; // r14d
  unsigned int v19; // ebp
  long long v20; // r13
  int v21; // eax
  int v24; // [rsp+8h] [rbp-200h]
  unsigned int v25; // [rsp+2Ch] [rbp-1DCh]
  long long v26; // [rsp+30h] [rbp-1D8h]
  unsigned int v27; // [rsp+38h] [rbp-1D0h]
  int v28; // [rsp+3Ch] [rbp-1CCh]
  unsigned int n; // [rsp+4Ch] [rbp-1BCh] BYREF
  int n_4[8]; // [rsp+50h] [rbp-1B8h] BYREF
  int *v31; // [rsp+70h] [rbp-198h]
  char *v32; // [rsp+B0h] [rbp-158h]
  char src[264]; // [rsp+C0h] [rbp-148h] BYREF
  unsigned long long v34; // [rsp+1C8h] [rbp-40h]

  v34 = __readfsqword(0x28u);
  v28 = *(int *)(*(long long *)(a4 + 8) + 32LL) & 0x40000000;
  clear_problem_context((long long)n_4);
  v7 = *(long long *)(a2 + 32);
  n_4[2] = a3;
  v27 = *(unsigned char *)(v7 + 252);
  if ( v27 <= 2 )
  {
    v8 = *(unsigned char *)(v7 + 252) + 3;
    if ( (*(char *)(v7 + 352) & 2) == 0 )
      v8 = *(unsigned char *)(v7 + 252);
    v27 = v8;
  }
  v25 = 0;
  if ( *(int *)(a4 + 52) > 1u )
  {
    v9 = 1;
    v10 = a4;
    while ( 1 )
    {
      v11 = *(long long *)(v10 + 40) + 24LL * v9;
      v12 = *(int **)(v11 + 16);
      if ( !*v12 )
        goto LABEL_8;
      v13 = *(long long *)(v11 - 8);
      v24 = ext2fs_dirent_name_len(v13);
      v14 = ext2fs_dirent_name_len(v12);
      if ( !(unsigned int)sub_3ACB0(a5, v12 + 2, v14, (const void *)(v13 + 8), v24) )
        goto LABEL_8;
      v15 = *(int **)(v11 - 8);
      v31 = *(int **)(v11 + 16);
      if ( *v31 == *v15 )
      {
        if ( (unsigned int)fix_problem((long long)a1, 0x20041u, (long long)n_4) )
          break;
      }
      if ( (*(char *)(*(long long *)(v10 + 8) + 33LL) & 8) != 0
        && (unsigned int)fix_problem((long long)a1, (unsigned int)&loc_20054, (long long)n_4) )
      {
        break;
      }
      v16 = *(long long *)(v11 + 16);
      v17 = ext2fs_dirent_name_len(v16);
      n = v17;
      if ( v17 )
      {
        __memcpy_chk(src, v16 + 8, v17);
        sub_3AD10(src, &n);
        v18 = n;
        if ( *(int *)(v10 + 52) )
        {
          v26 = v11;
          v19 = 0;
          do
          {
            while ( v19 != v9 )
            {
              v20 = *(long long *)(*(long long *)(v10 + 40) + 24LL * v19 + 16);
              v21 = ext2fs_dirent_name_len(v20);
              if ( !(unsigned int)sub_3ACB0(a5, src, v18, (const void *)(v20 + 8), v21) )
                break;
              v19 = 0;
              sub_3AD10(src, &n);
              v18 = n;
              if ( !*(int *)(v10 + 52) )
                goto LABEL_20;
            }
            ++v19;
          }
          while ( *(int *)(v10 + 52) > v19 );
LABEL_20:
          v11 = v26;
        }
        src[v18] = 0;
        v32 = src;
        if ( !(unsigned int)fix_problem((long long)a1, (unsigned int)&loc_20042, (long long)n_4) )
          goto LABEL_8;
        ++v9;
        memcpy((void *)(*(long long *)(v11 + 16) + 8LL), src, v18);
        ext2fs_dirent_set_name_len(*(long long *)(v11 + 16), v18);
        ext2fs_dirhash2(
          v27,
          (unsigned int)src,
          v18,
          *(long long *)(a2 + 360),
          v28,
          *(long long *)(a2 + 32) + 236,
          v11,
          v11 + 4);
        ++v25;
        if ( *(int *)(v10 + 52) <= v9 )
          return v25;
      }
      else
      {
        ext2fs_unmark_valid(a2);
LABEL_8:
        if ( *(int *)(v10 + 52) <= ++v9 )
          return v25;
      }
    }
    e2fsck_adjust_inode_count(a1, **(unsigned int **)(v11 + 16), -1);
    **(int **)(v11 + 16) = 0;
    ++v25;
    goto LABEL_8;
  }
  return v25;
}


// Function: write_directory @ 0x3b190
long long write_directory(long long *a1, long long a2, int *a3, unsigned int a4, long long a5, int a6)
{
  int v12; // ecx
  long long result; // rax
  int v14; // eax
  int *v15; // [rsp+0h] [rbp-68h] BYREF
  long long v16; // [rsp+8h] [rbp-60h]
  unsigned int v17; // [rsp+10h] [rbp-58h]
  long long *v18; // [rsp+18h] [rbp-50h]
  unsigned int v19; // [rsp+20h] [rbp-48h]
  unsigned long long v20; // [rsp+28h] [rbp-40h]

  v12 = *a3;
  v20 = __readfsqword(0x28u);
  result = e2fsck_expand_directory(a1, a4, -1, v12);
  if ( !result )
  {
    v15 = a3;
    v16 = 0;
    v17 = a4;
    v18 = a1;
    v19 = a4;
    result = ext2fs_block_iterate3(a2, a4, 0, 0, sub_3B2C0, &v15);
    if ( !result )
    {
      result = v16;
      if ( !v16 )
      {
        e2fsck_read_inode(a1, a4, a5, (int)"rehash_dir");
        v14 = *(int *)(a5 + 32);
        if ( a6 )
          BYTE1(v14) &= ~0x10u;
        else
          BYTE1(v14) |= 0x10u;
        *(int *)(a5 + 32) = v14;
        result = ext2fs_inode_size_set(a2, a5, *(unsigned int *)(a2 + 40) * (unsigned long long)(unsigned int)*a3);
        if ( !result )
          return ext2fs_punch(a2, a4, a5, 0, (unsigned int)*a3, -1);
      }
    }
  }
  return result;
}


// Function: write_dir_block @ 0x3b2c0
long long write_dir_block(long long a1, long long *a2, long long a3, long long a4, long long a5, unsigned int **a6)
{
  long long v7; // rsi
  long long v8; // r8
  long long v10; // rdx
  long long v11; // rax
  bool v12; // zf
  long long result; // rax
  long long v14; // rdx
  long long v15[5]; // [rsp+10h] [rbp-28h] BYREF

  v7 = *a2;
  v15[1] = __readfsqword(0x28u);
  v15[0] = 0;
  if ( a3 < 0 || !v7 )
    return 0;
  v8 = *((unsigned int *)a6 + 8);
  if ( **a6 <= a3 )
  {
    result = 0;
    if ( a6[3][138] != (int)v8 )
      return result;
    v14 = ext2fs_new_dir_block(a1, 0, 0, v15);
    a6[1] = (unsigned int *)v14;
    result = 2;
    if ( v14 )
      return result;
    v10 = v15[0];
    v7 = *a2;
    v8 = *((unsigned int *)a6 + 8);
    ++**a6;
  }
  else
  {
    v10 = *((long long *)*a6 + 1) + *(unsigned int *)(a1 + 40) * a3;
  }
  v11 = ext2fs_write_dir_block4(a1, v7, v10, 0, v8);
  v12 = v15[0] == 0;
  a6[1] = (unsigned int *)v11;
  if ( !v12 )
  {
    ext2fs_free_mem(v15);
    v11 = (long long)a6[1];
  }
  return 2 * (unsigned int)(v11 != 0);
}


// Function: get_next_block @ 0x3b450
long long get_next_block(long long a1, unsigned int *a2, long long *a3)
{
  long long v5; // rdi
  unsigned int v6; // eax
  unsigned int v7; // edx
  long long result; // rax
  size_t v9; // rdx
  void *v10; // rdi

  v5 = *a2;
  v6 = a2[1];
  if ( (unsigned int)v5 < v6 )
    goto LABEL_6;
  v7 = v6 / 0xA;
  if ( (int)(v6 / 0xA) < 50 )
    v7 = 50;
  result = sub_3B3C0(*(unsigned int *)(a1 + 40), a2, v6 + v7);
  if ( !result )
  {
    v5 = *a2;
LABEL_6:
    v9 = *(unsigned int *)(a1 + 40);
    *a2 = v5 + 1;
    v10 = (void *)(*((long long *)a2 + 1) + v9 * v5);
    *a3 = v10;
    memset(v10, 0, v9);
    return 0;
  }
  return result;
}


// Function: hash_cmp @ 0x3b550
int hash_cmp(int *a1, int *a2, long long a3)
{
  unsigned int v3; // eax

  if ( *a1 > *a2 )
    return 1;
  if ( *a1 < *a2 )
    return -1;
  v3 = a2[1];
  if ( a1[1] > v3 )
    return 1;
  if ( a1[1] < v3 )
    return -1;
  if ( *(int *)a3 )
    return sub_3B4C0(*(long long *)(a3 + 8), a1, a2);
  else
    return sub_3AC40((long long)a1, (long long)a2);
}


// Function: copy_dir_entries @ 0x3b910
long long copy_dir_entries(long long a1, long long a2, long long a3)
{
  long long v4; // r13
  long long v5; // rdi
  int v6; // eax
  bool v7; // zf
  int v8; // ecx
  int v9; // eax
  long long v10; // rcx
  int v11; // ebp
  unsigned int *v13; // r12
  long long v14; // rcx
  int v15; // edx
  unsigned int v16; // ebx
  unsigned int v17; // r15d
  long long v18; // rax
  int *v19; // r8
  int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // eax
  long long v24; // rcx
  int v25; // eax
  long long v26; // rbp
  unsigned int *v27; // r8
  unsigned char v28; // al
  unsigned int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // [rsp+Ch] [rbp-8Ch]
  int *v32; // [rsp+10h] [rbp-88h]
  unsigned int v33; // [rsp+10h] [rbp-88h]
  unsigned int v34; // [rsp+18h] [rbp-80h]
  unsigned int v35; // [rsp+1Ch] [rbp-7Ch]
  int v36; // [rsp+20h] [rbp-78h]
  int *v37; // [rsp+20h] [rbp-78h]
  unsigned int v38; // [rsp+28h] [rbp-70h]
  int v39; // [rsp+2Ch] [rbp-6Ch]
  int v41; // [rsp+38h] [rbp-60h]
  char v42[12]; // [rsp+3Ch] [rbp-5Ch]
  long long v43[9]; // [rsp+50h] [rbp-48h] BYREF

  v4 = *(long long *)a1;
  v5 = *(long long *)(a2 + 8);
  v43[1] = __readfsqword(0x28u);
  v34 = sub_3AB60(v5);
  if ( *(int *)(a1 + 608) == 255 )
  {
    profile_get_uint(*(long long *)(a1 + 864), "options", "indexed_dir_slack_percentage", 0, 20, a1 + 608);
    if ( *(int *)(a1 + 608) > 0x64u )
      *(int *)(a1 + 608) = 20;
  }
  v6 = sub_3B900(*(unsigned int *)(*(long long *)(v4 + 32) + 100LL));
  v7 = v6 == 0;
  v8 = v6;
  v9 = 12;
  if ( v7 )
    v9 = v8;
  v10 = *(unsigned int *)(v4 + 40);
  *(int *)(a3 + 4) = 0;
  v39 = v9;
  v11 = v9;
  *(long long *)&v42[4] = sub_3B3C0(*(unsigned int *)(v4 + 40), a3, (unsigned int)(*(long long *)(a2 + 56) / v10) + 2);
  if ( !*(long long *)&v42[4] )
  {
    *(int *)a3 = *(int *)(a2 + 64) == 0;
    **(int **)(a3 + 16) = 0;
    *(long long *)&v42[4] = sub_3B450(v4, (unsigned int *)a3, v43);
    if ( !*(long long *)&v42[4] )
    {
      *(long long *)v42 = (unsigned int)sub_3AB80(1, v34);
      v13 = (unsigned int *)v43[0];
      v14 = *(unsigned int *)v42;
      v15 = *(int *)(v4 + 40) - v11;
      if ( !*(int *)(a2 + 64) )
      {
        v30 = *(int *)(a1 + 608) * v15 / 0x64u;
        if ( *(int *)v42 >= v30 )
          v30 = *(int *)v42;
        *(int *)v42 = v30;
      }
      v16 = *(int *)(a2 + 52);
      if ( v16 )
      {
        v41 = 1;
        v17 = 0;
        v16 = 0;
        v35 = 0;
        v31 = 0;
        while ( 1 )
        {
          v26 = *(long long *)(a2 + 40) + 24LL * v17;
          v27 = *(unsigned int **)(v26 + 16);
          v14 = *v27;
          v33 = *v27;
          if ( !(int)v14 )
            goto LABEL_24;
          v38 = v15;
          v37 = *(int **)(v26 + 16);
          v28 = ext2fs_dirent_name_len(v27);
          v29 = sub_3AB80(v28, v34);
          v19 = v37;
          v21 = v33;
          v16 = v29;
          if ( v29 > v38 )
            break;
          v36 = *(int *)(v4 + 40) - v39;
          v31 = v36 - v35;
          v13 = (unsigned int *)(v43[0] + v35);
          if ( !v35 )
            goto LABEL_15;
LABEL_18:
          *v13 = v21;
          v32 = v19;
          v22 = ext2fs_dirent_name_len(v19);
          ext2fs_dirent_set_name_len(v13, v22);
          v23 = ext2fs_dirent_file_type(v32);
          ext2fs_dirent_set_file_type(v13, v23);
          v18 = ext2fs_set_rec_len(v4, v16, v13, v24);
          if ( v18 )
            goto LABEL_32;
          v25 = ext2fs_dirent_name_len(v13);
          memcpy(v13 + 2, (const void *)(*(long long *)(v26 + 16) + 8LL), v25);
          if ( v34 )
          {
            *(unsigned int *)((char *)v13 + (int)((ext2fs_dirent_name_len(v13) + 3) & 0xFFFFFFFC) + 8) = *(int *)v26;
            *(unsigned int *)((char *)v13 + (int)((ext2fs_dirent_name_len(v13) + 3) & 0xFFFFFFFC) + 12) = *(int *)(v26 + 4);
          }
          v15 = v31 - v16;
          if ( v31 - v16 < *(int *)v42 )
          {
            v18 = ext2fs_set_rec_len(v4, v31, v13, v14);
            if ( v18 )
              goto LABEL_32;
            v15 = 0;
            v35 = v36;
          }
          else
          {
            v35 += v16;
            v31 = v16;
          }
          v41 = *(int *)v26;
LABEL_24:
          if ( *(int *)(a2 + 52) <= ++v17 )
            goto LABEL_38;
        }
        if ( v38 )
        {
          v18 = ext2fs_set_rec_len(v4, v38 + v31, v13, v33);
          if ( v18 )
            goto LABEL_32;
        }
        if ( v39 )
          ext2fs_initialize_dirent_tail(v4, v43[0] + *(unsigned int *)(v4 + 40) - 12LL);
        v18 = sub_3B450(v4, (unsigned int *)a3, v43);
        if ( v18 )
        {
LABEL_32:
          *(long long *)&v42[4] = v18;
          return *(long long *)&v42[4];
        }
        v13 = (unsigned int *)v43[0];
        v19 = *(int **)(v26 + 16);
        v36 = *(int *)(v4 + 40) - v39;
        v31 = v36;
LABEL_15:
        v20 = *(int *)v26;
        if ( *(int *)v26 == v41 )
          v20 = v41 | 1;
        *(int *)(*(long long *)(a3 + 16) + 4LL * (unsigned int)(*(int *)a3 - 1)) = v20;
        v21 = *v19;
        v35 = 0;
        goto LABEL_18;
      }
LABEL_38:
      if ( v15 )
        *(long long *)&v42[4] = ext2fs_set_rec_len(v4, v15 + v16, v13, v14);
      if ( v39 )
        ext2fs_initialize_dirent_tail(v4, v43[0] + *(unsigned int *)(v4 + 40) - 12LL);
    }
  }
  return *(long long *)&v42[4];
}


// Function: set_int_node @ 0x3bd80
short *set_int_node(long long a1, short *a2)
{
  long long v3; // rsi
  long long v4; // rcx
  int v5; // edx

  memset(a2, 0, *(unsigned int *)(a1 + 40));
  v3 = *(unsigned int *)(a1 + 40);
  *(int *)a2 = 0;
  ext2fs_set_rec_len(a1, v3, a2, v4);
  LOBYTE(v5) = (unsigned int)sub_3B900(*(unsigned int *)(*(long long *)(a1 + 32) + 100LL)) != 0;
  a2[4] = (unsigned int)(*(int *)(a1 + 40) - 8 - 8 * v5) >> 3;
  a2[5] = 0;
  return a2 + 4;
}


// Function: alloc_blocks @ 0x3bdf0
long long alloc_blocks(
        long long a1,
        short **a2,
        long long *a3,
        long long *a4,
        int *a5,
        int *a6,
        long long a7,
        int a8,
        int *a9,
        int *a10)
{
  unsigned int v14; // esi
  int *v15; // rax
  long long result; // rax
  short *v17; // rax
  short *v19[9]; // [rsp+20h] [rbp-48h] BYREF

  v19[1] = (short *)__readfsqword(0x28u);
  if ( *a2 )
    (*a2)[1] = **a2;
  v14 = *(int *)a7;
  v15 = (int *)(*(long long *)(a7 + 8) + *a5);
  *a3 = v15;
  v15[1] = v14;
  if ( a8 != 1 )
    *v15 = *(int *)(*(long long *)(a7 + 16) + 4LL * a8);
  result = sub_3B450(a1, (unsigned int *)a7, v19);
  if ( !result )
  {
    *a3 = *(long long *)(a7 + 8) + *a5;
    v17 = sub_3BD80(a1, v19[0]);
    *a4 = v17;
    *a2 = v17;
    if ( a6 )
      *a6 = (int)v17 - *(int *)(a7 + 8);
    *a10 = (unsigned short)*v17;
    *a5 += 8;
    --*a9;
    return 0;
  }
  return result;
}


// Function: set_root_node @ 0x3bf00
long long set_root_node(long long a1, int *a2, int a3, int a4, long long a5)
{
  long long v8; // r12
  int v9; // edx
  bool v10; // zf
  char v11; // cl
  long long v12; // rax
  int v13; // eax
  int v14; // edx
  unsigned int v15; // edx
  long long v16; // r8

  v8 = (unsigned int)sub_3B8F0(*(unsigned int *)(*(long long *)(a1 + 32) + 96LL)) != 0;
  memset(a2, 0, *(unsigned int *)(a1 + 40));
  *a2 = a3;
  LODWORD(v8) = 2 * v8;
  *((char *)a2 + 8) = 46;
  ext2fs_dirent_set_name_len(a2, 1);
  ext2fs_dirent_set_file_type(a2, (unsigned int)v8);
  a2[3] = a4;
  *((short *)a2 + 10) = 11822;
  *((short *)a2 + 2) = 12;
  ext2fs_dirent_set_name_len(a2 + 3, 2);
  ext2fs_dirent_set_file_type(a2 + 3, (unsigned int)v8);
  v9 = *(int *)(a1 + 40);
  a2[6] = 0;
  *((short *)a2 + 8) = v9 - 12;
  v10 = (unsigned int)sub_3AB60(a5) == 0;
  v12 = *(long long *)(a1 + 32);
  if ( v10 )
    v11 = *(char *)(v12 + 252);
  *((char *)a2 + 28) = v11;
  *((char *)a2 + 29) = 8;
  *((short *)a2 + 15) = 0;
  v13 = sub_3B900(*(unsigned int *)(v12 + 100));
  *((short *)a2 + 17) = 0;
  v15 = v14 - 8 * (v13 != 0);
  *((short *)a2 + 16) = v15 >> 3;
  return v16;
}


// Function: calculate_tree @ 0x3c010
long long calculate_tree(long long a1, long long a2, int a3, int a4, long long a5)
{
  int *v6; // rsi
  long long v7; // rax
  long long v8; // rbx
  int v9; // r12d
  long long v10; // r14
  unsigned short *v11; // rbx
  int v12; // esi
  short v13; // r13
  unsigned short v14; // ax
  long long v15; // rax
  int v16; // edx
  long long v17; // rcx
  long long result; // rax
  int v19; // r8d
  int v20; // edx
  long long v21; // r14
  int v22; // ebx
  char *v23; // r12
  char *v24; // r13
  unsigned short *v25; // r13
  short *v26; // rcx
  int *v27; // rax
  int v28; // edi
  short v29; // si
  int v30; // r8d
  long long v31; // r14
  int v32; // eax
  int v33; // ebx
  short *v34; // rsi
  int *v35; // rdx
  int v36; // edi
  short *v37; // rax
  short v38; // di
  short v39; // cx
  int v40; // [rsp+4h] [rbp-B4h]
  long long v42; // [rsp+28h] [rbp-90h]
  int v43; // [rsp+3Ch] [rbp-7Ch] BYREF
  int v44; // [rsp+40h] [rbp-78h] BYREF
  int v45; // [rsp+44h] [rbp-74h] BYREF
  int v46; // [rsp+48h] [rbp-70h] BYREF
  int v47; // [rsp+4Ch] [rbp-6Ch] BYREF
  unsigned short *v48; // [rsp+50h] [rbp-68h] BYREF
  long long v49; // [rsp+58h] [rbp-60h] BYREF
  int *v50; // [rsp+60h] [rbp-58h] BYREF
  short *v51; // [rsp+68h] [rbp-50h] BYREF
  short *v52[9]; // [rsp+70h] [rbp-48h] BYREF

  v6 = *(int **)(a2 + 8);
  v52[1] = (short *)__readfsqword(0x28u);
  v50 = 0;
  v7 = sub_3BF00(a1, v6, a3, a4, a5);
  v8 = *(long long *)(a2 + 8);
  v9 = *(int *)a2;
  v10 = v7;
  v47 = v7 - *(int *)(a2 + 8) + *(unsigned char *)(v7 + 5);
  v11 = (unsigned short *)(v47 + v8);
  v42 = v47;
  v12 = *v11;
  v43 = v12;
  v13 = v12;
  if ( v12 < v9 - 1 )
  {
    v44 = 0;
    if ( v9 - 1 <= (int)ext2fs_htree_intnode_maxrecs(a1) )
    {
      v52[0] = 0;
      *(char *)(v10 + 6) = 1;
      if ( v9 <= 1 )
      {
        v39 = 17791;
        v14 = 0;
        v34 = 0;
      }
      else
      {
        v30 = v12;
        v31 = 4;
        v32 = 0;
        v33 = 1;
        do
        {
          if ( !(v30 | v32) )
            return 28;
          if ( !v32 )
          {
            result = (int)sub_3BDF0(a1, v52, &v48, &v50, &v47, 0, a2, v33, &v43, &v44);
            if ( (int)result )
              return result;
            v32 = v44;
            v30 = v43;
          }
          v34 = v52[0];
          v35 = v50;
          v36 = (unsigned short)*v52[0];
          v50[1] = v33;
          if ( v36 != v32 )
            *v35 = *(int *)(*(long long *)(a2 + 16) + v31);
          --v32;
          ++v33;
          v31 += 4;
          v50 = v35 + 2;
          v44 = v32;
        }
        while ( v9 != v33 );
        v11 = (unsigned short *)(*(long long *)(a2 + 8) + v42);
        v39 = v36 - v32;
        v14 = *v11 - v30;
      }
      v34[1] = v39;
    }
    else
    {
      v45 = 0;
      v52[0] = 0;
      v51 = 0;
      *(char *)(v10 + 6) = 2;
      if ( v9 <= 1 )
      {
        v29 = 17791;
        LOWORD(v20) = 0;
        v37 = 0;
        v26 = 0;
        v38 = 17791;
      }
      else
      {
        v40 = v9;
        v19 = 0;
        v20 = 0;
        v21 = 4;
        v22 = 1;
        do
        {
          if ( !v20 )
          {
            if ( !v19 )
            {
              if ( !v43 )
                return 28;
              result = (int)sub_3BDF0(a1, &v51, &v48, &v49, &v47, &v46, a2, v22, &v43, &v44);
              if ( (int)result )
                return result;
            }
            v23 = (char *)v51 - *(long long *)(a2 + 8);
            v24 = (char *)v48 - *(long long *)(a2 + 8);
            result = (int)sub_3BDF0(a1, v52, &v49, &v50, &v46, 0, a2, v22, &v44, &v45);
            if ( (int)result )
              return result;
            v25 = (unsigned short *)(*(long long *)(a2 + 8) + (int)v24);
            v20 = v45;
            v19 = v44;
            v51 = (short *)(*(long long *)(a2 + 8) + (int)v23);
            v48 = v25;
          }
          v26 = v52[0];
          v27 = v50;
          v28 = (unsigned short)*v52[0];
          v50[1] = v22;
          v29 = v28;
          if ( v28 != v20 )
            *v27 = *(int *)(*(long long *)(a2 + 16) + v21);
          --v20;
          ++v22;
          v21 += 4;
          v50 = v27 + 2;
          v45 = v20;
        }
        while ( v40 != v22 );
        v37 = v51;
        v13 = v43;
        v38 = v28 - v19;
        v11 = (unsigned short *)(*(long long *)(a2 + 8) + v42);
      }
      *v37 = v29;
      v37[1] = v38;
      v26[1] = *v26 - v20;
      v14 = *v11 - v13;
    }
  }
  else
  {
    v48 = v11;
    v14 = 0;
    if ( v9 > 1 )
    {
      *((int *)v11 + 1) = 1;
      v15 = 8;
      v16 = 1;
      while ( v9 != ++v16 )
      {
        v17 = *(long long *)(a2 + 16);
        *(int *)&v11[v15 - 2] = v16;
        *(int *)&v11[v15 - 4] = *(int *)(v17 + v15);
        v15 += 4;
      }
      v14 = v9 - 1;
    }
  }
  v11[1] = v14;
  return 0;
}


// Function: is_fake_entry @ 0x3c410
long long is_fake_entry(long long a1, int a2, unsigned int a3)
{
  long long result; // rax
  int v4; // edx
  long long v5; // rcx

  if ( a2 || (result = 1, a3 > 0xC) )
  {
    result = sub_3B900(*(unsigned int *)(*(long long *)(a1 + 32) + 100LL));
    if ( (int)result )
      return ((*(int *)(v5 + 40) - 1) & v4) == *(unsigned int *)(v5 + 40) - 12LL;
  }
  return result;
}


// Function: fill_dir_block @ 0x3c450
long long fill_dir_block(long long a1, long long *a2, long long a3, long long a4, long long a5, long long a6)
{
  int v6; // r12d
  size_t v7; // rdx
  long long v9; // r14
  long long v10; // r13
  long long v11; // rsi
  long long v12; // r8
  int v13; // eax
  int v14; // ebx
  long long dir_block4; // rax
  int v16; // edx
  long long v17; // rdi
  long long v18; // rax
  int v19; // edx
  unsigned int v20; // ebx
  long long v21; // r13
  unsigned int v22; // r14d
  long long v23; // r12
  int v24; // eax
  unsigned int v25; // edx
  int v26; // r15d
  long long v27; // rax
  long long v28; // rsi
  long long v29; // rdi
  long long v30; // r14
  unsigned int v31; // ecx
  int v32; // eax
  long long v34; // rcx
  long long v35; // rax
  long long v36; // rax
  unsigned int v37; // [rsp+Ch] [rbp-6Ch]
  long long v38; // [rsp+10h] [rbp-68h]
  int v39; // [rsp+20h] [rbp-58h]
  int v40; // [rsp+24h] [rbp-54h]
  unsigned int v41; // [rsp+28h] [rbp-50h]
  int v42; // [rsp+2Ch] [rbp-4Ch]
  unsigned int v43; // [rsp+34h] [rbp-44h] BYREF
  unsigned long long v44; // [rsp+38h] [rbp-40h]

  v44 = __readfsqword(0x28u);
  if ( a3 < 0 )
    return 0;
  v6 = a3;
  v7 = *(unsigned int *)(a1 + 40);
  v9 = a6;
  v10 = (unsigned int)(v6 * *(int *)(a1 + 40));
  if ( (unsigned int)(v7 + v10) > *(int *)(*(long long *)(a6 + 8) + 4LL) )
  {
LABEL_28:
    *(long long *)(v9 + 24) = 2133571363;
    return 2;
  }
  v11 = *a2;
  v38 = v10 + *(long long *)a6;
  if ( v11 )
  {
    v12 = *(unsigned int *)(a6 + 72);
    v13 = *(int *)(a1 + 16);
    v14 = v13 & 0x200000;
    *(int *)(a1 + 16) = v13 | 0x200000;
    dir_block4 = ext2fs_read_dir_block4(a1, v11, v38, 0, v12);
    v16 = *(int *)(a1 + 16);
    *(long long *)(v9 + 24) = dir_block4;
    *(int *)(a1 + 16) = v14 | v16 & 0xFFDFFFFF;
    if ( dir_block4 )
      return 2;
  }
  else
  {
    memset((void *)(v10 + *(long long *)a6), 0, v7);
    ext2fs_set_rec_len(a1, *(unsigned int *)(a1 + 40), v38, v34);
  }
  v17 = *(long long *)(v9 + 8);
  v42 = *(int *)(v17 + 32) & 0x40000000;
  v39 = sub_3AB60(v17);
  v18 = *(long long *)(a1 + 32);
  v41 = *(unsigned char *)(v18 + 252);
  if ( v41 <= 2 )
  {
    v19 = *(unsigned char *)(v18 + 252) + 3;
    if ( (*(char *)(v18 + 352) & 2) == 0 )
      v19 = *(unsigned char *)(v18 + 252);
    v41 = v19;
  }
  if ( !*(int *)(a1 + 40) )
    return 0;
  v40 = v6;
  v20 = 0;
  v21 = v9;
  while ( 1 )
  {
    if ( v39 )
    {
      v37 = sub_3C410(a1, v40, v20) == 0;
      v22 = (-v37 & 8) + 8;
    }
    else
    {
      v37 = 0;
      v22 = 8;
    }
    v23 = v38 + v20;
    ext2fs_get_rec_len(a1, v23, &v43);
    v24 = ext2fs_dirent_name_len(v23);
    v25 = *(int *)(a1 + 40);
    v26 = v24;
    v20 += v43;
    if ( v43 < v22 || v20 > v25 || (v43 & 3) != 0 || v43 < v22 + v24 )
    {
LABEL_27:
      v9 = v21;
      goto LABEL_28;
    }
    if ( *(int *)v23 )
      break;
LABEL_24:
    if ( v20 >= v25 )
      return 0;
  }
  if ( !v24 )
    goto LABEL_27;
  if ( !*(int *)(v21 + 64) )
  {
    if ( v24 == 1 )
    {
      if ( *(char *)(v23 + 8) == 46 )
        goto LABEL_24;
    }
    else if ( v24 == 2 && *(short *)(v23 + 8) == 11822 )
    {
      *(int *)(v21 + 68) = *(int *)v23;
      goto LABEL_24;
    }
  }
  v27 = *(unsigned int *)(v21 + 52);
  v28 = *(unsigned int *)(v21 + 48);
  if ( (unsigned int)v27 < (unsigned int)v28 )
  {
LABEL_22:
    v29 = *(long long *)(v21 + 40);
    *(int *)(v21 + 52) = v27 + 1;
    *(long long *)(v29 + 24 * v27 + 16) = v23;
    v30 = v29 + 24 * v27;
    *(long long *)(v21 + 56) += (unsigned int)sub_3AB80((unsigned char)v26, v37);
    *(long long *)(v30 + 8) = v31;
    if ( v37 )
    {
      *(int *)v30 = *(int *)(v23 + (int)((ext2fs_dirent_name_len(v23) + 3) & 0xFFFFFFFC) + 8);
      v32 = ext2fs_dirent_name_len(v23);
      v25 = *(int *)(a1 + 40);
      *(int *)(v30 + 4) = *(int *)(v23 + (int)((v32 + 3) & 0xFFFFFFFC) + 12);
    }
    else if ( *(int *)(v21 + 64) )
    {
      *(long long *)v30 = 0;
      v25 = *(int *)(a1 + 40);
    }
    else
    {
      v36 = ext2fs_dirhash2(
              v41,
              (int)v23 + 8,
              v26,
              *(long long *)(a1 + 360),
              v42,
              (unsigned int)*(long long *)(a1 + 32) + 236,
              v30,
              v30 + 4);
      *(long long *)(v21 + 24) = v36;
      if ( v36 )
        return 2;
      v25 = *(int *)(a1 + 40);
    }
    goto LABEL_24;
  }
  v35 = ext2fs_resize_array(24, v28, (unsigned int)(v28 + 500), v21 + 40);
  if ( !v35 )
  {
    *(int *)(v21 + 48) += 500;
    v27 = *(unsigned int *)(v21 + 52);
    goto LABEL_22;
  }
  *(long long *)(v21 + 24) = v35;
  return 2;
}


// Function: e2fsck_rehash_dir_later @ 0x3c820
long long e2fsck_rehash_dir_later(long long a1, unsigned int a2)
{
  long long v3; // rdi
  long long result; // rax

  v3 = *(long long *)(a1 + 584);
  if ( v3 )
    return ext2fs_u32_list_add(v3, a2);
  result = ext2fs_u32_list_create(a1 + 584, 50);
  v3 = *(long long *)(a1 + 584);
  if ( v3 )
    return ext2fs_u32_list_add(v3, a2);
  return result;
}


// Function: e2fsck_dir_will_be_rehashed @ 0x3c880
long long e2fsck_dir_will_be_rehashed(long long a1, long long a2)
{
  long long result; // rax
  long long v3; // rdi

  result = *(int *)(a1 + 76) & 0x400;
  if ( (*(int *)(a1 + 76) & 0x400) != 0 )
    return 1;
  v3 = *(long long *)(a1 + 584);
  if ( v3 )
    return ext2fs_u32_list_test(v3, a2);
  return result;
}


// Function: e2fsck_rehash_dir @ 0x3c8b0
long long e2fsck_rehash_dir(long long a1, unsigned int a2, long long a3)
{
  long long v3; // rbp
  long long mem; // r15
  long long v6; // rax
  int v7; // eax
  int v8; // r9d
  void *ptr; // [rsp+28h] [rbp-150h] BYREF
  unsigned int v11; // [rsp+30h] [rbp-148h] BYREF
  long long v12; // [rsp+38h] [rbp-140h]
  long long v13[4]; // [rsp+40h] [rbp-138h] BYREF
  __int128 v14; // [rsp+60h] [rbp-118h] BYREF
  __int128 v15; // [rsp+70h] [rbp-108h]
  _OWORD v16[3]; // [rsp+80h] [rbp-F8h] BYREF
  char v17[4]; // [rsp+B0h] [rbp-C8h] BYREF
  unsigned int v18; // [rsp+B4h] [rbp-C4h]
  char v19; // [rsp+D3h] [rbp-A5h]
  unsigned long long v20; // [rsp+138h] [rbp-40h]

  v3 = *(long long *)a1;
  v20 = __readfsqword(0x28u);
  v11 = 0;
  ptr = 0;
  memset(v13, 0, 24);
  v12 = 0;
  v14 = 0;
  v15 = 0;
  memset(v16, 0, sizeof(v16));
  e2fsck_read_inode((long long *)a1, a2, (long long)v17, (int)"rehash_dir");
  if ( !(unsigned int)sub_3B8E0(*(unsigned int *)(*(long long *)(v3 + 32) + 96LL)) || (mem = 0, (v19 & 0x10) == 0) )
  {
    mem = ext2fs_get_mem(v18, &ptr);
    if ( !mem )
    {
      LODWORD(v16[1]) = v18 >> 5;
      mem = ext2fs_get_array(24);
      if ( !mem )
      {
        LODWORD(v15) = a2;
        *(long long *)&v16[0] = a1;
        *(long long *)&v14 = ptr;
        DWORD2(v16[2]) = a2;
        *((long long *)&v14 + 1) = v17;
        if ( !(unsigned int)sub_3C810(*(unsigned int *)(*(long long *)(v3 + 32) + 92LL)) || v18 / *(int *)(v3 + 40) <= 1 )
          LODWORD(v16[2]) = 1;
        v6 = *(long long *)(v3 + 360);
        DWORD1(v16[2]) = 0;
        if ( v6 && (v19 & 0x40) != 0 )
        {
          v11 = 1;
          v12 = v6;
        }
        while ( 1 )
        {
          ext2fs_block_iterate3(v3, a2, 0, 0, sub_3C450, &v14);
          mem = *((long long *)&v15 + 1);
          if ( *((long long *)&v15 + 1) )
            break;
          v7 = v16[2];
          if ( LODWORD(v16[2]) || *((long long *)&v16[1] + 1) >= (unsigned int)(*(int *)(v3 + 40) - 24) )
          {
            while ( 1 )
            {
              if ( v7 && DWORD1(v16[1]) > 1 )
                sub_3B5F0(*((long long *)&v16[0] + 1) + 48LL, (unsigned int)(DWORD1(v16[1]) - 2), &v11);
              else
                sub_3B5F0(*((long long *)&v16[0] + 1), DWORD1(v16[1]), &v11);
              if ( !(unsigned int)sub_3AE50((long long *)a1, v3, a2, (long long)&v14, &v11) )
                break;
              v7 = v16[2];
            }
            if ( (*(char *)(a1 + 76) & 8) == 0 )
            {
              if ( LODWORD(v16[2]) && DWORD1(v16[1]) > 1 )
                qsort(
                  (void *)(*((long long *)&v16[0] + 1) + 48LL),
                  (unsigned int)(DWORD1(v16[1]) - 2),
                  0x18u,
                  (__compar_fn_t)sub_3AC10);
              mem = sub_3B910(a1, (long long)&v14, (long long)v13);
              if ( !mem )
              {
                free(ptr);
                v8 = v16[2];
                ptr = 0;
                if ( !LODWORD(v16[2]) )
                {
                  mem = sub_3C010(v3, (long long)v13, a2, SDWORD1(v16[2]), *((long long *)&v14 + 1));
                  if ( mem )
                    break;
                  v8 = v16[2];
                }
                mem = sub_3B190((long long *)a1, v3, (int *)v13, a2, (long long)v17, v8);
                if ( !mem )
                {
                  if ( (*(char *)(a1 + 77) & 0x40) != 0 )
                    mem = e2fsck_rebuild_extents_later(a1, a2);
                  else
                    mem = e2fsck_check_rebuild_extents(a1, a2, v17, a3);
                }
              }
            }
            break;
          }
          *(long long *)((char *)&v16[1] + 4) = 0;
          *(long long *)((char *)&v16[1] + 12) = 0x100000000LL;
        }
      }
    }
    ext2fs_free_mem(&ptr);
    ext2fs_free_mem((char *)v16 + 8);
    sub_3AC20((long long)v13);
  }
  return mem;
}


// Function: e2fsck_rehash_directories @ 0x3ccc0
unsigned long long e2fsck_rehash_directories(long long *a1)
{
  long long v1; // rdx
  int v2; // ebp
  long long v3; // rax
  unsigned int *v4; // r13
  int v5; // ebx
  int *v6; // rax
  long long v7; // rsi
  unsigned int v8; // esi
  float v9; // xmm0_4
  long long v10; // rax
  int v12; // [rsp+0h] [rbp-118h]
  int num_dirinfo; // [rsp+4h] [rbp-114h]
  unsigned int v14; // [rsp+14h] [rbp-104h] BYREF
  long long v15; // [rsp+18h] [rbp-100h] BYREF
  struct timeval tv; // [rsp+20h] [rbp-F8h] BYREF
  long long v17[2]; // [rsp+70h] [rbp-A8h] BYREF
  unsigned int v18; // [rsp+80h] [rbp-98h]
  unsigned long long v19; // [rsp+D8h] [rbp-40h]

  v19 = __readfsqword(0x28u);
  init_resource_track(&tv, *(long long *)(*a1 + 8));
  v2 = *((int *)a1 + 19) & 0x400;
  if ( a1[73] )
  {
    e2fsck_get_lost_and_found(a1, 0, v1);
    clear_problem_context((long long)v17);
    if ( !v2 )
    {
      v3 = ext2fs_u32_list_iterate_begin(a1[73], &v15);
      if ( v3 )
      {
        v17[0] = v3;
        fix_problem((long long)a1, 0x31001u, (long long)v17);
        return v19 - __readfsqword(0x28u);
      }
      v4 = 0;
      num_dirinfo = ext2fs_u32_list_count(a1[73]);
      goto LABEL_5;
    }
  }
  else
  {
    if ( !v2 )
      return v19 - __readfsqword(0x28u);
    e2fsck_get_lost_and_found(a1, 0, v1);
    clear_problem_context((long long)v17);
  }
  v4 = (unsigned int *)e2fsck_dir_info_iter_begin(a1);
  num_dirinfo = e2fsck_get_num_dirinfo((long long)a1);
LABEL_5:
  v12 = 0;
  v5 = 1;
LABEL_6:
  if ( v2 )
  {
LABEL_7:
    v6 = e2fsck_dir_info_iter((long long)a1, v4);
    if ( v6 )
    {
      v7 = (unsigned int)*v6;
      v14 = *v6;
      goto LABEL_9;
    }
    end_problem_latch((long long)a1, 144);
    e2fsck_dir_info_iter_end((long long)a1, (long long)v4);
  }
  else
  {
    while ( (unsigned int)ext2fs_u32_list_iterate(v15, &v14) )
    {
      v7 = v14;
LABEL_9:
      if ( !(unsigned int)ext2fs_test_inode_bitmap2(a1[47], v7) )
        goto LABEL_6;
      v8 = v14;
      v18 = v14;
      if ( v5 )
      {
        fix_problem((long long)a1, 0x31000u, (long long)v17);
        v8 = v14;
      }
      v17[0] = e2fsck_rehash_dir((long long)a1, v8, (long long)v17);
      if ( v17[0] )
      {
        end_problem_latch((long long)a1, 144);
        fix_problem((long long)a1, 0x31002u, (long long)v17);
      }
      if ( a1[44] && !*((int *)a1 + 178) )
      {
        ++v12;
        v5 = 0;
        v9 = (float)v12 * 100.0 / (float)num_dirinfo;
        e2fsck_simple_progress((long long)a1, "Rebuilding directory", v14, v9);
      }
      else
      {
        v5 = 0;
      }
      if ( v2 )
        goto LABEL_7;
    }
    end_problem_latch((long long)a1, 144);
    ext2fs_u32_list_iterate_end(v15);
  }
  if ( a1[73] )
    ext2fs_u32_list_free();
  v10 = *a1;
  a1[73] = 0;
  print_resource_track((long long)a1, "Pass 3A", &tv, *(long long *)(v10 + 8));
  return v19 - __readfsqword(0x28u);
}


// Function: append_string @ 0x3cfa0
char *append_string(char **a1, const char *a2, int a3)
{
  int v4; // ebx
  long long v5; // rdx
  int v6; // eax
  char *v7; // rdi
  int v8; // ecx
  int v9; // eax
  int v10; // r12d
  char *result; // rax
  int v12; // ebx

  v4 = a3;
  if ( !a3 )
    v4 = strlen(a2);
  v5 = *((int *)a1 + 3);
  v6 = *((int *)a1 + 2);
  v7 = *a1;
  v8 = v5 + v4 + 1;
  if ( v6 >= v8 )
    goto LABEL_8;
  v9 = 2 * v6;
  if ( v9 >= v8 )
    v8 = v9;
  v10 = v8;
  result = (char *)realloc(v7, v8);
  v7 = result;
  if ( result )
  {
    *a1 = result;
    v5 = *((int *)a1 + 3);
    *((int *)a1 + 2) = v10;
LABEL_8:
    memcpy(&v7[v5], a2, v4);
    v12 = *((int *)a1 + 3) + v4;
    result = *a1;
    *((int *)a1 + 3) = v12;
    result[v12] = 0;
  }
  return result;
}


// Function: do_read @ 0x3d3c0
long long do_read(int a1)
{
  int v1; // eax
  int v2; // r14d
  long long v3; // r13
  int v4; // ebp
  char *v5; // rax
  long long v7[519]; // [rsp+0h] [rbp-1038h] BYREF

  v7[513] = __readfsqword(0x28u);
  v1 = read(a1, v7, 0xFFFu);
  v2 = v1;
  if ( v1 > 0 )
  {
    v3 = dword_B7398;
    v4 = dword_B7398 + v1;
    v5 = (char *)realloc(buf, dword_B7398 + v1);
    if ( v5 )
    {
      buf = v5;
      memcpy(&v5[v3], v7, v2);
      dword_B7398 = v4;
    }
  }
  return (unsigned int)v2;
}


// Function: save_output @ 0x3d470
FILE *save_output(const char *a1, const char *a2, FILE *a3)
{
  const char *v3; // r13
  FILE *v4; // r12
  const char *v5; // rbp
  __pid_t v6; // eax
  int v7; // edi
  int v8; // ebx
  unsigned int v9; // edx
  char *v11; // rbp
  int v12; // edx
  int v13; // eax
  int v14; // eax
  int v15; // [rsp+0h] [rbp-48h] BYREF
  int fd; // [rsp+4h] [rbp-44h]
  unsigned long long v17; // [rsp+8h] [rbp-40h]

  v3 = a2;
  v4 = a3;
  v5 = a1;
  v17 = __readfsqword(0x28u);
  if ( !a1 )
  {
    if ( !a2 || !*a2 )
      goto LABEL_5;
    goto LABEL_31;
  }
  if ( !*a1 )
  {
    if ( !a2 || !*a2 )
    {
LABEL_5:
      if ( !a3 )
        return v4;
      if ( !LOBYTE(a3->_flags) )
        return 0;
      v5 = 0;
      goto LABEL_8;
    }
    v5 = 0;
    goto LABEL_31;
  }
  if ( a2 && *a2 )
  {
LABEL_31:
    if ( !a3 )
      goto LABEL_9;
LABEL_32:
    if ( !LOBYTE(a3->_flags) )
    {
      v4 = (FILE *)((unsigned long long)v3 | (unsigned long long)v5);
      if ( !((unsigned long long)v3 | (unsigned long long)v5) )
        return v4;
      v4 = 0;
    }
    goto LABEL_9;
  }
  if ( a3 )
  {
    v3 = 0;
    goto LABEL_32;
  }
LABEL_8:
  v3 = 0;
LABEL_9:
  if ( pipe(&v15) < 0 )
  {
    perror("pipe");
    exit(1);
  }
  v6 = fork();
  if ( v6 < 0 )
  {
    perror("fork");
    exit(1);
  }
  if ( !v6 )
  {
    if ( e2fsck_global_ctx )
    {
      v7 = *(int *)(e2fsck_global_ctx + 712);
      if ( v7 )
        close(v7);
    }
    if ( daemon(0, 0) < 0 )
    {
      perror("daemon");
      exit(1);
    }
    close(fd);
    while ( (int)sub_3D3C0(v15) > 0 )
      ;
    v8 = -1;
    close(v15);
    while ( 1 )
    {
      if ( v5 )
        v8 = open(v5, 577, 420);
      v9 = (unsigned int)v8 >> 31;
      if ( v8 < 0 )
      {
        if ( v3 )
        {
          v8 = open(v3, 577, 420);
          LOBYTE(v9) = v8 < 0;
        }
        if ( (char)v9 && v4 )
          v8 = open((const char *)v4, 577, 420);
      }
      if ( v8 >= 0 )
        break;
      sleep(1u);
    }
    v11 = (char *)buf;
    while ( 1 )
    {
      v12 = dword_B7398;
      if ( dword_B7398 <= 0 )
        break;
      while ( 1 )
      {
        v13 = write(v8, v11, v12);
        if ( v13 < 0 )
          break;
        v12 = dword_B7398 - v13;
        dword_B7398 = v12;
        v11 += v13;
        if ( v12 <= 0 )
          goto LABEL_41;
      }
      v14 = *__errno_location();
      if ( v14 != 11 && v14 != 4 )
        exit(0);
    }
LABEL_41:
    exit(0);
  }
  close(v15);
  v4 = fdopen(fd, "w");
  if ( !v4 )
    close(fd);
  return v4;
}


// Function: set_up_log_file @ 0x3d8d0
void *set_up_log_file(long long a1, long long a2, const char *a3)
{
  long long v5; // rdi
  void *v6; // rax
  char *v7; // rdi
  char *v8; // r13
  char *v9; // r15
  int v10; // r14d
  long long v11; // rsi
  char *v12; // r14
  char *v13; // rbp
  int v15; // ebx
  int v16; // eax
  void *v17; // [rsp+8h] [rbp-A0h]
  int v18; // [rsp+1Ch] [rbp-8Ch] BYREF
  char *s; // [rsp+20h] [rbp-88h] BYREF
  void *v20; // [rsp+28h] [rbp-80h] BYREF
  char *v21; // [rsp+30h] [rbp-78h] BYREF
  void *ptr[2]; // [rsp+40h] [rbp-68h] BYREF
  char *v23[11]; // [rsp+50h] [rbp-58h] BYREF

  v5 = *(long long *)(a1 + 864);
  v23[3] = (char *)__readfsqword(0x28u);
  v18 = 0;
  s = 0;
  v20 = 0;
  v23[0] = 0;
  ptr[0] = 0;
  v21 = 0;
  profile_get_boolean(v5, "options", "log_dir_wait", 0, 0, &v18);
  if ( a3 )
    v20 = string_copy(a1, a3, 0);
  else
    profile_get_string(*(long long *)(a1 + 864), "options", a2, 0, 0, &v20);
  profile_get_string(*(long long *)(a1 + 864), "options", "log_dir", 0, 0, &s);
  v6 = v20;
  if ( !v20 )
  {
    v13 = 0;
    v12 = 0;
    v8 = 0;
    goto LABEL_18;
  }
  if ( !*(char *)v20 )
  {
    v13 = 0;
    v12 = 0;
    v8 = 0;
    goto LABEL_27;
  }
  sub_3D7C0(a1, v20, &v21);
  v7 = s;
  if ( *(char *)v20 != 47 )
  {
    if ( s )
    {
      if ( *s )
      {
        v8 = v21;
        v9 = 0;
LABEL_9:
        v10 = strlen(s);
        v11 = v10 + (unsigned int)strlen(v8) + 2;
        sub_3D790(ptr, v11);
        sub_3CFA0((char **)ptr, s, 0);
        sub_3CFA0((char **)ptr, "/", 1);
        sub_3CFA0((char **)ptr, v8, 0);
        v7 = s;
        v12 = (char *)ptr[0];
        goto LABEL_13;
      }
      v9 = v21;
      goto LABEL_11;
    }
    v9 = v21;
LABEL_30:
    v8 = v9;
    v12 = 0;
    goto LABEL_13;
  }
  v9 = v21;
  if ( !s )
    goto LABEL_30;
LABEL_11:
  v8 = v9;
  if ( *s )
    goto LABEL_9;
  v12 = 0;
LABEL_13:
  free(v7);
  profile_get_string(*(long long *)(a1 + 864), "options", "log_dir_fallback", 0, 0, &s);
  v13 = s;
  if ( s )
  {
    if ( *s )
    {
      v15 = strlen(s);
      v16 = strlen(v8);
      sub_3D790(v23, (unsigned int)(v15 + v16 + 2));
      sub_3CFA0(v23, s, 0);
      sub_3CFA0(v23, "/", 1);
      sub_3CFA0(v23, v8, 0);
      v13 = v23[0];
      __printf_chk(1, "%s\n", v23[0]);
    }
    else
    {
      v13 = 0;
    }
  }
  if ( (!v9 || (v6 = fopen(v9, "w")) == 0)
    && (!v12 || (v6 = fopen(v12, "w")) == 0)
    && (!v13 || (v6 = fopen(v13, "w")) == 0) )
  {
    if ( v18 )
    {
      v6 = sub_3D470(v9, v12, (FILE *)v13);
      goto LABEL_18;
    }
LABEL_27:
    v6 = 0;
  }
LABEL_18:
  v17 = v6;
  free(v8);
  free(v12);
  free(v13);
  free(v20);
  free(s);
  return v17;
}


// Function: set_up_logging @ 0x3dc50
void *set_up_logging(long long a1)
{
  void *v1; // rax
  const char *v2; // rdx
  void *result; // rax

  v1 = sub_3D8D0(a1, (long long)"log_filename", *(const char **)(a1 + 48));
  v2 = *(const char **)(a1 + 64);
  *(long long *)(a1 + 40) = v1;
  result = sub_3D8D0(a1, (long long)"problem_log_filename", v2);
  *(long long *)(a1 + 56) = result;
  return result;
}


// Function: lookup_table @ 0x3dc90
long long lookup_table(int a1, long long a2)
{
  long long result; // rax

  while ( 1 )
  {
    result = *(long long *)(a2 + 8);
    if ( !result || *(int *)a2 == a1 )
      break;
    a2 += 16;
  }
  return result;
}


// Function: lookup_table_fallback @ 0x3dcb0
void *lookup_table_fallback(int a1, long long a2)
{
  void *result; // rax

  result = (void *)sub_3DC90(a1, a2);
  if ( !result )
  {
    __snprintf_chk(&unk_B73A0, 32, 1, 32, "%d", a1);
    byte_B73BF = 0;
    return &unk_B73A0;
  }
  return result;
}


// Function: die_signal_handler @ 0x3dd00
void die_signal_handler(unsigned int a1, long long a2)
{
  const char *v4; // rax
  int v5; // edi
  const char *v6; // rcx
  int v7; // eax
  void *v8; // rsi
  const char *v9; // rax
  const char *v10; // rax
  void *v11[37]; // [rsp+0h] [rbp-128h] BYREF

  v11[33] = (void *)__readfsqword(0x28u);
  v4 = (const char *)sub_3DCB0(a1, (long long)&unk_B6340);
  __fprintf_chk(stderr, 1, "Signal (%d) %s ", a1, v4);
  v5 = *(int *)(a2 + 8);
  if ( !v5 )
  {
    __fprintf_chk(stderr, 1, "(sent from pid %u) ", *(int *)(a2 + 16));
    v5 = *(int *)(a2 + 8);
  }
  v6 = (const char *)sub_3DC90(v5, (long long)&unk_B62A0);
  if ( v6 )
  {
    __fprintf_chk(stderr, 1, "si_code=%s ", v6);
LABEL_5:
    if ( *(int *)(a2 + 8) && a1 <= 0xB && ((0x990uLL >> a1) & 1) != 0 )
LABEL_13:
      __fprintf_chk(stderr, 1, "fault addr=%p", *(const void **)(a2 + 16));
LABEL_8:
    __fprintf_chk(stderr, 1, "\n");
    v7 = backtrace(v11, 32);
    backtrace_symbols_fd(v11, v7, 2);
    exit(8);
  }
  switch ( a1 )
  {
    case 4u:
      v8 = &unk_B61E0;
      goto LABEL_12;
    case 7u:
      v8 = &unk_B60C0;
      goto LABEL_12;
    case 8u:
      v8 = &unk_B6140;
      goto LABEL_12;
    case 0xBu:
      v8 = &unk_B6100;
LABEL_12:
      v9 = (const char *)sub_3DCB0(v5, (long long)v8);
      __fprintf_chk(stderr, 1, "si_code=%s ", v9);
      if ( *(int *)(a2 + 8) )
        goto LABEL_13;
      goto LABEL_8;
    case 0x11u:
      v10 = (const char *)sub_3DCB0(v5, (long long)&unk_B6040);
      __fprintf_chk(stderr, 1, "si_code=%s ", v10);
      goto LABEL_8;
    default:
      __fprintf_chk(stderr, 1, "si code=%d ", v5);
      goto LABEL_5;
  }
}


// Function: sigcatcher_setup @ 0x3df00
unsigned long long sigcatcher_setup()
{
  struct sigaction vars0; // [rsp+0h] [rbp+0h] BYREF
  unsigned long long vars98; // [rsp+98h] [rbp+98h]

  vars98 = __readfsqword(0x28u);
  memset(&vars0.sa_mask, 0, 0x90u);
  vars0.sa_flags = 4;
  vars0.sa_handler = (__sighandler_t)sub_3DD00;
  sigaction(8, &vars0, 0);
  sigaction(4, &vars0, 0);
  sigaction(7, &vars0, 0);
  sigaction(11, &vars0, 0);
  sigaction(6, &vars0, 0);
  return vars98 - __readfsqword(0x28u);
}


// Function: readahead_dir_block @ 0x3dfc0
long long readahead_dir_block(long long a1, long long a2, long long a3)
{
  long long v3; // r12
  long long v5; // rdx
  long long v6; // rcx
  long long v7; // rax

  v3 = 1;
  if ( (*(char *)(a3 + 24) & 1) == 0 )
    v3 = *(long long *)(a2 + 16);
  v5 = *(long long *)(a3 + 16);
  v6 = *(long long *)(a2 + 8);
  if ( v5 )
  {
    if ( v5 + *(long long *)(a3 + 8) == v6 )
    {
      v7 = *(long long *)a3;
      v3 += v5;
      goto LABEL_6;
    }
    v7 = io_channel_cache_readahead(*(long long *)(a1 + 8));
    v6 = *(long long *)(a2 + 8);
    *(long long *)a3 = v7;
  }
  else
  {
    v7 = *(long long *)a3;
  }
  *(long long *)(a3 + 8) = v6;
LABEL_6:
  *(long long *)(a3 + 16) = v3;
  return v7 != 0;
}


// Function: mark_bmap @ 0x3e040
long long mark_bmap(long long a1, unsigned long long a2)
{
  long long v2; // rdx
  long long v3; // rcx
  long long v4; // r8

  if ( ext2fs_get_generic_bmap_start() > a2 || ext2fs_get_generic_bmap_end(a1) < a2 )
    return 2133571399;
  ext2fs_mark_block_bitmap2(a1, a2, v2, v3, v4);
  return 0;
}


// Function: mark_bmap_range @ 0x3e090
long long mark_bmap_range(long long a1, unsigned long long a2, unsigned int a3)
{
  long long v4; // rcx
  long long v5; // r8

  if ( ext2fs_get_generic_bmap_start() > a2 || a2 + a3 > ext2fs_get_generic_bmap_end(a1) )
    return 2133571399;
  ext2fs_mark_block_bitmap_range2(a1, a2, a3, v4, v5);
  return 0;
}


// Function: e2fsck_readahead_bitmap @ 0x3e0f0
long long e2fsck_readahead_bitmap(long long a1, long long a2)
{
  long long v3; // rdi
  long long v4; // rbx
  long long result; // rax
  long long v6; // r15
  long long v7; // r14
  long long v8[9]; // [rsp+0h] [rbp-48h] BYREF

  v3 = *(long long *)(a1 + 32);
  v8[1] = __readfsqword(0x28u);
  v4 = ext2fs_blocks_count(v3) - 1;
  for ( result = ext2fs_find_first_set_block_bitmap2(a2, 1, v4, v8);
        !result;
        result = ext2fs_find_first_set_block_bitmap2(a2, v6, v4, v8) )
  {
    v7 = v8[0];
    result = ext2fs_find_first_zero_block_bitmap2(a2, v8[0], v4, v8);
    if ( result == 2 )
    {
      v8[0] = v4;
      if ( v4 == v7 )
        return 0;
      v6 = v4;
    }
    else
    {
      if ( result )
        return result;
      v6 = v8[0];
    }
    result = io_channel_cache_readahead(*(long long *)(a1 + 8));
    if ( result )
      break;
  }
  if ( result == 2 )
    return 0;
  return result;
}


// Function: e2fsck_readahead_dblist @ 0x3e1d0
long long e2fsck_readahead_dblist(long long a1, int a2, long long a3, long long a4, long long a5)
{
  long long result; // rax
  __int128 v6; // [rsp+0h] [rbp-38h] BYREF
  __int128 v7; // [rsp+10h] [rbp-28h]
  unsigned long long v8; // [rsp+28h] [rbp-10h]

  v8 = __readfsqword(0x28u);
  result = 2133571399;
  if ( (a2 & 0xFFFFFFFE) == 0 )
  {
    v7 = 0;
    DWORD2(v7) = a2;
    v6 = 0;
    result = ext2fs_dblist_iterate3(a3, sub_3DFC0, a4, a5, &v6);
    if ( (long long)v6 )
    {
      return v6;
    }
    else if ( !result )
    {
      if ( (long long)v7 )
        return io_channel_cache_readahead(*(long long *)(a1 + 8));
    }
  }
  return result;
}


// Function: e2fsck_readahead @ 0x3e280
long long e2fsck_readahead(long long a1, int a2, unsigned int a3, int a4)
{
  long long result; // rax
  char v5; // bp
  unsigned int v7; // r14d
  unsigned long long v9; // rsi
  long long v10; // rax
  int v11; // eax
  long long v12; // rcx
  int v13; // edx
  long long v14; // [rsp+8h] [rbp-80h]
  int v15; // [rsp+1Ch] [rbp-6Ch]
  unsigned int v16; // [rsp+24h] [rbp-64h] BYREF
  unsigned long long v17; // [rsp+28h] [rbp-60h] BYREF
  unsigned long long v18; // [rsp+30h] [rbp-58h] BYREF
  unsigned long long v19; // [rsp+38h] [rbp-50h] BYREF
  long long v20[9]; // [rsp+40h] [rbp-48h] BYREF

  v20[1] = __readfsqword(0x28u);
  result = 2133571399;
  v20[0] = 0;
  if ( (a2 & 0xFFFFFFE0) == 0 )
  {
    v5 = a2;
    result = 0;
    if ( a2 )
    {
      v7 = *(int *)(a1 + 48);
      result = ext2fs_allocate_block_bitmap(a1, "readahead bitmap", (long long)v20);
      if ( !result )
      {
        if ( a3 + a4 <= v7 )
          v7 = a3 + a4;
        if ( v7 > a3 )
        {
          do
          {
            v10 = ext2fs_super_and_bgd_loc2(a1, a3, &v17, &v18, &v19, &v16);
            if ( v10 )
              goto LABEL_20;
            if ( (v5 & 1) != 0 )
            {
              v10 = sub_3E040(v20[0], v17);
              if ( v10 )
                goto LABEL_20;
            }
            if ( (v5 & 2) != 0 )
            {
              v9 = v18;
              if ( !v18 )
                v9 = v19;
              v10 = sub_3E090(v20[0], v9, v16);
              if ( v10 )
                goto LABEL_20;
            }
            if ( (v5 & 4) == 0
              || (unsigned int)ext2fs_bg_flags_test(a1, a3, 2)
              || (unsigned int)ext2fs_bg_free_blocks_count(a1, a3) >= *(int *)(*(long long *)(a1 + 32) + 32LL) )
            {
              if ( (v5 & 8) == 0 )
                goto LABEL_15;
            }
            else
            {
              v17 = ext2fs_block_bitmap_loc(a1, a3);
              v10 = sub_3E040(v20[0], v17);
              if ( v10 )
                goto LABEL_20;
              if ( (v5 & 8) == 0 )
                goto LABEL_15;
            }
            if ( !(unsigned int)ext2fs_bg_flags_test(a1, a3, 1)
              && (unsigned int)ext2fs_bg_free_inodes_count(a1, a3) < *(int *)(*(long long *)(a1 + 32) + 40LL) )
            {
              v17 = ext2fs_inode_bitmap_loc(a1, a3);
              v10 = sub_3E040(v20[0], v17);
              if ( v10 )
                goto LABEL_20;
              if ( (v5 & 0x10) == 0 )
                goto LABEL_16;
              goto LABEL_29;
            }
LABEL_15:
            if ( (v5 & 0x10) == 0 )
              goto LABEL_16;
LABEL_29:
            if ( (unsigned int)ext2fs_bg_free_inodes_count(a1, a3) < *(int *)(*(long long *)(a1 + 32) + 40LL) )
            {
              v17 = ext2fs_inode_table_loc(a1, a3);
              v15 = *(int *)(a1 + 72);
              v11 = ext2fs_bg_itable_unused(a1, a3);
              v12 = *(long long *)(a1 + 32);
              v13 = 128;
              if ( *(int *)(v12 + 76) )
                v13 = *(unsigned short *)(v12 + 88);
              v16 = v15 - (unsigned int)(v13 * v11) / *(int *)(a1 + 40);
              v10 = sub_3E090(v20[0], v17, v16);
              if ( v10 )
                goto LABEL_20;
            }
LABEL_16:
            ++a3;
          }
          while ( v7 != a3 );
        }
        v10 = sub_3E0F0(a1, v20[0]);
LABEL_20:
        v14 = v10;
        ext2fs_free_block_bitmap(v20[0]);
        return v14;
      }
    }
  }
  return result;
}


// Function: e2fsck_can_readahead @ 0x3e560
long long e2fsck_can_readahead(long long a1)
{
  return io_channel_cache_readahead(*(long long *)(a1 + 8)) != 2133571457;
}


// Function: e2fsck_guess_readahead @ 0x3e590
unsigned long long e2fsck_guess_readahead(long long a1)
{
  unsigned long long v1; // rbx
  unsigned long long memory_size; // r8
  long long v3; // rax
  unsigned long long v4; // rbx
  bool v5; // cc
  unsigned long long result; // rax

  v1 = *(unsigned int *)(a1 + 72) * (unsigned long long)*(unsigned int *)(a1 + 40);
  memory_size = get_memory_size();
  v3 = 5 * v1;
  v4 = (2 * v1) >> 10;
  v5 = memory_size <= 20 * v3;
  result = 0;
  if ( !v5 )
    return v4;
  return result;
}


// Function: find_blocks @ 0x3e5e0
long long find_blocks(long long a1, long long *a2, long long a3, long long a4, long long a5, long long a6)
{
  unsigned int v6; // eax
  long long *v8; // rdx
  long long v9; // rcx
  long long result; // rax
  long long v11; // rdx
  long long v12; // rcx
  long long v13; // rax
  long long v14; // rdx
  long long v15; // [rsp+8h] [rbp-20h]

  if ( a3 < 0 )
  {
    ++*(long long *)a6;
    ext2fs_block_alloc_stats2(a1, *a2, 0xFFFFFFFFLL);
    return 0;
  }
  v6 = *(int *)(a6 + 16);
  if ( v6 )
  {
    v11 = *(long long *)(a6 + 8) + 24LL * v6 - 24;
    v12 = *(unsigned int *)(v11 + 16);
    if ( v12 + *(long long *)(v11 + 8) == a3 && *(long long *)v11 + v12 == *a2 )
    {
      ++*(int *)(v11 + 16);
      return 0;
    }
  }
  if ( v6 != *(int *)(a6 + 20) )
    goto LABEL_4;
  v15 = a6;
  v13 = ext2fs_resize_mem(0, 24 * v6 + 8184, a6 + 8);
  a6 = v15;
  v14 = v13;
  *(long long *)(v15 + 32) = v13;
  result = 2;
  if ( !v14 )
  {
    *(int *)(v15 + 20) += 341;
    v6 = *(int *)(v15 + 16);
LABEL_4:
    v8 = (long long *)(*(long long *)(a6 + 8) + 24LL * v6);
    v9 = *a2;
    v8[1] = a3;
    *v8 = v9;
    v8[2] = 1;
    *(int *)(a6 + 16) = v6 + 1;
    return 0;
  }
  return result;
}


// Function: rewrite_extent_replay @ 0x3e6e0
long long rewrite_extent_replay(long long *a1, long long a2, long long a3)
{
  long long v5; // rax
  long long stat_i_blocks; // rax
  const __m128i *v8; // r12
  unsigned int v9; // r15d
  long long fixed; // rax
  unsigned int v11; // eax
  long long v12; // rsi
  long long v13; // rax
  long long v14; // [rsp+0h] [rbp-80h]
  long long v15; // [rsp+8h] [rbp-78h]
  long long v16; // [rsp+10h] [rbp-70h]
  long long v17; // [rsp+20h] [rbp-60h] BYREF
  __m128i v18; // [rsp+28h] [rbp-58h] BYREF
  int v19; // [rsp+38h] [rbp-48h]
  int v20; // [rsp+3Ch] [rbp-44h]
  unsigned long long v21; // [rsp+40h] [rbp-40h]

  v21 = __readfsqword(0x28u);
  *(_OWORD *)(a3 + 40) = 0;
  *(_OWORD *)(a3 + 56) = 0;
  *(_OWORD *)(a3 + 72) = 0;
  *(long long *)(a3 + 88) = 0;
  *(int *)(a3 + 96) = 0;
  v5 = *a1;
  *(int *)(a3 + 32) &= ~0x80000u;
  quota_data_sub(a1[79], a3, *(unsigned int *)(a2 + 40), *(long long *)a2 * *(unsigned int *)(v5 + 40));
  v15 = sub_3E5D0(a3);
  v14 = ext2fs_iblk_sub_blocks(*a1, v15);
  if ( !v14 )
  {
    v14 = ext2fs_extent_open2(*a1, *(unsigned int *)(a2 + 40), v15, &v17);
    if ( !v14 )
    {
      stat_i_blocks = ext2fs_get_stat_i_blocks(*a1, v15);
      v8 = *(const __m128i **)(a2 + 8);
      v16 = stat_i_blocks;
      if ( *(int *)(a2 + 16) )
      {
        v9 = 0;
        while ( 1 )
        {
          v11 = v8[1].m128i_u32[0];
          if ( v11 )
          {
            v18 = _mm_loadu_si128(v8);
            v12 = v8[1].m128i_i64[0];
            v19 = v12;
            v20 = BYTE4(v12) & 2;
            if ( (v12 & 0x200000000LL) != 0 )
            {
              if ( v11 > 0x7FFF )
              {
                v19 = 0x7FFF;
                --v9;
                v8->m128i_i64[0] += 0x7FFF;
                v8->m128i_i64[1] += 0x7FFF;
                v8[1].m128i_i32[0] -= 0x7FFF;
                v8 = (const __m128i *)((char *)v8 - 24);
              }
            }
            else if ( v11 > 0x8000 )
            {
              v19 = 0x8000;
              --v9;
              v8->m128i_i64[0] += 0x8000;
              v8->m128i_i64[1] += 0x8000;
              v8[1].m128i_i32[0] -= 0x8000;
              v8 = (const __m128i *)((char *)v8 - 24);
            }
            fixed = ext2fs_extent_insert(v17, 1, &v18);
            if ( fixed )
              break;
            fixed = ext2fs_extent_fix_parents(v17);
            if ( fixed )
              break;
          }
          ++v9;
          v8 = (const __m128i *)((char *)v8 + 24);
          if ( *(int *)(a2 + 16) <= v9 )
            goto LABEL_15;
        }
        v14 = fixed;
      }
      else
      {
LABEL_15:
        v13 = ext2fs_get_stat_i_blocks(*a1, v15) - v16;
        if ( v13 )
          quota_data_add(a1[79], a3, *(unsigned int *)(a2 + 40), v13 << 9);
        e2fsck_write_inode(a1, *(unsigned int *)(a2 + 40), v15, (int)"rebuild_extents");
      }
      ext2fs_extent_free(v17);
    }
  }
  return v14;
}


// Function: rebuild_extent_tree @ 0x3eb00
long long rebuild_extent_tree(long long *a1, long long a2, unsigned int a3)
{
  long long v5; // rsi
  long long v7; // rax
  long long v8; // rcx
  int v9; // r8d
  long long result; // rax
  long long v11; // rdx
  long long v12; // rdi
  long long v13; // r8
  short v14[16]; // [rsp+0h] [rbp-D8h] BYREF
  int v15; // [rsp+20h] [rbp-B8h]
  unsigned long long v16; // [rsp+A8h] [rbp-30h]

  v5 = a3;
  v16 = __readfsqword(0x28u);
  *(int *)(a2 + 40) = a3;
  *(int *)(a2 + 16) = 0;
  *(long long *)a2 = 0;
  *(int *)(a2 + 24) = 0;
  v7 = sub_3E5D0(v14);
  e2fsck_read_inode_full(a1, v5, v7, v8, v9);
  result = 0;
  if ( v14[13] && (v15 & 0x10000000) == 0 )
  {
    v11 = v15 & 0x80000;
    v12 = *a1;
    if ( (int)v11 )
    {
      result = sub_3E940(v12, a2, v11);
      if ( !result )
        return sub_3E6E0(a1, a2, (long long)v14);
    }
    else
    {
      v13 = ext2fs_block_iterate3(v12, a3, 8, 0, sub_3E5E0, a2);
      result = 1;
      if ( !v13 && !*(long long *)(a2 + 32) )
        return sub_3E6E0(a1, a2, (long long)v14) != 0;
    }
  }
  return result;
}


// Function: e2fsck_rebuild_extents @ 0x3eee0
long long e2fsck_rebuild_extents(long long a1, long long a2, long long a3, long long a4, long long a5, long long a6)
{
  long long array; // r13
  long long v7; // rdx
  __int128 v9; // [rsp+0h] [rbp-68h] BYREF
  __int128 v10; // [rsp+10h] [rbp-58h]
  unsigned long long v11; // [rsp+38h] [rbp-30h]

  array = 0;
  v11 = __readfsqword(0x28u);
  if ( (unsigned int)sub_3EC30(
                       *(unsigned int *)(*(long long *)(*(long long *)a1 + 32LL) + 96LL),
                       a2,
                       *(long long *)(*(long long *)a1 + 32LL),
                       a4,
                       a5,
                       a6,
                       0,
                       0,
                       0,
                       0,
                       0,
                       0)
    && (*(char *)(a1 + 76) & 8) == 0
    && ((int)a2 == 2 || *(int *)(v7 + 84) <= (unsigned int)a2) )
  {
    e2fsck_read_bitmaps((long long *)a1);
    array = ext2fs_get_array(341);
    if ( !array )
    {
      DWORD1(v10) = 341;
      array = sub_3EB00((long long *)a1, (long long)&v9, a2);
      ext2fs_free_mem((char *)&v9 + 8);
    }
  }
  return array;
}


// Function: e2fsck_ino_will_be_rebuilt @ 0x3f090
long long e2fsck_ino_will_be_rebuilt(long long a1, long long a2)
{
  long long v2; // rdi

  v2 = *(long long *)(a1 + 928);
  if ( v2 )
    return ext2fs_test_inode_bitmap2(v2, a2);
  else
    return 0;
}


// Function: e2fsck_rewrite_extent_tree @ 0x3f0b0
long long e2fsck_rewrite_extent_tree(long long *a1, long long a2)
{
  long long v2; // r13
  long long v3; // rcx
  long long result; // rax
  char v5[168]; // [rsp+10h] [rbp-D8h] BYREF
  unsigned long long v6; // [rsp+B8h] [rbp-30h]

  v6 = __readfsqword(0x28u);
  memset(v5, 0, 0xA0u);
  v2 = sub_3E5D0(v5);
  result = ext2fs_read_inode_full(*a1, *(unsigned int *)(a2 + 40), v2, v3);
  if ( !result && (v5[35] & 0x10) == 0 )
  {
    result = sub_3E6E0(a1, a2, (long long)v5);
    if ( !result )
    {
      result = ext2fs_count_blocks(*a1, *(unsigned int *)(a2 + 40), v2);
      if ( !result )
      {
        result = ext2fs_iblk_set(*a1, v2);
        if ( !result )
          return ext2fs_write_inode_full(*a1, *(unsigned int *)(a2 + 40), v2, 160);
      }
    }
  }
  return result;
}


// Function: e2fsck_read_extents @ 0x3f1a0
long long e2fsck_read_extents(long long *a1, long long a2)
{
  long long inode; // r12
  long long v3; // rax
  long long v4; // rdx
  long long v6[27]; // [rsp+0h] [rbp-D8h] BYREF

  inode = 12;
  v6[21] = __readfsqword(0x28u);
  *(long long *)a2 = 0;
  *(long long *)(a2 + 8) = 0;
  *(long long *)(a2 + 16) = 0x15500000000LL;
  *(int *)(a2 + 24) = 0;
  if ( !ext2fs_get_array(341) )
  {
    v3 = sub_3E5D0(v6);
    inode = ext2fs_read_inode(*a1, *(unsigned int *)(a2 + 40), v3);
    if ( inode || (inode = sub_3E940(*a1, a2, v4)) != 0 )
    {
      ext2fs_free_mem(a2 + 8);
      *(long long *)(a2 + 16) = 0;
    }
  }
  return inode;
}


// Function: e2fsck_should_rebuild_extents @ 0x3f290
long long e2fsck_should_rebuild_extents(char *a1, long long a2, unsigned int *a3, long long a4)
{
  int v7; // r10d
  unsigned long long v8; // rdx
  long long v9; // rdi
  unsigned int v10; // ecx
  long long v11; // rax
  unsigned int v12; // esi

  if ( a3[1] )
    return e2fsck_rebuild_extents_later(a1, *a3);
  if ( (a1[78] & 1) != 0 )
    return 0;
  v7 = *(int *)(a4 + 16);
  v8 = ((unsigned long long)*(unsigned int *)(*(long long *)a1 + 40LL) - 12) / 0xC;
  if ( v7 < 0 )
    return 0;
  v9 = 0;
  while ( 1 )
  {
    v10 = a3[2 * v9 + 2];
    if ( a3[2 * v9 + 3] - v10 > (unsigned int)v8 )
    {
      v12 = 81927;
      goto LABEL_11;
    }
    v11 = 0;
    if ( v9 )
      break;
LABEL_14:
    if ( v7 < (int)++v9 )
      return 0;
  }
  while ( v10 >= a3[2 * v11 + 3] )
  {
    if ( (int)v9 <= (int)++v11 )
      goto LABEL_14;
  }
  v12 = 81926;
LABEL_11:
  *(long long *)(a2 + 40) = (int)v9;
  if ( (unsigned int)fix_problem((long long)a1, v12, a2) )
    return e2fsck_rebuild_extents_later(a1, *a3);
  else
    return 0;
}


// Function: e2fsck_check_rebuild_extents @ 0x3f360
long long e2fsck_check_rebuild_extents(char *a1, long long a2, long long a3, long long a4)
{
  long long v6; // rdi
  int v7; // eax
  long long v9; // rax
  long long v10; // rdi
  unsigned long long v11; // rax
  long long v12; // rdi
  char v13; // al
  int v14; // esi
  int v15; // edi
  int v16; // ecx
  int *v17; // rdx
  int v18; // r8d
  int v19; // r8d
  long long v20; // [rsp+8h] [rbp-100h] BYREF
  int v21; // [rsp+24h] [rbp-E4h]
  int v22; // [rsp+30h] [rbp-D8h] BYREF
  int v23; // [rsp+34h] [rbp-D4h]
  int v24; // [rsp+38h] [rbp-D0h]
  int v25; // [rsp+3Ch] [rbp-CCh]
  char v26[16]; // [rsp+60h] [rbp-A8h] BYREF
  int v27; // [rsp+70h] [rbp-98h]
  _OWORD v28[3]; // [rsp+90h] [rbp-78h] BYREF
  unsigned long long v29; // [rsp+C8h] [rbp-40h]

  v6 = *(long long *)a1;
  v29 = __readfsqword(0x28u);
  v7 = *(int *)(a3 + 32);
  if ( (v7 & 0x10080000) == 0 && (a1[77] & 0x40) != 0 )
    return e2fsck_rebuild_extents_later(a1, a2);
  if ( (v7 & 0x80000) == 0 )
    return 0;
  memset(v28, 0, sizeof(v28));
  LODWORD(v28[0]) = a2;
  if ( ext2fs_extent_open2(v6, (unsigned int)a2, a3, &v20) )
    return 0;
  if ( !ext2fs_extent_get_info(v20, v26) )
  {
    v9 = v27;
    v10 = v20;
    *(int *)(a4 + 8) = a2;
    *(long long *)(a4 + 40) = v9;
    v11 = ext2fs_max_extent_depth(v10);
    *(long long *)(a4 + 48) = v11;
    if ( v11 < *(long long *)(a4 + 40) )
    {
      if ( (unsigned int)fix_problem((long long)a1, 0x1007Fu, a4) )
        DWORD1(v28[0]) = 1;
      v11 = *(long long *)(a4 + 48);
    }
    *(long long *)(a4 + 40) = 5;
    if ( v11 > 5 )
      fix_problem((long long)a1, 0x14005u, a4);
    if ( (char)a1[77] >= 0 && !ext2fs_extent_get(v20, 1) )
    {
      do
      {
        if ( ext2fs_extent_get_info(v20, &v22) )
          break;
        v13 = v21;
        if ( v22 == 1 && !(DWORD1(v28[0]) | v21 & 4) )
        {
          v14 = v25;
          v15 = v24;
          v16 = v23;
          v17 = (int *)v28 + 2 * v23 + 2;
          v18 = v17[1];
          *v17 += v24;
          v19 = v14 + v18;
          if ( v16 )
          {
            if ( v15 < v14 )
              --v19;
          }
          v17[1] = v19;
        }
        v12 = v20;
        if ( (v13 & 1) != 0 )
        {
          if ( ext2fs_extent_get(v20, 4) )
            break;
          v12 = v20;
        }
      }
      while ( !ext2fs_extent_get(v12, 9) );
    }
  }
  ext2fs_extent_free(v20);
  return e2fsck_should_rebuild_extents(a1, a4, (unsigned int *)v28, (long long)v26);
}


// Function: handle_nomem @ 0x3f610
long long handle_nomem(long long a1, long long a2, long long a3)
{
  *(long long *)(a2 + 80) = a3;
  fix_problem(a1, 0x1007Eu, a2);
  *(int *)(a1 + 72) |= 1u;
  return 0;
}


// Function: fscrypt_context_to_policy @ 0x3f630
long long fscrypt_context_to_policy(char *a1, long long a2, long long a3)
{
  long long result; // rax
  char v5; // di

  result = 4294967294LL;
  if ( a2 )
  {
    v5 = *a1;
    if ( v5 == 1 )
    {
      if ( a2 == 28 )
      {
        *(char *)a3 = 1;
        *(char *)(a3 + 1) = a1[1];
        *(char *)(a3 + 2) = a1[2];
        *(char *)(a3 + 3) = a1[3];
        *(long long *)(a3 + 4) = *(long long *)(a1 + 4);
        return 0;
      }
    }
    else if ( v5 == 2 )
    {
      if ( a2 == 40 )
      {
        *(char *)a3 = 2;
        *(char *)(a3 + 1) = a1[1];
        *(char *)(a3 + 2) = a1[2];
        *(char *)(a3 + 3) = a1[3];
        *(int *)(a3 + 4) = *((int *)a1 + 1);
        result = 0;
        *(__m128i *)(a3 + 8) = _mm_loadu_si128((const __m128i *)(a1 + 8));
      }
    }
    else
    {
      return (unsigned int)(v5 == 0) - 3;
    }
  }
  return result;
}


// Function: cmp_fscrypt_policies @ 0x3f6c0
int cmp_fscrypt_policies(long long *a1, unsigned char *a2, unsigned char *a3)
{
  int v6; // edx
  int v7; // eax

  v6 = *a3;
  v7 = *a2;
  if ( (char)v7 != (char)v6 )
    return v7 - v6;
  if ( (char)v7 == 1 )
    return memcmp(a2, a3, 0xCu);
  if ( (char)v7 != 2 )
    fatal_error(a1, "Unhandled encryption policy version");
  return memcmp(a2, a3, 0x18u);
}


// Function: append_ino_and_policy_id @ 0x3f730
long long append_ino_and_policy_id(long long *a1, long long a2, unsigned int a3, unsigned int a4)
{
  long long *v6; // rbx
  long long v7; // rax
  long long v8; // r15
  unsigned int v9; // eax
  unsigned int *v10; // rax
  unsigned long long v12; // r15
  unsigned long long v13; // rdx

  v6 = (long long *)a1[74];
  v7 = v6[1];
  if ( v7 )
  {
    v8 = *v6 + 12 * v7 - 12;
    v9 = *(int *)(v8 + 4);
    if ( v9 >= a3 )
      fatal_error(a1, "Encrypted inodes processed out of order");
    if ( v9 + 1 == a3 && *(int *)(v8 + 8) == a4 )
    {
      *(int *)(v8 + 4) = a3;
      return 0;
    }
    v7 = v6[1];
  }
  if ( v6[2] != v7 )
  {
LABEL_6:
    v6[1] = v7 + 1;
    v10 = (unsigned int *)(*v6 + 12 * v7);
    *v10 = a3;
    v10[1] = a3;
    v10[2] = a4;
    return 0;
  }
  v12 = **(unsigned int **)(*a1 + 32LL);
  v13 = 2 * v7;
  if ( (unsigned long long)(2 * v7) < 0x80 )
    v13 = 128;
  if ( v12 > v13 )
    v12 = v13;
  if ( v12 < v7 + 1 )
    v12 = v7 + 1;
  if ( !ext2fs_resize_mem(12 * v7, 12 * v12, v6) )
  {
    v6[2] = v12;
    v7 = v6[1];
    goto LABEL_6;
  }
  return sub_3F610((long long)a1, a2, 12 * v12);
}


// Function: get_encryption_policy_id @ 0x3f900
long long get_encryption_policy_id(long long *a1, long long a2, int *a3)
{
  long long v5; // r15
  long long v6; // rdi
  long long v7; // rax
  long long mem; // r12
  long long v10; // r14
  int v11; // eax
  __m128i v12; // xmm0
  long long v13; // rdi
  long long v14; // rax
  long long *v15; // rdx
  int v16; // [rsp+Ch] [rbp-8Ch]
  long long *v17; // [rsp+18h] [rbp-80h]
  char *v18; // [rsp+28h] [rbp-70h] BYREF
  long long v19; // [rsp+30h] [rbp-68h] BYREF
  long long v20; // [rsp+38h] [rbp-60h] BYREF
  __m128i v21; // [rsp+40h] [rbp-58h] BYREF
  long long v22; // [rsp+50h] [rbp-48h]
  unsigned long long v23; // [rsp+58h] [rbp-40h]

  v5 = a1[74];
  v6 = *a1;
  v23 = __readfsqword(0x28u);
  v7 = sub_3F860(v6, a2, &v18, &v19);
  mem = v7;
  if ( v7 != 2133571398 )
  {
    if ( v7 )
    {
      *a3 = -1;
      return 0;
    }
    else
    {
      v16 = sub_3F630(v18, v19, (long long)&v21);
      ext2fs_free_mem(&v18);
      if ( !v16 )
      {
        v10 = *(long long *)(v5 + 24);
        if ( v10 )
        {
          while ( 1 )
          {
            v20 = v10 - 32;
            v11 = sub_3F6C0(a1, (unsigned char *)&v21, (unsigned char *)(v10 - 32));
            v15 = (long long *)(v10 + 16);
            if ( v11 >= 0 )
            {
              if ( !v11 )
              {
                *a3 = *(int *)(v20 + 24);
                return mem;
              }
              v15 = (long long *)(v10 + 8);
            }
            if ( !*v15 )
              goto LABEL_13;
            v10 = *v15;
          }
        }
        v15 = (long long *)(v5 + 24);
LABEL_13:
        v17 = v15;
        mem = ext2fs_get_mem(56, &v20);
        if ( !mem )
        {
          v12 = _mm_load_si128(&v21);
          v13 = v20 + 32;
          v16 = *(int *)(v5 + 32);
          *(int *)(v5 + 32) = v16 + 1;
          v14 = v22;
          *(int *)(v13 - 8) = v16;
          *(long long *)(v13 - 16) = v14;
          *(__m128i *)(v13 - 32) = v12;
          sub_3F5F0(v13, v10, v17);
          ext2fs_rb_insert_color(v13, v5 + 24);
        }
      }
      *a3 = v16;
    }
  }
  return mem;
}


// Function: add_encrypted_file @ 0x3fab0
long long add_encrypted_file(long long *a1, long long a2)
{
  unsigned int v2; // r13d
  long long result; // rax
  long long v4; // rdx
  unsigned int v5; // [rsp+Ch] [rbp-2Ch] BYREF
  long long v6; // [rsp+10h] [rbp-28h]
  unsigned long long v7; // [rsp+18h] [rbp-20h]

  v2 = *(int *)(a2 + 8);
  v7 = __readfsqword(0x28u);
  v6 = a1[74];
  if ( !v6 )
  {
    if ( ext2fs_get_memzero(0x28u) )
      return sub_3F610((long long)a1, a2, 40);
    a1[74] = v6;
  }
  if ( sub_3F900(a1, v2, &v5) )
    return sub_3F610((long long)a1, a2, 0);
  if ( v5 == -1 )
  {
    result = fix_problem((long long)a1, 0x1008Au, a2);
    if ( (int)result )
    {
      v4 = *(long long *)(a2 + 24);
      *(int *)(v4 + 32) &= ~0x800u;
      e2fsck_write_inode(a1, v2, v4, (int)"pass1");
      return 0;
    }
  }
  else if ( v5 == -2 )
  {
    return (unsigned int)-((unsigned int)fix_problem((long long)a1, 0x1008Bu, a2) != 0);
  }
  else
  {
    return sub_3F730(a1, a2, v2, v5);
  }
  return result;
}


// Function: find_encryption_policy @ 0x3fc00
long long find_encryption_policy(long long a1, unsigned int a2)
{
  long long *v2; // r9
  unsigned long long v3; // rcx
  unsigned long long v4; // rdx
  unsigned long long v5; // rax
  unsigned int *v6; // rdi

  v2 = *(long long **)(a1 + 592);
  if ( v2 )
  {
    v3 = v2[1];
    v4 = 0;
    while ( v3 > v4 )
    {
      v5 = v4 + ((v3 - v4) >> 1);
      v6 = (unsigned int *)(*v2 + 12 * v5);
      if ( *v6 <= a2 )
      {
        if ( v6[1] >= a2 )
          return v6[2];
        v4 = v5 + 1;
      }
      else
      {
        v3 = v4 + ((v3 - v4) >> 1);
      }
    }
  }
  return 0xFFFFFFFFLL;
}


// Function: destroy_encryption_policy_map @ 0x3fc60
unsigned long long destroy_encryption_policy_map(long long a1)
{
  long long v1; // rbx
  long long v2; // rdi
  long long v4; // [rsp+0h] [rbp-28h] BYREF
  unsigned long long v5; // [rsp+8h] [rbp-20h]

  v1 = *(long long *)(a1 + 592);
  v5 = __readfsqword(0x28u);
  if ( v1 )
  {
    while ( 1 )
    {
      v2 = *(long long *)(v1 + 24);
      if ( (unsigned int)sub_3FAA0(v2) )
        break;
      v4 = v2 - 32;
      ext2fs_rb_erase(v2, v1 + 24);
      ext2fs_free_mem(&v4);
    }
    *(int *)(v1 + 32) = 0;
  }
  return v5 - __readfsqword(0x28u);
}


// Function: destroy_encrypted_file_info @ 0x3fcf0
unsigned long long destroy_encrypted_file_info(long long a1)
{
  long long v2; // [rsp+0h] [rbp-18h] BYREF
  unsigned long long v3; // [rsp+8h] [rbp-10h]

  v3 = __readfsqword(0x28u);
  v2 = *(long long *)(a1 + 592);
  if ( v2 )
  {
    destroy_encryption_policy_map(a1);
    ext2fs_free_mem(v2);
    ext2fs_free_mem(&v2);
    *(long long *)(a1 + 592) = 0;
  }
  return v3 - __readfsqword(0x28u);
}


// Function: make_u32_list @ 0x48b20
long long make_u32_list(long long a1, int a2, const void *a3, long long *a4)
{
  int v4; // r15d
  long long mem; // r12
  long long v9; // rax
  int *v10; // rdx
  void *v11; // rdi
  size_t v12; // rdx
  long long v13[9]; // [rsp+0h] [rbp-48h] BYREF

  v4 = a1;
  v13[1] = __readfsqword(0x28u);
  mem = ext2fs_get_mem(32, v13);
  if ( !mem )
  {
    v9 = v13[0];
    a1 = (int)a1;
    *(_OWORD *)v13[0] = 0;
    v10 = (int *)v13[0];
    *(_OWORD *)(v9 + 16) = 0;
    *v10 = 2133571330;
    if ( !(int)a1 )
    {
      a1 = 10;
      v4 = 10;
    }
    v10[2] = v4;
    v10[1] = a2;
    mem = ext2fs_get_array(a1);
    if ( mem )
    {
      ext2fs_free_mem(v13);
    }
    else
    {
      v11 = *(void **)(v13[0] + 16LL);
      v12 = 4LL * *(int *)(v13[0] + 8LL);
      if ( a3 )
        memcpy(v11, a3, v12);
      else
        memset(v11, 0, v12);
      *a4 = v13[0];
    }
  }
  return mem;
}


// Function: ext2fs_u32_list_create @ 0x48c30
long long ext2fs_u32_list_create(long long *a1, unsigned int a2)
{
  return sub_48B20(a2, 0, 0, a1);
}


// Function: ext2fs_u32_copy @ 0x48c60
long long ext2fs_u32_copy(long long a1, long long *a2)
{
  long long result; // rax

  result = sub_48B20(*(unsigned int *)(a1 + 8), *(int *)(a1 + 4), *(const void **)(a1 + 16), a2);
  if ( !result )
    *(int *)(*a2 + 24LL) = *(int *)(a1 + 24);
  return result;
}


// Function: ext2fs_badblocks_copy @ 0x48ca0
long long ext2fs_badblocks_copy(long long a1, long long *a2)
{
  return ext2fs_u32_copy(a1, a2);
}


// Function: ext2fs_u32_list_add @ 0x48cb0
long long ext2fs_u32_list_add(long long a1, unsigned int a2)
{
  long long result; // rax
  long long v5; // rdx
  int v6; // eax
  unsigned int *v7; // rsi
  int v8; // edi
  long long v9; // r8
  unsigned int *v10; // rax
  int v11; // ecx
  unsigned int *v12; // rdx
  long long v13; // rsi
  unsigned int v14; // ecx

  result = 2133571330;
  if ( *(int *)a1 != 2133571330 )
    return result;
  v5 = *(int *)(a1 + 4);
  v6 = *(int *)(a1 + 8);
  if ( (int)v5 < v6 )
  {
    v7 = *(unsigned int **)(a1 + 16);
    if ( (int)v5 )
      goto LABEL_4;
LABEL_12:
    *(int *)(a1 + 4) = v5 + 1;
    result = 0;
    v7[v5] = a2;
    return result;
  }
  *(int *)(a1 + 8) = v6 + 100;
  result = ext2fs_resize_mem(4LL * v6, 4LL * v6 + 400, a1 + 16);
  if ( result )
  {
    *(int *)(a1 + 8) -= 100;
    return result;
  }
  v5 = *(int *)(a1 + 4);
  v7 = *(unsigned int **)(a1 + 16);
  if ( !(int)v5 )
    goto LABEL_12;
LABEL_4:
  v8 = v5 - 1;
  result = 0;
  v9 = (int)v5 - 1;
  if ( v7[v9] == a2 )
    return result;
  if ( v7[v8] < a2 )
    goto LABEL_12;
  v10 = v7;
  v11 = 0;
  if ( (int)v5 > 0 )
  {
    while ( 1 )
    {
      if ( *v10 == a2 )
        return 0;
      if ( *v10 > a2 )
        break;
      ++v11;
      ++v10;
      if ( v11 == (int)v5 )
        goto LABEL_19;
    }
    if ( (int)v5 > v11 )
    {
      v12 = &v7[v9 + 1];
      v13 = (long long)&v7[v9 - (unsigned int)(v8 - v11)];
      do
      {
        v14 = *--v12;
        v12[1] = v14;
      }
      while ( (unsigned int *)v13 != v12 );
    }
  }
  else
  {
LABEL_19:
    v10 = &v7[v9 + 1];
  }
  *v10 = a2;
  ++*(int *)(a1 + 4);
  return 0;
}


// Function: ext2fs_badblocks_list_add @ 0x48de0
long long ext2fs_badblocks_list_add(long long a1, unsigned int a2)
{
  return ext2fs_u32_list_add(a1, a2);
}


// Function: ext2fs_u32_list_find @ 0x48df0
long long ext2fs_u32_list_find(long long a1, unsigned int a2)
{
  int v2; // edx
  int *v3; // r9
  signed int v4; // edx
  unsigned int v5; // r8d
  signed int v6; // ecx
  unsigned int v7; // eax

  if ( *(int *)a1 != 2133571330 )
    return (unsigned int)-1;
  v2 = *(int *)(a1 + 4);
  if ( !v2 )
    return (unsigned int)-1;
  v3 = *(int **)(a1 + 16);
  v4 = v2 - 1;
  v5 = 0;
  if ( *v3 != a2 )
  {
    v5 = v4;
    v6 = 0;
    if ( v3[v4] != a2 )
    {
      while ( v6 < v4 )
      {
        v7 = (unsigned int)(v6 + v4) >> 1;
        v5 = v7;
        if ( v6 == v7 || v4 == v7 )
          break;
        if ( v3[v7] == a2 )
          return v5;
        if ( v3[v7] > a2 )
          v4 = (unsigned int)(v6 + v4) >> 1;
        else
          v6 = (unsigned int)(v6 + v4) >> 1;
      }
      return (unsigned int)-1;
    }
  }
  return v5;
}


// Function: ext2fs_u32_list_test @ 0x48e60
long long ext2fs_u32_list_test(long long a1, unsigned int a2)
{
  return (int)ext2fs_u32_list_find(a1, a2) >= 0;
}


// Function: ext2fs_badblocks_list_test @ 0x48e70
long long ext2fs_badblocks_list_test(long long a1, unsigned int a2)
{
  return ext2fs_u32_list_test(a1, a2);
}


// Function: ext2fs_u32_list_del @ 0x48e80
long long ext2fs_u32_list_del(long long a1, unsigned int a2)
{
  long long v2; // rax
  int v3; // r10d
  long long v4; // r11
  int v5; // edx
  long long v6; // rcx

  if ( !*(int *)(a1 + 4) )
    return 0xFFFFFFFFLL;
  LODWORD(v2) = ext2fs_u32_list_find(a1, a2);
  if ( (int)v2 < 0 )
    return 0xFFFFFFFFLL;
  v5 = v3 - 1;
  if ( (int)v2 < v3 - 1 )
  {
    v6 = *(long long *)(v4 + 16);
    v2 = (int)v2;
    do
    {
      *(int *)(v6 + 4 * v2) = *(int *)(v6 + 4 * v2 + 4);
      ++v2;
      v5 = *(int *)(v4 + 4) - 1;
    }
    while ( v5 > (int)v2 );
  }
  *(int *)(v4 + 4) = v5;
  return 0;
}


// Function: ext2fs_badblocks_list_del @ 0x48ee0
long long ext2fs_badblocks_list_del(long long a1, unsigned int a2)
{
  return ext2fs_u32_list_del(a1, a2);
}


// Function: ext2fs_u32_list_iterate_begin @ 0x48ef0
long long ext2fs_u32_list_iterate_begin(int *a1, long long *a2)
{
  long long result; // rax
  long long v3; // rdx
  long long v4[5]; // [rsp+0h] [rbp-28h] BYREF

  v4[1] = __readfsqword(0x28u);
  result = 2133571330;
  if ( *a1 == 2133571330 )
  {
    result = ext2fs_get_mem(24, v4);
    if ( !result )
    {
      v3 = v4[0];
      *(int *)v4[0] = 2133571331;
      *(long long *)(v3 + 8) = a1;
      *(int *)(v3 + 16) = 0;
      *a2 = v3;
    }
  }
  return result;
}


// Function: ext2fs_badblocks_list_iterate_begin @ 0x48f70
long long ext2fs_badblocks_list_iterate_begin(int *a1, long long *a2)
{
  return ext2fs_u32_list_iterate_begin(a1, a2);
}


// Function: ext2fs_u32_list_iterate @ 0x48f80
long long ext2fs_u32_list_iterate(long long a1, int *a2)
{
  long long result; // rax
  long long v3; // rdx
  long long v4; // rcx
  long long v5; // rax

  result = 0;
  if ( *(int *)a1 == 2133571331 )
  {
    v3 = *(long long *)(a1 + 8);
    if ( *(int *)v3 == 2133571330 )
    {
      v4 = *(int *)(a1 + 16);
      if ( (int)v4 < *(int *)(v3 + 4) )
      {
        v5 = *(long long *)(v3 + 16);
        *(int *)(a1 + 16) = v4 + 1;
        *a2 = *(int *)(v5 + 4 * v4);
        return 1;
      }
      else
      {
        *a2 = 0;
      }
    }
  }
  return result;
}


// Function: ext2fs_badblocks_list_iterate @ 0x48fd0
long long ext2fs_badblocks_list_iterate(long long a1, int *a2)
{
  return ext2fs_u32_list_iterate(a1, a2);
}


// Function: ext2fs_u32_list_iterate_end @ 0x48fe0
long long ext2fs_u32_list_iterate_end(long long a1)
{
  long long result; // rax
  long long v2; // [rsp+8h] [rbp-10h] BYREF

  v2 = a1;
  if ( a1 )
  {
    if ( *(int *)a1 == 2133571331 )
    {
      *(long long *)(a1 + 8) = 0;
      return ext2fs_free_mem(&v2);
    }
  }
  return result;
}


// Function: ext2fs_badblocks_list_iterate_end @ 0x49020
long long ext2fs_badblocks_list_iterate_end(long long a1)
{
  return ext2fs_u32_list_iterate_end(a1);
}


// Function: ext2fs_u32_list_equal @ 0x49030
long long ext2fs_u32_list_equal(const void **a1, long long a2)
{
  long long result; // rax
  long long v3; // rdx

  result = *(unsigned int *)a1;
  if ( (int)result != 2133571330 )
    return 2133571330;
  if ( *(int *)a2 == 2133571330 )
  {
    v3 = *((int *)a1 + 1);
    result = 0;
    if ( (int)v3 == *(int *)(a2 + 4) )
      return memcmp(a1[2], *(const void **)(a2 + 16), 4 * v3) == 0;
  }
  return result;
}


// Function: ext2fs_badblocks_equal @ 0x49090
long long ext2fs_badblocks_equal(const void **a1, long long a2)
{
  return ext2fs_u32_list_equal(a1, a2);
}


// Function: ext2fs_u32_list_count @ 0x490a0
long long ext2fs_u32_list_count(long long a1)
{
  return *(unsigned int *)(a1 + 4);
}


