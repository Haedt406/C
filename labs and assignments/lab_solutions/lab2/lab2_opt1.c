#include <stdio.h>
#include <math.h>

#define COST_THRESHOLD 150.0
#define LOW_DISCOUNT .1
#define HIGH_DISCOUNT .15
#define NO_DISCOUNT 0.0
#define TAX .05

// computes the discount for the military based on amount spent
double computeDiscount(double cost, char mil) {
    if (mil == 'Y' || mil == 'y') {
        if (cost < COST_THRESHOLD) {
            return LOW_DISCOUNT;
        }
        else {
            return HIGH_DISCOUNT;
        }
    }
    else {
        return NO_DISCOUNT;
    }
}

void printInfo(double cost, char mil) {
    double discount,    // percentage of discount for teachers
           tax,         // 5% tax to be added to purchase price
           disc_value;  // amount of discount with percentage applied

    discount = computeDiscount(cost, mil);

    if (discount != NO_DISCOUNT) {
        disc_value = discount * cost;
        
        cost -= disc_value;
        printf("Military discount (%d%%)\t\t$%.2lf\n", 
                 (int)(discount*100), disc_value);
        printf("Discounted total\t\t$%.2lf\n", cost);
    }
    
    tax = cost * .05;

    printf("Sales tax (5%%)\t\t\t$%.2lf\n", tax);
    printf("Total\t\t\t\t$%.2lf\n", (cost+tax));
    return;
}
    
int main(void) {
    double cost;  // amount of items purchased
    char answer;  // is the customer in the military or not

    // read in inputs
    printf("Cost of purchase:\t\t$");
    scanf("%lf", &cost);
    printf("In military (y or n)?\t\t");
    scanf(" %c", &answer);

    // check for incorrect answer
    if (answer != 'y' && answer != 'Y' && answer != 'n' &&
        answer != 'N') {
        printf("Error: bad input\n");
        return(1);
    }

    printInfo(cost, answer);

    return(0);
}
