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
	while(array[i][0] <= rangeUpper[0]){
	
		networkCount++;
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
	if (hosts == 1){
		printf("Class C has %d networks\nAll C networks have only 1 host\n", networkCount);	
	}
	else {
		printf("Class C has %d networks\nLargest C network is %hhu.%hhu.%hhu with %d hosts\n", networkCount, largestNetwork[0], largestNetwork[1], largestNetwork[2],hosts);
	}
	return;
}