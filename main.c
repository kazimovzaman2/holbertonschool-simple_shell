#include "shell.h"


/**
 * main - open source file
 *
 * Return: Always 0.
 */
int main(void)
{
	int i = 0;
	char *line;
	char **tokens;

	while (1)
	{
		printf("($) ");

		line = readline();
		if (!line)
			break;

		tokens = parse_line(line);
		printf("%s", line);
	}

	free(line);
	return (0);
}
