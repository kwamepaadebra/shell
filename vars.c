#include "shell.h"

/**
 * replace_variables_in_command - Replaces variables in a command
 * @info: The ArgumentsInfo structure
 * @command: The command to replace variables in
 *
 * Return: The command with replaced variables
 */
int replace_variables_in_command(info_t *info, char **command)
{
/* Replace variables logic here */
/* You may use info->env or to replace variables in the command */
/* Example: Replace "$HOME" with the actual home directory */

/* Example code for demonstration */
if (command && *command)
{
if (strcmp(*command, "$HOME") == 0)
{
char *home_dir = _getenv(info, "HOME");
if (home_dir)
{
free(*command);
*command = _strdup(home_dir);
free(home_dir);
}
}
}

return (0);
}

