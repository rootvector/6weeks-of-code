#include <stdio.h>
#include <unistd.h>

int main(){
    const char frames[] = {'|', '/', '-', '\\'};
    for(int i = 0; i < 100; i++){
        // \r returns cursor to start; fflush ensure it clear it draws immediately
        printf("\rLoading...%c", frames[i % 4]);
        fflush(stdout);         //  flush the standard output
        usleep(100000);         //  sleep for 100ms
    }
    printf("\nDone!\n");
    return 0;
}
