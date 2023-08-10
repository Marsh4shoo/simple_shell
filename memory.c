#include "shell.h"

/**
 * bfree - Frees Pointer Which NULLs the address
 * @ptr: Addresses of pointer to free
 *
 * Return: 1 IF freed, Eitherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
