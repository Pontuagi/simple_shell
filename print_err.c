#include "main.h"

/**
  * _eputs - prints output to stderr
  * @s: string to be printed
  *
  */

void _eputs(char *s)
{
	size_t i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		if (_eputchar(s[i]) == -1)
		{
			perror("eputchar fail");
			return;
		}
		i++;
	}
}

/**
  * _eputchar - writes a character ti stderr
  * @c: character to be printed
  *
  * Return: -1 on failure, 0 on success
  */

int _eputchar(char c)
{
	static int n;
	static char buffer[WRITE_BUFSIZE];

	if (c == FLUSH_BUF || n >= WRITE_BUFSIZE)
	{
		if (write(STDERR_FILENO, buffer, n) == -1)
		{
			perror("write failed");
			return (-1);
		}
		n = 0;
	}
	if (c != FLUSH_BUF)
		buffer[n++] = c;
	return (0);
}
