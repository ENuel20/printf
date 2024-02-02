#include "main.h"

/**
* print_character - Print a character to a buffer
* @buffer: The buffer to print to
* @buffer_index: The current index in the buffer
* @arguments: The va_list of arguments
*
* Return: The number of characters printed
*/
int print_character(char *buffer, int *buffer_index, va_list arguments)
{
	char c = va_arg(arguments, int);

	buffer[(*buffer_index)++] = c;
	return (1);
}

