#include "shell.h"
#include <stdlib.h>

/**
 * tokenize_string - Tokenizes a string based on a delimiter
 * @str: The string to tokenize
 * @delimiter: The delimiter to use for tokenization
 *
 * Return: An array of pointers to tokens
 */
char **tokenize_string(char *str, char *delimiter)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;

	if (str == NULL || delimiter == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	token = strtok(str, delimiter);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		tokens = realloc(tokens, (i + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			free(tokens);
			return (NULL);
		}

		token = strtok(NULL, delimiter);
	}

	tokens[i] = NULL;
	return (tokens);
}

