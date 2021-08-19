/**********************************************************************************
Exponential exploration - The program is used to compute e power x upto a given
                          accuracy.
                          
Input: 1 0.01
Output: 2.7183
**********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* AbsVal - returns the absolute value of a variable */
float AbsVal(float a) {
    if (a < 0.0) {
        return a * -1.0;
    }
    return a;
}

int main() {
    float x, reqAccuracy, accuracy, oldVal, newVal, previousVal;
    int i;
    
    /* Read the input */
    scanf("%f%f", &x, &reqAccuracy);
    
    /* Compute newvalue till the accuracy holds true */
    oldVal = 1;
    newVal = 1;
    previousVal = 1;
    i = 1;
    do {
        oldVal = newVal;
        previousVal = previousVal * x / i;
        newVal = oldVal + previousVal;
        i++;
        accuracy = AbsVal(oldVal - newVal) / AbsVal(oldVal) * 100.0;
    } while(accuracy > reqAccuracy);
    
    /* Print upto 4 decimal places */
    printf("%.4f", newVal);
}