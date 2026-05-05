#include <stdio.h>
#include <time.h>

int main(){
	time_t now = time(NULL);
	printf("%ld\n", now);
	return 0;
}
