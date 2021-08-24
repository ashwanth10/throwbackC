/*************************************************************************************
Denominations of Currency - Return's the denomination of the given sum

The purpose of the program is to return the input currency with optimal denominations
like 500, 100, 50, 20, 5, 2, 1.

Input1: 9
Output: Denomination is : 500 and count is : 0
        Denomination is : 100 and count is : 0
        Denomination is : 50 and count is : 0
        Denomination is : 20 and count is : 0
        Denomination is : 10 and count is : 0
        Denomination is : 5 and count is : 1
        Denomination is : 2 and count is : 2
        Denomination is : 1 and count is : 0
*************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int denominations[8] = {500, 100, 50, 20, 10, 5, 2, 1};
    long int countOfDenominations[8] = {0};
    long int n;
    int denomPtr = 0;
    
    /* Read the currency */
    scanf("%ld", &n);
    
    /* Breakdown the given input by sub dividing into denominatios */
    while(n > 0) {
        if (n >= denominations[denomPtr]) {
           countOfDenominations[denomPtr] = n / denominations[denomPtr];
           n = n % denominations[denomPtr];
        }
        denomPtr++;
    }
    
    /* Print the denominations */
    for(int i = 0; i < 8; i++) {
        printf("Denomination is : %d and count is : %ld\n", denominations[i], countOfDenominations[i]);
    }

    return 0;
}