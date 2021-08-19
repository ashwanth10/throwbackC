/*******************************************************************************
Arranging zeros - Write a program to move the zeroes in an integer array to the 
                  end of the array. The order of the non-zero elements must be 
                  preserved in the array.
                  
Input0: 10
        0 0 0 0 0 10 20 30 40 50
Output0: 10 20 30 40 50 0 0 0 0 0 

Input1: 20
        -218 628 -686 827 282 631 -322 71 -553 286 168 623 -140 587 -472 -852 -25 -17 -382 -231
Output1: -218 628 -686 827 282 631 -322 71 -553 286 168 623 -140 587 -472 -852 -25 -17 -382 -231 

Input2: 25
        0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Output2: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i, n, count;

    /* Read the input */
    scanf("%d", &n);
    int arrOfIntegers[n];    
    for(i = 0; i < n; i++) {
        scanf("%d", &arrOfIntegers[i]);
    }
    
    /* count variable for no. of non-zeros */
    count = 0;
    for(i = 0; i < n; i++) {
        if (arrOfIntegers[i] != 0) {
            arrOfIntegers[count++] = arrOfIntegers[i];
        }
    }
    
    /* place the zeros at the end of array */
    while(count < n) {
        arrOfIntegers[count++] = 0;
    }
    
    /* print the array */
    for(i = 0; i < n; i++) {
        printf("%d ", arrOfIntegers[i]);
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}