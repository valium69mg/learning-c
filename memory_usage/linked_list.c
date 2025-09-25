#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int *data;
    struct Node *next;
} Node;

typedef struct {
    Node **nodes;
    int size;
    int capacity;
} LinkedList;

void initLinkedList(LinkedList *linkedList) {
    // init struct fields
    linkedList->capacity = 10;
    linkedList->size = 0;
    linkedList->nodes = malloc(10* sizeof(Node*));
    for (int i = 0; i < 10; i++) { // fill with null
        linkedList->nodes[i] = NULL;
    }
}

void add(LinkedList *linkedList, int value) {
    if (linkedList->capacity == linkedList->size) { // realloc memory if max memory exceeded
        linkedList->capacity *= 2;
        linkedList->nodes = realloc(linkedList->nodes, linkedList->capacity * sizeof(Node*));
    } 
    Node *newNode = malloc(sizeof(Node));
    newNode->data = malloc(sizeof(int));
    *(newNode->data) = value;
    if (linkedList->size == 0) { // if first element
        newNode->next = NULL;
        linkedList->nodes[0] = newNode;
        linkedList->size = 1;
        return;
    } 
    // if not first element
    int insertIndex = linkedList->size;
    int previousIndex = linkedList->size - 1;
    // update next on previous index
    Node *previousNode = linkedList->nodes[previousIndex];
    previousNode->next = newNode;
    // build the current
    newNode->next = NULL;
    linkedList->nodes[insertIndex] = newNode;
    linkedList->size++;
}

void freeLinkedList(LinkedList *linkedList) {
    for (int i = 0; i < linkedList->size; i++) {
        Node *current = linkedList->nodes[i];
        free(current->data);
        free(current);
    }
    free(linkedList->nodes);
}

void printList(LinkedList *linkedList) {
    for (int i = 0; i < linkedList->size; i++) {
        printf("%d -> ", *(linkedList->nodes[i]->data));
    }
    printf("NULL\n");
}


int main() {
    LinkedList list;
    initLinkedList(&list);
    add(&list, 5);
    add(&list, 10);
    add(&list, 15);
    printList(&list);
    freeLinkedList(&list);
    return 0;
}