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

void process_user_input(char *user_input);
char *_getpath(char *command);
void execute_command(char *argv[], char *input);
void print_env(void);

#endif
