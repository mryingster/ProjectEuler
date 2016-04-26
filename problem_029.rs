// -*- compile-command: "rustc -o problem_029_rs problem_029.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {
    println!("Project Euler - Problem 29:");
    println!("How many distinct terms are in the sequence generated by a^b for 2 <= a <= 100 and 2 <= b <= 100?\n");

    let mut history = [[0; 200]; 10000];
    let mut index = 0;
    let debug = false;

    for a in 2..101 {
        let mut current = [0; 200];
        current[0] = a;

        for b in 2..101 {
            // Carry over
            for i in 0..current.len()-1 {
                while current[i] > 9 {
                    current[i] -= 10;
                    current[i+1] += 1;
                }
            }

            // Check if duplicate
            let mut duplicate = false;
            for i in 0..index {
                let mut same = true;
                for d in 0..current.len() {
                    if history[i][d] != current[d] {
                        same = false;
                        break;
                    }
                }
                if same == true {
                    duplicate = true;
                    break;
                }
            }

            // If not duplicate, add to history
            if duplicate == false {
                for d in 0..current.len() {
                    history[index][d] = current[d];
                }
                if debug == true {
                    println!("{} ^ {} is unique!", a, b);
                }
                index += 1;
            }

            // Multiply for next power
            for i in 0..current.len()-1 {
                current[i] *= a;
            }
        }
    }

    println!("{}", index + 1); // Add one because index is 0-based
}