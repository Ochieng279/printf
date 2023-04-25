#include "main.h"
/**
 * print_x - function that prints the contents of x if it exists
 * @x: Array of chars
 * @index: index that represents the length of the characters
 * Return: always 0
 */
void print_x(char x[], int *index)
{
	if (*index > 0)
		write(1, &x[0], *index);

	*index = 0;
}
/**
 * _printf - function that prints a  function
 * @format: format to be printed
 * Return: what has been printed in a given format.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0;
	int printed_chars = 0;
	int flags, width, precision = 0;
	int size = 0;
	int index = 0;

	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			x[index++] = format[i];
			if (index == BUFF_SIZE)
				print_buffer(x, &index);
			printed_chars++;
		}
		else
		{
			print_buffer(x, &index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, x,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_x(x, &index);
	va_end(list);
	return (printed_chars);
}
