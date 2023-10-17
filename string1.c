#include "shell.h"

/**
 * string_copy - Copy a string to another.
 * @dest: Destination buffer.
 * @src: Source string.
 * Return: Pointer to the destination buffer.
 */
char *string_copy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * string_duplicate - Duplicate a string.
 * @str: Input string to duplicate.
 * Return: Pointer to the new duplicated string.
 */
char *string_duplicate(const char *str)
{
	int len = string_length((char *)str) + 1;
	char *dup_str = (char *)malloc(sizeof(char) * len);

	if (dup_str == NULL)
		return (NULL);

	return (string_copy(dup_str, (char *)str));
}

/**
 * print_string - Print a string to standard output.
 * @str: The string to be printed.
 */
void print_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		print_character(str[i]);
		i++;
	}
}

/**
 * print_character - Print a character to standard output.
 * @c: The character to be printed.
 * Return: 1 on success, -1 on error.
 */
int print_character(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

