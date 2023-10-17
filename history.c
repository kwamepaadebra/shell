#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * get_history_file_path - Get the path to the history file.
 * @info: Pointer to the ArgumentsInfo structure.
 *
 * Return: Pointer to the history file path or NULL on failure.
 */
char *get_history_file_path(ArgumentsInfo *info)
{
	char *home_path;
	char *history_file_path;
	size_t path_length;

	home_path = _getenv(info, "HOME");
	if (home_path == NULL)
		return (NULL);

	path_length = strlen(home_path) + strlen(HIST_FILE) + 2;
	history_file_path = malloc(path_length);
	if (history_file_path == NULL)
		return (NULL);

	snprintf(history_file_path, path_length, "%s/%s", home_path, HIST_FILE);
	return (history_file_path);
}

/**
 * write_history_to_file - Write the history to a file.
 * @info: Pointer to the ArgumentsInfo structure.
 *
 * Return: 0 on success, -1 on failure.
 */
int write_history_to_file(ArgumentsInfo *info)
{
	FILE *file;
	char *history_file_path;
	ListNode *current;
	int linecount;

	history_file_path = get_history_file_path(info);
	if (history_file_path == NULL)
		return (-1);

	file = fopen(history_file_path, "w");
	free(history_file_path);

	if (file == NULL)
		return (-1);

	current = info->history;
	linecount = 0;
	while (current != NULL)
	{
		fprintf(file, "%d %s\n", current->num, current->str);
		current = current->next;
		linecount++;
	}

	fclose(file);
	renumber_history_list(info);

	return (linecount);
}

