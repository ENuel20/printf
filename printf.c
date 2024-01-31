#include "main.h"

/**
 * _printf - prints the formatted string character by character
 * @format: format string
 * Return: num_chars, the number of characters in the string
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
			if (*format == 'c')
			{
				char c = va_arg(arguments, int);
				buffer[buffer_index++] = c;
			}
			else if (*format == 's')
			{
				char *string = va_arg(arguments, char *);
				int len = strlen(string);
				memcpy(buffer + buffer_index, string, len);
				buffer_index += len;
			}
			else if (*format == '%')
			{
				buffer[buffer_index++] = '%';
			}
			else if (*format == 'd' || *format == 'i' || *format == 'u' ||
					*format == 'o' || *format == 'x' || *format == 'X')
			{
				long integer = 0;
				if (*format == 'd' || *format == 'i')
				{
					integer = va_arg(arguments, int);
				}
				else if (*format == 'u')
				{
					integer = va_arg(arguments, unsigned int);
				}
				else if (*format == 'o')
				{
					integer = va_arg(arguments, unsigned int);
					buffer_index += sprintf(buffer + buffer_index, "%o", integer);
					continue;
				}
				else if (*format == 'x' || *format == 'X')
				{
					integer = va_arg(arguments, unsigned int);
					buffer_index += sprintf(buffer + buffer_index, (*format == 'x') ? "%x" : "%X", integer);
					continue;
				}

				buffer_index += sprintf(buffer + buffer_index, "%ld", integer);
			}
		}
		else
		{
			buffer[buffer_index++] = *format;
		}

		if (buffer_index >= BUFFER_SIZE - 1 || *(format + 1) == '\0')
		{
			write(1, buffer, buffer_index);
			num_chars += buffer_index;
			buffer_index = 0;
		}

		format++;
	}

	va_end(arguments);
	return (num_chars);
}

