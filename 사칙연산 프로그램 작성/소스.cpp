#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
int mod(int a, int b);

int main() {
    int num1, num2;

    printf("첫 번째 숫자를 입력하세요: ");
    scanf("%d", &num1);
    printf("두 번째 숫자를 입력하세요: ");
    scanf("%d", &num2);

    printf("\n[사칙연산 결과]\n");
    printf("%d + %d = %d\n", num1, num2, add(num1, num2));
    printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
    printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));

    if (num2 != 0) {
        printf("%d / %d = %.2f\n", num1, num2, divide(num1, num2));
        printf("%d %% %d = %d\n", num1, num2, mod(num1, num2));
    }
    else {
        printf("0으로 나눌 수 없습니다.\n");
    }

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}

int mod(int a, int b) {
    return a % b;
}