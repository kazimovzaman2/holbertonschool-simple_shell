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
		
		args = parse_line(line, " \n\t");
		free(line);
		if (!args[0])
		{
			free(args);
			continue;
		}
		else if (strcmp(args[0], "exit") == 0 && args[1] == NULL)
		  {
		    free(args);
		    exit(0);
		  }
		else if (strcmp(args[0], "env") == 0)
		  {
		    free(args);
		    print_env();
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
