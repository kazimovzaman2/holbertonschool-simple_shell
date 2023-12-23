#include "shell.h"


char **parse_line(char *line, char **array)
{
	int token_count = 0;
	char *token = strtok(line, " ");

	if (!line || !array)
		return (NULL);

	while (!token)
	{
		array[token_count] = malloc(strlen(token) + 1);
		strcpy(array[token_count], token);
		token_count++;

		if (token_count >= 30)
			break;

		token = strtok(NULL, " ");
	}

	array[token_count] = NULL;

	return array;
}
