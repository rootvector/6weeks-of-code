#include <stdio.h>
#include <stdlib.h>

void print_utf(char *s, int size);

#define BYTES 0x10
int main(){
    int c;
    int memloc = 0x0;
    int res;
    int memsize = 0;
    char *s = (char *) calloc(BYTES, sizeof(char));

    while((c=getchar())!=EOF){
        s[memloc % BYTES] = c;
        if((res = memloc % BYTES) == 0x0){ 
            printf("%08x  ", memloc);
        }
        if(((memloc % 0x08) == 0x0) && memloc != 0x0 && (memloc % 0x10) != 0x0){
            putchar(' ');
        }
        
        memloc++;
        printf("%02x ", c);
        if((memloc % BYTES) == 0x0){
            printf(" ");
            print_utf(s, BYTES);
        }
    }

    memsize = (memloc%BYTES);
    if(memsize <= 0x8)
        printf("%*s", 2 + (3*(0x10 - (memloc%0x10))), " ");
    else
        printf("%*s", 1 + (3*(0x10 - (memloc%0x10))), " ");
 
    if(memloc <= BYTES){
        print_utf(s, memloc);
    }
    else {
        print_utf(s, (memloc%0x10));
        printf("%08x ", memloc);
    }
    return 0;
}

void print_utf(char *s, int size){
    printf("|");
    for(int i = 0; i < size;i++ ){
        if((s[i] >= 0x00 && s[i] <= 0x1F) || s[i] >= 0x7E)
            printf(".");
        else
            printf("%c", s[i]);
    }
    printf("|\n");
}
