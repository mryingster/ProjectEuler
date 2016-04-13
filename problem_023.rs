// -*- compile-command: "rustc -o problem_023_rs problem_023.rs" -*-
// Copyright (c) 2016 Michael Caldwell


fn divisor_sum(n: usize) -> usize {
    let mut s = 0;
    for d in 1..(n/2+1) {
        if n % d == 0 {
            s += d;
        }
    }
    return s;
}

fn main() {
    println!("Project Euler - Problem 23:");
    println!("Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.\n");

    const LIMIT: usize = 28123;
    let mut abundant = Vec::new();

    for n in 12..LIMIT {
        if divisor_sum(n) > n {
            abundant.push(n);
        }
    }

    let mut abundant_sum: [bool; LIMIT] = [false; LIMIT];
    for a in 0..abundant.len() {
        for b in 0..abundant.len() {
            let n = abundant[a] + abundant[b];
            if n >= LIMIT {
                break;
            }
            abundant_sum[n] = true;
        }
    }

    let mut sum = 0;
    for n in 0..(LIMIT-1) {
        if abundant_sum[n] == false {
            sum += n;
        }
    }

    println!("{}", sum);
}
