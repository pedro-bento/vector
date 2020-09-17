#include "vector.h"

void __vector_expand(char **data, size_t *size, size_t *capacity, size_t element_size) {
    if(*size + 1 > *capacity) {
        size_t new_capacity;
        if (*capacity == 0) { 
            new_capacity = 1;
        } else {
            new_capacity = *capacity * VECTOR_GROWTH_FACTOR;
        }

        *data = realloc(*data, new_capacity * element_size);
        *capacity = new_capacity;
    }
}

void __vector_reserve(char **data, size_t *size, size_t *capacity, size_t element_size, size_t n) {
    (void) size;

    if(n > *capacity) {
        *data = realloc(*data, n * element_size);
        *capacity = n;
    }
}

void __vector_resize(char **data, size_t *size, size_t *capacity, size_t element_size, size_t n) {
    (void) size;

    if(*capacity != n) {
        *data = realloc(*data, n * element_size);
        *capacity = n;
    }
}

void __vector_swap(char **data, size_t *size, size_t *capacity, size_t element_size, size_t index1, size_t index2) {
    (void) size;
    (void) capacity;

    if(index1 == index2) return;

    char *a, *b, tmp;
    a = (char*)*data + index1 * element_size;
    b = (char*)*data + index2 * element_size;

    while(element_size--) {
        tmp = *a;
        *a = *b;
        *b = tmp;
        a++;
        b++;
    }
}

void __vector_reverse(char **data, size_t *size, size_t *capacity, size_t element_size) {
    size_t start = 0;
    size_t end = *size - 1;

    while(start < end) {
        __vector_swap(data, size, capacity, element_size, start, end);
        start++;
        end--;
    }
}

void __vector_move_left(char **data, size_t *size, size_t *capacity, size_t element_size, size_t index) {
    size_t offset = index * element_size;
    size_t number_of_bytes = (*size - index - 1) * element_size;
    memmove(*data + offset, *data + offset + element_size, number_of_bytes);
}

void __vector_move_right(char **data, size_t *size, size_t *capacity, size_t element_size, size_t index) {
    assert(*size < *capacity);

    size_t offset = index * element_size;
    size_t number_of_bytes = (*size - index) * element_size;
    memmove(*data + offset + element_size, *data + offset, number_of_bytes);
}