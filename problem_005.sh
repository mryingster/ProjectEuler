#!/bin/bash

echo "Project Euler - Problem 5"
echo "What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?"
echo

function isPrime() {
    n=$1
    [ $n -lt 2 ] && return 1
    [ $n -eq 2 ] && return 0
    [ $(($n % 2)) == 0 ] && return 1
    for (( i=3; i*i<$(($n+1)); i=$(($i+2)) )); do
        [ $(($n % $i)) == 0 ] && return 1
    done
    return 0
}

limit=20

# Prime number with all prime numbers under limit
base=1
for (( n=2; n<$limit; n++ )); do
    $(isPrime $n) && base=$(($base * $n))
done

# Check multiples of base for one that is divisible
n=0
for m in {1..100}; do
    n=$(($base*$m))
    found=true
    for (( d=11; d<21; d++ )); do
        if [ $(($n % $d)) -ne 0 ]; then
            found=false
            break
        fi
    done
    [ $found == true ] && break
done

echo "$n"
