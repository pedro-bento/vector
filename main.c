#include <stdio.h>

#include "vector/vector.h"

// TODO:
// replace condition in vector_pop_back by custom assert that can be turned off

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    Vector(int) v, v2;
    new_vector(&v);
    new_vector(&v2);

    vector_push_array(&v, ((const int[]){9, 8, 7, 10, 6, 5, 4, 3, 2, 1}), 10);
    printf("size: %d\n", (int)vector_size(&v));

    for(int i = 110; i >= 101; --i) {
        vector_push_back(&v2, i);
    }

    vector_extend(&v, &v2);
    printf("size: %d\n", (int)vector_size(&v));

    vector_sort(&v, int_comparator);

    int temp;
    vector_foreach(&v, temp, i) {
        printf("%d ", temp);
    }

    delete_vector(&v);
    delete_vector(&v2);

    return 0;
}
