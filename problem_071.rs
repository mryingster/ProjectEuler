// -*- compile-command: "rustc -o problem_071_rs problem_071.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 71:");
    println!("By listing the set of reduced proper fractions for d <= 1,000,000 in ascending order of size, find the numerator of the fraction immediately to the left of 3/7.\n");

    let limit = 1000000;
    let target: f64 = 3.0/7.0;
    let mut min_num: usize = 0;
    let mut min_fraction: f64 = 0.0;

    for d in 7..limit {
        let n = (((d as f64) * target) as usize) - 1;
        let f = (n as f64)/(d as f64);
        if f > min_fraction {
            min_fraction = f;
            min_num = n;
        }
    }

    println!("{}", min_num);
}
