// -*- compile-command: "rustc -o problem_087_rs problem_087.rs -O" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 87:");
    println!("How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?\n");

    let debug = false;
    let limit = 50000000;

    // Power Limits
    let square_limit = (limit as f32).powf(1.0/2.0) as usize +1;
    let cube_limit = (limit as f32).powf(1.0/3.0) as usize;
    let quad_limit = (limit as f32).powf(1.0/4.0) as usize;

    // Power Vectors
    let mut square_vec = Vec::new();
    let mut cube_vec = Vec::new();
    let mut quad_vec = Vec::new();

    // Find primes using sieve
    let mut prime_sieve  = vec![true; square_limit];
    for i in 2..square_limit {
        // If a new prime
        if prime_sieve[i] == true {

            // Get list of prime powers
            if i <= square_limit {
                square_vec.push((i as f64).powi(2) as usize);
            }
            if i <= cube_limit {
                cube_vec.push((i as f64).powi(3) as usize);
            }
            if i <= quad_limit {
                quad_vec.push((i as f64).powi(4) as usize);
            }

            // Sieve
            let mut m = 2;
            let mut n = m*i;
            while n < prime_sieve.len() {
                prime_sieve[n] = false;
                m += 1;
                n = m*i;
            }
        }
    }

    // Keep history since numbers should be distinct
    let mut history = vec![false; limit];
    let mut count = 0;

    // Combine powers to find answers
    for a in 0..square_vec.len() {

        for b in 0..cube_vec.len() {
            if square_vec[a] + cube_vec[b] > limit { break; }

            for c in 0..quad_vec.len() {
                let n = square_vec[a] + cube_vec[b] + quad_vec[c];
                if n >= limit { break; }

                // Make sure we haven't encountered this number before
                if history[n] == true { continue; }

                history[n] = true;
                count += 1;

                if debug == true {
                    println!("{} + {} + {} = {}",
                             square_vec[a], cube_vec[b], quad_vec[c], n);
                }
            }
        }
    }

    println!("{}", count);
}
