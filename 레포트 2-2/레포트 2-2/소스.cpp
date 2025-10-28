#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    double temp;            // ���� �µ�(��C)
    int doorOpen;           // 0=����, 1=����
    int openSecs;           // ���� ���� ���� �ð�(��)
    int outSecs;            // ���� ���¿��� �µ� ���� ��� �ð�(��)

    printf("=== ��ų���� �µ� �����ġ ===\n");
    printf("�Է� ����: [����µ�(��C)] [������(0=����,1=����)] [�����ð�(��)] [������Ż�ð�(��,������)]\n");
    printf("���� �Է�: 5.0 0 0 0\n");
    printf("------------------------------------------\n");
    printf(">> �Է��ϼ���: ");

    if (scanf("%lf %d %d %d", &temp, &doorOpen, &openSecs, &outSecs) != 4) {
        printf("invalid input\n");
        return 0;
    }

    /* -------- �Է� ��ȿ�� ���� -------- */
    if ((doorOpen != 0 && doorOpen != 1) || openSecs < 0 || outSecs < 0) {
        printf("invalid input\n");
        return 0;
    }
    // ���� �����ε� �����ð��� �����ϸ� ���
    if (doorOpen == 0 && openSecs != 0) {
        printf("invalid input\n");
        return 0;
    }

    /* -------- ���� ���� -------- */
    int inRange = (temp >= 2.0 && temp <= 8.0);
    int outRange = !inRange;

    const char* state =
        (doorOpen == 0 && inRange) ? "Normal" :
        (doorOpen == 1 && openSecs >= 60 && outRange) ? "Critical" :
        (doorOpen == 0 && outRange) ? (outSecs <= 30 ? "Warning" : "Critical")
        : "Normal";

    printf("\n���� ����: %s\n", state);
    return 0;
}
