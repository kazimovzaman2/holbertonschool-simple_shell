#include "shell.h"

/**
 * main - Base functionality of shell.
 *
 * Return: Always 0.
 */
int main(void)
{
    size_t input_len = 0;
    ssize_t line = 0;
    char *input = NULL;

	while (1)
	{
		line = getline(&input, &input_len, stdin);
		if (line == EOF)
        {
            free(input);
            exit(0);
        }

        if (line > 0 && input[line - 1] == '\n')
            input[line - 1] = '\0';

       process_user_input(input); 
	}

	free(input);
	return (0);
}