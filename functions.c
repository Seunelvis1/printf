#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - it will print a char
 * @types: is the list of arguments
 * @buffer:is the buffer array that handle print
 * @flags:  will calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char d = va_arg(types, int);

	return (handle_write_char(d, flags, width, buffer, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - it will print a string
 * @types: is the list of arguments
 * @buffer: is the buffer array to handle print
 * @flags: will calculates active flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, j;
	char *ptr = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (ptr == NULL)
	{
		ptr = "(null)";
		if (precision >= 6)
			ptr = "      ";
	}

	while (ptr[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (j = width - length; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - length; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, ptr, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - it will prints a percent sign
 * @types: is the Lisa of arguments
 * @buffer:is the buffer array that handle print
 * @flags:  will calculates active flags
 * @width: it will get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(width);
	UNSUED(flags);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - is the print int
 * @types: is the list of arguments
 * @buffer: is the buffer array that handle print
 * @flags: it will calculate active flags
 * @width: it will get width.
 * @precision: is the precision specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int its_negative = 0;
	long int m = va_arg(types, long int);
	unsigned long int dig;

	m = convert_size_number(m, size);

	if (m == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	dig = (unsigned long int)m;

	if (m < 0)
	{
		dig = (unsigned long int)((-1) * m);
		its_negative = 1;
	}

	while (dig > 0)
	{
		buffer[j--] = (dig % 10) + '0';
		dig /= 10;
	}

	j++;

	return (write_number(its_negative, j, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - will prints an unsigned number
 * @types: is the Lisa of arguments
 * @buffer: it is the buffer array that handle print
 * @flags:  it will calculates active flags
 * @width: it will get width.
 * @precision: is the Precision specifier
 * @size: specifies Size
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int m, n, j, sum;
	unsigned int a[32];
	int comp;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	m = va_arg(types, unsigned int);
	n = 2147483648; /* (2 ^ 31) */
	a[0] = m / n;
	for (j = 1; j < 32; j++)
	{
		n /= 2;
		a[i] = (m / n) % 2;
	}
	for (j = 0, sum = 0, comp = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			char y = '0' + a[j];

			write(1, &z, 1);
			comp++;
		}
	}
	return (comp);
}
}

