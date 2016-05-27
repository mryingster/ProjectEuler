// -*- compile-command: "rustc -o problem_058_rs problem_058.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_prime(n: u64) -> bool {
    if n < 2 { return false; }
    if n == 2 { return true; }
    if n % 2 == 0 { return false; }

    let limit = (n as f64).sqrt() as u64;
    let mut i = 3;
    while i <= limit {
        if n % i == 0 { return false; }
        i += 2;
    }
    return true;
}

fn main() {
    println!("Project Euler - Problem 58:");
    println!("Start with 1 and spiral anticlockwise with numbers incrementing from 1 forming a square. What is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?\n");

    let debug = false;

    let mut corner_val = 3;       // Starting on top right corner
    let mut side_len = 3;         // Side length is already 3
    let mut side = 1;             // Side we are currently on

    let mut all_corners = 2;      // Start with center and second corner (1, 3)
    let mut prime_corners = 1;    // Second corner == 3
    let mut fraction:f64 = 100.0;

    while fraction > 10.0 {
        if side % 4 == 0 { side_len += 2; }
        corner_val += side_len - 1;
        side += 1;

        // Keep track of corner ratios
        all_corners += 1;
        if is_prime(corner_val) { prime_corners += 1; }
        fraction = prime_corners as f64 / all_corners as f64 * 100.0;

        if debug == true {
            println!("{}/{}*100 = {} (n={}, side={})",
                     prime_corners, all_corners,
                     fraction, corner_val, side_len);
        }
    }

    println!("{}", side_len);
}
