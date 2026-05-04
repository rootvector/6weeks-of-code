#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    char op;
    int no[3];
    int flag = 0;

    if(argc < 5){
        printf("Usage: %s -o [+, -, *, /] no1 no2\n", argv[0]);
        return -1;
    }
    op = argv[2][0];
    no[0] = atoi(argv[3]);
    no[1] = atoi(argv[4]);

    switch(op){
        case '+':
            printf("Addition: %d\n", no[0] + no[1]);
            break;
        case '-':
            printf("Substration: %d\n", no[0] - no[1]);
            break;
        case '*':
            printf("Multiplication: %d\n", no[0] * no[1]);
            break;
        case '/':
            printf("Division: %.2f\n", no[0] / no[1]);
            break;
        default:
            printf("Invalid operator..!\n");
    }
    return 0;
}
