//made by Benjamin Headt for CSCI112, fall 2020 semester MSU bozeman
//this program takes an int and determines if its a palindrome using recursion
//we read numbers from a file line by line and send to our recursive function
//the recursive function will return a boolean data type

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef enum {false, true} Bool_t; 							//our enum to define a boolean value

Bool_t NumPal(int num, int rev, int original, int len){		//our recursive function that actually determines if a number is a palindrome
	if(len == 0){
		if((rev == original) || (num == original)){return true;}
		else{return false;}
	}
	else{
		len--;
		rev += (num%10)*pow(10, len);
		return(NumPal(num/10, rev, original, len));
	}
}

int main(){													//our main function that reads in a file line by line and sends the int into the recursive function
	int num, len = 0;
	FILE *infptr = fopen("/public/lab5/numbers.txt", "r");
	if (infptr == NULL){
			printf("ERROR: could not open input file\n");
			return(0);
	}

	while(fscanf(infptr, "%d", &num) != EOF){
		len = floor(log10(num)+1);
		printf("Is %d a palindrome? %s\n", num, (NumPal(num, 0, num, len) ? "yes" : "no"));	
	}
	fclose(infptr);
	return 1;
	
}