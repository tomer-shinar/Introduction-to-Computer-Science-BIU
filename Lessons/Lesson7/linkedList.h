//
// Created by tomer on 17/12/2020.
//

#ifndef LESSON7_LINKEDLIST_H
#define LESSON7_LINKEDLIST_H

typedef struct {
    int len;
    int* arr;
} array;

struct node {
    array* val;
    struct node* next;
    struct node* prev;
};
typedef struct node node;

node* initList();
void add(node* lst, int len);
void removeFirst(node* lst);
void removeLast(node* lst);
void removeIfContains(node* lst, int x);
array* findByLen(node* lst, int len);
void deleteList(node* lst);
int getLen(node* lst);



#endif //LESSON7_LINKEDLIST_H
