#include "main.h"

/**
 * get_history_
 * ets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *get_history(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * wrt_hist - 
 * ruct
 *
 * Return: 1 on success, else -1
 */
int wrt_hist(info_t *info)
{
	ssize_t fd;
	char *filename = get_history(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_his- reads history from file
 * @info: the puct
 *
 * Return: histcount on success, 0 otherwise
 */
int r_hist(info_t *info)
{
	int x, hist = 0, linec = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (x = 0; x < fsize; x++)
		if (buf[x] == '\n')
		{
			buf[x] = 0;
			build_hist(info, buf + hist, linec++);
			hist = x + 1;
		}
	if (hist != x)
		build_hist(info, buf + hist, linec++);
	free(buf);
	info->histcount = linec;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	re_hist(info);
	return (info->histcount);
}

/**tory linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @e history linecount, histcount
 *
 * Return: Always 0
 */
int build_hist(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * re_hist - renumbersd list after changes
 * @info: Structure l arguments. Used to maintain
 *
 * Return: the nunt
 */
int re_hist(info_t *info)
{
	list_t *node = info->history;
	int p = 0;

	while (node)
	{
		node->num = p++;
		node = node->next;
	}
	return (info->histcount = p);
}
