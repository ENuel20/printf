#include "main.h"
/**
 * _printf: prints the formated string charcater by character
 * handles the the following conversion string
 * c
 * s
 * %
 * format: a pointer to the arguments passed to the string
 * Return: num_chars, the number of characters in the string
 */

int _printf(const char *format, ...)
{
	int num_chars = 0;
	va_list arguments;

	if	(format == NULL)
	{
	return (-1);
	}
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if	(*format == '%')
			{
				write(1, format, 1);
				num_chars++;
			}
			else if	(*format == '\0')
			{
				break;
			}
			else if	(*format == 'c')
			{
				char c = va_arg(arguments, int);
					write(1, &c, 1);
					num_chars++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(arguments, char*);

				write(1, string, strlen(string));
				num_chars += strlen(string);
			}
		}
		else
		{
			write(1, format, 1);
			num_chars++;
		}
		format++;
	}
	va_end(arguments);
	return (num_chars);
}

