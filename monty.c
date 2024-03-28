#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
/*    char parse_and_execute_instruction[];*/
    char *line = NULL;
    size_t len = 0;
   /* int read;*/
    unsigned int line_number = 0;

   /* stack_t *stack = NULL;*/

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, len, file) != NULL)
 {
        line_number++;
        /* Parse and execute instruction */
        /* Assuming you have a function to parse and execute instructions */
      /*  if (parse_and_execute_instruction(line, &stack, line_number) == EXIT_FAILURE) {
            fprintf(stderr, "L%u: unknown instruction %s", line_number, line);
            exit(EXIT_FAILURE);
        }*/
    }

    if (line) {
        free(line);
    }
    fclose(file);
    /* Free any remaining memory */
    /* Assuming you have a function to free memory used by the stack */
    /*free_stack(&stack);*/
    return EXIT_SUCCESS;
}

