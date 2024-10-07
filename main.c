#include <stdio.h>

// lets implement a prime number finder using only the <stdio.h> library.
// this means that booleans arent a thing, so im going to use int 0/1.
// why am I doing it in C? Because C is based. Also I hate myself...
// this is also a exercise to learn raw C because thats a huge goal for me.

// I said that I wouldnt use any other libraries, so here are some functions that do basic things.

int stringLength(char *str) // returns the length of a string
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}


// MAIN FUNCTIONS
int quickNumberPrimeCheck(unsigned long long int numberToCheck)
{
    // simply checks if the number ends with an even number or a 5.

    // convert the int to a string
    char convertedString[30];
    snprintf(convertedString,sizeof(convertedString), "%llu", numberToCheck);
    
    // convertedString is now the string equivalent of the int.
    char lastChr = convertedString[stringLength(convertedString)-1];
    
    // yes, this is cursed, but I want to avoid implementing a array find function for now. If I implement one, ill update this to use it.
    if (lastChr == '2' || lastChr == '4' || lastChr == '5' || lastChr == '6' || lastChr == '8' || lastChr == '0')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

long int checkIfPrimeNumber(unsigned long long int numberToCheck)
{
    int hasFoundFactor = 0;
    int numberToDivide = 2;
    int storedNumberToDivide = 0;
    if (!quickNumberPrimeCheck(numberToCheck)) {return 0;}
    while (!hasFoundFactor && numberToDivide < numberToCheck/2)
    {
        if (numberToDivide != numberToCheck)
        {
            hasFoundFactor = (numberToCheck % numberToDivide) == 0;
            //printf("hasFoundFactor: %d -- numberToDivide: %d\n", hasFoundFactor, numberToDivide);
            storedNumberToDivide = numberToDivide;
        }
        numberToDivide += 1;
    }
    if (hasFoundFactor) {return storedNumberToDivide;} else {return -1;}
}

int main(int argc, char *argv[])
{
    unsigned long long int checkNum = 18446744073709551615; // unsigned 64-bit largest number
    long int result = checkIfPrimeNumber(checkNum);
    if (result == -1)
    {
        printf("%llu is a prime number.\n", checkNum);
    }
    else
    {
        printf("%llu is not a prime number.\n", checkNum);
    }
    return 1;
}