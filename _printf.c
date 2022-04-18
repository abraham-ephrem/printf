#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
/**
 * _printf - a printf function
 * @format: the format of the content to be printed
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i;
	int j;
	int length = strlen(format);
	int str_length;
	int count = 0;
	char c;
	char *string;
	va_list ap;

	va_start(ap, format);
	for (i = 0; i < length; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1);
				count++;
				i++;
			}
			if (format[i + 1] == 'c')
			{
				c = va_arg(ap, int);
				write(1, &c, 1);
				i++;
				count++;
			}
			if (format[i + 1] == 's')
			{
				string = va_arg(ap, char *);
				str_length = strlen(string);
				for (j = 0; j < str_length; j++)
				{
					write(1, &string[j], 1);
					count++;
				}
				i++;
			}
		}
		va_end(ap);
	}
	return (count);
}
