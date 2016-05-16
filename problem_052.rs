// -*- compile-command: "rustc -o problem_052_rs problem_052.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn num_sig(n: usize) -> u64 {
    let mut n = n;
    let mut sig: u64 = 0;
    while n > 0 {
        sig += (10 as f32).powi((n % 10) as i32) as u64;
        n /= 10;
    }
    return sig;
}

fn main() {
    println!("Project Euler - Problem 52:");
    println!("Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.\n");

    for a in 1000..1000000 {
        let sig = num_sig(a);
        for b in 2..7 {
            if num_sig(b*a) != sig {
                break;
            }
            if b == 6 {
                println!("{}", a);
                return;
            }
        }
    }
}
