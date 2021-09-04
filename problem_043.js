#!/usr/bin/node

console.log("Project Euler - Problem 43:");
console.log("Find the sum of all 0 to 9 pandigital numbers with the sub-string divisibility property.\n");

// Find all 2-3 digit numbers divisible by the first 7 primes
var prime_sub_numbers = {
    2  : [],
    3  : [],
    5  : [],
    7  : [],
    11 : [],
    13 : [],
    17 : [],
};

for (var n=1; n<1000; n++){
    for (p in prime_sub_numbers)
        if (n*p < 1000 && n*p > 9)
            prime_sub_numbers[p].push(n*p);
}

// Use recursion to construct these numbers with sub-string divisibility
var potential_pandigitals = [];
function build_number(n, s){
    if (s.length == 0){
        potential_pandigitals.push(n);
        return n;
    }

    for (var p of prime_sub_numbers[s[0]]){
        if (Math.floor(n % 100) == Math.floor(p / 10)){
            build_number(n * 10 + Math.floor(p % 10), s.slice(1));
        }
    }
}

for (var n of prime_sub_numbers[2]){
    build_number(n, [3, 5, 7, 11, 13, 17]);
}

// Sort through the potential pandigitals and add up only the real pandigitals
function is_pandigital(s){
    var digits = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];

    // Count up digits
    for (c of s.toString())
        digits[Number(c)]++;

    // One digit should be missing. This will be the leading digit
    // If we have more than one missing digit or two of anything return 0
    var missing = -1;
    for (var d of digits){
        if (d == 0){
            if (missing == -1){
                missing = d;
            } else {
                return 0;
            }
        }
        if (d > 1)
            return 0;
    }

    return Number(missing + s);
}

var sum = 0;
for (var pp of potential_pandigitals)
    sum += is_pandigital(pp);

console.log(sum);
