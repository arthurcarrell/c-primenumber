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
int quickNumberPrimeCheck(int numberToCheck)
{
    // simply checks if the number ends with an even number or a 5.

    // convert the int to a string
    char convertedString[20];
    snprintf(convertedString,sizeof(convertedString), "%d", numberToCheck);
    
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

int checkIfPrimeNumber(int numberToCheck)
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
    int numsToCheck[200] = {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223};
    
    for (int i=0; i <= 198; i++)
    {
        printf("Input: %d -- checkIfPrimeNumber returned: %d\n", numsToCheck[i], checkIfPrimeNumber(numsToCheck[i]));
    }

    printf("Input: %d -- checkIfPrimeNumber returned: %d\n", 2147483647, checkIfPrimeNumber(2147483647));
    return 1;
}