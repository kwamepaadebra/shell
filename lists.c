#include "shell.h"
#include <stdio.h>

/**
 * add_node_to_list - Adds a new node at the beginning of a list
 * @head: Pointer to the head of the list
 * @str: The string to add to the list
 * @num: The number associated with the string
 *
 * Return: The address of the new node, or NULL on failure
 */
ListNode *add_node_to_list(ListNode **head, const char *str, int num)
{
	if (head == NULL)
		return (NULL);

	ListNode *new_node = malloc(sizeof(ListNode));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->num = num;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

