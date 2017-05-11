#!/bin/bash

echo "Project Euler - Problem 9"
echo "There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc."
echo

target=1000
reducedTarget=$((target / 2))

for (( a=1; a<reducedTarget; a++ )); do
    aa=$((a * a))
    for (( b=a; b<reducedTarget; b++ )); do
        leftside=$((aa + (b * b)))
        
        c=$((target - a - b))
        cc=$((c * c))

        [[ $leftside -eq $cc ]] && echo $(($a*$b*$c)) && exit
    done
done
