//
// Created by tomer on 20/12/2020.
//

#ifndef LESSON8_DYNAMICARRAYLIST_H
#define LESSON8_DYNAMICARRAYLIST_H

#include "point.h"
typedef struct {
    int len;
    point** arr;
} dynamicArrayList;

#define initList() {0, 0}; //not a function
void add(dynamicArrayList* lst, int x, int y);
void removeFirst(dynamicArrayList* lst);
void removeLast(dynamicArrayList* lst);
void removeIfX(dynamicArrayList* lst, int x);
point* findByY(dynamicArrayList* lst, int y);
void deleteList(dynamicArrayList* lst);
int getLen(dynamicArrayList* lst);

#endif //LESSON8_DYNAMICARRAYLIST_H
