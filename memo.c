#include "main.h"

/**
 * bufree - frees a pointer and NULLs the address
 r: address otherwise 0.
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
