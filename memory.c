#include "shell.h"

/**
 * reallocate_memory - Reallocate memory for a buffer.
 * @ptr: Pointer to the previously
 * allocated memory.
 * @old_size: Previous size of the memory.
 * @new_size: New size of the memory.
 *
 * Return: Pointer to the reallocated memory.
 */
void *reallocate_memory(void *ptr, unsigned int old_size,
unsigned int new_size)
{
	char *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (new_ptr);

	if (new_size <= old_size)
		old_size = new_size;

	while (old_size--)
		new_ptr[old_size] = ((char *)ptr)[old_size];

	free(ptr);
	return (new_ptr);
}

/**
 * free_buffer - Free a buffer.
 * @buffer: Pointer to the buffer to free.
 *
 * Return: 1 on success, 0 on failure.
 */
int free_buffer(void **buffer)
{
	if (buffer != NULL)
	{
		free(*buffer);
		*buffer = NULL;
		return (1);
	}
	return (0);
}

