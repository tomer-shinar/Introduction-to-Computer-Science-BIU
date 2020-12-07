#ifndef TILE_PUZZLE_H

#define TILE_PUZZLE_H
#define PUZZLE_SIZE 9
#define PUZZLE_ROW_SIZE 3
#define PUZZLE_NUM_OF_ROWS PUZZLE_SIZE/PUZZLE_ROW_SIZE
#define MIN_VAL '1'
#define MAX_VAL MIN_VAL + PUZZLE_SIZE - 1
#define ERRORS_ROW_SIZE 2
#define ERRORS_DEFAULT_VALUE -1
#define SPECIAL_VAL ' '

#ifndef UTILS_H
#include "utils.h"
#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum Bool { FALSE, TRUE } bool;

typedef enum Move { VAL, DIR } move;

void createPuzzle(char tilePuzzle[][PUZZLE_ROW_SIZE], char initString[]);

void makeMove(char tilePuzzle[][PUZZLE_ROW_SIZE], char move[]);
bool isValidMove(char tilePuzzle[][PUZZLE_ROW_SIZE], char move[]);
void translateDirectionToOffset(char direction, int* row, int* col);
bool isInbound(int n, int max);
bool isMoveStringValid(char move[]);


void printPuzzle(char tilePuzzle[][PUZZLE_ROW_SIZE]);


void initArr(int arr[], int length, int value);
void testPuzzle(char tilePuzzle[][PUZZLE_ROW_SIZE]);


#endif
