// -*- compile-command: "rustc -o problem_006_rs problem_006.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 6");
    println!("Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n");

    let mut sum = 0;
    let mut squ = 0;

    for n in 1..101 {
        sum += n*n;
        squ += n;
    }

    squ *= squ;

    println!("{}", squ-sum);
}
