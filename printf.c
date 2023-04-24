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
	int i = 0, char_printed_count = 0;
	char c, *s;

	va_start(args, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(args, int);
					char_printed_count = write_and_count(1, &c, 1, char_printed_count);
					break;
				case 's':
					s = va_arg(args, char *);
					while (*s != '\0')
					{
						char_printed_count = write_and_count(1, s, 1, char_printed_count);
						s++;
					}
					break;
				case '%':
					char_printed_count = write_and_count(1, "%", 1, char_printed_count);
					break;
				default:
					break;
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
