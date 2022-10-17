#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - produces output according to a format
 * @format: format
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	char cval, *sval;
	const char *p;
	int i = 0;

	va_start(ap, format);
	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			write(1, p, 1);
			i++;
			continue;
		}
		switch (*++p)
		{
			case 'c':
				cval = va_arg(ap, int);
				write(1, &cval, 1);
				i++;
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
				{
					write(1, sval, 1);
					i++;
				}
				break;
			case '%':
				write(1, p, 1);
				i++;
				break;
			default:
				i++;
				break;
		}
	}
	va_end(ap);
	return (1);
}
