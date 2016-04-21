// -*- compile-command: "rustc -o problem_027_rs problem_027.rs" -*-
// Copyright (c) 2016 Michael Caldwell

fn is_prime(n: u64) -> bool {
    if n < 2 {
        return false;
    }
    if n == 2 {
        return true;
    }
    if n % 2 == 0 {
        return false;
    }

    let limit = (n as f64).sqrt() as u64;
    for i in 3..(limit+1) {
        if n % i == 0 {
            return false;
        }
    }
    return true;
}

fn main() {
    println!("Project Euler - Problem 27:");
    println!("Find the product of the coefficients, a and b, for the quadratic expression, n^2 + an + b, that produces the maximum number of primes for consecutive values of n, starting with n = 0.\n");

    let limit = 1000;
    let mut max = [0, 0];

    for a in (limit * -1)..limit as i32 {
        for b in a..limit as i32 {
            let mut n = 0;
            let mut c = 0;
            let mut equation: i32 = (n * n) + (a * n) + b;
            while equation > 0 && is_prime(equation as u64) {
                c += 1;
                n += 1;
                equation = (n * n) + (a * n) + b;
            }
            if c > max[0] {
                max[0] = c;
                max[1] = a * b;
            }
        }
    }

    println!("{}", max[1]);
}
