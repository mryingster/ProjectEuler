// -*- compile-command: "rustc -o problem_074_rs problem_074.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn factorial_sum(mut n: u64) -> u64 {
    let mut sum = 0;
    let factorial = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880];

    while n > 0 {
        sum += factorial[(n % 10) as usize];
        n /= 10;
    }

    return sum;
}

fn contains(c: &Vec<u64>, n: u64) -> bool{
    for i in 0..c.len() {
        if c[i] == n {
            return true;
        }
    }
    return false;
}

fn main() {
    println!("Project Euler - Problem 74:");
    println!("How many factorial chains, with a starting number below one million, contain exactly sixty non-repeating terms?\n");

    let mut history = [0; 1000000];
    let mut count = 0;

    for i in 1..1000000 {
        let mut n: u64 = i;
        let mut c = Vec::new();

        loop {
            // Keep track of new numbers
            if contains(&c, n) == true {
                history[i as usize] = c.len();
                break;
            }

            // Keep track of numbers we've seen in our history
            if (n as usize) < history.len() {
                if history[n as usize] > 0 {
                    history[i as usize] = history[n as usize] + c.len();
                    break;
                }
            }

            // Get next factorial sum
            c.push(n);
            n = factorial_sum(n);
        }
    }

    // Look through history for non-repeating == 60
    for i in 1..history.len() {
        if history[i] == 60 {
            count += 1;
        }
    }

    println!("{}", count);
}
