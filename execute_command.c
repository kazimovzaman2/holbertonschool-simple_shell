#include "shell.h"
#include <errno.h>

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
  int status, flag = 0, i = 0;
    char *fullPath;
    struct stat st;
    char **pathArr;

    if (getenv("PATH"))
      {
    char *path = malloc(strlen(getenv("PATH")) * sizeof(char *));
    
    strcpy(path, getenv("PATH"));

    pathArr = parse_line(path, ":");

    if (!path || !pathArr)
      perror("malloc");
    
    free(path);
      }
    
    if (stat(args[0], &st) == 0)
    {
        fullPath = malloc(strlen(args[0]) * sizeof(char *));
        strcpy(fullPath, args[0]);
	flag = 1;
        child_pid = fork();
    }
    else
    {
        while(pathArr[i])
        {
            fullPath = malloc((strlen(pathArr[i]) + strlen(args[0]) + 1) * sizeof(char *));
            strcpy(fullPath, pathArr[i]);
            strcat(fullPath, "/");
            strcat(fullPath, args[0]);
            if (stat(fullPath, &st) == 0)
            {
                child_pid = fork();
		flag = 1;
                break;
            }
            free(fullPath);
            i++;
        }
    }
    if(!flag)
    {
        for (i = 0; pathArr[i]; i++)
        free(pathArr[i]);
        free(pathArr);
        fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
	return;
    }
    else
    {
        if (child_pid == -1)
        {
            free(fullPath);
            for (i = 0; pathArr[i]; i++)
            free(pathArr[i]);
            free(pathArr);
            perror("fork");
        }
        else if (child_pid == 0)
        {
            if (execve(fullPath, args, environ) == -1)
            {
                free(fullPath);
                for (i = 0; pathArr[i]; i++)
                free(pathArr[i]);
                free(pathArr);
                perror("Error");
                exit(EXIT_FAILURE);
            }
        }
        else
        wait(&status);

        free(fullPath);
        for (i = 0; pathArr[i]; i++)
        free(pathArr[i]);
        free(pathArr);
    }
}
