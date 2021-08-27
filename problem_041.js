#!/usr/bin/node

console.log("Project Euler - Problem 41:");
console.log("What is the largest n-digit pandigital prime that exists?\n");

function is_pandigital(n){
    // convert to string
    let s = n.toString();

    // See if digits 1-n are present
    for (var i=1; i<=s.length; i++)
        if (s.indexOf(i.toString()) < 0)
            return false;
    return true;
}

function is_prime(n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (var i=3; i<=Math.sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

// Can't be 8 or 9 digit number becaause 9 and 8 pandigitals are all divisible by 3

var n = 7654321;

while (n > 0){
    if (is_pandigital(n)){
        if (is_prime(n)){
            console.log(n);
            break;
        }
    }
    n--;
}
