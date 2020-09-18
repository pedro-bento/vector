#include <stdio.h>

#include "vector/vector.h"

int int_comparator(const void *a, const void *b) {
    if(*(int*)a < *(int*)b) return -1;
    else if(*(int*)a == *(int*)b) return 0;
    else return 1;
}

// TODO: Write test cases for Vector LIB

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    Vector(int) v1, v2;
    vector_new(&v1);
    vector_new(&v2);

    vector_push_array(&v1, ((const int[]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0}), 10);

    vector_move(&v2, &v1);

    int temp;
    vector_foreach(&v2, temp, i) {
        printf("%d ", temp);
    }

    printf("\n");

    vector_foreach(&v1, temp, i) {
        printf("%d ", temp);
    }

    vector_delete(&v1);
    vector_delete(&v2);

    return 0;
}
