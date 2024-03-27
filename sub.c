#include "monty.h"
/**
 * sub -  subtracts the top element of the stack from the second top element of the stack.
 * @stack: linked list of the data as stack
 * @line_number: line number
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;

	stack_t *second;

	if (*stack == NULL || first->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	second = first->next;
	second->n = second->n - first->n;
	second->prev = NULL;
	free(first);
	*stack = second;
}
