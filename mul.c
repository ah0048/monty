#include "monty.h"
/**
 * mul -  multiplies the first with second
 * @stack: linked list of the data as stack
 * @line_number: line number
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;

	stack_t *second;

	if (*stack == NULL || first->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	second = first->next;
	second->n = second->n * first->n;
	second->prev = NULL;
	free(first);
	*stack = second;
}
