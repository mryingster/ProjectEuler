#!/bin/bash

echo "Project Euler - Problem 14:"
echo "Which starting number, under one million, produces the longest chain by following the rules below?"
echo
echo "if n is even, n/2"
echo "if n is odd, 3n+1"
echo

history[0]=0
longest_chain=0
longest_number=0

for i in {1..1000000}; do
    n=$i
    count=0
    while [[ $n -ne 1 ]]; do
	if [[ $(($n % 2)) -eq 0 ]]; then
	    n=$(($n / 2))
	else
	    n=$(($n * 3 + 1))
	fi
	count=$(($count + 1))

	if [[ $n -lt $i ]]; then
	    count=$(($count + ${history[$n]}))
	    n=1
	fi
    done
    history[$i]=$count

    if [[ $count -gt $longest_chain ]]; then
	longest_chain=$count
	longest_number=$i
    fi
done

echo $longest_number
