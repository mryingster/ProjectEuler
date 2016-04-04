// -*- compile-command: "rustc -o problem_015_rs problem_015.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 15");
    println!("Starting in the top left corner in a 20 by 20 grid, how many routes are there to the bottom right corner?\n");

    let mut triangle: [[u64; 41]; 41] = [[0; 41]; 41];

    for i in 0..triangle.len() {
        triangle[i][0] = 1;
        for n in 1..i+1 {
            triangle[i][n] = triangle[i-1][n] + triangle[i-1][n-1];
        }
    }

    println!("{}", triangle[(triangle.len()-1)][((triangle.len()-1)/2)]);
}

