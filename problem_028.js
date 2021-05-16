#!/usr/bin/node

console.log("Project Euler - Problem 28:");
console.log("Starting with the number 1 and moving to the right in a clockwise direction, form a 1001 by 1001 spiral. What is the sum of the numbers on the diagonals in this spiral?\n");

/*
  21 22 23 24 25
  20  7  8  9 10
  19  6  1  2 11
  18  5  4  3 12
  17 16 15 14 13
*/

let limit  = 1001;
let sum    = 1;
let n      = 1;
let length = 2;
let side   = 0;

while (n < limit * limit){
    n += length;
    sum += n;
    side += 1;
    if (side == 4){
        side = 0;
        length += 2;
    }
}

console.log(sum);
