#ifndef MONTY_H
#define MONTY_H

#define UNUSED __attribute__((unused))

#include <stdlib.h>
<<<<<<< HEAD
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
=======

>>>>>>> c5cab4ffcbcd92b61f35f92fde9adf1a4a628d3c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* Function prototypes */
void push(stack_t **stack, char *value, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);

/*id pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number, char *arg);
<<<<<<< HEAD
int main(int argc, char *argv[]);
int main_(int argc, char *argv[]);
void execute(char *instruction, stack_t **stack, unsigned int line_number,FILE *file);
void free_stack(stack_t *stack);
=======
int main(int argc, char *argv[]);*/
int main(int argc, char *argv[]);
>>>>>>> c5cab4ffcbcd92b61f35f92fde9adf1a4a628d3c
#endif
