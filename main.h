/* main.h */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int print_character(char *buffer, int *buffer_index, va_list arguments);
int print_string(char *buffer, int *buffer_index, va_list arguments);
int print_integer(char *buffer, int *buffer_index, va_list arguments);
int print_octal(char *buffer, int *buffer_index, va_list arguments);
int print_hex(char *buffer, int *buffer_index, va_list arguments);
int print_upper_hex(char *buffer, int *buffer_index, va_list arguments);

#endif

