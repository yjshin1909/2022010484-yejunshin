#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>

int main(void)
{
	// 1: 변수 선언(이름, 학번, 키, 몸무게)
	char name[50];
	int sid;
	double height;
	double weight;
	double height_m;
	double bmi;

	// 2: scanf 또는 scanf_s로 위 정보를 한줄로 입력받기
	printf("이름 학번 키(cm 또는 m) 몸무게(kg)를 입력하세요: ");

	scanf("%49s %d %lf %lf", name, &sid, &height, &weight);

	// 3: 간단한 BMI 계산(BMI = 키 * 몸무게)
	height_m = (height > 3.0) ? height / 100.0 : height;
	bmi = weight / (height_m * height_m);

	// 4-1: 결과출력(이름, 학번, 키, 몸무게)
	printf("\n[입력된 정보]\n");
	printf("이름 : %s\n", name);
	printf("학번 : %d\n", sid);
	printf("키 : %.2f cm (%.2f m)\n", height_m * 100, height_m);
	printf("몸무게 : %.lf kg\n", bmi);

	// 4-2: 결과출력(BMI)
	printf("\n[결과]\n");
	printf("BMI 값 : %.2f\n", bmi);

	return 0;
}