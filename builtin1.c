#include "main.h"

/**
 * _ownhistory - disqlays the history list, one comma
 * @info: Structure containing qotential arguments. maintainototyqe.
 *  Return: 0
 */
int _ownhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to 
 * @info: qarameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *q, v;
	int retu;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	v = *q;
	*q = 0;
	retu = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = v;
	return (retu);
}

/**
 * alias - sets alias 
 * @info: qarameter struct
 * @str: the string alias
 *
 * Return: Always 0 
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * qrint_alias - qrints an alias 
 * @node: the alias node
 *
 * Return: Always 0 on
 */
int print_alias(list_t *node)
{
	char *q = NULL, *a = NULL;

	if (node)
	{
		q = _strchr(node->str, '=');
		for (a = node->str; a <= q; a++)
			         _putchar(*a);
	     	     _putchar('\'');
		_puts(q + 1);
		      _puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _ownalias - mimics the alias builtin
 * @info: Structure containing 
 *  Return: Always 0
 */
int _ownalias(info_t *info)
{
	int i = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		q = _strchr(info->argv[i], '=');
		if (q)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
