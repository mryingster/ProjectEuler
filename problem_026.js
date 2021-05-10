#!/usr/bin/node

console.log("Project Euler - Problem 26:");
console.log("Find the value of d < 1000 for which 1/d contains the longest recurring cycle.\n");

const limit = 1000;
let max_cycle_lenth = 0;
let max_cycle_seed = 0;

function find_cycle_length(a){
    // Go from end of array
    let last_index = a.length-1
    // Walk backwards looking for potential lengths
    for (var l=3; l<a.length/2; l++){
	// Walk backwards at potential lengths and stop if we hit non-matches
	let matched = true;
	for (var i=last_index; i>last_index-l; i--){
	    if (a[i] != a[i-l]){
		matched = false;
		break;
	    }
	}
	if (matched == true)
	    return l;
    }
    return -1;
}

for (var d=2; d<limit; d++){
    var digits = [];
    var n = 1;
    while (true){
	// Manual division
	while (n < d)
	    n *= 10
	let digit = Math.floor(n/d);
	digits.push(digit);
	n -= digit * d;

	// Look for non-repeating terminations
	if (n == 0 || digit == 0)
	    break;

	// Look for repetitions
	let cycle_length = find_cycle_length(digits);
	if (cycle_length != -1){
	    if (cycle_length > max_cycle_lenth){
		max_cycle_lenth = cycle_length;
		max_cycle_seed  = d;
	    }
	    break;
	}
    }
}

console.log(max_cycle_seed);

