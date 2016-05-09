// -*- compile-command: "rustc -o problem_047_rs problem_047.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 47:");
    println!("What is the first of four consecutive integers to have four distinct prime factors?\n");

    let mut primes: [usize; 1000000] = [0; 1000000];
    let mut count = 0;

    for n in 2..primes.len() {
        // Prime seive
        if primes[n] == 0 {
            let mut m = 2;
            let mut i = m * n;
            while i < primes.len() {
                primes[i] += 1;
                m += 1;
                i = m * n;
            }
        }

        // 4 prime factors
        if primes[n] == 4 {
            count += 1;
            if count == 4 {
                println!("{}", n-3);
                break;
            }
        } else {
            count = 0;
        }
    }
}
