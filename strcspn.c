#include "main.h"

/**
  * _strcspn - finds the first occurrence of a character in a string
  * @s: string to search
  * @look: character to search for
  *
  * Return: return characters in s that don't appear in look
  */

size_t _strcspn(const char *s, const char *look)
{
	const char *m, *n;

	for (m = s; *m; m++)
	{
		for (n = look; *n; n++)
		{
			if (*m == *n)
				return (m - s);
		}
	}
	return (m - s);
}
