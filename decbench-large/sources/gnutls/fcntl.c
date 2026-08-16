

       
       
       
       
extern int _gl_cxxalias_dummy

                                      ;

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;
extern int rpl_fcntl (int fd, int action, ...);
extern int _gl_cxxalias_dummy;
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

extern int _gl_cxxalias_dummy;
extern int _gl_cxxalias_dummy;

extern int _gl_cxxalias_dummy;




static int rpl_fcntl_DUPFD (int fd, int target);

static int rpl_fcntl_DUPFD_CLOEXEC (int fd, int target);
int

rpl_fcntl 
     (int fd, int action, ...)




{
  va_list arg;
  int result = -1;
  
 __builtin_va_start(
 arg
 ,
 action
 )
                       ;
  switch (action)
    {
    case 
        0
               :
      {
        int target = 
                    __builtin_va_arg(
                    arg
                    ,
                    int
                    )
                                     ;
        result = rpl_fcntl_DUPFD (fd, target);
        break;
      }

    case 
        1030
                       :
      {
        int target = 
                    __builtin_va_arg(
                    arg
                    ,
                    int
                    )
                                     ;
        result = rpl_fcntl_DUPFD_CLOEXEC (fd, target);
        break;
      }
    default:
      {

        switch (action)
          {
          case 
              1
                     :


          case 
              3
                     :


          case 
              1025
                        :





          case 
              9
                      :


          case 
              1032
                          :
          case 
              1034
                         :


          case 
              11
                      :
            result = fcntl (fd, action);
            break;


          case 
              1033
                         :
          case 
              0
                     :


          case 
              1030
                             :
          case 
              1026
                      :
          case 
              2
                     :


          case 
              4
                     :


          case 
              1024
                        :





          case 
              8
                      :


          case 
              1031
                          :





          case 
              10
                      :





            {
              int x = 
                     __builtin_va_arg(
                     arg
                     ,
                     int
                     )
                                      ;
              result = fcntl (fd, action, x);
            }
            break;

          default:

            {
              void *p = 
                       __builtin_va_arg(
                       arg
                       ,
                       void *
                       )
                                           ;
              result = fcntl (fd, action, p);
            }
            break;
          }



        break;
      }
    }
  
 __builtin_va_end(
 arg
 )
             ;
  return result;
}

static int
rpl_fcntl_DUPFD (int fd, int target)
{
  int result;
  result = fcntl (fd, 
                     0
                            , target);

  return result;
}

static int
rpl_fcntl_DUPFD_CLOEXEC (int fd, int target)
{
  int result;
  static int have_dupfd_cloexec = 
                                 0 
                                                                ? -1 : 0;
  if (0 <= have_dupfd_cloexec)
    {
      result = fcntl (fd, 
                         1030
                                        , target);
      if (0 <= result || 
                        (*__errno_location ()) 
                              != 
                                 22
                                       )
        {
          have_dupfd_cloexec = 1;




        }
      else
        {
          result = rpl_fcntl_DUPFD (fd, target);
          if (result >= 0)
            have_dupfd_cloexec = -1;
        }
    }
  else

    result = rpl_fcntl_DUPFD (fd, target);
  if (0 <= result && have_dupfd_cloexec == -1)
    {
      int flags = fcntl (result, 
                                1
                                       );
      if (flags < 0 || fcntl (result, 
                                     2
                                            , flags | 
                                                      1
                                                                ) == -1)
        {
          int saved_errno = 
                           (*__errno_location ())
                                ;
          close (result);
          
         (*__errno_location ()) 
               = saved_errno;
          result = -1;
        }
    }

  return result;
}
