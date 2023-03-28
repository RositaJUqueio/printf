/* Authors: Aliyu Adekola and Rosita J Uqueio */
#include "main.h"

/* Function to convert unsigned int to binary */
void print_binary(unsigned int num) {
    if (num > 1) {
        print_binary(num / 2);
    }
    printf("%d", num % 2);
}

/* Function to handle custom conversion specifier 'b'*/
int print_binary_specifier(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    print_binary(num);
    return 0;
}

/* Main printf function that handles u, o, x, X, and b specifiers*/
int my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int chars_written = 0;
    char c;

    while ((c = *format++) != '\0') {
        if (c != '%') {
            putchar(c);
            chars_written++;
            continue;
        }

        c = *format++;
        switch (c) {
            case 'u': {
                unsigned int num = va_arg(args, unsigned int);
                chars_written += printf("%u", num);
                break;
            }
            case 'o': {
                unsigned int num = va_arg(args, unsigned int);
                chars_written += printf("%o", num);
                break;
            }
            case 'x': {
                unsigned int num = va_arg(args, unsigned int);
                chars_written += printf("%x", num);
                break;
            }
            case 'X': {
                unsigned int num = va_arg(args, unsigned int);
                chars_written += printf("%X", num);
                break;
            }
            case 'b': {
                unsigned int num = va_arg(args, unsigned int);
                print_binary_specifier(args);
                chars_written += 0;
                break;
            }
            default:
                printf("Invalid format specifier\n");
                exit(EXIT_FAILURE);
        }
    }
    va_end(args);
    return chars_written;
}

int main() {
    my_printf("u: %u\n", 10);
    my_printf("o: %o\n", 10);
    my_printf("x: %x\n", 255);
    my_printf("X: %X\n", 255);
    my_printf("b: %b\n", 10);
    return 0;
}

