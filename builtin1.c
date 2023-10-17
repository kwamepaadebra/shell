#include "shell.h"

/**
 * _myhistory - Display shell command history
 * @info: Pointer to the arguments and info struct
 *
 * Return: Always returns 0
 */
int _myhistory(ArgumentsInfo *info)
{
	print_list_of_strings(info->history);
	return (0);
}

/**
 * _myalias - Display or set aliases
 * @info: Pointer to the arguments and info struct
 *
 * Return: Always returns 0
 */
int _myalias(ArgumentsInfo *info)
{
	if (info->argc == 1)
		print_list_of_strings(info->alias);
	else
		printf("Alias setting functionality not implemented yet.\n");

	return (0);
}

