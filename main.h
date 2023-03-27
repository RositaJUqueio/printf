#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* prototypes */
int _printf(const char *format, ...);
int _strlen(char *s);
int print_char(va_list args, char specifier);
int print_string(va_list args, char specifier);
int print_percent(va_list args, char specifier);
int print_number(va_list args, char specifier);

#endif /* MAIN_H */
