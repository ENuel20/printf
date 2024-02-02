#include "main.h"

/**
 * print_buffer - Write buffer to stdout and reset buffer
 * @buffer: The buffer to print
 * @buffer_index: The index in the buffer
 * @num_chars: Pointer to the total number of characters printed
 */
void print_buffer(char *buffer, int *buffer_index, int *num_chars)
{
	write(1, buffer, *buffer_index);
	*num_chars += *buffer_index;
	*buffer_index = 0;
}

/**
 * process_format - Process format specifier and update buffer
 * @buffer: The buffer to update
 * @buffer_index: The index in the buffer
 * @num_chars: Pointer to the total number of characters printed
 * @format: The format specifier
 * @arguments: The va_list of arguments
 *
 * Return: The number of characters processed
 */
int process_format(char *buffer, int *buffer_index, int *num_chars,
				   const char *format, va_list arguments)
{
	switch (*format)
	{
		case 'c':
			return (print_character(buffer, buffer_index, arguments));
		case 's':
			return (print_string(buffer, buffer_index, arguments));
		case 'd':
		case 'i':
			return (print_integer(buffer, buffer_index, arguments));
		case 'o':
			return (print_octal(buffer, buffer_index, arguments));
		case 'x':
			return (print_hex(buffer, buffer_index, arguments));
		case 'X':
			return (print_upper_hex(buffer, buffer_index, arguments));
		case '%':
			buffer[(*buffer_index)++] = '%';
			(*num_chars)++;
			break;
		default:
			break;
	}
	return (0);
}

/**
 * _printf - Print formatted output to stdout
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	int num_chars = 0;
	va_list arguments;

	if (format == NULL)
		return (-1);

	va_start(arguments, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			num_chars += process_format(buffer, &buffer_index, &num_chars,
										 format, arguments);
		}
		else
		{
			buffer[buffer_index++] = *format;
			num_chars++;
		}

		if (buffer_index >= BUFFER_SIZE - 1 || *(format + 1) == '\0')
		{
			print_buffer(buffer, &buffer_index, &num_chars);
		}

		format++;
	}

	va_end(arguments);
	return (num_chars);
}

