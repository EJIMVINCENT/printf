#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


/**
 * struct format - Struct op
 *
 * @c: character to be checked.
 * @fc: The function associated.
 *
 */

typedef struct format
{
	char c;
	int (*fc)(va_list list);

} check;


#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);
int printString(va_list list);
int printChar(va_list list);
int printInt(va_list list);
int (*checkFormat(char c))(va_list list);
void printNumber(int num);
int digitCount(int num);
int _putString(char *string);
int printPercentSign(va_list list);

#endif
