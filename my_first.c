#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * @format: Formatted string in which to print the arguments
 *
 * Return: Precision.
 */

int get_precision(const char *format, int *i, va_list list)
{
	int c_i = *i + 1;
	int precision = -1;

	if (format[c_i] != '.')
		return (precision);

	precision = 0;


	for (c_i += 1; format[c_i] != '\0'; c_i++)


	{
		if (is_digit(format[c_i]))
		{
			precision *= 10;
			precision += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c_i - 1;

	return (precision);
}



/**
 * get_width - Calculates the width for printing
 * @list: list of arguments.
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 *
 * Return: width.
 */

int get_width(const char *format, int *i, va_list list)
{
	int curr_i, width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;

	return (width);
}
