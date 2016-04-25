// -*- compile-command: "rustc -o problem_031_rs problem_031.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 31:");
    println!("How many different ways can 2 pounds be made using any number of coins?\n");

    let coins = [1, 2, 5, 10, 20, 50, 100, 200];
    let mut ways = [0; 201];
    ways[0] = 1;

    for c in 0..coins.len() {
        for v in coins[c]..201 {
            ways[v] += ways[v-coins[c]];
        }
    }

    println!("{}", ways[ways.len()-1]);
}
