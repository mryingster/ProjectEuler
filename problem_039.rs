// -*- compile-command: "rustc -o problem_039_rs problem_039.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 39:");
    println!("Find the perimeter of a right triangle (p) that has the most possible solutions, where the perimiter is less than or equal to 1000.\n");

    let mut counter = [0; 1000];

    for a in 1..1000 {
        for b in 1..1000 {
            let c = ((a as f32).powi(2) + (b as f32).powi(2) as f32).sqrt();
            let p = a + b + (c as usize);
            if p >= 1000 { continue; }
            if (c as u32) as f32 != c { continue; }
            counter[p] += 1;
            if counter[p] > counter[0] {
                counter[0] = counter[p];
                counter[1] = p;
            }
        }
    }

    println!("{}", counter[1]);
}
