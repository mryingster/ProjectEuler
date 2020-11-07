#!/usr/bin/node

console.log("Project Euler - Problem 2:");
console.log("By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\n");

const limit = 4000000;
var sum = 0;

let f1 = 1;
let f2 = 0;
while (f1 < limit){
    let t = f1 + f2;
    f2 = f1;
    f1 = t;

    if (f1 % 2 == 0)
        sum += f1;
}

console.log(sum);
