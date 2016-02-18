// -*- compile-command: "rustc -o problem_002_rs problem_002.rs" -*-
// Copyright (c) 2016 Michael Caldwell


fn main() {
    println!("Project Euler - Problem 2");
    println!("By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.\n");

    let limit = 4000000;
    let mut sum = 0;
    let mut pre = 1; // Previous value
    let mut cur = 1; // Current value

    while cur < limit {
        let tmp = cur;
        cur = cur + pre;
        pre = tmp;

        if cur % 2 == 0 {
            sum = sum + cur;
        }
    }

    println!("{}", sum);
}
