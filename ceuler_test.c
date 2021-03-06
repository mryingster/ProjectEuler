// -*- compile-command: "gcc -std=c99 -o ceuler_test ceuler_test.c ceuler.c -Wall -O3 -lm" -*-
// Copyright (c) 2014 Michael Caldwell

#include <stdio.h>
#include "ceuler.h"

void printTest(char name[])
{
    printf("Function: %-18s ", name);
    return;
}

int main()
{
    int number = 0;
    int count = 0;

    // Begin time tracking
    struct timeval start;
    gettimeofday(&start, NULL);

    // Test prime calculation
    printTest("isPrime()");
    for (number = 2 ; number < 1000 ; number++)
    {
        if (isPrime(number) == true)
            count++;
    }
    if (count == 168 && isPrime(104743) == true && isPrime(1) == false)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test next prime function
    printTest("nextPrime()");
    if (nextPrime(47) == 53 && nextPrime(50) == 53)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test prime sieve function
    printTest("primeSieve()");
    int primes[10000] = {};
    int max = 10000;
    primeSieve(primes, max);
    if (primes[9999] == 104729 && primes[9] == 29)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test palindromic calculation
    printTest("isPalindromic()");
    if (isPalindromic(12321) == true && isPalindromic(123456) == false)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test pandigital number
    printTest("isPandigital()");
    if (isPandigital(951628437) == true && isPandigital(123455789) == false)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test triangle number
    count = 0;
    printTest("isTriangle()");
    for (number=0 ; number<=10000; number++)
        if (isTriangle(number) == true)
            count++;
    if ( count == 140 )
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test square number
    count = 0;
    printTest("isSquare()");
    for (number=0 ; number<=10000; number++)
        if (isSquare(number) == true)
            count++;
    if ( count == 100 )
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test pentagonal number
    count = 0;
    printTest("isPentagonal()");
    for (number=0 ; number<=10000; number++)
        if (isPentagonal(number) == true)
            count++;
    if ( count == 81 )
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test hexagonal number
    count = 0;
    printTest("isHexagonal()");
    for (number=0 ; number<=10000; number++)
        if (isHexagonal(number) == true)
            count++;
    if ( count == 70 )
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test heptagonal number
    count = 0;
    printTest("isHeptagonal()");
    for (number=0 ; number<=10000; number++)
        if (isHeptagonal(number) == true)
            count++;
    if ( count == 63 )
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test octagonal number
    count = 0;
    printTest("isOctagonal()");
    for (number=0 ; number<=10000; number++)
        if (isOctagonal(number) == true)
            count++;
    if ( count == 58 )
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test digit factorial
    printTest("digitFactorial()");
    if (digitFactorial(9) == 362880 && digitFactorial(10) == 0)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test power check
    printTest("powerOf()");
    if (powerOf(2048, 2) == true && powerOf(73, 12) == false)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test Number Of Digits
    printTest("numberOfDigits()");
    if (numberOfDigits(12345678901) == 11 && numberOfDigits(0) == 1 && numberOfDigits(-11568) == 5)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test even number detection
    printTest("isEven()");
    if (isEven(10) == true && isEven(9) == false)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test greatest common denominator
    printTest("gcd()");
    if (gcd(100, 121) == 1 && gcd(5280, 22352) == 176)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test word score
    printTest("wordScore()");
    if (wordScore("ABC", 3) == 6 && wordScore("", 0) == 0)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test number signature
    printTest("numSignature()");
    if (numSignature(112233445566777) == 32222220 && numSignature(0) == 0)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test number reverse
    printTest("reverseNum()");
    if (reverseNum(123321) == 123321 && reverseNum(123456789) == 987654321)
        printf("Pass\n");
    else
        printf("Fail\n");

    // Test time tracking
    printElapsedTime(start);

    return 0;
}
