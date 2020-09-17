#include <stdio.h>

#include "vector/vector.h"

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

// TODO:
// replace condition in vector_pop_back by custom assert that can be turned off

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    Vector(int) v;
    vector_new(&v);
    vector_push_array(&v, ((const int[]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0}), 10);

    int temp;
    vector_foreach(&v, temp, i) {
        printf("%d ", temp);
    }

    vector_reverse(&v);

    printf("\n");
    vector_foreach(&v, temp, i) {
        printf("%d ", temp);
    }

    vector_push_front(&v, 999);
    vector_push_front(&v, 999);
    vector_push_front(&v, 999);

    printf("\n");
    vector_foreach(&v, temp, i) {
        printf("%d ", temp);
    }

    vector_pop_front(&v);
    vector_pop_front(&v);
    vector_pop_front(&v);

    printf("\n");
    vector_foreach(&v, temp, i) {
        printf("%d ", temp);
    }

    vector_delete(&v);

    return 0;
}
