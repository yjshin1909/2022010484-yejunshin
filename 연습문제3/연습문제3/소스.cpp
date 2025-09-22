#include <stdio.h>

int main(void) {
	char ch = 'A';
	const char* line1 = "First line";
		const char* line2 = "Indented second line";
	const char* line3 = "Third line";
	double avg = 87.35;

	printf("=== Char/String & Escapes ===\n\n"
		"Char : %c, code : %d\n\n"
		"Message : \n\n"
		"%s\n\n"
		"\t%s\n\n"
		"%s\n\n"
		"Quotes : \"double quotes\" and 'single quotes'\n\n"
		"Backslash : \\\n\n"
		"Average : [%8.2f]\n\n",
		ch, (int)ch,
		line1,
		line2,
		line3,
		avg);

	return 0;
}