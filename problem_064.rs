// -*- compile-command: "rustc -o problem_064_rs problem_064.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 64:");
    println!("How many continued fractions for N <= 10000 have an odd period?\n");

    let mut number: u64 = 0;
    let mut count = 0;

    while number < 10000 {
        number += 1;
        let a0 = (number as f32).sqrt() as u64;

        if a0 * a0 == number {
            continue;
        }

        let mut period = 0;
        let mut d = 1;
        let mut m = 0;
        let mut a = a0;

        while a != a0 * 2
        {
            m = d*a - m;
            d = (number - m * m) / d;
            a = (a0 + m) /d;
            period += 1;
        }


        if period %2 != 0 {
            count += 1;
        }
    }

    println!("{}", count);
}
