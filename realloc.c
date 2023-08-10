#include "shell.h"

/**
 * _memset - Fill ALL Memory With Constant byte
 * @s: Pointer Memory areas
 * @b: Byte Fill *s With
 * @n: Amount Bbytes that Will be filled
 * Return: (s) A pointer OF the Memory Areas
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - FREES STRING Of strings
 * @pp: String Of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - Reallocate Block Of MEMORY
 * @ptr: Pointer Previous malloc'ated BLOCK
 * @old_size: BYTE Size Previous Block
 * @new_size: Byte SIZE NEW Block
 *
 * Return: Pointer TO OL'block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
