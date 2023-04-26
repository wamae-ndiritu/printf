#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
 * handle_integers - formats integers
 * @char_printed_count: number of characters printed to the output stream
 * @args: list of arguments to be formatted
 *
 * Return: returnschar_printed_character
 */

int handle_integers(int char_printed_count, va_list args)
{
	char buf[32];
	int num, len, write_res;

	num = va_arg(args, int);
	len = sprintf(buf, "%d", num);
	write_res = write(1, buf, len);
	if (write_res < 0)
		return (char_printed_count);
	char_printed_count += write_res;
	return (char_printed_count);
}

/**
 * handle_unsigned_decimal - formats unsigned decimals
 * @char_printed_count: number of characters printed to the stdout
 * @args: list of args to be formatted
 *
 * Return: returns char_printed_count
 */

int handle_unsigned_decimal(int char_printed_count, va_list args)
{
	unsigned int num;
	int result;
	char buffer[20];

	num = va_arg(args, unsigned int);
	result = snprintf(buffer, sizeof(buffer), "%u", num);
	if (result < 0)
		return (char_printed_count);
	write(1, buffer, result);
	char_printed_count += result;
	return (char_printed_count);
}

/**
 * to_hex_helper - helps in converting number to base 16
 * @num: the number to be formatted
 * @format: %x for lowercase, %X for uppercase
 *
 * Return: returns the number of characters stored in buffer
 */

int to_hex_helper(unsigned int num, char *format)
{
	char *buffer;
	int print_count = 0, result;

	buffer = (char *)malloc(sizeof(char) * 9);
	if (buffer == NULL)
	{
		free(buffer);
		return (0);
	}
	result = snprintf(buffer, 9, format, num);
	if (result < 0)
	{
		free(buffer);
		return (print_count);
	}
	write(1, buffer, result);
	print_count += result;
	free(buffer);
	return (print_count);
}

/**
 * handle_hex_lower - formats a number to hexadecimal (base 16)
 * @char_printed_count: number of characters printed to the stdout
 * @args: list of arguments to be formatted
 *
 * Return: returns char_printed_count
 */

int handle_hex_lower(int char_printed_count, va_list args)
{
	int count, num;

	num = va_arg(args, unsigned int);
	count = to_hex_helper(num, "%x");
	if (count == 0)
		return (char_printed_count);
	char_printed_count += count;
	return (char_printed_count);
}

/**
 * handle_hex_upper - formats a number to base 16 in upper
 * @char_printed_count: number of characters printed to the stdout
 * @args: list of arguments to be formatted
 *
 * Return: returns char_printed_count
 */

int handle_hex_upper(int char_printed_count, va_list args)
{
	int count, num;

	num = va_arg(args, unsigned int);
	count = to_hex_helper(num, "%X");
	if (count == 0)
		return (char_printed_count);
	char_printed_count += count;
	return (char_printed_count);
}
