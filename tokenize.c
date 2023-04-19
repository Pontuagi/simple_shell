#include "main.h"

/**
  * tokenize - function to tokenize a string in a array vector
  * @argc: number of arguments in array
  * @buffer: string to tokenize
  *
  * Return: return Array of arguments or NULL
  */

char **tokenize(char *buffer, int argc)
{
	char **argv, *token;
	int i;
	char *delim = " \n";

	argv = malloc(sizeof(char *) * argc);
	if (argv == NULL)
		return (NULL);
	token = strtok(buffer, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		argv[i] = token;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}
