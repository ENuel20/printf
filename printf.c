#include "main.h"

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
        return -1;

    va_start(arguments, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c': num_chars += print_character(buffer, &buffer_index, arguments); break;
                case 's': num_chars += print_string(buffer, &buffer_index, arguments); break;
                case 'd': case 'i': num_chars += print_integer(buffer, &buffer_index, arguments); break;
                case 'o': num_chars += print_octal(buffer, &buffer_index, arguments); break;
                case 'x': num_chars += print_hex(buffer, &buffer_index, arguments); break;
                case 'X': num_chars += print_upper_hex(buffer, &buffer_index, arguments); break;
                case '%': buffer[buffer_index++] = '%'; num_chars++; break;
                default: break;
            }
        }
        else
        {
            buffer[buffer_index++] = *format;
            num_chars++;
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
    return num_chars;
}

