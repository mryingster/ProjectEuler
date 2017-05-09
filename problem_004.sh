#!/bin/bash

echo "Project Euler - Problem 4"
echo "Find the largest palindrome made from the product of two 3-digit numbers."
echo

answer=0

for (( a=999; a>99; a-- )); do
    ((c=a*a))
    for (( b=a; b<1000; b++ )); do
        ((c=c+a))

        # Pre-screen by making sure it's bigger
        if [[ $c -gt $answer ]]; then

            # Pre screen again by making sure it could be palindrome
            if [[ ${c:5:1} -eq ${c:0:1} ]]; then

                # Check if palindrome
                if [[ $c -eq $(echo -n "$c" | rev) ]]; then
                    answer=$c
                fi
            fi
        fi
    done
done

echo "$answer"
