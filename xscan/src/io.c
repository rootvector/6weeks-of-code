#include <stdio.h>
#include <stdlib.h>
#include "../include/xscan.h"

void stream_copy(FILE *fp)
{
    int c;
    while((c = fgetc(fp))!=EOF)
        putchar(c);
}
