/*Authors: Aliyu Adekola and Rosita J Uqueio Task 7*/
#include "print.h"

/**
 * print_plus_space_hash - Handles +, space and # flags
 * @format: The format specifier
 * @args: The list of arguments
 *
 * Return: The number of characters printed
 */

int print_plus_space_hash(const char *format, va_list args)
{
	int printed = 0; /* Initialize the number of characters printed */
	char *str_arg; /* Declare a pointer to a string argument */
	va_list arg_copy; /* Declare a copy of the argument list */

	/* Copy the argument list */
	va_copy(arg_copy, args);

	switch (*format)
	{
		case '+': /* Handle + flag */
			printed += putchar('+'); /* Print the + character */
			str_arg = va_arg(args, char *); /* Get the string argument */
			printed += print_string(str_arg); /* Print the string */
			break;
		case ' ': /* Handle space flag */
			printed += putchar(' '); /* Print the space character */
			str_arg = va_arg(args, char *); /* Get the string argument */
			printed += print_string(str_arg); /* Print the string */
			break;
		case '#': /* Handle # flag */
			str_arg = va_arg(args, char *); /* Get the string argument */
			if (*format == 'o')/* If the format specifier is octal */
			{
				printed += putchar('0'); /* Print the leading zero */
				printed += print_string(str_arg); /* Print the string */
			}
			else if (*(format + 1) == 'x')
			{
				printed += print_string("0x");  /* Print the leading 0x */
				printed += print_string(str_arg); /* Print the string */
			}
			else if (*(format + 1) == 'X')
			{
				printed += print_string("0X"); /* Print the leading 0X */
				printed += print_string(str_arg); /* Print the string */
			}
			break;
	}
	va_end(arg_copy);
	return (printed); /* Return the number of characters printed */
}
