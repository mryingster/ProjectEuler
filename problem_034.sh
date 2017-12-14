#!/bin/bash

echo "Project Euler - Problem 34:"
echo "Find the sum of all the numbers that can be written as the sum of the factorials of their digits"
echo

factorials=(1)
for i in $(seq 1 9); do
    factorials[$i]=$((${factorials[$(($i - 1))]} * $i))
done


i=3
total=0

while [[ $i -lt 50000 ]]; do
    n=$i
    sum=0
    while [[ $n -gt 0 ]]; do
        sum=$(($sum + ${factorials[$(($n % 10))]}))
        [[ $sum -gt $i ]] && break
        n=$(($n / 10))
    done

    [[ $sum -eq $i ]] && total=$(($total + $i))

    i=$(($i + 1))
done

echo $total
