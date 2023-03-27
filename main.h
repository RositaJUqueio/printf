#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct print_func - struct to store function and associated format char
 * @f: function pointer to a function to print associated format char
 * @format: associated format char
 *
 * Description: Used to select the correct function to print a format char
 */
typedef struct print_func
{
	int (*f)(va_list, char *);
	char format;
} print_func_t;

/* prototypes */
int _printf(const char *format, ...);
int print_c(va_list args);
int print_number(va_list args, char specifier);
int _strlen(char *s);


#endif /* MAIN_H */
