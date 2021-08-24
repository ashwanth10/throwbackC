/*************************************************************************************
Palindrome Sequences - Takes n palindromes from input and prints whether the given
                       string is palindrome or not.
                       
Input:  4
        a
        bb
        ccc
        dddd
        
Output: YES
        YES
        YES
        YES
        Number of Palindromes: 4
*************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 1000

/* 
* IsPalindrome - returns 1 if the given string is palindrome
*                otherwise returns 0.
*/
int IsPalindrome(char *str) {
    for(int i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if(str[i] == str[j]) {
            continue;
        } else {
            return 0;
        }
    }
    return 1;
}

/*
* Strip - Strip's the leading and trailing spaces.
*/
char* Strip(char *str) {
    size_t size = strlen(str);
    if (!size) {
       return str; 
    }
    
    /* Strip spaces at the end of sentence */
    char* end = str + size - 1;
    while (end >= str && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';
    
    /* Strip spaces at the beginning of sentence */
    while (*str && isspace(*str)) {
        str++;
    }
    
    return str;
}


int main() {

    /* read n from stdin */
    char buf[MAX_LEN];
    fgets(buf, MAX_LEN, stdin);
    int n = atoi(buf);
    
    /* read the n input strings */
    char input[n][MAX_LEN];
    for(int i = 0; i < n; i++) {
        fgets(input[i], MAX_LEN, stdin);
    }
    
    /* Count the palindromes */
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(IsPalindrome(Strip(input[i]))) {
            printf("YES\n");
            count++;
        } else {
            printf("NO\n");
        }
    }
    
    /* print the number of palidromes */
    printf("Number of Palindromes: %d", count);
    
    return 0;
}