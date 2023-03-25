#include <stdio.h> //imports stdio.h so we can use basic I/O
#include <ctype.h>
int main(void){ //main function
	
	double militaryDiscount, cost, salesTax; //initializes our variables
	char inMilitaryChar;

	printf("Cost of purchase: \t$");  //print statement
	scanf("%lf",&cost);  //get input from user

	printf("In military (y or n)? \t");
	scanf("%s", &inMilitaryChar);
	
	if (tolower(inMilitaryChar) == 'y'){ //our if statement, starts with a base case that yes, the individual is a military member
		if(cost > 150){
			militaryDiscount = cost * .15;
			printf("Military discount (15%%) $%.2lf" , militaryDiscount);
			cost = cost - (cost * .15); //calculates discounted total
			printf("\nDiscounted total \t$%.2lf\n", cost); 
		}
		else{
			militaryDiscount = cost * .1;
			printf("Military discount (10%%) $%.2lf", militaryDiscount);
			cost = cost - (cost * .1);
			printf("\nDiscounted total \t$%.2lf\n", cost);
		} 
	}
	else if (tolower(inMilitaryChar) != 'n'){ // second part of the if statement, if a invalid entry is entered it gives error messsage and exits program
		printf("Error: bad input\n");
		return(1);
	}

	salesTax = cost * .05; //equation for sales tax

	printf("Sales tax (5%%)     \t$%.2lf \n", salesTax);
	cost = cost + (cost * .05); //equation for final cost after discounted total if applicable

	printf("Total \t\t\t$%.2lf\n", cost);
return(0);
}




