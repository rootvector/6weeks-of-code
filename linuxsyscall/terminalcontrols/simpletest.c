#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "include/tercont.h"

int main(){
	char buffer[100] = ".@#!$%^&*(){}[]\"':;?/><|\\-_=+~`";
	int len = strlen(buffer);
	int j=1;

	CLEAR_SCR(2);
	printf("%s%sred color white background%s\n", RED, BACK_WHITE, NOR);
	MOVE_COLIN_ROW(30);
	printf("%s%s\tBOLD BLUE text and green background\t%s\n", BLUE_B, BACK_GREEN, NOR);
	MOVE_TO(40, 50);
	printf("%s%sgreen text red background%s\n", GREEN, BACK_RED, NOR);
	usleep(10000);
	HIDE_CURSOR();
	for(int i=0; i<50; i++){
		fflush(stdout);
		if(i >= 24){
			int k = i - j;
			printf(".");;
			MOVE_TO(k, i);
			j=j+2;
		}else{
			printf(".");
			MOVE_TO(i, i);
		}
		usleep(200000);
	}
	
	printf("\n");
	SHOW_CURSOR();
	return 0;
}
