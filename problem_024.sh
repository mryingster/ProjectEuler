#!/bin/bash

echo "Project Euler - Problem 24:"
echo "Find the 1,000,000th lexiconic permutation of the numbers 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9."
echo

target=1000000
count=0

perm() {
    local items="$1"
    local out="$2"
    local i
    if [[ "$items" == "" ]]; then
        if [[ $count == $target ]]; then
            echo "$out"
            exit
        fi
        count=$(($count+1))
        return
    fi
    for (( i=0; i<${#items}; i++ )) ; do
        perm "${items:0:i}${items:i+1}" "$out${items:i:1}"
    done
}

echo $(perm 0123456789)
