#include "main.h"

/**
 * get_width - get width of a string
 * @format: formatted list
 * @i: arguments to print
 * @list: list of arguments
 * Return: 0
 */

int get_width(const char *format, int *i, va_list list)
{
	int current_index;
	int wdth = 0;

	for (current_index = *i + 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			wdth *= 10;
			wdth += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			wdth = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = current_index - 1;

	return (wdth);
}
