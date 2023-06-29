#include "main.h"

/**
 * get_size - determines size of an object insidethe stack and heap
 * @format: string composed of 0 or more directives
 * @i: printed arguments
 * Return: 0
 */

int get_size(const char *format, int *i)
{
	int s = 0;
	int current_index = *i + 1;

	if (format[current_index] == 'l')
		s = S_LONG;
	else if (format[current_index] == 'h')
		s = S_SHORT;
	if (s == 0)
		*i = current_index - 1;
	else
		*i = current_index;
	return (s);
}
