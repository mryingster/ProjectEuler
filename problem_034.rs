// -*- compile-command: "rustc -o problem_034_rs problem_034.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 34:");
    println!("Find the sum of all numbers which are equal to the sum of the factorial of their digits.\n");

    // Calculate factorials
    let mut factorial = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0];
    for i in 1..factorial.len() {
        factorial[i] = i * factorial[i-1];
    }

    let mut sum = 0;

    // Find solutions
    for i in 10..100000 {
        let mut n = i;
        let mut fs = 0;
        while n > 0 {
            fs += factorial[n % 10];
            n /= 10;
        }
        if fs == i {
            sum += i;
        }
    }

    println!("{}", sum);
}
