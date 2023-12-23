#include "shell.h"


/**
 * main - open source file
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		printf("($) ");

		line = readline();
		if (!line)
			break;

		args = parse_line(line);
		execute_command(args);

		free(line);
		free(args);
	}

	return (0);
}
