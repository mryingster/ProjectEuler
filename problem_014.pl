#!/usr/bin/env perl
use POSIX;

print "Project Euler - Problem 14:\n";
print "Which starting number, under one million, produces the longest chain by following the rules below?\n\n";
print "if n is even, n/2\n";
print "if n is odd, 3n+1\n\n";

$limit = 1000000;
@history = (0) * $limit;
$maxSeed = 0;
$history[0] = 1;

for ($i=2; $i<=$limit; $i++) {
    $n = $i;

    $steps = 0;
    while ($n != 1) {
        $steps++;
        if ($n % 2 == 0) {
            $n /= 2;
        } else {
            $n *= 3;
            $n += 1;
        }

        if ($n < $i) {
            $steps += $history[$n];
            $n = 1;
        }
    }

    $history[$i] = $steps;

    if ($steps > $history[$maxSeed]) {
        $maxSeed = $i;
    }
}

print $maxSeed, "\n";
