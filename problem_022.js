#!/usr/bin/node

console.log("Project Euler - Problem 20:");
console.log("Sort 5000 names and calculate the sum of their name scores.\n");

const fs = require('fs');
var buffer;

function score_name(name){
    score = 0;
    for(var c=1; c<name.length-1; c++)
	score += name.charCodeAt(c) - "A".charCodeAt(0) + 1;
    return score;
}

function score_names(buffer){
    var sum = 0;
    let names = buffer.split(",");
    names.sort();

    for (var i=0; i<names.length; i++){
	score = score_name(names[i]);
	sum += score * (i + 1);
    }

    console.log(sum);
}

fs.readFile('problem_022.txt', 'utf8', (err, data) => {
    if (err) {
	console.error(err);
	return;
    }
    score_names(data);
})


