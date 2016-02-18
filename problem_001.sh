#!/bin/bash

echo "Project Euler - Problem 1"
echo "Find the sum of all the multiples of 3 or 5 below 1000."
echo

sum=0
n=1
while [ $n -lt 1000 ]; do
    if [ $(($n % 3)) -eq 0 ] || [ $(($n % 5)) -eq 0 ]; then
        sum=$(($sum+n))
    fi
    n=$(($n+1))
done

echo "$sum"
