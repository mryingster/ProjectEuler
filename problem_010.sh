#!/bin/bash

echo "Project Euler - Problem 10"
echo "Find the sum of all the primes below two million."
echo

limit=2000000
sum=0

# Generate primes up to sqrt of 2000000
primeLimit=$(echo "scale=0;sqrt($limit*2)" | bc) # To validate prime n, only need to check divisibility up to sqrt(n)
primes[$primeLimit]=0                            # Prime table for our seive function
primeList[0]=2                                   # Array of primes for finding more primes later
primeListSquared[0]=4                            # Array for squared primes to minimize limit calculation later
primeIndex=0                                     # Index for recording found primes
for (( i=2; i<$primeLimit; i++ )); do
    if [[ ${primes[$i]} -eq \0 ]]; then
        sum=$(($sum+$i))
        primeList[$primeIndex]=$i
        primeListSquared[$primeIndex]=$i*$i
        primeIndex=$(($primeIndex+1))
        for (( n=$i; n<$primeLimit; n+=$i )); do
            primes[$n]=1
        done
    fi
done

# Make sure primeLimit is an odd number
[[ $(($primeLimit % 2)) -eq 0 ]] && primeLimit=$(($primeLimit + 1))

# Use known primes to check all remaining numbers up to limit
for (( i=$primeLimit; i<$limit; i+=2 )); do
    prime=1
    for (( p=0; ${primeListSquared[$p]}<=$i; p++ )); do
        if [[ $(($i % ${primeList[$p]})) -eq 0 ]]; then
            prime=0
            break
        fi
    done
    # Record!
    if [[ $prime -eq 1 ]]; then
        sum=$(($sum+$i))
    fi
done

echo $sum
