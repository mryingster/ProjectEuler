#!/bin/bash

echo "Project Euler - Problem 6"
echo "Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum."
echo

square=0
sum=0

for n in {1..100}; do
    sum=$(($sum + $n))
    square=$(($square + $(($n * $n))))
done

sum=$(($sum * $sum))

echo $(($sum-$square))
