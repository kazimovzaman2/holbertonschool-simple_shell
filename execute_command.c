#include "shell.h"


/**
 * execute_command - Execute a command in a new process.
 *
 * @args: Arguments as a null-terminated array.
 *
 * Return: No return value.
 */
void execute_command(char **args)
{
	pid_t child_pid;
	int status;

    if (!args || !args[0])
        return;

    if (strcmp(args[0], "exit") == 0)
    {
        free(args);
        exit(EXIT_SUCCESS);
    } 

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
	}
	else if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
            fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);

        if (WIFEXITED(status))
        {
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0)
                exit(2);
        }
	}
}
