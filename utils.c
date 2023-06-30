#include "main.h"

/**
 * is_printable - finds if character is printable
 * @c: character to evaluate
 * Return: 1
 */

int is_printable(char d)
{
	if (d >= 32 && d < 127)
		return (1);
	return (0);
}

/**
 * append_hexa_code - append hexadecimal to buffer
 * @buffer: temporary storage for array
 * @i: index when to start appending
 * @ascii_code: ascii
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int j)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[j++] = '\\';
	buffer[j] = 'x';

	buffer[j++] = map_to[ascii_code / 16];
	buffer[j] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - finds if character is digit
 * @c: character
 * Return: 0
 */

int is_digit(char d)
{
	if (d >= '0' && d <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_number - convert value of one data type to another
 * @num: number to convert
 * @size: type to be converted
 * Return: 0
 */
long int convert_size_number(long int dig, int size)
{
	if (size == S_LONG)
		return (dig);
	else if (size == S_SHORT)
		return ((short)dig);
	return ((int)dig);
}
/**
 * convert_size_unsgnd - sets number to specific size
 * @num: nubber
 * @size: size
 * Return: 0
 */
long int convert_size_unsgnd(unsigned long int dig, int size)
{
	if (size == S_LONG)
		return (dig);
	else if (size == S_SHORT)
		return ((unsigned short)dig);
	return ((unsigned int)dig);
}
