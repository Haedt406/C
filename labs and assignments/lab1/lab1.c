#include <stdio.h> //imports stdio.h so we can use basic I/O


#define BO_TO_BTU 5.8 //defines a preprocessor statement
#define BO_TO_GAL 42

int main(void){		//main function	, no other input needed at this time so we say it is void
	double efficiency, total_BTU, gallons; //defines our local variables that will be used to compute total BTU's

	printf("Enter number of gallons of oil for house: "); //print statement
	scanf("%lf", &gallons); //scan gathers input from the user

	printf("Enter furnace efficiency: ");
	scanf("%lf", &efficiency);
	
	total_BTU = (BO_TO_BTU * (efficiency/100)) * (gallons/BO_TO_GAL); //this is our equation to calculate total BTU

	printf("BTUs delivered to house through furnace is %.2lf million.\n", total_BTU);
	

return(0); // basic return statement to end our program

}


