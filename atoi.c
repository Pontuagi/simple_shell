#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */

int _atoi(char *s)
{
	int sign = 1, n = 0, digit;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			sign = -1;
		}
		else if (*s >= '0' && *s <= '9')
		{
			digit = *s - '0';
			if (n > (INT_MAX - digit) / 10)
			{
				return (0);
			}
			n = n * 10 + digit;
		}
		else if (n > 0)
		{
			break;
		}
		s++;
	}
	return (n * sign);
}
