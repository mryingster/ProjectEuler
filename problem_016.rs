// -*- compile-command: "rustc -o problem_016_rs problem_016.rs" -*-
// Copyright (c) 2016 Michael Caldwell


fn main() {
    println!("Project Euler - Problem 16");
    println!("What is the sum of the digits of the number 2^1000\n");

    let mut bignum = Vec::new();
    bignum.push(1);

    for _ in 0..1000 {
        // Multiple all elements by 2
        for i in 0..bignum.len() {
            bignum[i] *= 2;
        }

        // Carry cells over to the right
        for i in 0..bignum.len() {
            while bignum[i] > 9 {
                if i+1 >= bignum.len() {
                    bignum.push(0);
                }
                bignum[i] -= 10;
                bignum[i+1] += 1;
            }
        }
    }

    let mut sum = 0;
    for i in 0..bignum.len() {
        sum += bignum[i];
    }

    println!("{}", sum);
}
