#include "tilePuzzle.h"


bool
isInbound(int n, int max) {
	if (0 <= n && n < max) return TRUE;
	return FALSE;
}

void
createPuzzle(char tilePuzzle[][PUZZLE_ROW_SIZE], char initString[]) {
	const int initStringLength = strlen(initString);
	if (initStringLength != PUZZLE_SIZE) return;
	for (int k = 0; k < initStringLength; ++k) {
		const int i = k / (PUZZLE_NUM_OF_ROWS);
		const int j = k % PUZZLE_ROW_SIZE;
		tilePuzzle[i][j] = initString[k];
	}
}

bool
isValidMove(char tilePuzzle[][PUZZLE_ROW_SIZE], char move[]) {
	if (!isMoveStringValid(move)) return FALSE;
	int i, j;
	bool match = FALSE;
	for (i = 0; i < PUZZLE_NUM_OF_ROWS; ++i) {
		for (j = 0; j < PUZZLE_ROW_SIZE; ++j) {
			if (tilePuzzle[i][j] == move[VAL]) {
				match = TRUE;
				break;
			}
		}
		if (match) break;
	}
	int row = i, col = j;
	translateDirectionToOffset(move[DIR], &row, &col);
	if (!isInbound(col,PUZZLE_ROW_SIZE) || !isInbound(row,PUZZLE_NUM_OF_ROWS)) return FALSE;
	if (move[VAL] != ' ' && tilePuzzle[row][col] != ' ') return FALSE;
	return TRUE;
}

void
translateDirectionToOffset(char direction, int* row, int* col) {
	switch (toupper(direction)) {
		case 'L':
			*col -= 1;
			break;
		case 'U':
			*row -= 1;
			break;
		case 'R':
			*col += 1;
			break;
		case 'D':
			*row += 1;
			break;
		default:
			break;
	}
}


bool
isMoveStringValid(char move[]) {
	if (strlen(move) != 2) return FALSE;
	if ((move[VAL] < MIN_VAL || move[VAL] > MAX_VAL) && move[VAL] != SPECIAL_VAL) return FALSE;
	char directions[] = {'L', 'U', 'R', 'D'};
	const char upperCaseDirection = toupper(move[DIR]);
	const int length = strlen(directions);
	for (int i = 0; i < length; ++i) {
		if (directions[i] == upperCaseDirection) return TRUE;
	}
	return FALSE;
}

void
makeMove(char tilePuzzle[][PUZZLE_ROW_SIZE], char move[]) {
	if (!isValidMove(tilePuzzle, move)) return;
	int i, j;
	bool match = FALSE;
	for (i = 0; i < PUZZLE_NUM_OF_ROWS; ++i) {
	  for (j = 0; j < PUZZLE_ROW_SIZE; ++j) {
		if (tilePuzzle[i][j] == move[VAL]) {
		  match = TRUE;
		  break;
		}
	  }
	  if (match) break;
	}
	int row = i, col = j;
	translateDirectionToOffset(move[DIR], &row, &col);

	//swtich tiles
	const char temp = tilePuzzle[i][j];
	tilePuzzle[i][j] = tilePuzzle[row][col];
	tilePuzzle[row][col] = temp;
}


void
printPuzzle(char tilePuzzle[][PUZZLE_ROW_SIZE]) {
	for (int j = 0; j < PUZZLE_ROW_SIZE; ++j) {
		printf("  __");
	}
	printf("\n");
	for (int i = 0; i < PUZZLE_NUM_OF_ROWS; ++i) {
		printf("| ");
		for (int j = 0; j < PUZZLE_ROW_SIZE; ++j) {
			printf("%c | ", tilePuzzle[i][j]);
		}
		printf("\n");
		for (int j = 0; j < PUZZLE_ROW_SIZE; ++j) {
			printf("  __");
		}
		printf("\n");
	}
}

char**
createSolvedBoard() {
	char initString[PUZZLE_SIZE + 1];
	initString[PUZZLE_SIZE] = '\0';
	for (int i = 0; i < PUZZLE_SIZE; ++i) {
		initString[i] = MIN_VAL + i;
	}
	char solvedPuzzle[PUZZLE_SIZE / PUZZLE_ROW_SIZE][PUZZLE_ROW_SIZE];
	createPuzzle(solvedPuzzle, initString);
	return solvedPuzzle;
}


void
initArr(int arr[], int length, int value) {
	for (int i = 0; i < length; ++i) {
		arr[i] = value;
	}
}

void
testPuzzle(char tilePuzzle[][PUZZLE_ROW_SIZE]) {
	char solvedTilePuzzle[][PUZZLE_ROW_SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', ' '}};
	int errors[PUZZLE_SIZE][ERRORS_ROW_SIZE];
	for (int i = 0; i < PUZZLE_SIZE; ++i) {
		initArr(errors[i], ERRORS_ROW_SIZE, ERRORS_DEFAULT_VALUE);
	}
	int numOfErrors = 0;
	for (int i = 0; i < PUZZLE_NUM_OF_ROWS; ++i) {
		for (int j = 0; j < PUZZLE_ROW_SIZE; ++j) {
			if (tilePuzzle[i][j] != solvedTilePuzzle[i][j]) {
				errors[numOfErrors][0] = i;
				errors[numOfErrors][1] = j;
				++numOfErrors;
			}
		}
	}
	if (numOfErrors > 0) {
		printWithColor("Errors:\n", 'r');
		for (int k = 0; k < numOfErrors; ++k) {
			const int i = errors[k][0], j = errors[k][1];
			const char current = tilePuzzle[i][j], correct = solvedTilePuzzle[i][j];
			printf("Error #%d puzzle[%d][%d]='%c' and should be '%c'\n", k + 1, i, j, current, correct);
		}
	} else {
		printWithColor("Puzzle Solved!\n", 'g');
	}


}
