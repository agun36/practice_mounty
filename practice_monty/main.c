#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_open(argv[1]);
	_free();
	return (0);
}

/**
 * _create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *_create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		_err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * _free - Frees nodes in the stack.
 */
void _free(void)
{
	stack_t *template;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		template = head;
		head = head->next;
		free(template);
	}
}


/**
 * _add_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void _add_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (template->next != NULL)
		template = template->next;

	template->next = *new_node;
	(*new_node)->prev = template;

}
