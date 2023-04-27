#include "main.h"

/**
  * main - create a simple shell
  * @ac: argument count
  * @av: argument vector to store the arguments
  * @env: parameter to store our local enviromental variables
  *
  * Return: 0 or -1
  */

int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	size_t n;
	ssize_t read;

	while (1)
	{
		_putchar('(');
		_putchar('$');
		_putchar(')');
		_putchar(' ');
		read = getline(&buffer, &n, stdin);
		if (read == -1)
			break;

		if (buffer[0] == '\n')
			continue;
		if (buffer == NULL)
			return (-1);
		ac = _argc(buffer);
		av = tokenize(buffer, ac);
		keyword(ac, av, env);
	}
	free(buffer);
	return (0);
}
