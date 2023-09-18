#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct format
{
	char c;
	int (*fc)(va_list list);

}check;


#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);
int printString(va_list lis);
int printChar(va_list list);
int printInt(va_list list);
int checkFormat(va_list list, char character);

#endif
