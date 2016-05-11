// -*- compile-command: "rustc -o problem_048_rs problem_048.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 48:");
    println!("Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.\n");

    let mut total: u64 = 0;

    for i in 1..1000 {
        let mut n = i as u64;
        for _ in 1..i {
            n *= i as u64;
            n %= 10000000000;
        }
        total += n;
        total %= 10000000000;
    }

    println!("{}", total);
}
