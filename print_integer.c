#include "main.h"
/**
 * print_integer - Print an integer to a buffer
 * @buffer: The buffer to print to
 * @buffer_index: The current index in the buffer
 * @arguments: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int print_integer(char *buffer, int *buffer_index, va_list arguments)
{
	long integer = va_arg(arguments, int);

	return (sprintf(buffer + *buffer_index, "%ld", integer));
}
