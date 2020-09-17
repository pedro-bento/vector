#include <stdio.h>

#include "vector/vector.h"

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    printf("\nVector library test.\n\n");

    Vector(int) v;
    new_vector(&v);

    printf("vector_push_back & vector_size & vector_capacity & vector_back\n");
    for(int i = 0; i < 18; ++i) {
        vector_push_back(&v, i);
        printf("(s: %d, c: %d, b: %d)\n", 
            (int)vector_size(&v),
            (int)vector_capacity(&v),
            (int)vector_back(&v)
        );
    }
    printf("\n");

    int temp, *temp_ptr;

    printf("vector_foreach\n");
    vector_foreach(&v, temp, i) {
        printf("%d ", temp);
    }   
    printf("\n");

    printf("vector_foreach_rev\n");
    vector_foreach_rev(&v, temp, i) {
        printf("%d ", temp);
    }   
    printf("\n");

    printf("vector_foreach_ptr\n");
    vector_foreach_ptr(&v, temp_ptr, i) {
        printf("%d ", *temp_ptr);
    }   
    printf("\n");

    printf("vector_foreach_ptr_rev\n");
    vector_foreach_ptr_rev(&v, temp_ptr, i) {
        printf("%d ", *temp_ptr);
    }   
    printf("\n");

    delete_vector(&v);

    return 0;
}
