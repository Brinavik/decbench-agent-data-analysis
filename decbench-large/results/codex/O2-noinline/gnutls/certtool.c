// Function: yyparse @ 0x253e0
int
yyparse(void *arg)
{
  typedef long int intmax_t;
  typedef union
  {
    intmax_t word[7];
    unsigned char bytes[56];
  } YYSTYPE;
  typedef struct
  {
    intmax_t word[3];
  } three_word_value;

  static const unsigned char yyr2[92] = {
    0,2,1,1,2,0,2,1,1,1,1,1,1,1,1,1,
    1,3,2,4,6,1,2,4,6,0,1,2,1,2,1,1,
    2,2,3,1,2,1,2,2,2,3,5,3,3,2,4,2,
    3,1,3,2,1,1,2,2,1,2,2,1,2,2,1,2,
    2,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,
    2,1,1,1,1,1,1,1,1,2,0,2
  };
  static const unsigned char yyr1[92] = {
    0,28,29,29,30,31,31,32,32,32,32,32,32,32,32,32,
    33,34,35,35,35,35,36,36,36,37,37,38,39,39,40,40,
    40,40,40,40,40,41,41,41,41,42,42,42,42,42,42,42,
    42,42,43,44,44,44,45,45,45,45,45,45,45,45,45,45,
    45,45,45,45,45,45,45,45,45,45,45,46,46,46,46,46,
    46,47,48,48,49,49,50,50,51,52,53,53
  };
  static const signed char yypact[113] = {
    27,5,6,7,8,9,10,4,12,15,102,15,16,19,15,19,
    19,20,19,25,112,25,19,27,5,6,7,8,9,10,5,6,
    7,8,9,10,19,19,19,107,19,20,25,25,25,113,19,20,
    21,22,25,5,6,7,8,9,10,11,12,13,14,23,16,17,
    18,19,20,21,22,96,24,5,6,7,8,9,10,0,12,5,
    6,7,8,9,10,25,4,27,26,20,30,22,9,9,19,24,
    3,19,26,20,20,20,59,27,84,20,20,-1,20,20,19,-1,
    25
  };
  static const signed char yycheck[113] = {
    79,67,68,69,70,71,72,58,73,100,107,74,75,101,110,76,
    49,50,101,102,113,77,59,78,61,62,63,64,65,66,61,62,
    63,64,65,66,101,101,92,111,90,91,106,112,88,111,5,6,
    7,8,88,13,14,15,16,17,18,19,20,21,22,1,23,24,
    25,26,27,28,29,79,30,51,52,53,54,55,56,12,57,61,
    62,63,64,65,66,60,48,80,47,6,83,8,81,82,26,84,
    85,86,87,94,95,96,89,105,97,98,99,0,108,109,101,0,
    88
  };
  static const unsigned char yydefgoto[26] = {
    0,2,3,4,31,32,33,34,35,103,104,36,37,38,39,40,
    41,42,43,44,9,10,11,45,46,93
  };
  static const signed char yypgoto[26] = {
    -93,-93,-93,-93,-93,-93,-93,-93,20,-68,-27,-93,-93,
    -93,-93,-93,-93,-93,60,-93,-93,-93,-92,-93,-93,43
  };
  static const unsigned char yydefact[113] = {
    5,0,0,2,3,85,87,84,86,4,82,83,1,56,59,65,
    68,73,62,81,37,35,28,0,0,30,0,88,0,0,31,6,
    7,16,8,21,9,10,12,11,49,13,52,74,53,14,15,38,
    29,0,45,54,57,63,66,69,60,39,36,90,32,75,76,78,
    79,80,77,55,58,64,67,70,61,40,18,47,90,0,0,22,
    89,71,72,33,0,51,44,0,0,34,43,48,50,27,25,41,
    0,17,46,91,19,90,0,23,26,0,0,25,42,25,20,24,0
  };
  static const signed char yytable[113] = {
    38,27,77,-93,46,-93,-93,-93,-93,-93,-93,-93,-93,-93,-93,-93,
    -93,-93,-93,-93,62,-93,82,-3,66,3,74,-4,83,84,75,-93,
    -93,-93,-93,-93,-93,-93,-93,-93,71,-93,93,-93,-93,-93,-93,-93,
    -93,78,72,-93,-93,-93,-93,-93,-93,-93,-93,25,-93,-93,-93,-93,
    -93,-93,-93,-93,-93,-93,-93,-93,-93,-93,-93,21,19,79,80,-93,
    -93,-93,-93,-93,81,-93,-93,85,86,-93,-93,-93,-93,-93,-6,76,
    17,-93,-93,-93,-93,87,69,-93,-93,88,89,-1,-93,18,-93,-93,69
  };
  static const unsigned char yytranslate[278] = {
    0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,26,2,2,27,
    2,2,2,2,2,2,2,2,2,2,25,2,2,2,2,2,
    23,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,24,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,
    17,18,19,20,21,22
  };

  extern int yylex(YYSTYPE *, void *);
  extern void digits_to_date_time(void *, three_word_value);
  extern int apply_relative_time(void *, intmax_t, intmax_t, intmax_t,
                                 intmax_t, intmax_t, intmax_t, int, int);
  extern int time_zone_hhmm(void *, unsigned char, intmax_t, intmax_t,
                            intmax_t);

  unsigned char *pc = (unsigned char *) arg;
  signed char state_stack[20];
  YYSTYPE value_stack[20];
  signed char *yyssp = state_stack;
  YYSTYPE *yyvsp = value_stack;
  YYSTYPE yylval;
  YYSTYPE yyval;
  int yychar = -2;
  int yytoken = 0;
  int yystate = 0;
  int yyerrstatus = 0;
  int yyn;
  int yylen;

#define I64(Off) (*(intmax_t *)(pc + (Off)))
#define I32(Off) (*(int *)(pc + (Off)))
#define U8(Off)  (*(unsigned char *)(pc + (Off)))
#define OVERFLOW_ADD(A, B, Out)                                            \
  (((__int128)(A) + (__int128)(B) > (__int128)0x7fffffffffffffffL          \
    || (__int128)(A) + (__int128)(B) < -((__int128)0x7fffffffffffffffL)-1) \
   ? 1 : (*(Out) = (A) + (B), 0))
#define OVERFLOW_MUL(A, B, Out)                                            \
  (((__int128)(A) * (__int128)(B) > (__int128)0x7fffffffffffffffL          \
    || (__int128)(A) * (__int128)(B) < -((__int128)0x7fffffffffffffffL)-1) \
   ? 1 : (*(Out) = (A) * (B), 0))

  *yyssp = 0;

  for (;;)
    {
      int index;

      if (yystate == 12)
        return 0;

      yyn = yypact[yystate];
      if (yyn != -93)
        {
          if (yychar == -2)
            yychar = yylex(&yylval, pc);

          if (yychar <= 0)
            {
              yychar = 0;
              yytoken = 0;
            }
          else
            yytoken = yychar <= 277 ? yytranslate[yychar] : 2;

          index = yyn + yytoken;
          if ((unsigned int) index <= 112 && yycheck[index] == yytoken)
            {
              yyn = yytable[index];
              if (yyn > 0)
                {
                  if (yyn == 256)
                    goto syntax_error;
                  if (++yyssp == state_stack + 19)
                    return 2;
                  *yyssp = (signed char) yyn;
                  *++yyvsp = yylval;
                  yystate = yyn;
                  yychar = -2;
                  if (yyerrstatus)
                    --yyerrstatus;
                  continue;
                }
              if (yyn != 0 && yyn != -93)
                {
                  yyn = -yyn;
                  goto reduce;
                }
              goto syntax_error;
            }
        }

      yyn = yydefact[yystate];
      if (yyn == 0)
        goto syntax_error;

reduce:
      yylen = yyr2[yyn];
      yyval = yyvsp[1 - yylen];

      switch (yyn)
        {
        case 4:
          U8(0xa0) = 1;
          I64(0x58) = yyvsp[0].word[0];
          I64(0x60) = yyvsp[0].word[1];
          break;

        case 7:
          ++I64(0xc8);
          ++I64(0xa8);
          break;
        case 8:  ++I64(0xc8); break;
        case 9:  ++I64(0xb8); break;
        case 10: ++I64(0xd0); break;
        case 11: ++I64(0xa8); break;
        case 12: ++I64(0xb0); break;

        case 18:
          I64(0x48) = yyvsp[-1].word[1];
          I64(0x50) = 0;
          I64(0x58) = 0;
          I64(0x60) = 0;
          I32(0x1c) = (int) yyvsp[0].word[0];
          break;
        case 19:
          I64(0x48) = yyvsp[-3].word[1];
          I64(0x50) = yyvsp[-1].word[1];
          I64(0x58) = 0;
          I64(0x60) = 0;
          I32(0x1c) = (int) yyvsp[0].word[0];
          break;
        case 20:
          I64(0x48) = yyvsp[-5].word[1];
          I64(0x50) = yyvsp[-3].word[1];
          I64(0x58) = yyvsp[-1].word[0];
          I64(0x60) = (int) yyvsp[-1].word[1];
          I32(0x1c) = (int) yyvsp[0].word[0];
          break;
        case 22:
          I64(0x48) = yyvsp[-1].word[1];
          I64(0x50) = 0;
          I64(0x58) = 0;
          I64(0x60) = 0;
          I32(0x1c) = 2;
          break;
        case 23:
          I64(0x48) = yyvsp[-3].word[1];
          I64(0x50) = yyvsp[-1].word[1];
          I64(0x58) = 0;
          I64(0x60) = 0;
          I32(0x1c) = 2;
          break;
        case 24:
          I64(0x48) = yyvsp[-5].word[1];
          I64(0x50) = yyvsp[-3].word[1];
          I64(0x58) = yyvsp[-1].word[0];
          I64(0x60) = (int) yyvsp[-1].word[1];
          I32(0x1c) = 2;
          break;

        case 27:
          ++I64(0xd0);
          if (!time_zone_hhmm(pc, (unsigned char) yyvsp[-1].word[0],
                              yyvsp[-1].word[1], yyvsp[-1].word[2],
                              yyvsp[0].word[0]))
            return 1;
          break;
        case 28: I32(0x14) = (int) yyvsp[0].word[0]; break;
        case 29: ++I64(0xc0); I32(0x14) = 1; break;
        case 30: I32(0x18) = (int) yyvsp[0].word[0]; break;
        case 31: I32(0x18) = -25200; break;
        case 32:
          I32(0x18) = (int) yyvsp[-1].word[0];
          if (!apply_relative_time(pc, yyvsp[0].word[0], yyvsp[0].word[1],
                                   yyvsp[0].word[2], yyvsp[0].word[3],
                                   yyvsp[0].word[4], yyvsp[0].word[5],
                                   (int) yyvsp[0].word[6], 1))
            return 1;
          break;
        case 33:
          I32(0x18) = -25200;
          if (!apply_relative_time(pc, yyvsp[0].word[0], yyvsp[0].word[1],
                                   yyvsp[0].word[2], yyvsp[0].word[3],
                                   yyvsp[0].word[4], yyvsp[0].word[5],
                                   (int) yyvsp[0].word[6], 1))
            return 1;
          break;
        case 34:
          if (!time_zone_hhmm(pc, (unsigned char) yyvsp[-2].word[0],
                              yyvsp[-2].word[1], yyvsp[-2].word[2],
                              yyvsp[0].word[0]))
            return 1;
          {
            intmax_t v;
            if (OVERFLOW_ADD((intmax_t) I32(0x18), yyvsp[-2].word[0], &v)
                || (int) v != v)
              return 1;
            I32(0x18) = (int) v;
          }
          break;
        case 35: I32(0x18) = (int) yyvsp[0].word[0] + 3600; break;
        case 36: I32(0x18) = (int) yyvsp[-1].word[0] + 3600; break;
        case 37: I64(0x08) = 0; I32(0x10) = (int) yyvsp[0].word[0]; break;
        case 38: I64(0x08) = 0; I32(0x10) = (int) yyvsp[-1].word[0]; break;
        case 39:
          I64(0x08) = yyvsp[-1].word[0];
          U8(0xdf) = 1;
          I32(0x10) = (int) yyvsp[0].word[0];
          break;
        case 40:
          I64(0x08) = yyvsp[-1].word[1];
          U8(0xdf) = 1;
          I32(0x10) = (int) yyvsp[0].word[0];
          break;

        case 41:
          I64(0x38) = yyvsp[-2].word[1];
          I64(0x40) = yyvsp[0].word[1];
          break;
        case 42:
          if (yyvsp[-4].word[2] <= 3)
            {
              I64(0x20) = yyvsp[0].word[0];
              I64(0x28) = yyvsp[0].word[1];
              I64(0x30) = yyvsp[0].word[2];
              I64(0x38) = yyvsp[-4].word[1];
              I64(0x40) = yyvsp[-2].word[1];
            }
          else
            {
              I64(0x20) = yyvsp[-4].word[0];
              I64(0x28) = yyvsp[-4].word[1];
              I64(0x30) = yyvsp[-4].word[2];
              I64(0x38) = yyvsp[-2].word[1];
              I64(0x40) = yyvsp[0].word[1];
            }
          break;
        case 43:
          I64(0x38) = yyvsp[-1].word[0];
          I64(0x40) = yyvsp[-2].word[1];
          I64(0x28) = -yyvsp[0].word[1];
          I64(0x30) = yyvsp[0].word[2];
          if (yyvsp[0].word[1] == (-0x7fffffffffffffffL - 1)) return 1;
          break;
        case 44:
          I64(0x38) = yyvsp[-2].word[0];
          I64(0x40) = -yyvsp[-1].word[1];
          I64(0x28) = -yyvsp[0].word[1];
          I64(0x30) = yyvsp[0].word[2];
          if (yyvsp[-1].word[1] == (-0x7fffffffffffffffL - 1)
              || yyvsp[0].word[1] == (-0x7fffffffffffffffL - 1))
            return 1;
          break;
        case 45:
          I64(0x38) = yyvsp[-1].word[0];
          I64(0x40) = yyvsp[0].word[1];
          break;
        case 46:
          I64(0x20) = yyvsp[0].word[0];
          I64(0x28) = yyvsp[0].word[1];
          I64(0x30) = yyvsp[0].word[2];
          I64(0x38) = yyvsp[-3].word[0];
          I64(0x40) = yyvsp[-1].word[1];
          break;
        case 47:
          I64(0x38) = yyvsp[0].word[0];
          I64(0x40) = yyvsp[-1].word[1];
          break;
        case 48:
          I64(0x20) = yyvsp[0].word[0];
          I64(0x28) = yyvsp[0].word[1];
          I64(0x30) = yyvsp[0].word[2];
          I64(0x38) = yyvsp[-1].word[0];
          I64(0x40) = yyvsp[-2].word[1];
          break;
        case 50:
          I64(0x20) = yyvsp[-2].word[0];
          I64(0x28) = yyvsp[-2].word[1];
          I64(0x30) = yyvsp[-2].word[2];
          I64(0x38) = -yyvsp[-1].word[1];
          I64(0x40) = -yyvsp[0].word[1];
          if (yyvsp[-1].word[1] == (-0x7fffffffffffffffL - 1)
              || yyvsp[0].word[1] == (-0x7fffffffffffffffL - 1))
            return 1;
          break;

        case 51:
          if (!apply_relative_time(pc, yyvsp[-1].word[0], yyvsp[-1].word[1],
                                   yyvsp[-1].word[2], yyvsp[-1].word[3],
                                   yyvsp[-1].word[4], yyvsp[-1].word[5],
                                   (int) yyvsp[-1].word[6],
                                   (int) yyvsp[0].word[0]))
            return 1;
          break;
        case 52:
        case 53:
          if (!apply_relative_time(pc, yyvsp[0].word[0], yyvsp[0].word[1],
                                   yyvsp[0].word[2], yyvsp[0].word[3],
                                   yyvsp[0].word[4], yyvsp[0].word[5],
                                   (int) yyvsp[0].word[6], 1))
            return 1;
          break;

        case 54: yyval.word[0] = yyvsp[-1].word[0]; break;
        case 55: yyval.word[0] = yyvsp[-1].word[1]; break;
        case 56:
          yyval.word[0] = 1; yyval.word[1] = 0; yyval.word[2] = 0;
          yyval.word[3] = 0; yyval.word[4] = 0; yyval.word[5] = 0;
          yyval.word[6] = 0;
          break;
        case 57:
          yyval.word[0] = 0; yyval.word[1] = yyvsp[-1].word[0];
          yyval.word[2] = 0; yyval.word[3] = 0; yyval.word[4] = 0;
          yyval.word[5] = 0; yyval.word[6] = 0;
          break;
        case 58:
          yyval.word[0] = 0; yyval.word[1] = yyvsp[-1].word[1];
          yyval.word[2] = 0; yyval.word[3] = 0; yyval.word[4] = 0;
          yyval.word[5] = 0; yyval.word[6] = 0;
          break;
        case 59:
          yyval.word[0] = 0; yyval.word[1] = 1; yyval.word[2] = 0;
          yyval.word[3] = 0; yyval.word[4] = 0; yyval.word[5] = 0;
          yyval.word[6] = 0;
          break;
        case 60:
        case 61:
          if (OVERFLOW_MUL(yyvsp[-1].word[1], yyvsp[0].word[0],
                           &yyval.word[4]))
            return 1;
          yyval.word[0] = 0; yyval.word[1] = 0; yyval.word[2] = 0;
          yyval.word[3] = 0; yyval.word[5] = 0; yyval.word[6] = 0;
          break;
        case 62:
          yyval.word[0] = 0; yyval.word[1] = 0; yyval.word[2] = 0;
          yyval.word[3] = 0; yyval.word[4] = yyvsp[0].word[0];
          yyval.word[5] = 0; yyval.word[6] = 0;
          break;
        case 63:
          yyval.word[0] = 0; yyval.word[1] = 0;
          yyval.word[2] = yyvsp[-1].word[0];
          yyval.word[3] = 0; yyval.word[4] = 0; yyval.word[5] = 0;
          yyval.word[6] = 0;
          break;
        case 64:
          yyval.word[0] = 0; yyval.word[1] = 0;
          yyval.word[2] = yyvsp[-1].word[1];
          yyval.word[3] = 0; yyval.word[4] = 0; yyval.word[5] = 0;
          yyval.word[6] = 0;
          break;
        case 65:
          yyval.word[0] = 0; yyval.word[1] = 0; yyval.word[2] = 1;
          yyval.word[3] = 0; yyval.word[4] = 0; yyval.word[5] = 0;
          yyval.word[6] = 0;
          break;
        case 66:
        case 67:
          yyval.word[0] = 0; yyval.word[1] = 0; yyval.word[2] = 0;
          yyval.word[3] = yyvsp[-1].word[0];
          yyval.word[4] = 0; yyval.word[5] = 0; yyval.word[6] = 0;
          break;
        case 68:
          yyval.word[0] = 0; yyval.word[1] = 0; yyval.word[2] = 0;
          yyval.word[3] = 1; yyval.word[4] = 0; yyval.word[5] = 0;
          yyval.word[6] = 0;
          break;
        case 69:
        case 70:
          yyval.word[0] = 0; yyval.word[1] = 0; yyval.word[2] = 0;
          yyval.word[3] = 0; yyval.word[4] = 0;
          yyval.word[5] = yyvsp[-1].word[0]; yyval.word[6] = 0;
          break;
        case 71:
        case 72:
          yyval.word[0] = 0; yyval.word[1] = 0; yyval.word[2] = 0;
          yyval.word[3] = 0; yyval.word[4] = 0;
          yyval.word[5] = yyvsp[-1].word[0];
          yyval.word[6] = yyvsp[-1].word[1];
          break;
        case 73:
          yyval.word[0] = 0; yyval.word[1] = 0; yyval.word[2] = 0;
          yyval.word[3] = 0; yyval.word[4] = 0; yyval.word[5] = 1;
          yyval.word[6] = 0;
          break;
        case 75: yyval.word[0] = yyvsp[-1].word[1]; break;
        case 76: yyval.word[1] = yyvsp[-1].word[1]; break;
        case 77:
          if (OVERFLOW_MUL(yyvsp[-1].word[1], yyvsp[0].word[0],
                           &yyval.word[4]))
            return 1;
          break;
        case 78: yyval.word[2] = yyvsp[-1].word[1]; break;
        case 79: yyval.word[3] = yyvsp[-1].word[1]; break;
        case 80: yyval.word[5] = yyvsp[-1].word[1]; break;
        case 81: yyval.word[4] = yyvsp[0].word[0]; break;
        case 85:
        case 87:
          yyval.word[0] = yyvsp[0].word[1];
          yyval.word[1] = 0;
          break;
        case 88:
          {
            three_word_value v = {{ yyvsp[0].word[0], yyvsp[0].word[1],
                                     yyvsp[0].word[2] }};
            digits_to_date_time(pc, v);
          }
          break;
        case 89:
          {
            three_word_value v = {{ yyvsp[-1].word[0], yyvsp[-1].word[1],
                                     yyvsp[-1].word[2] }};
            digits_to_date_time(pc, v);
          }
          if (!apply_relative_time(pc, yyvsp[-1].word[0], yyvsp[-1].word[1],
                                   yyvsp[-1].word[2], yyvsp[-1].word[3],
                                   yyvsp[-1].word[4], yyvsp[-1].word[5],
                                   (int) yyvsp[-1].word[6], 1))
            return 1;
          break;
        case 90: yyval.word[0] = -1; break;
        case 91: yyval.word[0] = yyvsp[0].word[1]; break;
        default:
          break;
        }

      yyssp -= yylen;
      yyvsp -= yylen;
      yystate = *yyssp;
      {
        int lhs = yyr1[yyn] - 28;
        index = yypgoto[lhs] + yystate;
        if ((unsigned int) index <= 112 && yycheck[index] == yystate)
          yystate = yytable[index];
        else
          yystate = yydefgoto[lhs];
      }
      if (++yyssp == state_stack + 19)
        return 2;
      *yyssp = (signed char) yystate;
      *++yyvsp = yyval;
      continue;

syntax_error:
      if (yyerrstatus == 3)
        {
          if (yychar <= 0)
            return 1;
          yychar = -2;
        }

      yyerrstatus = 3;
      for (;;)
        {
          yyn = yypact[yystate];
          if (yyn != -93)
            {
              index = yyn + 1;
              if ((unsigned int) index <= 112 && yycheck[index] == 1)
                {
                  yyn = yytable[index];
                  if (yyn > 0)
                    break;
                }
            }
          if (yyssp == state_stack)
            return 1;
          --yyssp;
          --yyvsp;
          yystate = *yyssp;
        }

      if (++yyssp == state_stack + 19)
        return 2;
      *yyssp = (signed char) yyn;
      *++yyvsp = yylval;
      yystate = yyn;
    }

#undef I64
#undef I32
#undef U8
#undef OVERFLOW_ADD
#undef OVERFLOW_MUL
}


