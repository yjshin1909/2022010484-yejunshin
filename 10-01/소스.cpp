#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>

int main(void)
{
	// 1: ���� ����(�̸�, �й�, Ű, ������)
	char name[50];
	int sid;
	double height;
	double weight;
	double height_m;
	double bmi;

	// 2: scanf �Ǵ� scanf_s�� �� ������ ���ٷ� �Է¹ޱ�
	printf("�̸� �й� Ű(cm �Ǵ� m) ������(kg)�� �Է��ϼ���: ");

	scanf("%49s %d %lf %lf", name, &sid, &height, &weight);

	// 3: ������ BMI ���(BMI = Ű * ������)
	height_m = (height > 3.0) ? height / 100.0 : height;
	bmi = weight / (height_m * height_m);

	// 4-1: ������(�̸�, �й�, Ű, ������)
	printf("\n[�Էµ� ����]\n");
	printf("�̸� : %s\n", name);
	printf("�й� : %d\n", sid);
	printf("Ű : %.2f cm (%.2f m)\n", height_m * 100, height_m);
	printf("������ : %.lf kg\n", bmi);

	// 4-2: ������(BMI)
	printf("\n[���]\n");
	printf("BMI �� : %.2f\n", bmi);

	return 0;
}