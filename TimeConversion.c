/*************************************************************************************
Time Conversion - Convert 12 hour format time to 24 hour format.

Input:     07:05:45PM
Output:    19:05:45

Input:     12:40:22AM
Output:    00:40:22
*************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 1000

int main() {
    /* Read input */
    char input[MAX_LEN];
    fgets(input, MAX_LEN, stdin);
    
    /* Extract AM or PM */
    char buf[3] = { input[strlen(input) - 2], input[strlen(input) - 1], '\0' };
    
    /* Trim last two characters as we extracted AM or PM */
    input[strlen(input)-2] = '\0';
    
    /* Split the time and save hours, minutes and seconds */
    char *token = strtok(input, ":");
    char *time[3];
    int count = 0;
    while(token != NULL) {
        time[count++] = token;
        token = strtok(NULL, ":");
    }
    
    /* Convert to 24 hour format */
    int hour = atoi(time[0]);
    if(strcmp(buf, "AM") == 0) {
        if (hour == 12) {
            hour = 0;
        }
    } else if (hour != 12) {
        hour = hour + 12;
    }
    
    /* Print time in 24 hour format */
    printf("%02d:%s:%s", hour, time[1], time[2]);
    
    return 0;
}
