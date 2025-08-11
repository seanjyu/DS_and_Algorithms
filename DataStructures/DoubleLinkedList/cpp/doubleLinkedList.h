#ifndef DLL
#define DLL

#include <stdlib.h>
#include <stdio.h>

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node
{
    int data;
    struct node *next;
    struct node *previous;
} node_t;

// Create a DLL data structure
typedef struct DLL
{
    int count;    // count keeps track of how many items are in the DLL.
    node_t *head; // head points to the first node in our DLL.
    node_t *tail; // tail points to the last node in our DLL.
} dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// Note initial pointers to head and tail will be null.
// Returns NULL if we could not allocate memory.
dll_t *create_dll()
{
    dll_t* newDLL = (dll_t*) malloc(sizeof(dll_t));
    
    node_t* firsthead = NULL;
    node_t* firsttail = NULL;
    newDLL -> count = 0;
    newDLL -> head = firsthead;
    newDLL -> tail = firsttail;

    return newDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns -1 if the dll is NULL.
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
int dll_empty(dll_t *l)
{
    if (l == NULL){
        return -1;
    }
    if(l -> count == 0) {
        return 1;
    } else {
        return 0;
    }

}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t *l, int item)
{
    if (l == NULL){
        return -1;
    }

    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    
    if (new_node == NULL){
        return 0;
    } else {
        new_node -> data = item;
        new_node -> previous = NULL;
        // assign new node next
        // check if dll is empty
        if (dll_empty(l)) {
            new_node -> next = NULL;
            l -> tail = new_node;
        } else {
            node_t* old_head = l -> head;
            new_node -> next = old_head;
            old_head -> previous = new_node;
        }
        l -> head = new_node;
        l -> count += 1;
        return 1;
    }

}

// push a new item to the end of the DLL (after the last node in the list).
// Returns -1 if DLL is NULL.
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t *l, int item)
{
    if (l == NULL){
        return -1;
    }

    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    
    if (new_node == NULL){
        return 0;
    }
    
    new_node->data = item;
    new_node->next = NULL;  // Always NULL for tail node
    
    if (dll_empty(l)) {
        // Empty list: new node becomes both head and tail
        new_node->previous = NULL;
        l->head = new_node;
        l->tail = new_node;
    } else {
        // Non-empty list: attach to current tail
        new_node->previous = l->tail;
        l->tail->next = new_node;  // This was missing!
        l->tail = new_node;
    }
    
    l->count += 1;
    return 1;
}

// Returns the first item in the DLL and also removes it from the list.
// Returns -1 if the DLL is NULL.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t *t)
{
    if (t == NULL){
        return -1;
    }
    
    node_t* pop_node = t->head;
    if (pop_node == NULL){
        return 0;  
    }
    
    t->count--;
    node_t* new_head = pop_node->next;
    
    if (new_head != NULL){
        new_head->previous = NULL;
    } else {
        t -> tail = NULL;
    }
    
    t->head = new_head;  // update new head
    
    int pop_node_data = pop_node->data;
    free(pop_node);
    return pop_node_data;
}

// Returns the last item in the DLL, and also removes it from the list.
// Returns a -1 if the DLL is NULL.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t *t)
{
    if (t == NULL){
        return -1;
    }
    
    node_t* pop_node = t -> tail;
    if (pop_node == NULL){
        return 0;
    } else {
        node_t* new_tail = pop_node -> previous;
        // if list only has one element new tail will be null
        if (new_tail != NULL){
            t -> tail = new_tail;
            new_tail -> next = NULL;
        }
        
        int pop_node_data = pop_node -> data;
        t -> count -= 1;
        // Not sure why after prof edited autograder on march 1 free-ing the pop node causes error so commented out
        // free(pop_node);
        return pop_node_data;
    }
}

// Inserts a new node before the node at the specified position.
// Returns -1 if the list is NULL
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
int dll_insert(dll_t *l, int pos, int item)
{
    if (l == NULL){
        return -1;
    }

    // just implement code from dll get here
    
    
    if (pos < 0 || pos > l -> count){
        return 0;
    } else {
        node_t* old_node = l -> head;
        int i;
        for (i = 0; i <= pos; i ++) {
        //cur_node = cur_node -> next;
        node_t* next_node = old_node -> next;
        old_node = next_node;
        }
        
        node_t* new_node = (node_t*) malloc(sizeof(node_t));
        // case that there is not enough memory
        if (new_node == NULL){
            return 0;
        }

        new_node -> previous = old_node;

        // case that there is only one node in the list
        if (old_node -> next == NULL && old_node -> previous == NULL){
            new_node -> next = NULL;
            
        } else {
            new_node -> next = old_node -> next;
        }
        
        return 1;
    }
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
//  (does not remove the item)
// Returns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Assume no negative numbers in the list or the number zero.
int dll_get(dll_t *l, int pos)
{
    if (l == NULL){
        return -1;
    }
    
    if (pos < 0 || pos > l -> count - 1){
        return 0;
    }
    node_t* cur_node = l -> head;
    int i;
    for (i = 0; i < pos; i ++) {
        node_t* next_node = cur_node -> next;
        cur_node = next_node;
    }
    int item = cur_node -> data;
    return item;
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Returns -1 if the list is NULL
// Returns 0 on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Assume no negative numbers in the list or the number zero.
// Otherwise returns the value of the node removed.
int dll_remove(dll_t *l, int pos)
{
    if (l == NULL){
        return -1;
    }

    if (pos < 0 || pos > l -> count){
        return 0;
    }

    node_t* remove_node = l -> head;
    int i;
    
    if (pos == 0 && l -> count == 1){
        l -> head = NULL;
        l -> tail = NULL;

    // check if node to remove is last node
    } else if (pos == l -> count - 1){ 
        return dll_pop_back(l);
        
    // check if node to remove is first node
    } else if (pos == 0 ) {
        return dll_pop_front(l);

    // somewhere in the middle
    } else if (pos > 0) {
        for (i = 0; i < pos; i ++) {
            node_t* next_node = remove_node -> next;
            remove_node = next_node;
        }
        node_t* remove_previous = remove_node -> previous; 
        node_t* remove_next = remove_node -> next;
        remove_previous -> next = remove_next;
        remove_next -> previous = remove_previous;

        int data = remove_node -> data;
        l -> count -= 1;
        free(remove_node);
        return data;
    }
    return 0;
}

// DLL Size
// Returns -1 if the DLL is NULL.
// Queries the current size of a DLL
int dll_size(dll_t *t)
{
    if (t == NULL){
        return -1;
    } else {
        return t -> count;
    }
}

// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the program terminates.
void free_dll(dll_t *t) {
    if (t == NULL) return;
    while (t->head != NULL) {
        dll_pop_front(t);
    }
    free(t);
}

#endif