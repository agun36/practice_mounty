#include "monty.h"

/**
 * _print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _print_char(stack_t **stack, unsigned int line_number)
{
	int _ascii_code;

	if (stack == NULL || *stack == NULL)
		_string_err(11, line_number);

	_ascii_code = (*stack)->n;
	if (_ascii_code < 0 || _ascii_code > 127)
		_string_err(10, line_number);
	printf("%c\n", _ascii_code);
}

/**
 * _print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int _ascii_code;
	stack_t *template;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	template = *stack;
	while (template != NULL)
	{
		_ascii_code = template->n;
		if (_ascii_code <= 0 || _ascii_code > 127)
			break;
		printf("%c", _ascii_code);
		template = template->next;
	}
	printf("\n");
}

/**
 * _rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *template;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	template = *stack;
	while (template->next != NULL)
		template = template->next;

	template->next = *stack;
	(*stack)->prev = template;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * _rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *template;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	template = *stack;

	while (template->next != NULL)
		template = template->next;

	template->next = *stack;
	template->prev->next = NULL;
	template->prev = NULL;
	(*stack)->prev = template;
	(*stack) = template;
}
