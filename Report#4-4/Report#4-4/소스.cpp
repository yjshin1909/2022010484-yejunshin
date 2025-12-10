#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOTTO_SIZE 6
#define LOTTO_MAX 45

// 난수 시드 생성
void GenRandSeed()
{
    srand((unsigned int)(time(NULL)));
}

// 0 ~ (nRange-1) 난수 생성
unsigned int GenRandNum(unsigned int nRange)
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

// 배열에 특정 숫자가 있는지 확인
int IsExist(int* arr, int size, int value)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return 1;
    }
    return 0;
}

// 로또 번호 생성 (중복 없음)
void GenLottoNumbers(int* lotto, int size)
{
    int count = 0;

    while (count < size)
    {
        int num = (int)GenRandNum(LOTTO_MAX) + 1; // 1~45

        if (IsExist(lotto, count, num) == 0)
        {
            lotto[count] = num;
            count++;
        }
    }
}

// 사용자 번호 입력
void InputUserNumbers(int* user, int size)
{
    int i;
    printf("당신의 로또 번호 %d개를 입력하세요 (1~%d):\n", size, LOTTO_MAX);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &user[i]);
    }
}

// 로또, 사용자 번호 비교
int CountMatch(int* lotto, int* user, int size)
{
    int i, j;
    int match = 0;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (lotto[i] == user[j])
                match++;
        }
    }
    return match;
}

// 배열 출력
void PrintNumbers(const char* msg, int* arr, int size)
{
    int i;
    printf("%s", msg);
    for (i = 0; i < size; i++)
    {
        printf(" %2d", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int lotto[LOTTO_SIZE];
    int user[LOTTO_SIZE];
    int matchCount = 0;

    GenRandSeed();   // 시드 설정

    // 로또 번호 생성
    GenLottoNumbers(lotto, LOTTO_SIZE);

    // 사용자 번호 입력
    InputUserNumbers(user, LOTTO_SIZE);

    // 번호 출력
    PrintNumbers("컴퓨터 로또 번호:", lotto, LOTTO_SIZE);
    PrintNumbers("당신의 로또 번호:", user, LOTTO_SIZE);

    // 맞춘 개수 계산
    matchCount = CountMatch(lotto, user, LOTTO_SIZE);

    printf("\n맞춘 개수: %d 개\n", matchCount);

    if (matchCount == 6)
        printf("결과: 1등!!\n");
    else if (matchCount == 5)
        printf("결과: 2등!\n");
    else if (matchCount == 4)
        printf("결과: 3등\n");
    else if (matchCount == 3)
        printf("결과: 4등(or 꽝)\n");
    else
        printf("결과: 꽝입니다...\n");

    return 0;
}
