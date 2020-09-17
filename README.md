# vector

A generic type-safe vector implementation in pure C.

# API

## Type
### Vector(T) 
Defines a vector of type T
```c 
Vector(float) fv;
```

## Constructor 
### vector_new(&v)
Zero initializes the vector 'v'
```c 
Vector(float) v; 
vector_new(&v);
```

## Destructor 
### vector_delete(&v)
Frees allocated data for vector 'v'
```c 
Vector(int) v; 
vector_new(&v);
vector_delete(&v);
```

## Insertion
### vector_assign(&v, index, element)
Assigns 'element' to position 'index' in vector 'v' (asserts index < vector_size(v))
```c 
vector_assign(&v, 42, 42);
```
### vector_insert(&v, index, element)
Inserts 'element' to position 'index' in vector 'v' by moving all elements after 'index' to the right (asserts index < vector_size(v))
```c 
vector_insert(&v, 42, 42);
```
### vector_push_back(&v, element)
Inserts 'element' at the end of vector 'v', if needed, increases the capacity of 'v'
```c 
vector_push_back(&v, 'A');
```
### vector_push_array(&v, array, array_size)
Extends vector 'v' by appending all 'array_size' values of 'array', if needed, increases the capacity of 'v'
```c 
vector_push_array(&v, ((const int[]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0}), 10);
```
### vector_extend(&v_dst, &v_src)
Extends vector 'v_dst' by appending all elements of 'v_src', if needed, increases the capacity of 'v_dst'
```c 
vector_extend(&v_dst, &v_src);
```

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
