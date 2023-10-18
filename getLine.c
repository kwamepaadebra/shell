#include "shell.h"

/**
 * custom_getline - Custom getline function to read input from the user.
 *                  Uses a buffer to minimize the read system call.
 *
 * Return: A pointer to the line read, NULL on failure or end of input.
 */
char *custom_getline(void)
{
	static char buffer[READ_BUF_SIZE];
	static int buffer_index;
	int i = 0;
	char *line = NULL;
	int c;

	/* Initialize buffer_index to 0 if it's uninitialized */
	if (!buffer_index)
		buffer_index = 0;

	while (1)
	{
		/* If buffer is empty, read into the buffer */
		if (buffer_index == 0)
		{
			buffer_index = read(STDIN_FILENO, buffer, READ_BUF_SIZE);
			if (buffer_index <= 0)
				return (NULL);  /* Error or end of input */
		}

		c = buffer[buffer_index - 1];
		buffer_index--;

		if (c == '\n')
		{
			buffer[i] = '\0';
			line = strdup(buffer);  /* Allocate memory for the line and copy */
			if (line == NULL)
				perror("Error: Unable to allocate memory");
			return (line);
		}

		buffer[i] = c;
		i++;

		/* If buffer is empty, reset i and read again */
		if (buffer_index == 0)
			i = 0;
	}

	return (NULL);
}

