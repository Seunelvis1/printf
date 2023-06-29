#include "main.h"

/**
 * get_precision - will calculate precision for print
 * @format: is the format string in which to print the arguments
 * @i: is the pointer to the current index in the format string
 * @list: List of arguments
 *
 * Return: Precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int pre_i = *i + 1;
	int precision = -1;

	if (format[pre_i] != '.')
		return (precision);

	precision = 0;

	for (pre_i += 1; format[pre_i] != '\0'; pre_i++)
	{
		if (is_digit(format[pre_i]))
		{
			precision *= 10;
			precision += format[pre_i] - '0';
		}
		else if (format[pre_i] == '*')
		{
			prei++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = pre_i - 1;

	return (precision);
}
