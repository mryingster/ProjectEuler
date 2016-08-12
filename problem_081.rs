// -*- compile-command: "rustc -o problem_081_rs problem_081.rs" -*-
// Copyright (c) 2016 Michael Caldwell
use std::fs::File;
use std::io::Read;

fn main() {
    println!("Project Euler - Problem 81:");
    println!("Find the minimal path sum in a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right by only moving right and down.\n");

    let mut matrix: [[u32; 80]; 80] = [[0; 80]; 80];

    // Import data from file
    let mut raw_data = String::new();
    let mut f = File::open("problem_081.txt").unwrap();
    f.read_to_string(&mut raw_data).unwrap();

    // Split data lines into vector
    let data: Vec<&str> = raw_data.split_whitespace().collect();

    // Put vector into matrix array
    for row in 0..data.len() {
        // Split line into vector of values
        let line_of_data: Vec<&str> = data[row].split(",").collect();

        for col in 0..line_of_data.len() {
            matrix[row][col] = line_of_data[col].parse::<u32>().unwrap();
        }
    }

    // Solve!
    for y in 0..matrix.len() {
        for x in 0..matrix.len() {
            // Case 0: Top-left corner
            if y == 0 && x == 0 { continue; };

            // Case 1: Along top edge
            if y == 0 {
                matrix[y][x] += matrix[y][x-1];
                continue;
            }

            // Case 2: Along left edge
            if x == 0 {
                matrix[y][x] += matrix[y-1][x];
                continue;
            }

            // Case 3: Can choose
            if matrix[y-1][x] < matrix[y][x-1] {
                matrix[y][x] += matrix[y-1][x];
            } else {
                matrix[y][x] += matrix[y][x-1];
            }
        }
    }

    // Print last cell for answer
    println!("{}", matrix[matrix.len()-1][matrix.len()-1]);
}
