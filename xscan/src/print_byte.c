#include "../include/xscan.h"
#include <stdio.h>

int print_byte(const int *c){
    if(*c != EOF)
        return putchar(*c);
    else
        return -1;
}
