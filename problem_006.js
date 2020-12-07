#!/usr/bin/node

console.log("Project Euler - Problem 6:");
console.log("Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n");

const limit = 100;
var sum = 0;
var squares = 0;

for (var n=1; n<=100; n++){
    sum += n;
    squares += (n * n);
}

console.log((sum * sum) - squares);
