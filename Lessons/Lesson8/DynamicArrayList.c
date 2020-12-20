//
// Created by tomer on 20/12/2020.
//
#include "DynamicArrayList.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void addPoint(dynamicArrayList* lst, point* p) {
    assert(p!=NULL);
    lst->arr = (point**) realloc(lst->arr, sizeof(point*)*(lst->len + 1));
    assert(lst->arr!=NULL);
    lst->arr[lst->len++] = p;
}
//create new point and add to list
void add(dynamicArrayList* lst, int x, int y) {
    point* p = (point*) malloc(sizeof(point));
    assert(p!=NULL);
    addPoint(lst, p);
}
//remember that the next functions are code duplications for the example
/*remove first point in list*/
void removeFirst(dynamicArrayList* lst) {
    assert(lst->len > 0);
    free(lst->arr[0]);
    lst->len--;
    for (int i = 0; i < lst->len; i++) {
        lst->arr[i] = lst->arr[i+1];
    }
    lst->arr = (point**) realloc(lst->arr, sizeof(point*)*lst->len);
    assert(lst->arr != NULL);
}
/*remove last point in list*/
void removeLast(dynamicArrayList* lst) {
    assert(lst->len > 0);
    free(lst->arr[lst->len-1]);
    lst->len--;
    lst->arr = (point**) realloc(lst->arr, sizeof(point*)*lst->len);
    assert(lst->arr != NULL);
}
/*remove the point in specific index(compare to array not to list) from the list*/
void removeAtIndex(dynamicArrayList* lst, int i) {
    assert(lst->arr[i] != NULL);
    free(lst->arr[i]);
    lst->len--;
    for (; i < lst->len; i++) {
        lst->arr[i] = lst->arr[i+1];
    }
    lst->arr = (point**) realloc(lst->arr, sizeof(point*)*lst->len);
    assert(lst->arr != NULL);
}
/*remove all points with specific x*/
void removeIfX(dynamicArrayList* lst, int x) {
    for (int i = 0; i < lst->len;) {
        if (lst->arr[i]->x==x)
            removeAtIndex(lst, i);
        else
            i++;
    }
}
/* find the first point with specific y*/
point* findByY(dynamicArrayList* lst, int y) {
    for (int i = 0; i < lst->len; i++) {
        if (lst->arr[i]->y==y)
            return lst->arr[i];
    }
    return NULL;
}
/*delete the list*/
void deleteList(dynamicArrayList* lst) {
    for (int i = 0; i < lst->len; i++) {
        free(lst->arr[i]);
    }
    free(lst->arr);
}
/*return the length of list*/
int getLen(dynamicArrayList* lst) {
    return lst->len;
}

