#include "dynamic_array.h"

const int INITIAL_CAPACITY = 2;

dyn_arr* new_dyn_arr() {
    // Allocate memory for a new dynamic array
    dyn_arr * a = (dyn_arr*) malloc(sizeof(dyn_arr));

    // Initialize fields-> Allocate memory equal to the size of an int
    // multiplied by the initial capacity.
    a->array = (int*) malloc(sizeof(int) * INITIAL_CAPACITY);
    a->size = 0;
    a->capacity = INITIAL_CAPACITY;

    return a;
}

void dyn_arr_add(dyn_arr *a, int i) {
    if (a->size == a->capacity) {
        int* new_arr = (int*) malloc(sizeof(int) * a->capacity*2 );
        for (int j=0;j < a->size; j++) {
            new_arr[j] = a->array[j];
        }
        free(a->array);
        a->array = new_arr;
        a->capacity = a->capacity*2;
    }
    a->array[a->size] = i;
    a->size++;
}

void dyn_arr_remove(dyn_arr *a, int i) {
    // TODO: Implement the remove method-> Removing an item will require you to
    // move all items after it back one spot in the array.
    for (int j=0; j < a->size; ++j) {
        if (a->array[j] == i) {
            for (int k=j; k+1 < a->size; ++k) {
                a->array[k] = a->array[k+1];
            }
            a->size--;
            return;
        }
    }
}

bool dyn_arr_contains(dyn_arr *a, int i) {
    for (int j=0; j < a->size; ++j) {
        if (a->array[j] == i) {
            return true;
        }
    }
    return false;
}

int dyn_arr_size(dyn_arr *a) {
    return a->size;
}

void free_dyn_arr(dyn_arr *a) {
    free(a->array);
    free(a); 
}
