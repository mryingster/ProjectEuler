// -*- compile-command: "rustc -o problem_036_rs problem_036.rs" -*-
// Copyright (c) 2016 Michael Caldwell
//use std::num;

fn is_palindromic_bin(mut n: u64) -> bool {
    let mut bin = [0; 20];

    // Convert into binary number
    for i in (0..20).rev() {
        let b = (2 as f64).powi(i) as u64;
        if n >= b {
            n -= b;
            bin[i as usize] = 1;
        }
    }

    // Find end of BIN number, then compare with other side
    let mut compare: i32 = -1;
    for i in (0..20).rev() {
        if bin[i] == 1 && compare == -1{
            compare = 0;
        }
        if compare > -1 {
            if bin[i] != bin[compare as usize] {
                return false;
            }
            compare += 1;
        }
    }

    return true;
}

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
    println!("Project Euler - Problem 36");
    println!("Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.\n");

    let mut sum = 0;

    for n in 1..1000000 {
        if n == reverse(n) {
            if is_palindromic_bin(n) {
                sum += n;
            }
        }
    }

    println!("{}", sum);
}


//872187
