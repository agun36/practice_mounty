#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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
        struct stack_s *prev; /*head*/
        struct stack_s *next;/*tail*/
} stack_t;

/**
 * struct instruction_s - opcode and its function name
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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations prototypes*/
void _open(char *file_name);
int _parse(char *buffer, int line_number, int format);
void _read(FILE *);
int _len(FILE *);
void _find(char *, char *, int, int);

/*Stack operations prototypes*/
stack_t *_create_node(int n);
void _free(void);
void _print_stack(stack_t **, unsigned int);
void _add_stack(stack_t **, unsigned int);
void _add_queue(stack_t **, unsigned int);

void _call_f(op_func, char *, char *, int, int);

void _print(stack_t **, unsigned int);
void _pop(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void _swap(stack_t **, unsigned int);

/*Math operations with nodes prototypes*/
void _add(stack_t **, unsigned int);
void _sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void _mul(stack_t **, unsigned int);
void _mod(stack_t **, unsigned int);

/*String operations prototypes*/
void _print_char(stack_t **, unsigned int);
void _print_str(stack_t **, unsigned int);
void _rotl(stack_t **, unsigned int);

/*Error hanlding prototypes*/
void _err(int error_code, ...);
void _more_err(int error_code, ...);
void _string_err(int error_code, ...);
void _rotr(stack_t **, unsigned int);

#endif
