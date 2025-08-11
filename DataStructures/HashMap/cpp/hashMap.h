#ifndef HASHMAP
#define HASHMAP

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
    char *key;
    float value;
    struct node *next;
} h_node;

typedef struct ht {
    int size;
    h_node **contents; 

} *hashmap;

typedef unsigned long ul;
typedef h_node **hashTable;

/**
 * A hashing algorithm. Students may pick their own
 * but it is recommended they use one of the ones 
 * from the lab. 
*/
ul get_hash(char *str) {
    // used djb2 hashfunction
    typedef unsigned long ul;
    ul hash = 5381;
    int c;
    while((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    // moving string by 5 and adding hash is the same as multiplying by 33 (bit maninpulation)

    return hash;
}

/**
 * Creates with the specified size.
*/
// hashmap map_create(int size) {
     
//     hashmap map = (hashmap) malloc(sizeof(hashmap));
//     map -> size = size;
//     hashTable table = (hashTable) malloc(sizeof(h_node) * size);
//     map -> contents = table;
//     return map;
// }
hashmap map_create(int size) {
    // Allocate space for the hashmap struct itself
    hashmap map = (hashmap) malloc(sizeof(struct ht)); // or whatever your struct is named
    if (map == NULL) {
        return NULL;
    }
    
    map->size = size;
    
    // Allocate array of h_node pointers, not h_node structs
    hashTable table = (hashTable) malloc(sizeof(h_node*) * size);
    if (table == NULL) {
        free(map);
        return NULL;
    }
    
    // Initialize all buckets to NULL - this is crucial!
    for (int i = 0; i < size; i++) {
        table[i] = NULL;
    }
    
    map->contents = table;
    return map;
}

/**
 * Gets a value from the hashmap. 
 * If a value is not found, return -1.0F
*/
float map_get(hashmap map, char *key) {
    int hash = get_hash(key) % (map -> size);
    hashTable table = map -> contents;
    if (table[hash] == NULL || table[hash] -> key == NULL) {
        return -1.0F;
    } else {
        h_node *cur = table[hash];
        while (cur != NULL) {
            int compare_result = strcmp(cur -> key, key);
            if(compare_result == 0) { 
                return cur -> value;}
            cur = cur->next;
        }
        return -1.0F;
    }
}

/**
 * Removes an item from the hashmap, returning
 * the value of the item. If an item
 * is not found to remove, return -1.0F
*/
float map_del(hashmap map, char *key) {
    
    int hash = get_hash(key) % map->size;
    hashTable table = map -> contents;
    if (table[hash] == NULL || table[hash] -> key == NULL) {
        return -1.0F;
    } else {
        h_node *cur = table[hash];
        h_node *prev = NULL;
        while (cur != NULL) {
            if(strcmp(cur -> key, key) == 0) {
                float return_value = cur -> value;
                if (prev != NULL) {
                    prev -> next = cur -> next;
                } else {
                    table[hash] = cur -> next;
                }
                
                free(cur); 
                return return_value;
            }
            prev = cur;
            cur = cur->next;
        }
        return -1.0F;
    }
    
}

/**
 * Stores a value into the hashmap. 
 * 1. if a key is already in the map, overwrites it with the new value
 * 2. if the key is not in the map, adds the key/value (node) pair.
*/
void map_put(hashmap map, char *new_key, float value) {
    // calcualte hash
    int hash = get_hash(new_key) % map->size;
    h_node *new_node = (h_node*) malloc(sizeof(h_node));
    new_node -> key = (char *)malloc(strlen(new_key) + 1);
    strcpy(new_node->key, new_key);
    new_node -> value = value;
    new_node -> next = NULL;
    hashTable table = map -> contents;
    h_node *table_node = table[hash];
    if (table_node == NULL || table_node -> key == NULL){
        table[hash] = new_node;
    } else {
        h_node *cur = table[hash];
        if (strcmp(cur -> key, new_key) == 0) {
            cur -> value = value;
            free(new_node -> key);
            free(new_node);
            return;
        }
        while (cur -> next != NULL) {
            // if duplicate key then 
            if (strcmp(cur->key, new_key) == 0) {
                cur -> value = value;
                free(new_node -> key);
                free(new_node);
                return;
            }
            cur = cur -> next;
            
        }
        cur -> next = new_node;
    }
    
}

/**
 * Prints the map in the specified format of
 * {key : value, key : value}
 * Notice there is not a comma after the last
 * value. Refer to lab if needed. It should
 * only produce strings of .2f (two decimals). 
*/
void map_print(hashmap map) {
    hashTable table = map -> contents;
    printf("{");
    int print_once = 0, i;
    for(i = 0; i < map -> size; i++) {
        if(table[i] != NULL) {
            h_node *cur = table[i];
            while(cur != NULL && cur -> key != NULL) {
                if(print_once) printf(", ");
                printf("%s : %.2f", cur->key, cur->value);
                cur = cur->next;
                if(print_once == 0) print_once = 1;
            }
        }
    }
    printf("}\n");
   
}

/**
 * Frees the map in memory.
*/
void map_free(hashmap map) {
 
    int j;
    int size = map -> size;
    hashTable table = map -> contents;
    for(j = 0; j < size; j++) {
        h_node *cur = table[j];
        while(cur != NULL) {
            h_node *tmp = cur -> next;
            free(cur -> key);
            free(cur);
            cur = tmp;
        }
    }
    free(map -> contents);
    free(map);
}
#endif