#include "main.h"

/**
  * _argc - count the number of arguments the user inputed.
  * @buf: buffer that stores the string
  *
  * Return: number of arguments
  */

int _argc(char *buf)
{
	char *token;
	int ac = 0;
	const char *delim = " \n";
	char *buf_cpy = _strdup(buf);

	if (buf_cpy == NULL)
		return (0);

	token = strtok(buf_cpy, delim);
	while (token != NULL)
	{
		ac++;
		token = strtok(NULL, delim);
	}
	free(buf_cpy);
	return (ac);
}
