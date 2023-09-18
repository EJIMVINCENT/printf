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
int len = 0, len1 = 0;

len1 = _printf("Character:[%c]\n", 'H');
printf("%d\n", len1);
len = _printf("String:[%s]\n", "I am a string !");
printf("%d\n", len);
len = _printf("%s, %s %s %s\n", "ajhadjkshjk", "qwdBJQDHJ", "BASJHBASJH", "kdDIDkkdjkj");
printf("%d\n", len);
_printf("%d\n", len);
return (0);

}

