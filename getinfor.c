#include "main.h"

/**
 * clear_info - in_t struct
 * @info: struct address
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @info: struct address
 r
 */
void set_info(info_t *info, char **av)
{
	int j = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (j = 0; info->argv && info->argv[j]; j++)
			;
		info->argc = j;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - frees info_t struct fields
 * @info: struct address
 * @alls
 */
void free_info(info_t *info, int all)
{
	_ffre(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		   if (info->env)
free_list(&(info->env));
		         if (info->history)
			free_list(&(info->history));
			if (info->alias)
			free_list(&(info->alias));
		_ffre(info->environ);
info->environ = NULL;
		   bufree((void **)info->cmd_buf);
		if (info->readfile > 2)
			close(info->readfile);
		_putchar(BUF_FLUSH);
	}
}
