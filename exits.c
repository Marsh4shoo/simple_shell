#include "shell.h"

/**
 **_strncpy - Copies A String
 *@dest: Destination String to be copied to
 *@src: Source string
 *@n: Amount Of characters to be copied
 *Return: CDoncatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int l, j;
	char *s = dest;

	l = 0;
	while (src[l] != '\0' && l < n - 1)
	{
		dest[l] = src[l];
		l++;
	}
	if (l < n)
	{
		j = l;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - Concatenates two strings
 *@dest: First string
 *@src: Second string
 *@n: Amount of bytes to be maximally used
 *Return: Concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int l, j;
	char *s = dest;

	l = 0;
	j = 0;
	while (dest[l] != '\0')
		l++;
	while (src[j] != '\0' && j < n)
	{
		dest[l] = src[j];
		l++;
		j++;
	}
	if (j < n)
		dest[l] = '\0';
	return (s);
}

/**
 **_strchr - locate Character in a string
 *@s: String To Be parsed
 *@c: Character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
