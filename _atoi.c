#include "shell.h"

/**
 * is_numeric_character - Check if a character is numeric.
 * @c: The character to check.
 * @allowed_chars: Additional allowed characters (e.g., "-").
 *
 * Return: 1 if numeric, 0 otherwise.
 */
int is_numeric_character(char c, char *allowed_chars)
{
	int i;

	if (c == '\0')
		return (0);

	if (c == '-' && allowed_chars != NULL)
		return (1);

	for (i = 0; allowed_chars && allowed_chars[i]; i++)
	{
		if (c == allowed_chars[i])
			return (1);
	}

	return (c >= '0' && c <= '9');
}

/**
 * _atoi - Convert a string to an integer.
 * @str: The string to convert.
 *
 * Return: The converted integer.
 */
int _atoi(char *str)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	if (str == NULL)
		return (0);

	while (str[i] != '\0' && (!is_numeric_character(str[i], NULL)))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

	while (str[i] != '\0' && is_numeric_character(str[i], NULL))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}

	return (result * sign);
}

