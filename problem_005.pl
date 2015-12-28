#!/usr/bin/env perl

print "Project Euler - Problem 5:\n";
print "What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?\n\n";

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

$l = 20; # limit

# Start off with multiplication of all primes less than 20
# Must be larger than that number

$n = 1;

for ($i=0; $i<$l; $i++){
    if (isPrime($i) == 1){
        $n *= $i;
    }
}

# Begin search. If not divisible, start multiplying by all numbers
# starting with 2, and increasing until we find match

$found = 0;
$m = 1;

while ($found == 0) {
    $n *= $m;
    $m += 1;

    $found = 1;
    for ($d=3; $d<=$l; $d++) {
        if ($n % $d != 0) {
            $found = 0;
            break;
        }
    }
}

print $n, "\n";
