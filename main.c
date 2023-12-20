#include "shell.h"


/**
 * main - open source file
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;

	while (1)
	{
		printf("($) ");

		line = readline();
		if (!line)
			break;
		printf("%s", line);
	}

	free(line);
	return (0);
}
