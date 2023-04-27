#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

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

/**
 * get_ascii - gets the ascii value of a character
 * @ch: the character whose ascii value is being found
 *
 * Return: returns the ascii value of ch
 */

int get_ascii(char ch)
{
	return (ch);
}

/**
 * handle_String - formats a custom conversion in printf
 * @char_printed_count: number of the characters printed to the stdout
 * @args: list of arguments to be formatted
 *
 * Return: returns char_printed-count
 */

int handle_String(int char_printed_count, va_list args)
{
	char *str, *buffer;
	int ascii_val, result;

	buffer = (char *)malloc(sizeof(char) * 2);
	if (buffer == NULL)
	{
		free(buffer);
		return (char_printed_count);
	}
	str = va_arg(args, char *);
	while (*str != '\0')
	{
		ascii_val = get_ascii(*str);
		if ((ascii_val > 0 && ascii_val < 32) || ascii_val >= 127)
		{
			write(1, "\\x", 3);
			char_printed_count += 3;
			result = snprintf(buffer, 2, "%02X", ascii_val);
			if (result < 0)
			{
				free(buffer);
				return (char_printed_count);
			}
			write(1, buffer, result);
			char_printed_count += result;
		}
		else
		{
			write(1, str, 1);
			char_printed_count++;
		}
		str++;
	}
	free(buffer);
	return (char_printed_count);
}

/**
 * handle_address - formats address of a pointer
 * @char_printed_count: number of character printed to the output
 * @args: list of argumnets to be fomatted
 *
 * Return: return char_printed_count
 */

int handle_address(int char_printed_count, va_list args)
{
	char buffer[32], *str;
	int result, buf_len;

	str = va_arg(args, char *);
	result = snprintf(buffer, 32, "%p", str);
	if (result < 0)
		return (char_printed_count);
	buf_len = strlen(buffer);
	write(1, buffer, buf_len);
	char_printed_count += buf_len;
	return (char_printed_count);

}
