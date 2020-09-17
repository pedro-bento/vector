# vector

A generic type-safe vector implementation in pure C.

# API

## Type
* Vector(T) 

## Constructor and Destructor
* new_vector(&vector)
* delete_vector(&vector)

## Element access
* vector_front(&vector)
* vector_back(&vector)
* vector_data(&vector)

## Capacity
* vector_capacity(&vector)
* vector_size(&vector)
* vector_reserve(&vector)
* vector_capacity(&vector)

## Modifiers
* vector_clear(&vector)
* vector_push_back(&vector, element)
* vector_pop_back(&vector)
* vector_resize(&vector)

## Algorithms
* vector_foreach(&vector, variable, iterator)
* vector_foreach_rev(&vector, variable, iterator)
* vector_foreach_ptr(&vector, variable, iterator)
* vector_foreach_ptr_rev(&vector, variable, iterator)
* vector_sort(&vector, comparator)

## Helper functions
* char_comparator
* int_comparator
* float_comparator
* double_comparator

# Examples
```c
Vector(int) vector;
new_vector(&vector);

vector_push_back(&vector, 42);
vector_push_back(&vector, 21);

int size = vector_size(&vector); 
int capacity = vector.capacity;

int first = vector_front(&vector);
int last = vector_back(&vector);

vector_data(&vector)[0] = vector_back(&vector);

vector_pop_back(&vector);

for(int i = 0; i < 18; ++i) {
    vector_push_back(&vector, i);
}

vector_sort(&vector, int_comparator);

int temp, *temp_ptr;

vector_foreach(&vector, temp, i) {
    printf("%d ", temp);
}   

vector_foreach_ptr_rev(&vector, temp_ptr, i) {
    printf("%d ", *temp_ptr);
}   

vector_clear(&v);

delete_vector(&v);

```
