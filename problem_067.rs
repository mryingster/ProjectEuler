// -*- compile-command: "rustc -o problem_067_rs problem_067.rs" -*-
// Copyright (c) 2016 Michael Caldwell
use std::fs::File;
use std::io::Read;

fn main() {
    println!("Project Euler - Problem 67:");
    println!("Find the maximum total from top to bottom of the triangle contained in the file, problem_067.txt.\n");

    let mut triangle: [[u32; 100]; 100] = [[0; 100]; 100];

    // Import data from file
    let mut data = String::new();
    let mut f = File::open("problem_067.txt").unwrap();
    f.read_to_string(&mut data).unwrap();

    // Split data into vector
    let data_input: Vec<&str> = data.split_whitespace().collect();

    // Put vector into triangle array
    let mut row = 0;
    let mut col = 0;
    for n in 0..data_input.len() {
        triangle[row][col] = data_input[n].parse::<u32>().unwrap();
        if row == col {
            col = 0;
            row += 1;
        } else {
            col += 1;
        }
    }

    // Solve!
    for y in (0..triangle.len()-1).rev() {
        for x in 0..y+1 {
            if triangle[y+1][x] > triangle[y+1][x+1] {
                triangle[y][x] +=  triangle[y+1][x];
            } else {
                triangle[y][x] +=  triangle[y+1][x+1];
            }
        }
    }

    println!("{}", triangle[0][0]);
}
