// -*- compile-command: "rustc -o problem_046_rs problem_046.rs" -*-
// Copyright (c) 2016 Michael Caldwell

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
    println!("Project Euler - Problem 46:");
    println!("What is the smallest odd, composite number that cannot be written as the sum of a prime and twice a square?\n");

    let mut array = [0; 10000];
    array[2] = 1;

    for i in 2..array.len() {
        if is_prime(i) {
            let mut m = 1;
            let mut n = i + (2 * (m * m));
            while n < array.len() {
                array[n] += 1;
                m += 1;
                n = i + (2 * (m * m));
            }
        } else {
            if i % 2 != 0 && array[i] == 0 {
                println!("{}", i);
                break;
            }
        }
    }
}
