#ifndef CEULER_H
#define CEULER_H

#include <math.h>
#include <stdbool.h>

bool isPrime(int input);
bool isPrimeOpt(int input, int *primes);
bool isPalindromic(int input);
bool isPandigital(long number);
bool isTriangle(long long number);
bool isSquare(long long number);
bool isPentagonal(long long number);
bool isHexagonal(long long number);
bool isHeptagonal(long long number);
bool isOctagonal(long long number);
bool powerOf(long long number, int power);
int  digitFactorial(int input);
int  numberOfDigits(long long number);
bool isEven(int anumber);
int wordScore(char *word, int length);
unsigned numSignature(unsigned long long number);
#endif
