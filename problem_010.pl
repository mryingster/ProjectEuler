#!/usr/bin/env perl

print "Project Euler - Problem 10:
Find the sum of all the primes below two million.\n\n";

sub isPrime{
    local $i, $n;
    my($n) = @_;

    if ($n < 2){
        return 0;
    }

    if ($n == 2){
        return 1;
    }

    if ($n % 2 == 0){
        return 0;
    }

    for ($i=3 ; $i ** 2 <= $n ; $i+=2){
        if ($n % $i == 0){
            return 0;
        }
    }

    return 1;
}

$n = 3;
$s = 5;

while ($n < 2000000){
    $n += 2;
    if (isPrime($n) == 1){
        $s += $n;
    }
}

print $s, "\n";
