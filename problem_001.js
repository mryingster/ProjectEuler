#!/usr/bin/node

console.log("Project Euler - Problem 1:");
console.log("Find the sum of all the multiples of 3 or 5 below 1000.\n");

var sum = 0;
for (var n=3; n<1000; n++)
    if (n % 3 == 0 || n % 5 == 0)
        sum += n;

console.log(sum);
