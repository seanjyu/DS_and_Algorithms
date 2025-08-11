#include "../../DataStructures/HashMap/cpp/hashMap.h"

// test map_create
int unitTest1(int status){
  

  int passed  = 0;

  hashmap test1 = map_create(1);

  if (test1 -> size == 1){
    passed = 1;
  }
  map_free(test1);
  return passed;
}

// test map_put and map_get
int unitTest2(int status){
  int passed  = 0;
  hashmap test2 = map_create(2);
  char key1[] = "Apple";
  char key2[] = "pear";
  map_put(test2, key1, 2.08);
  map_put(test2, key2, 2.08);
  if (map_get(test2, key1) == 2.08F) {
    passed = 1;
  }
  
  map_free(test2);
  return passed;
}

// test map_put and map_del
int unitTest3(int status){
  int passed  = 0;
  
  hashmap test3 = map_create(1);
  char key1[] = "pear";
  map_put(test3, key1, 2.08);
  
  if (map_del(test3, key1) == 2.08F) {
    passed = 1;
  }
  
  map_free(test3);
  return passed;
}

// test map_put override
int unitTest4(int status){
  int passed  = 0;
  char key1[] = "Apple";
  char key2[] = "Orange";
  char key3[] = "Banana";
  hashmap test4 = map_create(3);
  map_put(test4, key1, 2.08);
  map_put(test4, key2, 3.08);
  map_put(test4, key3, 3.08);
  map_put(test4, key1, 3.08);
  if (map_get(test4, key1) == 3.08F) {
    passed = 1;
  }
  
  map_free(test4);
  return passed;
}

// test collisions (create array with size one)
int unitTest5(int status){
  int passed  = 0;
  char key1[] = "Apple";
  char key2[] = "Orange";
  
  hashmap test5 = map_create(1);
  map_put(test5, key1, 2.08);
  map_put(test5, key2, 3.08);
  if (map_get(test5, key2) == 3.08F) {
    passed = 1;
  }
  
  map_free(test5);
  return passed;
}

// test get non-existing node return -1F
int unitTest6(int status){
  int passed  = 0;

  char key1[] = "Apple";
  char key2[] = "Orange";
  
  hashmap test6 = map_create(3);
  map_put(test6, key1, 2.08);
  if (map_get(test6, key2) == -1.0F) {
    passed = 1;
  }
  
  map_free(test6);
  return passed;
}

// test delete non-existing node return -1F
int unitTest7(int status){
  int passed  = 0;
  
  char key1[] = "Apple";
  char key2[] = "Orange";
  
  hashmap test7 = map_create(3);
  map_put(test7, key1, 2.08);
  if (map_del(test7, key2) == -1.0F) {
    passed = 1;
  }
  
  map_free(test7);
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
    NULL};

int main() {

    unsigned int testsPassed = 0;
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