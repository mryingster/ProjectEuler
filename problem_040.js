#!/usr/bin/node

console.log("Project Euler - Problem 40:");
console.log("If dn represents the nth digit of an irrational fraction created by concatenating the positive integers, find the value of the following expression:\n");
console.log("d1 x d10 x d100 x d1000 x d10000 x d100000 x d1000000\n");

// Create a long string of numbers until the string is long enough
var n = 1;
var s = "";
var limit = 1000000;

while (s.length < limit){
    s += n.toString();
    n += 1;
}

// Do the multiplication
var product = 1;
n = 1;

while (n <= limit){
    product *= Number(s[n-1]);
    n *= 10;
}

console.log(product);
