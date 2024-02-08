// Austin Yelle
// Chpt2 PA

#include <stdio.h>


int power(int base, int exponent) {
    
    if (exponent == 1)
        return base;
   
    else
        return base * power(base, exponent - 1);
}

int main() {
    int base, exponent;

    // Prompts the user to input the base
    printf("Enter the base: ");
    // Reads the base value from the input
    scanf("%d", &base);

    // Prompts the user to input the exponent
    printf("Enter exponent: ");
    // Reads the exponent value from input
    scanf("%d", &exponent);

    // Calculates and prints the result
    printf("Value is %d\n", power(base, exponent));

    return 0;
}