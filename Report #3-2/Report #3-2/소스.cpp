#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 난수 생성 함수
int get_random(int min, int max) {
    return rand() % (max - min + 1) + min;   // [min, max] 범위의 정수 반환
}

// 업다운 게임 함수
void play_game(int min, int max, int max_try) {
    int secret = get_random(min, max);       // 함수 호출 → 난수 생성
    int guess;

    for (int i = 1; i <= max_try; i++) {     // 반복문: 최대 10회 시도
        printf("%d번째 시도 (%d~%d): ", i, min, max);
        scanf("%d", &guess);

        if (guess < min || guess > max) {    // 선택문: 범위 검사
            printf("범위를 벗어남! 다시 입력하세요.\n\n");
            i--;                             // 잘못 입력 시 시도 횟수 차감 안 함
            continue;
        }

        if (guess == secret) {               // 선택문: 정답인 경우
            printf("정답! %d를 %d번 만에 맞췄습니다.\n", secret, i);
            return;
        }
        else if (guess < secret) {         // 선택문: 입력값이 작을 때
            printf("업!\n\n");
        }
        else {                             // 선택문: 입력값이 클 때
            printf("다운!\n\n");
        }
    }

    // 반복문이 끝날 때까지 맞히지 못한 경우
    printf("실패! 정답은 %d였습니다.\n", secret);
}

int main(void) {
    srand((unsigned)time(NULL));             // 시드 설정
    play_game(1, 100, 10);                   // 함수 호출 (1~100 사이, 최대 10번)
    return 0;
}