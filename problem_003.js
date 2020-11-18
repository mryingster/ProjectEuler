#!/usr/bin/node

console.log("Project Euler - Problem 3:");
console.log("What is the largest prime factor of the number 600851475143?\n");

var n = 600851475143;
var f = 2;

while (n > f){
    while (n % f == 0)
        n /= f;
    f += 1;
}

console.log(f);
