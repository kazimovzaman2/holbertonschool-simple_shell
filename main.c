#include "shell.h"

/**
 * main - Base functionality of shell.
 *
 * Return: Always 0.
 */
int main(void)
{
    size_t input_len = 0;
    size_t line = 0;
    char *input = NULL;

	while (1)
	{
		line = getline(&input, &input_len, stdin);
		if (line == EOF)
        {
            free(input);
            exit(0);
        }
	}

	free(input);
	return (0);
}
