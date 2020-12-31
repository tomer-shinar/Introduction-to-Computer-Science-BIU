#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Queue* initStack() {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    if (s == NULL) {
        printf("failed to malloc\n");
        exit(1);
    }
}
void push(Stack* stack, int val) {
    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL) {
        printf("failed to malloc\n");
        exit(1);
    }
    new->data = val;
    new->prev = NULL;
    new->next = stack->head;
    new->next->prev = new;
    stack->head = new;
}
int pop(Stack* stack) {
    if (stack->head == NULL) {
        printf("Error\n");
        exit(1);
    }
    Node* first = stack->head;
    int val = first->data;
    stack->head = first->next;
    if (stack->head != NULL) {
        stack->head->prev = NULL;
    }
    free(first);
    return val;
}
void destroyStack(Stack* stack) {
    Node* n = stack->head;
    while (n != NULL) {
        Node* toFree = n;
        n = n->next;
        free(toFree);
    }
    free(stack);
}

