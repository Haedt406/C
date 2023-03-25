#include <stdio.h>
#include <stdlib.h>

void SortAddresses(unsigned char adds[][4], int n) {

    // sort the addresses and put in the original array
    
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (adds[i][0] > adds[j][0] ||
               (adds[i][0] == adds[j][0] && 
                adds[i][1] > adds[j][1]) ||
               (adds[i][0] == adds[j][0] && 
                adds[i][1] == adds[j][1] &&
                adds[i][2] > adds[j][2]) ||
               (adds[i][0] == adds[j][0] && 
                adds[i][1] == adds[j][1] &&
                adds[i][2] == adds[j][2] && 
                adds[i][3] < adds[j][3])) {

                // swap the two addresses
                unsigned char temp;
                for (int k = 0; k < 4; ++k) {
                    temp = adds[i][k];
                    adds[i][k] = adds[j][k];
                    adds[j][k] = temp;
                }
            }
        }
    }
    return;
}
