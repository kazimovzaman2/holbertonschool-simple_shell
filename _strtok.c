#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *str = "This is test.";
	char *stc = malloc(sizeof(char) * strlen(str));

	char delim[5] = " ";
	char *words;

	strcpy(stc, str);
	words = strtok(stc, delim);
	while (words != NULL)
	{
		printf("%s\n", words);
		words = strtok(NULL, delim);
	}


	return (0);
}
