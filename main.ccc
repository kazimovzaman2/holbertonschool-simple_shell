#include "shell.h"


int findpath(char *argument0, char *newpath)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		snprintf(newpath, 50, "%s/%s", token, argument0);
		if (access(newpath, X_OK) == 0)
		{
			return (0);
		}
		token = strtok(NULL, ":");
	}
	return (1);
}



int runcommand(char *line)
{
	pid_t child_pid;
	int i, status;
	char *args[10];

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (child_pid == 0)
    {
		i = 0;
		args[i] = strtok(line, " ");
		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, " ");
		}
		args[i] = NULL;
		if (args[0] && !strchr(args[0], '/'))
		{
			char newpath[50];

			if (findpath(args[0], newpath) == 0)
				args[0] = newpath;
		}
		execve(args[0], args, environ);
		perror(args[0]);
		exit(1);
	}
	else
	{
		wait(&status);
        if (WIFEXITED(status))
        {
            return (WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            return (127);
        }
	}

    return (-1);
}



int main(void)
{
	char *line = NULL, **env = environ;
	size_t line_len = 0;
	ssize_t line_read;
	int i;
    char *ptr;
    int command_status = 0;

	while (1)
	{
		line_read = getline(&line, &line_len, stdin);
		if (line_read == -1)
		{
			free(line);
			exit(0);
		}
		ptr = line;
        while (*ptr != '\0')
        {
            if (*ptr == '\n')
            {
                *ptr = '\0';
                break;
            }
            ptr++;
        }
        for (i = 0; line[i] != '\0'; i++)
		{
			if (line[i] != ' ')
				break;
		}
		if (line[i] == '\0')
			continue;
		if (strcmp(line, "exit") == 0)
			break;
		else if (strcmp(line, "env") == 0)
        {
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
		}
		else
			command_status = runcommand(line);
	}
	free(line);
	return (command_status);
}
