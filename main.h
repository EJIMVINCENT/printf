#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct format
{
	char c;
	int (*fc(char))(int, ...);

}check;

#define BUFFER_SIZE 1024

_printf(const char *format, ...);
int _putchar(char c);
int printBuffer(char *string);

#endif
