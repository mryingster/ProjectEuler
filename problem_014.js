#!/usr/bin/node

console.log("Project Euler - Problem 14:");
console.log("Which starting number, under one million, produces the longest chain by following the rules below?\n");
console.log("if n is even, n/2");
console.log("if n is odd, 3n+1\n");

const limit = 1000000;
var longest = [0, 0];
var history = [0, 0];

for (var i=2; i<limit; i++) {
    let n = i;
    let chain = [];

    while (history.length <= n) {
	chain.push(n);
	if (n % 2 == 0)
	    n /= 2;
	else
	    n = (3 * n) + 1;
    }

    let total_length = history[n] + chain.length + 1;
    history.push(total_length);
    if (total_length > longest[1]){
	longest[0] = i;
	longest[1] = total_length;
    }
}

console.log(longest[0] + " (" + longest[1] + ")");
