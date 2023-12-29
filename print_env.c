#include "shell.h"

void print_env(void)
{
    char **env;

    for (env = environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
}
