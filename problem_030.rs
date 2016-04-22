// -*- compile-command: "rustc -o problem_030_rs problem_030.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn power_digits(n: usize) -> usize {
    let mut n = n;
    let mut sum = 0;
    while n > 0 {
        let d = n % 10;
        sum += (d as f64).powi(5) as usize;
        n /= 10;
    }
    return sum;
}

fn main() {
    println!("Project Euler - Problem 30:");
    println!("Find the sum of all the numbers that can be written as the sum of fifth powers of their digits\n");

    let mut sum = 0;

    for n in 2..1000000 {
        if n == power_digits(n) {
            sum += n;
        }
    }

    println!("{}", sum);
}
