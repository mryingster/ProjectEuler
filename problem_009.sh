#!/bin/bash

echo "Project Euler - Problem 9"
echo "There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc."
echo

for (( a=1; a<1000; a++ )); do
    aa=$(($a*$a))
    for (( b=$a+1; b<1000; b++ )); do
        leftside=$(($aa+($b*$b)))
        for (( c=$b+1; c<1000; c++ )); do
            # Check for appropriate c
            rightside=$(($c*$c))
            [[ $leftside -lt $rightside || $(($a+$b+$c)) -gt 1000 ]] && break
 
            # See if sum is 1000
            [[ $leftside -eq $rightside && $(($a+$b+$c)) -eq 1000 ]] && echo $(($a*$b*$c)) && exit
         done
    done
done
