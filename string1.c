#include "main.h"

/**
 * _strcpy - cs a string
 * @destination: the destinationination
 * @src: the sourc
 * Return: pointer to destinationination
 */
char *_strcpy(char *destination, char *src)
{
	int x = 0;

	if (destination == src || src == 0)
		return (destination);
	while (src[x])
	{
		destination[x] = src[x];
		x++;
	}
	destination[x] = 0;
	return (destination);
}

/**
 * _strdup - duplicateshe string to duplicate
 *
 * Return: p to the duplicated string
 */
char *_strdup(const char *str)
{
	int lenth = 0;
	char *retu;

	if (str == NULL)
		return (NULL);
	while (*str++)
		lenth++;
	retu = malloc(sizeof(char) * (lenth + 1));
	if (!retu)
		return (NULL);
	for (lenth++; lenth--;)
		retu[lenth] = *--str;
	return (retu);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @The character to print
 *
 * Res returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}
