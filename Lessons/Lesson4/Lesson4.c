#include <stdio.h>
#define MAX_SIZE 100

int
calculateLength(char* ch) {
	char* ctr = ch;
	while (*ch != '\0') {
		ch++;
	}
	printf("address subtraction: 0x%p - 0x%p\n", ch, ctr);
	return ch - ctr;
}

/**
 * Compares two strings lexicographically.
 */
int
compare(char* str1, char* str2) {
	while ((*str1 && *str2) && (*str1 == *str2)) {
		str1++;
		str2++;
	}

	return *str1 - *str2;
}

void
concatenate(char* s1, char* s2) {
	/* Move till the end of str1 */
	while (*(++s1));

	/* Copy str2 to str1 */
	while (*(s1++) = *(s2++));
}

int
main() {
	printf("%d\n", calculateLength("string"));

	char str1[MAX_SIZE], str2[MAX_SIZE];

	/* Input two strings from user */
	printf("Enter first string: ");
	gets_s(str1,MAX_SIZE);
	printf("Enter second string: ");
	gets_s(str2, MAX_SIZE);


	/* Call the compare function to compare strings */
	const int res = compare(str1, str2);

	if (res == 0) {
		printf("Both strings are equal.\n");
	} else if (res < 0) {
		printf("First string is lexicographically smaller than second.\n");
	} else {
		printf("First string is lexicographically greater than second.\n");
	}

	concatenate(str1, str2);
	printf("Concatenated string = %s", str1);
	return 0;
}
