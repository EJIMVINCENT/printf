#include "main.h"

/**
 * _printf - the simplem printf function
 *
 * @format: the string passed to _printf to be printed
 *
 * Return: returns the number of char printed
 *
 */

int _printf(const char *format, ...)
{
	va_list list;
	int (*printFunc)(va_list, flags *, convs *);
	const char *f;
	flags flag = {0, 0, 0, 0, 0};
	convs c = {0, 0};

	register int count = 0;

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(list, format);
	for (f = format; *f; f++)
	{
		if (*f == '%')
		{
			f++;
			if (*f == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (checkFlag(*f, &flag))
				f++;
			while (checkConvSpec(*f, &c, list))
				f++;
			printFunc = checkFormat(*f);
			if (printFunc != NULL)
				count += printFunc(list, &flag, &c);
			else
				count += _printf("%%%c", *f);
		}
		else
			count += _putchar(*f);
	}
	_putchar(-1);
	va_end(list);
	return (count);
}
