#include "shell.h"

/**
 * list_len - Determine length of linked list
 * @h: pointer first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t j = 0;

	while (h)
	{
		h = h->next;
		j++;
	}
	return (j);
}

/**
 * list_to_strings - return array of strings of the list->str
 * @head: pointer first node
 *
 * Return: array of string
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t j = list_len(head), k;
	char **strs;
	char *str;

	if (!head || !j)
		return (NULL);
	strs = malloc(sizeof(char *) * (j + 1));
	if (!strs)
		return (NULL);
	for (j = 0; node; node = node->next, j++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (k = 0; k < j; k++)
				free(strs[k]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[j] = str;
	}
	strs[j] = NULL;
	return (strs);
}


/**
 * print_list - print all elements of a list_t linked list
 * @h: pointer first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t j = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		j++;
	}
	return (j);
}

/**
 * node_starts_with - return node whose string starts with prefix
 * @node: pointer list head
 * @prefix: string to match
 * @b: Next character after prefix to match
 *
 * Return: Match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char b)
{
	char *o = NULL;

	while (node)
	{
		o = starts_with(node->str, prefix);
		if (o && ((b == -1) || (*o == b)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - get index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t j = 0;

	while (head)
	{
		if (head == node)
			return (j);
		head = head->next;
		j++;
	}
	return (-1);
}
