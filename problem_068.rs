// -*- compile-command: "rustc -o problem_068_rs problem_068.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn next_permutation(mut a: [u32; 5]) -> [u32; 5] {
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
        let mut r = [0, 0, 0, 0, 0];
        let mut j = 4;
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

fn factorial(mut n: usize) -> usize {
    let mut result = 1;
    while n > 1 {
        result *= n;
        n -= 1;
    }
    return result;
}

fn check_solution(o: [u32; 5], i: [u32; 5], length: usize) -> String {
    let mut result = String::new();
    let target = o[0] + i[0] + i[1];

    // Compare each triplet's sum against the first
    for p in 0..length {
        if o[p] + i[p] + i[(p+1)%length] != target {
            // Return a blank string
            return String::from("");
        }

        // Append our new numbers to the string
        result = format!("{}{}{}{}", result, o[p], i[p], i[(p+1)%length]);
    }

    return result;
}

fn main() {
    println!("Project Euler - Problem 68:");
    println!("Find the maximum concatenation for a 16 digit string for a solution to a \"magic 5-gon ring\" using the numbers 1-10?\n");

    let mut outer: [u32; 5] = [6, 7, 8, 9, 10];
    let length = outer.len() as usize;
    let num_permutations = factorial(length);

    let mut solution = String::new();

    // Go through permutations of the outside number
    for _ in 0..num_permutations {
        outer = next_permutation(outer);

        // Go through permutations of the inside number
        let mut inner: [u32; 5] = [1, 2, 3, 4, 5];
        for _ in 0..num_permutations {
            inner = next_permutation(inner);

            // See if we found a solution
            solution = check_solution(outer, inner, length);

            // Non-empty string means we found a solution. Break!
            if solution.is_empty() == false {
                break;
            }
        }
        if solution.is_empty() == false {
            break;
        }
    }

    println!("{}", solution);
}
