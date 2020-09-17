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

    vector_push_array(&v, ((const int[]){9, 8, 7, 6, 5, 4, 3, 2, 1, 0}), 10);

    int temp;
    vector_foreach(&v, temp, i) {
        printf("%d ", temp);
    }

    printf("\n");

    vector_reverse(&v);

    vector_foreach(&v, temp, i) {
        printf("%d ", temp);
    }
    
    delete_vector(&v);

    return 0;
}
