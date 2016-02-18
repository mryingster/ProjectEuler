#!/bin/bash

echo "Project Euler - Problem 3"
echo "What is the largest prime factor of the number 600851475143?"
echo

n=600851475143
d=2

while [ $n -ne 1 ]; do
    if [ $(($n % $d)) -eq 0 ]; then
        n=$(($n / $d))
    else
        d=$(($d + 1))
    fi
done

echo "$d"
