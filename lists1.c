#include "shell.h"

/**
 * list_len - Determines The length linked list
 * @p: Pointer To First Node
 *
 * Return: Size Of list
 */
size_t list_len(const list_tt *p)
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
char **list_to_strings(list_tt *head)
{
	list_tt *node = head;
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
 * print_list - Print All elements in A list_tt linked list
 * @p: Pointer To First Node
 *
 * Return: Size Of list
 */
size_t print_list(const list_tt *p)
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
 * node_starts_with - Returns the Node with string That starts with prefix
 * @node: Pointer List head
 * @prefix: String To match
 * @c: Next Character After prefix to match
 *
 * Return: Match Node or null
 */
list_tt *node_starts_with(list_tt *node, char *prefix, char c)
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
 * get_node_index - Get index Of A node
 * @head: Pointer List head
 * @node: Pointer To The node
 *
 * Return: index Of node or -1
 */
ssize_t get_node_index(list_tt *head, list_tt *node)
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
