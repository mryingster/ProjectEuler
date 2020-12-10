#!/usr/bin/node

console.log("Project Euler - Problem 7:");
console.log("What is the 10,001st prime number?\n");

const target = 10001;
var primes = [2];

function isPrime(n, primes) {
    for (var p of primes)
	if (n % p == 0)
	    return false;

    return true;
}

var n = 3;
while (primes.length < target) {
    if (isPrime(n, primes))
	primes.push(n);
    n += 2;
}

console.log(primes[primes.length - 1]);
