#include <stdio.h>

// implements the selection sort algorithm

void SelectionSort(char arr[], int size) {
	int i, j;
	char temp;
	
	for (i = 0; i < size-1; i++) {
		for (j = i+1; j < size; j++){
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {
	int n = 100
	char array[n], n1;
	
	int i = 0;
	
	while (scanf("%c%c, &array[i], &n1) == 2){
		i++;
	}
	SelectionSort(array,i);
	for (int j = 0; j < i; j++) {
		printf(" %c ", array[j]);
	}
	
	printf("\n";
	return(0);
}