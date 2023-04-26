#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include "main.h"

/**
 * write_and_count - writes to the stdout
 * @fd: file descriptor -> 1 for the std output
 * @buf: buffer to be written to the output stream
 * @n: size of the buffer
 * @count: number of characters written to the output stream
 *
 * Return: returns the count;
 */

int write_and_count(int fd, void *buf, size_t n, int count)
{
	write(fd, buf, n);
	count++;
	return (count);
}

/**
 * _printf - prints formated text to the stdout
 * @format: how the text will be formatted
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, char_printed_count = 0, (*result)(int, va_list);
	char c;

	va_start(args, format);
	if (format == NULL)
		return (char_printed_count);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			c = format[i];
			if (c == '%')
			{
				char_printed_count = write_and_count(1, "%", 1, char_printed_count);
			}
			else
			{
				result = get_handler(c);
				if (result == NULL)
					return (char_printed_count);
				char_printed_count = result(char_printed_count, args);
			}
		}
		else
		{
			c = format[i];
			char_printed_count = write_and_count(1, &c, 1, char_printed_count);
		}
		i++;
	}
	va_end(args);
	return (char_printed_count);
}
