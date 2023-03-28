/* Authors: Aliyu Adekola and Rosita J Uqueio */

#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: the format string to be printed
 *
 * Return: the number of characters printed (excluding the null byte used
 * to end output to strings), or -1 if an error occured
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += print_c(args);
					break;
				case 's':
					count += print_string(args);
					break;
				case 'd':
				case 'i':
					count += print_number(args, 'd');
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, &format[i - 1], 2);
					break;
			}
		}
		else
		{
			count += write(1, &format[i], 1);
		}
	}
	va_end(args);
	return (count);
}

/**
 * print_c - prints a single character to stdout
 * @args: va_list pointing to the character to print
 *
 * Return: the number of character written to stdout
 */
int print_c(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
/**
 * _strlen - gets the length of a string
 * @str: the string to get the length of
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * print_string - prints a string to stdout
 * @args: va_list pointing to the number to print
 *
 * Return: the number of characters written to stdout
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	return (write(1, str, _strlen(str)));
}
/**
 * print_number - prints an integer to stdout
 * @args: va_list pointing to the integer to print
 *
 * Return: the number of characters written to stdout
 */
int print_number(va_list args, char specifier)
{
	int n = va_arg(args, int);
	int count = 0;

	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n / 10)
	{
		count += print_number(args);
	}
	count += write(1, &"0123456789"[n % 10], 1);
	return (count);
}
