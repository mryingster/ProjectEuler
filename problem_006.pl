#!/usr/bin/env perl

print "Project Euler - Problem 6:\n";
print "Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n\n";

$sumsquare = 0; # Sum of squares
$squaresum = 0; # Square of sum

for ($i=1; $i<=100; $i++){
    $squaresum += $i;
    $sumsquare += $i**2;
}

$squaresum **= 2;

print $squaresum - $sumsquare, "\n";


