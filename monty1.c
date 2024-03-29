#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXIT_FAILURE 1
#define MAX_LINE_LENGTH 1024

/* Define your data structures and functions here */

int main_(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    char *newline;
    stack_t *stack;
    char *token;

    if (argc != 2) {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    stack = NULL;  /* Initialize an empty stack*/

    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;

        /* Remove trailing newline*/
        newline = strchr(line, '\n');
        if (newline != NULL)
            *newline = '\0';

        /* Tokenize the line and process the instruction*/
        token = strtok(line, " ");
        if (token == NULL)
            continue;  /* Empty line*/

        /* Execute the appropriate instruction*/
        if (strcmp(token, "push") == 0) {
            char *arg = strtok(NULL, " ");
            if (arg == NULL) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&stack, line_number, arg);
        } else {
            /* Handle other instructions*/
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    return 0;
}

