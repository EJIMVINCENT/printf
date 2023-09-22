#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

/**
 * struct convs - conversion specifiers
 *
 * @w: field width
 * @p: precision
 *
 */

typedef struct convs
{
	int w;
	int p;
} convs;


/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 *
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 *
 */

typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags;


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
	int (*fc)(va_list list, flags *f, convs *c);

} check;


#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);
int printString(va_list list, flags *f, convs *c);
int printChar(va_list list, flags *f, convs *c);
int printInt(va_list list, flags *f, convs *c);
int (*checkFormat(char c))(va_list list, flags *f, convs *c);
void printNumber(int num);
int digitCount(int num);
int _putString(char *string);
int printPercentSign(va_list list, flags *f, convs *c);
int printBinary(va_list list, flags *f, convs *c);
int printAddress(va_list list, flags *f, convs *c);
int printUnsigned(va_list list, flags *f, convs *c);
int printOcta(va_list list, flags *f, convs *c);
int printhex(va_list list, flags *f, convs *c);
int printHEX(va_list list, flags *f, convs *c);
int printRev(va_list, flags *f, convs *c);
int printRot13(va_list list, flags *f, convs *c);
int printNonPrint(va_list list, flags *f, convs *c);
char *converter(unsigned long int n, int base, char);
int checkFlag(char, flags *flag);
int checkConvSpec(char s, convs *c);
int printConvSpec(int n);

#endif
