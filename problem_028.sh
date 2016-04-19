#!/bin/bash

echo "Project Euler - Problem 28:"
echo "Starting with the number 1 and moving to the right in a clockwise direction, form a 1001 by 1001 spiral. What is the sum of the numbers on the diagonals in this spiral?"
echo

limit=$((1001 * 1001))
n=1
sum=1
step=2
c=0

while [[ $n -lt $limit ]]; do
    n=$(($n + $step))
    sum=$(($sum + $n))
    c=$(($c + 1))
    if [[ $c -eq 4 ]]; then
        c=0
        step=$(($step + 2))
    fi
done

echo $sum
