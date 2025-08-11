#include <stdio.h>  // Include file for standard input/output

#include "../../Algorithms/Sort/Merge/cpp/mergeSort.h"
#include "../helperFunctions.h"

int unitTest1(int status)
{   
    int passed  = 0;
    
    int dataset1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int solution[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    mergeSortIntegers(dataset1, 11, 1);


    if (arrays_equal(dataset1, solution, 11))
    {
        passed = 1;
    }

    return passed;
}

int unitTest2(int status)
{   
    int passed  = 0;
    
    int dataset2[] = {2, 1, 1, 1, 1, 1, 1, 1};
    int solution[] = {1, 1, 1, 1, 1, 1, 1, 2};

    mergeSortIntegers(dataset2, 8, 1);


    if (arrays_equal(dataset2, solution, 8))
    {
        passed = 1;
    }

    return passed;
}

int unitTest3(int status)
{   
    int passed  = 0;
    
    int dataset3[] = {100, 201, 52, 3223, 24, 55, 623, 75, 8523, -9, 150};
    int solution[] = {-9, 24, 52, 55, 75, 100, 150, 201, 623, 3223, 8523};

    mergeSortIntegers(dataset3, 11, 1);


    if (arrays_equal(dataset3, solution, 11))
    {
        passed = 1;
    }

    return passed;
}

int (*unitTests[])(int) = {
   unitTest1,
   unitTest2,
   unitTest3,
    NULL};


// =============== Main Functions ===============
int main(int argc, char *argv[])
{

    unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter = 0;
    while (unitTests[counter] != NULL)
    {
        printf("========unitTest %d========\n", counter);
        if (1 == unitTests[counter](1))
        {
            printf("passed test\n");
            testsPassed++;
        }
        else
        {
            printf("failed test, missing functionality, or incorrect test\n");
        }
        counter++;
    }

    printf("%d of %d tests passed\n", testsPassed, counter);

    return 0;

}