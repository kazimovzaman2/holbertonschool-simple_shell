#include <stdio.h>


/*
 * main - Entry point
 *
 * @ac: var
 * @av: var
 * Return: 0
 */
int main(int ac, char **av)
{
	int i;

	(void) ac;
	for (i = 0; av[i] != NULL; i++)
		printf("%s\n", av[i]);

	return (0);
}
