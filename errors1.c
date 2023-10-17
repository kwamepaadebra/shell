#include "shell.h"

/**
 * _erratoi - Converts an error string to an integer.
 * @str: The error string to convert.
 *
 * Return: The converted integer.
 */
int _erratoi(char *str)
{
	return (atoi(str));
}

/**
 * print_error - Prints an error message.
 * @info: The ArgumentsInfo structure.
 * @message: The error message to print.
 */
void print_error(ArgumentsInfo *info, char *message)
{
	_putsfd(info->fname, STDERR_FILENO);
	_putsfd(": ", STDERR_FILENO);
	_putsfd(message, STDERR_FILENO);
	_putsfd("\n", STDERR_FILENO);
}

/**
 * print_digits - Prints digits recursively.
 * @n: The number to print.
 * @fd: The file descriptor to print to.
 *
 * Return: The number of characters printed.
 */
static int print_digits(int n, int fd)
{
	if (n / 10)
		return (print_digits(n / 10, fd) + _putfd((n % 10) + '0', fd));
	return (_putfd((n % 10) + '0', fd));
}

/**
 * convert_number - Converts a number to a string.
 * @n: The number to convert.
 * @convert_lowercase: Whether to convert to lowercase.
 * @convert_unsigned: Whether to convert to unsigned.
 *
 * Return: The converted string.
 */
char *convert_number(long int n, int convert_lowercase, int convert_unsigned)
{
	static char buffer[21]; /* Maximum 64-bit integer has 20 digits */
	char *ptr = &buffer[20]; /* Points to the end of buffer */
	int negative = 0;

	*ptr = '\0';

	if (n < 0)
	{
		negative = 1;
		n = -n;
	}

	if (convert_unsigned)
	{
		do
		{
			*--ptr = (n % 10) + '0';
			n /= 10;
		} while (n != 0);
	}
	else
	{
		do
		{
			*--ptr = (n % 10) + '0';
			n /= 10;
		} while (n != 0);
	}

	if (negative)
		*--ptr = '-';
	if (convert_lowercase)
	{
		while (*ptr)
		{
			if (*ptr >= 'A' && *ptr <= 'Z')
				*ptr += 32; /* Convert to lowercase */
			ptr++;
		}
	}

	return (ptr);
}

/**
 * remove_comments - Removes comments from a string.
 * @str: The input string.
 */
void remove_comments(char *str)
{
	char *ptr = str;

	while (*ptr)
	{
		if (*ptr == '#')
		{
			*ptr = '\0';
			return;
		}
		ptr++;
	}
}

