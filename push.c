#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the instruction.
 * @arg: Argument passed with the instruction.
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new_node;

    if (!arg)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(arg);
    new_node->next = NULL;
    
    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
	new_node->next = *stack;
    }
    *stack = new_node;
}
