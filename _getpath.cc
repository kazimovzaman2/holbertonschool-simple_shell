#include "shell.h"



/*char* contains_slash(const char* command) {
    const char *c;

    for (c = command; *c != '\0'; ++c) {
        if (*c == '/') {
            return strdup(command);
        }
    }

    return NULL;
}*/



char *_getpath(char *command)
{
    int i = 0;
    char *token = NULL, *history, *result = NULL;

    if (strchr(command, '/' != NULL))
        return (strdup(command));

    while (environ[i])
    {
        history = strdup(environ[i]);
        token = strtok(history, "=");
        if (strcmp(token, "PATH") == 0)
        {
            token = strtok(NULL, "=");
            token = strtok(token, ":");

            while (token)
            {
                result = malloc(strlen(token) + strlen(command) + 2);
                if (result == NULL)
                {
                    perror("Malloc error");
                    return (NULL);
                }

                sprintf(result, "%s%s", token, command);

                free(history);
                return (result);
            }
        }
        free(history);
        i++;
    }
    free(command);
    return (NULL);
}
