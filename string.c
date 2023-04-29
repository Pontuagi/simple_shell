#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *er length of string
 */
int _strlen(char *s)
{
	int x = 0;

	if (!s)
		return (0);

	while (*s++)
		x++;
	return (x);
}

/**
 * _strcm
 * Retur positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if need starts with hstack
 * @hayst search
 * @need:
 * Return: addrof next char of hstack or NULL
 */
char *starts_with(const char *hstack, const char *need)
{
	while (*need)
		if (*need++ != *hstack++)
			return (NULL);
	return ((char *)hstack);
}

/**
 * _strcat - concatenon: the destinationination buffer
 * @src: the
 *
 * Return: po to destinationination buffer
 */
char *_strcat(char *destination, char *src)
{
	char *retu = destination;

	while (*destination)
		destination++;
	while (*src)
		*destination++ = *src++;
	*destination = *src;
	return (retu);
}
