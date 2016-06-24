#!/bin/bash

function score(){
    score=0
    for i in $(echo $1 | sed -e 's/\(.\)/\1 /g'); do
        score=$(($score + $(printf "%d\n" "'$i") - 64))
    done
    echo $score
}

echo "Project Euler: 22"
echo "Sort 5000 names and calculate the sum of their name scores."
echo

file="problem_022.txt"

sum=0
pos=1
for name in $(cat $file | sed -e 's/\"//g' | sed -e 's/\,/\n/g' | sort); do
    sum=$(($sum + ($pos * $(score $name))))
    pos=$(($pos + 1))
done

echo $sum
