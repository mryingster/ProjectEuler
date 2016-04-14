// -*- compile-command: "rustc -o problem_025_rs problem_025.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 25:");
    println!("What is the index of the first term in the Fibonacci sequence to contain 1000 digits?\n");

    let mut pre: u64 = 1; // Previous value
    let mut cur: u64 = 0; // Current value
    let mut digits = 16;
    let mut index = 0;

    while digits < 1000 {
        let tmp = cur;
        cur = cur + pre;
        pre = tmp;

        index += 1;

        if cur > 9999999999999999 {
            cur /= 10;
            pre /= 10;
            digits += 1;
        }
    }

    println!("{}", index);
}
