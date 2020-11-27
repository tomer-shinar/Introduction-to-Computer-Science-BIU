#include <stdio.h>


int factorial(int n);
int powRecursive(int num, int power);
int atoiRecursive(char* num);
int atoiIter(char* num);
int stringLen(char* str);


void
PowRecursiveStart() {
	int n;
	int pow;
	printf("Enter a number:\n");
	scanf_s("%d", &n);
	printf("Enter a power:\n");
	scanf_s("%d", &pow);
	printf("%d^%d=%d\n", n, pow, powRecursive(n, pow));
}

int
main() {
	for (;;) {
		char* num = "1250";
		//PowRecursiveStart();
		printf("%d", atoiRecursive(num));
	}
	return 0;
}

int
powRecursive(int num, int power) {
	if (power == 0) {
		return 1;
	}
	if (power == 1) {
		return num;
	}
	int temp = powRecursive(num, power / 2);
	temp *= temp;
	if (power % 2 != 0) {
		temp *= num;
	}
	return temp;
}

int
atoiRecursive(char* num) {
	if (num[0] == '\0') {
		return 0;
	}
	return (num[0] - '0') * powRecursive(10, stringLen(num) - 1) + atoiRecursive(num + 1);
}

int
stringLen(char* str) {
	if (str[0] == '\0') {
		return 0;
	}
	return stringLen((str + 1)) + 1;
}


int
atoiIter(char* num) {
	int mult = 1;
	int score = 0;
	int length = stringLen(num) - 1;
	for (int i = length; i >= 0; --i) {
		score += (num[i] - '0') * mult;
		mult *= 10;
	}
	return score;
}
