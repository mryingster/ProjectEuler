#!/usr/bin/node

console.log("Project Euler - Problem 16:");
console.log("What is the sum of the digits of the number 2^1000\n");

var bignum = [2];
for (var i=1; i<1000; i++){
    for (var d in bignum)
	bignum[d] *= 2;

    for (var d=0; d<bignum.length; d++)
	while (bignum[d] >= 10){
	    if (d + 1 >= bignum.length)
		bignum.push(0);

	    bignum[d+1] += 1;
	    bignum[d] -= 10;
	}
}

var sum = 0;
for (var d of bignum)
    sum += d;

console.log(sum);

