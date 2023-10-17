#include "shell.h"
#include <stdlib.h>

/**
 * get_list_length - Gets the length of a linked list
 * @head: Pointer to the head of the list
 *
 * Return: The length of the list
 */
size_t get_list_length(const ListNode *head)
{
	size_t count = 0;
	const ListNode *current = head;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}

/**
 * convert_list_to_strings - Converts a linked
 * list of strings to an array of strings
 * @head: Pointer to the head of the list
 *
 * Return: An array of pointers to strings
 */
char **convert_list_to_strings(const ListNode *head)
{
	size_t list_len = get_list_length(head);
	char **strings = malloc((list_len + 1) * sizeof(char *));
	size_t i = 0;
	const ListNode *current = head;

	if (strings == NULL)
		return (NULL);

	while (current != NULL)
	{
		strings[i] = strdup(current->str);
		if (strings[i] == NULL)
		{
			for (i = 0; i < list_len; i++)
				free(strings[i]);
			free(strings);
			return (NULL);
		}

		current = current->next;
		i++;
	}

	strings[i] = NULL;
	return (strings);
}

