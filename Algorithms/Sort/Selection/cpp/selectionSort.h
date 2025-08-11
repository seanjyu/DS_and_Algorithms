#ifndef INSERTSORT
#define INSERTSORT

#include <stdlib.h>
#include "../../sortUtils.h"

int findMinimum(int *array, int start, int stop)
{
    // loop through given array index and return minimum
    int i;
    int min_ind = start;
    for (i = start; i < stop; ++i) {
        if (array[i] < array[min_ind]) {
            min_ind = i;
        }
    }
    return min_ind;
}

// SelectionSortIntegers
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    int i;
    int min_ind;
    for (i = 0; i < size; ++i) {
        min_ind = findMinimum(array, i, size);
        swap(&array[i], &array[min_ind]);
        printIntArray(array, size);
    }
}

#endif