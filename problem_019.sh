#!/bin/bash

echo "Project Euler - Problem 19:"
echo "Find the total number of Sundays that fell on the first of the month in the 20th Century."
echo

sum=0

for year in $(seq 1901 2000); do
    for month in $(seq 1 12); do
        # Find all the weeks with "1" in them, then make sure they start on
        # Monday by checking that there are 7 days on that week
        [ $(cal $month $year | grep \ 1\ | wc -w) -eq 7 ] && sum=$(($sum+1))
    done
done

echo $sum
