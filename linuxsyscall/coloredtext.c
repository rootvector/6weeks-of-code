#include <stdio.h>
#include <unistd.h>

//  basic syntax       "\033[style;color_codem" 0;31 for normal style( or 1 for bold) and 31 for red.
//  "m" ends the escape sequence.
//  \033[0m The reset code.
//
#define RED "\033[0;31m"

int main(){
    printf("%s %s \033[0m\n", RED, "This is red text");
    return 0;
}
