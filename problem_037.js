#!/usr/bin/node

console.log("Project Euler - Problem 37:");
console.log("Find the sum of the only eleven primes that are both truncatable from left to right and right to left.\n");

function is_truncatable(n, primes){
    // Single digit primes don't count
    if (n < 10) return false;

    // Truncate from right
    var right = n;
    while (right > 0){
        if (primes[right] == 0)
            return false;
        right = Math.floor(right / 10);
    }
        
    // Truncate from left
    var left = n;
    while (left > 0){
        if (primes[left] == 0)
            return false;
        left = Number(left.toString().slice(1));
    }

    return true;
}

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

// Go through each and see if they are truncatable 
var sum = 0;
for (var prime of primes)
    if (is_truncatable(prime, prime_sieve))
        sum += prime;

console.log(sum);
