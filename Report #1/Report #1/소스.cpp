#define _CRT_SECURE_NO_WARNINGS //scanf 보안 경고 방지
#include <stdio.h>

int main(void) {
    int age;

    printf("나이를 입력하세요: ");
    scanf("%d", &age);

    // 관계 연산자 사용: 나이 비교
    if (age < 0) {
        printf("잘못된 나이입니다.\n");
        return 0;
    }

    // 논리 연산자 사용: 연령대 판별
    if (age >= 0 && age < 13) {
        printf("어린이입니다.\n");
    } else if (age >= 13 && age < 20) {
        printf("청소년입니다.\n");
    } else if (age >= 20 && age < 65) {
        printf("성인입니다.\n");
    } else {
        printf("노인입니다.\n");
    }

    // 증감 연산자 사용: 내년 나이 출력
    age++;  // age = age + 1 과 동일
    printf("내년에는 %d살이 됩니다.\n", age);

    return 0;
}