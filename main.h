#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>



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
	int (*fc)(va_list list, flags *f);

} check;


#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);
int printString(va_list list, flags *f);
int printChar(va_list list, flags *f);
int printInt(va_list list, flags *f);
int (*checkFormat(char c))(va_list list, flags *f);
void printNumber(int num);
int digitCount(int num);
int _putString(char *string);
int printPercentSign(va_list list, flags *f);
int printBinary(va_list list, flags *f);
int printAddress(va_list list, flags *f);
int printUnsigned(va_list list, flags *f);
int printOcta(va_list list, flags *f);
int printhex(va_list list, flags *f);
int printHEX(va_list list, flags *f);
int printRev(va_list, flags *f);
int printRot13(va_list list, flags *f);
int printNonPrint(va_list list, flags *f);
char *converter(unsigned long int n, int base, char);
int checkFlag(char, flags *flag);

#endif
