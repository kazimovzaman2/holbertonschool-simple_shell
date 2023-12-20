#include <stdio.h>
#include <stdlib.h>

/*
 * main - Entry point
 *
 * Return: 0
 */
int main(void)
{
	char *input = NULL;
	size_t input_size = 0;

	printf("$ ");
	getline(&input, &input_size, stdin);
	printf("%s", input);

	free(input);
	return (0);
}
