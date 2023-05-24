#include "shell.h"

/**
 * _memset - fill memory with constant byte
 * @h: pointer memory area
 * @a: byte to fill *h with
 * @m: Amount of bytes to be filled
 * Return: (h) pointer to the memory area h
 */
char *_memset(char *h, char a, unsigned int m)
{
	unsigned int j;

	for (j = 0; j < m; j++)
		h[j] = a;
	return (h);
}

/**
 * ffree - free string of strings
 * @fe: string of strings
 */
void ffree(char **fe)
{
	char **v = fe;

	if (!fe)
		return;
	while (*fe)
		free(*fe++);
	free(v);
}

/**
 * _realloc - reallocate block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *l;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	l = malloc(new_size);
	if (!l)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (l);
}
