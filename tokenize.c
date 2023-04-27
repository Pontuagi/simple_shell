#include "main.h"

/**
  * tokenize - function to tokenize a string in a array vector
  * @bytes: number of bytes read from stdin
  * @buffer: string to tokenize
  *
  * Return: return Array of arguments or NULL
  */

char **tokenize(char *buffer)
{
	char **argv, *token;
	int i = 0;

	argv = malloc(sizeof(char *) * 2);
	if (argv == NULL)
		return (NULL);
	token = strtok(buffer, " ");
	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (argv[i] == NULL)
		{
			free(argv[i]);
		}
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	return (argv);
}
