#!/bin/bash

function monthStartDays() {
for year in $(seq $1 $2); do
    for month in Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec; do
        date +%A --date="$month 1 $year"
    done
done

}

echo "Project Euler - Problem 19:"
echo "Find the total number of Sundays that fell on the first of the month in the 20th Century."
echo

monthStartDays 1901 2000 | grep -c Sunday
