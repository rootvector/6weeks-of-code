#include <stdio.h>
#include "include/tercont.h"

#define WIDTH 400
#define HEIGGT 250

int main(){
	int x = 40, y = 55, z = 40;
	int xb = x/z, yb = y/z;

	CLEAR_SCR(2);
	HIDE_CURSOR();

	MOVE_TO(x, y);
	printf("%s#%s", RED, NOR);
	MOVE_TO((x+20),y);
	printf("%s#%s", RED, NOR);
	MOVE_TO(x, (y+20));
	printf("%s#%s", RED, NOR);
	MOVE_TO((x+20),(y+20));
	printf("%s#%s", RED, NOR);
	
	MOVE_TO(xb, yb);                                                  printf("%s#%s", RED, NOR);                                        MOVE_TO((xb+20),yb);                                              printf("%s#%s", RED, NOR);                                        MOVE_TO(xb, (yb+20));                                             printf("%s#%s", RED, NOR);                                        MOVE_TO((xb+20),(yb+20));                                         printf("%s#%s", RED, NOR);

	printf("\n\n");
	SHOW_CURSOR();

	return 0;
}
