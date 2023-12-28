#include "shell.h"

void execute_command(char *argv[], char *input)
{
    int status;
    pid_t child;

    (void) input;
    child = fork();

    if (child == -1)
    {
        perror("Fail Fork\n");
        exit(0);
    }
    else if (child == 0)
    {
        execve(argv[0], argv, environ);
        free(argv[0]);
        exit(0);
    }
    else
    {
        wait(&status);
    }
}
