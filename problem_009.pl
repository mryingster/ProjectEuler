#!/usr/bin/env perl
use POSIX;

print "Project Euler - Problem 9:
There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.\n\n";

$a = 1;
$product = 0;
while (1 > 0){
    $a++;
    $b = $a;
    while (1 > 0){
        $b++;
        $c = sqrt(($a ** 2) + ($b ** 2));

        if (($a + $b + $c) > 1000) {
            last;
        }

        if ($c == floor($c)) {
            #print "$a $b $c\n"; # DEBUG
            if ($a + $b + $c == 1000) {
                $product = $a * $b * $c;
            }

            if ($product > 0){
                last;
            }
        }
    }
    if ($product > 0) {
        last;
    }
}

print "$product\n";
