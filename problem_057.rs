// -*- compile-command: "rustc -o problem_057_rs problem_057.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 57:");
    println!("In the first one-thousand expansions of 1+1/(2+1/(2+1/(2+...)))=1.414213, how many fractions contain a numerator with more digits than denominator?\n");

    let debug = false;

    // Setup our big number holders
    let mut num = [0; 1000];
    num[0] = 3;
    let mut num_old = [0; 1000];
    num_old[0] = 1;
    let mut num_older = [0; 1000];
    num_older[0] = 3;
    let mut den = [0; 1000];
    den[0] = 2;

    let mut topheavy = 0;

    for _ in 0..1000 {
        // Update numbers
        for i in 0..num.len()-1 {
            den[i] += num[i];
            num_older[i] = num_old[i];
            num_old[i] = num[i];
            num[i] = num[i] * 2 + num_older[i];
        }

        // Roll over values
        for i in 0..num.len()-1 {
           while num[i] > 9 {
                num[i] -= 10;
                num[i+1] += 1;
            }

            while den[i] > 9 {
                den[i] -= 10;
                den[i+1] += 1;
            }
        }

        // Count digits
        let mut num_count = 1000-1;
        let mut den_count = 1000-1;
        while num[num_count] == 0 { num_count -= 1; }
        while den[den_count] == 0 { den_count -= 1; }

        // Check if topheavy
        if num_count > den_count {
            topheavy += 1;
        }

        // DEBUG - Print Fractions
        if debug == true {
            for i in (0..num_count).rev() {
                print!("{}", num[i]);
            }
            print!(" / ");
            for i in (0..num_count).rev() {
                print!("{}", den[i]);
            }
            println!("\n{} digits / {} digits\n", num_count, den_count);
        }
    }

    println!("{}", topheavy);
}
