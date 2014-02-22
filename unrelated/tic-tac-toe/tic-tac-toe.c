#include <stdio.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
	for (int i = 0; i < 3; i++)
	{
		if (i == 0 || i == 1)
			printf("___|___|___\n");
		else
			printf("   |   |   \n");
	}

	printf("this game is nonfunctional :^)\n");
	return 0;
}
