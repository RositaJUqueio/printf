#ifndef PRINT_H
#define PRINT_H

#include <stdarg.h>
#include <stdio.h>

int putchar(int c);
int print_string(const char *str);
int print_plus_space_hash(const char *format, va_list args);

#endif /* PRINT_H */
