#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int passengers;                 // 승객 수 (1~3)
    double w_passengers, w_cargo;   // 승객 총무게(kg), 짐 무게(kg)
    const double RATED = 600.0;

    printf("[Elevator] passengers(1~3) totalPassengerWeight(kg) cargoWeight(kg): ");
    if (scanf("%d %lf %lf", &passengers, &w_passengers, &w_cargo) != 3) {
        printf("invalid input\n");
        return 0;
    }

    // 물리/규칙 검증
    int invalid =
        (passengers < 1 || passengers > 3) ||          // 승객 수 범위
        (w_passengers < 0 || w_cargo < 0) ||           // 음수 무게 불가
        (passengers == 3 && w_cargo > 0) ||            // 3인 탑승 시 짐 금지
        (passengers <= 2 && (w_passengers == 0));      // 사람이 있는데 승객 총무게가 0 kg는 비현실(센서 오류 가정)

    if (invalid) {
        printf("invalid input\n");
        return 0;
    }

    double total = w_passengers + w_cargo;

    // 조건연산자로 최종 상태 결정
    const char* state = (total <= RATED) ? "OK" : "Overload";
    printf("%s\n", state);
    return 0;
}
