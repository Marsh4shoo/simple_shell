#include "shell.h"

/**
 * interactive - Return true if Shell is IN interactive mode
 * @info: Struct Address
 *
 * Return: 1 If Interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Check character is a Delimeter
 * @d: Char To Check
 * @delim: Delimeter String
 * Return: 1 If True, 0 if False
 */
int is_delim(char d, char *delim)
{
	while (*delim)
		if (*delim++ == d)
			return (1);
	return (0);
}

/**
 * _isalpha - Check Alphabetic characters
 * @d: Character To Input
 * Return: 1 If d is Alphabetic, 0 otherwise
 */

int _isalpha(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Convert A string an integer
 * @s: String To be converted
 * Return: 0 if No number in string, converted nmber Eitherwise
 */

int _atoi(char *s)
{
	int i, signChar = 1, flag = 0, output;
	unsigned int results = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			signChar *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			results *= 10;
			results += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (signChar == -1)
		output = -results;
	else
		output = results;

	return (output);
}
