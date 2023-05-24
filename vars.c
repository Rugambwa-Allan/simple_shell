#include "shell.h"
/**
 * is_chain - test if current character in buffer is chain delimeter
 * @info: parameter struct
 * @buf: char buffer
 * @t: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *t)
{
	size_t m = *t;

	if (buf[m] == '|' && buf[m + 1] == '|')
	{
		buf[m] = 0;
		m++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[m] == '&' && buf[m + 1] == '&')
	{
		buf[m] = 0;
		m++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[m] == ';') /* found end of command */
	{
		buf[m] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*t = m;
	return (1);
}

/**
 * check_chain - check we should continue chaining based on last status
 * @info: parameter struct
 * @buf: char buffer
 * @m: address of current position in buf
 * @o: starting position in buf
 * @top: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *m, size_t o, size_t top)
{
	size_t j = *m;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[o] = 0;
			j = top;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[o] = 0;
			j = top;
		}
	}

	*m = j;
}

/**
 * replace_alias - replace aliases in tokenized string
 * @info: parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int j;
	list_t *node;
	char *m;

	for (j = 0; j < 10; j++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		m = _strchr(node->str, '=');
		if (!m)
			return (0);
		p = _strdup(p + 1);
		if (!m)
			return (0);
		info->argv[0] = m;
	}
	return (1);
}

/**
 * replace_vars - replace vars in tokenized string
 * @info: parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int j = 0;
	list_t *node;

	for (j = 0; info->argv[j]; j++)
	{
		if (info->argv[j][0] != '$' || !info->argv[j][1])
			continue;

		if (!_strcmp(info->argv[j], "$?"))
		{
			replace_string(&(info->argv[j]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[j], "$$"))
		{
			replace_string(&(info->argv[j]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[j][1], '=');
		if (node)
		{
			replace_string(&(info->argv[j]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replace string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
