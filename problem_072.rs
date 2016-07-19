// -*- compile-command: "rustc -o problem_072_rs problem_072.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main(){
    println!("Project Euler - Problem 72:");
    println!("How many elements would be contained in the set of reduced proper fractions for d <= 1,000,000?\n");
    let mut phi:[u64; 1000001] = [0; 1000001];
    let max_value = phi.len();

    // Initialize Array
    for i in 0..max_value {
        phi[i] = i as u64;
    }

    // Perform Euler's Totient
    for n in 2..max_value {
        // If value hasn't been calculated yet, it the next prime we will use
        if phi[n] == n as u64 {
            // For totient, multiply each number by 1 - 1/p for each prime factor
            let mut k = n;
            while k < max_value {
                //println!("{} {} {} {}", n, phi[n], k, phi[k]);
                phi[k] = phi[k] / (n as u64) * (n - 1) as u64;
                k = k + n;
            }
        }
    }

    // tabulate results
    let mut count = 0;
    for i in 2..max_value {
        count += phi[i];
    }

    println!("{}", count);
}
