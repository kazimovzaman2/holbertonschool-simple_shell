#include "shell.h"


char **parse_line(char *line)
{
	int token_count = 0;
	char *token;
	char **tokens = malloc(strlen(line) * sizeof(char *));

	if (!tokens)
		return (NULL);

	token = strtok(line, " ");

	while (token)
	{
		tokens[token_count] = strdup(token);
		if (!tokens[token_count])
		{
			fprintf(stderr, "Error happens.");
			exit(EXIT_FAILURE);
		}
		token_count++;
		token = strtok(NULL, " ");
	}

	tokens[token_count] = NULL;

	return tokens;
}
