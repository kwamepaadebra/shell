#include "shell.h"

/**
 * _getenv - Get the value of an environment variable
 * @info: The ArgumentsInfo struct
 * @name: The name of the environment variable
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *_getenv(ArgumentsInfo *info, const char *name)
{
	int i = 0;
	char *env_var;

	if (info->environ == NULL || name == NULL)
		return (NULL);

	while (info->environ[i] != NULL)
	{
		env_var = info->environ[i];
		if (_strncmp(env_var, name, _strlen(name)) == 0)
		{
			env_var = _strchr(env_var, '=');
			if (env_var == NULL)
				return (NULL);
			env_var++;
			return (env_var);
		}
		i++;
	}
	return (NULL);
}

