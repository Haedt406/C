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