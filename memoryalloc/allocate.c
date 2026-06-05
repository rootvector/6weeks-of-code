#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

int main(){
	int *arr = malloc(BUFFER_SIZE * sizeof(int));
	for(int i=0; i<BUFFER_SIZE; i++){
		arr[i] = i;
	}

	for(int j=0; j<BUFFER_SIZE; j++)
		printf("Arr[%d] = %d\n",j+1, arr[j]);

	free(arr);
	return 0;
}
