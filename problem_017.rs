// -*- compile-command: "rustc -o problem_017_rs problem_017.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn num_len(n: u16) -> u16 {
    match n {
        1  | 2  | 6  | 10           => return 3,
        4  | 5  | 9                 => return 4,
        3  | 7  | 8  | 40 | 50 | 60 => return 5,
        11 | 12 | 20 | 30 | 80 | 90 => return 6,
        15 | 16 | 70                => return 7,
        13 | 14 | 18 | 19           => return 8,
        17                          => return 9,
        _ => return 0,
    }
}

fn main() {
    println!("Project Euler - Problem 17:");
    println!("If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used\n");

    let mut sum = 0;

    for i in 1..1001 {
        let mut n = i;

        if n > 999 {
            sum += num_len(n / 100);
            sum += 8; // thousand
            n %= 1000;
        }

        if n > 99 {
            sum += num_len(n / 100);
            sum += 7; // hundred
            n %= 100;
            if n != 0 {
                sum += 3; // and
            }
        }

        if n < 21 {
            sum += num_len(n);
        } else {
            sum += num_len((n/10)*10);
            sum += num_len(n%10);
        }
    }

    println!("{}", sum);
}
