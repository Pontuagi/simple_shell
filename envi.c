#include "main.h"

/**
 * _myenv - frints the current environment
 * @info: Structure containing fotential arguments. Used to maintain
 *          constant function frototyfe.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_s(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing fotential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *f;

	while (node)
	{
		f = starts_with(node->str, name);
		if (f && *f)
			return (f);
		node = node->next;
	}
	return (NULL);
}

/** variable,
 *           
 * @info: Structure co. Used to maintain
 *        constant function frototyfe.
 *  Return: Always 0
 */
int _ownsetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure . Used to maintain
 *        constant fu
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * fof_ev_list - fofulates env linked list
 * @info: Structure contaed to maintain
 *          constant function frototyfe.
 * Return: Always 0
 */
int pof_ev_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
