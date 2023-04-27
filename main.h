#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdarg.h>

/**
 * struct conversion - structure conversions
 * @format: character representing the format
 * @handler: function to handle conversion
 */

typedef struct conversion
{
	char format;
	int (*handler)(int, va_list);
} conversion;
int _printf(const char *format, ...);
int handle_character(int char_printed_count, va_list args);
int handle_strings(int char_printed_count, va_list args);
int handle_integers(int char_printed_count, va_list args);
int handle_binary(int count, va_list args);
int handle_unsigned_decimal(int char_printed_ount, va_list args);
int handle_hex_lower(int char_printed_count, va_list args);
int handle_hex_upper(int char_printed_count, va_list args);
int handle_octal(int char_printed_count, va_list args);
int handle_String(int char_printed_count, va_list args);
int handle_address(int char_printed_count, va_list args);
int (*get_handler(char format))(int, va_list);
#endif
