#include <stdio.h>

#define RED "\033[1;41m"
#define NOR "\033[0m"

int main(){
	printf("%s Hello %s\n", RED, NOR);
	return 0;
}
