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
	printf("�̸� �й� Ű(cm �Ǵ� m) ������(kg)�� �Է��ϼ���\n");
	printf("�ſ��� 2022010484 170 74\n\n");
	printf("�Է�: ");

	scanf("%49s %d %1f %1f", name, &sid, &height, &weight);

	// 3: ������ BMI ���(BMI = Ű * ������)
	height_m = (height > 3.0) ? height / 100.0 : height;
	bmi = weight / (height_m * height_m);

	// 4-1: ������(�̸�, �й�, Ű, ������)
	printf("\n[�Էµ� ����]wn");
	printf("�̸� : %s\n", name);
	printf("�й� : %d\n", sid);
	printf("Ű : %.2f cm (%.2f m)\n", height_)
	// 4-2: ������(BMI)
	return 0;
}