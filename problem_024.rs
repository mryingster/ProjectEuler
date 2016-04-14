// -*- compile-command: "rustc -o problem_024_rs problem_024.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn next_permutation(mut a: [u32; 10]) -> [u32; 10] {
    // Find the largest index k such that a[k] < a[k + 1]
    let mut k = 0;
    for i in 0..(a.len()-1) {
        if a[i] < a[i+1] {
            k = i;
        }
    }

    // Find the largest index l greater than k such that a[k] < a[l]
    let mut l = 0;
    for i in k..a.len() {
        if a[k] < a[i] {
            l = i;
        }
    }

    // Swap the value of a[k] with that of a[l]
    let t = a[k];
    a[k] = a[l];
    a[l] = t;

    // Reverse the sequence from a[k + 1] up to and including the final element a[n]
    if k < 8 {
        let mut r = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
        let mut j = 9;
        for i in (k+1)..a.len() {
            r[j] = a[i];
            j -= 1;
        }
        for i in (k+1)..a.len() {
            a[i] = r[i];
        }
    }
    return a;
}

fn main() {
    println!("Project Euler - Problem 24:");
    println!("Find the 1,000,000th lexiconic permutation of the numbers 0, 1, 2, 3, 4, 5, 6, 7, 8, and 9.\n");

    let mut array: [u32; 10] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

    for _ in 0..1000000 {
        array = next_permutation(array);
    }

    for i in 0..array.len() {
        print!("{}", array[i]);
    }
    println!("");
}
