// -*- compile-command: "rustc -o problem_022_rs problem_022.rs" -*-
// Copyright (c) 2016 Michael Caldwell
use std::fs::File;
use std::io::Read;

fn decipher(data: &Vec<&str>, key: [u8; 3]) -> u32 {
    let mut sum: u32 = 0;
    let mut spaces = 0;
    let mut index = 0;

    for c in data {
        // Perform XOR operation using KEY
        let new_c: u8 = c.parse::<usize>().unwrap() as u8 ^ key[index % 3];
        sum += new_c as u32;
        //print!("{}", new_c as char); // DEBUG - Print deciphered text

        // See if character is out of range, and reject cipher
        if new_c < ' ' as u8 || new_c > 'z' as u8 { return 0; }

        // Make sure no longer than 16 characters between spaces
        if new_c == ' ' as u8 {
            spaces = 0;
        } else {
            spaces += 1;
        }

        if spaces > 16 {
            return 0;
        }

        // Next char
        index += 1;
    }

    return sum;
}

fn main() {
    println!("Project Euler - Problem 59:");
    println!("Decrypt the message and find the sum of the ASCII values in the original text.\n");

    // Import data from file
    let mut data = String::new();
    let mut f = File::open("problem_059.txt").unwrap();
    f.read_to_string(&mut data).unwrap();

    // Split character codes into vector
    let chars: Vec<&str> = data.split(',').collect();

    // Iterate through all 3-letter keys
    for a in ('a' as u8)..('z' as u8) {
        for b in ('a' as u8)..('z' as u8) {
            for c in ('a' as u8)..('z' as u8) {
                let sum = decipher(&chars, [a, b, c]);
                if sum != 0 {
                    println!("{} (Key: {}{}{})", sum, a as char, b as char, c as char);
                    return;
                }
            }
        }
    }

    println!("No solution found.");
    return;
}
