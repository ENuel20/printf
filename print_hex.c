#include "main.h"
/**
 * print_hex - Print a hexadecimal number to a buffer
 * @buffer: The buffer to print to
 * @buffer_index: The current index in the buffer
 * @arguments: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int print_hex(char *buffer, int *buffer_index, va_list arguments)
{
	unsigned int integer = va_arg(arguments, unsigned int);

	return (sprintf(buffer + *buffer_index, "%x", integer));
}


