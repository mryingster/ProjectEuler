#!/usr/bin/env perl

print "Project Euler - Problem 1:\n";
print "Find the sum of all the multiples of 3 or 5 below 1000.\n\n";

$number = 1;
$sum = 0;

while ($number < 1000) {
    if ($number % 3 == 0) {
        $sum += $number;
    } else {
        if ($number % 5 == 0) {
            $sum += $number;
        }
    }
    $number++;
}

print "Sum: ", $sum, "\n";
