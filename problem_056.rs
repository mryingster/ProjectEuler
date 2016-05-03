// -*- compile-command: "rustc -o problem_056_rs problem_056.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 56:");
    println!("Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?\n");

    let mut max = 0;

    for b in 1..100 {
        let mut digits = [0; 200];
        digits[0] = b;

        for _ in 1..100 {
            let mut sum = 0;

            // Multiply each digit by the base num
            for i in 0..digits.len() {
                digits[i] *= b;
                // Carry over multiplication
                if i > 0 {
                    while digits[i-1] > 9 {
                        digits[i-1] -= 10;
                        digits[i] += 1;
                    }
                    // Sum the digits
                    sum += digits[i-1];
                }
            }

            // See if new max
            if sum > max {
                max = sum;
            }
        }
    }

    println!("{}", max);
}
