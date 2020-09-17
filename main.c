#include <stdio.h>

#include "vector/vector.h"

// TODO:
// replace condition in vector_pop_back by custom assert that can be turned off

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    Vector(int) v;
    new_vector(&v);

    printf("empty: %d\n", vector_empty(&v));

    for(int i = 9; i >= 0; --i) {
        vector_push_back(&v, i);
    }

    printf("empty: %d\n", vector_empty(&v));

    printf("Before sort\n");

    int temp;
    vector_foreach(&v, temp, i) {
        printf("%d ", temp);
    }

    vector_sort(&v, int_comparator);

    printf("\nAfter sort\n");

    vector_foreach(&v, temp, i) {
        printf("%d ", temp);
    }

    delete_vector(&v);

    return 0;
}
