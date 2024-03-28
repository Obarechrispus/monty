#include "monty.h"
#include <stdio.h>

/**
 * push - Opcode function to push an element to the stack
 * @stack: Double pointer to the head of the stack
 * @value: Value to be pushed to the stack
 */
void push(stack_t **stack, int value)
{
    /* Create a new stack node */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

/**
 * pall - Opcode function to print all the values on the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - Opcode function to print the value at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
