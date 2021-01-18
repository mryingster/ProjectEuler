#!/usr/bin/node

console.log("Project Euler - Problem 12:");
console.log("What is the value of the first triangle number to have over five hundred divisors?\n");

function divisors(n){
    // Prime factorization
    var primes = {};
    var prime = 2;
    while (n > 1){
	while (n % prime == 0){
	    n /= prime;
	    if (prime in primes)
		primes[prime] += 1;
	    else
		primes[prime] = 1;
	}
	prime += 1;
    }

    // Convert to divisor count
    var divisors = 1
    for (prime in primes)
	divisors *= (primes[prime] + 1);

    return(divisors);
}

var t = 1;
var n = 1;

while (divisors(t) < 500){
    n += 1;
    t += n;
}

console.log(t);
