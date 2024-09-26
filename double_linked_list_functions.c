#include "monty.h"

/**
 *add_dnodeint_end - function that add a note at the end of the doubly
 *@head: first position
 *@n: data that stores
 *Return: linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *t, *a;

	if (head == NULL)
		return (NULL);
	t = malloc(sizeof(stack_t));
	if (!t)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	t->n = n;

	if (*head == NULL)
	{
		t->next = *head;
		t->prev = NULL;
		*head = t;
		return (*head);
	}
	a = *head;
	while (a->next)
		a = a->next;
	t->next = a->next;
	t->prev = a;
	a->next = t;
	return (a->next);
}

/**
 *add_dnodeint - function that add a note at the begining of link list
 *@head: first position
 *@n: data
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *t;

	if (head == NULL)
		return (NULL);
	t = malloc(sizeof(stack_t));
	if (!t)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	t->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		t->next = *head;
		t->prev = NULL;
		*head = t;
		return (*head);
	}
	(*head)->prev = t;
	t->next = (*head);
	t->prev = NULL;
	*head = t;
	return (*head);
}

/**
 * free_dlistint - function that frees doubly linked list
 *
 * @head: head of the list
 * Return: Zero
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}

