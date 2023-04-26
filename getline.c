#include "main.h"

/**
  * _read_line - get input from standard input and save to buffer
  *
  * Return: return pointer to buffer.
  */
#define _BUFSIZE 1024
char *_read_line(void)
{
	int bufsize = _BUFSIZE;
	int pos = 0;
	int c;
	char *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		perror("error allocating memory\n");
		free(buffer);
		return (NULL);
	}

	while (1)
	{
		c = getchar();

		if (c == EOF || c == '\n')
		{
			buffer[pos] = '\0';
			return (buffer);
		}
		else
		{
			buffer[pos] = c;
		}
		pos++;

		if (pos >= bufsize)
		{
			bufsize += _BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "Error re-allocating memory\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
