//
// Created by tomer on 31/12/2020.
//

#ifndef LESSON11_STACK_H
#define LESSON11_STACK_H

#include "queue.h"

typedef struct {
    Node* head;
} Stack;

Queue* initStack();
void push(Stack* stack, int val);
int pop(Stack* stack);
void destroyStack(Stack* stack);

#endif //LESSON11_STACK_H
