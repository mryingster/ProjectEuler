#!/bin/bash

echo "Project Euler - Problem 7"
echo "What is the 10,001st prime number?"
echo

function isPrime() {
    for (( i=3; i*i<=$1; i+=2 )); do
        [ $(($1 % $i)) == 0 ] && return 1
    done
    return 0
}

count=1
n=1
while [ $count -lt 10001 ]; do
    n=$(($n + 2))
    $(isPrime $n) && count=$(($count + 1))
done

echo "$n"
