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
    float x, reqAccuracy, accuracy, oldVal, newVal, previousVal, i, sign;
    
    /* Read the input */
    scanf("%f", &x);
    
    /* Compute newvalue till the accuracy holds true */
    oldVal = previousVal = x;
    reqAccuracy = i = 1;
    sign = -1;
    do {
        previousVal = (previousVal * x * x) / ((i + 1) * (i + 2));
        newVal = oldVal + sign * previousVal;
        i = i + 2;
        sign = sign * -1;
        accuracy = AbsVal(oldVal - newVal) / AbsVal(oldVal) * 100.0;
        oldVal = newVal;
    } while(accuracy > reqAccuracy);
    
    /* Print upto 4 decimal places */
    printf("%.4f", newVal);
}