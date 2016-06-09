// -*- compile-command: "rustc -o problem_063_rs problem_063.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 63:");
    println!("How many n-digit positive integers exist which are also an nth power?\n");

    let mut count = 0;

    for b in 1..100 {                               // Base
        for e in 1..100 {                           // Exponent
            let n: f64 = (b as f64).powf(e as f64); // Number
            let l: f64 = n.log10().floor() + 1.0;   // Length
            if l > e as f64 { break; }
            if l == e as f64 {
                //println!("{}^{} = {} ({})", b, e, n, l); // DEBUG
                count += 1;
            }
        }
    }

    println!("{}", count);
}
