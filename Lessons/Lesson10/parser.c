/**
 * In this exercise we will be a parser of string representing arithmetical and logical
 * operations.
 * each line can either have boolean operation like and, or, xor.
 * or have a condition contains:
 * left side expression
 * compare operation
 * right side expression
 * each separated by ';'
 *
 * each expression contains:
 * arithmetic operations, separated by ','
 * operands separated by ','
 * separated by ':' from each other
 *
 * a line can have a comment starts with '#' until end of line
 * all spaces must be ignored
 * the order of operations is left to right
 * operations can have mix of capital and small letters
 *
 * example:
 * "
 * add: 5,6; >; sub: 10, 7   # 5 + 6 > 10 -7
 * and
 * mUl, adD: 1, 2, 3; == ;   DIV, sub: 11, 5  , -3  # 1*2 + 3 == 11/5 - 3
 * Or      # every line can have comment
 * sub: 4, 5, 6; <= ;    add: 5, 6 #illegal
 */

#include "parser.h"

/**
 * takes a condition line and return the value
 * @param line string of condition line
 * @return the value of the condition 1 if true 0 if false
 */
int parseConditionLine(char* line) {
    char *left, *op, *right;
    const char delim[] = ";";
    removeComment(line);
    left = strtok(line, delim);
    op = strtok(NULL, delim);
    right = strtok(NULL, delim);
    assert(strtok(NULL, delim) == NULL);  // there should be exactly 3 parts
    int rightValue = expValue(right);
    int leftValue = expValue(left);
    int (*comparator) (int, int) = getComparator(op);
    return comparator(leftValue, rightValue);
}

/**
 * remove comment from end of line
 */
void removeComment(char* line) {
    const char s[] = "#";
    strtok(line, s);
}

/**
 * parse expression and calculate its value
 * @param exp string of arithmetic expression
 * @return value of expression
 */
int expValue(char* exp) {
    const char delim[] = ":";
    char* operationsString = strtok(exp, delim);
    char* numbersString = strtok(NULL, delim);
    int numbersLen, operatorsLen;
    int* numbers = getNumbers(numbersString, &numbersLen);
    int (**operations)(int, int) = getOperations(operationsString, &operatorsLen);
    assert(numbersLen == operatorsLen + 1);
    int res = numbers[0];
    for (int i = 0; i < operatorsLen; i++) {
        res = operations[i](res, numbers[i+1]);
    }
    free(numbers);
    free(operations);
    return res;
}

/**
 * split string to array of strings
 * @param toSplit string to split
 * @param splitBy string to split by
 * @param len pointer to array length
 * @return pointer to first string in array
 */
char** split(char* toSplit, char* splitBy, int* len) {
    char** arr = NULL;
    *len = 0;
    char* token = strtok(toSplit, splitBy);
    while (token != NULL) {
        arr = (char**) realloc(arr, ((*len) + 1) * sizeof(char*));
        assert(arr != NULL);
        arr[*len] = token;
        *len++;
        token = strtok(NULL, splitBy);
    }
    return arr;
}

/**
 * remove spaces from string
 * @param str string to strip from spaces
 * @return start of new string
 */
char* strip(char* str) {
    while (str[0] == ' ') {
        str++;
    }
    for (int i = strlen(str) - 1; i > 0 && str[i] == ' '; i --) {
        str[i] = '\0';
    }
    return str;
}

/**
 * takes string of numbers and return array of ints
 * @param asString the numbers in string, separated by ','
 * @param len pointer to array length
 * @return array of int
 */
int* getNumbers(char* asString, int* len) {
    char** stringArr = split(asString, ",", len);
    int* arr = (int*) malloc(*len * sizeof(int));
    assert(arr!=NULL);
    for (int i = 0; i < *len; i++) {
        arr[i] = atoi(stringArr[i]);
    }
    free(stringArr);
    return arr;
}

/**
 * takes string contains operators and return list of functions
 * @param str string with operators separated by ','
 * @param len length of functions array
 */
int (**getOperations(char* str, int* len))(int, int) {
    char** stringArr = split(str, ",", len);
    int (**arr)(int, int) = (int (**)(int, int)) malloc(*len * sizeof(int (*)(int, int)));
    assert(arr != NULL);
    for (int i = 0; i < *len; i++) {
        arr[i] = getArithOperation(stringArr[i]);
    }
    free(stringArr);
    return arr;
}

/**
 * get a string of operator name and return function to apply the operator
 * @param str operator name
 */
int (*getArithOperation(char* str))(int, int) {
    int (* operations[])(int, int) = {add, sub, mul, divide};
    char* names[] = {"add", "sub", "mul", "div"};
    return getOperation(str, names, operations, sizeof(names)/ sizeof(char*));
}

/**
 * takes operation name and return the operation
 * @param str operation name
 * @param names all operation names
 * @param operations all possible operators
 * @param len number of option
 */
int (*getOperation(char* str, char** names, int (*operations[])(int, int), int len))(int, int) {
    makeLower(str);
    for (int i = 0; i < len; i++) {
        if (!strcmp(names[i], str)) {
            return operations[i];
        }
    }
    printf("no such operator %s\n", str);
    exit(1);
}

/*takes string and make it lower case*/
void makeLower(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }
}

/**
 * takes comparator name and return the comparator
 * @param str name of comparator
 */
int (*getComparator(char* str)) (int, int) {
    int (*operations[])(int, int) = {isBigger, isSmaller, isEqual,
                                     isBiggerEqual, isSmallerEqual, isNotEqual};
    char* names[] = {">", "<", "==", ">=", "<=", "!="};
    str = strip(str);
    return getOperation(str, names, operations, sizeof(names)/ sizeof(char*));
}

/**
 * takes line of boolean operator and return function to apply operator
 * @param line to parse
 */
int (*parseOperationLine(char* line)) (int, int) {
    removeComment(line);
    line = strip(line);
    int (* operations[])(int, int) = {andOp, orOp, xorOp};
    char* names[] = {"and", "or", "xor"};
    return getOperation(line, names, operations, sizeof(names)/ sizeof(char*));
}

/**
 * takes a string representing our code, return the result
 * @param code string that should be in the format from above
 * @return 1 if result is true, 0 if false
 */
int parse(char* code) {
    char* delim = "\n";
    char *condLine, *opLine;
    condLine = strtok(code, delim); //first condition
    opLine = strtok(NULL, delim); //first operator
    code = opLine + strlen(opLine) + 1;
    int result = parseConditionLine(condLine);
    while (opLine != NULL) {
        int (*operation) (int, int) = parseOperationLine(opLine);
        condLine = strtok(code, delim);
        opLine = strtok(NULL, delim); //operator for next iteration
        code = opLine + strlen(opLine) + 1;
        int lineVal = parseConditionLine(condLine);
        result = operation(result, lineVal);
    }
    return result;
}
