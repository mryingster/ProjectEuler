// -*- compile-command: "rustc -o problem_014_rs problem_014.rs" -*-
// Copyright (c) 2016 Michael Caldwell


fn main() {
    println!("Project Euler - Problem 14");
    println!("Which starting number, under one million, produces the longest chain by following the rules below?\n\nif n is even, n/2\nif n is odd, 3n+1\n");

    let mut longest = [0, 0];
    let mut chainlength = Vec::new();
    chainlength.push(0);

    for n in 1..1000000 {
        let mut count = 0;
        let mut num = n;

        // Follow chain to 1
        while num != 1 {
            count += 1;
            if num % 2 == 0 {
                num /= 2;
            } else {
                num = num * 3 + 1;
            }
            if num < chainlength.len() {
                count += chainlength[num];
                num = 1;
            }
        }

        // Keep track of longest chain
        if count > longest[0] {
            longest[0] = count;
            longest[1] = n;
        }

        // Record this chain's length
        chainlength.push(count);
    }

    println!("{}", longest[1]);
}
