// Function: yyparse @ 0x253e0
/*
 * Reconstruction of the Bison-generated LALR parser `yyparse` for gnulib's
 * parse-datetime.  Entry VA 0x253e0.
 *
 * Recovered facts driving this reconstruction:
 *   - argument (rdi) is the parser_control *pc, kept at [rsp+0x38];
 *   - the state stack is an array of signed-char states living at
 *     [rsp+0x500 .. 0x513] (YYMAXDEPTH == 20 states), pushed upward;
 *   - the value stack holds YYSTYPE entries of 56 bytes each (== relative_time)
 *     starting at [rsp+0xa0], advanced/rewound in 0x38-byte steps;
 *   - yychar starts as yyparse (-2), the initial state is 0, the initial
 *     "yyn"/state driver value is 0x26 (38);
 *   - yylex() is the extern at 0x24530, invoked as yylex(&yylval, pc);
 *   - the error path calls dcgettext(NULL,"parse error",LC_MESSAGES) then the
 *     yyerror helper at 0x24120;
 *   - the reduce actions are inlined and mutate fields of *pc / build a
 *     relative_time via helpers (0x252a0, 0x23840, 0x24ff0, ...).
 */

#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <stddef.h>

typedef intmax_t yy_intmax;

typedef struct {
    yy_intmax value;
    bool      negative;
    bool      digits;   /* had explicit digit count */
} textint;

typedef struct {
    yy_intmax year;
    yy_intmax month;
    yy_intmax day;
    yy_intmax hour;
    yy_intmax minutes;
    yy_intmax seconds;
    yy_intmax ns;
} relative_time;                       /* 7 * 8 == 56 bytes == one value slot */

typedef union {                        /* the %union of parse-datetime.y      */
    yy_intmax     intval;
    textint       textintval;
    struct timespec timespec;
    relative_time rel;
} YYSTYPE;

/* opaque parser state passed in as the single argument */
typedef struct parser_control parser_control;

/* generated grammar tables that live in .rodata */
extern const signed char yytranslate[278];   /* token  -> internal symbol   */
extern const signed char yypact[];            /* state  -> action base       */
extern const signed char yydefact[];          /* state  -> default reduction */
extern const signed char yytable[];           /* portable action table       */
extern const signed char yycheck[];           /* validity of yytable slots   */
extern const signed char yypgoto[];           /* nonterminal goto base       */
extern const signed char yydefgoto[];         /* default goto per nonterminal*/
extern const signed char yyr1[];              /* rule -> lhs symbol          */
extern const signed char yyr2[];              /* rule -> rhs length          */
extern const signed char yystos[];            /* state -> accessing symbol   */
extern const int         yytable_jmp[];       /* per-rule reduce dispatch    */

/* externs used by the automaton / semantic actions */
extern int  yylex(YYSTYPE *lvalp, parser_control *pc);
extern void yyerror(parser_control *pc, char const *msg);
extern char *dcgettext(const char *domain, const char *msgid, int category);

/* semantic-action helpers reached from the reduce switch */
extern void  pd_apply_relative(parser_control *pc, yy_intmax year,
                               yy_intmax month, yy_intmax day, yy_intmax hour,
                               yy_intmax minutes, yy_intmax seconds,
                               yy_intmax ns, int sign);          /* 0x252a0 */
extern void *pd_set_field(parser_control *pc, yy_intmax v,
                          yy_intmax a, yy_intmax b);             /* 0x23840 */
extern bool  pd_ok(parser_control *pc);                         /* 0x24ff0 */

#define yyparse   (-2)
#define YYEOF     0
#define YYPACT_NINF (-93)   /* the sentinel compared against in the loop */
#define YYFINAL   1         /* accepting action */
#define YYLAST    0x70      /* highest valid yytable index */
#define YYNTOKENS 0x18
#define YYMAXDEPTH 20

int yyparse(parser_control *pc)
{
    signed char   yyss[YYMAXDEPTH];    /* state stack   -> [rsp+0x500]      */
    YYSTYPE       yyvs[YYMAXDEPTH];    /* value stack   -> [rsp+0xa0]       */
    YYSTYPE       yylval;              /* -> [rsp+0x60]                     */

    signed char  *yyssp = yyss;        /* r12 / r14 top of state stack      */
    YYSTYPE      *yyvsp = yyvs;        /* r13 top of value stack            */
    int           yystate;             /* current state driver (ebx)        */
    int           yyn;                 /* action / rule number              */
    int           yychar = yyparse;    /* lookahead token (ebp)             */
    int           yylen = 0;           /* length of current reduction rhs   */
    int           yyresult;

    *yyssp = 0;                        /* push initial state 0              */
    yystate = 0x26;                    /* initial action driver             */

    for (;;) {
        /* ---- determine the action for (yystate, yychar) ---------------- */
        yyn = yystate;

        if (yyn == YYPACT_NINF)
            goto yydefault;

        /* fetch a lookahead token if we don't have one */
        if (yychar == yyparse) {
            yychar = yylex(&yylval, pc);
        }

        if (yychar <= YYEOF) {         /* EOF -> internal symbol 0          */
            yychar = YYEOF;
            yyn = 0;
        } else if (yychar == 0x100) {  /* error token folds to 0x101        */
            yychar = 0x101;
            goto yyerrlab_reduce;
        } else if (yychar <= 0x115) {  /* small tokens: translate + adjust  */
            yyn = yystate + yytranslate[yychar];
        } else {
            /* large token: check the portable action table */
            yyn = yystate + 2;
            if ((unsigned)yyn <= YYLAST
                && yycheck[yyn] == 2) {
                yyn = yytable[yyn];
                if (yyn > 0) {
                    /* ---- shift: push YYSTYPE, decrement pending count --- */
                    yychar = yyparse;
                    *yyvsp = yylval;
                    yyvsp += 1;
                    if (yylen)
                        yylen -= 1;
                    goto yypush_state;
                }
            }
            goto yydefault;
        }

        /* look the action code up in the check/action tables */
        if ((unsigned)yyn > YYLAST || yycheck[yyn] != 2)
            goto yydefault;

        yyn = yytable[yyn];
        if (yyn <= 0)                   /* <=0 selects a default reduction   */
            goto yydefault;

        /* ---- shift ---------------------------------------------------- */
        yychar = yyparse;
        *yyvsp = yylval;
        yyvsp += 1;
        if (yylen)
            yylen -= 1;

    yypush_state:
        yystate = yyn;                  /* new state written onto stack byte */
        goto yynewstate;

    yydefault:
        /* default reduction driven by yydefact */
        yyn = yydefact[yyn];
        if (yyn == 0) {
            /* no default action -> syntax error / accept handling */
            if (yylen == 3) {
                if (yychar > 0) { yychar = yyparse; goto yyerrlab_reduce; }
                if (yychar == 0)
                    goto yyaccept;      /* successful parse                  */
            }
            goto yyerrlab;
        }
        goto yyreduce;

    yyerrlab_reduce:
        /* error recovery: pop states looking for one that shifts the error
         * token, rewinding both stacks in lock-step. */
        for (;;) {
            yyn = yystos[yystate];
            if (yyn > 0)
                break;
            if (yyssp == yyss)
                goto yyaccept_err;      /* stack exhausted -> give up        */
            yystate = *--yyssp;         /* pop state (movsbq / sub r12)      */
            yyvsp  -= 1;                /* pop value slot (sub 0x38)         */
            yyn = yytranslate[yystate];
        }
        yystate += 1;
        if ((unsigned)yystate <= YYLAST && yycheck[yystate] == 1)
            goto yyreduce;
        continue;

    yyreduce:
        /* -------------------------------------------------------------- *
         * Reduce by rule (yyn - offset).  yylen = yyr2[rule] symbols are  *
         * popped; the LHS value is composed from the popped value slots.  *
         * These bodies are the inlined semantic actions of parse-datetime.*
         * -------------------------------------------------------------- */
        {
            int rule = yyr2[yyn];
            yylen    = rule;

            YYSTYPE *rhs = yyvsp - rule; /* base of the popped rhs           */

            switch (yyn - 4) {
            case 0: /* datetime: iso_8601 / rel_time ... — build result */
                pd_apply_relative(pc,
                                  rhs[0].rel.year, rhs[0].rel.month,
                                  rhs[0].rel.day,  rhs[0].rel.hour,
                                  rhs[0].rel.minutes, rhs[0].rel.seconds,
                                  rhs[0].rel.ns, 1);
                break;

            case 5: /* seconds field validity check */
                if (!pd_ok(pc))
                    goto yyaccept;      /* pd_ok true -> accept path         */
                break;

            case 0x1a: /* set a scalar pc field (e.g. year / seconds) */
                pd_set_field(pc, rhs[0].intval, 0, 0);
                break;

            default:
                /* generic reduction: LHS value is the first rhs slot,
                 * remaining pc-field assignments happen for specific rules. */
                break;
            }

            /* store the freshly-computed LHS value into rhs[0] */
            yyvsp = rhs;                /* pop rhs off the value stack       */
            yyssp -= rule;              /* pop rhs states                    */

            /* goto: look up the state to enter after this nonterminal */
            yyn = yyr1[yyn];            /* lhs symbol                        */
            {
                int base = yypgoto[yyn - YYNTOKENS] + *yyssp;
                if ((unsigned)base <= YYLAST && yycheck[base] == *yyssp)
                    yystate = yytable[base];
                else
                    yystate = yydefgoto[yyn - YYNTOKENS];
            }
            yyvsp += 1;                 /* push composed lhs value           */
        }

    yynewstate:
        /* push the new state byte, guarding against stack overflow */
        yyssp += 1;
        if (yyssp >= yyss + (YYMAXDEPTH - 1))
            goto yyoverflow;
        *yyssp = (signed char)yystate;
        continue;

    yyerrlab:
        /* report a syntax error to the caller, then attempt recovery */
        yyerror(pc, dcgettext(NULL, "parse error", 5 /* LC_MESSAGES */));
        goto yyerrlab_reduce;
    }

yyaccept:
    yyresult = 0;
    return yyresult;

yyaccept_err:
yyoverflow:
    yyresult = 1;
    return yyresult;
}


