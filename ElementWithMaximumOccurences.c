/*************************************************************************************
Element with maximum occurences - From a sequence of N integers, print the integer that
                                  repeats the most& the number of times it repeats.
                                  
Input1: 7
        1 1 2 2 3 3 3 
Output1: 3 3

Input2: 8
        2 3 1 10 1 10 1 10 
Output2: 1 3

Input3: 10
        0 -10 7 1 4 3 3 2 5 7 
Output3: 7 2                      
*************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, i, maxCount, maxNum; 
    int countTracker[201] = {};
    
    /* Read input */
    scanf("%d", &n);
    int arrOfIntegers[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arrOfIntegers[i]);
    }
    
    /* count the max number of repeatitions in sequence */ 
    maxCount = maxNum = 0;
    for(i=0; i < n; i++) {
        int number = arrOfIntegers[i] + 100;
        countTracker[number] = countTracker[number] + 1;
        if (maxCount < countTracker[number]) {
            maxCount = countTracker[number];
        }
    }
    
    /* figure out the number which repeated the most and first in 
       the sequence in case if it a tie in number or repetitions. */
    for(i = 0; i < n; i++) {
        int number = arrOfIntegers[i] + 100;
        if (countTracker[number] == maxCount) {
            maxNum = arrOfIntegers[i];
            break;
        }
    }
    
    /* print number that repeated the most and it's count */
    printf("%d %d", maxNum, maxCount);
    return 0;
}