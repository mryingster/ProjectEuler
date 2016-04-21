// -*- compile-command: "rustc -o problem_028_rs problem_028.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 28:");
    println!("Starting with the number 1 and moving to the right in a clockwise direction, form a 1001 by 1001 spiral. What is the sum of the numbers on the diagonals in this spiral?\n");

    let mut sum = 1;
    let mut skip = 2;
    let mut step = skip;
    let mut side = 1;

    for n in 1..1001*1001+1 {
        if side == 4 {
            skip += 2;
            side = 0;
        }

        if step == 0 {
            sum += n;
            side += 1;
            step = skip;
        }

        step -= 1;
    }

    println!("{}", sum);
}
