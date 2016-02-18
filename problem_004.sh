#!/bin/bash

echo "Project Euler - Problem 4"
echo "Find the largest palindrome made from the product of two 3-digit numbers."
echo

answer=12321

for (( a=999; a>99; a-- )); do
    for (( b=a; b<1000; b++ )); do
        c=$(($a*$b))
        if [ $c -gt $answer ]; then
            if [ $c -eq $(echo -n "$c" | rev) ]; then
                answer=$c
            fi
        fi
    done
done

echo "$answer"
