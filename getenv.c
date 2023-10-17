#include "shell.h"

/**
 * _getenv - Get the value of an environment variable
 * @info: Pointer to ArgumentsInfo structure
 * @name: Name of the environment variable
 * Return: Value of the environment variable, or NULL if not found
 */
char *_getenv(ArgumentsInfo *info, const char *name)
{
	char *env_name, *value;
	int i, len;

	if (info == NULL || name == NULL || info->environ == NULL)
		return (NULL);

	len = strlen(name);
	for (i = 0; info->environ[i] != NULL; i++)
	{
		env_name = info->environ[i];
		if (strncmp(env_name, name, len) == 0 && env_name[len] == '=')
		{
			value = env_name + len + 1;
			return (value);
		}
	}

	return (NULL);
}
