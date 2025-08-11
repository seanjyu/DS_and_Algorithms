#ifndef STACK
#define STACK

#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Stores the maximum 'depth' of stack.
// (i.e. capacity cannot exceed MAX_DEPTH for any stack)
#define MAX_DEPTH 32

// Create a node data structure to store data within stack. 
// In thiis implementation integers are stored
typedef struct node
{
    int data;
    struct node *next;
} node_t;

// Create a stack data structure
typedef struct stack
{
    int count;             // count keeps track of how many items are in the stack.
    unsigned int capacity; // Stores the maximum size of stack
    node_t *head;          // head points to a node on the top of stack.
} stack_t;


// Creates a stack
// Returns a pointer to a newly created stack.
// The stack should be initialized with data on the heap.
stack_t *create_stack(unsigned int capacity)
{
    // Modify the body of this function as needed.
    stack_t* myStack = (stack_t*) malloc(sizeof(stack_t));
    node_t* firstNode = NULL;
    myStack -> count = 0;
    myStack -> capacity = capacity;
    myStack -> head = firstNode;

    return myStack;
}


// Check if the stack is empty
int stack_empty(stack_t *s)
{
    if (s -> count == 0){
        return 1;
    }
    return 0;
}

// Check if the stack is full
int stack_full(stack_t *s)
{
    
    if (s -> count == s -> capacity){
        return 1;
    }
    return 0;
}

// Enqueue a new item
int stack_enqueue(stack_t *s, int item)
{
    if (stack_full(s) == 1){
        return -1;
    }

    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    
    newNode -> data = item;
    newNode -> next = s -> head;
    s -> head = newNode;
    s -> count += 1;
    return 1;
}

// Dequeue an item
int stack_dequeue(stack_t *s)
{
    if (stack_empty(s) == 1){
        return -1;
    }

    node_t* pop_node = s -> head;
    if (pop_node != NULL){
        s -> head = pop_node -> next;
        s -> count -= 1;
        int pop_node_data = pop_node -> data;
        free(pop_node);
        return pop_node_data;
    } else {
        return -1;
    }
}


// Function to return stack size
unsigned int stack_size(stack_t *s)
{
    return s -> count;
}


// Function to Free memory from stack
void free_stack(stack_t *s)
{

    while (stack_empty(s) != 1){
        stack_dequeue(s);
    }

    free(s -> head);
    free(s);   
}

#endif