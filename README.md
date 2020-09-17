# vector

A generic type-safe vector implementation in pure C.

# API

## Type
* Vector(T) 

## Constructor and Destructor
* new_vector(&vector)
* delete_vector(&vector)

## Capacity
* vector_capacity(&vector)
* vector_size(&vector)

## Element access
* vector_front(&vector)
* vector_back(&vector)
* vector_data(&vector)

## Modifiers
* vector_push_back(&vector, element)
* vector_pop_back(&vector)
* vector_clear(&vector)

## Algorithms
* vector_foreach(&vector, variable, iterator)
* vector_foreach_rev(&vector, variable, iterator)
* vector_foreach_ptr(&vector, variable, iterator)
* vector_foreach_ptr_rev(&vector, variable, iterator)

# Examples
```c
#include <stdio.h>

#include "vector/vector.h"

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    Vector(int) vector;
    new_vector(&vector);

    vector_push_back(&vector, 42);
    vector_push_back(&vector, 21);

    printf("\nsize = %d, capacity = %d\n", (int)vector_size(&vector), (int)vector_capacity(&vector));

    printf("front = %d, back = %d, data[0] = %d\n", vector_front(&vector), vector_back(&vector), vector_data(&vector)[0]);

    vector_pop_back(&vector);

    delete_vector(&vector);

    Vector(int) v;
    new_vector(&v);

    for(int i = 0; i < 18; ++i) {
        vector_push_back(&v, i);
    }

    int temp, *temp_ptr;

    printf("\nvector_foreach\n");
    vector_foreach(&v, temp, i) {
        printf("%d ", temp);
    }   
    printf("\n");

    printf("vector_foreach_rev\n");
    vector_foreach_rev(&v, temp, i) {
        printf("%d ", temp);
    }   
    printf("\n");

    printf("vector_foreach_ptr\n");
    vector_foreach_ptr(&v, temp_ptr, i) {
        printf("%d ", *temp_ptr);
    }   
    printf("\n");

    printf("vector_foreach_ptr_rev\n");
    vector_foreach_ptr_rev(&v, temp_ptr, i) {
        printf("%d ", *temp_ptr);
    }   
    printf("\n\n");

    vector_clear(&v);

    printf("cleared vector size = %d", (int)v.size);

    delete_vector(&v);

    return 0;
}

```
