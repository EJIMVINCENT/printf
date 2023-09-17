#include "main.h"







int printString(int i, ...)
{
	char *string;
	va_list list;


	va_start(list, i);

	string = va_arg(list, char *);
	if (string == NULL)
		return (-1);
	i = 0;
	while(string[i])
		i++;
	i++;
	write(1, string, i);
	va_end(list);
	return(i);

}

int printChar(int i, ...)
{
	va_list character;
	char temp;
	
	va_start(character, i);

	i = 1;
	temp = va_arg(character, int);
	_putchar(temp);
	va_end(character);
	return (i);

}

