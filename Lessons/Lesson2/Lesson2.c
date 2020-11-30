#include <stdio.h>
#define MAX_SIZE 256
#define ALPHABET_SIZE 26

typedef enum bool { false, true } bool;

bool isSemiSimilar(char source[], char target[]);
unsigned int stringLength(char* source);

int
main() {
	for (;;) {
		char s1[MAX_SIZE] = {0};
		printf("Enter first string:\n");
		scanf("%s", s1);
		char s2[MAX_SIZE] = {0};
		printf("Enter second string:\n");
		scanf("%s", s2);
		char* semiSimilar = "are not";
		if (isSemiSimilar(s1, s2)) {
			semiSimilar = "are";
		}
		printf("the string %s semi similar\n", semiSimilar);
		printf("\n");
	}
	return 1;
}

bool
isSemiSimilar(char source[], char target[]) {
	const unsigned int lengthSource = stringLength(source);
	if (lengthSource != stringLength(target)) {
		return false;
	}
	int amounts[ALPHABET_SIZE * 2] = {0};
	for (int i = 0; i < lengthSource; ++i) {
		char sourceChar, targetChar;
		if (source[i] >= 'a' && source[i] <= 'z') {
			sourceChar = 'a' - ALPHABET_SIZE;
		} else {
			sourceChar = 'A';
		}
		if (target[i] >= 'a' && target[i] <= 'z') {
			targetChar = 'a' - ALPHABET_SIZE;
		} else {
			targetChar = 'A';
		}
		amounts[source[i] - sourceChar]++;
		amounts[target[i] - targetChar]--;
	}
	for (int i = 0; i < ALPHABET_SIZE * 2; ++i) {
		if (amounts[i] != 0) {
			return false;
		}
	}
	return true;

}

unsigned int
stringLength(char* source) {
	unsigned int i;
	for (i = 0; source[i] != '\0'; ++i);
	return i;
}
