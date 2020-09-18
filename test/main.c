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

    printf("Begin of Vector tests\n");

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

    vector_shrink_to_fit(&v1);
    assert(vector_capacity(&v1) == 3);
    assert(vector_full(&v1));
    assert(vector_unused_space(&v1) == 0);

    vector_reverse(&v1);
    assert(vector_at(&v1, 0) == 11);
    assert(vector_at(&v1, 1) == 7);
    assert(vector_at(&v1, 2) == 5);

    vector_sort(&v1, int_comparator);
    assert(vector_at(&v1, 0) == 5);
    assert(vector_at(&v1, 1) == 7);
    assert(vector_at(&v1, 2) == 11);

    vector_swap(&v1, 0, 1);
    assert(vector_at(&v1, 0) == 7);
    assert(vector_at(&v1, 1) == 5);

    int aux, *aux_ptr;
    vector_foreach(&v1, aux, i) {
        assert(vector_at(&v1, i) == aux);
    }

    vector_foreach_rev(&v1, aux, i) {
        assert(vector_at(&v1, i) == aux);
    }

    vector_foreach_ptr(&v1, aux_ptr, i) {
        assert(vector_at(&v1, i) == *aux_ptr);
    }

    vector_foreach_ptr_rev(&v1, aux_ptr, i) {
        assert(vector_at(&v1, i) == *aux_ptr);
    }

    vector_resize(&v1, 10);
    assert(vector_capacity(&v1) == 10);

    vector_reserve(&v1, 13);
    assert(vector_capacity(&v1) == 13);

    vector_delete(&v1);
    vector_delete(&v2);

    printf("End of Vector tests :: Success\n");

    return 0;
}
