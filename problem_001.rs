// -*- compile-command: "rustc -o problem_001_rs problem_001.rs" -*-
// Copyright (c) 2016 Michael Caldwell


fn main() {
    println!("Project Euler - Problem 1");
    println!("Find the sum of all the multiples of 3 or 5 below 1000.\n");

    let mut sum = 0;

    for n in 1..1000 {
        if n % 3 == 0 || n % 5 == 0 {
            sum = sum + n;
        }
    }

    println!("{}", sum);
}
