#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Entry {
    char *key;
    int value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry **buckets;
    int size;
    int count;
} HashMap;

void initMap(HashMap *map, int size) {
    map->size = size;
    map->count = 0;
    map->buckets = malloc(size * sizeof(Entry*));
    for (int i = 0; i < size; i++) {
        map->buckets[i] = NULL;
    }
}

int hash(char *key, int size) {
    unsigned long hash = 5381;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = ((hash << 5) + hash) + key[i];
    }
    return hash % size;
}

void insert(HashMap *map, char *key, int value) {
    int index = hash(key, map->size);
    Entry *current = map->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            current->value = value;
            return;
        }
        current = current->next;
    }
    Entry *newEntry = malloc(sizeof(Entry));
    newEntry->key = strdup(key); 
    newEntry->value = value;
    newEntry->next = map->buckets[index];  
    map->buckets[index] = newEntry;

    map->count++;
}
int get(HashMap *map, char *key) {
    int index = hash(key, map->size);
    Entry *current = map->buckets[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return -1; // Not found
}

void removeKey(HashMap *map, char *key) {
    int index = hash(key, map->size);
    Entry *current = map->buckets[index];
    Entry *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                map->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            map->count--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void freeMap(HashMap *map) {
    for (int i = 0; i < map->size; i++) {
        Entry *current = map->buckets[i];
        while (current != NULL) {
            Entry *next = current->next;
            free(current->key);
            free(current);
            current = next;
        }
    }
    free(map->buckets);
    map->buckets = NULL;
    map->size = map->count = 0;
}

int main() {
    HashMap map;
    initMap(&map, 10);

    insert(&map, "apple", 42);
    insert(&map, "banana", 99);
    insert(&map, "grape", 17);

    printf("apple → %d\n", get(&map, "apple"));   // 42
    printf("banana → %d\n", get(&map, "banana")); // 99
    printf("grape → %d\n", get(&map, "grape"));   // 17

    removeKey(&map, "banana");

    printf("banana → %d\n", get(&map, "banana")); // -1 (not found)

    freeMap(&map);
    return 0;
}
