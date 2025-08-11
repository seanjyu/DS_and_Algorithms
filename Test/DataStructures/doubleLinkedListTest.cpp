
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free
#include "../../DataStructures/DoubleLinkedList/cpp/doubleLinkedList.h"

// Tests creation and deletion of list
// Dll should also be empty.
int unitTest1(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    if (dll_empty(test))
    {
        passed = 1;
    }
    free_dll(test);

    return passed;
}

// Tests push_front and size functions
int unitTest2(int status)
{   

    int passed = 0;
    dll_t *testDLL2 = create_dll();
    dll_push_front(testDLL2, 789);
    if (1 == dll_size(testDLL2))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(testDLL2);

    return passed;
}

// Tests push_back and size functions
int unitTest3(int status)
{
    int passed = 0;
    dll_t *test3 = create_dll();
    dll_push_back(test3, 142);
    if (1 == dll_size(test3))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(test3);

    return passed;
}

// Tests push_front and dll_pop_back functions
int unitTest4(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_back(test, 142);
    dll_pop_back(test);
    if (0 == dll_size(test))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(test);

    return passed;
}

// Tests push_back twice, then pops once
// then should compute the correct size.
int unitTest5(int status)
{
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_back(test, 142);
    dll_push_front(test, 142);
    dll_pop_back(test);
    if (1 == dll_size(test))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }
    free_dll(test);

    return passed;
}

// Tests push front and get
int unitTest6(int status){
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_front(test, 0);
    dll_push_front(test, 1);
    dll_push_front(test, 2);
    dll_push_front(test, 3);
    if (0 == dll_get(test, 3)){
        passed = 1;
    }
    free_dll(test);
    return passed;
}

int unitTest7(int status){
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_back(test, 0);
    dll_push_back(test, 1);
    dll_push_back(test, 2);
    dll_push_back(test, 3);
    if (3 == dll_get(test, 3)){
        passed = 1;
    }
    free_dll(test);
    return passed;
}

int unitTest8(int status){
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_back(test, 0);
    dll_push_back(test, 1);
    dll_push_back(test, 2);
    dll_push_back(test, 3);
    if (1 == dll_remove(test, 1)){
        passed = 1;
    }
    free_dll(test);
    return passed;
}

// test pop list from front with one element
int unitTest9(int status){
    int passed = 0;
    dll_t *test = create_dll();
    dll_push_back(test, 0);
    if (0 == dll_pop_front(test)){
        passed = 1;
    }
    free_dll(test);
    return passed;
}

// test pop list from front with no elements
int unitTest10(int status){
    int passed = 0;
    dll_t *test = create_dll();
    if (0 == dll_pop_front(test)){
        passed = 1;
    }
    free_dll(test);
    return passed;
}

int (*unitTests[])(int) = {
   unitTest1,
   unitTest2,
   unitTest3,
   unitTest4,
   unitTest5,
   unitTest6,
   unitTest7,
   unitTest8,
   unitTest9,
   unitTest10,
    NULL};

int main()
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