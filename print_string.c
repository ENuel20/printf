#include "main.h"

/**
 * print_string - Print a string to a buffer
 * @buffer: The buffer to print to
 * @buffer_index: The current index in the buffer
 * @arguments: The va_list of arguments
 *
 * Return: The length of the string
 */
int print_string(char *buffer, int *buffer_index, va_list arguments)
{
	char *string = va_arg(arguments, char *);
	int len = strlen(string);

	memcpy(buffer + *buffer_index, string, len);
	*buffer_index += len;

	return (len);
}

