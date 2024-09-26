#include "monty.h"

/**
 * _add - function Adds the top two values of a stack_t linked
 * @doubly: head of linked list
 * @cline: line no
 * Description: result is stored in the second value node
 *
 */
void _add(stack_t **doubly, unsigned int cline)
{
	int d = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, d++)
		;

	if (d < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - function stack_t linked list by top value
 * @doubly: linked list head
 * @cline: line number
 */
void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}
/**
 * _sub - function that ubtracts 2nd value from the top of stack_t linked list
 * @head: the head node
 * @cline: the line no
 * Description: The result is stored in the second value node
 *
 */

void _sub(stack_t **head, unsigned int cline)
{
	int d = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, d++)
		;

	if (d < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n -= (*head)->n;
	_pop(head, cline);
}

/**
 *_div -function that Divides 2nd value from the top of stack_t linkedlist
 * @doubly: head of the linked list
 * @cline: line number
 * Return: zero
 */

void _div(stack_t **doubly, unsigned int cline)
{
	int k = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline);
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
	aux->n /= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 *_mul -funtion that Multiplies 2nd value from the top of stack_t linked list
 * @head: the head node
 * @cline: the line number
 * info:The result is stored in the 2nd value node
 *
 */

void _mul(stack_t **head, unsigned int cline)
{
	int k = 0;
	stack_t *current;

	current = *head;

	for (; current != NULL; current = current->next, k++)
		;

	if (k < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	current = (*head)->next;
	current->n *= (*head)->n;
	_pop(head, cline);
}



