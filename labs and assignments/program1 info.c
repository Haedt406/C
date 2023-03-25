#include <stdio.h>
#include <stdlib.h>
#define END -1

//to run: ./search 11 < numbers.txt
int search(const int array[], int numToFind){
	int i = 0;
	int found = 0;
	
	while(!found && array[i] != END){
		if (array[i] == numToFind){
			found = 1;
		}
		else {
			++i;
		}
	}	
	return found;
}

int main(int argc, char** argv){
	
	int noRead = 1, num, numToSearch, i, array[50];
	
	if (argc != 2){
		printf("ERROR: need to send in the number to search on the command line\n");
	}
	for (i = 0; noRead ==1; ++i){
		noRead = scanf("%d", &num);
		if (noRead == 1){
			array[i] = num;
		}
		else {
			array[i] = END;
		}
	}
	
	numToSearch = atoi(argv[1]);
	printf("%d was ", numToSearch);
	if (search(array, numToSearch)){
		printf("notfound\n");
	}
	else{
		printf("found\n");
	}
}