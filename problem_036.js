#!/usr/bin/node

console.log("Project Euler - Problem 36:");
console.log("Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.\n");

function is_palindromic(n){
    if (n == n.split("").reverse().join(""))
        return true;
    return false;
}

const limit = 1000000;
var sum = 0;

for (var n=1; n<limit; n++)
    if (is_palindromic(Number(n).toString()) && is_palindromic(Number(n).toString(2)))
        sum += n;

console.log(sum);
