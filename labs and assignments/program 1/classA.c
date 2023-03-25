#include <stdio.h>
void classA(const unsigned char array[][4]){		// the classA function that seperates and provides us with the requiired information for class A networks
	int count = 0;
	int hosts = 1;
	int i = 0;
	char largestNetwork;
	int networkCount = 0;
	unsigned char range[1] = {127};
	unsigned char rangeTest[1] = {128};		// the classA function that seperates and provides us with the requiired information for class A networks
	while(array[i][0] <= range[0]){			//this is where it starts, before it just work setting up values that will help us count, find, etc the 2d array to get the largest network in the class A range and the largest number of hosts in that network
		networkCount++;
		if(array[i+1][0] == array[i][0]){
				count++;
		}
		while(array[i+1][0] == array[i][0]){
				i++;
				count++;
				
		}
		if (count > hosts){
				largestNetwork = array[i][0];
				hosts = count;
		}
		count=0;
		if(array[i][0] < rangeTest[0]){
			i++;
		}
	}
	if (hosts == 1){
		printf("Class A has %d networks\nAll A networks have only 1 host\n", networkCount);	
	}
	else {
		printf("Class A has %d networks\nLargest A network is %hhu with %d hosts\n", networkCount, largestNetwork, hosts);
	}
	return;
}