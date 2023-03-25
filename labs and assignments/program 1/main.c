//Made by Benjamin Haedt for class CSCI112, Fall 2020 semester, current date is 9/30/2020
//This program takes a collection of network addresses from a text file, sorts them, and then tells us the largest network in each class,
// and how many hosts are in that network. 



#include <stdio.h>  //this are the librars we use for this program
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char** argv){ //our main function
	if(argc != 2){ 			//this tells us that if we dont get 2 arguments in our input then exit the program
		printf("ERROR: NEED NUMBER OF LINES FOLLOWED BY THE INPUT FILE, EX. ./program1 17 inp17.txt");
		return 0;
	}
	long length = strtol(argv[1], &argv[2], 10);	//turns our first value input into a integer that the program can use
	if (length == 0){    		//makes sure we are given an actual int argument in the command line
		printf("ERROR: NEED NUMBER OF ARGUMENTS");
		return 0;
	}	
	printf("running %s with %ld addresses\n", argv[0],length);
	unsigned char array[length][4];			//makes a unisigned char array with demention's [n] and [4]
	int  i;
	for (i = 0; i < length; i++){			// uses stdin to read the .txt file and put it into an array
		scanf("%hhu.%hhu.%hhu.%hhu", &array[i][0], &array[i][1], &array[i][2], &array[i][3]);
	}
	
	sort(array, length);	//calls our sort function to sort the array
	classA(array);		//calls the classA function that seperates and provides us with the requiired information for class A networks
	classB(array);		//calls the classB function that seperates and provides us with the requiired information for class B networks
	classC(array);		//calls the classC function that seperates and provides us with the requiired information for class C networks
	printf("\n");
}
