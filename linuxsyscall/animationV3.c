#include <stdio.h>
#include <unistd.h>

int main(){
    const char frames[] = {'|', '/', '-', '\\'};
    printf("Animation V3..\n");
    for(int i=0; i < 10; i++){
        printf("\rLoading...%c", frames[i % 4]);
        fflush(stdout);
        sleep(1);
    }
    printf("\nDone!\n");
    return 0;
}
