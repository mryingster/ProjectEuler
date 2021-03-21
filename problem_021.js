#!/usr/bin/node

console.log("Project Euler - Problem 20:");
console.log("Evaluate the sum of all the amicable numbers under 10000.\n");

const limit = 10000;
var numbers = [];
var sum = 0;

// Initialize array
for (var n=0; n<limit; n++)
    numbers.push(1);

// Find all divisor sums
for (var n=2; n<limit; n++){
    let i = n + n;
    while (i < limit) {
	numbers[i] += n;
	i += n;
    }

    // Record amicable numbers
    if (numbers[n] < n && numbers[numbers[n]] == n)
	sum += n + numbers[n]
}

console.log(sum);

