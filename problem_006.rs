// -*- compile-command: "rustc -o problem_006_rs problem_006.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 6");
    println!("Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.\n");

    let mut sum_of_squares: i32 = 0;
    let mut square_of_sums: i32 = 0;

    for n in 1..101 {
        sum_of_squares += n*n;
        square_of_sums += n;
    }

    square_of_sums *= square_of_sums;

    println!("{}", square_of_sums - sum_of_squares);
}
