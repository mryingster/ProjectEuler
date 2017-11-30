#!/bin/bash

echo "Project Euler - Problem 32:"
echo "Find the sum of all numbers that can be written as pandigital products."
echo ""

function isPandigital(){
    [[ 10 -ne $(echo "0$1" | grep -o . | sort | uniq | wc -l) ]] && return 1
    return 0
}

sum=0
history="0"
debug=0
lastb=9876

for a in $(seq 2 987); do
    start=$((1234 / a))
    end=$((9876 / a))
    [[ $lastb -lt $a ]] && break
    for b in $(seq $start $end); do
        c=$((a * b))
        if isPandigital $a$b$c; then
            if ! $(echo "$history" | grep -q "$c"); then
                [[ $debug -eq 1 ]] && echo "$a x $b = $c"
                sum=$((sum + c))
                history="$history $c"
                lastb=$b
            fi
        fi
    done
done

echo $sum
