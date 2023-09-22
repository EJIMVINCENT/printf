#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    _printf("In the middle %6i of a sentence.\n", 1024);
    _printf("%6u", 102498402);
    _printf("%6u", 0);
    _printf("%6u", 1024);
    _printf("In the middle %6u of a sentence.\n", 1024);
    _printf("%6o", 102498402);
    _printf("%6o", 0);
    _printf("In the middle %6o of a sentence.\n", 1024);

    _printf("%6s", "Hi!\n");
    _printf("In the middle %6s of a sentence.\n", "Hey");
    _printf("%*d", 6, 102498402);
    _printf("%*d", 6, -102498402);
    _printf("In the middle %*d of a sentence.\n", 6, 1024);
    _printf("In the middle %*s of a sentence.\n", 6, "Hey");
    return (0);
}
