#define _CRT_SECURE_NO_WARNINGS //scanf ���� ��� ����
#include <stdio.h>

int main(void) {
    int age;

    printf("���̸� �Է��ϼ���: ");
    scanf("%d", &age);

    // ���� ������ ���: ���� ��
    if (age < 0) {
        printf("�߸��� �����Դϴ�.\n");
        return 0;
    }

    // �� ������ ���: ���ɴ� �Ǻ�
    if (age >= 0 && age < 13) {
        printf("����Դϴ�.\n");
    } else if (age >= 13 && age < 20) {
        printf("û�ҳ��Դϴ�.\n");
    } else if (age >= 20 && age < 65) {
        printf("�����Դϴ�.\n");
    } else {
        printf("�����Դϴ�.\n");
    }

    // ���� ������ ���: ���� ���� ���
    age++;  // age = age + 1 �� ����
    printf("���⿡�� %d���� �˴ϴ�.\n", age);

    return 0;
}