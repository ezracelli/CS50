#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Please specify a password length.\n");
		return 1;
	}

	int length = atoi(argv[1]);
	char current;

	srand((unsigned int) time(NULL));

	for (int i = 0; i < length; i ++)
	{
		current = (rand() % 94) + 32;
		printf("%c", current);
	}

	printf("\n");
	return 0;
}
