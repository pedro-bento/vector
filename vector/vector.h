#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <string.h>

// Macros for modifiers.

#define VECTOR_GROWTH_FACTOR 2

// Type.

#define Vector(T)\
    struct {\
        size_t capacity;\
        size_t size;\
        T *data;\
    }

// Constructor and Destructor. 

#define new_vector(vector)      memset((vector), 0, sizeof(*(vector)))
#define delete_vector(vector)   free((vector)->data)

// Element access.

#define vector_front(vector)    (vector)->data[0]
#define vector_back(vector)     (vector)->data[(vector)->size - 1]
#define vector_data(vector)     (vector)->data

// Capacity.

#define vector_empty(vector)        ((vector)->size == 0)
#define vector_size(vector)         (vector)->size
#define vector_reserve(vector, n)   __vector_reserve(__vector_unpack(vector), n)
#define vector_capacity(vector)     (vector)->capacity

// Modifiers.

#define vector_clear(vector)                ((vector)->size = 0)
#define vector_push_back(vector, element)   (__vector_expand(__vector_unpack(vector)), (vector)->data[(vector)->size] = (element), (vector)->size++)
#define vector_pop_back(vector)             (if ((vector)->size > 0) (vector)->size--)
#define vector_resize(vector, n)            __vector_resize(__vector_unpack(vector), n)

// Algorithms.

#define vector_foreach(vector, variable, iterator)\
    if((vector)->size > 0)\
    for(long long (iterator) = 0;\
        (iterator) < (vector)->size &&\
        (((variable) = (vector)->data[(iterator)]), 1);\
        ++(iterator))

#define vector_foreach_rev(vector, variable, iterator)\
    if((vector)->size > 0)\
    for(long long (iterator) = (vector)->size - 1;\
        (iterator) >= 0 &&\
        (((variable) = (vector)->data[(iterator)]), 1);\
        --(iterator))

#define vector_foreach_ptr(vector, variable, iterator)\
    if((vector)->size > 0)\
    for(long long (iterator) = 0;\
        (iterator) < (vector)->size &&\
        (((variable) = &(vector)->data[(iterator)]), 1);\
        ++(iterator))

#define vector_foreach_ptr_rev(vector, variable, iterator)\
    if((vector)->size > 0)\
    for(long long (iterator) = (vector)->size - 1;\
        (iterator) >= 0 &&\
        (((variable) = &(vector)->data[(iterator)]), 1);\
        --(iterator))

#define vector_sort(vector, comparator)   qsort((vector)->data, (vector)->size, sizeof(*(vector)->data), comparator)

// Public helper Macros and Functions.

int char_comparator(const void *a, const void *b);
int int_comparator(const void *a, const void *b);
int float_comparator(const void *a, const void *b);
int double_comparator(const void *a, const void *b);

// Private helper Macros and Functions.

#define __vector_unpack(vector) (char**)&(vector)->data, &(vector)->size, &(vector)->capacity, sizeof(*(vector)->data)  

void __vector_expand(char **data, size_t *size, size_t *capacity, size_t element_size);
void __vector_reserve(char **data, size_t *size, size_t *capacity, size_t element_size, size_t n);
void __vector_resize(char **data, size_t *size, size_t *capacity, size_t element_size, size_t n);

#endif // VECTOR_H