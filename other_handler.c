#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * to_octal_helper - helps in formatting to base 8
 * @num: the number to be formatted
 *
 * Return: returns the number of characters printed
 */

int to_octal_helper(unsigned int num)
{
	char *buffer;
	int print_count = 0, result;

	buffer = (char *)malloc(sizeof(unsigned int) * 12);
	if (buffer == NULL)
	{
		free(buffer);
		return (0);
	}
	result = snprintf(buffer, 12, "%o", num);
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
 * handle_octal - formats a number to octal (base 8)
 * @char_printed_count: number of characters printed to the stdout
 * @args: list of arguments to be formatted
 *
 * Return: returns char_printed_count
 */

int handle_octal(int char_printed_count, va_list args)
{
	unsigned int num;
	int count = 0;

	num = va_arg(args, unsigned int);
	count = to_octal_helper(num);
	if (count == 0)
		return (char_printed_count);
	char_printed_count += count;
	return (char_printed_count);
}
