#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char **hurricanes, int arrSize){
	char *temp = malloc(sizeof(char) *43);;
	int compValue;
	for (int i = 1; i < arrSize-1; i++){
		for (int j = 1; j < arrSize - i -1; j++){
			compValue = strncmp(hurricanes[j+1], hurricanes[j+2], 4);
				if(compValue >0){
						temp = hurricanes[j+1];
						hurricanes[j+1] = hurricanes[j+2];
						hurricanes[j+2] = temp;
				}
		}
	}
	return;
	
}


void output(FILE *out, char **hurricanes, int arrSize){
	//char *token;
	char *name;
	char *date;
	//int category;
	int catNum;
	char catChar;
	char hurrCopy[60];

	fprintf(out, "Hurricanes in Florida with category and date\n");
	fprintf(out, "____________________________________________\n");
	for (int i = 2; i < arrSize-1; i++){
		strcpy(hurrCopy, hurricanes[i]);
		name = strtok(hurrCopy, ","); 
		char *fullCat = strtok(NULL, ",");	
		//printf("%s", fullCat);
		catNum = fullCat[9];
		catChar = catNum;
		date = strtok(NULL,",");
		/*sscanf(token, "%hhu", &name);
		strtok(NULL, ",");
		sscanf(token, "%hhu", &p);
		strtok(NULL, ",");
		sscanf(token, "%hhu", &date);*/
/*		while (*p){
				if (isdigit(*p)){
					category = *p;
				}
		}*/
		fprintf(out, "%-10s\t\t%c\t%s\n", name, catChar, date);
	}
}
int main(){
	int arrSize = 38;
	char *hurricanes[arrSize];
	FILE *infptr = fopen("/public/lab4/hurricanes.csv", "r");
	if (infptr == NULL){
			printf("ERROR: could not open input file\n");
			return(0);
	}
	FILE* outpfptr = fopen("out.txt", "w");
	for (int i = 1; i < arrSize; i++){
		hurricanes[i] =  malloc(sizeof(char) *60);
		fgets(hurricanes[i], 43, infptr);
		
	}
	sort(hurricanes, arrSize);
	output(outpfptr, hurricanes, arrSize);
	fclose(infptr);
	fclose(outpfptr);
return(0);	
}


