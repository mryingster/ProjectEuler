// -*- compile-command: "rustc -o problem_037_rs problem_037.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 37:");
    println!("Find the sum of the only eleven primes that are both truncatable from left to right and right to left\n");

    let mut primes: [bool; 1000000] = [true; 1000000];
    primes[0] = false;
    primes[1] = false;
    let mut sum = 0;
    let mut count = 0;
    let debug = false;

    for n in 2..(primes.len()) {
        if primes[n] == true {
            // Prime seive
            let mut m=2;
            let mut i=m*n;
            while i < primes.len() {
                primes[i] = false;
                m += 1;
                i = m*n;
            }

            // 1 digit primes don't count
            if n < 10 {
                continue;
            }

            // Truncate from right
            let mut candidate = true;
            let mut t = n/10;
            while t > 0 {
                if primes[t] == false{
                    candidate = false;
                    break;
                }
                t /= 10;
            }

            // Truncate from left
            t = n;
            let mut mask = 1;
            let l = (t as f32).floor().log10() as i32;
            for _ in 0..l {
                mask *= 10;
                t = n % mask;
                if primes[t] == false{
                    candidate = false;
                    break;
                }
            }

            // Take care of winners
            if candidate == true {
                if debug == true {
                    println!("{}", n);
                }
                sum += n;
                count += 1;
            }
        }
        if count == 11 {
            break;
        }
    }

    println!("{}", sum);
}
