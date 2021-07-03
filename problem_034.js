#!/usr/bin/node

console.log("Project Euler - Problem 34:");
console.log("Find the sum of all the numbers that can be written as the sum of the factorials of their digits\n");

function is_factorial_sum(n, factorial){
    let t = n;
    var sum = 0;

    // Decompose number and create factorial sum
    while (t > 0 && sum <= n){
        sum += factorial[Math.floor(t % 10)];
        t = Math.floor(t / 10);
    }

    // Compare sum
    if (sum == n)
        return true;

    return false;
}

// Pre-populate factorials
var factorials = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1];
for (var i=1; i<10; i++)
    for (var n=i; n<10; n++)
        factorials[n] *= i;

var sum = 0;
const limit = 100000;

for (var n=10; n<limit; n++)
    if (is_factorial_sum(n, factorials))
        sum += n;

console.log(sum);
