#include "shell.h"

/**
 * exit_shell - Handles the exit command.
 * @info: The ArgumentsInfo structure.
 *
 * Return: Always returns -1 to exit the shell.
 */
int exit_shell(ArgumentsInfo *info)
{
	free_arguments_info(info, 1);
	exit(0);
}
