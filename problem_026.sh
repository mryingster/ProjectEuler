#!/bin/bash

echo "Project Euler - Problem 26"
echo "Find the value of d < 1000 for which 1/d contains the longest recurring cycle."
echo

longestVal=0
longestNum=0
debug=0

export BC_LINE_LENGTH=0

for d in {2..1000}; do
    answer=$(echo "scale=2000; 1/$d" | bc)
    end=${answer:1996:5}
    length=$(echo $answer | sed -e "s/.*\($end.*\)$end/\1$end/" | wc -c)

    [[ $length -gt $longestVal ]] && longestVal=$length && longestNum=$d

    # Print answers
    if [[ $debug == 1 ]]; then
        echo "1/$d repeats after $length digits"
    fi
done

echo $longestNum
