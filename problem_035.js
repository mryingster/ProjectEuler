#!/usr/bin/node

console.log("Project Euler - Problem 35:");
console.log("How many circular primes are there below one million?\n");

function is_circular(n, primes){
    // Single digit primes are circular
    if (n < 10) return true;

    // Convert the prime into a string so we can get it's length etc.
    let string_prime = n.toString();

    // Rotate the number as many times as it has digits
    for (var rot=0; rot<string_prime.length; rot++){
        string_prime = string_prime.slice(1) + string_prime[0];

        // See if rotated number is in prime sieve
        if (primes[Number(string_prime)] == 0)
            return false;
    }

    return true;
}

var count = 0;
const limit = 1000000;
var prime_sieve = Array.from({length: limit + 1}, (v, i) => 1);
var primes = [];

// Use a sieve to find all primes under 1,000,000.
prime_sieve[0] = 0;
prime_sieve[1] = 0;
for (var n=2; n<limit; n++){
    if (prime_sieve[n] == 1){
        primes.push(n);
        let m = 2;
        while (m * n < limit){
            prime_sieve[m * n] = 0;
            m++;
        }
    }
}

// Go through each and see if they are circular
for (var prime of primes)
    if (is_circular(prime, prime_sieve))
        count++;

console.log(count);
