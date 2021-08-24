/*************************************************************************************
Ramanujan and squares - Find the count of square numbers between two given numbers.

Input: 2
       3 9
       17 24
Output: 2
        0
*************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    float a, b;
    
    /* read input */
    scanf("%d", &n);
    int count[n];
    
    /* count the squares between a and b */
    for(int i = 0; i < n; i++) {
        scanf("%f %f", &a, &b);
        a = ceil(sqrt(a));
        b = floor(sqrt(b));
        count[i] = (b - a) >= 0 ? (b - a + 1) : 0;
    }
    
    /* print the count between each a and b */
    for(int i = 0; i < n; i++) {
        printf("%d\n", count[i]);
    }
    
    return 0;
}
