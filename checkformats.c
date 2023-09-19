#include "main.h"
//**
// * printBinary - prints an integer in binary representation
//  *
//   * @num: the integer to be printed in binary
//    *
//     * Return: the count of characters printed
//      */
//      int printBinary(int num)
//      {
//          unsigned int count = 0;
//
//              if (num < 0)
//                  {
//                          _putchar('-');
//                                  count++;
//                                          num = -num;
//                                              }
//
//                                                  if (num == 0)
//                                                      {
//                                                              _putchar('0');
//                                                                      count++;
//                                                                          }
//                                                                              else
//                                                                                  {
//                                                                                          count += printBinaryHelper(num);
//                                                                                              }
//
//                                                                                                  return count;
//                                                                                                  }
//
//                                                                                                  /**
//                                                                                                   * printBinaryHelper - recursive helper function to print binary representation
//                                                                                                    *
//                                                                                                     * @num: the integer to be printed in binary
//                                                                                                      *
//                                                                                                       * Return: the count of characters printed
//                                                                                                        */
//                                                                                                        int printBinaryHelper(int num)
//                                                                                                        {
//                                                                                                            if (num == 0)
//                                                                                                                    return 0;
//
//                                                                                                                        int count = 0;
//
//                                                                                                                            count += printBinaryHelper(num >> 1);  // Shift right to get the next bit
//                                                                                                                                _putchar((num & 1) + '0');  // Print the least significant bit
//                                                                                                                                    count++;
//
//                                                                                                                                        return count;
//                                                                                                                                        }
//                                                                                                                                        In this modified version:
//
//                                                                                                                                        printBinary is the entry point to print the binary representation of an integer.
//                                                                                                                                        printBinaryHelper is a recursive helper function that prints the binary representation recursively.
//                                                                                                                                        You can call printBinary within your _printf implementation to handle the %b format specifier for printing integers in binary. For example:
//
//                                                                                                                                        c
//                                                                                                                                        Copy code
//                                                                                                                                        int printBinary(va_list list)
//                                                                                                                                        {
//                                                                                                                                            int num = va_arg(list, int);
//                                                                                                                                                return printBinary(num);
//                                                                                                                                                }
//
//
//
//
//
