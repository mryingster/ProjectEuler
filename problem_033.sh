#!/bin/bash

echo "Project Euler - Problem 33:"
echo "Find the denominator of the product of all the two digit fractions with a non-trivial unorthodox canceling method."
echo

debug=False
result_n=1
result_d=1

#Find non-trivial, unorthodox canceling fractions
for num in $(seq 11 100); do
    for den in $(seq $num 100); do
        if [[ ${num:1} -eq ${den:0:1} ]] && [[ ${num:1} -ne ${den:1} ]] && [[ ${den:1} -ne "0" ]]; then
            frac_orig=$(echo "scale=30; $num/$den" | bc)
            frac_simp=$(echo "scale=30; ${num:0:1}/${den:1}" | bc)
            if [ "$frac_orig" == "$frac_simp" ]; then
                result_n=$(($result_n * $num))
                result_d=$(($result_d * $den))
                if [[ $debug == True ]]; then
                    echo "Found: $num/$den"
                fi
            fi
        fi
    done
done

# Simplify result
if [[ $debug == True ]]; then
    echo "Fraction: $result_n/$result_d"
fi

t=2
while [[ $t -le $result_n ]]; do
    if [[ $(($result_n % $t)) -eq 0 ]] && [[ $(($result_d % $t)) -eq 0 ]]; then
        result_n=$(($result_n / $t))
        result_d=$(($result_d / $t))
    else
        t=$(($t + 1))
    fi
done

# Print simplified denominator
echo $result_d
