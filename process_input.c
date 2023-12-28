#include "shell.h"

/**
 * main - Base functionality of shell.
 *
 * Return: Always 0.
 */
void process_user_input(char *user_input)
{
    char *token = NULL;
    char *tokens[1024] = { NULL };
    int index = 0;

    token = strtok(user_input, " \n\t");
    while (token)
    {
        if (strlen(token) > 0)
        {
            tokens[index] = token;
            index += 1;
        }
        token = strtok(NULL, " \n\t");
    }

    if (tokens[0] == NULL)
    {
        return;
    }
    if (strcmp(tokens[0], "env") == 0)
    {
        print_env();
        return;
    }
    if (strcmp(tokens[0], "exit") == 0 && tokens[1] == NULL)
    {
        free(tokens[0]);
        exit(0);
    }

    token = strdup(tokens[0]);
    tokens[0] = _getpath(tokens[0]);
    if (!tokens[0])
    {
        free(token);
        execute_command(tokens, user_input);
        free(tokens[0]);
        return;
    }
    fprintf(stderr, "./hsh: 1: %s not found\n", token);
    free(token);
    exit(127);
}
