#!/usr/bin/node

console.log("Project Euler - Problem 5:");
console.log("What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n");

function getFactors(n){
    let factors = [0, 1];
    let f = 2;
    while (n > 1){
        let fcount = 0;
        while (n % f == 0){
            fcount += 1;
            n /= f;
        }
        factors.push(fcount);
        f += 1;
    }

    return factors;
}

const limit = 20 + 1;
var factors = [];

// Initialize factors array
for (var i=0; i<limit; i++)
    factors.push(0);

for (var n=2; n<limit; n++){
    // Get factors of each number through limit
    let t_factors = getFactors(n);

    // For our list of factors, keep biggest group for each factor
    for (var i=0; i<t_factors.length; i++)
        if (t_factors[i] > factors[i])
            factors[i] = t_factors[i];
}

// Multiply Final Factors Together
var result = 1;
for (var i=0; i<factors.length; i++)
    for (var n=0; n<factors[i]; n++)
        result *= i;

console.log(result);
