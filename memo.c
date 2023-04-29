#include "main.h"

/**
 * bufree - frees a pointer and NULLs the address
 * @ptr: address
 *
 * Return: return 1 if true otherwise 0.
 */
int bufree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
