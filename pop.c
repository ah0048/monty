#include "monty.h"
/**
 * pop - removes the top element of the stack.
 * @stack: linked list of the data as stack
 * @line_number: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    if (current->next)
        current->next->prev = NULL;
    *stack = current->next;
    free(current);
}
