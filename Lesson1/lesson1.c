#include <stdio.h>

//function decelerations

void printSpecialSquare();
void stringOrder();

typedef enum bool { false, true } bool;


/*
* This code is a sum up for lesson n.1.
* All question are taken from 2020 fall semester assignment 2 (located in this repository).
*/

int
main() {
	for (;;) {
		//uncomment the function you want to use.
		//printSpecialSquare();
		//stringOrder();
	}
	return 1;
}


//Assignment 2 question 1.
void
printSpecialSquare() {
	int x;
	printf("Enter positive number for square size:");
	scanf_s("%d", &x);
	printf("\n");
	for (int i = 0; i < 2 * x + 1; ++i) {
		for (int j = 0; j < 2 * x + 1; ++j) {
			char c;
			if (i == x && i == j) {
				//special case for 'x'
				c = 'X';
			} else if (i + j == 0 || i + j == 4 * x || ((i == 0 || j == 0) && i + j == 2 * x)) {
				//special case for '+'
				c = '+';
			} else if (i == j) {
				//special case for '\'
				c = '\\';
			} else if (i + j == 2 * x) {
				//special case for '/'
				c = '/';
			} else if (i == 0 || i == 2 * x) {
				//special case for '-'
				c = '-';
			} else if (j == 0 || j == 2 * x) {
				//special case for '|'
				c = '|';
			} else {
				//fallback case
				c = ' ';
			}
			printf("%c", c);
		}
		//go to next row
		printf("\n");
	}
}

//Assignment 2 question 3.

void
stringOrder() {
	printf("Please insert string: ");
	char before;
	bool dec, inc;
	bool invalid = dec = inc = false;
	scanf_s("%c", &before);
	char current = before;
	while (current != '\n') {
		if (current < 'a' || current > 'z') {
			invalid = true;
		} else if (current > before) {
			inc = true;
		} else if (current < before) {
			dec = true;
		}
		before = current;
		scanf_s("%c", &current);
	}
	if (invalid == true) {
		printf("Your text is invalid");
	} else if (dec == true && inc == true) {
		printf("Your text is mixed");
	} else if (inc == true) {
		printf("Your text is increasing");
	} else if (dec == true) {
		printf("Your text is decreasing");
	} else {
		printf("Your text is constant");
	}
	printf("\n");
}
