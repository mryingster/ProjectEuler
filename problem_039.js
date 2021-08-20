#!/usr/bin/node

console.log("Project Euler - Problem 39:");
console.log("Find the perimeter of a right triangle (p) that has the most possible solutions, where the perimiter is less than or equal to 1000.\n");

var solutions = {};
var limit = 1000;

for (var a=1; a<limit; a++){
    for (var b=1; a+b<=limit; b++){
        let c = Math.sqrt((a * a) + (b * b));
        if (Math.floor(c) == c){
            let p = a + b + c;
            if (p > limit) break;
            if (p in solutions) {
                solutions[p]++;
            } else {
                solutions[p] = 1;
            }
        }
    }
}

var max = null;
for (var i in solutions)
    if (solutions[i] > solutions[max] || max == null)
        max = i;

console.log(max);
