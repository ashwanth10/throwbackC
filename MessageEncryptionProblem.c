/*****************************************************************************
Message Encryption Problem - Crypt takes as input a message and a cipher and 
                             returns the ciphered message.
                             
Input1: abba yzxwaaabbbccccddddeeeeffff
Output1: INVALID CIPHER

Input2: abba yzxwvutsrqponmlkjihgfedcba
Output2: yzzy

Input3: abcdef zyxwvutsrqponmlkjihgfedcba
Output3: zyxwvu
*****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG_CIPHER_LEN 126
#define MAX_MSG_LEN 100
#define MAX_CIPHER_LEN 26

int main() {
    char msgAndCipher[MAX_MSG_CIPHER_LEN];
    char msg[MAX_MSG_LEN + 2];
    char cipher[MAX_CIPHER_LEN + 2];
    
    int j, msgLen, cipherLen, isInvalidCipher;
    
    /* Read the input */
    fgets(msgAndCipher, MAX_MSG_CIPHER_LEN, stdin);
    
    /* split the input using space as delimiter */
    int i = 0;
    char *array[2];
    char *ptr = strtok(msgAndCipher, " ");
    while(ptr != NULL) {
        array[i++] = ptr;
        ptr = strtok(NULL, " ");
    }
    
    /* get msg and cipher from input */
    strcpy(msg, array[0]);
    strcpy(cipher, array[1]);
    
    /* compute the length of msg and cipher */
    msgLen = strlen(msg);
    cipherLen = strlen(cipher);
    
    /* trim the newline in cipher */
    if (cipher[cipherLen - 1] == '\n') {
        cipher[cipherLen - 1] = '\0';
    }
    
    /* capture the cipher mappiing */
    isInvalidCipher = 0;
    char cipherMapping[MAX_CIPHER_LEN];
    for(i = 0; i < cipherLen; i++) {
        for(j = 0; j < i; j++) {
            if (cipherMapping[j] == cipher[i]) {
                isInvalidCipher = 1;
                break;
            }
        }
        
        if (isInvalidCipher) {
            break;
        }
        cipherMapping[i] = cipher[i];
    }
    
    /* Return if invalid cipher */
    if(isInvalidCipher) {
        printf("INVALID CIPHER");
        return 0;
    }
    
    /* cipher the message */
    for(i = 0; i < msgLen; i++) {
        printf("%c", cipherMapping[msg[i] - 'a']);
    }
    
}
}