#include <stdio.h>
#include <stdlib.h>

void ReadAddresses(unsigned char[][4], int);
void SortAddresses(unsigned char[][4], int);
void PrintClassInfo(unsigned char[][4], int);

int main(int argc, char** argv) {

    if (argc != 2) {
        perror("ERROR: Did not provide number of addresses\n");
        return(1);
    }

    int num_adds = atoi(argv[1]);

    // printf("num_adds is %d\n", num_adds);
    unsigned char addresses[num_adds][4];

    printf("size of unsigned char is %lu\n", sizeof(unsigned char));
    // read in the addresses
    ReadAddresses(addresses, num_adds);

    // printf("before sort\n");
    // sort addresses
    SortAddresses(addresses, num_adds);
    /* for (int i = 0; i < num_adds; ++i) {
        printf("%hhu.%hhu.%hhu.%hhu\n", addresses[i][0],
            addresses[i][1], addresses[i][2], addresses[i][3]);
    } */

    // printf("before printinfo\n");
    // print number of each class of network and number of hosts in each
    PrintClassInfo(addresses, num_adds);
    // printf("done\n");
    return(0);
}
