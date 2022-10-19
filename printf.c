#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _putchar(char c);
char *convert(int num, char *buffer, int base);
int _strlen(char *s);

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
	char *tmp;
	char buffer[20];
	int i = 0;
	int ival;

	va_start(ap, format);
	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			_putchar(*p);
			i++;
			continue;
		}
		i++;
		switch (*++p)
		{
			case 'c':
				cval = va_arg(ap, int);
				_putchar(cval);
				i++;
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
				{
					_putchar(*sval);
				}
				i += _strlen(sval);
				break;
			case '%':
				_putchar('%');
				i++;
				break;
			case 'i':
			case 'd':
				ival = va_arg(ap, int);
				if (ival < 0)
				{
					ival = -ival;
					_putchar('-');
				}
				for (tmp = convert(ival, buffer, 10); *tmp; tmp++)
				{
					_putchar(*tmp);
				}
				i += _strlen(tmp);
			default:
				break;
		}
	}
	va_end(ap);
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1
 * On error, -1 is returned and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strrev - a function to reverse a string
 * @str: a string
 *
 * Return: reversed string
 */

char *_strrev(char *str)
{
	int i, len = 0;
	char c;

	if (!str)
		return (NULL);
	while (*str)
	{
		len++;
	}

	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}
	return (str);
}

/**
 * convert - a function to convert integer to string
 * @num: the number
 * @buffer: an array holding the string
 * @base: base
 *
 * Return: the string
 */

char *convert(int num, char *buffer, int base)
{
	int i = 0, rem;

	if (num == 0)
	{
		buffer[i++] = '0';
	}

	while (num)
	{
		rem = num % base;
		buffer[i++] = ((rem > 9) ? (rem - 10) + 'A' : rem + '0');
		num = num / base;
	}
	buffer[i] = '\0';
	_strrev(buffer);
	return (buffer);
}

/**
 * _strlen - a function to derive length of an input string
 * @s: a string
 *
 * Return: the length of string
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; *s; i++)
	{
	}
	return (i);
}
