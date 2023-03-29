/* Authors: Aliyu Adekola and Rosita J Uqueio */

#include "main.h"

/* Function to convert unsigned int to binary */

/**
 * print_binary - Recursively prints binary representation of an unsigned int.
 *
 * @num: The unsigned int to be printed in binary form.
 */

void print_binary(unsigned int num)
{
	if (num > 1)
	{
		print_binary(num / 2);
	}
	printf(num % 2 + '0');
}

/* Function to handle custom conversion specifier 'b'*/

/**
 * print_binary_specifier - Converts an unsigned int to binary and prints it.
 *
 * @args: A va_list containing the unsigned int to be printed.
 *
 * Return: Always 0.
 */
int print_binary_specifier(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int chars_written = 0;
	unsigned int divisor = 1;

	while (num / divisor > 9)
	{
		divisor *= 10;
	}

	while (divisor != 0)
	{
		putchar(num / divisor + '0');
		chars_written++;
		num %= divisor;
		divisor /= 10;
	}

	return (chars_written);
}

/**
 * print_o - Prints an unsigned int in octal format.
 *
 * @args: A va_list containing the unsigned int to be printed.
 *
 * Return: The number of characters printed.
 */
int print_o(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int chars_written = 0;
	unsigned int octal_num = 0, i = 1;

	while (num != 0)
	{
		octal_num += (num % 8) * i;
		num /= 8;
		i *= 10;
	}

	while (i > 1)
	{
		i /= 10;
		putchar((octal_num / i) + '0');
		chars_written++;
		octal_num %= i;
	}

	return (chars_written);
}

/**
 * print_x - Prints an unsigned int in hexadecimal format (lowercase).
 *
 * @args: A va_list containing the unsigned int to be printed.
 *
 * Return: The number of characters printed.
 */
int print_x(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int chars_written = 0;
	char hex_digits[] = "0123456789abcdef";
	char hex_num[32];
	int i = 0;

	while (num != 0)
	{
		hex_num[i++] = hex_digits[num % 16];
		num /= 16;
	}

	while (i-- > 0)
	{
		putchar(hex_num[i]);
		chars_written++;
	}

	return (chars_written);
}

/**
 * print_X - Prints an unsigned int in hexadecimal format (uppercase).
 *
 * @args: A va_list containing the unsigned int to be printed.
 *
 * Return: The number of characters printed.
 */
int print_X(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int chars_written = 0;
	char hex_digits[] = "0123456789ABCDEF";
	char hex_num[32];
	int i = 0;

	while (num != 0)
	{
		hex_num[i++] = hex_digits[num % 16];
		num /= 16;
	}

	while (i-- > 0)
	{
		putchar(hex_num[i]);
		chars_written++;
	}

	return (chars_written);
}

/**
 * print_b - Prints an unsigned int in binary format.
 *
 * @args: A va_list containing the unsigned int to be printed.
 *
 * Return: The number of characters printed.
