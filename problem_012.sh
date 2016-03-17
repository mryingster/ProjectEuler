#!/bin/bash

echo "Project Euler - Problem 12:"
echo "What is the value of the first triangle number to have over five hundred divisors?"
echo

function findDivisors() {
    n=$1
    count=1
    p=0

    while [[ $p -lt $primeIndex ]] && [[ $n -gt 1 ]]; do
        dCount=1
        while [[ $(($n % ${primes[$p]})) -eq 0 ]]; do
            n=$(($n / ${primes[$p]}))
            dCount=$(($dCount + 1))
        done
        p=$(($p + 1))
        count=$(($count * $dCount))
    done

    echo $count
}

# Generate primes up to limit
primeLimit=100
primeSeive[$primeLimit]=0
primes[0]=2
primeIndex=0
for (( i=2; i<$primeLimit; i++ )); do
    if [[ ${primeSeive[$i]} -eq \0 ]]; then
        primes[$primeIndex]=$i
        primeIndex=$(($primeIndex+1))
        for (( n=$i; n<$primeLimit; n+=$i )); do
            primeSeive[$n]=1
        done
    fi
done

divisors=1
triangle=1
n=1
while [[ $divisors -lt 500 ]]; do
    n=$(($n + 1))
    triangle=$(($triangle + n))
    [[ $((triangle % 10)) -ne 0 ]] && continue
    divisors=$(findDivisors triangle)
done

echo $triangle
