#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#define _POSIX_C_SOURCE 200809L
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    char line[MAX_LINE_LENGTH];
    FILE *file;
    /**size_t size = 0;
    size_t read_line = 1;*/
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /**while (read_line > 0)
    {
        content = NULL;
        read_line = getline(&content, &size, file);
        counter++;
        if (read_line > 0)
        {
            execute(content, &stack, counter,file);
        }
        free(content);
    }*/
    while (fgets(line, sizeof(line), file) != NULL)
    {
	    counter++;
	    execute(line, &stack, counter, file);
    }
    free_stack(stack); 
    fclose(file);
    return (0);
}
