#include <stdio.h>
#include <stdlib.h>      // for system()
#include <unistd.h>      // for sleep()

int main(){
    int i;
    for(i = 0; i < 15; i++){
        system("clear");
        sleep(2);
        printf("\n\n%*s*", i, " ");
    }
    system("clear");
    return 0;
}
