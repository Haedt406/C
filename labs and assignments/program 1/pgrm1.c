#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include <string.h>

void classA(const unsigned char array[][4]){
	int count = 0;
	int hosts = 1;
	int i = 0;
	char largestNetwork;
	int networkCount = 0;
	unsigned char range[1] = {127};
	unsigned char rangeTest[1] = {128};
	while(array[i][0] <= range[0]){
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
//	printf("I after main loop %d\n", i);
//	printf("on next array %d\n", array[i][0]);
//	if(array[i-1][0] == array[i][0]){
////		networkCount--;
//	}
	if (hosts == 1){
		printf("Class A has %d networks\nAll A networks have only 1 host\n", networkCount);	
	}
	else {
		printf("Class A has %d networks\nLargest A network is %hhu with %d hosts\n", networkCount, largestNetwork, hosts);
	}
	return;
}


void classB(const unsigned char array[][4]){
	int count = 0;
	int hosts = 1;
	int i = 0;
	unsigned char largestNetwork[2];
	int networkCount = 0;

	unsigned char rangeLower[1] = {128};
	unsigned char rangeUpper[1] = {191};
	unsigned char rangeTest[1] = {192};
	
	while(array[i][0] < rangeLower[0]){
			i++;
	}
//	printf("I before main loop %d\n", i);
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
//		printf("I after main loop %d\n", i);
//	printf("on next array %d\n", array[i][0]);
//	if(array[i-1][0] == array[i][0]){
//		networkCount--;
//	}
	if (hosts == 1){
		printf("Class B has %d networks\nAll B networks have only 1 host\n", networkCount);	
	}
	else {
		printf("Class B has %d networks\nLargest B network is %hhu.%hhu with %d hosts\n", networkCount, largestNetwork[0], largestNetwork[1], hosts);
	}
	return;
}


void classC(const unsigned char array[][4]){
	int count = 0;
	int hosts = 1;
	int i = 0;
	unsigned char largestNetwork[3];
	int networkCount = 0;

	unsigned char rangeLower[1] = {192};
	unsigned char rangeUpper[1] = {223};
	unsigned char rangeTest[1] = {224};
	while(array[i][0] < rangeLower[0]){
			i++;
	}
//	printf("I before main loop %d\n", i);
	while(array[i][0] <= rangeUpper[0]){
	
		networkCount++;
		//printf("C NETWORK %hhu.%hhu.%hhu with\n",  array[i][0], array[i][1], array[i][2]);
		if(array[i+1][0] == array[i][0] && array[i+1][1] == array[i][1] && array[i+1][2] == array[i][2]){
				count++;
		}
		while(array[i+1][0] == array[i][0] && array[i+1][1] == array[i][1] && array[i+1][2] == array[i][2]){
				i++;
				count++;		
		}
		if (count > hosts){
				largestNetwork[0] = array[i][0];
				largestNetwork[1] = array[i][1];
				largestNetwork[2] = array[i][2];
				hosts = count;
		}
		count=0;
		if(array[i][0] < rangeTest[0]){
		i++;
		}
	}
//		printf("I after main loop %d\n", i);
//	printf("on next array %d\n", array[i][0]);
//	if(array[i-1][0] == array[i][0]){
//		networkCount--;
//	}
	if (hosts == 1){
		printf("Class C has %d networks\nAll C networks have only 1 host\n", networkCount);	
	}
	else {
		printf("Class C has %d networks\nLargest C network is %hhu.%hhu.%hhu with %d hosts\n", networkCount, largestNetwork[0], largestNetwork[1], largestNetwork[2],hosts);
	}
	return;
}


void sort(unsigned char array[][4], int length){
	char temp0;
	char temp1;
	char temp2;
	char temp3;
	for(int i = 0; i < length - 1; i++){
		for(int j = i+1; j < length; j++){
			if(array[i][0] > array[j][0]){
				temp0 = array[i][0];
				temp1 = array[i][1];
				temp2 = array[i][2];
				temp3 = array[i][3];
				array[i][0] = array[j][0];
				array[i][1] = array[j][1];
				array[i][2] = array[j][2];
				array[i][3] = array[j][3];
				array[j][0] = temp0;
				array[j][1] = temp1;
				array[j][2] = temp2;
				array[j][3] = temp3;
			}
			else if(array[i][0] == array[j][0]){
				if(array[i][1] > array[j][1]){
					temp1 = array[i][1];
					temp2 = array[i][2];
					temp3 = array[i][3];
					array[i][1] = array[j][1];
					array[i][2] = array[j][2];
					array[i][3] = array[j][3];
					array[j][1] = temp1;
					array[j][2] = temp2;
					array[j][3] = temp3;
				}
				else if(array[i][1] == array[j][1]){
					if(array[i][2] > array[j][2]){
						temp2 = array[i][2];
						temp3 = array[i][3];
						array[i][3] = array[j][3];
						array[j][3] = temp3;
					}
					else if(array[i][2] == array[j][2]){
						if(array[i][3] > array[j][3]){
							temp2 = array[i][2];
							temp3 = array[i][3];
							array[i][3] = array[j][3];
							array[j][3] = temp3;
						}
					}
				}
			}
		}
	}
}


int main(int argc, char** argv){
	if(argc != 2){
		printf("ERROR: NEED NUMBER OF LINES FOLLOWED BY THE INPUT FILE, EX. ./program1 17 inp17.txt");
		return 0;
	}
//	printf("%s", argv[1]);
	long length = strtol(argv[1], &argv[2], 10);	
	if (length == 0){
		printf("ERROR: NEED NUMBER OF ARGUMENTS");
		return 0;
	}	
	printf("running %s with %ld addresses\n", argv[0],length);
//	printf("%ld", length);
	unsigned char array[length][4];
	int  i;
	for (i = 0; i < length; i++){
		scanf("%hhu.%hhu.%hhu.%hhu", &array[i][0], &array[i][1], &array[i][2], &array[i][3]);
//		printf("%hhu.%hhu.%hhu.%hhu\n",array[i][0],array[i][1],array[i][2],array[i][3]);
	}
	
	sort(array, length);
	classA(array);
	classB(array);
	classC(array);
/*	for (i = 0; i < length; i++){
	printf("%hhu.%hhu.%hhu.%hhu\n", array[i][0],array[i][1], array[i][2],array[i][3]);
	}*/
}


