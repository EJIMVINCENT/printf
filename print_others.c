#include "main.h"

/**
 * printPercentSign - prints percent sign
 *
 * @list: argument list
 * @f: flag passed
 *
 * Return: number of char printed
 *
 */

int printPercentSign(va_list list, flags *f, convs *c)
{
	(void)list;
	(void)f;
	(void)c;

	return (_putchar('%'));
}

/**
 * printNonPrint - prints Non printable characters
 *
 * @list: va_list arguments from _printf
 * @f: pointer to the struct flags
 *
 * Return: number of char printed
 *
 */

int printNonPrint(va_list list, flags *f, convs *c)
{
	int i, count = 0;
	char *temp;
	char *s = va_arg(list, char *);

	(void)f;
	(void)c;
	if (!s)
		return (_putString("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_putString("\\x");
			count += 2;
			temp = converter(s[i], 16, 'u');
			if (!temp[1])
				count += _putchar('0');
			count += _putString(temp);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}


/**
 * printRev - prints a string reverse
 *
 * @list: list of arguments from _printf
 * @f: pointer to the struct flags
 *
 * Return: length of the printed string
 *
 */

int printRev(va_list list, flags *f, convs *c)
{
	int i = 0, j = 0;
	char *string = va_arg(list, char *);

	(void)f;
	(void)c;
	if (!string)
		string = "(null)";

	while (string[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(string[j]);

	return (i);
}

/**
 * printRot13 - prints a string using rot13
 *
 * @list: list of arguments from _printf
 * @f: pointer to the struct flags
 *
 * Return: length of the printed string
 *
 */

int printRot13(va_list list, flags *f, convs *c)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *string = va_arg(list, char *);

	(void)f;
	(void)c;
	for (j = 0; string[j]; j++)
	{
		if (string[j] < 'A' || (string[j] >
		'Z' && string[j] < 'a') || string[j] > 'z')
			_putchar(string[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (string[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}

	return (j);
}

/**
 * printAddress - prints address of input in hexa format
 *
 * @list: va_list arguments from _printf
 * @f: pointer to the struct flags
 *
 * Return: number of char printed
 *
 */

int printAddress(va_list list, flags *f, convs *c)
{
	char *string;
	unsigned long int p = va_arg(list, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
		count = (_putString("(nil)"));
	else
	{
		string = converter(p, 16, 'l');
		count += _putString("0x");
		count += _putString(string);
		printConvSpec(c->w - count);
		return (count);
	}
}
