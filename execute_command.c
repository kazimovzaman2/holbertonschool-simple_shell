#include "shell.h"


/**
 * execute_command - Execute a command in a new process.
 *
 * @args: Arguments as a null-terminated array.
 *
 * Return: No return value.
 */
void execute_command(char **args, char *line)
{
	pid_t child_pid;
	int status;
    int i;

    if (!args || !args[0])
        return;

    if (strcmp(args[0], "exit") == 0)
    {
         for (i = 0; args[i] != NULL; i++)
            free(args[i]);
        free(args);
        free(line);
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
			perror("Error");
			exit(127);
		}
	}
	else
	{
        /*wait(&status);*/
		waitpid(child_pid, &status, 0);

        if (WIFEXITED(status))
        {
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0)
                exit(2);
        }
	}
}
