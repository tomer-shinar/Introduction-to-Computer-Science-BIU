//
// This is the bad const sized array list
//

#ifndef LESSON8_CONSTARRAYLIST1_H
#define LESSON8_CONSTARRAYLIST1_H

#include "point.h"
#define SIZE 10

typedef struct {
    int len;
    point* arr[SIZE];
} constArrayList1;

#define initList() {0, {0}}; //not a function
void add(constArrayList1* lst, int x, int y);
void removeFirst(constArrayList1* lst);
void removeLast(constArrayList1* lst);
void removeIfX(constArrayList1* lst, int x);
point* findByY(constArrayList1* lst, int y);
void deleteList(constArrayList1* lst);
int getLen(constArrayList1* lst);

#endif //LESSON8_CONSTARRAYLIST1_H
