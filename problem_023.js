#!/usr/bin/node

console.log("Project Euler - Problem 23:");
console.log("Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.\n");

const limit = 28123;
var numbers = [];
var abundant_numbers = [];

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

    // Keep track of abundant numbers
    if (numbers[n] > n)
        abundant_numbers.push(n);
}

// Re-use array for abundant sums
for (var n=0; n<limit; n++)
    numbers[n] = 0;


// Add all the abundant numbers together
for (var a=0; a<abundant_numbers.length; a++)
    for (var b=a; b<abundant_numbers.length; b++){
	let abundant_sum = abundant_numbers[a] + abundant_numbers[b];
	if (abundant_sum > limit) break;
	numbers[abundant_sum] += 1;
    }

// Finally, sum all the numbers we managed not to create using abundant sums
var sum = 0;
for (var n=0; n<limit; n++)
    if (numbers[n] == 0)
	sum += n;

console.log(sum);
