#!/usr/bin/node

console.log("Project Euler - Problem 20:");
console.log("Find the sum of the digits in the number 100!\n");

var bignum = [1];
for (var i=1; i<=100; i++){
    for (var d in bignum)
	bignum[d] *= i;

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

