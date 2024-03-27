#include "main.h"
/**
 * push - adds new node at the end of the list
 * @stack: linked list of the data as stack
 * @line_number: line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *newNode = (stack_t *)malloc(sizeof(stack_t));

    stack_t *current = *stack;

    if (newNode == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer", line_number);
        exit(EXIT_FAILURE);
    }
    newNode->n = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (*stack == NULL)
    {
        *stack = newNode;
        return;
    }
    while (current->next)
        current = current->next;
    current->next = newNode;
    newNode->next = NULL;
    newNode->prev = current;
}
