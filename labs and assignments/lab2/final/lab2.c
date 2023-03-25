#include <stdio.h> //imports stdio.h so we can use basic I/O
#include <ctype.h>

int discount(double cost, double discount);
int main(void){ //main function
	
	double cost; //initializes our variables in main funciton
	char inMilitaryChar;

	printf("Cost of purchase: \t$");  //print statement
	scanf("%lf",&cost);  //get input from user

	printf("In military (y or n)? \t");
	scanf("%s", &inMilitaryChar);
	
	if (tolower(inMilitaryChar) == 'y'){ //our if statement, starts with a base case that yes, the individual is a military member
		if(cost > 150){
			discount(cost, .15);
		}
		else{
			discount(cost, .1);
		} 
	}
	else if (tolower(inMilitaryChar) == 'n'){ // second part of the if statement, if entry is n or N then it doesnt calculate military discount in the discount function
		discount(cost, 0);
	}
	else{ //final part of the if statement, if y or n is not entered then the program exits with a value of 1, meaning not successful since in this iteration 0 is successfull
			printf("Error: bad input\n");
			return(1);
	}


return(0);
}

int discount(double cost, double discount){ //our other function as per the directions
	double militaryDiscount, salesTax;
	militaryDiscount = cost * discount;
	if(discount > 0){
		printf("Military discount (%.lf%%) $%.2lf", (discount*100) , militaryDiscount);
		cost = cost - (cost * discount); //calculates discounted total
		printf("\nDiscounted total \t$%.2lf\n", cost);
	}	
	salesTax = cost * .05; //equation for sales tax
	printf("Sales tax (5%%)     \t$%.2lf \n", salesTax);
	cost = cost + (cost * .05); //equation for final cost after discounted total if applicable
	printf("Total \t\t\t$%.2lf\n", cost);
	return(0);
}




