# vector

A generic type-safe vector implementation in pure C.

# API

## Type
* Vector(Type) 

## Constructor 
* vector_new(&vector)

## Destructor 
* vector_delete(&vector)

## Copy
* vector_copy(&vector_dst, &vector_src)

## Insertion
* vector_assign(&vector, index, element)
* vector_insert(&vector, index, element)
* vector_push_back(&vector, element)
* vector_push_front(&vector, element)
* vector_push_array(&vector, array, array_size)
* vector_extend(&vector_dst, &vector_src)

## Deletion
* vector_clear(&vector)
* vector_erase(&vector, index)
* vector_pop_back(&vector)
* vector_pop_front(&vector)

## Lookup
* vector_front(&vector)
* vector_back(&vector)
* vector_data(&vector)
* vector_at(&vector, index)

## Information
* vector_empty(&vector)
* vector_full(&vector)
* vector_size(&vector)
* vector_capacity(&vector)
* vector_unused_space(&vector)

## Memory management
* vector_resize(&vector)
* vector_reserve(&vector)
* vector_shrink_to_fit(&vector)

## Algorithms
* vector_foreach(&vector, variable, iterator)
* vector_foreach_rev(&vector, variable, iterator)
* vector_foreach_ptr(&vector, variable, iterator)
* vector_foreach_ptr_rev(&vector, variable, iterator)
* vector_sort(&vector, comparator)
* vector_swap(&vector, index1, index2)
* vector_reverse(&vector)

# Example usage
```c 
Vector(int) v;
vector_new(&v);
vector_reserve(&v, 128);
vector_push_array(&v, ((const int[]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0}), 10);
vector_assign(&v, 42, 42);
vector_erase(&v, 42);
vector_reverse(&v);
vector_delete(&v);
```
