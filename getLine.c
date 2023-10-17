#include "shell.h"

/**
 * get_input - Read input from the user and store it in a buffer
 * @info: The ArgumentsInfo struct
 *
 * Return: The number of characters read.
 */
ssize_t get_input(ArgumentsInfo *info)
{
	ssize_t n;
	size_t size = READ_BUFFER_SIZE;

	info->arg = NULL;
	info->argc = 0;
	info->line_count = 0;

	n = _getline(info, &(info->arg), &size);
	if (n == -1)
	{
		if (info->arg)
			free(info->arg);
		return (n);
	}

	info->arg[n] = '\0';

	return (n);
}

/**
 * _getline - Custom getline function
 * @info: The ArgumentsInfo struct
 * @buf: The buffer to store the input
 * @size: The size of the buffer
 *
 * Return: The number of characters read.
 */
int _getline(ArgumentsInfo *info, char **buf, size_t *size)
{
	int n;
	char *line = NULL;

	n = read(STDIN_FILENO, line, *size);

	if (n == -1)
	{
		free(line);
		return (-1);
	}
	else if (n == 0)
	{
		free(line);
		return (-1);
	}

	if (line[n - 1] == '\n')
		line[n - 1] = '\0';

	*buf = line;
	return (n);
}

