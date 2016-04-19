// -*- compile-command: "rustc -o problem_026_rs problem_026.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn main() {

    println!("Project Euler - Problem 26:");
    println!("Find the value of d < 1000 for which 1/d contains the longest recurring cycle.\n");

    let mut longest = [0, 0];
    let debug = false;

    for d in 2..1000 {
        let mut answer = Vec::new();
        answer.push(1);
        let mut repeat_index: i32 = 1;
        let mut repeat_length: i32 = -1;
        let mut i = 0;

        // Perform long division!
        while answer.len() < 1500 {
            let tmp1 = answer[i] / d;
            let tmp2 = tmp1 * d;
            answer[i] -= tmp2;
            answer.push(0);
            if answer[i] < d {
                answer[i+1] += answer[i]*10;
                answer[i] = 0;
            }
            answer[i] = tmp1;

            // Keep track if repeating digits.
            if answer.len() > 3 {
                if answer[i] == answer[repeat_index as usize] {
                    repeat_index += 1;
                } else {
                    repeat_index = 1;
                }
            }
            if repeat_index >= 10 {
                repeat_length = i as i32 - repeat_index + 1;
                if repeat_length > longest[0] {
                    longest[0] = repeat_length;
                    longest[1] = d;
                }
                break;
            }
            i += 1;
        }

        // Print answers
        if debug == true {
            println!("1/{} repeats after {} digits", d, repeat_length);
        }
    }

    println!("{}", longest[1]);
}
