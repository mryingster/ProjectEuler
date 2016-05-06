// -*- compile-command: "rustc -o problem_044_rs problem_044.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_pentagonal(n: i32) -> bool {
    let check = ((((24 * n + 1) as f32).sqrt()) + 1.0) / 6.0;
    if check == (check as u32) as f32 {
        return true;
    }
    return false;
}

fn main() {
    println!("Project Euler - Problem 44:");
    println!("Find the smallest difference for a pair of pentagonal numbers whose sum and difference is also pentagonal.\n");

    let debug = false;
    let mut result = -1;
    let mut pent = Vec::new();
    pent.push(1);

    for n in 1..5000 {
        pent.push(n * (3 * n - 1) / 2);
        for i in (1..n-1).rev() {
            let s: i32 = pent[n] as i32;
            let n2: i32 = pent[i] as i32;

            let n1: i32 = s - n2;
            if is_pentagonal(n1) == false {
                continue;
            }

            let d: i32 = n2 - n1;
            if is_pentagonal(d) == false {
                continue;
            }

            if debug == true { println!("{} = {} +/- {} = {}", d, n1, n2, s); }
            result = d;
            break;
        }
        if result > 0 { break; }
    }

    println!("{}", result);
}
