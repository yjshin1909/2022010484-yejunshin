#include <stdio.h>
#define NUM_PRINT 0

void PrintHelloWorld(int nCount);

int main(void)
{
	int nCount = 100;
	PrintHelloWorld(nCount);
	return 0;
}

void PrintHelloWorld(int nCount)
{
	if (nCount == NUM_PRINT)
	{
		return;
	}
	printf("HEllo, World!(%d)\n", nCount);
	PrintHelloWorld(--nCount);
	printf("jam\n");
	return;
}