//
// Created by tomer on 27/12/2020.
//
#include "logic.h"

int andOp(int x, int y) {
    return x && y;
}
int orOp(int x, int y) {
    return x || y;
}
int xorOp(int x, int y) {
    return (x || y) && !(x && y);
}


















int nandOp(int x, int y) {
    return !(x&&y);
}