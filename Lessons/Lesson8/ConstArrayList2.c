//
// Created by tomer on 20/12/2020.
//

#include "ConstArrayList2.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void addPoint(constArrayList2* lst, point* p) {
    assert(p!=NULL);
    assert(lst->len < SIZE);
    lst->arr[lst->len++] = p;
}
//create new point and add to list
void add(constArrayList2* lst, int x, int y) {
    point* p = (point*) malloc(sizeof(point));
    assert(p!=NULL);
    addPoint(lst, p);
}
//remember that the next functions are code duplications for the example
/*remove first point in list*/
void removeFirst(constArrayList2* lst) {
    assert(lst->len > 0);
    free(lst->arr[0]);
    lst->len--;
    for (int i = 0; i < lst->len; i++) {
        lst->arr[i] = lst->arr[i+1];
    }
    lst->arr[lst->len] = NULL;
}
/*remove last point in list*/
void removeLast(constArrayList2* lst) {
    assert(lst->len > 0);
    lst->len--;
    lst->arr[lst->len] = NULL;
}
/*remove the point in specific index(compare to array not to list) from the list*/
void removeAtIndex(constArrayList2* lst, int i) {
    assert(lst->arr[i] != NULL);
    free(lst->arr[i]);
    lst->len--;
    for (; i < lst->len; i++) {
        lst->arr[i] = lst->arr[i+1];
    }
    lst->arr[lst->len] = NULL;
}
/*remove all points with specific x*/
void removeIfX(constArrayList2* lst, int x) {
    for (int i = 0; i < lst->len;) {
        if (lst->arr[i]->x==x)
            removeAtIndex(lst, i);
        else
            i++;
    }
}
/* find the first point with specific y*/
point* findByY(constArrayList2* lst, int y) {
    for (int i = 0; i < lst->len; i++) {
        if (lst->arr[i]->y==y)
            return lst->arr[i];
    }
    return NULL;
}
/*delete the list*/
void deleteList(constArrayList2* lst) {
    for (int i = 0; i < lst->len; i++) {
        free(lst->arr[i]);
    }
}
/*return the length of list*/
int getLen(constArrayList2* lst) {
    return lst->len;
}