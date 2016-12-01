#!/bin/bash

echo "Project Euler - Problem 63:"
echo "How many n-digit positive integers exist which are also an nth power?"
echo

count=0
debug=0

for n in $(seq 1 50); do
    for e in $(seq 1 50); do
        number=$(($n ** $e))

        # Look for overflow... Use BC instead which is slower
        [[ $number -lt 1 ]] && number=$(echo "$n ^ $e" | bc)

        length=$(($(echo -n $number | wc -m) + 0))

        # Look for equality
        if [[ $length -eq $e ]]; then
            count=$(($count + 1))
            [[ debug -eq 1 ]] && echo "$n ^ $e = $number ($length)"
        fi

        # Break if we go too far
        [[ $length -gt $e ]] && break
    done
done

echo $count
