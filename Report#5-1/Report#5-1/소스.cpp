#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3   // 3x3 정수 행렬 크기

// 난수 시드 설정 함수
void GenRandSeed()
{
    srand((unsigned int)time(NULL));
}

// min ~ max 사이의 랜덤 정수 생성 함수
int GenRandInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// 행렬을 난수로 채우는 함수
void FillRandom(int m[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            m[i][j] = GenRandInt(-5, 5);   // -5 ~ 5 범위 난수
        }
    }
}

// 행렬 출력 함수
void PrintM(const char* msg, int m[SIZE][SIZE])
{
    int i, j;
    printf("%s\n", msg);
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// A + B 계산
void Add(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// A - B 계산
void Sub(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// k * A 계산
void ScalarMul(int k, int A[SIZE][SIZE], int C[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            C[i][j] = k * A[i][j];
}

// A × B (행렬 곱셈) 계산
void Mul(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE])
{
    int i, j, k;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < SIZE; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// 3x3 행렬의 determinant 계산
int Det3x3(int M[SIZE][SIZE])
{
    int det;
    det =
        M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]) -
        M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0]) +
        M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);
    return det;
}

int main(void)
{
    int A[SIZE][SIZE];
    int B[SIZE][SIZE];
    int C[SIZE][SIZE];
    int k;
    int detA, detB;

    // 랜덤 시드 생성
    GenRandSeed();

    // A, B, k 랜덤 생성
    FillRandom(A);
    FillRandom(B);
    k = GenRandInt(-5, 5);

    // 출력
    PrintM("행렬 A:", A);
    PrintM("행렬 B:", B);
    printf("스칼라 k = %d\n\n", k);

    // A + B
    Add(A, B, C);
    PrintM("A + B:", C);

    // A - B
    Sub(A, B, C);
    PrintM("A - B:", C);

    // k * A
    ScalarMul(k, A, C);
    PrintM("k * A:", C);

    // A × B
    Mul(A, B, C);
    PrintM("A * B:", C);

    // 역행렬 존재 여부 판단 (det != 0)
    detA = Det3x3(A);
    detB = Det3x3(B);

    printf("det(A) = %d -> ", detA);
    if (detA != 0)
        printf("A의 역행렬 계산 가능\n");
    else
        printf("A의 역행렬 계산 불가능 (det=0)\n");

    printf("det(B) = %d -> ", detB);
    if (detB != 0)
        printf("B의 역행렬 계산 가능\n");
    else
        printf("B의 역행렬 계산 불가능 (det=0)\n");

    return 0;
}
