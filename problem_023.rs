// -*- compile-command: "rustc -o problem_023_rs problem_023.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 23:");
    println!("Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.\n");

    const LIMIT: usize = 28123; // Given as largest abundant sum

    // Find sums of all numbers less than LIMIT
    // and Isolate abundant numbers into vector
    let mut sums: [usize; LIMIT] = [0; LIMIT];
    let mut abundant = Vec::new();
    for n in 1..LIMIT {
        for m in 2..LIMIT {
            let t = n * m;
            if t > LIMIT {
                break;
            }
            sums[t] += n;
        }
        if sums[n] > n{
            abundant.push(n);
        }
    }

    // Add each pair of abundant numbers, track in table of bools
    let mut abundant_sum: [bool; LIMIT] = [false; LIMIT];
    for a in 0..abundant.len() {
        for b in a..abundant.len() {
            let n = abundant[a] + abundant[b];
            if n >= LIMIT {
                break;
            }
            abundant_sum[n] = true;
        }
    }

    // Sum all the numbers that are not a sum of 2 abundant numbers (false)
    let mut sum = 0;
    for n in 0..(LIMIT-1) {
        if abundant_sum[n] == false {
            sum += n;
        }
    }

    println!("{}", sum);
}
