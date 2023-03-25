//this function takes the class number and finds it in the struct array


#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "Class.h"

void printClassGivenNumber(const Class_t *classArray, const char *classID){
	for(int i = 0; i < 15; i++){
		if(strcmp(classArray[i].ID, classID) == 0){
			printf("%-25s\t\t%s\t\t%s\t\t%s\t%s\t%s", classArray[i].title, classArray[i].ID, classArray[i].professor, classArray[i].seats, classArray[i].days, classArray[i].time);
			return;
		}
	}
	printf("Class '%s' cannot be found, please try again\n\n", classID);
	return;
}