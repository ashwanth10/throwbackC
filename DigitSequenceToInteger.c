/********************************************************************************
Digit sequence to integer - Program to convert a digit sequence to an integer

Purpose: The program takes a sequence as input and converts into an integer.
         This is done by iterating over the sequence one character at a time and 
         converting it to an integer and multiplying by 10 each time after processing
         a character.

********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 14

int main() {
    char sequence[MAX_LEN];
    
    /* get sequence from input */
    fgets(sequence, MAX_LEN, stdin);
    
    /* compute the length of sequence */
    int sequenceLen;
    sequenceLen = strlen(sequence);
    
    /* converted integer */
    long int convertedInt = 0;
    
    /* flag to check if input is valid */
    bool isValidInputFlg = true;
    
    /* covert sequence to integer */
    int i;
    for(i = 0; i < sequenceLen; i++ ) {
        convertedInt = convertedInt * 10;
        
        /* check each element of the sequence */
        int element = sequence[i];
        if (element < '0' && element > '9' ) {
            isValidInputFlg = false;
            break;
        }
        
        /* Convert to integer */
        element = element - '0';
        convertedInt = convertedInt + element;
    }
    
    /* check if input is valid */
    if (!isValidInputFlg) {
        printf("%d", -1);
    } else {
        printf("%ld", convertedInt);
    }
    
    return 0;
}