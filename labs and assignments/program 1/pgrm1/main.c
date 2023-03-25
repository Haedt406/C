//Made by Benjamin Haedt for class CSCI112, Fall 2020 semester, current date is 9/30/2020
//This program takes a collection of network addresses from a text file, sorts them, and then tells us the largest network in each class,
// and how many hosts are in that network. 


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char** argv){
	if(argc != 2){
		printf("ERROR: NEED NUMBER OF LINES FOLLOWED BY THE INPUT FILE, EX. ./program1 17 inp17.txt");
		return 0;
	}
	long length = strtol(argv[1], &argv[2], 10);	
	if (length == 0){
		printf("ERROR: NEED NUMBER OF ARGUMENTS");
		return 0;
	}	
	printf("running %s with %ld addresses\n", argv[0],length);
	unsigned char array[length][4];
	int  i;
	for (i = 0; i < length; i++){
		scanf("%hhu.%hhu.%hhu.%hhu", &array[i][0], &array[i][1], &array[i][2], &array[i][3]);
	}
	
	sort(array, length);
	classA(array);
	classB(array);
	classC(array);
/*	for (i = 0; i < length; i++){
	printf("%hhu.%hhu.%hhu.%hhu\n", array[i][0],array[i][1], array[i][2],array[i][3]);
	}*/
}