#include "main.h"

/**
 * strtow - splits a strings into tokens. Repeat dare ignored
 * @str: string
 * @d: the delimeter string
 *
 * Return: s or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int x, g, h, f, words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) ||
					!str[x + 1]))
			words++;

	if (words == 0)
		return (NULL);
	s = malloc((1 + words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, g = 0; g < words; g++)
	{
		while (is_delim(str[x], d))
			x++;
		h = 0;
		while (!is_delim(str[x + h], d) && str[x + h])
			h++;
		s[g] = malloc((h + 1) * sizeof(char));
		if (!s[g])
		{
			for (h = 0; h < g; h++)
				free(s[h]);
			free(s);
			return (NULL);
		}
		for (f = 0; f < h; f++)
			s[g][f] = str[x++];
		s[g][f] = 0;
	}
	s[g] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: string
 * @d: the deln array of strings, or NULL on failure
 *
 * Return: split string
 */
char **strtow2(char *str, char d)
{
	int x, g, h, f, words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
		    (str[x] != d && !str[x + 1]) || str[x + 1] == d)
			words++;
	if (words == 0)
		return (NULL);
	s = malloc((1 + words) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, g = 0; g < words; g++)
	{
		while (str[x] == d && str[x] != d)
			x++;
		h = 0;
		while (str[x + h] != d && str[x + h] && str[x + h] != d)
			h++;
		s[g] = malloc((h + 1) * sizeof(char));
		if (!s[g])
		{
			for (h = 0; h < g; h++)
				free(s[h]);
			free(s);
			return (NULL);
		}
		for (f = 0; f < h; f++)
			s[g][f] = str[x++];
		s[g][f] = 0;
	}
	s[g] = NULL;
	return (s);
}
