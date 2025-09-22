#include <stdio.h>

int main(void) {
	int age = 28;
	unsigned int count = 3000000000;
	float score = 93.5f;
	const char* title = "Basic Contants";
	const char* name = "Sungwook";
	char initial = name[0];

	printf("=== %s ===\n\n"
		"Name\t: %s\n\n"
		"Initial\t: %c\n\n"
		"Age\t: %d\n\n"
		"Score\t: %f\n\n"
		"Count\t: %u\n\n",
		title, name, initial, age, score, count);

	return 0;
}