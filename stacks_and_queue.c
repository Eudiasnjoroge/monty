#include "monty.h"

/**
 * _queue - function sets format of data
 * @doubly: head of linked list
 * @cline: line no
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * _stack - function  sets format of data
 * @doubly: linked list
 * @cline: line no
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}
