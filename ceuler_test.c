// -*- compile-command: "gcc -o ceuler_test ceuler_test.c ceuler.c -Wall -O3 -lm" -*-
// Copyright (c) 2014 Michael Caldwell

#include <stdio.h>
#include <ceuler.h>

int main()
{
    int number = 0;
    int count = 0;

    // Test prime calculation
    printf("Testing isPrime() function: ");
    for (number = 2 ; number < 1000 ; number++)
    {
        if (isPrime(number) == true)
            count++;
    }
    if (count == 168 && isPrime(104743) == true)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test optimized prime calculation
    printf("Testing isPrimeOpt() function: ");
    int primeArray[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    if (isPrimeOpt(53, primeArray) == true && isPrimeOpt(42, primeArray) == false)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test palindromic calculation
    printf("Testing isPalindromic() function: ");
    if (isPalindromic(12321) == true && isPalindromic(123456) == false)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test pandigital number
    printf("Testing isPandigital() function: ");
    if (isPandigital(951628437) == true && isPandigital(123455789) == false)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test digit factorial
    printf("Testing digitFactorial() function: ");
    if (digitFactorial(9) == 362880 && digitFactorial(10) == 0)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test power check
    printf("Testing powerOf() function: ");
    if (powerOf(2048, 2) == true && powerOf(73, 12) == false)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test Number Of Digits
    printf("Testing numberOfDigits() function: ");
    if (numberOfDigits(12345678901) == 11 && numberOfDigits(0) == 1 && numberOfDigits(-11568) == 5)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test even number detection
    printf("Testing isEven() function: ");
    if (isEven(10) == true && isEven(9) == false)
        printf("Pass\n");
    else
        printf("Fail\n");

    return 0;
}
