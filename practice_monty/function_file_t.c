#include "monty.h"

/**
 * _open - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void _open(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		_err(2, file_name);

	_read(fd);
	fclose(fd);
}


/**
 * _read - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void _read(FILE *fd)
{
	int line, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line = 1; getline(&buffer, &len, fd) != -1; line++)
	{
		format = _parse(buffer, line, format);
	}
	free(buffer);
}


/**
 * _parse - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int _parse(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		_err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	_find(opcode, value, line_number, format);
	return (format);
}

/**
 * _find - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void _find(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", _add_stack},
		{"pall", _print_stack},
		{"pint", _print},
		{"pop", _pop},
		{"nop", _nop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _print_char},
		{"pstr", _print_str},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			_call_f(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		_err(3, ln, opcode);
}


/**
 * _call_f - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void _call_f(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			_err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				_err(5, ln);
		}
		node = _create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			_add_queue(&node, ln);
	}
	else
		func(&head, ln);
}
