#include "monty.h"
#include <stdio.h>

int main(int argc, char **argv UNUSED)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    /* Read and parse the Monty bytecode file */
    /* Execute the instructions */

    return 0;
/*
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = MAX_LINE_LENGTH;
    unsigned int line_number = 0;
    FILE *file;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    line = malloc(len);
    if (line == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        line_number++;
        if (line[0] != '\n') {
           
            size_t line_len = strlen(line);
            if (line[line_len - 1] == '\n') {
                line[line_len - 1] = '\0';
            }
            push(&stack, line_number, line);
            pall(&stack, line_number);
        }
    }

    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}
*/

