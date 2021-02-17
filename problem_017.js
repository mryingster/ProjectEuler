#!/usr/bin/node

console.log("Project Euler - Problem 17:");
console.log("If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?\n");

const numbers = {
    0    : 0,
    1    : "one".length,
    2    : "two".length,
    3    : "three".length,
    4    : "four".length,
    5    : "five".length,
    6    : "six".length,
    7    : "seven".length,
    8    : "eight".length,
    9    : "nine".length,
    10   : "ten".length,
    11   : "eleven".length,
    12   : "twelve".length,
    13   : "thirteen".length,
    14   : "fourteen".length,
    15   : "fifteen".length,
    16   : "sixteen".length,
    17   : "seventeen".length,
    18   : "eighteen".length,
    19   : "nineteen".length,
    20   : "twenty".length,
    30   : "thirty".length,
    40   : "forty".length,
    50   : "fifty".length,
    60   : "sixty".length,
    70   : "seventy".length,
    80   : "eighty".length,
    90   : "ninety".length,
    100  : "hundred".length,
    1000 : "thousand".length,
}

var total_sum = 0;

for (var n=1; n<=1000; n++){
    let number = n;
    let sum = 0;

    // Take care of thousands
    if (number >= 1000) {
	sum += numbers[Math.floor(number / 1000)];
	sum += numbers[1000];
	number %= 1000;
    }

    // Take care of hundreds
    if (number >= 100) {
	sum += numbers[Math.floor(number / 100)];
	sum += numbers[100];
	number %= 100;

	// Add the 'and'
	if (number > 0)
	    sum += "and".length;
    }

    // Take care of tens > 19
    if (number >= 20) {
	sum += numbers[number % 10];
	sum += numbers[Math.floor(number / 10) * 10];
    }
    else {
	sum += numbers[number];
    }

    total_sum += sum;
    //console.log(n, sum, total_sum);
}

console.log(total_sum);

