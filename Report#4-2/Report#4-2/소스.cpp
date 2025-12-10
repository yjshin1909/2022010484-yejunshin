#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_DATA 100   // 전체 난수 개수
#define NUM_PICK 10    // 선택할 정수 개수

// 난수 시드 생성 함수
void GenRandSeed(void)
{
    srand((unsigned int)time(NULL));
}

// 특정 범위 [min, max] 의 난수 정수 하나 생성
int GenRandIntInRange(int min, int max)
{
    int range = max - min + 1;
    int n = rand() % range;
    return min + n;
}

// 난수로 배열 채우기 함수
void FillRandomArray(int* arr, int size, int min, int max)
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = GenRandIntInRange(min, max);
    }
}

// 부분 구간에 대한 합, 분산, 표준편차 계산 함수
void CalcStatsRange(int* arr, int startIndex, int count,
    double* sum, double* variance, double* stdev)
{
    int i;
    double mean = 0.0;
    double tempSum = 0.0;
    double tempVar = 0.0;

    // 합 계산
    for (i = 0; i < count; i++)
    {
        tempSum += arr[startIndex + i];
    }

    // 평균 계산
    mean = tempSum / (double)count;

    // 분산 계산 (모집단 분산 기준)
    for (i = 0; i < count; i++)
    {
        double diff = arr[startIndex + i] - mean;
        tempVar += diff * diff;
    }
    tempVar = tempVar / (double)count;

    // 결과를 포인터로 되돌려주기
    *sum = tempSum;
    *variance = tempVar;
    *stdev = sqrt(tempVar);
}

int main(void)
{
    int data[NUM_DATA];     // 100개 정수를 저장할 배열
    int minValue, maxValue; // 난수 범위
    int startIndex;         // 10개를 뽑을 시작 인덱스
    double sum = 0.0;
    double variance = 0.0;
    double stdev = 0.0;
    int i;

    // 난수 시드 설정
    GenRandSeed();

    // 난수 생성 범위 입력 받기
    printf("난수로 생성할 정수의 범위 (최소값 최대값)를 입력하세요: ");
    scanf("%d %d", &minValue, &maxValue);

    if (minValue > maxValue)
    {
        printf("범위가 잘못되었습니다. 최소값이 최대값보다 큽니다.\n");
        return 0;
    }

    // 100개의 정수 난수 생성
    FillRandomArray(data, NUM_DATA, minValue, maxValue);

    // 생성된 100개 정수 출력 (확인용)
    printf("\n생성된 %d개의 정수:\n", NUM_DATA);
    for (i = 0; i < NUM_DATA; i++)
    {
        printf("%4d ", data[i]);
        if ((i + 1) % 20 == 0)   // 20개씩 끊어서 보기 좋게 출력
            printf("\n");
    }

    // 사람에게 10개를 뽑을 시작 위치 지정 받기
    printf("\n\n전체 %d개 중에서 연속된 %d개를 선택할 시작 인덱스를 입력하세요 (0 ~ %d): ",
        NUM_DATA, NUM_PICK, NUM_DATA - NUM_PICK);
    scanf("%d", &startIndex);

    if (startIndex < 0 || startIndex > NUM_DATA - NUM_PICK)
    {
        printf("시작 인덱스가 범위를 벗어났습니다.\n");
        return 0;
    }

    // 선택된 10개 정수 출력
    printf("\n선택된 %d개 정수 (index %d ~ %d):\n",
        NUM_PICK, startIndex, startIndex + NUM_PICK - 1);
    for (i = 0; i < NUM_PICK; i++)
    {
        printf("%4d ", data[startIndex + i]);
    }
    printf("\n");

    // 선택된 구간에 대한 합, 분산, 표준편차 계산
    CalcStatsRange(data, startIndex, NUM_PICK, &sum, &variance, &stdev);

    printf("\n합      : %.2f\n", sum);
    printf("분산    : %.4f\n", variance);
    printf("표준편차: %.4f\n", stdev);

    return 0;
}
