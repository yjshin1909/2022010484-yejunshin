#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b;
	printf("�� ������ �Է��ϼ���: ");
	scanf("%d %d", &a, &b);

	int x = a, y = b, temp;

	do {
		temp = x % y;
		x = y;
		y = temp;
	} while (y != 0);

	int gcd = x;
	int lcm = (a * b) / gcd;

	printf("�� ��: %d, %d\n", a, b);
	printf("�ִ�����(GCD): %d\n", gcd);
	printf("�ִ�����(LCM): %d\n", lcm);

	return 0;
}