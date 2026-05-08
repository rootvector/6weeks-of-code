#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define MOVEUP "\033[5A"
#define MOVEDOWN "\033[10B"

int main(){
	printf("%sMoved Up\n", MOVEUP);
	sleep(2);
	printf("%sMoved Down\n", MOVEDOWN);
	return 0;
}
