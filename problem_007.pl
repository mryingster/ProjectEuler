#!/usr/bin/env perl

print "Project Euler - Problem 7:\n";
print "What is the 10,001st prime number?\n\n";

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
$c = 2;

while ($c < 10001){
    $n += 2;
    if (isPrime($n) == 1){
        $c++;
    }
}

print $n, "\n";
