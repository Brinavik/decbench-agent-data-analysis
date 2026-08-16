






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




extern inline gl_list_t
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

extern inline gl_list_t
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

extern inline size_t
gl_list_size (gl_list_t list)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->size (list);
}

extern inline const void *
gl_list_node_value (gl_list_t list, gl_list_node_t node)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->node_value (list, node);
}

extern inline __attribute__ ((__warn_unused_result__)) int
gl_list_node_nx_set_value (gl_list_t list, gl_list_node_t node,
                           const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->node_nx_set_value (list, node, elt);
}

extern inline gl_list_node_t
gl_list_next_node (gl_list_t list, gl_list_node_t node)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->next_node (list, node);
}

extern inline gl_list_node_t
gl_list_previous_node (gl_list_t list, gl_list_node_t node)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->previous_node (list, node);
}

extern inline gl_list_node_t
gl_list_first_node (gl_list_t list)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->first_node (list);
}

extern inline gl_list_node_t
gl_list_last_node (gl_list_t list)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->last_node (list);
}

extern inline const void *
gl_list_get_at (gl_list_t list, size_t position)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->get_at (list, position);
}

extern inline const void *
gl_list_get_first (gl_list_t list)
{
  return gl_list_get_at (list, 0);
}

extern inline const void *
gl_list_get_last (gl_list_t list)
{
  return gl_list_get_at (list, gl_list_size (list) - 1);
}

extern inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_set_at (gl_list_t list, size_t position, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_set_at (list, position, elt);
}

extern inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_set_first (gl_list_t list, const void *elt)
{
  return gl_list_nx_set_at (list, 0, elt);
}

extern inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_set_last (gl_list_t list, const void *elt)
{
  return gl_list_nx_set_at (list, gl_list_size (list) - 1, elt);
}

extern inline gl_list_node_t
gl_list_search (gl_list_t list, const void *elt)
{
  size_t size = ((const struct gl_list_impl_base *) list)->vtable->size (list);
  return ((const struct gl_list_impl_base *) list)->vtable
         ->search_from_to (list, 0, size, elt);
}

extern inline gl_list_node_t
gl_list_search_from (gl_list_t list, size_t start_index, const void *elt)
{
  size_t size = ((const struct gl_list_impl_base *) list)->vtable->size (list);
  return ((const struct gl_list_impl_base *) list)->vtable
         ->search_from_to (list, start_index, size, elt);
}

extern inline gl_list_node_t
gl_list_search_from_to (gl_list_t list, size_t start_index, size_t end_index,
                        const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->search_from_to (list, start_index, end_index, elt);
}

extern inline size_t
gl_list_indexof (gl_list_t list, const void *elt)
{
  size_t size = ((const struct gl_list_impl_base *) list)->vtable->size (list);
  return ((const struct gl_list_impl_base *) list)->vtable
         ->indexof_from_to (list, 0, size, elt);
}

extern inline size_t
gl_list_indexof_from (gl_list_t list, size_t start_index, const void *elt)
{
  size_t size = ((const struct gl_list_impl_base *) list)->vtable->size (list);
  return ((const struct gl_list_impl_base *) list)->vtable
         ->indexof_from_to (list, start_index, size, elt);
}

extern inline size_t
gl_list_indexof_from_to (gl_list_t list, size_t start_index, size_t end_index,
                         const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->indexof_from_to (list, start_index, end_index, elt);
}

extern inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_first (gl_list_t list, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_first (list, elt);
}

extern inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_last (gl_list_t list, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_last (list, elt);
}

extern inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_before (gl_list_t list, gl_list_node_t node, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_before (list, node, elt);
}

extern inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_after (gl_list_t list, gl_list_node_t node, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_after (list, node, elt);
}

extern inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_list_nx_add_at (gl_list_t list, size_t position, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->nx_add_at (list, position, elt);
}

extern inline 
              _Bool

gl_list_remove_node (gl_list_t list, gl_list_node_t node)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->remove_node (list, node);
}

extern inline 
              _Bool

gl_list_remove_at (gl_list_t list, size_t position)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->remove_at (list, position);
}

extern inline 
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

extern inline 
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

extern inline 
              _Bool

gl_list_remove (gl_list_t list, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->remove_elt (list, elt);
}

extern inline void
gl_list_free (gl_list_t list)
{
  ((const struct gl_list_impl_base *) list)->vtable->list_free (list);
}

extern inline gl_list_iterator_t
gl_list_iterator (gl_list_t list)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->iterator (list);
}

extern inline gl_list_iterator_t
gl_list_iterator_from_to (gl_list_t list, size_t start_index, size_t end_index)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->iterator_from_to (list, start_index, end_index);
}

extern inline 
              _Bool

gl_list_iterator_next (gl_list_iterator_t *iterator,
                       const void **eltp, gl_list_node_t *nodep)
{
  return iterator->vtable->iterator_next (iterator, eltp, nodep);
}

extern inline void
gl_list_iterator_free (gl_list_iterator_t *iterator)
{
  iterator->vtable->iterator_free (iterator);
}

extern inline gl_list_node_t
gl_sortedlist_search (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_search (list, compar, elt);
}

extern inline gl_list_node_t
gl_sortedlist_search_from_to (gl_list_t list, gl_listelement_compar_fn compar, size_t start_index, size_t end_index, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_search_from_to (list, compar, start_index, end_index,
                                      elt);
}

extern inline size_t
gl_sortedlist_indexof (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_indexof (list, compar, elt);
}

extern inline size_t
gl_sortedlist_indexof_from_to (gl_list_t list, gl_listelement_compar_fn compar, size_t start_index, size_t end_index, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_indexof_from_to (list, compar, start_index, end_index,
                                       elt);
}

extern inline __attribute__ ((__warn_unused_result__)) gl_list_node_t
gl_sortedlist_nx_add (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_nx_add (list, compar, elt);
}

extern inline 
              _Bool

gl_sortedlist_remove (gl_list_t list, gl_listelement_compar_fn compar, const void *elt)
{
  return ((const struct gl_list_impl_base *) list)->vtable
         ->sortedlist_remove (list, compar, elt);
}






