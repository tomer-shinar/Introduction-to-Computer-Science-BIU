#include <stdio.h>

typedef enum Bool {
    False = 0, True
} bool;

void rhombus();

void base20ToDecimal();

void multiply();

void add();

void differentBits();

void pow2();

void baseToDecimal();

int numToThePower(int num, int pow);

int main() {
    int option = -1;
    char dummy;
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
            printf("Error! %c is not a valid digit in base %d\n", c, base);
            continue;
        }
        number += numToThePower(base, power) * currNum;
        power++;
    } while (c);
    printf("%d\n", number);
}

void pow2() {
    unsigned long number;
    char dummy;
    printf("Enter a number:\n");
    scanf_s("%lu", &number);
    scanf_s("%c", &dummy);
    if ((number & (number - 1)) == 0) {
        printf("%lu is a power of 2\n", number);
    } else {
        printf("%lu is not a power of 2\n", number);
    }
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
    int num1, num2;
    char dummy;
    printf("Enter two numbers:\n");
    scanf_s("%d", &num1);
    scanf_s("%d", &num2);
    scanf_s("%c", &dummy);
    // Iterate till there is no carry
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
    printf("%d\n", num1);
}

void multiply() {
    int num1, num2;
    int ans = 0;
    int count = 0;
    char dummy;
    printf("Enter two numbers:\n");
    scanf_s("%d", &num1);
    scanf_s("%d", &num2);
    scanf_s("%c", &dummy);
    while (num2) {
        // check for set bit and left
        // shift n, count times
        if (num2 % 2 == 1)
            ans += num1 << count;

        // increment of place value (count)
        count++;
        num2 >>= 1;
    }
    printf("%d\n", ans);
}


