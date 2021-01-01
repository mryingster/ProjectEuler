#!/usr/bin/node

console.log("Project Euler - Problem 9:");
console.log("There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc..\n");

// a^2 + b^2 = c^2
// a + b + c = 1000
// c = (a^2 + b^2)^(1/2)
// c = 1000 - a - b
// (a^2 + b^2)^(1/2) = 1000 - a - b

const target = 1000;

function findTriple(t){
    for (var a=1; a<t; a++){
	for (var b=a; a+b<t; b++){
	    let c1 = 1000 - a - b;
	    let c2 = Math.sqrt(a * a + b * b);

	    if (c1 == c2)
		return a * b * c1;
	}
    }
}

console.log(findTriple(target));
