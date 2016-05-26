// -*- compile-command: "rustc -o problem_043_rs problem_043.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn substring_divisibility(a: [u32; 10]) -> bool {
    let divisor = [1, 2, 3, 5, 7, 11, 13, 17];

    for i in 1..8 {
        let n = a[i] * 100 + a[i+1] * 10 + a[i+2];
        //println!("{} {}", n, divisor[i]);
        if n % divisor[i] != 0 { return false; }
    }

    return true;
}

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
    println!("Project Euler - Problem 43:");
    println!("Find the sum of all 0 to 9 pandigital numbers with the sub-string divisibility property.\n");

    let mut array: [u32; 10] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
    let mut sum: u64 = 0;

    while array != [9, 8, 7, 6, 5, 4, 3, 2, 1, 0] {
        if substring_divisibility(array) == true {
            let mut n: u64 = 0;
            for i in 0..array.len() {
                n *= 10;
                n += array[i] as u64;
            }
            sum += n;
            //println!("{} {}", n, sum); // DEBUG
        }
        array = next_permutation(array);
    }

    println!("{}", sum);
}
