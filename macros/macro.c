#include <stdio.h>
#include "../include/perror.h"

// macro without paramenter
#define PI 3.14

// macro with parameters
#define SUM(X, Y) (X)+(Y)

#define perror printf("\033[1;31mThis is an error...!\033[0m\n");

#define inc(N) (N)+1

int main(){
    int a = 5;
    perror
    printf("Sum of 5 " "and a is: %d\n", SUM(a, 5));
    printf("increment value of a is: %d\n", inc(a));
    Perror("this is an perror macro");
    return 0;
}
