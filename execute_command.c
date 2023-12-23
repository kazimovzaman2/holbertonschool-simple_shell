#include "shell.h"


void execute_command(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
	}
	else if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
