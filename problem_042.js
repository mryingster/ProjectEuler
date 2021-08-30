#!/usr/bin/node

console.log("Project Euler - Problem 42:");
console.log("In a list of two-thousand common English words, how many are triangle words?\n");

const fs = require('fs');
var buffer;

function score_word(word){
    score = 0;
    for (var c=0; c<word.length; c++)
	score += word.charCodeAt(c) - "A".charCodeAt(0) + 1;

    return score;
}

function count_triangle_words(buffer, triangles){
    var sum = 0;
    let words = buffer.split(",");

    for (var word of words)
	if (triangles.indexOf(score_word(word.replace(/"/g,""))) >= 0)
	    sum++;

    console.log(sum);
}

// Pre-computer triangle numbers
var triangles = [];
for (var i=1; i<100; i++)
    triangles.push(Math.floor(1/2 * i * (i + 1)));

// Read in text file
fs.readFile('problem_042.txt', 'utf8', (err, data) => {
    if (err) {
	console.error(err);
	return;
    }
    count_triangle_words(data, triangles);
})
