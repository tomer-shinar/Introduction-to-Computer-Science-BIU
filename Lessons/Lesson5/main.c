#include <stdio.h>
#include "tilePuzzle.h"
#include "utils.h"

void test1() {
	printWithColor("test 1:", 'b');
	printf("\n\n");
	char* initString = "1354672 8";
	char tilePuzzle[PUZZLE_NUM_OF_ROWS][PUZZLE_ROW_SIZE]={{'\0'}};
	createPuzzle(tilePuzzle, initString);
	printPuzzle(tilePuzzle);
	printf("\n\n");
	makeMove(tilePuzzle, "6d");
	printPuzzle(tilePuzzle);
	printf("\n\n");
	makeMove(tilePuzzle, "4r");
	printPuzzle(tilePuzzle);
	printf("\n\n");
	makeMove(tilePuzzle, "2u");
	printPuzzle(tilePuzzle);
	printf("\n\n");
	testPuzzle(tilePuzzle);
	printf("\n");
}

void test2() {
	printWithColor("test 2:", 'b');
	printf("\n\n");
	char* initString = "123 56478";
	char tilePuzzle[PUZZLE_NUM_OF_ROWS][PUZZLE_ROW_SIZE] = {{'\0'}};
	createPuzzle(tilePuzzle, initString);
	printPuzzle(tilePuzzle);
	printf("\n\n");
	makeMove(tilePuzzle, "4u");
	printPuzzle(tilePuzzle);
	printf("\n\n");
	makeMove(tilePuzzle, " R");
	printPuzzle(tilePuzzle);
	printf("\n\n");
	makeMove(tilePuzzle, "8L");
	printPuzzle(tilePuzzle);
	printf("\n\n");
	testPuzzle(tilePuzzle);
	printf("\n");
}

int main() {
	test1();
	test2();
}
