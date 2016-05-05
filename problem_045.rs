// -*- compile-command: "rustc -o problem_045_rs problem_045.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 45:");
    println!("Find the next triangle number after 40755 that is also pentagonal and hexagonal.\n");

    let mut tri: [u64; 2]  = [285, 40755];
    let mut pent: [u64; 2] = [165, 0];
    let mut hex: [u64; 2]  = [143, 0];

    while tri[1] != hex[1] || tri[1] != pent[1] {
        // Get next Triangle number
        tri[0] += 1;
        tri[1] = tri[0] * (tri[0] + 1) / 2;

        // Get next Pentagonal number once Triangle number is larger
        while pent[1] < tri[1] {
            pent[0] += 1;
            pent[1] = pent[0] * (3 * pent[0] - 1) / 2;
        }

        // Get next Hexagonal number once Triangle number is larger
        while hex[1] < tri[1] {
            hex[0] += 1;
            hex[1] = hex[0] * (2 * hex[0] - 1);
        }
    }

    println!("{}", tri[1]);
}
