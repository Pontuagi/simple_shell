#include "main.h"

/**
  * tokenize - function to tokenize a string in a array vector
  * @argc: argument count
  * @buffer: string to tokenize
  *
  * Return: return Array of arguments or NULL
  */

char **tokenize(char *buffer, int argc)
{
	char **argv, *token;
	int i, j;
	const char *delim = " \n";
	char *buf_cpy = _strdup(buffer);

	if (buf_cpy == NULL)
		return (NULL);

	argv = malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
	{
		free(buf_cpy);
		return (NULL);
	}
	token = strtok(buf_cpy, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (argv[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(argv[j]);
			free(argv);
			free(buf_cpy);
			return (NULL);
		}
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(buf_cpy);

	return (argv);
}
