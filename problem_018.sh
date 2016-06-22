#!/bin/bash

function a() {
    b=$(($2+1))
    echo ${array[$1]} | awk '{print $'$b'}'
}

function aset {
    IFS=' ' read -r -a tmp <<< "${array[$1]}"
    tmp[$2]=$3
    array[$1]="${tmp[@]}"
}

echo "Project Euler - Problem 18:"
echo "Find the maximum total from top to bottom of the triangle below:"
echo

array=("75  0  0  0  0  0  0  0  0  0  0  0  0  0  0" \
       "95 64  0  0  0  0  0  0  0  0  0  0  0  0  0" \
       "17 47 82  0  0  0  0  0  0  0  0  0  0  0  0" \
       "18 35 87 10  0  0  0  0  0  0  0  0  0  0  0" \
       "20  4 82 47 65  0  0  0  0  0  0  0  0  0  0" \
       "19  1 23 75  3 34  0  0  0  0  0  0  0  0  0" \
       "88  2 77 73  7 63 67  0  0  0  0  0  0  0  0" \
       "99 65  4 28  6 16 70 92  0  0  0  0  0  0  0" \
       "41 41 26 56 83 40 80 70 33  0  0  0  0  0  0" \
       "41 48 72 33 47 32 37 16 94 29  0  0  0  0  0" \
       "53 71 44 65 25 43 91 52 97 51 14  0  0  0  0" \
       "70 11 33 28 77 73 17 78 39 68 17 57  0  0  0" \
       "91 71 52 38 17 14 91 43 58 50 27 29 48  0  0" \
       "63 66  4 68 89 53 67 30 73 16 69 87 40 31  0" \
       "04 62 98 27 23  9 70 98 73 93 38 53 60  4 23")

# Print array
for line in {0..14}; do
    for i in $(seq 0 $((14 - $line))); do
        printf "  "
    done
    for i in $(seq 0 $line); do
        printf "%02d  " $(a line i )
    done
    echo
done
echo

# Solve it
for y in $(seq 14 -1 -1); do
    for x in $(seq 0 $y); do
        if [[ $(a $(($y+1)) $x) -gt $(a $(($y+1)) $(($x+1))) ]]; then
            aset $y $x $(($(a $(($y+1)) $x) + $(a $y $x)))
        else
            aset $y $x $(($(a $(($y+1)) $(($x+1))) + $(a $y $x)))
        fi
    done
done

# Print it
a 0 0
