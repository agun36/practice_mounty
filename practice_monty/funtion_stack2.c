#include "monty.h"

/**
 * _nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * _swap - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *template;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_more_err(8, line_number, "swap");
	template = (*stack)->next;
	(*stack)->next = template->next;
	if (template->next != NULL)
		template->next->prev = *stack;
	template->next = *stack;
	(*stack)->prev = template;
	template->prev = NULL;
	*stack = template;
}

/**
 * _add - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum_num = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum_num;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * _sub - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int sub_num;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		_more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sub_num = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub_num;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * _div - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		_more_err(9, line_number);
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
