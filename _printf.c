#include "main.h"

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Is the Printf function
 * @format: is the format.
 * Return: is the printed chars.
 */
int _printf(const char *format, ...)
{
	int y, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (y = 0; format[y] != '\0'; y++)
	{
		if (format[y] != '%')
		{
			buffer[buff_ind++] = format[y];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				printed_chars += buff_ind;
			}
			else
			{
				printed_chars++;
			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &y);
			width = get_width(format, &y, list);
			precision = get_precision(format, &y, list);
			size = get_size(format, &y);
			y++;
			printed = handle_print(format, &y, list, buffer,
					       flags, width, precision, size);
			if (printed == -1)
			{
				va_end(list);
				return (-1);
			}
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - will print the content of the buffer if it exists
 * @buffer: is the array of chars
 * @buff_ind: is the Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}
