






typedef 
       _Bool 
            (*gl_listelement_equals_fn) (const void *elt1, const void *elt2);



typedef size_t (*gl_listelement_hashcode_fn) (const void *elt);



typedef void (*gl_listelement_dispose_fn) (const void *elt);

struct gl_list_impl;

typedef struct gl_list_impl * gl_list_t;

struct gl_list_node_impl;



typedef struct gl_list_node_impl * gl_list_node_t;

struct gl_list_implementation;

typedef const struct gl_list_implementation * gl_list_implementation_t;
typedef struct
{

  const struct gl_list_implementation *vtable;

  gl_list_t list;
  size_t count;

  void *p; void *q;
  size_t i; size_t j;
} gl_list_iterator_t;
typedef int (*gl_listelement_compar_fn) (const void *elt1, const void *elt2);
struct gl_list_implementation
{

  gl_list_t (*nx_create_empty) (gl_list_implementation_t implementation,
                                gl_listelement_equals_fn equals_fn,
                                gl_listelement_hashcode_fn hashcode_fn,
                                gl_listelement_dispose_fn dispose_fn,
                                
                               _Bool 
                                    allow_duplicates);
  gl_list_t (*nx_create) (gl_list_implementation_t implementation,
                          gl_listelement_equals_fn equals_fn,
                          gl_listelement_hashcode_fn hashcode_fn,
                          gl_listelement_dispose_fn dispose_fn,
                          
                         _Bool 
                              allow_duplicates,
                          size_t count, const void **contents);
  size_t (*size) (gl_list_t list);
  const void * (*node_value) (gl_list_t list, gl_list_node_t node);
  int (*node_nx_set_value) (gl_list_t list, gl_list_node_t node,
                            const void *elt);
  gl_list_node_t (*next_node) (gl_list_t list, gl_list_node_t node);
  gl_list_node_t (*previous_node) (gl_list_t list, gl_list_node_t node);
  gl_list_node_t (*first_node) (gl_list_t list);
  gl_list_node_t (*last_node) (gl_list_t list);
  const void * (*get_at) (gl_list_t list, size_t position);
  gl_list_node_t (*nx_set_at) (gl_list_t list, size_t position,
                               const void *elt);
  gl_list_node_t (*search_from_to) (gl_list_t list, size_t start_index,
                                    size_t end_index, const void *elt);
  size_t (*indexof_from_to) (gl_list_t list, size_t start_index,
                             size_t end_index, const void *elt);
  gl_list_node_t (*nx_add_first) (gl_list_t list, const void *elt);
  gl_list_node_t (*nx_add_last) (gl_list_t list, const void *elt);
  gl_list_node_t (*nx_add_before) (gl_list_t list, gl_list_node_t node,
                                   const void *elt);
  gl_list_node_t (*nx_add_after) (gl_list_t list, gl_list_node_t node,
                                  const void *elt);
  gl_list_node_t (*nx_add_at) (gl_list_t list, size_t position,
                               const void *elt);
  
 _Bool 
      (*remove_node) (gl_list_t list, gl_list_node_t node);
  
 _Bool 
      (*remove_at) (gl_list_t list, size_t position);
  
 _Bool 
      (*remove_elt) (gl_list_t list, const void *elt);
  void (*list_free) (gl_list_t list);

  gl_list_iterator_t (*iterator) (gl_list_t list);
  gl_list_iterator_t (*iterator_from_to) (gl_list_t list,
                                          size_t start_index,
                                          size_t end_index);
  
 _Bool 
      (*iterator_next) (gl_list_iterator_t *iterator,
                         const void **eltp, gl_list_node_t *nodep);
  void (*iterator_free) (gl_list_iterator_t *iterator);

  gl_list_node_t (*sortedlist_search) (gl_list_t list,
                                       gl_listelement_compar_fn compar,
                                       const void *elt);
  gl_list_node_t (*sortedlist_search_from_to) (gl_list_t list,
                                               gl_listelement_compar_fn compar,
                                               size_t start_index,
                                               size_t end_index,
                                               const void *elt);
  size_t (*sortedlist_indexof) (gl_list_t list,
                                gl_listelement_compar_fn compar,
                                const void *elt);
  size_t (*sortedlist_indexof_from_to) (gl_list_t list,
                                        gl_listelement_compar_fn compar,
                                        size_t start_index, size_t end_index,
                                        const void *elt);
  gl_list_node_t (*sortedlist_nx_add) (gl_list_t list,
                                       gl_listelement_compar_fn compar,
                                    const void *elt);
  
 _Bool 
      (*sortedlist_remove) (gl_list_t list,
                             gl_listelement_compar_fn compar,
                             const void *elt);
};

struct gl_list_impl_base
{
  const struct gl_list_implementation *vtable;
  gl_listelement_equals_fn equals_fn;
  gl_listelement_hashcode_fn hashcode_fn;
  gl_listelement_dispose_fn dispose_fn;
  
 _Bool 
      allow_duplicates;
};




inline gl_list_t
gl_list_nx_create_empty (gl_list_implementation_t implementation,
                         gl_listelement_equals_fn equals_fn,
                         gl_listelement_hashcode_fn hashcode_fn,
                         gl_listelement_dispose_fn dispose_fn,
                         
                        _Bool 
                             allow_duplicates)
{
  return implementation->nx_create_empty (implementation, equals_fn,
                                          hashcode_fn, dispose_fn,
                                          allow_duplicates);
}

inline gl_list_t
gl_list_nx_create (gl_list_implementation_t implementation,
                   gl_listelement_equals_fn equals_fn,
                   gl_listelement_hashcode_fn hashcode_fn,
                   gl_listelement_dispose_fn dispose_fn,
                   
                  _Bool 
                       allow_duplicates,
                   size_t count, const void **contents)
{
  return implementation->nx_create (implementation, equals_fn, hashcode_fn,
                                    dispose_fn, allow_duplicates, count,
                                    contents);
}

inline size_t
gl_list_size (gl_list_t list)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->size (list);
}

inline const void *
gl_list_node_value (gl_list_t list, gl_list_node_t node)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->node_value (list, node);
}

inline __attribute__ ((__warn_unused_result__)) int
gl_list_node_nx_set_value (gl_list_t list, gl_list_node_t node,
                           const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->node_nx_set_value (list, node, elt);
}

inline gl_list_node_t
gl_list_next_node (gl_list_t list, gl_list_node_t node)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->next_node (list, node);
}

inline gl_list_node_t
gl_list_previous_node (gl_list_t list, gl_list_node_t node)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->previous_node (list, node);
}

inline gl_list_node_t
gl_list_first_node (gl_list_t list)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->first_node (list);
}

inline gl_list_node_t
gl_list_last_node (gl_list_t list)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->last_node (list);
}

inline const void *
gl_list_get_at (gl_list_t list, size_t position)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->get_at (list, position);
}

inline const void *
gl_list_get_first (gl_list_t list)
{
  return gl_list_get_at (list, 0);
}

inline const void *
gl_list_get_last (gl_list_t list)
{
  return gl_list_get_at (list, gl_list_size (list) - 1);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_set_at (gl_list_t list, size_t position, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_set_at (list, position, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_set_first (gl_list_t list, const void *elt)
{
  return gl_list_nx_set_at (list, 0, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_set_last (gl_list_t list, const void *elt)
{
  return gl_list_nx_set_at (list, gl_list_size (list) - 1, elt);
}

inline gl_list_node_t
gl_list_search (gl_list_t list, const void *elt)
{
  size_t size = ((const struct gl_list_impl_base *) list)->vtable->size (list);
  return ((const struct gl_list_impl_base *) list)->vtable
         ->search_from_to (list, 0, size, elt);
}

inline gl_list_node_t
gl_list_search_from (gl_list_t list, size_t start_index, const void *elt)
{
  size_t size = ((const struct gl_list_impl_base *) list)->vtable->size (list);
  return ((const struct gl_list_impl_base *) list)->vtable
         ->search_from_to (list, start_index, size, elt);
}

inline gl_list_node_t
gl_list_search_from_to (gl_list_t list, size_t start_index, size_t end_index,
                        const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->search_from_to (list, start_index, end_index, elt);
}

inline size_t
gl_list_indexof (gl_list_t list, const void *elt)
{
  size_t size = ((const struct gl_list_impl_base *) list)->vtable->size (list);
  return ((const struct gl_list_impl_base *) list)->vtable
         ->indexof_from_to (list, 0, size, elt);
}

inline size_t
gl_list_indexof_from (gl_list_t list, size_t start_index, const void *elt)
{
  size_t size = ((const struct gl_list_impl_base *) list)->vtable->size (list);
  return ((const struct gl_list_impl_base *) list)->vtable
         ->indexof_from_to (list, start_index, size, elt);
}

inline size_t
gl_list_indexof_from_to (gl_list_t list, size_t start_index, size_t end_index,
                         const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->indexof_from_to (list, start_index, end_index, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_first (gl_list_t list, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_first (list, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_last (gl_list_t list, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_last (list, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_before (gl_list_t list, gl_list_node_t node, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_before (list, node, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_after (gl_list_t list, gl_list_node_t node, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_after (list, node, elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_at (gl_list_t list, size_t position, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_at (list, position, elt);
}

inline 
              _Bool

gl_list_remove_node (gl_list_t list, gl_list_node_t node)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->remove_node (list, node);
}

inline 
              _Bool

gl_list_remove_at (gl_list_t list, size_t position)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->remove_at (list, position);
}

inline 
              _Bool

gl_list_remove_first (gl_list_t list)
{
  size_t size = gl_list_size (list);
  if (size > 0)
    return gl_list_remove_at (list, 0);
  else
    return 
          0
               ;
}

inline 
              _Bool

gl_list_remove_last (gl_list_t list)
{
  size_t size = gl_list_size (list);
  if (size > 0)
    return gl_list_remove_at (list, size - 1);
  else
    return 
          0
               ;
}

inline 
              _Bool

gl_list_remove (gl_list_t list, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->remove_elt (list, elt);
}

inline void
gl_list_free (gl_list_t list)
{
  ((const struct gl_list_impl_base *) list)->vtable->list_free (list);
}

inline gl_list_iterator_t
gl_list_iterator (gl_list_t list)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->iterator (list);
}

inline gl_list_iterator_t
gl_list_iterator_from_to (gl_list_t list, size_t start_index, size_t end_index)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->iterator_from_to (list, start_index, end_index);
}

inline 
              _Bool

gl_list_iterator_next (gl_list_iterator_t *iterator,
                       const void **eltp, gl_list_node_t *nodep)
{
  return iterator->vtable->iterator_next (iterator, eltp, nodep);
}

inline void
gl_list_iterator_free (gl_list_iterator_t *iterator)
{
  iterator->vtable->iterator_free (iterator);
}

inline gl_list_node_t
gl_sortedlist_search (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_search (list, compar, elt);
}

inline gl_list_node_t
gl_sortedlist_search_from_to (gl_list_t list, gl_listelement_compar_fn compar, size_t start_index, size_t end_index, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_search_from_to (list, compar, start_index, end_index,
                                      elt);
}

inline size_t
gl_sortedlist_indexof (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_indexof (list, compar, elt);
}

inline size_t
gl_sortedlist_indexof_from_to (gl_list_t list, gl_listelement_compar_fn compar, size_t start_index, size_t end_index, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_indexof_from_to (list, compar, start_index, end_index,
                                       elt);
}

inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_sortedlist_nx_add (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_nx_add (list, compar, elt);
}

inline 
              _Bool

gl_sortedlist_remove (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_remove (list, compar, elt);
}









typedef ptrdiff_t idx_t;
       
       






           
          _Noreturn void xalloc_die (void);





void *xmalloc (size_t s)
      __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1)));
void *xzalloc (size_t s)
      __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1)));
void *xcalloc (size_t n, size_t s)
      __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2)));
void *xrealloc (void *p, size_t s)
      __attribute__ ((__alloc_size__ (2)));
void *xreallocarray (void *p, size_t n, size_t s)
      __attribute__ ((__alloc_size__ (2, 3)));
void *x2realloc (void *p, size_t *pn);
void *xpalloc (void *pa, idx_t *nitems, idx_t nitems_incr_min,
               ptrdiff_t nitems_max, idx_t item_size);
void *xmemdup (void const *p, size_t s)
      __attribute__ ((__alloc_size__ (2)));
char *xstrdup (char const *str)
      __attribute__ ((__malloc__));
inline void *xnmalloc (size_t n, size_t s)
                    __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1, 2)));
inline void *
xnmalloc (size_t n, size_t s)
{
  return xreallocarray (
                       ((void *)0)
                           , n, s);
}





inline void *xnrealloc (void *p, size_t n, size_t s)
                    __attribute__ ((__alloc_size__ (2, 3)));
inline void *
xnrealloc (void *p, size_t n, size_t s)
{
  return xreallocarray (p, n, s);
}
inline void *
x2nrealloc (void *p, size_t *pn, size_t s)
{
  size_t n = *pn;

  if (! p)
    {
      if (! n)
        {




          enum { DEFAULT_MXFAST = 64 * sizeof (size_t) / 4 };

          n = DEFAULT_MXFAST / s;
          n += !n;
        }
    }
  else
    {

      if (__builtin_add_overflow (n, (n >> 1) + 1, &n))
        xalloc_die ();
    }

  p = xreallocarray (p, n, s);
  *pn = n;
  return p;
}




inline char *xcharalloc (size_t n)
                    __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (1)));
inline char *
xcharalloc (size_t n)
{
  return ((char *) (sizeof (char) == 1 ? xmalloc (n) : xnmalloc (n, sizeof (char))));
}






extern inline gl_list_t
gl_list_create_empty (gl_list_implementation_t implementation,
                      gl_listelement_equals_fn equals_fn,
                      gl_listelement_hashcode_fn hashcode_fn,
                      gl_listelement_dispose_fn dispose_fn,
                      
                     _Bool 
                          allow_duplicates)
{
  gl_list_t result =
    gl_list_nx_create_empty (implementation, equals_fn, hashcode_fn, dispose_fn,
                             allow_duplicates);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

extern inline gl_list_t
gl_list_create (gl_list_implementation_t implementation,
                gl_listelement_equals_fn equals_fn,
                gl_listelement_hashcode_fn hashcode_fn,
                gl_listelement_dispose_fn dispose_fn,
                
               _Bool 
                    allow_duplicates,
                size_t count, const void **contents)
{
  gl_list_t result =
    gl_list_nx_create (implementation, equals_fn, hashcode_fn, dispose_fn,
                       allow_duplicates, count, contents);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

extern inline void
gl_list_node_set_value (gl_list_t list, gl_list_node_t node, const void *elt)
{
  int result = gl_list_node_nx_set_value (list, node, elt);
  if (result < 0)
    xalloc_die ();
}

extern inline gl_list_node_t
gl_list_set_at (gl_list_t list, size_t position, const void *elt)
{
  gl_list_node_t result = gl_list_nx_set_at (list, position, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

extern inline gl_list_node_t
gl_list_set_first (gl_list_t list, const void *elt)
{
  gl_list_node_t result = gl_list_nx_set_first (list, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

extern inline gl_list_node_t
gl_list_set_last (gl_list_t list, const void *elt)
{
  gl_list_node_t result = gl_list_nx_set_last (list, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

extern inline gl_list_node_t
gl_list_add_first (gl_list_t list, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_first (list, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

extern inline gl_list_node_t
gl_list_add_last (gl_list_t list, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_last (list, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

extern inline gl_list_node_t
gl_list_add_before (gl_list_t list, gl_list_node_t node, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_before (list, node, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

extern inline gl_list_node_t
gl_list_add_after (gl_list_t list, gl_list_node_t node, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_after (list, node, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

extern inline gl_list_node_t
gl_list_add_at (gl_list_t list, size_t position, const void *elt)
{
  gl_list_node_t result = gl_list_nx_add_at (list, position, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}

extern inline gl_list_node_t
gl_sortedlist_add (gl_list_t list, gl_listelement_compar_fn compar,
                   const void *elt)
{
  gl_list_node_t result = gl_sortedlist_nx_add (list, compar, elt);
  if (result == 
               ((void *)0)
                   )
    xalloc_die ();
  return result;
}






