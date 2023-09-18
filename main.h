#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct format
{
	char c;
	int (*fc)(int, ...);

}check;


#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);
void _printBuffer(const char *string, int count[]);
int printString(int, ...);
int printChar(int, ...);
int printInt(int, ...);
check checkFormat(char);
char *string_copy(const char *string);

#endif
