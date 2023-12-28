#include "shell.h"


/**
 * readline - Read a line of input from the standard input.
 *
 *
 * Return: A pointer string containing the input line.
 */
char *readline(void)
{
	char *line = NULL;
	size_t line_size = 0;

	if (getline(&line, &line_size, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
