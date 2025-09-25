#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DinamicArray;

void initArray(DinamicArray *arr, int capacity) {
    arr->data = (int *)malloc(capacity * sizeof(int));
    arr->size = 0;
    arr->capacity = capacity;
}

void resizeArray(DinamicArray *arr) {
    arr->capacity *= 2;
    arr->data = (int *) realloc(arr->data, arr->capacity * sizeof(int));
}

void insert(DinamicArray *arr, int value) {
    if (arr->size  == arr->capacity) { // if we reach max capacity
        resizeArray(arr);
    }
    arr->data[arr->size++] = value;
}

void printArray(DinamicArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void freeArray(DinamicArray *arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = arr->capacity = 0;
}

int main() {
    // init array
    DinamicArray arr;
    initArray(&arr, 4);
    
    // insert  numbers 1 through 10
    for (int i = 0; i <= 10; i++) {
        insert(&arr, i);
    }

    printArray(&arr);

    freeArray(&arr);
}