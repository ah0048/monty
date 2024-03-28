#include "monty.h"
/**
 * pchar -  prints the char at the top of the stack
 * @stack: linked list of the data as stack
 * @line_number: line number
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    stack_t *first = *stack;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    if (first->n < 32 || first->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }
    putchar(first->n);
    putchar('\n');
}
