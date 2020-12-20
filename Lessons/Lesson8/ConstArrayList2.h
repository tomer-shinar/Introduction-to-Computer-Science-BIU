//
// this is better implementation for cont sized array list
//

#ifndef LESSON8_CONSTARRAYLIST2_H
#define LESSON8_CONSTARRAYLIST2_H

#include "point.h"
#define SIZE 10
typedef struct {
    int len;
    point* arr[SIZE];
} constArrayList2;

#define initList() {0, {0}}; //not a function
void add(constArrayList2* lst, int x, int y);
void removeFirst(constArrayList2* lst);
void removeLast(constArrayList2* lst);
void removeIfX(constArrayList2* lst, int x);
point* findByY(constArrayList2* lst, int y);
void deleteList(constArrayList2* lst);
int getLen(constArrayList2* lst);
#endif //LESSON8_CONSTARRAYLIST2_H
