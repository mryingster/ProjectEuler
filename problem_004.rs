// -*- compile-command: "rustc -o problem_004_rs problem_004.rs" -*-
// Copyright (c) 2016 Michael Caldwell
//use std::num;

fn reverse(mut n: u64) -> u64 {
    let mut o = 0;

    while n > 0 {
        o *= 10;
        o += n % 10;
        n /= 10;
    }

    return o;
}


fn main() {
    println!("Project Euler - Problem 4");
    println!("Find the largest palindrome made from the product of two 3-digit numbers.\n");

    let mut largest = 0;

    for a in 100..999 {
        for b in 100..999 {
            let p  = a * b;
            if p != reverse(p) {
                continue;
            }
            if p > largest {
                largest = p;
            }
        }
    }

    println!("{}", largest);
}
