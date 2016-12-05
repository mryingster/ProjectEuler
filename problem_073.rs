// -*- compile-command: "rustc -o problem_073_rs problem_073.rs -O" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_prime(n: u64) -> bool {
    if n < 2 { return false; }
    if n == 2 { return true; }
    if n % 2 == 0 { return false; }

    let limit = (n as f64).sqrt() as u64;
    for i in 3..(limit+1) {
        if n % i == 0 {
            return false;
        }
    }
    return true;
}

fn main(){
    println!("Project Euler - Problem 73:");
    println!("How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d <= 12,000?\n");

    let limit = 12000;

    // Get some primes
    let mut primes = Vec::new();
    for i in 1..limit {
        if is_prime(i) {
            primes.push(i as usize);
        }
    }

    let mut count = 0;

    for d in 4..(limit+1) as usize {
        for n in d/3+1..d/2+1 {
            // If it reduces, ignore it!
            let mut reduces = false;
            for p in &primes {
                if *p > n { break; }
                if d % p == 0 {
                    if n % p == 0 {
                        reduces = true;
                        break;
                    }
                }
            }

            // Check if we have a countable number
            if reduces == false {
                //println!("{}/{}", n, d);
                count += 1;
            }
        }
    }

    println!("{}", count);
}
