#include "shell.h"

/**
 * _eputs - print an input string
 * @str: String to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int y = 0;

	if (!str)
		return;
	while (str[y] != '\0')
	{
		_eputchar(str[y]);
		y++;
	}
}

/**
 * _eputchar - write the character c to stderr
 * @b: char to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char b)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		y = 0;
	}
	if (b != BUF_FLUSH)
		buf[y++] = b;
	return (1);
}

/**
 * _putrt- write character b to given rt
 * @b: char to print
 * @rt: Filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putrt(char b, int rt)
{
	static int y;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(rt, buf, y);
		y = 0;
	}
	if (b != BUF_FLUSH)
		buf[y++] = b;
	return (1);
}

/**
 * _putsrt- print input string
 * @str: String to be printed
 * @rt: filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsrt(char *str, int rt)
{
	int y = 0;

	if (!str)
		return (0);
	while (*str)
	{
		y += _putrt(*str++, rrt);
	}
	return (y);
}
