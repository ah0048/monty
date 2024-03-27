#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: linked list of the data as stack
 * @line_number: line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *first = *stack;

    stack_t *second;

    if (*stack == NULL || first->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    second = first->next;
    second->n = first->n + second->n;
    second->prev = NULL;
    free(first);
    *stack = second;
}
