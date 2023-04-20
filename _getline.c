#include "main.h"

#define _BUFSIZE 1024
char *_read_line(void)
{
	int bufsize = _BUFSIZE;
	int pos = 0;
	int c;
	char *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		fprintf(stderr, "error allocating memory\n");
		exit(EXIT_FAILURE);
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
