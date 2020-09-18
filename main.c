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

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    Vector(int) v1, v2;
    vector_new(&v1);
    vector_new(&v2);

    vector_push_array(&v1, ((const int[]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0}), 10);

    vector_copy(&v2, &v1);

    int temp;
    vector_foreach(&v2, temp, i) {
        printf("%d ", temp);
    }

    vector_delete(&v1);
    vector_delete(&v2);

    return 0;
}
