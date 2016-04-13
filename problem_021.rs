// -*- compile-command: "rustc -o problem_021_rs problem_021.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 21:");
    println!("Evaluate the sum of all the amicable numbers under 10000.\n");

    let mut divisor_sum_table: [usize; 10000] = [0; 10000];

    for i in 1..divisor_sum_table.len() {
        let mut t = 2;
        while t * i < divisor_sum_table.len() {
            divisor_sum_table[t*i] += i as usize;
            t += 1;
        }
    }

    let mut amicable_sum = 0;

    for i in 1..divisor_sum_table.len() {
        let t = divisor_sum_table[i];
        if t < divisor_sum_table.len() && i != t{
            if i == divisor_sum_table[t] {
                amicable_sum += i;
            }
        }
    }

    println!("{}", amicable_sum);
}
