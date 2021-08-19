/*************************************************************************

Finding Pattern in the string - A program used to find a given pattern in text

Purpose: The program prints the start index of the pattern in the given text
         by iterating and comparing each character in the pattern with the text.
         If the entire pattern is matching, only then we print the index.
         In case there is no pattern match in the text, we simply print '-1'.

Input1: ABABABBBBABDBA
       BAB
Output1: 1 3 8

Input2: XYXYYXYYXYYY
        XYYX
Output2: 2 5 

Input3: AAABCD
        ABBCD
Output3: -1
*************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 300

int main() {
    
    char text[MAX_LEN];
    char pattern[MAX_LEN];
    
    int textLen;
    int patternLen;
    int i, j;
    
    /* Get the input text and pattern from stdin */
    gets(text);
    gets(pattern);
    
    /* Compute the length of text and pattern */
    textLen = strlen(text);
    patternLen = strlen(pattern);
    
    /* Flag to check if there is atleast one match or not */ 
    bool hasAtLeastOneMatchFlg = false;
    
    /* Iterate over the text and compare each character of pattern */
    for(i = 0; i <= textLen - patternLen + 1; i++) {
        bool isMatchFlg = true;
        for(j = 0; j < patternLen; j++) {            
            if (text[i+j] != pattern[j]) {
                /* Pattern didn't match */
                isMatchFlg = false;
                break;
            }
        }
        
        /* Print the start index of the pattern in text, if it is a match */
        if (isMatchFlg == true) {
            hasAtLeastOneMatchFlg = true;
            printf("%d ", i);
        }
    } /* End of the pattern search in the text */
    
    /* Print '-1' if there is no match */
    if (!hasAtLeastOneMatchFlg) {
        printf("%d", -1);
    }
    
    return 0;
}