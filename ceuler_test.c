// -*- compile-command: "gcc -o ceuler_test ceuler_test.c ceuler.c -Wall -O3 -lm" -*-
// Copyright (c) 2014 Michael Caldwell

#include <stdio.h>
#include <ceuler.h>

int main()
{
    // Test prime calculation
    printf("Testing isPrime() function: ");
    if (isPrime(53) == true && isPrime(42) == false)
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

    // Test even number detection
    printf("Testing isEven() function: ");
    if (isEven(10) == true && isEven(9) == false)
        printf("Pass\n");
    else
        printf("Fail\n");

    return 0;
}
