#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 3차원 벡터 크기
#define VEC_SIZE 3

// 벡터 입력 함수
void InputVector(double* v)
{
    int i;
    printf("3차원 벡터의 3개 요소를 입력하세요: ");
    for (i = 0; i < VEC_SIZE; i++)
    {
        scanf("%lf", &v[i]);
    }
}

// 내적 계산 함수
double CalcDot(double* a, double* b)
{
    double sum = 0.0;
    int i;
    for (i = 0; i < VEC_SIZE; i++)
    {
        sum += a[i] * b[i];
    }
    return sum;
}

// 외적 계산 함수
void CalcCross(double* a, double* b, double* result)
{
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] = a[2] * b[0] - a[0] * b[2];
    result[2] = a[0] * b[1] - a[1] * b[0];
}

int main(void)
{
    double vecA[VEC_SIZE];
    double vecB[VEC_SIZE];
    double cross[VEC_SIZE];
    double dot = 0.0;

    printf("=== 벡터 A 입력 ===\n");
    InputVector(vecA);

    printf("=== 벡터 B 입력 ===\n");
    InputVector(vecB);

    // 내적 계산
    dot = CalcDot(vecA, vecB);

    // 외적 계산
    CalcCross(vecA, vecB, cross);

    // 출력
    printf("\n=== 내적(dot product) ===\n");
    printf("A · B = %.4lf\n", dot);

    printf("\n=== 외적(cross product) ===\n");
    printf("A × B = ( %.4lf , %.4lf , %.4lf )\n",
        cross[0], cross[1], cross[2]);

    return 0;
}
