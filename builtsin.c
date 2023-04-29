#include "main.h"

/**
 * _mexit - exits shell
 * @info: Structure containing potential arguments

 *  Return: exits with a given exit status
 */
int _mexit(info_t *info)
{
	int exitchk;

	if (info->argv[1])
	{
		exitchk = _errtoi(info->argv[1]);
		if (exitchk == -1)
		{
			info->status = 2;
			print_error(info, "Ilegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _errtoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _owncays 0
 */
int _owncd(info_t *info)
{
	char *s, *directory, buffer[1024];
	int chdir_return;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		directory= _getenv(info, "HOME=");
		if (!directory)
			chdir_return = 
				chdir((directory= _getenv(info, "PWD=")) ? directory: "/");
		else
			chdir_return = chdir(directory);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_return = /* will change this later  */
			chdir((directory= _getenv(info, "OLDPWD=")) ? directory: "/");
	}
	else
		chdir_return = chdir(info->argv[1]);
	if (chdir_return == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _ownhelp - cha
 * @info: Structure containing potential argumentstotype.
 *  Return: Always 0
 */
int _ownhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); 
	return (0);
}
