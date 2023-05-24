#include "monty.h"


/**
 * _add_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void _add_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *template;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	template = head;
	head = *new_node;
	head->next = template;
	template->prev = head;
}


/**
 * _print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void _print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *template;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	template = *stack;
	while (template != NULL)
	{
		printf("%d\n", template->n);
		template = template->next;
	}
}

/**
 * _pop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *template;

	if (stack == NULL || *stack == NULL)
		_more_err(7, line_number);

	template = *stack;
	*stack = template->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(template);
}

/**
 * _print - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _print(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		_more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
