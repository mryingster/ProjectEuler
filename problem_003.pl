#!/usr/bin/env perl

print "Project Euler - Problem 3:\n";
print "What is the largest prime factor of the number 600851475143 ?\n\n";

$number = 600851475143;
$lastFactor = 0;

for ($i=2 ; $i<10000 ; $i++) {
    if ( $number % $i == 0 ) {
        $number /= $i;
        $lastFactor = $i;
        $i = 2;
    }
}

print "Largest factor found: ", $lastFactor, "\n";
