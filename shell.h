#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *readline(void);
char **parse_line(char *line, char *delimiter);
int execute_command(char **args);
void print_env(void);
char *find_executable(char **args);

#endif
