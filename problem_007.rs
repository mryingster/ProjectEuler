// -*- compile-command: "rustc -o problem_007_rs problem_007.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_prime(n: u64) -> bool {
    if n < 2 {
        return false;
    }
    if n == 2 {
        return true;
    }
    if n % 2 == 0 {
        return false;
    }

    let limit = (n as f64).sqrt() as u64;
    for i in 3..(limit+1) {
        if n % i == 0 {
            return false;
        }
    }
    return true;
}

fn main() {
    println!("Project Euler - Problem 7");
    println!("What is the 10,001st prime number?\n");

    let mut count = 1;
    let mut n = 1;
    while count < 10001 {
        n += 2;
        if is_prime(n) == true {
            count += 1;
        }
    }

    println!("{}", n);
}
