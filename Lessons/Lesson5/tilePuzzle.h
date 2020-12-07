#ifndef TILE_PUZZLE_H
#define TILE_PUZZLE_H
//pre-defined
#define PUZZLE_SIZE 9
#define PUZZLE_ROW_SIZE 3
#define MIN_VAL '1'
#define SPECIAL_VAL ' '
//self-defined
#define PUZZLE_NUM_OF_ROWS PUZZLE_SIZE/PUZZLE_ROW_SIZE
#define MAX_VAL MIN_VAL + PUZZLE_SIZE - 1
#define ERRORS_ROW_SIZE 2
#define ERRORS_DEFAULT_VALUE -1

#ifndef UTILS_H
#include "utils.h"
#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum Bool { FALSE, TRUE } bool;

typedef enum Move { VAL, DIR } move;

void createPuzzle(char tilePuzzle[][PUZZLE_ROW_SIZE], char initString[]);

void printPuzzle(char tilePuzzle[][PUZZLE_ROW_SIZE]);

void initArr(int arr[], int length, int value);
void testPuzzle(char tilePuzzle[][PUZZLE_ROW_SIZE]);

void makeMove(char tilePuzzle[][PUZZLE_ROW_SIZE], char move[]);
bool isValidMove(char tilePuzzle[][PUZZLE_ROW_SIZE], char move[]);
void translateDirectionToOffset(char direction, int* row, int* col);
bool isInbound(int n, int max);
bool isMoveStringValid(char move[]);



#endif
