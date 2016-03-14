#!/usr/bin/env perl

print "Project Euler - Problem 12:\n";
print "What is the value of the first triangle number to have over five hundred divisors?\n\n";

sub isPrime{
    local $i, $n;
    my($n) = @_;

    if ($n < 2){ return 0; }
    if ($n == 2){ return 1; }
    if ($n % 2 == 0) { return 0; }

    for ($i=3 ; $i ** 2 <= $n ; $i+=2) {
        if ($n % $i == 0) {
            return 0;
        }
    }

    return 1;
}

sub divisors{
    local $i, $c, $n, $np, @p;
    my($n, $np, @p) = @_;

    $i = 0; # Number we are dividing by
    $c = 1; # Total divisor count
    while ($n > 1 && $i < $np) {
        $t = 1; # Count for current divisor
        while ($n % @p[$i] == 0) {
            $t += 1;
            $n /= @p[$i];
        }
        $c *= $t; # Running total of divisors
        $i += 1 # Get next prime to divide by
    }

    return $c;
}

# Precompute Primes
@primes = (2);
for (my $i=3; $i < 5000; $i+=2) {
    if (isPrime($i) == 1) {
        push(@primes, $i);
    }
}

$nPrimes = @primes; # Number of primes we pre-computed
$tNum = 1; # Triangle Number
$tIndex = 1; # Triangle Number Helper
$div = 0; # Divisors

while ($div < 500) {
    $tIndex += 1;
    $tNum += $tIndex;
    if ($tNum % 10 != 0) {next; } # Optimization
    $div = divisors($tNum, $nPrimes, @primes);
    #print $tNum, ", ", $div, "\n"; # Debug
}

print $tNum, "\n";
