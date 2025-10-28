#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
int mod(int a, int b);

int main() {
    int num1, num2;

    printf("ù ��° ���ڸ� �Է��ϼ���: ");
    scanf("%d", &num1);
    printf("�� ��° ���ڸ� �Է��ϼ���: ");
    scanf("%d", &num2);

    printf("\n[��Ģ���� ���]\n");
    printf("%d + %d = %d\n", num1, num2, add(num1, num2));
    printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
    printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));

    if (num2 != 0) {
        printf("%d / %d = %.2f\n", num1, num2, divide(num1, num2));
        printf("%d %% %d = %d\n", num1, num2, mod(num1, num2));
    }
    else {
        printf("0���� ���� �� �����ϴ�.\n");
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