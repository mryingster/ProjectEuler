#!/bin/bash

echo "Project Euler - Problem 89:"
echo "Find the number of characters saved by writing each of these one thousand Roman numerals in their minimal form."
echo ""

file="problem_089.txt"

before=$(cat $file | wc -m)

after=$(cat $file | \
    sed -e 's/VIIII/IX/g' | \
    sed -e 's/IIII/IV/g' | \
    sed -e 's/LXXXX/XC/g' | \
    sed -e 's/XXXX/XL/g' | \
    sed -e 's/DCCCC/CM/g' | \
    sed -e 's/CCCC/DC/g' | \
    wc -m )

echo $(($before - $after))
