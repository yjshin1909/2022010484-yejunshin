#include <stdio.h>

int main(void)
{
	for (int dan = 2; dan <= 9; dan++) {
		printf("=== %d´Ü ===\n", dan);
		for (int i = 1; i <= 9; i++) {
			printf("%d x %d = %2d\n", dan, i, dan * i);
		}
		puts("");
	}
	return 0;
}