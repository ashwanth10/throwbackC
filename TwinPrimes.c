/*************************************************************************************
Twim Primes - The program prints all the twin primes between the given range.

Input1: 100 200
Output1: (101 103)(107 109)(137 139)(149 151)(179 181)(191 193)(197 199)

Input2: 3 7
Output2: (3 5)(5 7)

Input3: 313 347
Output3: (# #)
*************************************************************************************/

#include <stdio.h>
#include <math.h>

/* return's 1 if the number is prime */
int PrimeTest(int number) {
    if (number == 2 || number == 3) {
        return 1;
    } else if (number % 2 == 0) {
        return 0;
    }
    
    for(int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) 
            return 0;
    }
    return 1;
}

/* Prints the co-prime numbers in the range */
void TwinPrimes(int range1, int range2) {
    int count = 0;
    int i = range1;
    while(i+2 <= range2) {
        if(PrimeTest(i) && PrimeTest(i+2)) {
            printf("(%d %d)", i, i+2);
            count++;
        }
        i = i+1;
    }
    
    if (count == 0) {
        printf("(# #)");
    }
}

int main() 
{
	int range1, range2;
	scanf ("%d %d", &range1, &range2);
	TwinPrimes(range1, range2);
	return 0;
}