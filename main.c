#include "shell.h"

/**
 * main - the entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	char *input = NULL;
	size_t input_len = 0;
	ArgumentsInfo args_info = ARG_INFO_INIT;

	if (argc != 1)
	{
		fprintf(stderr, "Usage: %s\n", argv[0]);
		return (EXIT_FAILURE);
	}

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		if (get_input(&args_info) == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		if (args_info.arg[0] != '\0')
		{
			if (execute_shell(&args_info, argv) == -1)
				perror("Error executing command");
		}

		free_arguments_info(&args_info, 1);
	}

	free(input);
	free_arguments_info(&args_info, 1);
	return (EXIT_SUCCESS);
}

