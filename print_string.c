#include "main.h"







int printString(int i, ...)
{
	char *string;
	va_list list;


	va_start(list, i);

	string = va_arg(list, char *);
	if (string == NULL)
		return (-1);

	while(string[i])
		i++;
	i++;
	write(1, string, i);
	return(i);

}

int printChar(int i, ...)
{
	va_list character;
	
	va_start(character, i);
	i++;
	putchar(va_arg(character, char));
	return (i);

}

