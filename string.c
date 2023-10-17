#include "shell.h"

/**
 * string_length - Calculate the length of a string.
 * @str: The input string.
 * Return: The length of the string.
 */
int string_length(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * compare_strings - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 * Return: 0 if strings are equal, otherwise the difference.
 */
int compare_strings(char *str1, char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * string_starts_with - Check if a string starts with a given prefix.
 * @str: The string to check.
 * @prefix: The prefix to check for.
 * Return: 1 if it starts with the prefix, 0 otherwise.
 */
char *string_starts_with(const char *str, const char *prefix)
{
	while (*prefix)
	{
		if (*prefix != *str)
			return (NULL);

		prefix++;
		str++;
	}

	return ((char *)str);
}

/**
 * concatenate_strings - Concatenate two strings.
 * @dest: Destination string.
 * @src: Source string to append.
 * Return: Pointer to the concatenated string.
 */
char *concatenate_strings(char *dest, char *src)
{
	int dest_len = string_length(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return (dest);
}

