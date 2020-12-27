//
// Created by tomer on 27/12/2020.
//

#ifndef LESSON10_PARSER_H
#define LESSON10_PARSER_H

#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include "arithmetics.h"
#include <stdio.h>
#include "compare.h"
#include "logic.h"

void removeComment(char* line);
int parseConditionLine(char* line);
int expValue(char* exp);
int* getNumbers(char* asString, int* len);
char** split(char* toSplit, char* splitBy, int* len);
char* strip(char* str);
int (**getOperations(char* str, int* len))(int, int);
int (*getArithOperation(char* str))(int, int);
void makeLower(char* str);
int (*getComparator(char* str)) (int, int);
int (*getOperation(char* str, char** names, int (*operations[])(int, int), int len))(int, int);
int (*parseOperationLine(char* line)) (int, int);

#endif //LESSON10_PARSER_H
