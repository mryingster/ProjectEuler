#!/usr/bin/node

console.log("Project Euler - Problem 30:");
console.log("Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.\n");

function sum_of_fifth_powers(n){
    var sum = 0

    while (n > 0){
        let d = Math.floor(n % 10);
        sum += power5[d];
        n /= 10;
    }

    return sum;
}

// Biggest number we can do is 354294. 9^5=59049, and 6 digits=354294
var limit = 354294;
var sum = 0;
var n = 10;

// Precalculate the powers of digits
var power5 = []
for (var i=0; i<10; i++)
    power5.push(Math.pow(i, 5));

while (n <= limit){
    if (sum_of_fifth_powers(n) == n)
        sum += n;
    n++;
}

console.log(sum);
