#include <stdio.h>

int transform(int c);

int main(){
    int c;
    while((c=getchar()) != EOF){
        putchar(transform(c));
    }
    return 0;
}

// inverts the bits 0 -> 1 & 1 -> 0
int transform(int c){
    return ~c;
}
