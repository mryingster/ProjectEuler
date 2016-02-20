#!/bin/bash

echo "Project Euler - Problem 9"
echo "There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc."
echo

answer=0

for a in {100..1000}; do
    for (( b=$a+1; b<1000; b++ )); do
        for (( c=$b+1; c<1000; c++ )); do
            # Check for appropriate c
            leftside=$((($a*$a)+($b*$b)))
            rightside=$(($c*$c))
            [ $leftside -gt $rightside ] && continue
            [ $leftside -lt $rightside ] && break

            # See if sum is 1000
            [ $(($a+$b+$c)) -ne 1000 ] && continue

            # We have our answer!
            answer=$(($a*$b*$c))
            break
        done
        [ $answer -ne 0 ] && break
    done
    [ $answer -ne 0 ] && break
done

echo "$answer"
