// -*- compile-command: "rustc -o problem_040_rs problem_040.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 40:");
    println!("If dn represents the nth digit of an irrational fraction created by concatenating the positive integers, find the value of the following expression:\n\nd1 x d10 x d100 x d1000 x d10000 x d100000 x d1000000\n");

    let mut product = 1;
    let mut count = 1;
    let mut power = 10;
    let mut i = 2;

    while power <= 1000000 {
        let len = ((i as f32).log10().floor() + 1.0) as usize;  // Get digit length
        count += len;                                           // Keep track of count
        if count >= power {
            let dif = (count - power) as i32;                   // Figure out which digit of i we want
            let mut digit = i / (10 as f32).powi(dif) as usize; // Remove trailing digits
            digit = digit % 10;                                 // Isolate digit
            product *= digit;                                   // Update our product
            power *= 10;                                        // Set next target value
        }
        i += 1;                                                 // Next number
    }

    println!("{}", product);
}
