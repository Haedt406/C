//this function takes a professor and finds each class they teach


#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "Class.h"


void printClassGivenProf(const Class_t *classArray, const char *prof){
	char *token = malloc(sizeof(char) *30);
	char *tokenVal;
	for(int i = 0; i < 15; i++){
		strcpy(token, classArray[i].professor);
		tokenVal = strtok(token, " ");
		if(strcmp(tokenVal, prof) == 0){
			printf("%-25s\t\t%s\t\t%s\t\t%s\t%s\t%s", classArray[i].title, classArray[i].ID, classArray[i].professor, classArray[i].seats, classArray[i].days, classArray[i].time);
		}
	}
	return;
}