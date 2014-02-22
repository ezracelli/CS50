#include <stdio.h>
#include <stdlib.h>

int combination(int n, int k);
long long factorial(int n);

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Please specify height.\n");
		return 1;
	}

	int height = atoi(argv[1]);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			printf("%d  ", combination(i, j));
		}

		printf("\n");
	}

	return 0;
}

int combination(int n, int k)
{
	return (int) (factorial(n)/(factorial(k) * factorial(n-k)));
}

long long factorial(int n)
{
	if (n == 0)
		return 1;

	long long buffer = 1;
	for (int i = n; i > 0; i--)
	{
		buffer = buffer * i;
	}
	return buffer;
}
