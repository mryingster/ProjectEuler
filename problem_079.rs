// -*- compile-command: "rustc -o problem_079_rs problem_079.rs" -*-
// Copyright (c) 2016 Michael Caldwell
use std::fs::File;
use std::io::Read;

fn is_present(a: [i32; 3], n: i32) -> bool {
    for i in 0..3 {
        if a[i] == n {
            return true;
        }
    }
    return false;
}

fn is_rightmost(a: [i32; 3], n: i32) -> bool {
    // See if number is in this set
    let mut seen = false;
    for i in 0..3 {
        if a[i] == n {
            seen = true;
        }
    }
    if seen == false { return true; }

    for i in (0..3).rev() {
        if a[i] == -1 { continue; }
        if a[i] == n { return true; }
        else { return false; }
    }
    return true;
}

fn main() {
    println!("Project Euler - Problem 79:");
    println!("Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.\n");

    // Import data from file
    let mut data = String::new();
    let mut f = File::open("problem_079.txt").unwrap();
    f.read_to_string(&mut data).unwrap();

    // Split codes into vector
    let mut codes_ascii: Vec<&str> = data.split('\n').collect();

    // Sort codes alphabetically
    codes_ascii.sort();

    // Convert codes from ASCII Text to Integers (new vector)
    let mut codes_int = Vec::new();
    for code in codes_ascii {
        let tmp = code.parse::<usize>();
        if tmp.is_err() == false {
            let mut int = tmp.unwrap();
            let mut array: [i32; 3] = [0, 0, 0];
            for i in (0..3).rev() {
                array[i] = (int % 10) as i32;
                int /= 10;
            }
            codes_int.push(array);
        }
    }

    // search for each number
    let mut answer = Vec::new();
    loop {
        for i in 0..10 {
            // See if number is present
            let mut present = false;
            for n in 0..codes_int.len(){
                if is_present(codes_int[n], i as i32) == true {
                    present = true;
                    break;
                }
            }
            if present == false { continue; }

            // See if number is right most
            let mut right = true;
            for n in 0..codes_int.len(){
                if is_rightmost(codes_int[n], i as i32) == false {
                    right = false;
                    break;
                }
            }

            if right == true {
                answer.push(i);

                // Mark code number as -1 to indicate used
                for n in 0..codes_int.len(){
                    for j in 0..3 {
                        if codes_int[n][j] == i as i32{
                            codes_int[n][j] = -1;
                        }
                    }
                }

                break;
            }
        }

        // See if we are done by checking if all numbers are used (-1)
        let mut done = true;
        for n in 0..codes_int.len(){
            for j in 0..3 {
                if codes_int[n][j] > -1 {
                    done = false;
                }
            }
        }

        if done == true {
            break;
        }
    }

    // Print answer
    for i in (0..answer.len()).rev() {
        print!("{}", answer[i]);
    }
    println!("");
}
