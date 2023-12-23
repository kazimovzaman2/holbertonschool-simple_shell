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
	char *tokens[30];

	while (1)
	{
		printf("($) ");

		line = readline();
		if (!line)
			break;

		parse_line(line, tokens);
		printf("%s", line);
	}

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);

	free(line);
	return (0);
}
