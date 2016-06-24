#!/bin/bash

echo "Project Euler - Problem 20:"
echo "Find the sum of the digits in the number 100!"
echo

# Set up array
for x in $(seq 0 200); do
    n[$x]=0
done
n[0]=1

for i in $(seq 1 100); do
    # Multiply
    for x in $(seq 0 200); do
        n[$x]=$((${n[$x]} * $i))
    done
    # Simplify
    for x in $(seq 0 200); do
        while [ ${n[$x]} -gt 9 ]; do
            n[$x]=$((${n[$x]} - 10))
            n[$(($x + 1))]=$((${n[$(($x + 1))]} + 1))
        done
    done
done

# Sum it all up
sum=0
for x in $(seq 0 200); do
    sum=$(($sum + n[$x]))
done

echo $sum
