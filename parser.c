#include "shell.h"

/**
 * is_cmd - Check if a word is a command
 * @info: Pointer to info_t structure
 * @word: Word to check
 *
 * Return: 1 if word is a command, 0 otherwise
 */
int is_cmd(info_t *info, char *word)
{
    /* Assuming any non-built-in command is executable */
    return (access(word, X_OK) == 0);
}

/**
 * dup_chars - Duplicate a portion of a string
 * @src: Source string
 * @start: Start index
 * @end: End index
 *
 * Return: Duplicated string
 */
char *dup_chars(char *src, int start, int end)
{
    int length = end - start + 1;
    char *duplicate = malloc(length + 1);

    if (duplicate == NULL)
        return (NULL);

    int i;
    for (i = start; i <= end; i++)
        duplicate[i - start] = src[i];

    duplicate[length] = '\0';
    return (duplicate);
}

/**
 * find_path - Find the full path of a command
 * @info: Pointer to info_t structure
 * @cmd: Command to find
 *
 * Return: Full path of the command if found, NULL otherwise
 */
char *find_path(info_t *info, char *cmd)
{
    char *path = _getenv(info, "PATH");
    if (path == NULL)
        return (NULL);

    char *token = strtok(path, ":");
    while (token != NULL)
    {
        char *full_path = malloc(strlen(token) + strlen(cmd) + 2); /* 1 for '/' and 1 for '\0' */
        if (full_path == NULL)
            return (NULL);

        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, cmd);

        if (access(full_path, F_OK) == 0)
            return (full_path);

        free(full_path);
        token = strtok(NULL, ":");
    }

    return (NULL);
}

