// -*- compile-command: "rustc -o problem_050_rs problem_050.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_prime(n: u64) -> bool {
    if n < 2 { return false; }
    if n == 2 { return true; }
    if n % 2 == 0 { return false; }

    let limit = (n as f64).sqrt() as u64;
    for i in 3..(limit+1) {
        if n % i == 0 { return false; }
    }
    return true;
}

fn main() {
    println!("Project Euler - Problem 50");
    println!("Which prime, below one-million, can be written as the sum of the most consecutive primes?\n");

    let mut max_sum = 0;
    let mut max_count = 0;

    for start in 1..27 {
        let mut sum = 0;
        let mut count = 0;
        for n in start..4000 {
            if is_prime(n) {
                sum += n;
                count += 1;
            }

            if sum > 1000000 { break; }

            if is_prime(sum) {
                if count > max_count {
                    //println!("Candidate: {} {} {} {}", sum, count, start, n);
                    max_count = count;
                    max_sum = sum;
                }
            }
        }
    }

    println!("{}", max_sum);
}
