/********************************************************************************
Divisible Sum Pairs - This program returns the number of pairs whose sum is
                      divisible by the given 'k'.
                      
Input0: 2 2
        8 10 
Output0: 1

Input1: 5 2
        5 9 10 7 4
Output1: 4

********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Number of elements in ar */
    int n;
    
    /* Integer divisor */
    int k;
    
    /* Read the input */
    scanf("%d", &n);
    scanf("%d", &k);
    
    /* Read the input array and store */
    int arrOfIntegers[n];
    int i, j;
    for(i = 0; i < n; i++) {
        scanf("%d", &arrOfIntegers[i]);
    }
    
    int count = 0;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            /* Compute the sum and check if it is divisble by given k */
            int sum = arrOfIntegers[i] + arrOfIntegers[j];
            if ((sum % k) == 0) {
                ++count;
            }
        }
    }
    
    printf("%d", count);
    
    return 0;
}
