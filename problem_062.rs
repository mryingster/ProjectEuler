// -*- compile-command: "rustc -o problem_062_rs problem_062.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn get_signature(mut n: u64) -> u64 {
    let mut sig = 0;
    while n > 0 {
        sig += (10 as f64).powi((n % 10) as i32) as u64;
        n /= 10;
    }
    return sig;
}

fn get_length(n: u64) -> u64 {
    return ((n as f32).log10().floor() + 1.0) as u64;
}

fn main() {
    println!("Project Euler - Problem 62:");
    println!("Find the smallest cube for which exactly five permutations of its digits are cube.\n");

    let mut cubes = Vec::new();

    // Get cubes, signatures, and number lengths
    for n in 1..10000 {
        let cube = n * n * n;
        cubes.push([cube, get_signature(cube), get_length(cube)]);
    }

    for a in 0..cubes.len() {
        let mut count = 1;
        for b in (a+1)..cubes.len() {
            // Look for permutations by comparing signatures
            if cubes[a][1] == cubes[b][1] {
                count += 1;
            }

            // If cube magnitudes change, go to next cube
            if cubes[b][2] > cubes[a][2] {
                break;
            }
        }
        if count == 5 {
            println!("{}", cubes[a][0]);
            break;
        }
    }
}
