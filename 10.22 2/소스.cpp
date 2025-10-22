#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a, b;
	printf("두 정수를 입력하세요: ");
	scanf("%d %d", &a, &b);

	int x = a, y = b;

	while (y != 0) {
		int temp = x % y;
		x = y;
		y = temp;
	}

	int gcd = x;
	int lcm = (a * b) / gcd;

	printf("두 수: %d, %d\n", a, b);
	printf("최대공약수(GCD): %d\n", gcd);
	printf("최대공배수(LCM): %d\n", lcm);
	
	return 0;
}