#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp = fopen("sample.txt", "r");
    int c;
    while((c=fgetc(fp))!=EOF){
        printf("%c", c);
    }

    fclose(fp);
    return 0;
}
