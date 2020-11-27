#include <stdio.h>
#include <fcntl.h>
#include <string.h>

typedef enum bool {
    false = 0, true
} bool;

void rhombus();

void base20ToDecimal();

void multiply();

void add();

int addBitwise(int num1, int num2);

void differentBits();

void pow2();

void baseToDecimal();

int numToThePower(int num, int pow);

int main() {
    int option = -1;
    char dummy;
    setbuf(stdout, 0);
    do {
        printf("Choose an option:");
        printf("\n");
        printf("1. Rhombus");
        printf("\n");
        printf("2. Base 20 to Decimal");
        printf("\n");
        printf("3. Base to Decimal");
        printf("\n");
        printf("4. Pow2");
        printf("\n");
        printf("5. Different bits");
        printf("\n");
        printf("6. Add");
        printf("\n");
        printf("7. Multiply");
        printf("\n");
        printf("0. Exit");
        printf("\n");
        scanf_s("%d", &option);
        scanf_s("%c", &dummy);
        switch (option) {
            case 0:
                break;
            case 1:
                rhombus();
                break;
            case 2:
                base20ToDecimal();
                break;
            case 3:
                baseToDecimal();
                break;
            case 4:
                pow2();
                break;
            case 5:
                differentBits();
                break;
            case 6:
                add();
                break;
            case 7:
                multiply();
                break;
            default:
                printf("Wrong option!");
                break;

        }
    } while (option != 0);
    return 0;
}

void rhombus() {
    int size, sign = 1, limit = 0;
    char dummy;
    printf("Enter the sides length:\n");
    scanf_s("%d", &size);
    scanf_s("%c", &dummy);
    for (int i = 0; i < size * 2; ++i) {
        if (i == size) {
            sign = -1;
        } else {
            limit += sign;
        }
        for (int j = 0; j < size + limit + 1; ++j) {
            char c;
            if (i == j && j == size) {
                c = '+';
            } else if (j == size) {
                c = '*';
            } else if (i == size && (j == 0 || j == size * 2)) {
                c = '|';
            } else if (i != size && j == size - limit) {
                if (i < size) {
                    c = '/';
                } else {
                    c = '\\';
                }
            } else if (i != size && j == limit + size) {
                if (i >= size) {
                    c = '/';
                } else {
                    c = '\\';
                }
            } else {
                c = ' ';
            }
            printf("%c", c);
        }
        printf("\n");
    }
}

void base20ToDecimal() {
    char c = -1;
    int power = 0;
    int number = 0;
    printf("Enter a reversed number in base 20:\n");
    do {
        scanf_s("%c", &c);
        int currNum;
        if (c >= '0' && c <= '9') {
            currNum = c - '0';
        } else if (c >= 'a' && c <= 'j') {
            currNum = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'J') {
            currNum = c - 'A' + 10;
        } else if (c == '\n') {
            break;
        } else {
            printf("Error! %c is not a valid digit in base 20\n", c);
            continue;
        }
        number += numToThePower(20, power) * currNum;
        power++;
    } while (c);
    printf("%d\n", number);
}

int numToThePower(int num, int pow) {
    int score = 1;
    for (int i = 0; i < pow; ++i) {
        score *= num;
    }
    return score;
}

void baseToDecimal() {
    char c, dummy;
    int base;
    int power = 0;
    int number = 0;
    bool valid = true;
    printf("Enter a a base (2-10):\n");
    scanf_s("%d", &base);
    scanf_s("%c", &dummy);
    printf("Enter a reversed number in base %d:\n", base);
    do {
        scanf_s("%c", &c);
        int currNum;
        if (c >= '0' && c < '0' + base) {
            currNum = c - '0';
        } else if (c == '\n') {
            break;
        } else {
            valid = false;
            printf("Error! %c is not a valid digit in base %d\n", c, base);
            continue;
        }
        number += numToThePower(base, power) * currNum;
        power++;
    } while (c);
    if (valid == true) {
        printf("%d\n", number);
    }
}

void pow2() {
    unsigned long number;
    char dummy;
    printf("Enter a number:\n");
    scanf_s("%lu", &number);
    scanf_s("%c", &dummy);
    if (number != 0 && (number & (number - 1)) == 0) {
        printf("%lu is a power of 2\n", number);
    } /*else {
        printf("%lu is not a power of 2\n", number);
    }*/
}

void differentBits() {
    unsigned int num1, num2, num3;
    char dummy;
    unsigned int total = 0;
    printf("Enter two numbers:\n");
    scanf_s("%u", &num1);
    scanf_s("%u", &num2);
    scanf_s("%c", &dummy);
    num3 = num1 ^ num2;
    while (num3 > 0) {
        total += num3 & (unsigned int) 1;
        num3 >>= (unsigned int) 1;
    }
    printf("There are %d different bits\n", total);
}

void add() {
    int num1, num2, score;
    char dummy;
    printf("Enter two numbers:\n");
    scanf_s("%d", &num1);
    scanf_s("%d", &num2);
    scanf_s("%c", &dummy);
    // Iterate till there is no carry
    score = addBitwise(num1, num2);
    printf("%d\n", score);
}

int addBitwise(int num1, int num2) {
    while (num2 != 0) {
        // carry now contains common
        //set bits of num1 and num2
        int carry = num1 & num2;

        // Sum of bits of num1 and num2 where at
        //least one of the bits is not set
        num1 = num1 ^ num2;

        // Carry is shifted by one so that adding
        // it to num1 gives the required sum
        num2 = carry << 1;
    }
    return num1;
}

void multiply() {
    int num1, num2, loopLimit, add;
    int ans = 0;
    char dummy;
    printf("Enter two numbers:\n");
    scanf_s("%d", &num1);
    scanf_s("%d", &num2);
    scanf_s("%c", &dummy);
    if (num1 < 0 && num2 < 0) {
        loopLimit = (~num1) + 1;
        add = (~num2) + 1;
    } else if (num1 < 0 && num2 >= 0) {
        loopLimit = num2;
        add = num1;
    } else if (num1 >= 0 && num2 < 0) {
        loopLimit = num1;
        add = num2;
    } else {
        loopLimit = num1;
        add = num2;
    }
    for (int i = 0; i < loopLimit; ++i) {
        ans += add;
    }
    printf("%d\n", ans);
}


