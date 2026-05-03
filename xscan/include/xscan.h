#ifndef XSCAN_H_    /* Include gard */
#define XSCAN_H_
#include <stdio.h>

int print_byte(const int *c);   // An function that print the stdin text as stdout
void stream_copy(FILE *fp);
void hex(const char *s);

#endif     //  XSCAN_H_
