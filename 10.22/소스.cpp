#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int dan;

	printf("����� ��(2~9)�� �Է��ϼ��� (0 �Է� �� ��ü ���): ");
	scanf("%d", &dan);

	if (dan == 0) {

		for (int d = 2; d <= 9; d++) {
			printf("=== %d�� ===\n", d);
			for (int i = 1; i <= 9; i++) {
				printf("=== %d�� ===\n", d, i, d * i);
			}
			puts("");
		}
	}
	else if (dan >= 2 && dan <= 9) {

		printf("=== %d�� ===\n", dan);
		for (int i = 1; i <= 9; i++) {
			printf("%d x %d + %2d\n", dan, i, dan * i);
		}
	}
	else {

		printf("�߸��� �Է��Դϴ�. 0 �Ǵ� 2~9 ������ ���ڸ� �Է��ϼ���.\n");
	}

	return 0;
}
