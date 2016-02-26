#!/bin/bash

echo "Project Euler - Problem 10"
echo "Find the sum of all the primes below two million."
echo

limit=2000000

# Generate primes up to sqrt of limit
primeLimit=$(echo "scale=0;sqrt($limit*2)" | bc) # To validate prime n, only need to check divisibility up to sqrt(n)
primes[$primeLimit]=0                            # Prime table for our seive function
primeList[0]=2                                   # Array of primes for finding more primes later
primeListSquared[0]=4                            # Array for squared primes to minimize limit calculation later
primeIndex=0                                     # Index for recording found primes
for (( i=2; i<$primeLimit; i++ )); do
    if [[ ${primes[$i]} -eq \0 ]]; then
        primeList[$primeIndex]=$i
        primeListSquared[$primeIndex]=$i*$i
        primeIndex=$(($primeIndex+1))
        for (( n=$i; n<$primeLimit; n+=$i )); do
            primes[$n]=1
        done
    fi
done

function checkRange() {
    start=$1
    end=$2
    rangeSum=0

    # Make sure range starts at an odd number
    [[ $start -lt 2 ]] && start=3 && rangeSum=2
    [[ $(($start % 2)) -eq 0 ]] && start=$(($start + 1))

    # Use known primes to check all remaining numbers up to limit
    for (( i=$start; i<$end; i+=2 )); do
        prime=1
        for (( p=0; ${primeListSquared[$p]}<=$i; p++ )); do
            if [[ $(($i % ${primeList[$p]})) -eq 0 ]]; then
                prime=0
                break
            fi
        done
        # Record!
        if [[ $prime -eq 1 ]]; then
            rangeSum=$(($rangeSum+$i))
        fi
    done
    echo $rangeSum
}

# Split up and check with multiple processes
sum=0
range=$(($limit / 50))
for (( start=0; start<$limit; start+=$range )); do
    checkRange $start $(($start+$range)) &
done | while read result; do
    sum=$(($sum+$result))
    echo $sum
done | tail -1

