/*********************************************************************************
Trailing zeros of Factorial - Returns the number of trailing zeros for a given
                              factorial number.

Input0: 0
Output0: 0

Input1: 9
Output1: 1

Input2: 30
Output2: 7
*********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    int count = 0;
    
    /* read the input - n */
    scanf("%d", &n);
    
    /* count the number of trailing zeros using the logic of 5 */
    while(n >= 5) {
        int temp = n;
        while (temp % 5 == 0) {
            temp = temp / 5;
            count++;
        }
        n--;
    }
    
    /* print the count */
    printf("%d", count);
    
    return 0;
}
