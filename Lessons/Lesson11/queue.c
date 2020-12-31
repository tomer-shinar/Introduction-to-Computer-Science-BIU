#include "queue.h"
#include "stdio.h"
#include "stdlib.h"

Queue* initQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("failed to malloc\n");
        exit(1);
    }
    q->head = q->last = NULL;
    return q;
}

void enqueue(Queue* queue, int val) {
    Node* new = (Node*) malloc(sizeof(Node));
    if (new == NULL) {
        printf("failed to malloc\n");
        exit(1);
    }
    new->data = val;
    if (queue->last == NULL) {
        // queue empty
        new->next = new->prev = NULL;
        queue->last = queue->head = new;
    } else {
        new->prev = queue->last;
        new->next = NULL;
        queue->last->next = new;
        queue->last = new;
    }
}
int dequeue(Queue* queue) {
        if (queue->head == NULL) {
            printf("Error\n");
            exit(1);
        }
        Node* first = queue->head;
        int val = first->data;
        queue->head = first->next;
        if (queue->head == NULL) {
            queue->last = NULL;
        } else {
            queue->head->prev = NULL;
        }
        free(first);
        return val;
}
void destroyQueue(Queue* queue) {
    Node* n = queue->head;
    while (n != NULL) {
        Node* toFree = n;
        n = n->next;
        free(toFree);
    }
    free(queue);
}
