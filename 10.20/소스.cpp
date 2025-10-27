#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int dan;

    printf("출력할 단(2~9)을 입력하세요 (0 입력 시 전체 출력): ");
    if (scanf("%d", &dan) != 1) {
        puts("입력 오류: 숫자를 입력하세요.");
        return 1;
    }

    if (dan == 0) {
        
        for (int d = 2; d <= 9; d++) {
            printf("=== %d단 ===\n", d);
            for (int i = 1; i <= 9; i++) {
                printf("%d x %d = %2d\n", d, i, d * i);
            }
            puts("");
        }
    }
    else if (dan >= 2 && dan <= 9) {
        
        printf("=== %d단 ===\n", dan);
        for (int i = 1; i <= 9; i++) {
            printf("%d x %d = %2d\n", dan, i, dan * i);
        }
    }
    else {
        puts("잘못된 입력입니다. 0 또는 2~9 사이의 숫자를 입력하세요.");
        return 1;
    }

    return 0;
}
