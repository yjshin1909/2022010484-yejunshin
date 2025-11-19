#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_line_info(double p1[], double p2[], double* slope, double* bias)
{
	*slope = (p2[1] - p1[1]) / (p2[0] - p1[0]);
	*bias = p1[1] - (*slope) * p1[0];
}

int main(void)
{
	double p1[2];
	double p2[2];
	double slope, bias;

	printf("Input 1st point information (x y): ");

	scanf("%If %If", &p1[0], &p1[1]);

	printf("Input 2nd point information (x y): ");

	scanf("%If %If", &p2[0], &p2[1]);

	get_line_info(p1, p2, &slope, &bias);

	printf("\nResult\n");
	printf("slope : %.4If\n", slope);
	printf("bias : %.4If\n", bias);
	printf("line equation : y = %.4Ifx + %.4If\n", slope, bias);

	return 0;
}