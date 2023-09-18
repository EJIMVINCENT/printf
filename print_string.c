#include "main.h"







int printString(va_list list)
{
	int i = 0;
	char *string;

	string = va_arg(list, char *);
	if (string == NULL)
		string = "(null)";
	
	i = 0;
	while(string[i] != '\0')
		i++;

	write(1, string, i);
	return(i);


}

int printChar(va_list list)
{
	char character;

	 character= va_arg(list, int);
	_putchar(character);
	return (1);

}

