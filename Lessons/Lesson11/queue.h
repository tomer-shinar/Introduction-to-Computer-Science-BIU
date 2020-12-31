//
// Created by tomer on 31/12/2020.
//

#ifndef LESSON11_QUEUE_H
#define LESSON11_QUEUE_H

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
typedef struct Node Node;
typedef struct {
    Node* head;
    Node* last;
} Queue;

Queue* initQueue();
void enqueue(Queue* queue, int val);
int dequeue(Queue* queue);
void destroyQueue(Queue* queue);

#endif //LESSON11_QUEUE_H
