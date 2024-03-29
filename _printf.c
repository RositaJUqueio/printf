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

	if (format == NULL)
		return (-1);

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
					count += print_number(args);
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
 * print_string - prints a string to stdout
 * @args: va_list pointing to the string to print
 *
 * Return: the number of characters written to stdout
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	return (write(1, str, _strlen(str)));
}

/**
 * print_number - prints an integer to stdout
 * @args: va_list pointing to the integer to print
 *
 * Return: the number of characters written to stdout
 */
int print_number(va_list args)
{
	int n = va_arg(args, int);
	char buffer[20];
	int i = 0, j, count = 0;

	if (n == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		buffer[i] = n % 10 + '0';
		i++;
		n /= 10;
	}
	for (j = i - 1; j >= 0; j--)
	{
		count += write(1, &buffer[j], 1);
	}
	return (count);
}

/**
 * _strlen - gets the length of a string
 * @str: the string to get the length of
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str && str[i])
		i++;
	return (i);
}
