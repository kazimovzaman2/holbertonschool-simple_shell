#include "shell.h"


/**
 * main - Base functionality of shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	char *line;
	char **args;

	while (1)
	{
		line = readline();
		if (!line)
		{
			free(line);
			break;
		}

		args = parse_line(line);
		if (!args[0])
		{
			free(args);
			continue;
		}
		execute_command(args);

		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	}

	free(line);
	return (0);
}
