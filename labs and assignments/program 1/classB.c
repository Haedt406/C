#include <stdio.h>
void classB(const unsigned char array[][4]){
	int count = 0;
	int hosts = 1;
	int i = 0;
	unsigned char largestNetwork[2];
	int networkCount = 0;

	unsigned char rangeLower[1] = {128};
	unsigned char rangeUpper[1] = {191};
	unsigned char rangeTest[1] = {192};
						// the classB function that seperates and provides us with the requiired information for class B networks
						//this is where it starts, before it just work setting up values that will help us count, find, etc the 2d array to get the largest network in the class B range and the largest number of hosts in that network
	while(array[i][0] < rangeLower[0]){
			i++;
	}
	while(array[i][0] <= rangeUpper[0]){
		networkCount++;
		if(array[i+1][0] == array[i][0] && array[i+1][1] == array[i][1]){
				count++;
		}
		while(array[i+1][0] == array[i][0] && array[i+1][1] == array[i][1]){
				i++;
				count++;		
		}
		if (count > hosts){
				largestNetwork[0] = array[i][0];
				largestNetwork[1] = array[i][1];
				hosts = count;
		}
		count=0;
		if(array[i][0] < rangeTest[0]){
			i++;
		}
	}
	if (hosts == 1){
		printf("Class B has %d networks\nAll B networks have only 1 host\n", networkCount);	
	}
	else {
		printf("Class B has %d networks\nLargest B network is %hhu.%hhu with %d hosts\n", networkCount, largestNetwork[0], largestNetwork[1], hosts);
	}
	return;
}