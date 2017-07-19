#!/bin/bash

echo "Project Euler - Problem 23"
echo "Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers."

echo

limit=28123

# Generate List of Divisor Sums
divisorSums[$limit]=0
abundantNumbers[0]=0
abundantIndex=0

for (( i=1; i<$limit; i++ )); do
    # Add abundant numbers to the list.
    if [[ ${divisorSums[$i]} -gt $i ]]; then
        abundantNumbers[$abundantIndex]=$i
        abundantIndex=$(($abundantIndex + 1))
    fi

    # Finish sieve
    for (( n=$i+$i; n<$limit; n+=$i )); do
        divisorSums[$n]=$((${divisorSums[$n]} + $i))
    done
done

# Create tmp file to store results from backgrounded processes
tmpFile="problem_023.tmp"
echo -n > $tmpFile

for (( i=0; i<$limit; i++ )); do
    echo $i >> $tmpFile
done

# Split into multiple background processes
function calculateRange() {
    SO=$1
    EO=$2
    SI=$3
    EI=$4

    for (( a=$SO; a<$EO; a++)); do
        for (( b=$SI; b<$EI; b++)); do
            abundantSum=$((${abundantNumbers[$a]} + ${abundantNumbers[$b]}))
            [[ $abundantSum -gt $limit ]] && break

            echo $abundantSum >> $tmpFile
        done
    done
}

range=500
for (( startOuter=0; startOuter<$abundantIndex-$range; startOuter+=$range )); do
    for (( startInner=$startOuter; startInner<$abundantIndex-$range; startInner+=$range )); do
        calculateRange $startOuter $(($startOuter+$range)) $startInner $(($startInner+$range)) &
    done
done

# Wait for all background tasks to complete
tmpFileLen=0
tmpFileLenNew=1
while [[ $tmpFileLen -ne $tmpFileLenNew ]]; do
    tmpFileLen=$tmpFileLenNew
    sleep 1
    tmpFileLenNew=$(wc -l < $tmpFile)
done

# Sort file, remove non-unique lines, sum remainder and print!
echo $(cat $tmpFile | sort -n | uniq -u | awk '{ sum += $1 } END { print sum }')

# Remove tmp file
rm $tmpFile
