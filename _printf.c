/* Authors: Aliyu Adekola and Rosita J Uqueio */

#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: the format string to be printed
 *
 * Return: the number of characters printed (excluding the null byte used
 * to end output to strings), or -1 if an error occurred
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;
	char *str;

	va_start(args, format);/* initialize the va_list */

	/* loop through the format string */
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
	{
			switch (format[i + 1])
			{
				case 'c': /* char */
					i++;
					count += write(1, (char *)&va_arg(args, int), 1);
					break;
				case 's': /* string */
					i++;
					str = va_arg(args, char *);
					if (str == NULL)
						count += write(1, "(null)", 6);
					else
						count += write(1, str, _strlen(str));
					break;
				case '%': /* percent sign */
					i++;
					count += write(1, "%", 1);
					break;
				default: /* handle unknown specifier */
					i++;
					count += write(1, &format[i], 1);
					break;
			}
		}
		else /* handle regular character */
			count += write(1, &format[i], 1);
	}
	va_end(args); /* clean up the va_list */
	return (count);
}

/**
 * _strlen - returns the length of a string
 * @s: the string to be measured
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s && s[i]; i++)
		;

	return (i);
}

/* extendig code to meet task 1 requirments */

/**
 * print_number - prints a number
 * @args: the va_list containing the number to be printed
 * @specifier: the conversion specifier (either 'd' or 'i')
 *
 * Return: the number of characters printed
 */
int print_number(va_list args)
{
	int num = va_arg(args, int);
	int is_negative = 0, count = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	if (num == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}

	if (is_negative)
		count += write(1, "-", 1);

	count += print_number_recursive(num);

	return (count);
}

/**
 * print_number_recursive - recursively prints a number
 * @num: the number to be printed
 *
 * Return: the number of characters printed
 */
int print_number_recursive(int num)
{
	int count = 0;

	if (num == 0)
		return (0);

	count += print_number_recursive(num / 10);

	count += write(1, &"0123456789"[num % 10], 1);

	return (count);
}
