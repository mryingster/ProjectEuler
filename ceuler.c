#include <math.h>
#include <stdbool.h>

bool isPrime(int input)
{
    int index;
    int search = sqrt(input);

    if (input == 2) return true;
    if (input % 2 == 0) return false;

    for (index=3 ; index<=search ; index+=2)
      if (input % index == 0)
          return false;

    return true;
}

bool isPrimeOpt(int input, int *primes)
{
    int index = 0;
    if (input == 2) return true;

    while (primes[index] != 0 && primes[index] <= sqrt(input))
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

bool isPandigital(long number)
{
    bool digits[10] = {false};
    int count = 0;

    // Decompose number
    while (number > 0)
    {
        short digit = number % 10;
        if ( digits[digit] == true )
            return false;
        digits[digit] = true;
        number /= 10;
        count++;
    }

    // Reject numbers larger than 10 digits
    if (count > 10) return false;

    // Include 0 in check of 10 digit numbers
    short start = 1;
    if (count == 10)
    {
        start = 0;
        count = 9;
    }

    // Check that each digit is used once
    short index;
    for (index = start ; index <= count ; index++ )
    {
        if ( digits[index] == false )
            return false;
    }
    return true;
}

bool isTriangle(long long number)
{
    if (number == 0) return false;
    long double check = (sqrt(8*number+1)-1)/2;
    if (check == (long long)check) return true;
    return false;
}

bool isSquare(long long number)
{
    if (number == 0) return false;
    long double check = sqrt(number);
    if (check == (long long)check) return true;
    return false;
}

bool isPentagonal(long long number)
{
    long double check = (sqrt(24*number+1)+1)/6;
    if (check == (long long)check) return true;
    return false;
}

bool isHexagonal(long long number)
{
    long double check = (sqrt(8*number+1)+1)/4;
    if (check == (long long)check) return true;
    return false;
}

bool isHeptagonal(long long number)
{
    long double check = (sqrt(40*number+9)+3)/10;
    if (check == (long long)check) return true;
    return false;
}
bool isOctagonal(long long number)
{
    long double check = (sqrt(3*number+1)+1)/3;
    if (check == (long long)check) return true;
    return false;
}

bool powerOf(long long number, int power)
{
    while ( number > 1 )
    {
        if (number % power == 0)
            number /= power;
        else
            return false;
    }
    return true;
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

int numberOfDigits(long long number)
{
    if (number == 0) return 1;
    if (number <  0) number *= -1;
    int digits = floor(log10(number))+1;
    return digits;
}

bool isEven(int anumber)
{
    if (anumber % 2 == 0)
        return true;
    return false;
}

int wordScore(char *word, int length)
{
    int index, score = 0;
    for (index=0; index<length; index++)
    {
        if (word[index] == '\0') break;
        //If upper case
        if (word[index] >= 'A' && word[index] <= 'Z')
        {
            score += word[index] - 'A' + 1;
            continue;
        }

        //If lower case
        if (word[index] >= 'a' && word[index] <= 'z')
        {
            score += word[index] - 'a' + 1;
            continue;
        }
        // out of range
        continue;
    }
    return score;
}

unsigned numSignature(unsigned long long number)
{
    unsigned out = 0;
    while (number > 0)
    {
        out += 1 * pow(10, number % 10);
        number /= 10;
    }
    return out;
}

unsigned long long reverseNum(unsigned long long input)
{
    unsigned long long output = input;
    int count = 0;

    while (output > 0)
    {
        output /= 10;
        count++;
    }

    while (input > 0)
    {
        output += input % 10 * pow(10, --count);
        input /= 10;
    }

    return output;
}
