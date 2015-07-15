#ifndef CEULER_H
#define CEULER_H

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <ctype.h>
#include <stdio.h>

bool isPrime(int input);
unsigned long long nextPrime(unsigned long long input);
void primeSieve(int *primes, int max);
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
int gcd(int a, int b);
int wordScore(char *word, int length);
unsigned numSignature(unsigned long long number);
unsigned long long reverseNum(unsigned long long input);
void printElapsedTime(struct timeval start);
#endif
