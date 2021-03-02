#!/usr/bin/node

console.log("Project Euler - Problem 18:");
console.log("Find the total number of Sundays that fell on the first of the month in the 20th Century.\n");

const monday = 1;
const sunday = 7;

const january = 1;
const february = 2;
const december = 12;

var day   = 1;
var date  = 1;
var month = 1;
var month_length = [null, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
var year  = 1900;

var count = 0;

while (year < 2001){
    // Check if Sunday is the first!
    if (day == sunday && date == 1 && year > 1900)
	count++;

    // Increment day
    day++;
    if (day > sunday) day = monday;

    // Increment date with month rollover
    date += 1;
    if (date > month_length[month]){
	month++;
	date = 1;
    }

    // Rollover year
    if (month > december){
	month = january;
	year += 1;

	// Decide if it's a leap year
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	    month_length[february] = 29;
	else
	    month_length[february] = 28;
    }
}

console.log(count);
