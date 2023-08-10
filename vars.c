#include "shell.h"

/**
 * is_chain - Test A Chain Delimeter
 * @info: Parameter Struct
 * @buf: Char Buffer
 * @p: Address Of current position in buf
 *
 * Return: 1 If chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t i = *p;

	if (buf[i] == '|' && buf[i + 1] == '|')
	{
		buf[i] = 0;
		i++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[i] == '&' && buf[i + 1] == '&')
	{
		buf[i] = 0;
		i++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[i] == ';') /* found end of this command */
	{
		buf[i] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = i;
	return (1);
}

/**
 * check_chain - Checks When we should Continue chaining based on last status
 * @info: Parameter Struct
 * @buf: Char Buffer
 * @p: Address of current Position in buf
 * @r: Starting Position In buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t r, size_t len)
{
	size_t i = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[r] = 0;
			i = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[r] = 0;
			i = len;
		}
	}

	*p = i;
}

/**
 * replace_alias - Replaces ALL Aliases in the tokenized string
 * @info: Parameter Struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int r;
	list_t *node;
	char *p;

	for (r = 0; r < 10; r++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - Replace Vars in Tokenized string
 * @info: Parameter Struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int r = 0;
	list_t *node;

	for (r = 0; info->argv[r]; r++)
	{
		if (info->argv[r][0] != '$' || !info->argv[r][1])
			continue;

		if (!_strcmp(info->argv[r], "$?"))
		{
			replace_string(&(info->argv[r]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[r], "$$"))
		{
			replace_string(&(info->argv[r]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[r][1], '=');
		if (node)
		{
			replace_string(&(info->argv[r]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[r], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - Replaces string
 * @old: Addres Old string
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
