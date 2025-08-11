# Data Structures Testing
The following document outlines the test cases used for testing.

# Quick Navigation
[Double Linked List](#double-linked-list) <br>
[Hashmaps](#hashmaps) <br>
[Queue](#queue)<br>
[Stack](#stack)<br>

## Double Linked List
### Test 1 - List Creation and Empty Check
Verify list initialization and empty state detection
### Test 2 - Push Front Operation
Test adding element to front and size tracking
### Test 3 - Push Back Operation
Test adding element to back and size tracking
### Test 4 - Push Back Then Pop Back
Test complete add/remove cycle from back
### Test 5 - Mixed Push Operations with Pop
Test mixed front/back insertion with back removal
### Test 6 - Push Front and Index Access
Verify push_front ordering with get() function. e.g. [3,2,1,0] → get(3) should return 0
### Test 7 - Push Back and Index Access
Verify push_back ordering with get() function. e.g. [0,1,2,3] → get(3) should return 3
### Test 8 - Remove Element by Index
Test removing element at specific position
### Test 9 - Pop Front with Single Element
Test removing from front of single-element list
### Test 10 - Pop Front from Empty List
Test edge case of popping from empty list

## Hashmaps
### Test 1 - Map Creation
Verify map initialization with specified size
### Test 2 - Put and Get Operations
Test inserting key-value pairs and retrieving values
### Test 3 - Put and Delete Operations
Test inserting key-value pair and then deleting it
### Test 4 - Value Override
Test updating existing key with new value
### Test 5 - Collision Handling
Test multiple insertions with size-1 map to force collisions. i.e. in test both "Apple" and "Orange" keys stored in single bucket.
### Test 6 - Get Non-Existing Key
Test retrieving value for key that doesn't exist. Should return -1.0F for missing keys
### Test 7 - Delete Non-Existing Key
Test deleting key that doesn't exist in the map. Should return -1.0F when attempting to delete missing keys

## Queue
### Test 1 - Queue Creation and Capacity
Verify queue initialization with specified capacity.
### Test 2 - Multiple Enqueue Operations
Test adding multiple items and size tracking.
### Test 3 - Complete Enqueue/Dequeue Cycle
Test full queue fill and empty operations.
### Test 4 - Multiple Fill/Empty Cycles
Test repeated enqueue/dequeue cycles for queue reusability.
### Test 5 - Queue Full Detection
Test queue_full() function with capacity-1 queue.
### Test 6 - FIFO Behavior Verification
Test FIFO ordering of queue operations.
### Test 7 - Underflow Handling
Test dequeuing from empty queue returns error code. Should return -1 when dequeuing empty queue.
### Test 8 - Overflow Handling
Test enqueuing to full queue returns error code. Should return -1 when enqueuing to full queue.

## Stack
### Test 1 - Stack Creation and Capacity
Verify stack initialization with MAX_DEPTH capacity
### Test 2 - Multiple Push Operations
Test adding multiple items and size tracking
Note: Uses stack_enqueue() for push operations
### Test 3 - Complete Push/Pop Cycle
Test full stack fill and empty operations
### Test 4 - Multiple Fill/Empty Cycles
Test repeated push/pop cycles for stack reusability
### Test 5 - Stack Full Detection
Test stack_full() function with capacity-1 stack. Verifies full state detection and clearing.
### Test 6 - LIFO Behavior Verification
Test Last-In-First-Out ordering of stack operations. Push 1, then 2 → pop should return 2 (last pushed).
### Test 7 - Underflow Handling
Test popping from empty stack returns error code. Should return -1 when popping empty stack.
### Test 8 - Overflow Handling
Test pushing to full stack returns error code. Should return -1 when pushing to full stack.