#!/usr/bin/node

console.log("Project Euler - Problem 27:");
console.log("Find the product of the coefficients, a and b, for the quadratic expression, n^2 + an + b, that produces the maximum number of primes for consecutive values of n, starting with n = 0.\n");

function is_prime(n){
    if (n < 2) return false;
    if (n == 2 ) return true;
    if (n % 2 == 0) return false;
    let limit = Math.sqrt(n)
    for (var i=3; i<=limit; i+=2)
	if (n % i == 0)
	    return false;
    return true;
}

var solutions = [{a : -1, b : -1, n : 0, product : 1}]

for (var a=-1000; a<=1000; a++){
    for (var b=-1000; b<=1000; b++){
	var n=0;
	while (is_prime(n*n + a*n + b) == true)
	    n += 1;
	if (n > solutions[solutions.length-1].n)
	    solutions.push({ a : a, b : b, n : n, product : a * b})
    }
}

console.log(solutions[solutions.length-1].product);
