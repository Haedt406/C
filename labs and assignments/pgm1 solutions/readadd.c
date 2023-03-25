#include <stdio.h>
#include <stdlib.h>

void ReadAddresses(unsigned char adds[][4], int n) {

    int i = 0;
    while (scanf("%hhu.%hhu.%hhu.%hhu", &adds[i][0],
                                &adds[i][1],
                                &adds[i][2],
                                &adds[i][3]) == 4) {
        ++i;
    }
    if (i != n) {
        perror("ERROR: wrong number of addresses provided\n");
        exit(1);
    }
    return;
}

