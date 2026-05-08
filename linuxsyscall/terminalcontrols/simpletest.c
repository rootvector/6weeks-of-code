#include <stdio.h>
#include "include/tercont.h"

int main(){
	printf("%s%sred color white background%s\n", RED, BACK_WHITE, NOR);
	printf("%s%s\tBOLD BLUE text and green background\t%s\n", BLUE_B, BACK_GREEN, NOR);
	printf("%s%sgreen text red background%s\n", GREEN, BACK_RED, NOR);
	
	return 0;
}
