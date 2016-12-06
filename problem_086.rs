// -*- compile-command: "rustc -o problem_086_rs problem_086.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 86:");
    println!("Find the least value of M such that the number of integer solutions for a cuboid smaller than M x M x M first exceeds one million.\n");

    let mut count = 0;
    let mut x = 1;

    while count < 1000000 {
        x += 1;
        for y in 1..x+1 {
            for z in 1..y+1 {
                // Find shortest of three paths
                let mut path_f:f64;

                if x+z < y+z {
                    if x+z < x+y {
                        path_f = (((x + z) as f64).powi(2) + (y as f64).powi(2)).sqrt();
                    } else {
                        path_f = (((x + y) as f64).powi(2) + (z as f64).powi(2)).sqrt();
                    }
                } else {
                    if y+z < x+y {
                        path_f = (((y + z) as f64).powi(2) + (x as f64).powi(2)).sqrt();
                    } else {
                        path_f = (((x + y) as f64).powi(2) + (z as f64).powi(2)).sqrt();
                    }
                }

                // See if solution is integer
                if path_f == (path_f as usize) as f64 {
                    //println!("{} {} {}: {}", x, y, z, path_f);
                    count += 1;
                }
            }
        }
    }

    println!("{}", x);
}
