#!/usr/bin/node

console.log("Project Euler - Problem 33:");
console.log("Find the denominator of the product of all the two digit fractions with a non-trivial unorthodox canceling method.\n");

function prime_factors(n){
    var factors = [];
    var i = 2;
    while (n > 1){
        while (n % i == 0){
            factors.push(i);
            n = Math.floor(n/i);
        }
        i += 1;
    }

    return factors;
}

function reduce(fraction){
    var n = fraction[0];
    var d = fraction[1];

    // Get factors of denominator
    var factors = prime_factors(d);

    // See if any of the factors reduce the numerator
    for (var f of factors)
        if (n % f == 0){
            n /= f;
            d /= f;
        }

    // return new fraction
    return [n, d];
}

function unconventional_cancels(fraction){
    // Check if fraction reduces
    const original_reduced = reduce(fraction);
    if (fraction[0] != original_reduced[0]) {
        var unconventional_reduced = null;

        // Check if numerator and demoninator have same number in leading digit
        if (Math.floor(fraction[0] / 10) == Math.floor(fraction[1] / 10))
            unconventional_reduced = [Math.floor(fraction[0] % 10), Math.floor(fraction[1] % 10)];

        // Check if numerator and demoninator have same number in cross digit
        else if (Math.floor(fraction[0] / 10) == Math.floor(fraction[1] % 10))
            unconventional_reduced = [Math.floor(fraction[0] % 10), Math.floor(fraction[1] / 10)];

        else if (Math.floor(fraction[0] % 10) == Math.floor(fraction[1] / 10))
            unconventional_reduced = [Math.floor(fraction[0] / 10), Math.floor(fraction[1] % 10)];

        // Check if numerator and demoninator have same number in trailing digit (and that it's not 0)
        else if (Math.floor(fraction[0] % 10) == Math.floor(fraction[1] % 10) && Math.floor(fraction[0] % 10) != 0)
            unconventional_reduced = [Math.floor(fraction[0] / 10), Math.floor(fraction[1] / 10)];

        if (unconventional_reduced != null) {
            // reduce the unconventionally reduced fraction
            const unconventional_reduced_reduced = reduce(unconventional_reduced);

            // Check if reduced fraction is same as unconventionally reduced reduced fraction
            if (unconventional_reduced_reduced[0] == original_reduced[0] &&
                unconventional_reduced_reduced[1] == original_reduced[1])
                return true;
        }
    }

    return false;
}

const debug = false;

var product = [1, 1];
// Iterate through all two-digit fractions that are less-than 1
for (var num=10; num<100; num++)
    for (var den=num+1; den<100; den++)
        if (unconventional_cancels([num, den]) == true){
            product[0] *= num;
            product[1] *= den;
            if (debug == true)
                console.log("Found: "+num+"/"+den);
}

console.log(reduce(product)[1]);
