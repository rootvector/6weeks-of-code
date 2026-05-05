#include <stdio.h>
#include <time.h>

int main(){
	time_t now = time(NULL);
	char *cureent_time = ctime(&now);
	printf("%s\n", cureent_time);
	printf("%ld\n", now);
	return 0;
}
