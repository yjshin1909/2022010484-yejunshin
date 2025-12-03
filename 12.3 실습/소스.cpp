#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void clear_input_buffer(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
		;
	}
}

int main(void)
{
	char str1[100];
	char copy[100];
	char str2[100];
	char sentence[200];
	char temp[200];

	char* pos;
	char ch;

	char* p_str1 = str1;
	char* p_str2 = str2;
	char* p_copy = copy;
	char* p_sentence = sentence;
	char* p_temp = temp;

	printf("Enter first string (no spaces): ");
	scanf("%99s", p_str1);

	printf("Enter second string (no spaces): ");
	scanf("%99s", p_str2);

	printf("\n--- Printed strings (using puts) ---\n");
	puts(p_str1);
	puts(p_str2);
}