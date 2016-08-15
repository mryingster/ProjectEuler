// -*- compile-command: "rustc -o problem_082_rs problem_082.rs" -*-
// Copyright (c) 2016 Michael Caldwell
use std::fs::File;
use std::io::Read;

fn main() {
    println!("Project Euler - Problem 82:");
    println!("Find the minimal path sum in a 31K text file containing a 80 by 80 matrix, from the left column to right column.\n");

    let mut matrix: [[u32; 80]; 80] = [[0; 80]; 80];

    // Import data from file
    let mut raw_data = String::new();
    let mut f = File::open("problem_082.txt").unwrap();
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

    // Solve by columns
    for x in (0..matrix.len()-1).rev() {
        // Create a tmp column with values to the right.
        let mut tmp_col = [0; 80];
        for y in 0..matrix.len() {
            tmp_col[y] = matrix[y][x] + matrix[y][x+1];
        }

        // Solve up
        for y in 1..matrix.len() {
            let tmp_value = matrix[y][x] + tmp_col[y-1];
            if tmp_value < tmp_col[y] {
                tmp_col[y] = tmp_value;
            }
        }

        // Then solve down
        for y in (0..matrix.len()-1).rev() {
            let tmp_value = matrix[y][x] + tmp_col[y+1];
            if tmp_value < tmp_col[y] {
                tmp_col[y] = tmp_value;
            }
        }

        // Copy values back to matrix
        for y in 0..matrix.len() {
            matrix[y][x] = tmp_col[y];
        }
    }

    // Print smallest value
    let mut smallest_value = matrix[0][0];

    for y in 0..matrix.len() {
        if matrix[y][0] < smallest_value {
            smallest_value = matrix[y][0];
        }
    }

    println!("{}", smallest_value);
}
