// -*- compile-command: "rustc -o problem_041_rs problem_041.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_pandigital(n: usize) -> bool {
    let mut n = n;
    let len = (n as f32).floor().log10() as usize + 1;
    let mut key = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0];

    while n > 0 {
        let d = (n % 10) as usize;
        if key[d] == 1 || d > len {
            return false;
        }
        key[d] += 1;
        n /= 10;
    }

    return true;
}

fn is_prime(n: usize) -> bool {
    if n < 2 { return false; }
    if n == 2 { return true; }
    if n % 2 == 0 { return false; }

    let limit = (n as f64).sqrt() as usize;
    for i in 3..(limit+1) {
        if n % i == 0 { return false; }
    }
    return true;
}

fn main() {
    println!("Project Euler - Problem 41:");
    println!("What is the largest n-digit pandigital prime that exists?\n");

    // Start with 7 digit number because the sums of 8 and 9 digit pandigital
    // numbers are divisible by 3, which precludes them from being prime.

    let mut n = 7654321;

    while n > 0 {
        if is_pandigital(n) {
            if is_prime(n) {
                println!("{}", n);
                break;
            }
        }
        n -= 2;
    }
}
