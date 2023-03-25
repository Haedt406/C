#include <stdio.h>
#include <stdlib.h>

void PrintClassInfo(unsigned char adds[][4], int n) {

    // holds start and stop numbers of addresses in 
    // network class
    int class_starts[] = {0, 128, 192};
    int class_ends[] = {127, 191, 223};
 
    int Anum_largest_hosts = 1,
        Bnum_largest_hosts = 1,
        Cnum_largest_hosts = 1,
        Acur_num_hosts = 1,
        Bcur_num_hosts = 1,
        Ccur_num_hosts = 1;
   

    int Anum = 0, Bnum = 0, Cnum = 0; // number of 
                                      // networks in the class

    unsigned char Alargest_net = 0,
                  Blargest_net[2] = {0, 0},
                  Clargest_net[3] = {0, 0, 0};

    // for each class determine the number of networks 
    // in the class and largest number of hosts in a 
    // network in that class also save that network
    for (int i = 0; i < n; ++i) {
        // working with the A class
        if (class_starts[0] <= adds[i][0] &&
            adds[i][0] <= class_ends[0]) {
            
            if ((i == 0) || 
                    (i != 0 && adds[i][0] != adds[i-1][0])) {
                // increase number of networks in A class
                ++Anum;
                Acur_num_hosts = 1;
            }
            else {
                ++Acur_num_hosts;
                if (Anum_largest_hosts < Acur_num_hosts) {
                    Anum_largest_hosts = Acur_num_hosts;
                    Alargest_net = adds[i][0];
                }
            }
        }
        // working with B class
        else if (class_starts[1] <= adds[i][0] &&
                 adds[i][0] <= class_ends[1]) {
            if (adds[i][0] != adds[i-1][0] || 
                 adds[i][1] != adds[i-1][1]) {
                // increase number of networks in B class
                ++Bnum;
                Bcur_num_hosts = 1;
            }
            else {
                ++Bcur_num_hosts;
                if (Bnum_largest_hosts < Bcur_num_hosts) {
                    Bnum_largest_hosts = Bcur_num_hosts;

                    Blargest_net[0] = adds[i][0];
                    Blargest_net[1] = adds[i][1];
                }
            }
        }
        // working with C class
        else if (class_starts[2] <= adds[i][0] &&
                 adds[i][0] <= class_ends[2]) { 
            if (adds[i][0] != adds[i-1][0] || 
                 adds[i][1] != adds[i-1][1] || 
                 adds[i][2] != adds[i-1][2]) {

                // increase number of networks in C class
                ++Cnum;
                Ccur_num_hosts = 1;
            }
            else {
                ++Ccur_num_hosts;
                if (Cnum_largest_hosts < Ccur_num_hosts) {
                    Cnum_largest_hosts = Ccur_num_hosts;
                    Clargest_net[0] = adds[i][0];
                    Clargest_net[1] = adds[i][1];
                    Clargest_net[2] = adds[i][2];
                }
            }
        }
    }

    // Print A class info
    printf("Class A has %d networks\n", Anum);
    if (Anum_largest_hosts != 1) {
        printf("Largest A network is %hhu with %d hosts\n",
                Alargest_net, Anum_largest_hosts);
    }
    else {
        if (Anum != 0) {
            printf("All A networks have only one host\n");
        }
    }
    // Print B class info
    printf("Class B has %d networks\n", Bnum);
    if (Bnum_largest_hosts != 1) {
        printf("Largest B network is %hhu.%hhu with %d hosts\n",
                Blargest_net[0], Blargest_net[1], 
                Bnum_largest_hosts);
    }
    else {
        if (Bnum != 0) {
            printf("All B networks have only one host\n");
        }
    }
    // Print C class info
    printf("Class C has %d networks\n", Cnum);
    if (Cnum_largest_hosts != 1) {
        printf("Largest C network is %hhu.%hhu.%hhu with %d hosts\n",
             Clargest_net[0], Clargest_net[1], Clargest_net[2],
             Cnum_largest_hosts);
    }
    else {
        if (Cnum != 0) {
            printf("All C networks have only 1 host\n");
        }
    }

    return;
}
