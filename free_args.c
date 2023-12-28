#include "shell.h"

/**
 * free_args - Free all arguments.
 *
 * @args: The input array.
 *
 * Return: 0.
 */
void free_args(char **args)
{
    int i;

    if (!args)
        return;

    for (i = 0; args[i] != NULL; i++)
        free(args[i]);
    free(args);
}
