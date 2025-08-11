#ifndef INSERTSORT
#define INSERTSORT

#include <stdlib.h>
#include "../../sortUtils.h"

// insertionSortIntegers
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{
    int i, j;
    int sorted = 0;
    for (i = 1; i < size; ++ i) {        
        sorted = 0;
        j = i - 1;
        while (sorted == 0) {
            if(array[j + 1] < array[j]) {
                swap(&array[j + 1], &array[j]);
            }
            --j;

            if (j == -1) {
                sorted = 1;
            }
        }
        printIntArray(array, size);
    }
}
#endif