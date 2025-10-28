#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    double temp;            // 현재 온도(°C)
    int doorOpen;           // 0=닫힘, 1=열림
    int openSecs;           // 열린 상태 지속 시간(초)
    int outSecs;            // 닫힌 상태에서 온도 범위 벗어난 시간(초)

    printf("=== 백신냉장고 온도 경고장치 ===\n");
    printf("입력 순서: [현재온도(°C)] [문상태(0=닫힘,1=열림)] [열린시간(초)] [범위이탈시간(초,닫힘시)]\n");
    printf("예시 입력: 5.0 0 0 0\n");
    printf("------------------------------------------\n");
    printf(">> 입력하세요: ");

    if (scanf("%lf %d %d %d", &temp, &doorOpen, &openSecs, &outSecs) != 4) {
        printf("invalid input\n");
        return 0;
    }

    /* -------- 입력 유효성 검증 -------- */
    if ((doorOpen != 0 && doorOpen != 1) || openSecs < 0 || outSecs < 0) {
        printf("invalid input\n");
        return 0;
    }
    // 문이 닫힘인데 열린시간이 존재하면 모순
    if (doorOpen == 0 && openSecs != 0) {
        printf("invalid input\n");
        return 0;
    }

    /* -------- 상태 판정 -------- */
    int inRange = (temp >= 2.0 && temp <= 8.0);
    int outRange = !inRange;

    const char* state =
        (doorOpen == 0 && inRange) ? "Normal" :
        (doorOpen == 1 && openSecs >= 60 && outRange) ? "Critical" :
        (doorOpen == 0 && outRange) ? (outSecs <= 30 ? "Warning" : "Critical")
        : "Normal";

    printf("\n현재 상태: %s\n", state);
    return 0;
}
