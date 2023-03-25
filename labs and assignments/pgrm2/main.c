//made by Benjamin Haedt, CSCI112, Fall 2020 semester
//this program takes data from a CSV file and puts the data in a struct I called class, 
// from there we can use that data to read from and do what we want with the data in its own structure
//"creates a program that reads in a list of CSCI classes from a flie. store the list in an array of data structures. Allow the user(a student) to have the following options:
// 1) print a class given a CSCI number
// 2) print all classes available on MWF or available on TR.
// 3) print all classes taught given by a particular professor's last name
// 4) quit"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "Class.h"

void printClassGivenDay(const Class_t*, const char*);
void printClassGivenNumber(const Class_t*, const char*);
void printClassGivenProf(const Class_t*, const char*);

int main(){
	char input = 'x';
	int size = 15;
	Class_t classArray[size];
	char *temp = malloc(sizeof(char) *95);
	char *classID = malloc(sizeof(char) *9);
	char *classDays = malloc(sizeof(char)*3);
	char *prof = malloc(sizeof(char)*11);
	FILE *infptr = fopen("/public/pgm2/classes.csv", "r");

	if (infptr == NULL){
			printf("ERROR: could not open input file\n");
			return(0);
	}
	
	for (int i = 0; i < size; i++){
		fgets(temp, 95, infptr);
		classArray[i].ID = malloc(sizeof(char) *9);
		classArray[i].title = malloc(sizeof(char) *30);
		classArray[i].seats = malloc(sizeof(char) *4);
		classArray[i].professor = malloc(sizeof(char) *30);
		classArray[i].days = malloc(sizeof(char) *4);
		classArray[i].time = malloc(sizeof(char) *10);
		strcpy(classArray[i].ID, strtok(temp, ","));
		strcpy(classArray[i].title, strtok(NULL, ","));
		strtok(NULL, ",");
		strcpy(classArray[i].seats, strtok(NULL, ","));
		strtok(NULL, ",");
		strtok(NULL, ",");
		strcpy(classArray[i].professor, strtok(NULL, ","));
		strcpy(classArray[i].days, strtok(NULL, " "));
		strcpy(classArray[i].time, strtok(NULL, " "));		
	}
	while(input != 'q'){
	printf("Choices:\nn - print class given number\nd - print all classes for a given day combo\np - print all classes for a given professor\nq - quit\n");
	scanf("%c%*c", &input);
	switch(input){
		case 'n':
			printf("Enter class number: ");
			scanf("%9[0-9a-zA-Z ]%*c", classID);
			printClassGivenNumber(classArray, classID);
			break;
		case 'd': 
			printf("Enter class days to print (MWF or TR): ");
			scanf("%3[a-zA-Z]%*c", classDays);
			printClassGivenDay(classArray, classDays);
			break;
		case 'p': 
			printf("Enter Professor's Last Name: ");
			scanf("%10[a-zA-Z]%*c", prof);
			printClassGivenProf(classArray, prof);
			break;
		case 'q': 
			break;
		default: printf("Please enter a valid choice from the list\n\n");
			break;
	}		
	}	
return 1;	
}
