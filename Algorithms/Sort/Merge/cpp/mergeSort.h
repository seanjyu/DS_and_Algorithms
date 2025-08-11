#ifndef MERGESORT
#define MERGESORT

#include <stdlib.h>
#include "../../sortUtils.h"

// merge function
void merge(int arr[], int temp[], int l, int m, int r)
{
    // if array is empty return null
    if (arr == NULL || temp == NULL)
    {
        exit(1);
    }

    if (l > m || m + 1 > r)
        return;

    int i = l;       // start of left half
    int j = m + 1;   // start of right half
    int k = l;       // start of temp array position

    // Merge both halves into temp[]
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements of left half, if any
    while (i <= m)
    {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right half, if any
    while (j <= r)
    {
        temp[k++] = arr[j++];
    }

    // Copy merged subarray back into original array
    for (i = l; i <= r; i++)
    {
        arr[i] = temp[i];
    }
}

void merge_sort(int arr[], int temp[], int l, int r)
{
    if (l >= r) // base case: 1 or 0 elements
        return;

    int m = l + (r - l) / 2; // avoid overflow

    // Sort left half
    merge_sort(arr, temp, l, m);

    // Sort right half
    merge_sort(arr, temp, m + 1, r);

    // Merge both halves
    merge(arr, temp, l, m, r);
}


// mergeSortIntegers
void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size);
    merge_sort(array, temp, 0, size - 1);
    free(temp);
}

#endif