#!/bin/bash

echo "Project Euler - Problem 16:"
echo "What is the sum of the digits of the number 2^1000"
echo

n=(2)
len=1

for t in {1..999}; do
    # Multiply each element first
    i=0
    while [ $i -lt $len ]; do
        n[$i]=$((${n[$i]} * 2))
        i=$(($i + 1))
    done

    # Carry over so each element is < 10
    i=0
    while [ $i -lt $len ]; do
        while [ ${n[$i]} -gt 9 ]; do
            n[$i]=$((${n[$i]} - 10))
            n[$(($i + 1))]=$((${n[$(($i + 1))]} + 1))
        done
        i=$(($i + 1))
    done

    # Get new array length
    len=$(echo ${n[@]} | wc | awk '{print$2}')
done

# Add it all up!
sum=0
i=0
while [ $i -lt $len ]; do
    sum=$(($sum + ${n[$i]}))
    i=$(($i + 1))
done

echo $sum
