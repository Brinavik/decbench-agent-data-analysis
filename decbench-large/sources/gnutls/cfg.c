
typedef struct cfg_option_st {
 char *name;
 char *value;
} *cfg_option_t;

cfg_option_t cfg_load(const char *filename);
void cfg_free(cfg_option_t options);
cfg_option_t cfg_next(const cfg_option_t options, const char *name);

       












       
       
       
extern int _gl_cxxalias_dummy

                                      ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;




extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                   ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                             ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                       ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                            ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy


                                          ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                          ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                     ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                           ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                    ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                   ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                   ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                              ;


extern int _gl_cxxalias_dummy;
       
       





extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                        ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                         ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                     ;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
       
       







extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                 ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                                                             ;



extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                          ;
extern int _gl_cxxalias_dummy

                                                              ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy
                                                                     ;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy

                                             ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;


       
       










inline size_t __attribute__ ((__pure__))
xsum (size_t size1, size_t size2)
{
  size_t sum = size1 + size2;
  return (sum >= size1 ? sum : 
                              (18446744073709551615UL)
                                      );
}


inline size_t __attribute__ ((__pure__))
xsum3 (size_t size1, size_t size2, size_t size3)
{
  return xsum (xsum (size1, size2), size3);
}


inline size_t __attribute__ ((__pure__))
xsum4 (size_t size1, size_t size2, size_t size3, size_t size4)
{
  return xsum (xsum (xsum (size1, size2), size3), size4);
}


inline size_t __attribute__ ((__pure__))
xmax (size_t size1, size_t size2)
{


  return (size1 >= size2 ? size1 : size2);
}




struct options_st {
 struct cfg_option_st *data;
 size_t length;
 size_t capacity;
};

struct parser_st
{
 FILE *fp;
 char pushback[2];
 size_t pushback_length;
};

static inline void
clear_option(struct cfg_option_st *option)
{
 free(option->name);
 free(option->value);
 memset(option, 0, sizeof(*option));
}

void
cfg_free(cfg_option_t options)
{
 for (size_t i = 0; options[i].name; i++) {
  clear_option(&options[i]);
 }
 free(options);
}
struct buffer_st {
 char *data;
 size_t length;
 size_t capacity;
};

static int
buffer_append(struct buffer_st *buffer, int c)
{
 size_t new_length = xsum(buffer->length, 1);
 if (((new_length) == 
    (18446744073709551615UL)
    )) {
  return -
         22
               ;
 }
 if (buffer->capacity < new_length) {
  size_t new_capacity;
  char *new_array;

  new_capacity = ((xsum(buffer->capacity, 1)) <= 
                (18446744073709551615UL) 
                / (2) ? (size_t) (xsum(buffer->capacity, 1)) * (2) : 
                (18446744073709551615UL)
                );
  if (((new_capacity) == 
     (18446744073709551615UL)
     )) {
   return -
          22
                ;
  }
  new_array = realloc(buffer->data, new_capacity);
  if (!new_array) {
   return -
          (*__errno_location ())
               ;
  }
  buffer->capacity = new_capacity;
  buffer->data = new_array;
 }
 
((void) sizeof ((
buffer->data
) ? 1 : 0), __extension__ ({ if (
buffer->data
) ; else __assert_fail (
"buffer->data"
, "cfg.c", 101, __extension__ __PRETTY_FUNCTION__); }))
                    ;
 buffer->data[buffer->length++] = c;
 return 0;
}

static int
parser_getc(struct parser_st *parser)
{
 if (parser->pushback_length > 0) {
  return parser->pushback[--parser->pushback_length];
 }
 int c = getc(parser->fp);
 return c;
}

static void
parser_ungetc(struct parser_st *parser, int c)
{
 
((void) sizeof ((
parser->pushback_length < (sizeof(parser->pushback) / sizeof((parser->pushback)[0]))
) ? 1 : 0), __extension__ ({ if (
parser->pushback_length < (sizeof(parser->pushback) / sizeof((parser->pushback)[0]))
) ; else __assert_fail (
"parser->pushback_length < SIZEOF(parser->pushback)"
, "cfg.c", 119, __extension__ __PRETTY_FUNCTION__); }))
                                                          ;
 parser->pushback[parser->pushback_length++] = c;
}

static void
skip_comment(struct parser_st *parser)
{
 int c;

 c = parser_getc(parser);
 if (c == 
         (-1)
            ) {
  return;
 }

 if (c == '#') {
  for (;;) {
   c = parser_getc(parser);
   if (c == 
           (-1)
              ) {
    return;
   }
   if (c == '\n') {
    break;
   }
  }
 }
 parser_ungetc(parser, c);
}

static void
skip_chars(struct parser_st *parser, const char *chars)
{
 int c;

 for (;;) {
  c = parser_getc(parser);
  if (c == 
          (-1)
             ) {
   return;
  }
  if (!strchr(chars, c)) {
   break;
  }
 }
 parser_ungetc(parser, c);
}

static void
skip_comments_and_whitespaces(struct parser_st *parser)
{
 int c;

 for (;;) {
  c = parser_getc(parser);
  if (c == 
          (-1)
             ) {
   return;
  }
  parser_ungetc(parser, c);
  if (c == '#') {
   skip_comment(parser);
  } else if (strchr("\t " "\n\v\f\r\b", c)) {
   skip_chars(parser, "\t " "\n\v\f\r\b");
  } else {
   break;
  }
 }
}


static char *
read_name(struct parser_st *parser)
{
 struct buffer_st buffer;
 int c;

 memset(&buffer, 0, sizeof(buffer));

 skip_comments_and_whitespaces(parser);

 c = parser_getc(parser);
 if (c == 
         (-1)
            ) {
  return 
        ((void *)0)
            ;
 }

 if (!strchr("_" "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", c)) {
  parser_ungetc(parser, c);
  return 
        ((void *)0)
            ;
 }

 buffer_append(&buffer, c);
 for (;;) {
  c = parser_getc(parser);
  if (c == 
          (-1)
             ) {
   break;
  }
  if (!strchr(":^-" "_" "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" "0123456789", c)) {
   parser_ungetc(parser, c);
   break;
  }
  buffer_append(&buffer, c);
 }
 
((void) sizeof ((
buffer.data
) ? 1 : 0), __extension__ ({ if (
buffer.data
) ; else __assert_fail (
"buffer.data"
, "cfg.c", 218, __extension__ __PRETTY_FUNCTION__); }))
                   ;
 if (buffer.data[buffer.length - 1] == ':') {
  buffer.data[buffer.length - 1] = '\0';
  buffer.length--;
  parser_ungetc(parser, ':');
 }


 buffer_append(&buffer, '\0');
 return buffer.data;
}

static char *
read_quoted_value(struct parser_st *parser)
{
 struct buffer_st buffer;
 int c, quote_char;

 memset(&buffer, 0, sizeof(buffer));

 c = parser_getc(parser);
 if (c == 
         (-1)
            ) {
  
 ((void) sizeof ((0) ? 1 : 0), __extension__ ({ if (0) ; else __assert_fail (
 "false"
 , "cfg.c", 240, __extension__ __PRETTY_FUNCTION__); }))
              ;
  return 
        ((void *)0)
            ;
 }

 if (c == '"' || c == '\'') {
  quote_char = c;
 } else {
  
 ((void) sizeof ((0) ? 1 : 0), __extension__ ({ if (0) ; else __assert_fail (
 "false"
 , "cfg.c", 247, __extension__ __PRETTY_FUNCTION__); }))
              ;
  return 
        ((void *)0)
            ;
 }

 for (;;) {
  c = parser_getc(parser);
  if (c == 
          (-1)
             ) {
   break;
  }
  if (c == '\\') {
   c = parser_getc(parser);
   if (c == 
           (-1)
              ) {

    free(buffer.data);
    return 
          ((void *)0)
              ;
   }
   if (c == '\n') {
    buffer_append(&buffer, ' ');
   } else if (c == quote_char) {
    buffer_append(&buffer, c);
   }
  } else if (c == quote_char) {
   break;
  } else {
   buffer_append(&buffer, c);
  }
 }


 buffer_append(&buffer, '\0');
 return buffer.data;
}


static char *
read_value(struct parser_st *parser)
{
 struct buffer_st buffer;
 int c;

 memset(&buffer, 0, sizeof(buffer));

 skip_chars(parser, "\t ");

 c = parser_getc(parser);
 if (c == 
         (-1)
            ) {
  goto out;
 }


 if (c == ':' || c == '=') {
  c = parser_getc(parser);
  if (c == 
          (-1)
             ) {
   goto out;
  }
  parser_ungetc(parser, c);
  skip_chars(parser, "\t ");
  c = parser_getc(parser);
  if (c == 
          (-1)
             ) {
   goto out;
  }
 }

 if (c == '\n') {
  return strdup("");
 } else if (c == '"' || c == '\'') {
  parser_ungetc(parser, c);
  return read_quoted_value(parser);
 }

 buffer_append(&buffer, c);
 for (;;) {
  c = parser_getc(parser);
  if (c == 
          (-1)
             ) {
   break;
  }
  if (c == '\\') {
   c = parser_getc(parser);
   if (c == 
           (-1)
              ) {
    break;
   }
   if (c == '\n') {
    buffer_append(&buffer, c);
   }
  } else if (c == '\n') {
   break;
  } else {
   buffer_append(&buffer, c);
  }
 }

 out:

 buffer_append(&buffer, '\0');
 return buffer.data;
}


static int
take_option(struct options_st *options, struct cfg_option_st *option)
{
 size_t new_length = xsum(options->length, 1);
 if (((new_length) == 
    (18446744073709551615UL)
    )) {
  return -
         22
               ;
 }
 if (options->capacity < new_length) {
  size_t new_capacity;
  struct cfg_option_st *new_array;

  new_capacity = ((xsum(options->capacity, 1)) <= 
                (18446744073709551615UL) 
                / (2) ? (size_t) (xsum(options->capacity, 1)) * (2) : 
                (18446744073709551615UL)
                );
  if (((new_capacity) == 
     (18446744073709551615UL)
     )) {
   return -
          22
                ;
  }
  new_array = reallocarray(options->data, new_capacity,
      sizeof(*option));
  if (!new_array) {
   return -
          (*__errno_location ())
               ;
  }
  options->capacity = new_capacity;
  options->data = new_array;
 }

 
((void) sizeof ((
options->data
) ? 1 : 0), __extension__ ({ if (
options->data
) ; else __assert_fail (
"options->data"
, "cfg.c", 369, __extension__ __PRETTY_FUNCTION__); }))
                     ;

 options->data[options->length].name = option->name;
 options->data[options->length].value = option->value;

 options->length++;

 option->name = 
               ((void *)0)
                   ;
 option->value = 
                ((void *)0)
                    ;

 return 0;
}

static void
clear_options(struct options_st *options)
{
 for (size_t i = 0; options->length; i++) {
  clear_option(&options->data[i]);
 }
}

cfg_option_t
cfg_load(const char *filename)
{
 struct parser_st parser;
 struct options_st options;
 struct cfg_option_st null_option = { 
                                     ((void *)0)
                                         , 
                                           ((void *)0) 
                                                };

 memset(&parser, 0, sizeof(parser));
 memset(&options, 0, sizeof(options));

 parser.fp = fopen(filename, "r");
 if (!parser.fp) {
  return 
        ((void *)0)
            ;
 }

 for (;;) {
  struct cfg_option_st option;

  option.name = read_name(&parser);
  if (!option.name) {
   break;
  }

  option.value = read_value(&parser);
  if (!option.value) {
   clear_option(&option);
   goto error;
  }

  if (take_option(&options, &option) < 0) {
   clear_option(&option);
   goto error;
  }
  
 ((void) sizeof ((
 !option.name && !option.value
 ) ? 1 : 0), __extension__ ({ if (
 !option.name && !option.value
 ) ; else __assert_fail (
 "!option.name && !option.value"
 , "cfg.c", 423, __extension__ __PRETTY_FUNCTION__); }))
                                      ;
 }

 fclose(parser.fp);

 take_option(&options, &null_option);
 return options.data;

error:
 clear_options(&options);
 fclose(parser.fp);
 return 
       ((void *)0)
           ;
}

cfg_option_t
cfg_next(const cfg_option_t options, const char *name)
{
 for (size_t i = 0; options[i].name; i++) {
  if (strcmp(options[i].name, name) == 0) {
   return &options[i];
  }
 }
 return 
       ((void *)0)
           ;
}
