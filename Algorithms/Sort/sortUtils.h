#ifndef SORTUTILS
#define SORTUTILS

#include <stdio.h> // Include file for standard input/output
// =============== Helper Functions ===============
// Swaps two numbers in an array
// Input: The 'address of' an index into an array for positions in an array.
void swap(int *a, int *b)
{
    // from sorting lab
    int buffer = *a;
    *a = *b;
    *b = buffer;
}

// Input: A pointer to an array (i.e. the array itself points to the first index)
//        The size of the array (Because we do not know how big the array is automatically)
void printIntArray(int *array, unsigned int size)
{
    unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

#endif