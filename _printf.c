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
	va_list args; /* declare va_list */
	int i, count = 0; /* initialize loop counter and character count */
	char *str; /* declare pointer to a string */

	va_start(args, format);/* initialize the va_list */

	for (i = 0; format && format[i]; i++)/* loop through the format string */
	{
		if (format[i] == '%') /* handle directive */
		{
			switch (format[i + 1])
			{
				case 'c': /* handle char */
					i++;
					count += write(1, (char *)&va_arg(args, int), 1);
					break;
				case 's': /* handle string */
					i++;
					str = va_arg(args, char *);
					if (str == NULL)
						count += write(1, "(null)", 6);
					else
						count += write(1, str, _strlen(str));
					break;
				case '%': /* handle percent sign */
					i++;
					count += write(1, "%", 1);
					break;
				case 'd': /* handle signed int */
				case 'i':
					i++;
					count += print_number(args);
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
	va_end(args);/* clean up the va_list */
	return (count); /* return total character count */
}

