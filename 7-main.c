/* Author: Rosita J Uqueio and Aliyu Adekola */

#include "print.h"
#include <limits.h>
#include <stdio.h>

int main()
{
    int num = 1024;

    printf("Test case 1: %+d\n", num);
    printf("Test case 2: %+d\n", 0);
    printf("Test case 3: %+d\n", -1024);
    printf("Test case 4: %+d\n", INT_MAX);

    return 0;
}

