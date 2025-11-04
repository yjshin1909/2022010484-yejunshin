#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10 // 난수 개수

// 평균 계산 함수
double get_mean(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];  // 반복문 사용
    return sum / n;
}

// 분산 계산 함수
double get_variance(int arr[], int n, double mean, char type) {
    double var = 0;
    for (int i = 0; i < n; i++)
        var += pow(arr[i] - mean, 2);
    if (type == 'S' || type == 's')              // 선택문 사용
        var /= (n - 1); // 표본분산
    else
        var /= n;       // 모분산
    return var;
}

int main(void) {
    int num[N];
    int min, max;
    char type;

    srand((unsigned)time(NULL)); // 난수 시드 설정

    printf("난수 범위 입력 [min max]: ");
    scanf("%d %d", &min, &max);

    printf("분산 유형 선택 (P=모분산, S=표본분산): ");
    scanf(" %c", &type);

    // 난수 생성 (반복문)
    for (int i = 0; i < N; i++) {
        num[i] = rand() % (max - min + 1) + min;
    }

    double mean = get_mean(num, N);                // 함수 호출
    double var = get_variance(num, N, mean, type); // 함수 호출
    double stddev = sqrt(var);

    printf("\n생성된 난수: ");
    for (int i = 0; i < N; i++) printf("%d ", num[i]);
    printf("\n평균 = %.2f\n분산 = %.2f\n표준편차 = %.2f\n", mean, var, stddev);

    return 0;
}