#!/usr/bin/node

console.log("Project Euler - Problem 16:");
console.log("What is the index of the first term in the Fibonacci sequence to contain 1000 digits?\n");

var bignum_a = [1];
var bignum_b = [0];
var count = 1;


while (bignum_a.length < 1000){
    // Shift our variables for the next fibonacci
    let bignum_t = [...bignum_b];
    bignum_b = [...bignum_a];

    // Add last two terms together
    for (var d=0; d<bignum_b.length; d++){
	let term_t = 0;
	if (d < bignum_t.length)
	    term_t = bignum_t[d];
	bignum_a[d] += term_t;
    }

    // Carry the digits
    for (var d=0; d<bignum_a.length; d++)
	while (bignum_a[d] >= 10){
	    if (d + 1 >= bignum_a.length)
		bignum_a.push(0);

	    bignum_a[d+1] += 1;
	    bignum_a[d] -= 10;
	}

    count += 1;
}

console.log(count);

