#include <stdlib.h>
#include <stdio.h>

#include "dynamic_array.h"

const int INITIAL_CAPACITY = 2;

dyn_arr* new_dyn_arr() {
    // Allocate memory for a new dynamic array
    dyn_arr * a = (dyn_arr*) malloc(sizeof(dyn_arr));

    // Initialize fields. Allocate memory equal to the size of an int
    // multiplied by the initial capacity.
    a->array = (int*) malloc(sizeof(int) * INITIAL_CAPACITY);
    a->size = 0;
    a->capacity = INITIAL_CAPACITY;

    return a;
}

void dyn_arr_add(dyn_arr *a, int i) {
    // Resize array if necessary
    if (a->size == a->capacity) {
        int* array2 = (int*) malloc(sizeof(int) * a->capacity*2);
        for (int j=0; j < a->size; j++) {
            array2[j] = a->array[j];
        }
        free(a->array);
        a->array = array2;
        a->capacity = a->capacity*2;
    }

    // Add item to end of array and increment the size
    a->array[a->size] = i;
    a->size++;
}

void dyn_arr_remove(dyn_arr *a, int i) {
    // Iterate through array to find item to remove
    for (int j=0; j < a->size; j++) {
        if (a->array[j] == i) {
            // To remove the item, we move all elements after it back one spot,
            // then decrement the size of the array
            for (int k=j; k+1 < a->size; k++) {
                a->array[k] = a->array[k+1];
            }
            a->size--;
            return;
        }
    }
}

bool dyn_arr_contains(dyn_arr *a, int i) {
    for (int j=0; j < a->size; j++) {
        if (a->array[j] == i) {
            return true;
        }
    }
    return false;
}

void dyn_arr_insertion_sort(dyn_arr *a) {
    for (int i = 0; i < a->size; i++) {
        int tmp = a->array[i];
        int j;
        for (j = i; j > 0; j--) {
            if (tmp >= a->array[j-1]) {
                break;
            }
            a->array[j] = a->array[j-1];
        }
        a->array[j] = tmp;
    }
}
// Austin's Functions for Merge Sort

// Function to get minimum of two numbers
int min(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

// Function to merge two arrays
void merge(dyn_arr *a, dyn_arr *tmp, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;

}

// Function to merge sort an array
void merge_sort (dyn_arr *a) {
    
    dyn_arr* tmp = new_dyn_arr();
    for (int i=0; i <= a->size; i++) {
        dyn_arr_add(tmp, a->array[i]);
    }

    for (int i=0; i < a->size; i = 2*i) {
        for (int j=0; j < a->size; j += 2*i) {
            int start = j;
            int mid = j + m - 1;
            int end = min(j + 2*i -1, a->size);
            merge(a, tmp, start, mid, end);
        }
    }
}

void dyn_arr_sort(dyn_arr *a) {
    // TODO: Implement a O(n log n) sorting algorithm (e.g. merge sort, quick
    // sort, or heap sort). The operation should modify the array in-place.
    //
    merge_sort(a);
    return;
}

int dyn_arr_size(dyn_arr *a) {
    return a->size;
}

void free_dyn_arr(dyn_arr *a) {
    free(a->array);
    free(a); 
}
