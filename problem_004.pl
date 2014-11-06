#!/usr/bin/env perl

print "Project Euler - Problem 4:\n";
print "Find the largest palindrome made from the product of two 3-digit numbers.\n\n";

$result = 0;

for ($a=100 ; $a<1000 ; $a++) {
    for ($b=$a ; $b<1000 ; $b++) {
        $product = $a * $b;
        $tcudorp = 0;
        while ($product > 0) {
            $tcudorp *= 10;
            $tcudorp += $product % 10;
            $product = int($product/10);
        }
        $product = $a * $b;
        #print $product, " : ", $tcudorp, "\n"; #DEBUG
        if ($product == $tcudorp) {
            if ($result < $product) {
                $result = $product;
            }
        }
    }
}

print "Largest product: ", $result, "\n";
