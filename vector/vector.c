#include "vector.h"

int char_comparator(const void *a, const void *b) {
    if(*(char*)a < *(char*)b) return -1;
    else if(*(char*)a == *(char*)b) return 0;
    else return 1;
}

int int_comparator(const void *a, const void *b) {
    if(*(int*)a < *(int*)b) return -1;
    else if(*(int*)a == *(int*)b) return 0;
    else return 1;
}

int float_comparator(const void *a, const void *b) {
    if(*(float*)a < *(float*)b) return -1;
    else if(*(float*)a == *(float*)b) return 0;
    else return 1;
}

int double_comparator(const void *a, const void *b) {
    if(*(double*)a < *(double*)b) return -1;
    else if(*(double*)a == *(double*)b) return 0;
    else return 1;
}

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

    *data = realloc(*data, n * element_size);
    *capacity = n;
}