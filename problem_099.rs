// -*- compile-command: "rustc -o problem_099_rs problem_099.rs" -*-
// Copyright (c) 2016 Michael Caldwell
use std::fs::File;
use std::io::Read;

fn main() {
    println!("Project Euler - Problem 99:");
    println!("In the textfile, problem_099.txt, find the line in which the base-exponent pair have the largest computed value.\n");

    // Import data from file
    let mut data = String::new();
    let mut f = File::open("problem_099.txt").unwrap();
    f.read_to_string(&mut data).unwrap();

    // Split names into vector
    let values: Vec<&str> = data.split('\n').collect();

    let mut maxval = 0.0;
    let mut maxline = 0;
    let mut linenum = 1;

    for line in values {
        let temp: Vec<&str> = line.split(',').collect();
        let base = temp[0].parse::<u64>().unwrap();
        let exp = temp[1].parse::<u64>().unwrap();
        let value = (base as f64).log10() * (exp as f64);
        if value > maxval {
            maxval = value;
            maxline = linenum;
            //println!("{}^{} = {}", base, exp, value);
        }
        linenum += 1;
    }

    println!("{}", maxline);
}
