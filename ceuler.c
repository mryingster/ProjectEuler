#include <math.h>
#include <stdbool.h>

bool isPrime(int input)
{
    int index;
    if (input == 2) return true;

    for (index=2 ; index<input ; index++)
      if (input % index == 0)
          return false;

    return true;
}

bool isPrimeOpt(int input, int *primes)
{
    int index = 0;
    if (input == 2) return true;

    while (primes[index] != 0)
    {
        if (input % primes[index] == 0)
            return false;
        index++;
    }

    return true;
}

bool isPalindromic(int input)
{
    int decompose = input;
    int reverse = 0;

    while (decompose > 0)
    {
        reverse *= 10;
        reverse += decompose %10;
        decompose /= 10;
    }

    if ( reverse == input )
        return true;
    return false;
}

int digitFactorial(int input)
{
    switch (input)
    {
    case 0: return 1;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    case 4: return 24;
    case 5: return 120;
    case 6: return 720;
    case 7: return 5040;
    case 8: return 40320;
    case 9: return 362880;
    default: break;
    }
    return 0;
}

bool isEven(int anumber)
{
    if (anumber % 2 == 0)
        return true;
    return false;
}
