#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
 * get_handler - selects the correct conversion to perfom
 * @format: the format of the conversion
 *
 * Return: returns return value of the conversion perfomed
 */

int (*get_handler(char format))(int, va_list)
{
	conversion conversions[] = {
		{'d', handle_integers},
		{'i', handle_integers},
		{'c', handle_character},
		{'s', handle_strings},
		{'b', handle_binary},
		{'u', handle_unsigned_decimal},
		{'x', handle_hex_lower},
		{'X', handle_hex_upper},
		{'o', handle_octal},
		{'\0', NULL}
	};
	int i = 0;

	while (conversions[i].format != '\0')
	{
		if (format == conversions[i].format)
		{
			return (conversions[i].handler);
		}
		i++;
	}
	return (NULL);
}

