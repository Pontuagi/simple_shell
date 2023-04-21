#include "main.h"

/**
  * get_path - find the path to a location of a command
  * @command: the command to check
  *
  * Return: return filepath or NULL
  */

char *get_path(char *command)
{
	char *path, *path_copy, *file_path, *token;
	int command_len, path_len;
	struct stat buffer;
	const char *delim = ":";

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_len = strlen(command);
		token = strtok(path_copy, delim);
		while (token != NULL)
		{
			path_len = strlen(token);
			file_path = malloc(path_len + command_len + 2);
			strcpy(file_path, token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				token = strtok(NULL, delim);
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
			return (command);

		return (NULL);
	}
	return (NULL);
}
