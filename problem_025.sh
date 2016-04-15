#!/bin/bash

echo "Project Euler - Problem 25:"
echo "What is the index of the first term in the Fibonacci sequence to contain 1000 digits?"
echo

pre=1
cur=0
digits=16
count=0

while [ $digits -lt 1000 ]; do
    tmp=$cur
    cur=$(($cur + $pre))
    pre=$tmp

    count=$(($count + 1))

    if [ $cur -gt 9999999999999999 ]; then
        cur=$(($cur / 10))
        pre=$(($pre / 10))
        digits=$(($digits + 1))
    fi
done

echo "$count"
