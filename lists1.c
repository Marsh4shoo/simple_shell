#include "shell.h"

/**
 * list_len - Determines The length linked list
 * @p: Pointer To First Node
 *
 * Return: Size Of list
 */
size_t list_len(const list_t *p)
{
	size_t i = 0;

	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - Return Array Of Srings Of list->str
 * @head: Pointer To First Node
 *
 * Return: Array Of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - Print All Element IN list_t linked list
 * @p: Pointer To First Node
 *
 * Return: Size Of list
 */
size_t print_list(const list_t *p)
{
	size_t i = 0;

	while (p)
	{
		_puts(convert_numbers(p->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(p->str ? p->str : "(nil)");
		_puts("\n");
		p = p->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - Returns THE Node String That Starts with Prefix
 * @node: Pointer List Head
 * @prefix: String To Match
 * @c: Next Character After Prefix Match
 *
 * Return: Match Node or Null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *r = NULL;

	while (node)
	{
		r = starts_with(node->str, prefix);
		if (r && ((c == -1) || (*r == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - Get Index A Node
 * @head: Pointer List Head
 * @node: Pointer To The Node
 *
 * Return: index Of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
