#include "shell.h"

/**
 **_strncpy - copy string
 *@dest: Destination string to be copied to
 *@src: Source string
 *@m: Amount of char to be copied
 *Return: Concatenated string
 */
char *_strncpy(char *dest, char *src, int m)
{
	int n, k;
	char *s = dest;

	n = 0;
	while (src[n] != '\0' && n < m - 1)
	{
		dest[n] = src[n];
		n++;
	}
	if (n < m)
	{
		k = n;
		while (k < m)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 **_strncat - Concatenates two strings
 *@dest: First string
 *@src: Second string
 *@m: Amount of bytes to be maximally used
 *Return: Concatenated string
 */
char *_strncat(char *dest, char *src, int m)
{
	int n, k;
	char *s = dest;

	n = 0;
	k = 0;
	while (dest[n] != '\0')
		n++;
	while (src[k] != '\0' && k < m)
	{
		dest[n] = src[k];
		n++;
		k++;
	}
	if (k < m)
		dest[n] = '\0';
	return (s);
}

/**
 **_strchr - locate char in a string
 *@s: String to be parsed
 *@b: Char to look for
 *Return: (s) pointer to the memory area s
 */
char *_strchr(char *s, char b)
{
	do {
		if (*s == b)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
