#include <stdio.h>
#include <unistd.h>

int main(){
    int j=0;
    const char *progress = "####################################################################################################################";
    for(int i=0; i < 100; i++){
        printf("\r[%.*s]", i, progress);
        fflush(stdout);
        usleep(100000);
        j++;
    }
    printf("\nDone..!\n");
    return 0;
}
