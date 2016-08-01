// -*- compile-command: "rustc -o problem_069_rs problem_069.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_prime(n: u64) -> bool {
    if n     <  2 { return false; }
    if n     == 2 { return true; }
    if n % 2 == 0 { return false; }

    let limit = (n as f64).sqrt() as u64;
    for i in 3..(limit+1) {
        if n % i == 0 {
            return false;
        }
    }
    return true;
}

fn main() {
    println!("Project Euler - Problem 69");
    println!("Find the value of n <= 1,000,000 for which n/phi(n) is a maximum, where phi(n) is Euler's Totient function.\n");

    let target = 1000000;
    let mut n = 1;

    for i in 2..1000 {
        if is_prime(i) {
            if n * i > target {
                break;
            } else {
                n *= i;
            }
        }
    }

    println!("{}", n);
}
