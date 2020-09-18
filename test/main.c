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

    vector_push_array(&v1, ((int[]){5,7,11}), 3);
    assert(vector_at(&v1, 0) == 5);
    assert(vector_at(&v1, 1) == 7);
    assert(vector_at(&v1, 2) == 11);

    Vector(int) v2;
    vector_new(&v2);

    vector_copy(&v2, &v1);
    assert(vector_data(&v1)[0] == 5);
    assert(vector_data(&v1)[1] == 7);
    assert(vector_data(&v1)[2] == 11);

    vector_erase(&v2, 0);
    assert(vector_size(&v2) == 2);
    assert(vector_at(&v2, 0) == 7);
    assert(vector_at(&v2, 1) == 11);

    vector_insert(&v2, 0, 5);
    assert(vector_size(&v2) == 3);
    assert(vector_at(&v2, 0) == 5);
    assert(vector_at(&v2, 1) == 7);
    assert(vector_at(&v2, 2) == 11);

    vector_extend(&v1, &v2);
    assert(vector_size(&v1) == 6);
    assert(vector_data(&v1)[0] == 5);
    assert(vector_data(&v1)[1] == 7);
    assert(vector_data(&v1)[2] == 11);
    assert(vector_data(&v1)[3] == 5);
    assert(vector_data(&v1)[4] == 7);
    assert(vector_data(&v1)[5] == 11);

    vector_assign(&v1, 0, 101);
    assert(vector_data(&v1)[0] == 101);

    vector_clear(&v1);
    assert(vector_size(&v1) == 0);

    vector_move(&v1, &v2);
    assert(vector_empty(&v2));
    assert(vector_size(&v1) == 3);
    assert(vector_at(&v1, 0) == 5);
    assert(vector_at(&v1, 1) == 7);
    assert(vector_at(&v1, 2) == 11);

    vector_delete(&v1);
    vector_delete(&v2);

    printf("Test completed.");

    return 0;
}
