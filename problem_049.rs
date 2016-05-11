// -*- compile-command: "rustc -o problem_049_rs problem_049.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn num_sig(n: usize) -> u32 {
    let mut n = n;
    let mut sig: u32 = 0;
    while n > 0 {
        sig += (10 as f32).powi((n % 10) as i32) as u32;
        n /= 10;
    }
    return sig;
}

fn main() {
    println!("Project Euler - Problem 49:");
    println!("What 12 digit sequence do you form by concatenating three four-digit primes that are permutations of each other and increase by the same amount?\n");

    let mut primes = [1; 10000];
    primes[0] = 0;
    primes[1] = 0;

    // Get number signatures for all primes
    for n in 2..(primes.len()) {
        if primes[n] == 1 {
            primes[n] = num_sig(n);
            let mut m=2;
            let mut i=m*n;
            while i < primes.len() {
                primes[i] = 0;
                m += 1;
                i = m*n;
            }
        }
    }

    // Look for solution
    for a in 1000..9999 {
        if primes[a] == 0 { continue; } // Skip non-primes
        if a == 1487 { continue; }      // Skip already-known sequence
        for b in (a+1)..9999 {
            if primes[a] == primes[b] {
                let c = b + (b - a);
                if c > 9999 { break; }  // Make sure c is not out-of-range
                if primes[a] == primes[c] {
                    println!("{}{}{}", a, b, c);
                }
            }
        }
    }
}
