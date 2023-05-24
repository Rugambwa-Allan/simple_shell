#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - check if character is delimeter
 * @b: character to check
 * @delim: Delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char b, char *delim)
{
	while (*delim)
		if (*delim++ == b)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @b: Character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int b)
{
	if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - convert string to an integer
 * @s: String to be converted
 * Return: 0 if no numbers in the  string, converted number otherwise
 */

int _atoi(char *s)
{
	int y, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (y = 0; s[y] != '\0' && flag != 2; i++)
	{
		if (s[y] == '-')
			sign *= -1;

		if (s[y] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[y] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
