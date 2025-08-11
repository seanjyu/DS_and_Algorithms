#include "../../DataStructures/Stack/cpp/stack.h"

// Tests the capacity of a stack
int unitTest1(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(MAX_DEPTH);
    if (MAX_DEPTH == test_s->capacity)
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Enqueu several items into a stack and test the size
int unitTest2(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(MAX_DEPTH);
    stack_enqueue(test_s, 1);
    stack_enqueue(test_s, 2);
    stack_enqueue(test_s, 3);
    stack_enqueue(test_s, 4);
    stack_enqueue(test_s, 5);
    stack_enqueue(test_s, 6);
    stack_enqueue(test_s, 7);
    stack_enqueue(test_s, 8);
    stack_enqueue(test_s, 9);
    stack_enqueue(test_s, 10);

    if (10 == stack_size(test_s))
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Tests enqueuing and fully dequeing a stack
int unitTest3(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(MAX_DEPTH);
    int i = 0;
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_dequeue(test_s);
    }

    if (0 == stack_size(test_s))
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Tests enqueuing and fully dequeing a stack multiple times
int unitTest4(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(MAX_DEPTH);
    int i = 0;
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_dequeue(test_s);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_enqueue(test_s, 1);
    }
    for (i = 0; i < MAX_DEPTH; i++)
    {
        stack_dequeue(test_s);
    }
    if (0 == stack_size(test_s))
    {
        passed = 1;
    }

    free_stack(test_s);

    return passed;
}

// Simple enqueu and deque stack test
// Also confirms that a stack is full
int unitTest5(int status)
{
    int passed = 0;

    stack_t *test_s = create_stack(1);
    stack_enqueue(test_s, 1);
    if (1 == stack_full(test_s))
    {
        passed = 1;
    }
    else
    {
        free_stack(test_s);
        return 0;
    }

    stack_dequeue(test_s);
    if (0 == stack_full(test_s))
    {
        passed = 1;
    }
    else
    {
        passed = 0;
    }

    free_stack(test_s);

    return passed;
}

// Test stack is LIFO
int unitTest6(int status){

    int passed = 0;

    stack_t *test_s = create_stack(2);
    stack_enqueue(test_s, 1);
    stack_enqueue(test_s, 2);
    int dequeue_1 = stack_dequeue(test_s);
    // if dequeue the last element that was queued then the structure follows LIFO
    if (dequeue_1 == 2) {
        passed = 1;
    } 
    return passed;
}

// test over dequeueing
int unitTest7(int status){
    int passed = 0;

    stack_t *test_s = create_stack(2);
    stack_enqueue(test_s, 1);
    stack_enqueue(test_s, 2);
    stack_dequeue(test_s);
    stack_dequeue(test_s);
    // dequeueing empty stack will return -1
    if (stack_dequeue(test_s) == -1){
        passed = 1;
    }
    return passed;
}

// test enqueue over set limit
int unitTest8(int status){
    int passed = 0;

    stack_t *test_s = create_stack(2);
    stack_enqueue(test_s, 1);
    stack_enqueue(test_s, 2);
    // enqueue over limit will return -1
    if (stack_enqueue(test_s, 3) == -1){
        passed = 1;
    }
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
