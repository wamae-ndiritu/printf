#include <stdio.h>
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
