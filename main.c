#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int i;
	pid_t child_pid;
	int status;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0)
		{
			char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Eroor:");
				return (1);
			}
		}
		else
		{
			wait(&status);
			printf("Chid process running. Status: %d\n", status);
		}
	}

	return (0);
}
