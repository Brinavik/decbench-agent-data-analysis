







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











extern const struct gl_list_implementation gl_linked_list_implementation;

       
       
       
       
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





struct gl_list_node_impl
{



  struct gl_list_node_impl *next;
  struct gl_list_node_impl *prev;
  const void *value;
};


struct gl_list_impl
{
  struct gl_list_impl_base base;
  struct gl_list_node_impl root;

  size_t count;
};
static gl_list_t
gl_linked_nx_create_empty (gl_list_implementation_t implementation,
                           gl_listelement_equals_fn equals_fn,
                           gl_listelement_hashcode_fn hashcode_fn,
                           gl_listelement_dispose_fn dispose_fn,
                           
                          _Bool 
                               allow_duplicates)
{
  struct gl_list_impl *list =
    (struct gl_list_impl *) malloc (sizeof (struct gl_list_impl));

  if (list == 
             ((void *)0)
                 )
    return 
          ((void *)0)
              ;

  list->base.vtable = implementation;
  list->base.equals_fn = equals_fn;
  list->base.hashcode_fn = hashcode_fn;
  list->base.dispose_fn = dispose_fn;
  list->base.allow_duplicates = allow_duplicates;







  list->root.next = &list->root;
  list->root.prev = &list->root;
  list->count = 0;

  return list;






}

static gl_list_t
gl_linked_nx_create (gl_list_implementation_t implementation,
                     gl_listelement_equals_fn equals_fn,
                     gl_listelement_hashcode_fn hashcode_fn,
                     gl_listelement_dispose_fn dispose_fn,
                     
                    _Bool 
                         allow_duplicates,
                     size_t count, const void **contents)
{
  struct gl_list_impl *list =
    (struct gl_list_impl *) malloc (sizeof (struct gl_list_impl));
  gl_list_node_t tail;

  if (list == 
             ((void *)0)
                 )
    return 
          ((void *)0)
              ;

  list->base.vtable = implementation;
  list->base.equals_fn = equals_fn;
  list->base.hashcode_fn = hashcode_fn;
  list->base.dispose_fn = dispose_fn;
  list->base.allow_duplicates = allow_duplicates;
  list->count = count;
  tail = &list->root;
  for (; count > 0; contents++, count--)
    {
      gl_list_node_t node =
        (struct gl_list_node_impl *) malloc (sizeof (struct gl_list_node_impl));

      if (node == 
                 ((void *)0)
                     )
        goto fail2;

      node->value = *contents;
      node->prev = tail;
      tail->next = node;
      tail = node;
    }
  tail->next = &list->root;
  list->root.prev = tail;

  return list;

 fail2:
  {
    gl_list_node_t node;

    for (node = tail; node != &list->root; )
      {
        gl_list_node_t prev = node->prev;

        free (node);
        node = prev;
      }
  }




  free (list);
  return 
        ((void *)0)
            ;
}

static size_t __attribute__ ((__pure__))
gl_linked_size (gl_list_t list)
{
  return list->count;
}

static const void * __attribute__ ((__pure__))
gl_linked_node_value (gl_list_t list __attribute__ ((__unused__)),
                      gl_list_node_t node)
{
  return node->value;
}

static int
gl_linked_node_nx_set_value (gl_list_t list __attribute__ ((__unused__)),
                             gl_list_node_t node,
                             const void *elt)
{
  node->value = elt;

  return 0;
}

static gl_list_node_t __attribute__ ((__pure__))
gl_linked_next_node (gl_list_t list, gl_list_node_t node)
{
  return (node->next != &list->root ? node->next : 
                                                  ((void *)0)
                                                      );
}

static gl_list_node_t __attribute__ ((__pure__))
gl_linked_previous_node (gl_list_t list, gl_list_node_t node)
{
  return (node->prev != &list->root ? node->prev : 
                                                  ((void *)0)
                                                      );
}

static gl_list_node_t __attribute__ ((__pure__))
gl_linked_first_node (gl_list_t list)
{
  if (list->count > 0)
    return list->root.next;
  else
    return 
          ((void *)0)
              ;
}

static gl_list_node_t __attribute__ ((__pure__))
gl_linked_last_node (gl_list_t list)
{
  if (list->count > 0)
    return list->root.prev;
  else
    return 
          ((void *)0)
              ;
}

static const void * __attribute__ ((__pure__))
gl_linked_get_at (gl_list_t list, size_t position)
{
  size_t count = list->count;
  gl_list_node_t node;

  if (!(position < count))

    abort ();

  if (position <= ((count - 1) / 2))
    {
      node = list->root.next;
      for (; position > 0; position--)
        node = node->next;
    }
  else
    {
      position = count - 1 - position;
      node = list->root.prev;
      for (; position > 0; position--)
        node = node->prev;
    }
  return node->value;
}

static gl_list_node_t
gl_linked_nx_set_at (gl_list_t list, size_t position, const void *elt)
{
  size_t count = list->count;
  gl_list_node_t node;

  if (!(position < count))

    abort ();

  if (position <= ((count - 1) / 2))
    {
      node = list->root.next;
      for (; position > 0; position--)
        node = node->next;
    }
  else
    {
      position = count - 1 - position;
      node = list->root.prev;
      for (; position > 0; position--)
        node = node->prev;
    }
  node->value = elt;

  return node;
}

static gl_list_node_t __attribute__ ((__pure__))
gl_linked_search_from_to (gl_list_t list, size_t start_index, size_t end_index,
                          const void *elt)
{
  size_t count = list->count;

  if (!(start_index <= end_index && end_index <= count))

    abort ();
  {
    gl_listelement_equals_fn equals = list->base.equals_fn;
    gl_list_node_t node = list->root.next;

    end_index -= start_index;
    for (; start_index > 0; start_index--)
      node = node->next;

    if (equals != 
                 ((void *)0)
                     )
      {
        for (; end_index > 0; node = node->next, end_index--)
          if (equals (elt, node->value))
            return node;
      }
    else
      {
        for (; end_index > 0; node = node->next, end_index--)
          if (elt == node->value)
            return node;
      }
    return 
          ((void *)0)
              ;

  }
}

static size_t __attribute__ ((__pure__))
gl_linked_indexof_from_to (gl_list_t list, size_t start_index, size_t end_index,
                           const void *elt)
{
  size_t count = list->count;

  if (!(start_index <= end_index && end_index <= count))

    abort ();
  {
    gl_listelement_equals_fn equals = list->base.equals_fn;
    size_t index = start_index;
    gl_list_node_t node = list->root.next;

    for (; start_index > 0; start_index--)
      node = node->next;

    if (equals != 
                 ((void *)0)
                     )
      {
        for (;
             index < end_index;
             node = node->next, index++)
          if (equals (elt, node->value))
            return index;
      }
    else
      {
        for (;
             index < end_index;
             node = node->next, index++)
          if (elt == node->value)
            return index;
      }
    return (size_t)(-1);

  }
}

static gl_list_node_t
gl_linked_nx_add_first (gl_list_t list, const void *elt)
{
  gl_list_node_t node =
    (struct gl_list_node_impl *) malloc (sizeof (struct gl_list_node_impl));

  if (node == 
             ((void *)0)
                 )
    return 
          ((void *)0)
              ;

  node->value = elt;
  node->prev = &list->root;
  node->next = list->root.next;
  node->next->prev = node;
  list->root.next = node;
  list->count++;





  return node;
}

static gl_list_node_t
gl_linked_nx_add_last (gl_list_t list, const void *elt)
{
  gl_list_node_t node =
    (struct gl_list_node_impl *) malloc (sizeof (struct gl_list_node_impl));

  if (node == 
             ((void *)0)
                 )
    return 
          ((void *)0)
              ;

  node->value = elt;
  node->next = &list->root;
  node->prev = list->root.prev;
  node->prev->next = node;
  list->root.prev = node;
  list->count++;





  return node;
}

static gl_list_node_t
gl_linked_nx_add_before (gl_list_t list, gl_list_node_t node, const void *elt)
{
  gl_list_node_t new_node =
    (struct gl_list_node_impl *) malloc (sizeof (struct gl_list_node_impl));

  if (new_node == 
                 ((void *)0)
                     )
    return 
          ((void *)0)
              ;

  new_node->value = elt;
  new_node->next = node;
  new_node->prev = node->prev;
  new_node->prev->next = new_node;
  node->prev = new_node;
  list->count++;





  return new_node;
}

static gl_list_node_t
gl_linked_nx_add_after (gl_list_t list, gl_list_node_t node, const void *elt)
{
  gl_list_node_t new_node =
    (struct gl_list_node_impl *) malloc (sizeof (struct gl_list_node_impl));

  if (new_node == 
                 ((void *)0)
                     )
    return 
          ((void *)0)
              ;

  new_node->value = elt;
  new_node->prev = node;
  new_node->next = node->next;
  new_node->next->prev = new_node;
  node->next = new_node;
  list->count++;





  return new_node;
}

static gl_list_node_t
gl_linked_nx_add_at (gl_list_t list, size_t position, const void *elt)
{
  size_t count = list->count;
  gl_list_node_t new_node;

  if (!(position <= count))

    abort ();

  new_node = (struct gl_list_node_impl *) malloc (sizeof (struct gl_list_node_impl));
  if (new_node == 
                 ((void *)0)
                     )
    return 
          ((void *)0)
              ;

  new_node->value = elt;
  if (position <= (count / 2))
    {
      gl_list_node_t node;

      node = &list->root;
      for (; position > 0; position--)
        node = node->next;
      new_node->prev = node;
      new_node->next = node->next;
      new_node->next->prev = new_node;
      node->next = new_node;
    }
  else
    {
      gl_list_node_t node;

      position = count - position;
      node = &list->root;
      for (; position > 0; position--)
        node = node->prev;
      new_node->next = node;
      new_node->prev = node->prev;
      new_node->prev->next = new_node;
      node->prev = new_node;
    }
  list->count++;





  return new_node;
}

static 
      _Bool

gl_linked_remove_node (gl_list_t list, gl_list_node_t node)
{
  gl_list_node_t prev;
  gl_list_node_t next;







  prev = node->prev;
  next = node->next;

  prev->next = next;
  next->prev = prev;
  list->count--;

  if (list->base.dispose_fn != 
                              ((void *)0)
                                  )
    list->base.dispose_fn (node->value);
  free (node);
  return 
        1
            ;
}

static 
      _Bool

gl_linked_remove_at (gl_list_t list, size_t position)
{
  size_t count = list->count;
  gl_list_node_t removed_node;

  if (!(position < count))

    abort ();

  if (position <= ((count - 1) / 2))
    {
      gl_list_node_t node;
      gl_list_node_t after_removed;

      node = &list->root;
      for (; position > 0; position--)
        node = node->next;
      removed_node = node->next;
      after_removed = node->next->next;
      node->next = after_removed;
      after_removed->prev = node;
    }
  else
    {
      gl_list_node_t node;
      gl_list_node_t before_removed;

      position = count - 1 - position;
      node = &list->root;
      for (; position > 0; position--)
        node = node->prev;
      removed_node = node->prev;
      before_removed = node->prev->prev;
      node->prev = before_removed;
      before_removed->next = node;
    }



  list->count--;

  if (list->base.dispose_fn != 
                              ((void *)0)
                                  )
    list->base.dispose_fn (removed_node->value);
  free (removed_node);
  return 
        1
            ;
}

static 
      _Bool

gl_linked_remove (gl_list_t list, const void *elt)
{
  gl_list_node_t node = gl_linked_search_from_to (list, 0, list->count, elt);

  if (node != 
             ((void *)0)
                 )
    return gl_linked_remove_node (list, node);
  else
    return 
          0
               ;
}

static void
gl_linked_list_free (gl_list_t list)
{
  gl_listelement_dispose_fn dispose = list->base.dispose_fn;
  gl_list_node_t node;

  for (node = list->root.next; node != &list->root; )
    {
      gl_list_node_t next = node->next;
      if (dispose != 
                    ((void *)0)
                        )
        dispose (node->value);
      free (node);
      node = next;
    }



  free (list);
}



static gl_list_iterator_t __attribute__ ((__pure__))
gl_linked_iterator (gl_list_t list)
{
  gl_list_iterator_t result;

  result.vtable = list->base.vtable;
  result.list = list;
  result.p = list->root.next;
  result.q = &list->root;






  return result;
}

static gl_list_iterator_t __attribute__ ((__pure__))
gl_linked_iterator_from_to (gl_list_t list,
                            size_t start_index, size_t end_index)
{
  gl_list_iterator_t result;
  size_t n1, n2, n3;

  if (!(start_index <= end_index && end_index <= list->count))

    abort ();
  result.vtable = list->base.vtable;
  result.list = list;
  n1 = start_index;
  n2 = end_index - start_index;
  n3 = list->count - end_index;


  if (n1 > n2 && n1 > n3)
    {

      gl_list_node_t node;
      size_t i;

      node = &list->root;
      for (i = n3; i > 0; i--)
        node = node->prev;
      result.q = node;
      for (i = n2; i > 0; i--)
        node = node->prev;
      result.p = node;
    }
  else if (n2 > n3)
    {

      gl_list_node_t node;
      size_t i;

      node = list->root.next;
      for (i = n1; i > 0; i--)
        node = node->next;
      result.p = node;

      node = &list->root;
      for (i = n3; i > 0; i--)
        node = node->prev;
      result.q = node;
    }
  else
    {

      gl_list_node_t node;
      size_t i;

      node = list->root.next;
      for (i = n1; i > 0; i--)
        node = node->next;
      result.p = node;
      for (i = n2; i > 0; i--)
        node = node->next;
      result.q = node;
    }







  return result;
}

static 
      _Bool

gl_linked_iterator_next (gl_list_iterator_t *iterator,
                         const void **eltp, gl_list_node_t *nodep)
{
  if (iterator->p != iterator->q)
    {
      gl_list_node_t node = (gl_list_node_t) iterator->p;
      *eltp = node->value;
      if (nodep != 
                  ((void *)0)
                      )
        *nodep = node;
      iterator->p = node->next;
      return 
            1
                ;
    }
  else
    return 
          0
               ;
}

static void
gl_linked_iterator_free (gl_list_iterator_t *iterator __attribute__ ((__unused__)))
{
}



static gl_list_node_t __attribute__ ((__pure__))
gl_linked_sortedlist_search (gl_list_t list, gl_listelement_compar_fn compar,
                             const void *elt)
{
  gl_list_node_t node;

  for (node = list->root.next; node != &list->root; node = node->next)
    {
      int cmp = compar (node->value, elt);

      if (cmp > 0)
        break;
      if (cmp == 0)
        return node;
    }
  return 
        ((void *)0)
            ;
}

static gl_list_node_t __attribute__ ((__pure__))
gl_linked_sortedlist_search_from_to (gl_list_t list,
                                     gl_listelement_compar_fn compar,
                                     size_t low, size_t high,
                                     const void *elt)
{
  size_t count = list->count;

  if (!(low <= high && high <= list->count))

    abort ();

  high -= low;
  if (high > 0)
    {

      size_t position = low;
      gl_list_node_t node;

      if (position <= ((count - 1) / 2))
        {
          node = list->root.next;
          for (; position > 0; position--)
            node = node->next;
        }
      else
        {
          position = count - 1 - position;
          node = list->root.prev;
          for (; position > 0; position--)
            node = node->prev;
        }

      do
        {
          int cmp = compar (node->value, elt);

          if (cmp > 0)
            break;
          if (cmp == 0)
            return node;
          node = node->next;
        }
      while (--high > 0);
    }
  return 
        ((void *)0)
            ;
}

static size_t __attribute__ ((__pure__))
gl_linked_sortedlist_indexof (gl_list_t list, gl_listelement_compar_fn compar,
                              const void *elt)
{
  gl_list_node_t node;
  size_t index;

  for (node = list->root.next, index = 0;
       node != &list->root;
       node = node->next, index++)
    {
      int cmp = compar (node->value, elt);

      if (cmp > 0)
        break;
      if (cmp == 0)
        return index;
    }
  return (size_t)(-1);
}

static size_t __attribute__ ((__pure__))
gl_linked_sortedlist_indexof_from_to (gl_list_t list,
                                      gl_listelement_compar_fn compar,
                                      size_t low, size_t high,
                                      const void *elt)
{
  size_t count = list->count;

  if (!(low <= high && high <= list->count))

    abort ();

  high -= low;
  if (high > 0)
    {

      size_t index = low;
      size_t position = low;
      gl_list_node_t node;

      if (position <= ((count - 1) / 2))
        {
          node = list->root.next;
          for (; position > 0; position--)
            node = node->next;
        }
      else
        {
          position = count - 1 - position;
          node = list->root.prev;
          for (; position > 0; position--)
            node = node->prev;
        }

      do
        {
          int cmp = compar (node->value, elt);

          if (cmp > 0)
            break;
          if (cmp == 0)
            return index;
          node = node->next;
          index++;
        }
      while (--high > 0);
    }
  return (size_t)(-1);
}

static gl_list_node_t
gl_linked_sortedlist_nx_add (gl_list_t list, gl_listelement_compar_fn compar,
                             const void *elt)
{
  gl_list_node_t node;

  for (node = list->root.next; node != &list->root; node = node->next)
    if (compar (node->value, elt) >= 0)
      return gl_linked_nx_add_before (list, node, elt);
  return gl_linked_nx_add_last (list, elt);
}

static 
      _Bool

gl_linked_sortedlist_remove (gl_list_t list, gl_listelement_compar_fn compar,
                             const void *elt)
{
  gl_list_node_t node;

  for (node = list->root.next; node != &list->root; node = node->next)
    {
      int cmp = compar (node->value, elt);

      if (cmp > 0)
        break;
      if (cmp == 0)
        return gl_linked_remove_node (list, node);
    }
  return 
        0
             ;
}


const struct gl_list_implementation gl_linked_list_implementation =
  {
    gl_linked_nx_create_empty,
    gl_linked_nx_create,
    gl_linked_size,
    gl_linked_node_value,
    gl_linked_node_nx_set_value,
    gl_linked_next_node,
    gl_linked_previous_node,
    gl_linked_first_node,
    gl_linked_last_node,
    gl_linked_get_at,
    gl_linked_nx_set_at,
    gl_linked_search_from_to,
    gl_linked_indexof_from_to,
    gl_linked_nx_add_first,
    gl_linked_nx_add_last,
    gl_linked_nx_add_before,
    gl_linked_nx_add_after,
    gl_linked_nx_add_at,
    gl_linked_remove_node,
    gl_linked_remove_at,
    gl_linked_remove,
    gl_linked_list_free,
    gl_linked_iterator,
    gl_linked_iterator_from_to,
    gl_linked_iterator_next,
    gl_linked_iterator_free,
    gl_linked_sortedlist_search,
    gl_linked_sortedlist_search_from_to,
    gl_linked_sortedlist_indexof,
    gl_linked_sortedlist_indexof_from_to,
    gl_linked_sortedlist_nx_add,
    gl_linked_sortedlist_remove
  };
