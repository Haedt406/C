//this function takes the given days and finds the classes on those days

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "Class.h"


void printClassGivenDay(const Class_t *classArray, const char *day){
	for(int i = 0; i < 15; i++){
		if(strcmp(classArray[i].days, day) == 0){
			printf("%-25s\t\t%s\t\t%s\t\t%s\t%s\t%s", classArray[i].title, classArray[i].ID, classArray[i].professor, classArray[i].seats, classArray[i].days, classArray[i].time);
		}
	}
	return;
}