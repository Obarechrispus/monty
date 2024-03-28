#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	size_t read;
	FILE *file;

	(void)read;
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

   
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

   /* while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
      
        push(&stack, line_number, line);
        pall(&stack, line_number);       
    }*/
    while (fgets(line, len, file) != NULL) {
        line_number++;
        
        if (line[0] != '\n') { 
            push(&stack, line_number, line);
            pall(&stack, line_number); 
        }
    }

    
    if (line)
    {
        free(line);
    }
    fclose(file);

    return EXIT_SUCCESS;
}

