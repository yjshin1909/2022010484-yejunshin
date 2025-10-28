#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void) {
    const double m = 100.0;
    const double mu_s = 0.5, mu_k = 0.4, g = 9.81;

    double theta_deg;
    printf("=== 팔레트 경사로 문제 ===\n");
    printf("입력: 경사각 theta(도, 0<=theta<90)\n");
    printf(">> theta = ");
    if (scanf("%lf", &theta_deg) != 1) { printf("invalid input\n"); return 0; }

    if (theta_deg < 0.0 || theta_deg >= 90.0) {
        printf("invalid input\n");
        return 0;
    }

    double theta = theta_deg * M_PI / 180.0;
    double sinth = sin(theta), costh = cos(theta);

    int stick = (sinth <= mu_s * costh);

    if (stick) {
        printf("정지상태 유지 (미끄러지지 않음)\n");
    }
    else {
        double a = g * (sinth - mu_k * costh);
        a = (a > 0.0) ? a : 0.0;
        printf("미끄러짐: 가속도 a = %.4f m/s^2\n", a);
    }
    return 0;
}
