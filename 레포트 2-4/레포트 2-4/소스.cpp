#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    const double D = 0.05;            // m
    const double rho = 998.2;         // kg/m^3
    const double mu = 0.001002;      // Pa��s

    double v; // m/s
    printf("=== ��� ���� ���� & ���� ��� ===\n");
    printf("�Է�: ���� v (m/s, v>=0)\n");
    printf(">> v = ");
    if (scanf("%lf", &v) != 1) { printf("invalid input\n"); return 0; }

    if (v < 0.0) { printf("invalid input\n"); return 0; }

    double Re = (rho * v * D) / mu;
    double q = 0.5 * rho * v * v; // Pa

    // ���ǿ����ڷ� ���� ���ڿ� ����
    const char* state =
        (Re < 2300.0) ? "���� (Laminar)" :
        (Re < 4000.0) ? "õ�� (Transitional)" :
        "���� (Turbulent)";

    printf("Re = %.2f -> %s\n", Re, state);
    printf("���� q = %.2f Pa\n", q);
    return 0;
}
