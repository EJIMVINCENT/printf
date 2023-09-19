nclude <stdarg.h>`
#include <stdio.h>
#include <stdlib.h>

char *string_copy(const char *src) {
	    // Implementation of string_copy depends on your requirements
	    //     // Make sure to allocate memory and copy the string properly
	    //         // For simplicity, using strdup which allocates memory and copies the string
	    //             return strdup(src);
	    //             }
	    //
	    //             int _printBuffer(const char *str) {
	    //                 int count = 0;
	    //                     while (*str) {
	    //                             putchar(*str);
	    //                                     count++;
	    //                                             str++;
	    //                                                 }
	    //                                                     return count;
	    //                                                     }
	    //
	    //                                                     typedef struct {
	    //                                                         char c;
	    //                                                             int (*fc)(int, ...);
	    //                                                             } check;
	    //
	    //                                                             int _printf(const char *format, ...) {
	    //                                                                 char *format_copy;
	    //                                                                     va_list arg_list;
	    //                                                                         int printed = 0, printedChar = 0;
	    //                                                                             check print_arg;
	    //
	    //                                                                                 if (format == NULL)
	    //                                                                                         return -1;
	    //
	    //                                                                                             va_start(arg_list, format);
	    //
	    //                                                                                                 format_copy = string_copy(format);
	    //                                                                                                     if (format_copy == NULL)
	    //                                                                                                             return -1;
	    //
	    //                                                                                                                 while (*format_copy != '\0') {
	    //                                                                                                                         if (*format_copy != '%')
	    //                                                                                                                                     printedChar += _printBuffer(format_copy);
	    //                                                                                                                                             else {
	    //                                                                                                                                                         print_arg.c = 's'; // Example: assume %s if format specifier is not properly checked
	    //                                                                                                                                                                     print_arg.fc = va_arg(arg_list, int (*)(int, ...)); // Example: assume function pointer for %s
	    //                                                                                                                                                                                 printed = print_arg.fc(0, va_arg(arg_list, char *));
	    //                                                                                                                                                                                             if (printed == -1)
	    //                                                                                                                                                                                                             return -1;
	    //                                                                                                                                                                                                                         printedChar += printed;
	    //                                                                                                                                                                                                                                 }
	    //                                                                                                                                                                                                                                         format_copy++;
	    //                                                                                                                                                                                                                                             }
	    //
	    //                                                                                                                                                                                                                                                 free(format_copy); // Fix: Free the dynamically allocated memory for the copied format
	    //                                                                                                                                                                                                                                                     va_end(arg_list);
	    //                                                                                                                                                                                                                                                         return printedChar;
	    //                                                                                                                                                                                                                                                         }
	    //
	    //                                                                                                                                                                                                                                                         int main() {
	    //                                                                                                                                                                                                                                                             _printf("Let's try to printf a simple sentence.\n");
	    //                                                                                                                                                                                                                                                                 return 0;
	    //                                                                                                                                                                                                                                                                 }
	    /#include <stdio.h>
#include <stdarg.h>
	    
	    int sum(int count, ...) {
		        va_list args;
			    va_start(args, count);
			    
			        int result = 0;
				    for (int i = 0; i < count; i++) {
					            int num = va_arg(args, int); // Fetch the next argument as an int
						            result += num;
							        }
				    
				        va_end(args); // Clean up the va_list
					
					    return result;
	    }

int main() {
	    int total = sum(5, 1, 2, 3, 4, 5);
	        printf("Sum: %d\n", total);
		    return 0;
}
/
