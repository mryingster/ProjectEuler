#!/usr/bin/node

console.log("Project Euler - Problem 4:");
console.log("Find the largest palindrome made from the product of two 3-digit numbers.\n");

function isPalindrome(n){
    let ns = n.toString();
    let nsr = ns.split("").reverse().join("");
    if (ns == nsr)
        return true;
    return false;
}

var result = 0;
for (var n1=99; n1<1000; n1++){
    for (var n2=n1; n2<1000; n2++){
        let t = n1 * n2;

        if (t <= result)
            continue;

        if (isPalindrome(t) == true){
            result = t;
        }
    }
}

console.log(result);
