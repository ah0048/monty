#include "monty.h"
/**
 * mod -  computes the rest of the division of the second by first
 * @stack: linked list of the data as stack
 * @line_number: line number
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;

	stack_t *second;

	if (*stack == NULL || first->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
    if (first->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }
	second = first->next;
	second->n = second->n % first->n;
	second->prev = NULL;
	free(first);
	*stack = second;
}
