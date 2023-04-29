#include "main.h"

/**
 * _memoset - file memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the const byte
 * @n: the byte in *s
 *
 * Return: (s) to the memory area *s
 */
char *_memoset(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = b;
	return (s);
}

/**
 * _ffre - frees a string of strings
 * @pp: string of strings
 */
void _ffre(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous mallocated block
 * @old_size: size of previously allocated space
 * @new_size: new size to allocate
 *
 * Return: pointer to the old block name.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *m;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	m = malloc(new_size);
	if (!m)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		m[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (m);
}
