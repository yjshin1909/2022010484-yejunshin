#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int passengers;                 // �°� �� (1~3)
    double w_passengers, w_cargo;   // �°� �ѹ���(kg), �� ����(kg)
    const double RATED = 600.0;

    printf("[Elevator] passengers(1~3) totalPassengerWeight(kg) cargoWeight(kg): ");
    if (scanf("%d %lf %lf", &passengers, &w_passengers, &w_cargo) != 3) {
        printf("invalid input\n");
        return 0;
    }

    // ����/��Ģ ����
    int invalid =
        (passengers < 1 || passengers > 3) ||          // �°� �� ����
        (w_passengers < 0 || w_cargo < 0) ||           // ���� ���� �Ұ�
        (passengers == 3 && w_cargo > 0) ||            // 3�� ž�� �� �� ����
        (passengers <= 2 && (w_passengers == 0));      // ����� �ִµ� �°� �ѹ��԰� 0 kg�� ������(���� ���� ����)

    if (invalid) {
        printf("invalid input\n");
        return 0;
    }

    double total = w_passengers + w_cargo;

    // ���ǿ����ڷ� ���� ���� ����
    const char* state = (total <= RATED) ? "OK" : "Overload";
    printf("%s\n", state);
    return 0;
}
