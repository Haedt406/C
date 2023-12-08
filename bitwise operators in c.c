#include <stdio.h>
#include <string.h>

// Function to print a number in binary
void print_binary(unsigned int num) {
    // bytes in num * 8 bits per byte
    for (int i = sizeof(num)*8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // Space every 8 bits for readability
    }
    printf("\n");
}

// Function to print a number in hex
void print_hex(unsigned int num) {
    // bytes in num * 8 bits per byte
    char fourBits;
    for (int i = sizeof(num)*8 - 4; i >= 0; i-= 4) {
        // push num over 
        fourBits = (num >> i) & 0xF; // mask off everything but these 4 bits
        //printf("i=%d, num >> i = %b, fourBits=%b\n", i, num >> i, fourBits);
        printf("%x    ", fourBits);

    }
    printf("\n");
}

// Function to set, clear, and toggle a bit
unsigned int modify_bit(unsigned int num, unsigned int pos, unsigned int operation) {
    switch (operation) {
        case 1: // Set bit
            return num | (1 << pos);
        case 2: // Clear bit
            return num & ~(1 << pos);
        case 3: // Toggle bit
            return num ^ (1 << pos);
    }
    return num; // In case of invalid operation
}

int main() {
    unsigned int a, b, pos, choice;

    printf("Enter two unsigned integers: ");
    scanf("%u %u", &a, &b);

    printf("\nBinary & hex representation:\n");
    printf("Number 1: \n"); print_binary(a); print_hex(a);
    printf("Number 2: \n"); print_binary(b); print_hex(b);

    printf("\nBitwise AND of Number 1 and Number 2: %u\n", a & b);
    printf("Binary & hex representation:\n");
    print_binary(a & b); print_hex(a & b);

    printf("\nBitwise OR: %u\n", a | b);
    printf("Binary & hex representation:\n");
    print_binary(a | b); print_hex(a | b);

    printf("\nBitwise XOR: %u\n", a ^ b);
    printf("Binary & hex representation:\n");
    print_binary(a ^ b); print_hex(a ^ b);

    printf("\nBitwise NOT on first number: %u\n", ~a);
    printf("Binary & hex representation:\n");
    print_binary(~a); print_hex(~a);
    printf("\nBitwise NOT on second number: %u\n", ~b);
    printf("Binary & hex representation:\n");
    print_binary(~b); print_hex(~b);

    printf("\nEnter a bit position to modify: ");
    scanf("%u", &pos);
    printf("Set, clear, or toggle (1/2/3)? ");
    scanf("%u", &choice);
    printf("Original number: %u\n", a); print_binary(a); print_hex(a);
    a = modify_bit(a, pos, choice);
    printf("Modified number: %u\n", a);
    printf("Binary & hex representation:\n");
    print_binary(a); print_hex(a);

    return 0;
}
