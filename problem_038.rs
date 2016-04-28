// -*- compile-command: "rustc -o problem_038_rs problem_038.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_pandigital(n: u64) -> bool {
    let mut n = n;
    let mut key = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0];

    while n > 0 {
        let d = (n % 10) as usize;
        if key[d] == 1 {
            return false;
        }
        key[d] += 1;
        n /= 10;
    }

    return true;
}

fn concat(n1: u64, n2: u64) -> u64 {
    let mut n = n1;
    let l = (n2 as f32).floor().log10() as i32;
    n *= (10 as f32).powi(l+1) as u64;
    n += n2;
    return n;
}

fn main() {
    println!("Project Euler - Problem 38:");
    println!("What is the largest 1 to 9 pandigital that can be formed by multiplying a fixed number by 1, 2, 3, ... ?\n");


    let mut largest = 123456789;

    for base in 1..9999 {
        let mut candidate = base;
        for multiplier in 2..4 {
            candidate = concat(candidate, base * multiplier);

            if candidate > 987654321 { break; }
            if candidate < largest { continue; }
            if is_pandigital(candidate) == false { continue; }

            largest = candidate;
        }
    }

    println!("{}", largest);
}
