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
    return len;
}

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
    return sprintf(buffer + *buffer_index, "%ld", integer);
}

/**
 * print_octal - Print an octal number to a buffer
 * @buffer: The buffer to print to
 * @buffer_index: The current index in the buffer
 * @arguments: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int print_octal(char *buffer, int *buffer_index, va_list arguments)
{
    unsigned int integer = va_arg(arguments, unsigned int);
    return sprintf(buffer + *buffer_index, "%o", integer);
}

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
    return sprintf(buffer + *buffer_index, "%x", integer);
}

/**
 * print_upper_hex - Print an uppercase hexadecimal number to a buffer
 * @buffer: The buffer to print to
 * @buffer_index: The current index in the buffer
 * @arguments: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int print_upper_hex(char *buffer, int *buffer_index, va_list arguments)
{
    unsigned int integer = va_arg(arguments, unsigned int);
    return sprintf(buffer + *buffer_index, "%X", integer);
}

