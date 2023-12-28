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
			break;
		if (strcmp(line, "exit"))
			break;

		args = parse_line(line, " \n\t");
		free(line);
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
