// -*- compile-command: "rustc -o problem_065_rs problem_065.rs" -*-
// Copyright (c) 2016 Michael Caldwell

/* Notes
 *                         (m)
 * Multipliers: 2   1   2   1   1   4   1   1   6   1   1
 * Numerators:  2   3   8   11  19  87 106 193
 *             (c) (b) (a)
 *
 * To calculate position a, a=b*m+c
 * This starts by calculating the second numerator (3),
 * and assumes 1 for the numerator to the left of 2
 * Multiplier continue in the same pattern of increasing by 2
 */

// Multiplies each element of array by n
fn multiply_array(mut a:[usize; 100], n:usize) -> [usize; 100]{
    for i in 0..a.len() {
        a[i] *= n;
    }
    return carry_array(a);
}

// Adds two arrays together
fn add_array(mut a:[usize; 100], b:[usize; 100]) -> [usize; 100] {
    for i in 0..a.len() {
        a[i] += b[i];
    }
    return carry_array(a);
}

// Performs carry operation so each element is single digit
fn carry_array(mut a:[usize; 100]) -> [usize; 100] {
    for i in 0..a.len()-1 {
        while a[i] > 9 {
            a[i] -= 10;
            a[i+1] += 1;
        }
    }
    return a;
}

fn main() {
    println!("Project Euler - Problem 65:");
    println!("Find the sum of the numerator of the 100th convergent fraction for e.\n");

    let debug = false;

    let mut num_a: [usize; 100] = [0; 100];
    let mut num_b: [usize; 100] = [0; 100];
    let mut num_c: [usize; 100];

    num_a[0] = 2;
    num_b[0] = 1;

    let mut multiplier = 0;
    let mut count = 1;

    for _ in 1..100 {
        let mut m = 1;
        count += 1;

        // Keep track of multipliers
        if count == 3 {
            count = 0;
            multiplier += 2;
            m = multiplier;
        }

        // Convergent Fraction
        num_c = num_b;
        num_b = num_a;
        num_a = multiply_array(num_b, m);
        num_a = add_array(num_a, num_c);

        // Debug print numerator for each step
        if debug == true {
            let mut print = false;
            for i in (0..num_a.len()).rev() {
                if num_a[i] > 0 { print = true; }
                if print == true {
                    print!("{}", num_a[i]);
                }
            }
            println!("");
        }
    }

    // Sum the digits
    let mut sum = 0;
    for i in 0..num_a.len() {
        sum += num_a[i];
    }

    println!("{}", sum);

}
