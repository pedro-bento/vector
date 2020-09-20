#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define VECTOR_VERSION 1

// Definitions
#define VECTOR_GROWTH_FACTOR 2

// Type
#define Vector(T)               struct { size_t capacity; size_t size; T *data; }

// Constructor 
#define vector_new(vector)      memset((vector), 0, sizeof(*(vector)))

// Destructor
#define vector_delete(vector)   do { free((vector)->data); memset((vector), 0, sizeof(*(vector))); } while(0)

// Copy
#define vector_copy(vector_dst, vector_src)     do { vector_reserve(vector_dst, (vector_src)->size); memcpy((vector_dst)->data, (vector_src)->data, (vector_src)->size * sizeof(*(vector_src)->data)); (vector_dst)->size = (vector_src)->size; (vector_dst)->capacity = (vector_src)->capacity; } while(0)

// Move
#define vector_move(vector_dst, vector_src)     do { vector_delete(vector_dst); (vector_dst)->size = (vector_src)->size; (vector_dst)->capacity = (vector_src)->capacity; (vector_dst)->data = (vector_src)->data; memset((vector_src), 0, sizeof(*(vector_src))); } while(0)

// Insertion
#define vector_assign(vector, index, element)           do { assert((index) < (vector)->capacity); ((vector)->data[(index)] = (element)); } while(0)
#define vector_insert(vector, index, element)           do { assert((index) < (vector)->capacity); __vector_move_right(__vector_unpack(vector), index); vector_assign(vector, index, element); (vector)->size++; } while(0)
#define vector_push_back(vector, element)               do { __vector_expand(__vector_unpack(vector)); (vector)->data[(vector)->size] = (element); (vector)->size++; } while(0)
#define vector_push_front(vector, element)              do { __vector_expand(__vector_unpack(vector)); vector_insert(vector, 0, element); } while (0)
#define vector_push_array(vector, array, array_size)    do { vector_reserve(vector, vector_size(vector) + (array_size)); memcpy(&(vector)->data[(vector)->size], array, array_size * sizeof(*array)); (vector)->size += array_size; } while(0)
#define vector_extend(vector_dst, vector_src)           vector_push_array(vector_dst, (vector_src)->data, (vector_src)->size)

// Deletion
#define vector_clear(vector)        ((vector)->size = 0)
#define vector_erase(vector, index) do { assert((index) < (vector)->capacity); __vector_move_left(__vector_unpack(vector), index); (vector)->size--; } while(0)
#define vector_pop_back(vector)     do { assert((vector)->size > 0); (vector)->size--; } while(0)
#define vector_pop_front(vector)    vector_erase(vector, 0)

// Lookup
#define vector_front(vector)        (vector)->data[0]
#define vector_back(vector)         (vector)->data[(vector)->size - 1]
#define vector_data(vector)         (vector)->data
#define vector_at(vector, index)    (vector)->data[(index)]

// Information
#define vector_empty(vector)        ((vector)->size == 0)
#define vector_full(vector)         ((vector)->size == (vector)->capacity)
#define vector_size(vector)         (vector)->size
#define vector_capacity(vector)     (vector)->capacity
#define vector_unused_space(vector) ((vector)->capacity - (vector)->size)

// Memory management
#define vector_resize(vector, n)        __vector_resize(__vector_unpack(vector), n)
#define vector_reserve(vector, n)       __vector_reserve(__vector_unpack(vector), n)
#define vector_shrink_to_fit(vector)    __vector_resize(__vector_unpack(vector), (vector)->size)

// Algorithms
#define vector_foreach(vector, variable, iterator)          for(long long (iterator) = 0; (iterator) < (vector)->size && (((variable) = (vector)->data[(iterator)]), 1); ++(iterator))
#define vector_foreach_rev(vector, variable, iterator)      for(long long (iterator) = (vector)->size - 1; (iterator) >= 0 && (((variable) = (vector)->data[(iterator)]), 1); --(iterator))
#define vector_foreach_ptr(vector, variable, iterator)      for(long long (iterator) = 0; (iterator) < (vector)->size && (((variable) = &(vector)->data[(iterator)]), 1); ++(iterator))
#define vector_foreach_ptr_rev(vector, variable, iterator)  for(long long (iterator) = (vector)->size - 1; (iterator) >= 0 && (((variable) = &(vector)->data[(iterator)]), 1); --(iterator))
#define vector_sort(vector, comparator)                     qsort((vector)->data, (vector)->size, sizeof(*(vector)->data), comparator)
#define vector_swap(vector, index1, index2)                 __vector_swap(__vector_unpack(vector), index1, index2)
#define vector_reverse(vector)                              __vector_reverse(__vector_unpack(vector))

// Private
#define __vector_unpack(vector) (char**)&(vector)->data, &(vector)->size, &(vector)->capacity, sizeof(*(vector)->data)  
void __vector_expand(char **data, size_t *size, size_t *capacity, size_t element_size);
void __vector_reserve(char **data, size_t *size, size_t *capacity, size_t element_size, size_t n);
void __vector_resize(char **data, size_t *size, size_t *capacity, size_t element_size, size_t n);
void __vector_swap(char **data, size_t *size, size_t *capacity, size_t element_size, size_t index1, size_t index2);
void __vector_reverse(char **data, size_t *size, size_t *capacity, size_t element_size);
void __vector_move_left(char **data, size_t *size, size_t *capacity, size_t element_size, size_t index);
void __vector_move_right(char **data, size_t *size, size_t *capacity, size_t element_size, size_t index);

#endif // VECTOR_H