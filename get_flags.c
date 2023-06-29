#include "main.h"

/**
 * get_flags - will calculate active flags
 * @format: will format string in which to print the arguments
 * @i: is the pointer to the current index in the format string
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	int k, pre_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (pre_i = *i + 1; format[pre_i] != '\0'; pre_i++)
	{
		for (k = 0; FLAGS_CH[k] != '\0'; k++)
		{
			if (format[pre_i] == FLAGS_CH[k])
			{
				flags |= FLAGS_ARR[k];
				break;
			}
		}

		if (FLAGS_CH[k] == '\0')
			break;
	}

	*i = pre_i - 1;

	return (flags);
}
