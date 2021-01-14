#!/usr/bin/node

console.log("Project Euler - Problem 10:");
console.log("Find the sum of all the primes below two million.\n");

const limit = 2000000;
var sum = 0;
var primes = [0,0];
for (var n=2; n<limit; n++)
    primes.push(n);

var p = 2;
while (p < limit){
    sum += p;

    // Remove all multiples of this prime
    let i = p + p;
    while (i < limit){
	primes[i] = 0;
	i += p;
    }

    // Find the next prime
    p += 1;
    while (primes[p] == 0)
	p += 1;
}

console.log(sum);
