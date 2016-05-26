// -*- compile-command: "rustc -o problem_042_rs problem_042.rs" -*-
// Copyright (c) 2016 Michael Caldwell
use std::fs::File;
use std::io::Read;

fn name_score(name: String) -> u64 {
    let mut score = 0;
    for c in name.chars() {
        if c == '"' { continue; }
        score += c as u64 - '@' as u64;
    }
    return score;
}

fn is_triangle(n: u64) -> bool {
    if n == 0 { return false; }
    let check = (((8 * n + 1) as f32).sqrt() - 1.0) / 2.0;
    if check == ((check as u32) as f32) { return true; }
    return false;
}

fn main() {
    println!("Project Euler - Problem 42:");
    println!("In a list of two-thousand common English words, how many are triangle words?\n");

    // Import data from file
    let mut data = String::new();
    let mut f = File::open("problem_042.txt").unwrap();
    f.read_to_string(&mut data).unwrap();

    // Split names into vector
    let names: Vec<&str> = data.split(',').collect();

    // Calculate name score
    let mut total = 0;
    for name in names {
        let score = name_score(name.to_string());
        if is_triangle(score) {
            total += 1;
        }
    }

    println!("{}", total);
}
