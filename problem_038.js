#!/usr/bin/node

console.log("Project Euler - Problem 38:");
console.log("What is the largest 1 to 9 pandigital that can be formed by multiplying a fixed number by 1, 2, 3, ...?\n");

function is_pandigital(s){
    var digits = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0];

    for (c of s)
        digits[Number(c)]++;

    for (var d of digits)
        if (d != 1)
            return false;

    return true;
}

const limit = 100000;
var largest = 0;

for (var base=1; base<limit; base++){
    var pandigit = "";
    for (var n=1; n<9; n++){
        pandigit += Number(base * n).toString();
        if (pandigit.length > 9) break;
        if (pandigit.length < 9) continue;

        if (is_pandigital(pandigit))
            if (Number(pandigit) > largest)
                largest = Number(pandigit);
    }
}

console.log(largest);
