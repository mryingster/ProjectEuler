#!/bin/bash

echo "Project Euler - Problem 17:"
echo "If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?"
echo

# Get charcater counts and store them
charcount[0]=0
charcount[1]=$(echo -n one         | wc -m)
charcount[2]=$(echo -n two         | wc -m)
charcount[3]=$(echo -n three       | wc -m)
charcount[4]=$(echo -n four        | wc -m)
charcount[5]=$(echo -n five        | wc -m)
charcount[6]=$(echo -n six         | wc -m)
charcount[7]=$(echo -n seven       | wc -m)
charcount[8]=$(echo -n eight       | wc -m)
charcount[9]=$(echo -n nine        | wc -m)
charcount[10]=$(echo -n ten        | wc -m)
charcount[11]=$(echo -n eleven     | wc -m)
charcount[12]=$(echo -n twelve     | wc -m)
charcount[13]=$(echo -n thirteen   | wc -m)
charcount[14]=$(echo -n fourteen   | wc -m)
charcount[15]=$(echo -n fifteen    | wc -m)
charcount[16]=$(echo -n sixteen    | wc -m)
charcount[17]=$(echo -n seventeen  | wc -m)
charcount[18]=$(echo -n eighteen   | wc -m)
charcount[19]=$(echo -n nineteen   | wc -m)
charcount[20]=$(echo -n twenty     | wc -m)
charcount[30]=$(echo -n thirty     | wc -m)
charcount[40]=$(echo -n forty      | wc -m)
charcount[50]=$(echo -n fifty      | wc -m)
charcount[60]=$(echo -n sixty      | wc -m)
charcount[70]=$(echo -n seventy    | wc -m)
charcount[80]=$(echo -n eighty     | wc -m)
charcount[90]=$(echo -n ninety     | wc -m)
charcount[100]=$(echo -n hundred   | wc -m)
charcount[1000]=$(echo -n thousand | wc -m)

and=$(echo -n and | wc -m)

count=0

for n in {1..1000}; do
    if [[ $n -ge 1000 ]]; then
        count=$(($count + ${charcount[${n:0:1}]}))
        count=$(($count + ${charcount[1000]}))
        n=$(($n % 1000))
    fi

    if [[ $n -ge 100 ]]; then
        count=$(($count + ${charcount[${n:0:1}]}))
        count=$(($count + ${charcount[100]}))
        n=$(($n % 100))
        [[ $n -gt 0 ]] && count=$(($count + $and))
    fi

    if [[ $n -ge 20 ]]; then
        count=$(($count + ${charcount[${n:0:1}0]}))
        n=$(($n % 10))
    fi

    count=$(($count + ${charcount[$n]}))
done

echo $count
