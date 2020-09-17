#include "vector.h"

void __vector_resize(char **data, size_t *size, size_t *capacity, size_t element_size) {
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