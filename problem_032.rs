// -*- compile-command: "rustc -o problem_032_rs problem_032.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_pandigital(a: usize, b: usize, c: usize) -> bool {
    let mut a = a;
    let mut b = b;
    let mut c = c;
    let mut key = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0];

    while a > 0 {
        key[a%10] += 1;
        a /= 10;
    }

    while b > 0 {
        key[b%10] += 1;
        b /= 10;
    }

    while c > 0 {
        key[c%10] += 1;
        c /= 10;
    }

    for i in 0..key.len() {
        if key[i] != 1 {
            return false;
        }
    }

    return true;
}

fn main() {
    println!("Project Euler - Problem 32:");
    println!("Find the sum of all numbers that can be written as pandigital products.\n");

    let mut sum = 0;
    let mut products = Vec::new();

    for a in 0..99 {
        for b in a..5000 {
            let c = a * b;
            if is_pandigital(a, b, c) == true {
                let mut new = true;
                for i in 0..products.len() {
                    if products[i] == c {
                        new = false;
                    }
                }
                if new == true {
                    sum += c;
                    products.push(c);
                    //println!("{} x {} = {}", a, b, c); // DEBUG
                }
            }
        }
    }

    println!("{}", sum);
}
