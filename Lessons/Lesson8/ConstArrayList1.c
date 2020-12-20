//
// Created by tomer on 20/12/2020.
//
#include "ConstArrayList1.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void addPoint(constArrayList1* lst, point* p) {
    assert(p!=NULL);
    for (int i = 0; i < SIZE; i++) {
        if (lst->arr[i] == NULL) {
            lst->arr[i] = p;
            lst->len++;
            return;
        }
    }
    printf("list is full!\n");
    exit(1);
}
//create new point and add to list
void add(constArrayList1* lst, int x, int y) {
    point* p = (point*) malloc(sizeof(point));
    assert(p!=NULL);
    addPoint(lst, p);
}
//remember that the next functions are code duplications for the example
/*remove first point in list*/
void removeFirst(constArrayList1* lst) {
    for (int i = 0; i < SIZE; i++) {
        if (lst->arr[i] != NULL) {
            free(lst->arr[i]);
            lst->arr[i] = NULL;
            lst->len--;
            return;
        }
    }
    printf("cant remove from empty list\n");
    exit(1);
}
/*remove last point in list*/
void removeLast(constArrayList1* lst) {
    for (int i = SIZE - 1; i >= 0; i--) {
        if (lst->arr[i] != NULL) {
            free(lst->arr[i]);
            lst->arr[i] = NULL;
            lst->len--;
            return;
        }
    }
    printf("cant remove from empty list\n");
    exit(1);
}
/*remove the point in specific index(compare to array not to list) from the list*/
void removeAtIndex(constArrayList1* lst, int i) {
    assert(lst->arr[i] != NULL);
    free(lst->arr[i]);
    lst->arr[i] = NULL;
    lst->len--;
}
/*remove all points with specific x*/
void removeIfX(constArrayList1* lst, int x) {
    for (int i = 0; i < SIZE; i++) {
        if (lst->arr[i] != NULL && lst->arr[i]->x==x)
            removeAtIndex(lst, i);
    }
}
/* find the first point with specific y*/
point* findByY(constArrayList1* lst, int y) {
    for (int i = 0; i < SIZE; i++) {
        if (lst->arr[i] != NULL && lst->arr[i]->y==y)
            return lst->arr[i];
    }
    return NULL;
}
/*delete the list*/
void deleteList(constArrayList1* lst) {
    for (int i = 0; i < SIZE; i++) {
        if (lst->arr[i] != NULL)
            free(lst->arr[i]);
    }
}
/*return the length of list*/
int getLen(constArrayList1* lst) {
    return lst->len;
}