#include <stdio.h>
#include "../include/perror.h"

// macro without paramenter
#define PI 3.14

// macro with parameters
#define SUM(X, Y) (X)+(Y)

#define perror printf("\033[1;31mThis is an error...!\033[0m\n");

#define inc(N) (N)+1
#define max(a, b) (((a)>(b)) ? (a) : (b))

int main(){
    int a = 5;
    perror
    printf("Sum of 5 " "and a is: %d\n", SUM(a, 5));
    printf("increment value of a is: %d\n", inc(a));
    Perror("this is an perror macro");
    printf("max between 5 and 10 is : %d\n", max(5, 10));
    return 0;
}
