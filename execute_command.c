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
	int status, i = 0;
	char *fullPath;
	struct stat st;
	char **pathArr;
 	char *path = malloc(strlen(getenv("PATH")));
 	strcpy(path, getenv("PATH"));
 	pathArr = parse_line(path, ":");
 	free(path);

	if (stat(args[0], &st) == 0)
    {
        fullPath = malloc(strlen(args[0]) * sizeof(char *));
        strcpy(fullPath, args[0]);
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
            break;
            }
            free(fullPath);
            i++;
    	}
    }
	if(!pathArr[i])
	{
	    i=0;
	    while (pathArr[i])
	    {
	       free(pathArr[i]);
	       i++;
	    }
	    free(pathArr);
	    perror("Error");
	}
	else
	{
	     if (child_pid == -1)
	    {
	        free(fullPath);
		perror("fork");
	    }
	    else if (child_pid == 0)
	    {
		    if (execve(fullPath, args, NULL) == -1)
		    {
			perror("Error");
			exit(EXIT_FAILURE);
		    }
		    free(fullPath);
	    }
	    else
		    wait(&status);
	}
	}
