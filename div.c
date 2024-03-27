#include "monty.h"
/**
 * stack_div -  divides the second top element of the stack by the top element of the stack.
 * @stack: linked list of the data as stack
 * @line_number: line number
 * Return: void
 */
void stack_div(stack_t **stack, unsigned int line_number)
{
	stack_t *first = *stack;

	stack_t *second;

	if (*stack == NULL || first->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
    if (first->n == 0)
    {
        fprintf(stderr, "L%d: division by zero", line_number);
        exit(EXIT_FAILURE);
    }
	second = first->next;
	second->n = second->n - first->n;
	second->prev = NULL;
	free(first);
	*stack = second;
}
