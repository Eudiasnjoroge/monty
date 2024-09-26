#include "monty.h"

/**
 * get_opcodes - function that selects the correct opcode to perform
 *
 * @opc: opcode
 *
 * Return: pointer to the function
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	int x;

	for (x = 0; instruct[x].opcode; x++)
	{
		if (_strcmp(instruct[x].opcode, opc) == 0)
			break;
	}

	return (instruct[x].f);
}
