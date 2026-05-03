#include <stdio.h>

#define square(X) (X) * (X)

int main(){
    int no = 5;
    printf("Square of %d is %d\n", no, square(no));
    return 0;
}
