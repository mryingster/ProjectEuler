// -*- compile-command: "rustc -o problem_075_rs problem_075.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn gcd(n: usize, d: usize) -> usize {
    let mut i = d;
    while i > 1 {
        if n % i == 0 && d % i == 0 {
            return i;
        }
        i -= 1;
    }
    return 1;
}

fn main() {
    println!("Project Euler - Problem 75:");
    println!("Given that L is the length of the wire, for how many values of L <= 1,500,000 can exactly one integer sided right angle triangle be formed?\n");

    let debug = false;
    let mut history = [0; 1500000];
    let limit:usize = history.len();
    let sqr_limit:usize = ((limit/2) as f32).sqrt() as usize;

    for m in 2..sqr_limit {
        let mut n = 1;
        while n < m {
            // Euclid's Formula:
            // If sides m and n add up to be odd and the greatest common
            // denominator of n/m is 1 then we have a pythagorean triple
            if (m + n) % 2 == 1 && gcd(n, m) == 1 {
                let a = (m * m) - (n * n);
                let b = 2 * m * n;
                let c = (m * m) + (n * n);
                let mut l = a + b + c;

                // Debug Print
                if debug == true {
                    println!("{}: {}, {}, {}", l, a, b, c);
                }

                // Add all multiples less than limit to history
                while l < limit {
                    history[l] += 1;
                    l += a + b + c;
                }
            }
            n += 1;
        }
    }

    // Count results
    let mut count = 0;
    for i in 0..limit {
        if history[i] == 1 {
            count += 1;
        }
    }

    println!("Total: {}", count);
}
