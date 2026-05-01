#include <stdio.h>

int transform(int c, char *key);
int get_bitmask(char *key);

int main(int argc, char *argv[]){
    int c;
    if(argc < 2){
        printf("Usage: %s 'password/kay' < file > outputfile\n", argv[0]);
        return -1;
    }
    while((c=getchar())!=EOF){
        putchar(transform(c, argv[1]));
    }

    return 0;
}

int transform(int c, char *key){
    int bitmask = get_bitmask(key);
    return c ^ bitmask;
}

int get_bitmask(char *key){
    int hash = 0;
    while(*key)
        hash+=(*key++);
    return hash;
}
