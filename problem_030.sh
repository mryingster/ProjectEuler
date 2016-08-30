#!/bin/bash

echo "Project Euler - Problem 30:"
echo "Find the sum of all the numbers that can be written as the sum of fifth powers of their digits"
echo

limit=500000
sum=0
powers[0]=0

for n in $(seq 1 9); do
    powers[$n]=$(($n ** 5))
done

function numDigits() {
    [[ $1 -lt 10 ]] && echo 1 && return
    [[ $1 -lt 100 ]] && echo 2 && return
    [[ $1 -lt 1000 ]] && echo 3 && return
    [[ $1 -lt 10000 ]] && echo 4 && return
    [[ $1 -lt 100000 ]] && echo 5 && return
    [[ $1 -lt 1000000 ]] && echo 6 && return
    [[ $1 -lt 10000000 ]] && echo 7 && return
}

function checkRange() {
    rangeSum=0

    # Iterate through all the numbers
    for i in $(seq $1 $2); do
        digitSum=0
        digitNum=$(numDigits $i)
        # Iterate through all the digits in the number
        for e in $(seq 0 $digitNum); do
            # Get the 5th power for the digit
            digitPow=${powers[${i:$e:1}]}
            # Sum them up
            digitSum=$(($digitSum + $digitPow))
            # Don't bother if number is already too big
            [[ $digitSum -gt $i ]] && break
        done

        # Record answer if meets criteria
        if [[ $i -eq $digitSum ]]; then
            rangeSum=$(($rangeSum + $i))
        fi
    done

    echo $rangeSum
}

# Split up and check with multiple processes
sum=0
range=$(($limit / 40))
for (( start=2; start<$limit; start+=$range )); do
    checkRange $start $(($start+$range)) &
done | while read result; do
    sum=$(($sum+$result))
    echo $sum
done | tail -1
