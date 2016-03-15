// -*- compile-command: "rustc -o problem_012_rs problem_012.rs" -*-
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
    for i in 3..limit+1 {
        if n % i == 0 {
            return false;
        }
    }
    return true;
}

fn divisors(mut n: u64, p: &Vec<u64>) -> u64 {
    let mut count = 1;
    for i in 0..p.len() {
        let mut t = 1;
        while n % p[i] == 0 {
            t += 1;
            n /= p[i];
        }
        count *= t;
        if n == 1 {
            break;
        }
    }
    return count;
}


fn main() {
    println!("Project Euler - Problem 12");
    println!("What is the value of the first triangle number to have over five hundred divisors?\n");

    // Find primes!
    let mut primes = Vec::new();
    for n in 2..5000 {
        if is_prime(n) {
            primes.push(n)
        }
    }

    // Find triangles
    let mut tri: u64 = 1;
    for n in 2..1000000 {
        tri += n;
        if divisors(tri, &primes) > 500 {
            break;
        }
    }


    println!("{}", tri);
}
