#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * push - Pushes an element onto the stack
 * @stack: Double pointer to the head of the stack
 * @value: Value to push onto the stack
 * @line_number: Line number in the Monty bytecode file
 *
 * Description: This function pushes an element onto the stack.
 */
void push(stack_t **stack, char *value, unsigned int line_number)
{
    int num;
    stack_t *new_node = malloc(sizeof(stack_t));

    if (value == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    num = atoi(value);
    if (num == 0 && *value != '0')
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

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

    if (current == NULL)
        return;

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
/*
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number of the instruction.
 * @arg: Argument passed with the instruction.
 
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
*/
