#include "shell.h"


/**
 * parse_line - Tokenize a string into an array of tokens.
 *
 * @line: The input string to be tokenized.
 *
 * This function takes a string as input and tokenizes into an array of
 * string, separating tokens based on space and newline.
 *
 * Return: And array of tokens, with the last element is NULL.
 */
char **parse_line(char *line)
{
	int token_count = 0;
	char *token;
	char **tokens = malloc(strlen(line) * sizeof(char *));

	if (!tokens)
		return (NULL);

	token = strtok(line, " \n\t");

	while (token)
	{
		tokens[token_count] = strdup(token);
		if (!tokens[token_count])
		{
			free(tokens[token_count]);
			fprintf(stderr, "Error happens.");
			exit(EXIT_FAILURE);
		}
		token_count++;
		token = strtok(NULL, " \n\t");
	}

	tokens[token_count] = NULL;

	return (tokens);
}
