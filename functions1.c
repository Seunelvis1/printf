#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - will print an unsigned number
 * @types: is the list a of arguments
 * @buffer:is the buffer array that will handle print
 * @flags:  will calculate active flags
 * @width: get width
 * @precision: is the specified prescision
 * @size: Size
 * Return: Number of chars printed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned long int dig = va_arg(types, unsigned long int);

	dig = convert_size_unsgnd(dig, size);

	return (handle_write_unsigned int(dig, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - will print an unsigned number in octal notation
 * @types: is the list of arguments
 * @buffer: is the buffer array that handle print
 * @flags:  will calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned long int dig = va_arg(types, unsigned long int);

	dig = convert_size_unsgnd(dig, size);

	return (handle_write_octal(dig, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - will print an unsigned number in hexadecimal notation
 * @types: is the list of arguments
 * @buffer: is the buffer array that handle print
 * @flags:  will calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: is the Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'z', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: is the list a of arguments
 * @buffer: is the buffer array that handle print
 * @flags:  it will calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'Z', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - it will print a hexadecimal number in lower or upper
 * @types: is the list a of arguments
 * @map_to: is the array of values to map the number to
 * @buffer: is the buffer array that handle print
 * @flags:  will calculates active flags
 * @flag_ch: will calculates active char flags
 * @width: is the Width
 * @precision: is the precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int dig = va_arg(types, unsigned long int);
	unsigned long int init_dig = dig;

	UNUSED(width);

	dig = convert_size_unsgnd(dig, size);

	if (dig == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (dig > 0)
	{
		buffer[j--] = map_to[dig % 16];
		dig /= 16;
	}

	if (flags & F_HASH && init_dig != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, j, flags, width, precision, buffer, size));
}
