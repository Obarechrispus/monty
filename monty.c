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
}
