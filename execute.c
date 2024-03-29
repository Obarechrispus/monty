#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void execute(char *instruction, stack_t **stack, unsigned int line_number, FILE *file) {
    char *token = strtok(instruction, " ");
    (void)file;
    if (token == NULL)
        return;
    if (strcmp(token, "push") == 0) {
        char *arg = strtok(NULL, " ");
        if (arg == NULL) {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        /* Assuming push function exists in your stack implementation*/
        push(stack, arg, line_number);
    } /*else if (strcmp(token, "pop") == 0) {
        // Assuming pop function exists in your stack implementation
        pop(stack);
    } else if (strcmp(token, "add") == 0) {
        // Assuming add function exists in your stack implementation
        add(stack);
    }
    // Add more cases for other ins*/
    else {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
        exit(EXIT_FAILURE);
    }
}
/**void push(stack_t **stack, char *value, unsigned int line_number)*/
