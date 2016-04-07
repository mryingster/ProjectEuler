// -*- compile-command: "rustc -o problem_020_rs problem_020.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 20:");
    println!("Find the sum of the digits in the number 100!\n");

    let mut bignum = Vec::new();
    bignum.push(100);

    for i in (1..100).rev() {
        for e in 0..bignum.len() {
            bignum[e] *= i;
        }

        let mut t = 0;
        while t < bignum.len() {
            while bignum[t] > 9 {
                if t == bignum.len()-1 {
                    bignum.push(0);
                }
                bignum[t] -= 10;
                bignum[t+1] += 1;
            }
            t += 1;
        }
    }

    let mut total = 0;
    for e in (0..bignum.len()).rev() {
        total += bignum[e];
        //print!("{}", bignum[e]); //DEBUG
    }

    println!("\n\n{}", total);
}
