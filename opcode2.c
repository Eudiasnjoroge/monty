#include "monty.h"

/**
 * _mod - function that computes the rest of the division
 *
 * @doubly: head of linked list
 * @cline: line no
 * Return: zero
 * info:The result is stored in 2nd value node
 *
 */

void _mod(stack_t **doubly, unsigned int cline)
{
	int x = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, x++)
		;

	if (x < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	_pop(doubly, cline);
}
/**
 * _pstr - funtion that prints the string of the stack
 *
 * @doubly: head of the linked list
 * @cline: line no.
 * Return: zero
 */
void _pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *a;
	(void)cline;

	a = *doubly;

	while (a && a->n > 0 && a->n < 128)
	{
		printf("%c", a->n);
		a = a->next;
	}

	printf("\n");
}
/**
 * _pchar - function that print the char value
 *
 * @doubly: head of linked list
 * @cline: line no
 * Return: zero
 */
void _pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

