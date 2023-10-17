#include "shell.h"

/**
 * _eputs - Prints a string to standard error.
 * @str: The string to print.
 */
void _eputs(char *str)
{
	while (*str)
	{
		_eputchar(*str);
		str++;
	}
}

/**
 * _eputchar - Prints a character to standard error.
 * @c: The character to print.
 *
 * Return: 1 on success, -1 on failure.
 */
int _eputchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * _putfd - Writes a character to a file descriptor.
 * @c: The character to write.
 * @fd: The file descriptor.
 *
 * Return: 1 on success, -1 on failure.
 */
int _putfd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/**
 * _putsfd - Writes a string to a file descriptor.
 * @str: The string to write.
 * @fd: The file descriptor.
 *
 * Return: The number of characters written, excluding null byte.
 */
int _putsfd(char *str, int fd)
{
	int len = 0;

	while (str && *str)
	{
		if (_putfd(*str, fd) == -1)
			return (-1);
		str++;
		len++;
	}
	return (len);
}

