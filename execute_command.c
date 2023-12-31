#include "shell.h"
#include <errno.h>

/**
 * execute_command - Execute a command in a new process.
 *
 * @args: Arguments as a null-terminated array.
 *
 * Return: No return value.
 */
int execute_command(char **args)
{
		pid_t child_pid;
	struct stat st;
	int status = 0, flag = 0, i = 0;
	char *fullPath = NULL, **pathArr = NULL, *path = NULL;

	if (stat(args[0], &st) == 0 && strcmp(args[0], "hbtn_ls") != 0)
	{
		fullPath = malloc(strlen(args[0]) * sizeof(char *));
		strcpy(fullPath, args[0]);
		flag = 1;
		child_pid = fork(); }
	else if (getenv("PATH") && strcmp(getenv("PATH"), "") != 0)
	{
		path = malloc(strlen(getenv("PATH")) * sizeof(char *));
		strcpy(path, getenv("PATH"));
		pathArr = parse_line(path, ":");
		if (!path || !pathArr)
			perror("malloc");
		while (pathArr[i])
		{
			fullPath = malloc((strlen(pathArr[i]) + strlen(args[0]) + 1)
					* sizeof(char *));
			strcpy(fullPath, pathArr[i]);
			strcat(fullPath, "/");
			strcat(fullPath, args[0]);
			if (stat(fullPath, &st) == 0)
			{
				child_pid = fork();
				flag = 1;
				break; }
			free(fullPath);
			i++; }
		for (i = 0; pathArr[i]; i++)
			free(pathArr[i]);
		free(pathArr);
		free(path);
	}
	if (!flag)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return (127);
	}
	else
	{
		if (child_pid == -1)
		{
			free(fullPath);
			perror("fork"); }
		else if (child_pid == 0)
		{
			if (execve(fullPath, args, environ) == -1)
			{
				free(fullPath);
				return (2); }
		}
		else
		{
			waitpid(child_pid, &status, 0);
			free(fullPath);
			if (WIFEXITED(status))
				return (WEXITSTATUS(status)); }
	}
	return (0);
}
