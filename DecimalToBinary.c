/**************************************************************************************
Decimal to binary - Program which converts a positive decimal input to binary format.

Input1: 0
Output1: 0

Input2: 4
Output: 100
**************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_BINARY_LEN 14

int main() {

    int n, count, rem;
    int binaryFormat[MAX_BINARY_LEN];
    
    /* read the decimal number from stdin */
    scanf("%d", &n);

    /* convert to binary */
    rem = count = 0;
    while(n > 0) {
        rem = n % 2;
        binaryFormat[count++] = rem;
        n /= 2;
    }
    
    /* print the binary format */
    if (count == 0) {
        printf("%d", 0);
    }
    
    for(int i = count - 1; i >= 0; i--) {
        printf("%d", binaryFormat[i]);
    }
    
    return 0;
}
