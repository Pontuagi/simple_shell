#include "main.h"

/**
 * is_command - function to check if is command
 * @path: path to the file
 * @info: struct info
 *
 * Return: 1 if true, 0 otherwise
 */
int is_command(info_t *info, char *path)
{
	struct stat t;

	(void)info;
	if (!path || stat(path, &t))
		return (0);

	if (t.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_c - duplicates characters
 * @pathstr: path to the string
 * @start: start index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_c(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int x = 0, k = 0;

	for (k = 0, x = start; x < stop; x++)
		if (pathstr[x] != ':')
			buf[k++] = pathstr[x];
	buf[k] = 0;
	return (buf);
}

/**
 * find_p - finds this cmd in the PATH string
 * @info: struct info
 * @pathstr: path string
 * @cmd: the cmd to find
 *
 * Return: th of cmd if found or NULL
 */
char *find_p(info_t *info, char *pathstr, char *cmd)
{
	int x = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_command(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[x] || pathstr[x] == ':')
		{
			path = dup_c(pathstr, curr_pos, x);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_command(info, path))
				return (path);
			if (!pathstr[x])
				break;
			curr_pos = x;
		}
		x++;
	}
	return (NULL);
}
