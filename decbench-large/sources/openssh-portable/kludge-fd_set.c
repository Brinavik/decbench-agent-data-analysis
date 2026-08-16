






void kludge_FD_SET(int n, fd_set *set) {
 
((void) (((
set
)->fds_bits)[((
n
) / (8 * (int) sizeof (__fd_mask)))] |= ((__fd_mask) (1UL << ((
n
) % (8 * (int) sizeof (__fd_mask)))))))
              ;
}
int kludge_FD_ISSET(int n, fd_set *set) {
 return 
       ((((
       set
       )->fds_bits)[((
       n
       ) / (8 * (int) sizeof (__fd_mask)))] & ((__fd_mask) (1UL << ((
       n
       ) % (8 * (int) sizeof (__fd_mask)))))) != 0)
                       ;
}
