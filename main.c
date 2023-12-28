#include "shell.h"

/**
 * main - Base functionality of shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		line = readline();
		if (!line)
			break;

		args = parse_line(line);
		free(line);

		if (!args[0])
		{
			free(args);
			continue;
		}

		execute_command(args);

        free_args(args);
	}

	free(line);
	return (0);
}
