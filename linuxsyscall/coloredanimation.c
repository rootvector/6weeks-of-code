#include <stdio.h>
#include <unistd.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"

int main(){
    const char frames[] = {'|', '/', '-', '\\'};
    for(int i = 0; i < 100; i++){
        printf("\r%sLoading..%c\033[0m", RED, frames[i % 4]);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n%sDone..!\033[0m\n", GREEN);
    return 0;
}
