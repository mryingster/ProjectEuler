#!/bin/bash

echo "Project Euler - Problem 15:"
echo "Starting in the top left corner in a 20 by 20 grid, how many routes are there to the bottom right corner?"
echo

a=(1 0)

for row in {0..39}; do
    # Calculate pascal's triagle
    b[0]=1
    for i in $(seq 0 $row); do
        b[$(($i + 1))]=$((${a[$i]} + ${a[$(($i + 1))]}))
    done
    b[$(($row + 2))]=0

    # copy b to a
    for i in $(seq 0 $(($row + 2))); do
        a[$i]=${b[$i]}
    done

done

echo ${a[20]}
