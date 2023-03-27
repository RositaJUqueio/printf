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
					count += write(1, &va_arg(args, int), 1);
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
