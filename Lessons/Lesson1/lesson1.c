#include <stdio.h>

//function decelerations

void printSpecialSquare();
void stringOrder();
void octalToDecimal();
void countBits();

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
		//octalToDecimal();
		//countBits();
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

//Assignment 2 question 4.
void
octalToDecimal() {
	int result = 0, pow = 1;
	char n;
	bool flag = true;
	printf("Enter a reversed number in base 8:\n");
	scanf_s("%c", &n);
	while (n != '\n') {
		int number = n - '0';
		if (!(number >= 0 && number < 8)) {
			printf("Error! %c is not a valid digit in base 8", n);
			flag = false;
			continue;
		}
		result += number * pow;
		pow *= 8;
		scanf_s("%c", &n);
	}
	if (flag == true) {
		printf("%d\n", result);
	}
}

//Assignment 2 question 6.
void
countBits() {
	int num;
	unsigned int count = 0;
	printf("Enter a number:\n");
	scanf_s("%d", &num);
	unsigned int temp = num;
	while (temp > 0) {
		count += temp & 1;
		temp >>= 1;
	}
	printf("The number of bits in %d is %d\n", num, count);
}
