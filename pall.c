#include "main.h"
/**
 * pall - print all the stack starting from top
 * @stack: linked list of the data as stack
 * @line_number: line number
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (current)
	while (current->next)
		current = current->next;
	while (current)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->prev;
	}
}
