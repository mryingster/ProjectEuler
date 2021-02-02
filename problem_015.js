#!/usr/bin/node

console.log("Project Euler - Problem 15:");
console.log("Starting in the top left corner in a 20 by 20 grid, how many routes are there to the bottom right corner?\n");

const limit = 20;
var triangle = [[1, 0]];

for (var i=0; i<limit * 2; i++){
    let new_row = [1];
    for (var n=0; n<triangle[i].length-1; n++)
	new_row.push(triangle[i][n] + triangle[i][n+1]);
    new_row.push(0);
    triangle.push(new_row);
}

console.log(triangle[40][20]);
