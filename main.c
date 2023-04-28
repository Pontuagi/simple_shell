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
	char *buffer = NULL, *promt = "$ ";

	size_t n;
	ssize_t read;
	int interactive = isatty(STDIN_FILENO);

	signal(SIGINT, sigint_handler);
	while (1)
	{
		if (interactive)
			write(STDOUT_FILENO, promt, 2);
		read = getline(&buffer, &n, stdin);
		if (read == -1)
		{
			if (interactive)
				_putchar('\n');
			break;
		}
		if (buffer[0] == '\n')
			continue;
		if (buffer == NULL)
			return (-1);
		buffer[_strcspn(buffer, "\n")] = '\0';
		if (access(buffer, X_OK) == 0)
			_exec_file(buffer, av, env);
		else
		{
			ac = _argc(buffer);
			av = tokenize(buffer, ac);
			if (av == NULL)
				_eputs("failed to allocate tokens to av\n");
			keyword(ac, av, env);
			free(av);
		}
		if (!interactive)
			break;
	}
	free(buffer);
	return (0);
}
