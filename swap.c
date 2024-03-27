#include "monty.h"
/**
 * swap - swaps the top two elements of the stack.
 * @stack: linked list of the data as stack
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *first = *stack;

    stack_t *second;

    if (*stack == NULL || first->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    second = first->next;
    first->next = second->next;
    first->prev = second;
    second->next = first;
    second->prev = NULL;
    *stack = second;
}
