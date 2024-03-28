#include "monty.h"
/**
 * execute - executes the passed command
 * @opcode: string of the required command
 * @stack: linked list of the data as stack
 * @line_number: line number
 * Return: void
 */
void execute(char *opcode, stack_t **stack, unsigned int line_number)
{
	unsigned long int i = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", stack_div},
		{"mul", mul},
		{"mod", mod},
		{"#", comment},
		{"pchar", pchar},
	};

	for (i = 0; i < sizeof(instructions) / sizeof(instruction_t); i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
