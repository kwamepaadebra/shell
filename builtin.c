#include "shell.h"

/**
 * _myexit - Exit the shell
 * @info: Pointer to the arguments and info struct
 *
 * Return: Always returns 0 to exit the shell
 */
int _myexit(ArgumentsInfo *info)
{
	free_arguments_info(info, 0);
	free_buffer((void **)&info->cmd_buf);
	free_list_of_nodes(&info->env);
	free_list_of_nodes(&info->history);
	free_list_of_nodes(&info->alias);

	exit(0);
}

/**
 * _mycd - Change the current working directory
 * @info: Pointer to the arguments and info struct
 *
 * Return: Always returns 0 on success
 */
int _mycd(ArgumentsInfo *info)
{
	char *new_dir;

	if (info->argc < 2 || info->argv[1] == NULL)
		new_dir = _get_environment_variable(info, "HOME");
	else if (_strcmp(info->argv[1], "-") == 0)
		new_dir = _get_environment_variable(info, "OLDPWD");
	else
		new_dir = info->argv[1];

	if (new_dir == NULL)
	{
		print_error_message("cd: HOME not set\n");
		return (1);
	}

	if (chdir(new_dir) == -1)
	{
		perror("cd");
		return (1);
	}

	return (0);
}

/**
 * _myhelp - Display help for built-in commands
 * @info: Pointer to the arguments and info struct
 *
 * Return: Always returns 0
 */
int _myhelp(ArgumentsInfo *info)
{
	(void)info;
	printf("Custom Shell - Built-in commands:\n");
	printf("cd [DIRECTORY] - Change the current working directory\n");
	printf("exit - Exit the shell\n");
	printf("env - Display the current environment\n");
	return (0);
}
