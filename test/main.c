#include <stdio.h>

#include "../vector/vector.h"

int int_comparator(const void *a, const void *b) {
    if(*(int*)a < *(int*)b) return -1;
    else if(*(int*)a == *(int*)b) return 0;
    else return 1;
}

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;

    Vector(int) v1;
    vector_new(&v1);
    
    vector_push_front(&v1, 2);
    assert(vector_front(&v1) == 2);

    vector_push_back(&v1, 3);
    assert(vector_back(&v1) == 3);

    vector_pop_back(&v1);
    assert(vector_size(&v1) == 1);

    vector_pop_front(&v1);
    assert(vector_size(&v1) == 0);

    vector_delete(&v1);

    printf("Test completed.");

    return 0;
}
