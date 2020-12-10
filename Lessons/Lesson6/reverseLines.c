//
// Created by tomer on 10/12/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseLines(char*);
char** splitLines(char*, int*);
void reverseArray(char**, int);
char* joinLines(char**, int);
char** addLine(char**, int*, char*);

/**
 * add line to array of lines.
 */
char** addLine(char** arr, int* len, char* line) {
    (*len)++;
    arr = (char**) realloc(arr, *len * sizeof(char*));
    if (arr==NULL) {
        printf("error\n");
        exit(-1);
    }
    arr[(*len)-1] = line;
    return arr;
}

/**
 * split a string to array of lines
 */
char** splitLines(char* str, int* len) {
    char** arr = NULL;

    const char s[] = "\n";
    char *token;

    *len = 0;
    /* get the first line */
    token = strtok(str, s);
    /* walk through other lines */
    while( token != NULL ) {
        arr = addLine(arr, len, token);
        token = strtok(NULL, s);
    }
    return arr;
}

/**
 * reverse the order of the array
 */
void reverseArray(char** arr, int len) {
    for (int i = 0; i < len/2; i++) {
        char* tmp = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1] = tmp;
    }
}

/**
 * takes list of lines
 */
char* joinLines(char** arr, int arrLen) {
    char* str = NULL;
    int strLen = 0;

    for (int i = 0; i < arrLen; i++) {
        int lineLen = strlen(arr[i]) + 1; //length of the new line added to the string + 1 for the \0
        str = (char*) realloc(str, (strLen + lineLen)*sizeof(char)); // the length of the new string
        if (str==NULL) {
            printf("error\n");
            exit(-1);
        }
        strcpy(str+strLen, arr[i]);
        strLen += lineLen;
        str[strLen-1] = '\n'; //replace \0 at the end of the line with \n
    }
    str[strLen-1] = '\0';
    return str;
}

/**
 * takes a string and reverse the order of its lines
 */
void reverseLines(char* str) {
    char* reversed = NULL;
    int len;
    char** arr = splitLines(str, &len);
    reverseArray(arr, len);
    reversed = joinLines(arr, len);
    strcpy(str, reversed);
    free(reversed);
    free(arr);
}

int main() {
    char* str = "line1\nline2\nline3\n";
    reverseLines(str);
    printf("%s", str);
}
