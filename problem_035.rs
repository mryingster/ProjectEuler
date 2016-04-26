// -*- compile-command: "rustc -o problem_035_rs problem_035.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn rotate(n: usize) -> usize {
    let l = (n as f64).log10().floor();
    let mut new = n/10;
    new += n % 10 * ((10 as f64).powf(l) as usize);
    return new;
}

fn main() {
    println!("Project Euler - Problem 35:");
    println!("How many circular primes are there below one million?\n");

    let debug = false;

    // Find all primes below 1,000,000
    let mut prime_seive: [bool; 1000000] = [true; 1000000];
    for i in 2..prime_seive.len()/2 {
        if prime_seive[i] == true {
            let mut m = 2;
            let mut n = m*i;
            while n < prime_seive.len() {
                prime_seive[n] = false;
                m += 1;
                n = m*i;
            }
        }
    }

    let mut count = 0;
    for i in 2..prime_seive.len() {
        // Skip non-primes
        if prime_seive[i] == false {
            continue;
        }

        // rotate and see if in prime seive
        let mut circular = true;
        let mut n = rotate(i);
        while n != i {
            if prime_seive[n] != true {
                circular = false;
                break;
            }
            n = rotate(n);
        }

        // Tabulate results
        if circular == true {
            if debug == true {
                println!("{}", i)
            }
            count += 1;
        }
    }

    println!("{}", count);
}
