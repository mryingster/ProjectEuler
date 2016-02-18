#!/bin/bash

echo "Project Euler - Problem 2"
echo "By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms."
echo

sum=0
n1=1
n2=1
nt=0
while [ $n1 -lt 4000000 ]; do
    nt=$n1
    n1=$(($n1+$n2))
    n2=$nt
    if [ $(($n1 % 2)) -eq 0 ]; then
        sum=$(($sum+$n1))
    fi
done

echo "$sum"
