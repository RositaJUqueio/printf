#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
int print_string(va_list args);
int print_number(va_list args);
int _strlen(char *str);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);
int power(int base, int exponent);

#endif /* MAIN_H */
