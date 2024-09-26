
#include "monty.h"
/**
 * _push - function that pushes an element to the stack
 *
 * @doubly: head of linked list
 * @cline: line no
 * Return: zero
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int x, j;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	x = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(doubly, x);
	else
		add_dnodeint_end(doubly, x);
}

/**
 * _pall - function that prints all values on the stack
 *
 * @doubly: head of linked list
 * @cline: line no
 * Return: zero
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}


/**
 * _pint - function that  prints the value at the top of the stack
 *
 * @doubly: head of linked list
 * @cline: line no
 * Return: zero
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * _pop - funtion that removes the top element of the stack
 *
 * @doubly: head of linked list
 * @cline: line no
 * Return: zero
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}


/**
 * _swap - funtion that swaps the top two elements of the stack
 *
 * @doubly: head of linked list
 * @cline: line no
 * Return:zero
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	int d = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, d++)
		;

	if (d < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}

