// -*- compile-command: "rustc -o problem_009_rs problem_009.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 9");
    println!("There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.\n");

    let mut answer = 0;

    for a in 1..1000 {
        for b in a+1..1000 {
            let c = ((a*a + b*b) as f64).sqrt();
            if c <= b as f64 {
                continue;
            }
            if a as f64+b as f64+c == 1000 as f64 {
                //println!("{} {} {}", a, b, c);
                answer = a*b*c as u32;
                break;
            }
        }
        if answer != 0 {
            break;
        }
    }

    println!("{}", answer);
}
