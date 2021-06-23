#!/usr/bin/node

console.log("Project Euler - Problem 32:");
console.log("Find the sum of all numbers that can be written as pandigital products.\n");

function is_pandigital(s){
    var digits = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0];

    for (c of s)
        digits[Number(c)]++;

    for (var d of digits)
        if (d != 1)
            return false;

    return true;
}

const limit = 2500;
var history = [];
var sum     = 0;

for (var a=1; a<limit; a++)
    for (var b=a+1; b<limit; b++){
        let c = a * b;
        let string = a.toString() + b.toString() + c.toString();
        if (string.length > 9) break;
        if (string.length < 9) continue;

        if (is_pandigital(string))
            if (history.indexOf(c) < 0){
                history.push(c);
                sum += c;
            }
    }

console.log(sum);
