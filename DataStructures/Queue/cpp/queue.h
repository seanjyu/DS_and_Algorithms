
#ifndef QUEUE
#define QUEUE
#include <stdlib.h> // for malloc/free

struct queue
{
    unsigned int back;     // The next free position in the queue
                           // (i.e. the end or tail of the line)
    unsigned int front;    // Current 'head' of the queue
                           // (i.e. the front or head of the line)
    unsigned int size;     // How many total elements we currently have enqueued.
    unsigned int capacity; // Maximum number of items the queue can hold
    int *data;             // Integer data
};

// Creates a global definition of 'queue_t' 
typedef struct queue queue_t;

// Create a queue
// Returns a pointer to a newly created queue.
// data should be stored on the heap (malloc)
queue_t *create_queue(unsigned int _capacity)
{
    // store data in heap and assign capacity
    queue_t *myQueue = (queue_t*) malloc(sizeof(queue_t));
    myQueue -> capacity = _capacity;
    myQueue -> data = (int*) malloc(sizeof(int) * _capacity);
    myQueue -> front = 0;
    myQueue -> back = 0;
    myQueue -> size = 0;

    return myQueue;
}

// Check if the queue is empty
//  Returns 1 if true (The queue is completely empty)
// Returns 0 if false (the queue has at least one element enqueued)
int queue_empty(queue_t *q)
{
    if (q -> size == 0){
        return 1;
    } else {
        return 0;
    }
}

// Check if the queue is Full
int queue_full(queue_t *q)
{
    if (q -> size == q -> capacity){
        return 1;
    } else {
        return 0;
    }

}

// Enqueue a new item
int queue_enqueue(queue_t *q, int item)
{
    // check if queue is full
    if (queue_full(q) == 1){
        return -1;
    }

    // push data
    q -> data[q -> back] = item;
    q -> back = (q -> back + 1) % (q -> capacity);
    q -> size += 1;
    return 0;
    
}

// Dequeue an item
int queue_dequeue(queue_t *q)
{
    if (queue_empty(q) == 1){

        //fputs("no items to dequeue!\n", stderr);
        //return EXIT_FAILURE;
        return -1;
    } 
    
    int sol = q -> data[q -> front];
    q -> front = (q -> front + 1) % (q -> capacity);
    q -> size -= 1;

    return sol;
}

// Return current queue size
unsigned int queue_size(queue_t *q)
{
    return q -> size;
}

// Free queue allocation
void free_queue(queue_t *q)
{
 free(q -> data);
 free(q);
}
#endif

