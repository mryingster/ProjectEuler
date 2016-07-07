#!/bin/bash

echo "Project Euler - Problem 21:"
echo "Evaluate the sum of all the amicable numbers under 10000."
echo

limit=10000

# Calculate divisor sums
sums[0]=0
for i in $(seq 1 $limit); do
    n=$(($i + $i))
    while [[ $n -lt $limit ]]; do
        sums[$n]=$((${sums[$n]} + $i))
        n=$(($n + $i))
    done
done

# Check if amicable
sum=0
for i in $(seq 2 $limit); do
    if [[ ${sums[$i]} -lt $i ]]; then
        if [[ ${sums[${sums[$i]}]} -eq $i ]]; then
            sum=$(($sum + $i + ${sums[$i]}))
        fi
    fi
done

echo $sum
