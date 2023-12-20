#include "shell.h"


/**
 * main - open source file
 *
 * Return: Always 0.
 */
int main(void)
{
	size_t input_size = 0;
	char *args;

	while (1)
	{
		printf("($) ");

		if (getline(&args, &input_size, stdin) == -1)
			break;

		printf("%s", args);
	}

	free(args);
	return (0);
}
