//
// Created by tomer on 17/12/2020.
//
#include "linkedList.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

/**
 * initialize new empty list
 */
node* initList() {
    node* lst = (node*) malloc(sizeof(node));
    assert(lst != NULL);
    (*lst).next = NULL;
    lst->prev = NULL;
    lst->val = NULL;
    return lst;
}
/**add allocated array to list**/
void addArray(node* lst, array* arr) {
    node* newNode = (node*) malloc(sizeof(node));
    assert(newNode != NULL);
    newNode->next = lst->next;
    newNode->prev = lst;
    if(lst->next != NULL) {
        lst->next->prev = newNode;
    }
    lst->next = newNode;
    lst->val = arr;
}
/** read new array and add to list*/
void add(node* lst, int len) {
    array* newArr = (array*) malloc(sizeof(array));
    assert(newArr != NULL);
    newArr->len = len;
    newArr->arr = (int*) malloc(len*sizeof(int));
    assert(newArr->arr != NULL);
    for (int i = 0; i < len; i++) {
        scanf("%d", newArr->arr + i);
    }
    addArray(lst, newArr);
}
//note that the next functions have code duplication used only for the example
/* remove first array in list*/
void removeFirst(node* lst) {
    assert(lst!=NULL);
    if (lst->next == NULL) {
        //empty list
        return;
    }
    node* removedNode = lst->next;
    lst->next = lst->next->next;
    if (lst->next!= NULL)
        lst->next->prev = lst;
    free(removedNode->val->arr);
    free(removedNode->val);
    free(removedNode);
}
/* remove last element of array*/
void removeLast(node* lst) {
    if (lst->next == NULL) {
        //empty list
        return;
    }
    node* removedNode = lst->next;
    while (removedNode->next!=NULL) {
        //while not last
        removedNode = removedNode->next;
    }
    removedNode->prev->next = NULL;

    free(removedNode->val->arr);
    free(removedNode->val);
    free(removedNode);
}
/*check if array contains x*/
int contains(array* arr, int x) {
    for (int i = 0; i < arr->len; i++) {
        if (arr->arr[i] == x) {
            return 1;
        }
    }
    return 0;
}
/*remove a node from list*/
void removeArray(node* n) {
    n->prev->next = n->next;
    if(n->next!= NULL) {
        n->next->prev = n->prev;
    }
    free(n->val->arr);
    free(n->val);
    free(n);
}
/*remove array from list if array contains x*/
void removeIfContains(node* lst, int x) {
    node* next = lst->next;
    while(next != NULL) {
        if (contains(next->val, x))
        {
            node* toRemove = next;
            next = next->next;
            removeArray(toRemove);
        } else
            next = next->next;
    }
}
/*return the first array in the list that have length len*/
array* findByLen(node* lst, int len){
    node* next = lst->next;
    while(next != NULL) {
        if (next->val->len == len)
            return next->val;
        next = next->next;
    }
    return NULL;
}
/*delete the list*/
void deleteList(node* lst) {
    while (lst!= NULL) {
        node *next = lst->next;
        if (lst->val != NULL) {
            free(lst->val->arr);
            free(lst->val);
        }
        free(lst);
        lst = next;
    }
    //try to find the problem here
}
/*returns the length of the list*/
int getLen(node* lst) {
    int counter = 0;
    for (node* next = lst->next; next!= NULL; next = next->next) {
        counter++;
    }
    return counter;
}
