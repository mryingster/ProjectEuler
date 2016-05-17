// -*- compile-command: "rustc -o problem_055_rs problem_055.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn reverse(mut n: u64) -> u64 {
    let mut o = 0;

    while n > 0 {
        o *= 10;
        o += n % 10;
        n /= 10;
    }

    return o;
}


fn main() {
    println!("Project Euler - Problem 55");
    println!("How many Lychrel numbers are there below ten-thousand?\n");

    let mut count = 0;
    let max = i64::max_value;

    for i in 1..10000 {
        let mut n: u64 = i as u64;
        let mut lychrel = false;
        while n < max as u64 {
            n += reverse(n);
            if n == reverse(n) {
                lychrel = true;
                break;
            }
        }
        if lychrel == false { count += 1; }
    }

    println!("{}", count);
}

