#include <stdio.h>

// constants - BTUs in a barrel of oil and the size of a barrel of oil
#define Barrel_BTU 5800000
#define Barrel_Size 42

// This program will compute the amount of BTUs delivered to a house
// for heat given the number of gallons of oil used to heat the house
// and the efficiency of the furnace

int main(void) {
    
    int oil_gallons, eff_percent;

    double btus_house;

    // read in inputs
    printf("Enter number of gallons of oil for house: ");
    scanf("%d", &oil_gallons);

    printf("Enter furnace efficiency: ");
    scanf("%d", &eff_percent);

    // Must determine BTUs in given number of gallons and then
    // multiply that by the efficiency percentage of the furnace

    btus_house = ((((double)oil_gallons/(double)Barrel_Size) * Barrel_BTU) * 
                    (eff_percent/100.0))/1000000.0;   

    printf("BTUs delivered to house through furnance is %.2lf million\n",
            btus_house);

    return(0);
}
