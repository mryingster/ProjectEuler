// -*- compile-command: "rustc -o problem_022_rs problem_022.rs" -*-
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

fn main() {
    println!("Project Euler - Problem 22:");
    println!("Sort 5000 names and calculate the sum of their name scores.\n");

    // Import data from file
    let mut data = String::new();
    let mut f = File::open("problem_022.txt").unwrap();
    f.read_to_string(&mut data).unwrap();

    // Split names into vector
    let mut names: Vec<&str> = data.split(',').collect();

    // Sort names alphabetically
    names.sort();

    // Calculate name score
    let mut total = 0;
    let mut index = 1;
    for name in names {
        let score = name_score(name.to_string());
        total += score * index;
        index += 1;
    }

    println!("{}", total);
}
